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

//Inserta la tascas en la posicio 0 del array, si s'ha pogut retorna 0 si no -1
int insereix_comentari(t_tasca *tas, t_comentari com){
    
    //Definim variables
    int i;

//Comprova que hi hagi suficient espai per al nou comentari
    if(tas->ncomentaris < MAX_COM){

        //Fem un espai per a introduir el nou comentari
        for(i=tas->ncomentaris;i>0;i--){
            tas->comentaris[i] = tas->comentaris[i-1];
        }

        //Introduim el nou comentai e incrementem el contador
        tas->comentaris[0] = com;
        tas->ncomentaris++;

        return 0;

  }else{
    //En cas de no tenir suficient espai per a incerir el comentari retonem -1
    return -1;
  }
  
}

int elimina_comentari(t_tasca *tas, int num){

    //Definim variables
    int i;

    //Comprovem que el numero del usuari existeix en el array de comentaris
    if(num > 0 && num <= tas->ncomentaris){

        //Amb un bucle reposicionem els comentaris fins "aixafar el que volem eliminar"
        for(i=num-1;i<tas->ncomentaris-1;i++){
            tas->comentaris[i] = tas->comentaris[i+1];
        }

        //Reduim el numero de comentaris
        tas->ncomentaris--;

        return 0;

    }else{
        //En cas de un nombre invalid retornem un -1
        return -1;
    }
}
