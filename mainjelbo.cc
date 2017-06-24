#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <ctime>
#include "arreglo.h"
#include "avl.h"
#include "lista.h"
#include "hash.h"
#include <stdlib.h>

int dim=1000000;
int seed;

void start_time(clock_t* start) { //Inicia el contador de tiempo
  (*start) = clock();
}

void end_time(clock_t* start, clock_t* end, int tipo) { //Finaliza el contador de tiempo
  (*end) = clock();
  double duration = ((*end) - (*start)) / (double) CLOCKS_PER_SEC;
  switch (tipo) {
    case 0:
    {
      cout << "Generar el arreglo";
      break;
    }
    case 1:
    {
      cout << "Generar la lista";
      break;
    }
    case 2:
    {
      cout << "Generar el bst";
      break;
    }
    case 3:
    {
      cout << "Generar el hash";
      break;
    }
  }
  cout << " se demoró: " << duration << endl;
}

hashNode** generarHash(int n, int m);
avlNode* generarBst(int n);
lista* generarLista(int n);
int* generarArreglo(int n);
int getRandomNumber();

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  clock_t start;
  clock_t end;

  //Tiempo para generar la lista
  // start_time_count(&start);
  //
  // end_time_count(&end);
  //
  // calculate_duration(&start, &end, 1);

  int n = atoi(argv[1]);

  seed = time(NULL);
  srand(seed);

  //-------------------------------------------------------------------------------
  //IMPLEMENTACION DEL ARREGLO
  start_time(&start);
  int *arreglo = generarArreglo(n);
  end_time(&start, &end, 0);
  arreglo_print(arreglo, n);

  int buscar = 321269;//busco un elemento en el arreglo y trato de eliminarlo
  int numero_arreglo = arreglo_buscar(arreglo, buscar,n);
  arreglo_delete(arreglo,numero_arreglo);
  arreglo_print(arreglo, n);

  //-------------------------------------------------------------------------------
  //IMPLEMENTACION DEL LA LISTA ENLAZADA
  start_time(&start);

  end_time(&start, &end, 0);



  //-------------------------------------------------------------------------------
  //IMPLEMENTACION DEL AVL



  //-------------------------------------------------------------------------------
  //IMPLEMENTACION DEL HASH MAP




  // cout << endl << endl;
  // postOrder(generarBst(n));
  // cout << endl << endl;
  // lista_imprimir(generarLista(n);
  // cout << endl << endl;
  // int m = sqrt(n);
  //
  // hash_print(generarHash(n, m), m);

  return 0;
}

hashNode** generarHash(int n, int m) {
  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i=0; i < m; i++){
    ht[i] = NULL;
  }
  gen_hashfunc(m);

  for(int i = 0; i < n; i++){
    hash_insert(ht, getRandomNumber());
  }

  return ht;
}

avlNode* generarBst(int n) {
  avlNode *bst = NULL;

  for(int i = 0; i < n;i++){
    bst = avlInsert(bst, getRandomNumber());
  }

  return bst;
}

lista* generarLista(int n) {
  lista *list = lista_crear();
  for(int i = 0; i < n;i++){
    lista_insertar(&list, getRandomNumber());
  }


  return list;
}

int* generarArreglo(int n) {
  int *arreglo = arreglo_crear(n);
  for(int i = 0; i < n;i++){
    arreglo_insert(arreglo, i, getRandomNumber());
  }

  return arreglo;
}

int getRandomNumber() {
  return rand()%dim;
}
