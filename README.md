# De qué trata el proyecto?
Mi proyecto consiste en un gestor de tareas, que es una programa que permite a los usuarios gestionar y organizar sus tareas diarias de manera eficiente. 
Sirve como una herramienta para ayudar a las personas a mantenerse organizadas, establecer prioridades y realizar un seguimiento de sus actividades pendientes. 

# Cómo funciona? 
Las funcionalidades clave de este gestor de tareas son las siguientes:
1.  **Agregar tareas:** Los usuarios pueden agregar nuevas tareas a su lista, proporcionando una descripción de la tarea y, en el caso de tareas programadas, una fecha límite. 
2. **Marcar tareas como completadas:** Los usuarios pueden marcar las tareas como completadas una vez que han sido realizadas.
3. **Organizar tareas:** Las tareas pueden ser organizadas por categoría, prioridad o fecha de vencimiento, según las necesidades del usuario. 
4. **Visualización de tareas:** Los usuarios pueden ver todas sus tareas en una lista, con información sobre su estado (completada o no) y otros detalles relevantes. 
5. **Gestión de usuarios:** Permite a los usuarios crear y gestionar sus cuentas, con información como nombre, correo electrónico, etc. 

Los beneficios del gestor de tareas son los siguientes:
- Organización: Ayuda a los usuarios a organizar sus tareas diarias y a tener una visión clara de lo que deben hacer. 
- Productividad: Al tener una lista estructurada de tareas, los usuarios pueden priorizar y completar sus actividades de manera más eficiente.
- Seguimiento: Permite a los usuarios realizar un seguimiento de su progreso y ver qué tareas han completado y cuáles quedan pendientes. 

En resumen, este gestor de tareas es una herramienta útil para cualquier persona que busque mejorar su organización y productividad al gestionar sus tareas diarias de manera efectiva.

# Clases utilizadas en el programa
1.  **TareaBase:** Esta clase sirve como base para todas las tareas y define la estructura básica de una tarea.
2.  **TareaSimple:** Esta clase hereda de Task y representa una tarea sin fecha de vencimiento ni categoría.
3.  **TareaProgramada:** Esta clase también hereda de Task y representa una tarea con fecha de vencimiento y hora programada.
4.  **ListaTareas:** Esta clase gestiona una lista de tareas para un usuario específico.
5.  **Usuario:** Esta clase contiene información sobre el usuario y proporciona métodos para acceder y modificar esta información.

# Fallos
1. **Fallos en la programación de tareas con fecha:** Si el usuario no escribe de manera correcta las fechas de vencimiento de las tareas programadas como muestra el ejemplo, no se agrega exitosamente la tarea y tendria que ingresar nuevamente la tarea de la manera correcta.

# Bibliotecas
Para mi proyecto utilicé únicamente 4 bibliotecas las cuales fueron:
- Iostream: Se utiliza para la entrada y salida estándar. (Para leer datos del usuario desde la consola y enseñar los resultados.)
- Ctime: Se utiliza para cuando se trabaja con fechas. En mi proyecto la utilicé para convertir cadenas de fecha en el siguiente formato ("YYYY-MM-DD).
- String: Se utiliza para cuando se trabaja con cadenas de caractéres ('string'). En mi proyecto lo utilicé para las descripciones de tareas, nombre del usuario y sus correos.
- Vector: Se utiliza para cuando se trabaja con vectores. En mi proyecto lo utilicé para almacenar las tareas en la lista de tareas.

# Revaluación
- Competencia: "SICT0301A Evalúa los componentes que integran una problemática."
  - Identifico de manera correcta las clases a utilizar para solucionar el problema
  - Identifico los casos que harían que el proyecto deje de funcionar
  - Genero un diagrama de clases UML correcto y y explico su relación con el problema de         forma clara
- Competencia: "SICT0303A Implementa acciones científicas"
  - Se implementa de manera correcta el concepto de Herencia
  -  Se implementa de manera correcta la sobrecarga y sobreescritura de métodos
  -  Se implementa de manera correcta el concepto de Clases Abstractas






