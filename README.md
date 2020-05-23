# GiV — Práctica 2 :::: Grupo F01
VisualDataGPU (2019-20): Visualització utilitzant la GPU

## Abstract

En este proyecto se ha implementado el algoritmo de RayTracing y se ha usado para la visualización de datos de forma realista. Para ello se han empleado diferentes objetos paramétricos como cilindros o  esferas y mallas, algunos como el cilindro se han desarrollado desde cero mientras que otros como las mallas de triángulos se ha complementado el código inicial.
Para poder crear escenas más realistas también se han creado varios materiales para los objetos. A la vez también se ha modificado el código del cálculo del color para incorporar las características de los nuevos materiales o las sombras.
Finalmente se ha diseñado un tipo de escena que permite generar visualizaciones a partir de datos localizados. Esta escena, carga los datos de un fichero y los mapea en un mundo virtual aplicando materiales y colores distintos en función del valor asociado a los datos.
Como ejemplo del punto anterior, se han extraído datos reales del Ayuntamiento de Barcelona sobre los puntos verdes de la ciudad y sus localizaciones para representarlos en un mapa de la ciudad.

## Features

* Fase 1:
    - Material - Rodrigo, Jin, Oriol
    - Light
        - [X] Puntual - Rodrigo, Jin, Abdel, Oriol
        - [X] Direccional - Rodrigo, Jin, Abdel, Oriol
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

* <ins>Gouraud Textura</ins> - Jin
* <ins>Read colormap</ins> - Rodrigo
* <ins>Autocarga de ficheros y escenas:</ins> - Rodrigo
    - <ins>Autocarga de datos:</ins> Carga automática de ficheros en el formulario de datos. Para una depuración y correción más sencilla.
        ![](https://i.imgur.com/7P5v6Kl.jpg)
    - <ins>Autocarga de objeto:</ins> Carga automáticamente una esfera. Nos ha sido muy útil durante el desarrollo de los shaders.
        ![](https://i.imgur.com/MdvgSeU.jpg)
    
    
## Screenshots
![](https://i.imgur.com/ilWE1gr.png)
![](https://i.imgur.com/YPnpzvq.png)
![](https://i.imgur.com/fmDUMzs.png)
![](https://i.imgur.com/JwDMUkN.png)
![](https://i.imgur.com/2IlawOx.png)

## Additional Information
<table>
  <tbody>
    <tr>
      <th>Fase</th>
      <th align="center">Horas</th>
      <th align="center">Problemas</th>
    </tr>
    <tr>
      <td>0</td>
      <td align="center">15</td>
      <td align="right">
          <li>Incompatibilidad del proyecto con Windows. Mucho tiempo perdido intentado instalar las librerías necesarias.</li>
     </td>
    </tr>
      <tr>
      <td>1</td>
      <td align="center">25</td>
      <td align="left">
          <li>Depurar en los shaders. Los errores que da al compilar los ficheros .glsl son muy vastos, y encontrar un pequño error                 se hace bastante complicado. A esto se le suma que no hemos encontrado ninguna herramienta para validar/compilar los shaders            de forma externa.</li>
     </td>
    </tr>
      <tr>
      <td>2</td>
      <td align="center">18</td>
      <td align="left">
          <li>Asd.</li>
     </td>
    </tr>
  </tbody>
</table>
