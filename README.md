# GiV — Práctica 2 :::: Grupo F01
VisualDataGPU (2019-20): Visualitzación usando la GPU

## Abstract

Este proyecto usa la visualización proyectiva con Z-Buffer para la visualización y representación de datos mediante la GPU.  
Implementa una interfaz, desarrollada en QtCreator, que permite visualizar los modelos en tiempo real así como cambiar los parámetros de la cámara sin terminar la ejecución.  
También permite la selección de distintos shaders (Gouraud, Toon y Phong entre otros)  así como la inclusión de texturas en los objetos o la carga de escenas predeterminadas, ya sean basadas en datos y con paletas de colores personalizadas o simplemente en unos pocos objetos.  
Se han adaptado y reutilizado clases de la entrega anterior, las relacionadas con el procesamiento de ficheros virtuales y creación de distintos tipos de escenas. A otras como Material o Light, se les ha incorporado las funciones necesarias para enviar los datos a la GPU.  
Por último, se han añadido un par de acciones que permiten la carga automática de recursos. Esto no solo nos ha evitado perder mucho tiempo en cada ejecución buscando y cargando los datos sino que además nos ha llevado a experimentar con el envío y rececpción de señales entre las ventanas y las múltiples clases involucradas. Creemos también facilitará la correción 😉.

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
![](https://i.imgur.com/HlKrSc6.png)
![](https://i.imgur.com/8GZrs4D.png)
![](https://i.imgur.com/X17DW3d.png)
![](https://i.imgur.com/nhzNVDE.png)
![](https://i.imgur.com/ZCZZzJb.png)
![](https://i.imgur.com/ilWE1gr.png)
![](https://i.imgur.com/YPnpzvq.png)
![](https://i.imgur.com/fmDUMzs.png)
![](https://i.imgur.com/JwDMUkN.png)
![](https://i.imgur.com/2IlawOx.png)
![](https://i.imgur.com/r9sZTWl.jpg)

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
      <td align="left">
          <li>Incompatibilidad del proyecto con Windows. Mucho tiempo perdido intentado instalar las librerías necesarias.</li>
     </td>
    </tr>
      <tr>
      <td>1</td>
      <td align="center">25</td>
      <td align="left">
          <li>Depurar en los shaders. Los errores que da al compilar los ficheros .glsl son muy vastos, y encontrar un pequeño error                 se hace bastante complicado. A esto se le suma que no hemos encontrado ninguna herramienta para validar/compilar los shaders            de forma externa.</li>
     </td>
    </tr>
      <tr>
      <td>2</td>
      <td align="center">18</td>
      <td align="left">
          <li>Colisión con las funciones de translación.</li>
     </td>
    </tr>
  </tbody>
</table>
