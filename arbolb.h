typedef struct _nodo {
	
  int cantidad_actual;
  int hoja;
  int claves[2*T-1];
  int miNombre;
  struct _nodo *hijos[2*T];
  
}BTree;

/////////////////////////////////////////////////

int escribirNodo(BTree*unNodo){
	if(unNodo==NULL)return -1;
	char strNombreNodo[10];
	sprintf(strNombreNodo,"%d",unNodo->miNombre);// tranforma nombre del nodo que es int a string.%d
	FILE*archivoNodo=fopen(strNombreNodo,"wb");
	fwrite(unNodo,sizeof(BTree),1,archivoNodo);
	fclose(archivoNodo);
	return(1);	//return 1;
}

///////////////////////////////////////////////

BTree *leeNodo(int nombreNodo){// recibe nodo 
	char strNombreNodo[10];
//	Nodo*pNodo;
	BTree*nuevoNodo=malloc(sizeof(BTree));
	sprintf(strNombreNodo,"%d",nombreNodo);
	FILE*archivoNodo = fopen(strNombreNodo,"rb");
	if(archivoNodo==NULL)return NULL;
	fread(nuevoNodo,sizeof(BTree),1,archivoNodo);
	fclose(archivoNodo);
	return(nuevoNodo);	
}

/////////////////////////////////////////////////

int buscarDato(BTree *unNodo, int nuevaClave){

	int i=0; 
	BTree *aux;
	
	while(i<=aux->cantidad_actual && nuevaClave>=aux->claves[i]){
		
		i++;
		
	}
		
	if(i<=aux->cantidad_actual && nuevaClave==aux->claves[i]){
		
		
		return (aux->miNombre);
		
	}
	
	if(aux->hoja==TRUE){
		
		free(aux);
		return -1;
		
	}else{
		
		//leeNodo(aux->miNombre);
		
		return buscarDato(aux->hijos[i],nuevaClave);
		
	}

}

//////////////////////////////////////////////////

BTree *crearArbolB () {
	
   BTree *nuevoNodo;
   nuevoNodo = (BTree *)malloc(sizeof(BTree));
   nuevoNodo->cantidad_actual = 0;
   nuevoNodo->hoja= TRUE;
   
   return nuevoNodo;
   
}

/////////////////////////////////////////////////

void ImprimirArbol (BTree *nuevoNodo, int posicion) {
	
   int i;

   for(i=0;i<posicion;i++){ 
   		printf("  "); 
	}
   printf("|");
   
   for(i=0;i<nuevoNodo->cantidad_actual;i++){
      printf("%d|", nuevoNodo->claves[i]);
   }
   printf("\n");

   for(i=0;i<=nuevoNodo->cantidad_actual;i++){
      if(nuevoNodo->hoja==FALSE){
         ImprimirArbol(nuevoNodo->hijos[i],posicion+1);
      }
   }
}
/////////////////////////////////////////////////

BTree *DividirHijo (BTree *nodoX, int i, BTree *nodoY) {
	
    int j;
    BTree *nodoZ = crearArbolB();
    nodoZ->cantidad_actual = T-1;
    nodoY=nodoX->hijos[i];
    nodoZ->hoja=nodoY->hoja;

    for (j = 0; j < T - 1; j++){
        nodoZ->claves[j] = nodoY->claves[j+T];
    }

    if (nodoY->hoja == FALSE)
    {
        for (j = 0; j < T; j++){
            nodoZ->hijos[j] = nodoY->hijos[j+T];
        }
    }

    nodoY->cantidad_actual = T-1;

    for (j = nodoX->cantidad_actual; j >= i+1; j--){
        nodoX->hijos[j+1] = nodoX->hijos[j];
    }

    nodoX->hijos[i+1] = nodoZ;

    for (j = nodoX->cantidad_actual-1; j >= i; j--){
        nodoX->claves[j+1] = nodoX->claves[j];
    }

    nodoX->claves[i] = nodoY->claves[T-1];
    nodoX->cantidad_actual++;
    escribirNodo(nodoY);
    escribirNodo(nodoZ);
    escribirNodo(nodoX);


   return nodoX;
}

/////////////////////////////////////////////////

BTree *InsertarNoLLeno (BTree *nodoX, int nuevaClave) {
	
    int i = nodoX->cantidad_actual-1;

    if (nodoX->hoja == TRUE){

        while (i >= 0 && nodoX->claves[i] > nuevaClave){
            nodoX->claves[i+1] = nodoX->claves[i];
            i--;
        }
        nodoX->claves[i+1] = nuevaClave;
        nodoX->cantidad_actual++;
        
        escribirNodo(nodoX);


    }else{
    	
        	while(i>=0 && nodoX->claves[i] > nuevaClave){
            i--;
        	}

        	i = i + 1;
        
        //	leeNodo(nodoX->miNombre);

        	if (nodoX->hijos[i]->cantidad_actual == 2*T-1){
        		
            	nodoX = DividirHijo(nodoX, i, nodoX->hijos[i]);

            	if (nuevaClave > nodoX->claves[i]){
                	i = i + 1;
            	}
        	}
        nodoX->hijos[i] = InsertarNoLLeno(nodoX->hijos[i], nuevaClave);
    	}

    return nodoX;
}

/////////////////////////////////////////////////

BTree *InsertarNodo (BTree *raiz, int claves) {
	
   BTree *nodoRaiz = raiz;
   if (nodoRaiz->cantidad_actual == (2*T - 1)) {
      BTree *nodoAux = crearArbolB();
      nodoAux->hoja = FALSE;
      nodoAux->hijos[0] = nodoRaiz;
      nodoAux = DividirHijo (nodoAux, 0, nodoRaiz);
      nodoAux = InsertarNoLLeno (nodoAux, claves);
      return nodoAux;
   }
   else {
      return InsertarNoLLeno (nodoRaiz, claves);
   }
}

