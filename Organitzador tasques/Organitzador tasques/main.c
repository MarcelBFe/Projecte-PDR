/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "tests.h" 

int main(int argc, char** argv) {
    t_organitzador mi_org;
    mi_org.ncarpetes = 0; // Inicializar siempre
    
    char opcio;
    
    printf("***********************************************\n");
    printf("*      ORGANITZADOR DE TASQUES PENDENTS       *\n");
    printf("*   Programacio i Estructures de Dades (PRD)  *\n");
    printf("*       ETSETB-GREELEC: Curs 2025/2026        *\n");
    printf("***********************************************\n\n");
    
    mostrar_ajuda();

    do {
        printf("\nIntrodueix una nova opcio: ");
        scanf(" %c", &opcio); 
        while(getchar() != '\n'); 

        switch(opcio) {
            case 'n': case 'N':
                processa_opcio_nova_carpeta(&mi_org);
                break;
            case 'd': case 'D':
                processa_opcio_nova_data(&mi_org);
                break;
            case 't': case 'T':
                processa_opcio_nova_tasca(&mi_org);
                break;
            case 'i': case 'I':
                processa_opcio_insereix_comentari(&mi_org);
                break;
            case 's': case 'S':
                processa_opcio_mostra_carpetes(&mi_org);
                break;
            case 'm': case 'M':
                processa_opcio_mostra_carpeta(&mi_org);
                break;
            case 'e': case 'E':
                processa_opcio_elimina_tasca(&mi_org);
                break;
            case 'b': case 'B':
                processa_opcio_neteja_dates_buides(&mi_org);
                break;
            case 'c': case 'C':
                processa_opcio_elimina_carpeta(&mi_org);
                break;
            case 'a': case 'A':
                mostrar_ajuda();
                break;
            case 'f': case 'F':
                break;
            default:
                printf("Opcio incorrecta. Torna a intentar-ho.\n");
                break;
        }
    } while (opcio != 'f' && opcio != 'F');

    printf("Finalitzant l'aplicacio... Adeu!\n");
    return (EXIT_SUCCESS);
}
void mostrar_ajuda()
{
    printf("Opcions disponibles:\n");
    printf("\t[N]ova carpeta\n");
    printf("\tNova [D]ata\n");
    printf("\tNova [T]asca\n");
    printf("\t[I]nsereix comentari\n");
    printf("\tMostra carpete[S]\n");
    printf("\t[M]ostra carpeta\n");
    printf("\t[E]limina tasca\n");
    printf("\tNeteja dates [B]uides\n");
    printf("\tElimina [C]arpeta\n");
    printf("\t[A]juda\n");
    printf("\t[F]inalitza\n");
}

void processa_opcio_nova_carpeta(t_organitzador *org) {
    char titol_llegit[MAX_C];
    
    printf("Titol de la nova carpeta: ");
    llegeix_text(titol_llegit);
    
    t_carpeta *trobada = cerca_carpeta(org, titol_llegit);
    
    if (trobada != NULL) {
        printf("Ja existeix la carpeta amb aquest titol.\n");
    } 
    else {
        t_carpeta nova_car;
        
        strcpy(nova_car.titol, titol_llegit);
        
        nova_car.ndates = 0; 
        
        int resultat = insereix_nova_carpeta(org, nova_car);
        
        if (resultat == 0) {
            printf("Carpeta inserida correctament.\n");
        } else {
            printf("Error: L'organitzador de carpetes esta ple.\n");
        }
    }
}

void processa_opcio_mostra_carpetes(t_organitzador *org) {
    mostra_carpetes(org);
}

void processa_opcio_mostra_carpeta(t_organitzador *org) {
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol); 
    
    mostra_contingut_carpeta(org, titol);
}


void llegeix_text(char text[MAX_C])
{
    fgets(text, MAX_C, stdin);
    if (strlen(text) > 0)
        text[strlen(text)-1] = '\0';
}

//Processa l'opcio 'D': afegeix una nova data a una carpeta ja existent.
//Cal comprovar que la carpeta existeix i que la data no estigui repetida.
void processa_opcio_nova_data(t_organitzador *org) {
    char titol_carpeta[MAX_C];

    //Demanem el titol de la carpeta i la busquem a l'organitzador
    printf("Titol de la carpeta: ");
    llegeix_text(titol_carpeta);

    t_carpeta *p_car = cerca_carpeta(org, titol_carpeta);

    //Si la carpeta no existeix, avisem i sortim
    if (p_car == NULL) {
        printf("Carpeta no trobada.\n");
        return;
    }

    //La carpeta existeix: llegim la nova data
    t_data nova_data = llegeix_nova_data();

    //Comprovem que la data no existeixi ja a la carpeta
    if (cerca_data(p_car, nova_data) != NULL) {
        printf("Ja existeix la data a la carpeta.\n");
        return;
    }

    //Inserim la data i comprovem el resultat
    int resultat = insereix_nova_data(p_car, nova_data);

    if (resultat == 0) {
        printf("Data inserida correctament.\n");
    } else {
        printf("Error: la carpeta ja te el maxim de dates.\n");
    }
}


