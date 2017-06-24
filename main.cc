#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <ctime>
#include <stddef.h>
#include "arreglo.h"
#include "avl.h"
#include "lista.h"
#include "hash.h"

int dim=1000000;
int seed;

void start_time_count(clock_t* start) {
  (*start) = clock();
}

void calculate_duration(clock_t* start, clock_t* end, int tipo) {
  // cout << CLOCKS_PER_SEC << endl;
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

  int n = atoi(argv[1]);

  seed = time(NULL);
  srand(seed);

  // start_time_count(&start);
  // int *arreglo = generarArreglo(n);
  // calculate_duration(&start, &end, 0);
  // arreglo_print(arreglo, n);
  //
  // cout << endl << endl;
  // start_time_count(&start);
  // bst_print(generarBst(n));
  // calculate_duration(&start, &end, 2);
  //
  // cout << endl << endl;
  //
  // start_time_count(&start);
  // lista_imprimir(generarLista(n));
  // calculate_duration(&start, &end, 1);
  //
  // cout << endl << endl;
  //
  // int m = sqrt(n);
  // start_time_count(&start);
  // hash_print(generarHash(n, m), m);
  // calculate_duration(&start, &end, 3);


  // int m = 10;
  // hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  // for(int i=0; i < m; i++){
  //   ht[i] = NULL;
  // }
  // gen_hashfunc(m);
  //
  // hash_insert(ht, 10)

  avlNode *tree = NULL;

  tree = bst_insert(tree, 1);
  tree = bst_insert(tree, 3);
  tree = bst_insert(tree, 2);
  tree = bst_insert(tree, 5);
  tree = bst_insert(tree, 8);
  tree = bst_insert(tree, 4);
  tree = bst_insert(tree, 10);
  tree = bst_insert(tree, 12);
  tree = bst_insert(tree, 14);
  tree = bst_insert(tree, 16);
  tree = bst_insert(tree, 20);
  bst_print(tree);

  cout << "eliminar valor 5" << endl;
  tree = bst_delete(tree, 5);
  // tree = bst_eliminar(bst_buscar(&tree, 20));
  // cout << bst_buscar(&tree, 10)->key;

  bst_print(tree);

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
    bst = bst_insert(bst, getRandomNumber());
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
