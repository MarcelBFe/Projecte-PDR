🗺️ EL PLAN DE TRABAJO (Hoja de Ruta)
📍 PASO PREVIO (Para los dos juntos)
Cread los archivos vacíos en vuestra carpeta: tasca.c, carpeta.c, organitzador.c y tests.c.
Haced un primer commit en GitHub con esos archivos vacíos para que ambos tengáis la misma base.
🟢 FASE 1: Estructuras Base (tasca.c y tests.c)
El objetivo aquí es dominar la entrada/salida básica de la consola y mover elementos en un array estático.
Miembro 1:
Abre tasca.c y programa llegeix_nou_comentari y mostra_comentari.
Programa llegeix_nova_tasca y mostra_tasca.
Abre tests.c y programa tests_tasca1(). (Llamad a esta función desde el main.c temporalmente para probar que funciona).
Miembro 2: (Puede esperar a que M1 acabe o hacerlo en paralelo)
Abre tasca.c y programa insereix_comentari y elimina_comentari.
Abre tests.c y programa tests_tasca2().
🟡 FASE 2: El Núcleo del Proyecto (carpeta.c y tests.c)
Aquí entra la lógica dura: fechas como enteros y arrays ordenados.
Miembro 1 (Funciones base y Búsquedas):
En carpeta.c, programa llegeix_nova_data y mostra_data.
Programa llegeix_nova_carpeta y mostra_carpeta.
Programa cerca_data y cerca_tasca (Búsquedas lineales usando bucles for).
En tests.c, programa tests_carpeta1().
Miembro 2 (Inserciones Ordenadas y Borrados):
En carpeta.c, programa insereix_nova_data (orden cronológico creciente).
Programa insereix_nova_tasca (orden de prioridad decreciente).
Programa elimina_tasca y neteja_dates_buides.
En tests.c, programa tests_carpeta2() y tests_carpeta3().
🟠 FASE 3: El Gestor Global (organitzador.c y tests.c)
Gestión de la estructura general que contiene todo.
Miembro 1:
En organitzador.c, programa cerca_carpeta.
Programa mostra_carpetes y mostra_contingut_carpeta.
En tests.c, programa tests_organitzador1().
Miembro 2:
En organitzador.c, programa insereix_nova_carpeta (orden alfabético).
Programa elimina_carpeta y neteja_dates_buides_carpetes.
En tests.c, programa tests_organitzador2().
🔴 FASE 4: Interfaz de Usuario (main.c)
Unir todas las piezas del puzzle.
Ambos: Limpiad el main.c de las pruebas anteriores (quitad las llamadas a tests_...()).
Miembro 2: Programa el bucle do-while en la función main() con un switch/case que controle qué letra introduce el usuario. Programa también las funciones modificadoras (processa_opcio_nova_carpeta, processa_opcio_nova_data, etc.).
Miembro 1: Completa mostrar_ajuda() (si le falta algo) y programa las funciones de visualización (processa_opcio_mostra_carpetes, etc.). Asegúrate de que el formato de salida sea idéntico al del PDF.
🚀 CÓMO EMPEZAR AHORA MISMO (FASE 1)
Decidid quién va a empezar (si el Miembro 1 o el Miembro 2). Vamos a ponernos con tasca.c.
Si sois el Miembro 1, vuestro objetivo es:
Leer un comentario (texto) por teclado y devolverlo.
Mostrar ese comentario.
Leer una tarea (título y prioridad) por teclado y devolverla.
Mostrar esa tarea (título, prioridad y sus comentarios si los tiene).
¿Cómo afrontar las funciones del Miembro 1 (Pistas conceptuales)?
Variables locales: Para devolver un t_comentari o t_tasca, primero tienes que crear una variable de ese tipo dentro de la función (ej: t_tasca nova;), rellenarla y hacer return nova;.
Inicializar arrays: Al crear una tarea nueva, ¡no tiene comentarios! Así que asegúrate de poner su contador (nova.ncomentaris = 0;).
Validación: El PDF pide que si la prioridad no está entre 1 y 3 (usando MIN_PRI y MAX_PRI), se avise al usuario y se vuelva a pedir. Usa un bucle do { ... } while (...); para esto.
Si sois el Miembro 2, vuestro objetivo es:
Meter un comentario en la posición [0] de una tarea, empujando los demás.
Borrar un comentario concreto, desplazando los demás para tapar el hueco.
¿Cómo afrontar las funciones del Miembro 2 (Pistas conceptuales)?
Paso por referencia: Tus funciones reciben un t_tasca *tas. Esto es un puntero. Para acceder a los campos, no uses un punto (.), usa la flecha (->). Ejemplo: tas->ncomentaris.
El límite del array: Antes de insertar, comprueba si tas->ncomentaris == MAX_COM. Si es igual, retorna -1 y no hagas nada más.
Desplazamiento a la derecha (para insertar): Tienes que hacer un for que empiece desde el final del array (donde haya comentarios) y vaya copiando el de la izquierda a la derecha. Piensa bien cómo hacer el bucle para no machacar datos.
