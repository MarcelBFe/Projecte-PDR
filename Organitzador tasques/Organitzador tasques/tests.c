#include <stdio.h>
#include "tests.h"
#include "tasca.h"
#include "carpeta.h"
#include "organitzador.h"


void tests_tasca1() {
    printf("--- INICI TEST TASCA 1 ---\n");

    t_tasca mi_tarea;
    mi_tarea = llegeix_nova_tasca();
    
    printf("\nComprovant mostra_tasca:\n");
    mostra_tasca(mi_tarea);

    printf("\nAra provarem els comentaris:\n");
    t_comentari mi_comentario;
    mi_comentario = llegeix_nou_comentari();
    
    printf("\nComprovant mostra_comentari:\n");
    mostra_comentari(mi_comentario);

    printf("\n--- FI TEST TASCA 1 ---\n");
}


/* Llegim una nova tasca i 3 comentaris, els inserim i n'eliminem un per
   comprovar que insereix_comentari i elimina_comentari funcionen correctament. */
void tests_tasca2() {
    printf("\n--- INICI TEST TASCA 2 ---\n");

    /* Llegim la nova tasca */
    t_tasca mi_tasca;
    mi_tasca = llegeix_nova_tasca();

    /* Llegim 3 comentaris diferents */
    printf("\nIntroduiex el comentari 1:\n");
    t_comentari c1 = llegeix_nou_comentari();
    printf("Introduiex el comentari 2:\n");
    t_comentari c2 = llegeix_nou_comentari();
    printf("Introduiex el comentari 3:\n");
    t_comentari c3 = llegeix_nou_comentari();

    /* Inserim els 3 comentaris a la tasca (cada nou comentari va a la posicio 0) */
    insereix_comentari(&mi_tasca, c1);
    insereix_comentari(&mi_tasca, c2);
    insereix_comentari(&mi_tasca, c3);

    /* Eliminem el comentari numero 1 (es pot canviar per provar amb el 2 o el 3) */
    printf("\nEliminant el comentari numero 1...\n");
    elimina_comentari(&mi_tasca, 1);

    /* Mostrem el resultat final de la tasca */
    printf("\nResultat del test (tasca amb 2 comentaris):\n");
    mostra_tasca(mi_tasca);

    printf("\n--- FI TEST TASCA 2 ---\n");
}


void tests_carpeta1() {
    printf("\n--- INICI TEST CARPETA 1 ---\n");

    t_carpeta mi_carpeta = llegeix_nova_carpeta();

    printf("Introduce la fecha 1 (ej: 31/12/2026):\n");
    t_data d1 = llegeix_nova_data();
    printf("Introduce la fecha 2 (ej: 01/01/2026):\n");
    t_data d2 = llegeix_nova_data();
    printf("Introduce la fecha 3 (ej: 15/06/2026):\n");
    t_data d3 = llegeix_nova_data();

    insereix_nova_data(&mi_carpeta, d1);
    insereix_nova_data(&mi_carpeta, d2);
    insereix_nova_data(&mi_carpeta, d3);

    printf("\nResultat del test (haurien de sortir ordenades):\n");
    mostra_carpeta(mi_carpeta);

    printf("\n--- FI TEST CARPETA 1 ---\n");
}


/* Llegim una carpeta, una data i 3 tasques. Inserim la data a la carpeta i
   les tasques a la data. Despres eliminem una tasca per provar elimina_tasca.
   Al mostrar la carpeta, les tasques han de sortir ordenades per prioritat
   decreixent. */
void tests_carpeta2() {
    printf("\n--- INICI TEST CARPETA 2 ---\n");

    /* Llegim una nova carpeta */
    t_carpeta mi_carpeta = llegeix_nova_carpeta();

    /* Llegim una data i la inserim a la carpeta */
    printf("Introdueix la data (ex: 24/04/2026):\n");
    t_data mi_data = llegeix_nova_data();
    insereix_nova_data(&mi_carpeta, mi_data);

    /* Busquem la data dins la carpeta per poder afegir-hi tasques */
    t_data *p_data = cerca_data(&mi_carpeta, mi_data);

    /* Llegim 3 tasques amb prioritats diferents i les inserim a la data */
    printf("\nIntrodueix la tasca 1 (prova prioritat 1):\n");
    t_tasca t1 = llegeix_nova_tasca();
    printf("Introdueix la tasca 2 (prova prioritat 3):\n");
    t_tasca t2 = llegeix_nova_tasca();
    printf("Introdueix la tasca 3 (prova prioritat 2):\n");
    t_tasca t3 = llegeix_nova_tasca();

    insereix_nova_tasca(p_data, t1);
    insereix_nova_tasca(p_data, t2);
    insereix_nova_tasca(p_data, t3);

    /* Eliminem la tasca t1 (la que te prioritat mes baixa) per provar elimina_tasca */
    printf("\nEliminant la tasca: %s\n", t1.titol);
    elimina_tasca(p_data, t1.titol);

    /* Mostrem la carpeta: les tasques han d'estar ordenades per prioritat decreixent */
    printf("\nResultat del test (tasques ordenades per prioritat decreixent):\n");
    mostra_carpeta(mi_carpeta);

    printf("\n--- FI TEST CARPETA 2 ---\n");
}


