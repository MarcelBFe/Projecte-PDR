
#include <stdio.h>
#include <string.h>
#include "tasca.h"

// Contingut heather.h
//#define MAX_C   100     /* Nombre màxim de caràcters  */
//#define MIN_PRI 1       /* Valor mínim de prioritat   */
//#define MAX_PRI 3       /* Valor màxim de prioritat   */
//#define MAX_COM 5       /* Nombre màxim de comentaris */

//typedef struct
//{
//    char text[MAX_C];       /* Text del comentari */
//}t_comentari;

//typedef struct
//{
//    char titol[MAX_C];                  /* Títol de la tasca             */
//    int prioritat;                      /* Prioritat de la tasca         */
//    int ncomentaris;                    /* Nombre de comentaris afegits  */
//    t_comentari comentaris[MAX_COM];    /* Comentaris afegits a la tasca */
//}t_tasca;

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
