#include <stdio.h>
#include <string.h>
#include "carpeta.h"
#include "tasca.h"

t_data llegeix_nova_data(){
  int num,dia,mes,any;
  printf("Nova data (dd/mm/aaaa):)"
  scanf("%d/%d/%d",&dia,&mes,&any);
  num=(any*10000)+(mes*100)+dia;
  while(getchar() != '\n');
  t_data data;
  data.ntasques=0;
  return data;
  
  
}
void mostra_data(t_data data){
  int any,mes,dia,i;
  any=data.data/10000;
  dia=data.data%100;
  mes=(data.data/100)%100;
  printf("Data:%02d/%02d/%04d",dia,mes,any);
  for (i=0;i<data.ntasques;i++){
    mostra_tasca(data.pendents[i]);
    printf("\n");
    
  }
  
}
t_carpeta llegeix_nova_carpeta(){
  t_carpeta nova_carpeta;
  print("Titol de la nova carpeta: ");
  fgets(nova_carpeta.titol,MAX_C,stdin);
  if (strlen(nova_carpeta.titol) > 0 && nova_carpeta.titol[strlen(nova_carpeta.titol)-1] == '\n') {
        nova_carpeta.titol[strlen(nova_carpeta.titol)-1] = '\0';
  }
  nova_carpeta.ndates = 0; 
  return nova_carpeta;
}
void mostra_carpeta(t_carpeta car){
  int i;
  printf("%s\n",car.titol);
  if (car.ndates > 0) {
        printf("Dates:\n");
      for (i = 0; i < car.ndates; i++){
            mostra_data(car.dates[i]);
      }
  }
}

t_data * cerca_data(t_carpeta *car, t_data data){
  int i;
  for (i=0;i<car->ndates;i++){
    if(car->dates[i].data==data){
      return &car->dates[i];
    }
  }
  return NULL;
    
}

t_tasca * cerca_tasca(t_data *data, char titol[MAX_C]){
  int i;
  for (i=0;i<data->ntasques;i++){
    if(strcmp(data->pendents[i].titol,titol)==0){
      return &data->pendents[i];
    }
  }
  return NULL;
    
}

//El codi insertará una nova data en ordre cronologic (les antigues primer), retornant 0 si s'ha pogut o -1 si no hi ha hagut espai sufucient
int insereix_nova_data(t_carpeta *car, t_data data){

    //Definim les variables locals
    int i,j;

    //En cas de que la carpeta estigui completament plena de dates retornem un -1
    if(car->ndates >= MAX_DAT){
        return -1;
    }

    //Si arribem en aquesta part del codi ja sabem que hi ha suficient espai per a inserir una nova data
    //Amb un bucle anirem recorrent les posicions de l'array per a trobar la posició exacta on inserir la nova
    for(i=0;i < car->ndates;i++){

        //recorrem l'array buscant una data mes antiga per a colocar-la just abans
        if(car->dates[i].data >= data.data){

            //fem espai per a la nova data
            for(j=car->ndates;j>i;j--){
                car->dates[j] = car->dates[j-1];
            }

            //inserim la nova data
            car->dates[i] = data;

            //incrementem el camp ndates
            car->ndates++;
        
            //retornem el 0 de exit absolut
            return 0;
        }
    }
    
    //en cas de que no hi hagi cap data mes antiga, la colocarem en la ultima posició de la llista
    car->dates[car->ndates] = data;

    //incrementem el camp ndates
    car->ndates++;
        
    //retornem el 0 de exit absolut
    return 0;

}

//El codi inserta una nova tasca en la data apuntada per el punter del enunciat, retornant un 0 en cas de exit i en cas negatiu un -1 
int insereix_nova_tasca(t_data *data, t_tasca tas){

    //Definim les variables locals
    int i,j;

    //En cas de que la data estigui completament plena de tasques retornem un -1
    if(data->ntasques >= MAX_TAS){
        return -1;
    }

    //Si arribem en aquesta part del codi ja sabem que hi ha suficient espai per a inserir una nova tasca
    //Amb un bucle anirem recorrent les posicions de l'array per a trobar la posició exacta on inserir la nova
    for(i=0;i < data->ntasques;i++){

        //recorrem l'array buscant una prioritat mes baixa per a inserir la tasca en la posició anterior
        if(data->pendents[i].prioritat <= tas.prioritat){

            //fem espai per a la nova tasca
            for(j=data->ntasques;j>i;j--){
                data->pendents[j] = data->pendents[j-1];
            }

            //inserim la nova tasca
            data->pendents[i] = tas;

            //incrementem el camp ntasques
            data->ntasques++;
        
            //retornem el 0 de exit absolut
            return 0;
        }
    }
    
    //en cas de que no hi hagi cap tasca amb prioritat mes baixa, la colocarem en la ultima posició de la llista
    data->pendents[data->ntasques] = tas;

    //incrementem el camp ntasques
    data->ntasques++;
        
    //retornem el 0 de exit absolut
    return 0;

}

//La funció elimina, de la data apuntada pel paràmetre data, la tasca amb títol igual al paràmetre titol 
int elimina_tasca(t_data *data, char titol[MAX_C]){
    
    //Definim les variables locals
    int i,j;

    //Amb un bucle anirem recorrent les posicions de l'array
    for(i=0;i < data->ntasques;i++){

        //recorrem l'array buscant la tasca amb el mateix nom
        if(strcmp(data->pendents[i].titol,titol) == 0){

            //eliminem la nova tasca desplaçant una posició a l'esquerra
            for(j=i;j<data->ntasques-1;j++){
                data->pendents[j] = data->pendents[j+1];
            }

            //decrementem el camp ntasques
            data->ntasques--;
        
            //retornem el 0 de exit absolut
            return 0;
        }
    }
    
    //en cas de que no hi hagi cap tasca amb el nom que busquem retornem un -1
    return -1;
    
}

//ha de netejar les dates buides de totes les carpetes guardades per l’organizador apuntat pel paràmetre org
//De cada carpeta, cal que la funció en mostri el seu títol i el nombre de carpetes buides eliminades.
int neteja_dates_buides(t_carpeta *car){

    //Definim variables locals
    int i,j,dates_eliminades = 0;

    //Bucle que recorre l'array de datesd de una carpeta
    for(i=0;i<car->ndates;i++){

        //comprovem si la carpeta te alguna tasca tasques.
        if(car->dates[i].ntasques == 0){

            //En cas de no tindre tasques eliminem la data movent la resta una posició cap a la esquerra
            for(j=i;j<car->ndates-1;j++){

                car->dates[j] = car->dates[j+1];

            }

            //aumentem el contador de dates eliminades
            dates_eliminades++;

            //disminuim el nombre de tasques de la carpeta
            car->ndates--;

            //disminuim un el index i per a tornar a comprovar la mateixa posició que acaben d'actualitzar
            i--;

        }

    } 

    //Finalment retornem el nombre de dates eliminades
    return dates_eliminades;

}
