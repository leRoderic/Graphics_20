# VisualDataGPU
Pràctica 2 (2019-20): Visualització utilitzant la GPU

## Abstract

En este proyecto se ha implementado el algoritmo de RayTracing y se ha usado para la visualización de datos de forma realista. Para ello se han empleado diferentes objetos paramétricos como cilindros o  esferas y mallas, algunos como el cilindro se han desarrollado desde cero mientras que otros como las mallas de triángulos se ha complementado el código inicial.
Para poder crear escenas más realistas también se han creado varios materiales para los objetos. A la vez también se ha modificado el código del cálculo del color para incorporar las características de los nuevos materiales o las sombras.
Finalmente se ha diseñado un tipo de escena que permite generar visualizaciones a partir de datos localizados. Esta escena, carga los datos de un fichero y los mapea en un mundo virtual aplicando materiales y colores distintos en función del valor asociado a los datos.
Como ejemplo del punto anterior, se han extraído datos reales del Ayuntamiento de Barcelona sobre los puntos verdes de la ciudad y sus localizaciones para representarlos en un mapa de la ciudad.

## Features

* Fase 1:
    - [X] Light - Abdel, Jin, Rodrigo, Oriol
    - [X] Material - Oriol, Rodrigo, Jin
    - [X] Blinn-Phong shader - Abdel
    - [X] Goroud Shader - Rodrigo
    - [X] Toon Shader - Oriol, Abdel
    - [X] Modificaciones UI - Rodrigo
    - [X] Texturas - Jin, Abdel
    - [X] Data visualization - Rodrigo
* Fase 2:
    - [X] Animaciones - Oriol


## Extensiones

* <ins>Luz spotlight<ins> - Oriol
* <ins>Goroud Textura<ins> - Jin
* <ins>Indirect texture mapping<ins> - Abdel
* <ins>Read colormap<ins> - Rodrigo
* <ins>Autocarga de ficheros y escenas<ins> - Rodrigo
