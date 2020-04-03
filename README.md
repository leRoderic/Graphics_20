GiV — Práctica 1 :::: Grupo F01
--------
## Abstract

*(NOTA: Un pequeño resumen de lo que habéis hecho, no mas de 200 palabras)*

## Features

* Figures:
    - [X] Triangle - Qijun
    - [X] Cilynder - Abdel
    - [X] Boundary Object - Rodrigo
* Blinn-Phong:
    - [X] Light - Abdel, Qijun
    - [X] Basic Blinn-Phong - Rodrigo
    - [X] Reflection - Abdel, Qijun, Rodrigo
    - [X] Transparency - Abdel, Qijun, Rodrigo
* Material:
    - [X] Metal - Abdel, Qijun
    - [X] Transparent - Abdel, Qijun, Rodrigo
    - [X] Texture - Oriol, Qijun
* Data:
    - [X] Situación en el mapa - Oriol, Qijun, Rodrigo
    - [X] Textura en el plano - Oriol, Qijun
    - [X] Nuevas escenas - Abdel, Oriol, Rodrigo

## Extensions

*(NOTA: Las extensiones de la práctica que hayáis implementado y que no estén listadas en el apartado anterior)*

## Screenshots
![](https://i.imgur.com/kM5vTC3.png)
![](https://i.imgur.com/D6UvTQo.png)
![](https://i.imgur.com/H5Df2hu.png)
![](https://i.imgur.com/xTPIUK6.png)
![](https://i.imgur.com/dt4UBGX.png)
![](https://i.imgur.com/Oetp8uE.png)
![](https://i.imgur.com/I2TYz5u.png)
![](https://i.imgur.com/N5AwqlP.png)
![](https://i.imgur.com/8kULdvL.png)
NO ES DEFINITIVA
![](https://i.imgur.com/NR603ao.png)
![](https://i.imgur.com/cRvJ1t6.png)
![](https://i.imgur.com/41O4k5B.png)
| **Escena:** 	| Virtual 	|  	|  	|  	|
|----------------	|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|---	|---	|---	|
| Fichero datos: 	| ``` sphere, 0, 0, -100, 100  sphere, 0, -3.5, 4, 1.5  sphere, -3.5, 0, 4, 1.5  sphere, 0, 3.5, 4, 1.5  sphere, 3.5, 0, 4, 1.5  sphere, 4, 4, 1, 1.5  sphere, 4, -4, 1, 1.5  sphere, -4, -4, 1, 1.5  sphere, -4, 4, 1, 1.5  sphere, 0, 0, 8, 1  ``` 	|  	|  	|  	|
| Materiales: 	| ```cpp s->objects[0]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));  s->ground = s->objects[0]; s->objects[1]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[2]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[3]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[4]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[5]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[6]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[7]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[8]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f)); s->objects[9]->setMaterial(new Mate(vec3(0.2f), vec3(0.5f), vec3(1.0f), 10, 1.0f));  ``` 	|  	|  	|  	|
| Iluminación: 	| ```cpp s->ambientGlobal = vec3(0.1f); s->lights.push_back(new Light(vec3(-30, 0, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01))); s->lights.push_back(new Light(vec3(30, 0, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01))); s->lights.push_back(new Light(vec3(0, -30, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01))); s->lights.push_back(new Light(vec3(0, 30, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));  ``` 	|  	|  	|  	|
## Additional 
*(NOTA: Horas de dedicación y problemas principales que hayáis tenido durante la realización de las prácticas)*
