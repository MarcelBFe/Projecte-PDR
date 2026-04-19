#include <stdio.h>
#include "tests.h"
#include "tasca.h"


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
    
}

#include <stdio.h>
#include "tests.h"
#include "carpeta.h"

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