//Processa l'opcio 'T': afegeix una nova tasca a una data d'una carpeta.
//Cal comprovar que tant la carpeta com la data existeixen.
void processa_opcio_nova_tasca(t_organitzador *org) {
    char titol_carpeta[MAX_C];

    //Busquem la carpeta
    printf("Titol de la carpeta: ");
    llegeix_text(titol_carpeta);

    t_carpeta *p_car = cerca_carpeta(org, titol_carpeta);

    if (p_car == NULL) {
        printf("Carpeta no trobada.\n");
        return;
    }

    //Llegim la data i la busquem dins la carpeta
    t_data data_llegida = llegeix_nova_data();
    t_data *p_data = cerca_data(p_car, data_llegida);

    if (p_data == NULL) {
        printf("Data no trobada.\n");
        return;
    }

    //Llegim la nova tasca i la inserim a la data
    t_tasca nova_tas = llegeix_nova_tasca();
    int resultat = insereix_nova_tasca(p_data, nova_tas);

    if (resultat == 0) {
        printf("Tasca inserida correctament.\n");
    } else {
        printf("Error: la data ja te el maxim de tasques.\n");
    }
}


//Processa l'opcio 'I': afegeix un comentari a una tasca existent.
//Cal que existeixin la carpeta, la data i la tasca.
void processa_opcio_insereix_comentari(t_organitzador *org) {
    char titol_carpeta[MAX_C];
    char titol_tasca[MAX_C];

    //Busquem la carpeta
    printf("Titol de la carpeta: ");
    llegeix_text(titol_carpeta);

    t_carpeta *p_car = cerca_carpeta(org, titol_carpeta);

    if (p_car == NULL) {
        printf("Carpeta no trobada.\n");
        return;
    }

    //Busquem la data dins la carpeta
    t_data data_llegida = llegeix_nova_data();
    t_data *p_data = cerca_data(p_car, data_llegida);

    if (p_data == NULL) {
        printf("Data no trobada.\n");
        return;
    }

    //Busquem la tasca dins la data
    printf("Titol de la tasca: ");
    llegeix_text(titol_tasca);

    t_tasca *p_tas = cerca_tasca(p_data, titol_tasca);

    if (p_tas == NULL) {
        printf("Tasca no trobada.\n");
        return;
    }

    //Llegim el comentari i l'inserim a la tasca
    t_comentari nou_com = llegeix_nou_comentari();
    int resultat = insereix_comentari(p_tas, nou_com);

    if (resultat == 0) {
        printf("Comentari inserit correctament.\n");
    } else {
        printf("Error: la tasca ja te el maxim de comentaris.\n");
    }
}


//Processa l'opcio 'E': elimina una tasca d'una data d'una carpeta.
//Cal que existeixin la carpeta, la data i la tasca.
void processa_opcio_elimina_tasca(t_organitzador *org) {
    char titol_carpeta[MAX_C];
    char titol_tasca[MAX_C];

    //Busquem la carpeta
    printf("Titol de la carpeta: ");
    llegeix_text(titol_carpeta);

    t_carpeta *p_car = cerca_carpeta(org, titol_carpeta);

    if (p_car == NULL) {
        printf("Carpeta no trobada.\n");
        return;
    }

    //Busquem la data dins la carpeta
    t_data data_llegida = llegeix_nova_data();
    t_data *p_data = cerca_data(p_car, data_llegida);

    if (p_data == NULL) {
        printf("Data no trobada.\n");
        return;
    }

    //Demanem el titol de la tasca i l'eliminem
    printf("Titol de la tasca: ");
    llegeix_text(titol_tasca);

    int resultat = elimina_tasca(p_data, titol_tasca);

    if (resultat == 0) {
        printf("Tasca eliminada correctament.\n");
    } else {
        printf("Tasca no trobada.\n");
    }
}


//Processa l'opcio 'B': neteja les dates buides de totes les carpetes.
//La funcio neteja_dates_buides_carpetes ja mostra el titol i el nombre
//de dates eliminades de cada carpeta, per tant aqui nomes cal cridar-la.
void processa_opcio_neteja_dates_buides(t_organitzador *org) {
    neteja_dates_buides_carpetes(org);
}


//Processa l'opcio 'C': elimina una carpeta sencera de l'organitzador.
void processa_opcio_elimina_carpeta(t_organitzador *org) {
    char titol_carpeta[MAX_C];

    //Demanem el titol de la carpeta i l'eliminem
    printf("Titol de la carpeta: ");
    llegeix_text(titol_carpeta);

    int resultat = elimina_carpeta(org, titol_carpeta);

    if (resultat == 0) {
        printf("Carpeta eliminada correctament.\n");
    } else {
        printf("Carpeta no trobada.\n");
    }
}
