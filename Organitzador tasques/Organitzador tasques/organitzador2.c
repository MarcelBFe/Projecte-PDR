#include <stdio.h>
#include <string.h>
#include "organitzador.h"
#include "carpeta.h"
#include "tasca.h"


// ha d’inserir la carpeta rebuda com a paràmetre a l’organitzador apuntat pel paràmetre org
//La inserció ha de realitzar-se en aquella posició que mantingui les carpetes ordenades de forma creixent,
// en funció dels seus títols (ordre alfabètic creixent)
int insereix_nova_carpeta(t_organitzador *org, t_carpeta car){

    //En cas de que el organitzador estigui ple, retornem -1
    if(org->ncarpetes == MAX_CAR){
        return -1;
    }

    //definim variables locals de la funcio
    int i,j;

    //Mitjançant un bucle recorrem la llista de carpetes
    for(i=0;i<org->ncarpetes;i++){

        //anem comparant tamanys de titol fins a trobar un que sigui major al nostre:
        if(strcmp(org->carpetes[i].titol,car.titol)>0){

            //Fem espai per a introduir la nova carpeta
            for(j=org->ncarpetes;j>i;j--){
                org->carpetes[j] = org->carpetes[j-1];
            }

            //Insertem la nova carpeta
            org->carpetes[i] = car;

            //Actualitzem el index de numero de carpetes
            org->ncarpetes++;

            //Retornem un 0 de exit absolut
            return 0;
        }

    }

    //Si arribem aqui es que no hi ha cap carpeta que tingui un nom mes gran que la que volem inserir, aixi que la inserim al final
    org->carpetes[org->ncarpetes] = car;

    //Actualitzem el index de numero de carpetes
    org->ncarpetes++;

    //Retornem un 0 de exit absolut
    return 0;

}

//Ha de netejar les dates buides de totes les carpetes guardades per l’organizador apuntat pel paràmetre org.
//De cada carpeta, cal que la funció en mostri el seu títol i el nombre de carpetes buides eliminades
void neteja_dates_buides_carpetes(t_organitzador *org){

    //Definim variables locals de la funció
    int i,n_carpetes_eliminades;

    //Amb un bucle recorrem totes les carpetes d'un organitzador
    for(i=0;i<org->ncarpetes;i++){

        //Li passem una a una les carpetes del organitzador a la funcio que elimina les dates buides
        n_carpetes_eliminades = neteja_dates_buides(&org->carpetes[i]);

        //Mostrem el resultat
        printf("Carpeta: %s\n", org->carpetes[i].titol);
        printf("%d dates eliminades.\n", n_carpetes_eliminades);

    }

}

//ha d’eliminar la carpeta amb títol igual al paràmetre titol de l’organitzador apuntat pel paràmetre org
int elimina_carpeta(t_organitzador *org, char titol[MAX_C]){

    //Definim les variables locals
    int i,j;

    //Amb un bucle anirem recorrent les posicions de l'array
    for(i=0;i < org->ncarpetes;i++){

        //recorrem l'array buscant la carpeta amb el mateix nom
        if(strcmp(org->carpetes[i].titol,titol) == 0){

            //eliminem la carpeta desplaçant una posició a l'esquerra
            for(j=i;j<org->ncarpetes-1;j++){
                org->carpetes[j] = org->carpetes[j+1];
            }

            //decrementem el camp ncarpetes
            org->ncarpetes--;
        
            //retornem el 0 de exit absolut
            return 0;
        }
    }
    
    //en cas de que no hi hagi cap carpeta amb el nom que busquem retornem un -1
    return -1;

}
