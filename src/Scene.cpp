#include "Scene.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Circle.h" // Afegits

Scene::Scene() {
    pmin.x = -0.5f;
    pmin.y = -0.5f;
    pmin.z = -0.5f;
    pmax.x = 0.5f;
    pmax.y = 0.5f;
    pmax.z = 0.5f;
}

Scene::~Scene() {
// TODO Fase 1: Quan s'incloguin nous objectes, cal retocar aquest destructor
    for (unsigned int i = 0; i < objects.size(); ++i) {
        if (objects[i]) {
            if (dynamic_cast<Sphere *>(objects[i]))
                delete (Sphere *) (objects[i]);
            else if (dynamic_cast<Plane *>(objects[i]))
                delete (Plane *) (objects[i]);
            else if (dynamic_cast<Triangle *>(objects[i]))
                delete (Triangle *) (objects[i]);
            else if (dynamic_cast<Cylinder *>(objects[i]))
                delete (Cylinder *) (objects[i]);
            else if (dynamic_cast<Circle *>(objects[i]))
                delete (Circle *) (objects[i]);
            else if (dynamic_cast<BoundaryObject *>(objects[i]))
                delete (BoundaryObject *) (objects[i]);
        }
    }
    delete (cam);
}

/*
** TODO: FASE 1: Metode que testeja la interseccio contra tots els objectes de l'escena
**
** Si un objecte es intersecat pel raig, el parametre  de tipus IntersectInfo conte
** la informació sobre la interesccio.
** El metode retorna true si algun objecte es intersecat o false en cas contrari.
**
*/
bool Scene::intersection(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const {

    IntersectionInfo min_inter = info; //local copy to maintain the minimum
    bool intersects = false;

    //cycle through all the objects in the scene
    for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
        //if the ray intersects the object
        if ((*it)->intersection(raig, t_min, t_max, info)) {
            intersects = true;
            // compute at which distance
            // if its less then the current minimum, save the new intersection
            if (info.t < min_inter.t)
                min_inter = info;
        }
    }

    info = min_inter;

    return intersects;
    // TODO FASE 0 i FASE 1: Heu de codificar la vostra solucio per aquest metode substituint el 'return true'
    // Una possible solucio es cridar el mètode intersection per a tots els objectes i quedar-se amb la interseccio
    // mes propera a l'observador, en el cas que n'hi hagi més d'una.
    // Cada vegada que s'intersecta un objecte s'ha d'actualitzar el IntersectionInfo del raig,
    // pero no en aquesta funcio.

}

/*
** TODO: Funcio ComputeColorRay es la funcio recursiva del RayTracing.
 * TODO: FASE 1 per a cridar a la intersecció amb l'escena i posar el color de l'objecte
** TODO: Fase 2 de l'enunciat per incloure Blinn-Phong  i ombres
** TODO: Fase 2 per a tractar reflexions i transparències
**
*/
vec3 Scene::ComputeColorRay(Ray &ray, int depth) {
    vec3 color;
    vec3 ray2;
    IntersectionInfo info = IntersectionInfo();


    if (this->intersection(ray, 0.01f, 10, info)) {

        color += (1.0f - info.mat_ptr->alpha) * BlinnPhong(info.p, info.normal, info.mat_ptr);

        vec3 scatterColor = vec3(0.0f);
        vector<Ray> scatterRay;

        if (MAX_DEPTH > depth) {
            if (info.mat_ptr->scatter(ray, info, scatterColor, scatterRay)) {
                color += scatterColor * ComputeColorRay(scatterRay.at(scatterRay.size() - 1), depth + 1);
            }
        }

        color += this->ambientGlobal * info.mat_ptr->ambient;

    } else {
        ray2 = normalize(ray.direction);
        color = vec3(1.0f) - (((ray2.t + 1) / 2) * vec3(0.7, 0.5, 0));
    }
    return color;
}

vec3 Scene::BlinnPhong(vec3 point, vec3 normal, const Material *material) {

    vec3 resultat = vec3(0.0f);

    for (Light *light:lights) {

        vec3 L = normalize(light->pos - point); // entre punt i llum
        vec3 V = normalize(cam->origin - point); // entre punt i observador
        vec3 H = normalize(L + V);

        float d = distance(light->pos, point);

        vec3 ambient = light->ambient * material->ambient;
        vec3 diffuse = light->diffuse * material->diffuse * glm::max(dot(L, normal), 0.0f);
        vec3 specular =
                light->specular * material->specular * (float) pow(glm::max(dot(normal, H), 0.0f), material->beta);

        float atenuacio = dot(light->atenuacio, vec3(1.0f, d, pow(d, 2)));

        IntersectionInfo *info = new IntersectionInfo();

        float shadowFactor = 1.0f;

        if (this->intersection(Ray(point, L), 0.01f, d, *info)) {
            if (info->mat_ptr->alpha == 1.0f) {
                shadowFactor = 1.0f;

                IntersectionInfo *info2 = new IntersectionInfo();
                if(this->intersection(Ray(info->p, info->p - point), 0.01f, distance(info->p, point), *info2)){
                    if (info2->mat_ptr->alpha != 1.0f) shadowFactor = 0.0f;
                }

            } else {
                shadowFactor = 0.0f;
            }
        }

        resultat += ((diffuse + specular) / atenuacio) * shadowFactor + ambient;
    }

    return resultat;
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i < objects.size(); i++) {
        if (dynamic_cast<Animable *>(objects[i])) objects[i]->update(nframe);
    }
}

void Scene::setMaterials(ColorMap *cm) {

    Material *m;
    // TODO: Fase 0
    // Cal canviar el codi per a afegir més materials.
    // TODO: Fase 2
    // Cal canviar el tipus de material Lambertian, Specular, Transparent, Tipus Textura
    if (cm == nullptr)
        m = new Lambertian(vec3(0.5, 0.2, 0.7));
    else {
        // TODO: Fase 2:
        //  Crear els materials segons la paleta de cada propietat a cada objecte de l'escena
        m = new Lambertian(cm->getColor(0));
    }

    for (auto it = this->objects.begin(); it != this->objects.end(); ++it) {
        if ((*it)->getMaterial() == nullptr) {
            m = new Lambertian(vec3(0.5, 0.2, 0.7));
            /* modify data objects color depending on the value of data */
            if ((*it)->getData() != -1.0) {
                vec3 qwe = cm->getColor((*it)->getData());
                //std::cerr << (*it)->getData() << std::endl;
                //std::cerr << "(" << qwe.r << ", " << qwe.g << ", " << qwe.b << ")" << std::endl;
                m = new Lambertian(cm->getColor((*it)->getData()));
            } else
                m = new Lambertian(vec3(0.5, 0.2, 0.7));
            (*it)->setMaterial(m);
        }
    }
}

void Scene::setDimensions(vec3 p1, vec3 p2) {
    pmin = p1;
    pmax = p2;
}

