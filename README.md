GiV — Práctica 1 :::: Grupo F01
--------
## Abstract

En este proyecto se ha implementado el algoritmo de RayTracing y se ha usado para la visualización de datos de forma realista. Para ello se han empleado diferentes objetos paramétricos como cilindros o  esferas y mallas, algunos como el cilindro se han desarrollado desde cero mientras que otros como las mallas de triángulos se ha complementado el código inicial.
Para poder crear escenas más realistas también se han creado varios materiales para los objetos. A la vez también se ha modificado el código del cálculo del color para incorporar las características de los nuevos materiales o las sombras.
Finalmente se ha diseñado un tipo de escena que permite generar visualizaciones a partir de datos localizados. Esta escena, carga los datos de un fichero y los mapea en un mundo virtual aplicando materiales y colores distintos en función del valor asociado a los datos.
Como ejemplo del punto anterior, se han extraído datos reales del Ayuntamiento de Barcelona sobre los puntos verdes de la ciudad y sus localizaciones para representarlos en un mapa de la ciudad.

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

* <ins>Carga de escena híbridas</ins>: La escena DATA es capaz de cargar diferentes tipos de gizmos a la vez, por ejemplo cilindros y esferas.

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
![](https://i.imgur.com/W5ZBxk0.png)

| Escena:        	| Data - Puntos verdes de Barcelona ([Fichero RAW](https://pastebin.com/6LxqsarW)) 	|
|----------------	|-----------------------------------------------------	|
| Fichero datos: 	| [dataBCNPuntosVerdes.txt](https://github.com/GiVD2019/dataray-f01/blob/master/resources/dataBCNPuntosVerdes.txt)                             	|
| Materiales:    	| ![](https://i.imgur.com/CFfRjly.png)                	|
| Iluminación:   	| ![](https://i.imgur.com/EiAarzO.png)                	|
| Cámara:        	| ![](https://i.imgur.com/ZjNMaqa.png)                	|

![](https://i.imgur.com/cRvJ1t6.png)
![](https://i.imgur.com/41O4k5B.png)

| Escena:        	| Virtual - Esferas 1 ([Fichero RAW](https://pastebin.com/CmmPbZPQ)) 	|
|----------------	|-------------------------------------------------------	|
| Fichero datos: 	| ![](https://i.imgur.com/hO49HRp.png)                  	|
| Materiales:    	| ![](https://i.imgur.com/OgNa6f3.png)                  	|
| Iluminación:   	| ![](https://i.imgur.com/4A0upjI.png)                  	|
| Cámara:        	| ![](https://i.imgur.com/hvthcaW.png)                  	|

![](https://i.imgur.com/VNk8oXn.png)

| Escena:           	| Virtual - Cara 1 ([Fichero RAW](https://pastebin.com/tXJJyAkb)) 	|
|----------------	|----------------------------------------------------	|
| Fichero datos: 	| ![](https://i.imgur.com/ZUnmbFV.png)               	|
| Materiales:    	| ![](https://i.imgur.com/o7ZD2q2.png)               	|
| Iluminación:   	| ![](https://i.imgur.com/cd6W6cY.png)               	|
| Cámara:        	| ![](https://i.imgur.com/ZjNMaqa.png)               	|

![](https://i.imgur.com/aIZxaol.png)

| Escena:           	| Virtual - Cara 2 ([Fichero RAW](https://pastebin.com/QyL0DqLL)) 	|
|----------------	|----------------------------------------------------	|
| Fichero datos: 	| ![](https://i.imgur.com/nPQCCCN.png)               	|
| Materiales:    	| ![](https://i.imgur.com/Cde0Mfx.png)               	|
| Iluminación:   	| ![](https://i.imgur.com/LMXy8pJ.png)               	|
| Cámara:        	| ![](https://i.imgur.com/J3vgqpe.png)               	|

![](https://i.imgur.com/oMPQ8ZA.png)

| Escena:           	| Data - Hospitales de Barcelona ([Fichero RAW](https://pastebin.com/BFJ5hnsj)) 	|
|----------------	|-------------------------------------------------------------------------------	|
| Fichero datos: 	| ![](https://i.imgur.com/VJbjZU8.png)                                          	|
| Iluminación:   	| ![](https://i.imgur.com/rpOMVCd.png)                                          	|
| Cámara:        	| ![](https://i.imgur.com/lKXuib1.png)                                          	|



## Additional 
<table>
  <tbody>
    <tr>
      <th>Fase</th>
      <th align="center">Horas</th>
      <th align="right">Problemas</th>
    </tr>
    <tr>
      <td>0</td>
      <td align="center">9999</td>
      <td align="right">
          <li>item1</li>
          <li>item2</li>
     </td>
    </tr>
      <tr>
      <td>1</td>
      <td align="center">9999</td>
      <td align="right">
          <li>item1</li>
          <li>item2</li>
     </td>
    </tr>
      <tr>
      <td>2</td>
      <td align="center">9999</td>
      <td align="right">
          <li>item1</li>
          <li>item2</li>
     </td>
    </tr>
      <tr>
      <td>3</td>
      <td align="center">9999</td>
      <td align="right">
          <li>item1</li>
          <li>item2</li>
     </td>
    </tr>
  </tbody>
</table>
