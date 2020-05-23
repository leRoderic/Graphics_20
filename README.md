# VisualDataGPU
Pràctica 2 (2019-20): Visualització utilitzant la GPU

## Abstract

En este proyecto se ha implementado el algoritmo de RayTracing y se ha usado para la visualización de datos de forma realista. Para ello se han empleado diferentes objetos paramétricos como cilindros o  esferas y mallas, algunos como el cilindro se han desarrollado desde cero mientras que otros como las mallas de triángulos se ha complementado el código inicial.
Para poder crear escenas más realistas también se han creado varios materiales para los objetos. A la vez también se ha modificado el código del cálculo del color para incorporar las características de los nuevos materiales o las sombras.
Finalmente se ha diseñado un tipo de escena que permite generar visualizaciones a partir de datos localizados. Esta escena, carga los datos de un fichero y los mapea en un mundo virtual aplicando materiales y colores distintos en función del valor asociado a los datos.
Como ejemplo del punto anterior, se han extraído datos reales del Ayuntamiento de Barcelona sobre los puntos verdes de la ciudad y sus localizaciones para representarlos en un mapa de la ciudad.

## Features

* Fase 1:
    - Material - Rodrigo, Jin, Oriol
    - Light
        - [X] Puntual - Rodrigo, Jin, Abdel
        - [X] Direccional - Rodrigo, Jin, Abdel
        - [X] Spotlight - Oriol
        - [X] Ambient Global - Rodrigo, Jin, Abdel
    - Shading
        - [X] Phong - Abdel
        - [X] Gouroud - Rodrigo
        - [X] Toon - Oriol, Abdel
    - Textures
        - [X] Textura com material - Jin, Abdel
        - [X] Mapping indirecte - Abdel
- Fase 2 
    - [X] Animacions amb dades temporals - Oriol
    - [ ] Normal mapping
    - [ ] Entorn amb textures
    - [ ] Reflexions
    - [ ] Transparencias via objectes.
    - [ ] Transparencias via environmental mapping.


## Extensiones

* <ins>Gouraud Textura<ins> - Jin
* <ins>Read colormap<ins> - Rodrigo
* <ins>Autocarga de ficheros y escenas<ins> - Rodrigo
    
    
Screenshots
^^^^^^^^^^^
*(NOTA: Capturas de pantalla de las pruebas que hayáis realizado)*

Additional Information
^^^^^^^^^^^^^^^^^^^^^^
*(NOTA: Horas de dedicación y problemas principales que hayáis tenido durante la realización de las prácticas)*
