#include <stdio.h>
#include <string.h>
#include "tasca.h"

t_comentari llegeix_nou_comentari() {
    t_comentari nou_com;
    printf("Text del nou comentari: ");
    fgets(nou_com.text, MAX_C, stdin);
    
    if (strlen(nou_com.text) > 0 && nou_com.text[strlen(nou_com.text)-1] == '\n') {
        nou_com.text[strlen(nou_com.text)-1] = '\0';
    }
    return nou_com;
}

void mostra_comentari(t_comentari com){
    printf("%s\n", com.text);
}

t_tasca llegeix_nova_tasca(){
    t_tasca nova_tasca; 
    printf("Titol de la nova tasca: ");
    fgets(nova_tasca.titol, MAX_C, stdin);
    
    if (strlen(nova_tasca.titol) > 0 && nova_tasca.titol[strlen(nova_tasca.titol)-1] == '\n') {
        nova_tasca.titol[strlen(nova_tasca.titol)-1] = '\0';
    }
    
    do {
        printf("Prioritat de la nova tasca (entre [%d,%d]): ", MIN_PRI, MAX_PRI);
        scanf("%d", &nova_tasca.prioritat);
        if (nova_tasca.prioritat < MIN_PRI || nova_tasca.prioritat > MAX_PRI){
            printf("Valor erroni, torna-hi.\n");
        }
    } while (nova_tasca.prioritat < MIN_PRI || nova_tasca.prioritat > MAX_PRI);
    
    while(getchar() != '\n'); 
  
    nova_tasca.ncomentaris = 0;
    
    return nova_tasca;
}

void mostra_tasca(t_tasca tas){
    printf("Titol de la tasca: %s\n", tas.titol);
    printf("Prioritat de la tasca: %d\n", tas.prioritat);
    
    if (tas.ncomentaris > 0){
        printf("Comentaris:\n");
        for(int i = 0; i < tas.ncomentaris; i++){
            printf("%d. %s\n", i + 1, tas.comentaris[i].text);
        }
    } 
}
