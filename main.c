#include <stdio.h>
#include <stdlib.h>

#define T 2
#define NOT_FOUND -1
#define TRUE 1
#define FALSE 0

#include "arbolb.h"


/////////////////////////////////////////////////

int main () {

   BTree *nuevoNodo = crearArbolB();
   
   
   nuevoNodo = InsertarNodo (nuevoNodo, 2);
   nuevoNodo = InsertarNodo (nuevoNodo, 10);
   nuevoNodo = InsertarNodo (nuevoNodo, 50);
   nuevoNodo = InsertarNodo (nuevoNodo, 35);
   nuevoNodo = InsertarNodo (nuevoNodo, 30);
   nuevoNodo = InsertarNodo (nuevoNodo, 8);
   
 //7  ImprimirArbol(nuevoNodo, 0);
//   escribirNodo(nuevoNodo);
 //  printf("---------------\n");*/
      
   //BTree *unNodo=leeNodo(6);
   nuevoNodo = InsertarNodo (nuevoNodo, 9);
   nuevoNodo = InsertarNodo (nuevoNodo, 80);
   nuevoNodo = InsertarNodo (nuevoNodo, 55);
   nuevoNodo = InsertarNodo (nuevoNodo, 40);
   nuevoNodo = InsertarNodo (nuevoNodo, 1);
   nuevoNodo = InsertarNodo (nuevoNodo, 36);
   nuevoNodo = InsertarNodo (nuevoNodo, 89);
   nuevoNodo = InsertarNodo (nuevoNodo, 100);
   nuevoNodo = InsertarNodo (nuevoNodo, 12);
   ImprimirArbol(nuevoNodo, 0);
  // buscarDato(nuevoNodo,80);
   
  
//   escribirNodo(nuevoNodo);
   
  // buscarDato(nuevoNodo,);

   return 0;
}
