# Sistema de Recomendación de Películas

![Sistema de Recomendación de Películas](resources/icon.png)

## Índice
- [Introducción](#introducción)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)
- [Patrones de Diseño](#patrones-de-diseño)
- [Algoritmos y Estructuras de Datos](#algoritmos-y-estructuras-de-datos)
- [Programación Genérica](#programación-genérica)
- [Programación Concurrente](#programación-concurrente)
- [Namespaces](#namespaces)
- [Manejo de Errores](#manejo-de-errores)
- [Video](#Link-del-video-explicativo)
- [Bibliografía](#bibliografía)
- [Contribuyentes](#contribuyentes)


## Introducción
El Sistema de Recomendación de Películas es una aplicación en C++ diseñada para ayudar a los usuarios a buscar películas por título o etiquetas, y recibir recomendaciones basadas en sus gustos. Emplea varios patrones de diseño y algoritmos para garantizar un rendimiento eficiente y una interfaz amigable.

## Características
- Búsqueda de películas por título o etiqueta.
- Posibilidad de dar "Me gusta" a las películas y ver recomendaciones basadas en las películas que te gustan.
- Agregar películas a una lista de "Ver más tarde".
- Resultados de búsqueda paginados.
- Interfaz de consola intuitiva e interactiva con soporte para colores.

## Instalación
Para instalar y ejecutar el Sistema de Recomendación de Películas, sigue estos pasos:

1. Clona el repositorio:
    ```bash
    git clone https://github.com/markjesusjh/Proyecto_PrograIII.git
    ```

2. Navega al directorio del proyecto:
    ```bash
    cd Proyecto_PrograIII
    ```
3. Descargar y agregar el archivo "mpst_full_data.csv" en el directorio de Proyecto_PrograIII

    link del archivo
   [https://drive.google.com/file/d/1iusSIbmXJW_OUBm6X7Ik593rgCGPCPza/view]
   
4. Construye el proyecto usando CMake:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

5. Ejecuta el archivo ejecutable:
    ```bash
    ./Proyecto_PrograIII
    ```

## Uso
Al ejecutar la aplicación, se te presentarán las siguientes opciones:

1. Buscar por título
2. Buscar por etiqueta
3. Ver películas que me gustaron
4. Ver lista de "Ver más tarde"
5. Salir

### Ejemplo de Uso
- Busca películas ingresando un título o etiqueta.
- Ve la sinopsis y elige si te gusta o si quieres verla más tarde.
- Ve recomendaciones basadas en las películas que te gustan.

## Patrones de Diseño
En este proyecto se utilizan los siguientes patrones de diseño:
1. **Singleton**: Para gestionar la instancia de la base de datos de películas.
2. **Factory Method**: Para la creación de instancias de películas.
3. **Observer**: Para manejar los cambios en las listas de "Me gusta" y "Ver más tarde".
4. **Strategy**: Para diferentes estrategias de búsqueda (por título, por etiqueta).
5. **Command**: Para encapsular las acciones del usuario como dar "Me gusta" o agregar a "Ver más tarde".

## Algoritmos y Estructuras de Datos
El proyecto hace uso de algoritmos y estructuras de datos eficientes, incluyendo:
- **Búsqueda Binaria**: Para una búsqueda rápida de películas.
- **Hash Maps**: Para acceso rápido a los datos de las películas.
- **Sets**: Para gestionar colecciones únicas de películas que te gustan y de "Ver más tarde".
- **Ordenamiento y filtrado personalizados**: Para mostrar las 10 mejores películas recomendadas.

## Programación Genérica
La programación genérica se utiliza en el proyecto para crear funciones y clases que puedan trabajar con cualquier tipo de datos. Por ejemplo, se utiliza una función genérica de búsqueda que puede operar tanto sobre títulos como sobre etiquetas.

## Programación Concurrente
La programación concurrente se implementa para mejorar el rendimiento en las búsquedas. Utilizamos `std::thread` y `std::future` para realizar operaciones en paralelo, permitiendo que las búsquedas sean más rápidas y eficientes.

## Namespaces
El proyecto utiliza namespaces para organizar el código y evitar conflictos de nombres. Los principales namespaces utilizados son:

- `Utilities`: Contiene las estructuras y funciones utilitarias.
- `MovieDB`: Contiene las clases relacionadas con la base de datos de películas.
- `UI`: Contiene las clases relacionadas con la interfaz de usuario.
- `Search`: Contiene las estrategias de búsqueda.

## Manejo de Errores
La aplicación incluye un manejo robusto de errores para asegurar una experiencia de usuario fluida:
- Manejo adecuado de entradas inválidas.
- Provisión de retroalimentación para acciones (dar "Me gusta", agregar a "Ver más tarde").
- Gestión eficiente de memoria y limpieza de recursos.

## Link del video explicativo
[https://drive.google.com/drive/folders/1L1ace5JHIzD2C6N2l7PLPldDwHFuyBfd?usp=sharing]

## Bibliografía
1. Gamma, E., Helm, R., Johnson, R., & Vlissides, J. (1994). *Design Patterns: Elements of Reusable Object-Oriented Software*. Addison-Wesley Professional.
2. Meyers, S. (2005). *Effective C++: 55 Specific Ways to Improve Your Programs and Designs*. Addison-Wesley Professional.
3. Josuttis, N. M. (2012). *The C++ Standard Library: A Tutorial and Reference*. Addison-Wesley Professional.
4. Coplien, J. O. (1992). *Advanced C++ Programming Styles and Idioms*. Addison-Wesley Professional.

## Contribuyentes

| **David Quispe** | 
|:------------:|
| ![David Quispe](https://avatars.githubusercontent.com/u/91276766?v=4) | 
| [https://github.com/DavidUTECo](https://github.com/DavidUTECo) |

| **Mark Jesus** | 
|:------------:|
| ![Mark Jesus](https://avatars.githubusercontent.com/u/91276766?v=4) | 
| [https://github.com/markjesusjh](https://github.com/markjesusjh) |

| **Fernando Padilla** | 
|:------------:|
| ![Fernando Padilla](https://avatars.githubusercontent.com/u/91276766?v=4) | 
| [https://github.com/nosoyfernandow](https://github.com/nosoyfernandow) |
