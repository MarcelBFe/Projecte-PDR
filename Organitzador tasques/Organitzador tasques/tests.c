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
