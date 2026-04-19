t_carpeta * cerca_carpeta(t_organitzador *org, char titol[MAX_C]){
  int i;
  for (i=0;i<org->ncarpetes;i++){
    if(strcmp(org->carpetes[i].titol,titol)==0){
      return &org->carpetes[i];
      
    }
  }
  return NULL;
}
void mostra_carpetes(t_organitzador *org){
  int i;
  for (i=0;i<org->ncarpetes;i++){
    printf("%s\n",org->carpetes[i].titol); 
  }
   
}
void mostra_contingut_carpeta(t_organitzador *org, char titol[MAX_C]) {
    t_carpeta * p_car = cerca_carpeta(org, titol);

    if (p_car == NULL) {
        printf("Carpeta no trobada.\n");
    } 
    else {
        mostra_carpeta(*p_car);
    }
}
