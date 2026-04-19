#include <stdio.h>
#include "carpeta.h"
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
  
  








