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
                printf("Finalitzant l'aplicacio... Adeu!\n");
                break;
            default:
                printf("Opcio incorrecta. Torna a intentar-ho.\n");
                break;
        }
    } while (opcio != 'f' && opcio != 'F');

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