/* Llegim una carpeta i 3 dates buides. Les inserim a la carpeta i despres
   cridem neteja_dates_buides. La carpeta ha de quedar sense cap data. */
void tests_carpeta3() {
    printf("\n--- INICI TEST CARPETA 3 ---\n");

    /* Llegim una nova carpeta */
    t_carpeta mi_carpeta = llegeix_nova_carpeta();

    /* Llegim 3 dates diferents (totes buides, sense cap tasca) */
    printf("Introdueix la data 1:\n");
    t_data d1 = llegeix_nova_data();
    printf("Introdueix la data 2:\n");
    t_data d2 = llegeix_nova_data();
    printf("Introdueix la data 3:\n");
    t_data d3 = llegeix_nova_data();

    /* Inserim les 3 dates a la carpeta */
    insereix_nova_data(&mi_carpeta, d1);
    insereix_nova_data(&mi_carpeta, d2);
    insereix_nova_data(&mi_carpeta, d3);

    /* Netegem les dates buides de la carpeta */
    int eliminades = neteja_dates_buides(&mi_carpeta);
    printf("\nS'han eliminat %d dates buides.\n", eliminades);

    /* Mostrem la carpeta: ha de quedar sense cap data */
    printf("\nResultat del test (la carpeta no ha de tenir cap data):\n");
    mostra_carpeta(mi_carpeta);

    printf("\n--- FI TEST CARPETA 3 ---\n");
}


void tests_organitzador1() {
    printf("\n--- INICI TEST ORGANITZADOR 1 ---\n");

    /* Llegim 3 noves carpetes */
    printf("Introdueix la primera carpeta:\n");
    t_carpeta c1 = llegeix_nova_carpeta();
    printf("Introdueix la segona carpeta:\n");
    t_carpeta c2 = llegeix_nova_carpeta();
    printf("Introdueix la tercera carpeta:\n");
    t_carpeta c3 = llegeix_nova_carpeta();

    /* Les inserim a un organitzador */
    t_organitzador mi_org;
    mi_org.ncarpetes = 0;
    insereix_nova_carpeta(&mi_org, c1);
    insereix_nova_carpeta(&mi_org, c2);
    insereix_nova_carpeta(&mi_org, c3);

    /* Mostrem el titol de totes les carpetes inserides */
    printf("\nLlista de carpetes (han de sortir en ordre alfabetic):\n");
    mostra_carpetes(&mi_org);

    /* Mostrem el contingut complet d'una d'elles */
    printf("\nMostrant el contingut complet de la carpeta: %s\n", c1.titol);
    mostra_contingut_carpeta(&mi_org, c1.titol);

    printf("\n--- FI TEST ORGANITZADOR 1 ---\n");
}


/* Llegim 3 carpetes i les inserim a un organitzador. Afegim 2 dates a una
   carpeta, eliminem una carpeta buida i mostrem les carpetes restants. Al
   final cridem neteja_dates_buides_carpetes per veure que s'eliminen les
   dues dates inserides. */
void tests_organitzador2() {
    printf("\n--- INICI TEST ORGANITZADOR 2 ---\n");

    /* Creem un nou organitzador buit */
    t_organitzador mi_org;
    mi_org.ncarpetes = 0;

    /* Llegim 3 carpetes noves */
    printf("Introdueix la carpeta 1:\n");
    t_carpeta c1 = llegeix_nova_carpeta();
    printf("Introdueix la carpeta 2:\n");
    t_carpeta c2 = llegeix_nova_carpeta();
    printf("Introdueix la carpeta 3:\n");
    t_carpeta c3 = llegeix_nova_carpeta();

    /* Inserim les 3 carpetes a l'organitzador (s'ordenaran alfabeticament) */
    insereix_nova_carpeta(&mi_org, c1);
    insereix_nova_carpeta(&mi_org, c2);
    insereix_nova_carpeta(&mi_org, c3);

    /* Llegim 2 dates i les inserim a una de les carpetes (la c1) */
    printf("\nIntrodueix 2 dates per afegir a la carpeta '%s':\n", c1.titol);
    printf("Data 1:\n");
    t_data d1 = llegeix_nova_data();
    printf("Data 2:\n");
    t_data d2 = llegeix_nova_data();

    /* Busquem la carpeta c1 dins l'organitzador i hi afegim les dates */
    t_carpeta *p_car = cerca_carpeta(&mi_org, c1.titol);
    insereix_nova_data(p_car, d1);
    insereix_nova_data(p_car, d2);

    /* Eliminem una de les carpetes buides (c2, que no te dates) */
    printf("\nEliminant la carpeta buida: %s\n", c2.titol);
    elimina_carpeta(&mi_org, c2.titol);

    /* Mostrem les carpetes restants (ja no hi ha d'apareixer c2) */
    printf("\nCarpetes despres d'eliminar '%s':\n", c2.titol);
    mostra_carpetes(&mi_org);

    /* Netegem les dates buides de totes les carpetes de l'organitzador.
       Les 2 dates de c1 son buides, aixi que s'han d'eliminar totes dues. */
    printf("\nNetejant les dates buides de totes les carpetes:\n");
    neteja_dates_buides_carpetes(&mi_org);

    printf("\n--- FI TEST ORGANITZADOR 2 ---\n");
}
