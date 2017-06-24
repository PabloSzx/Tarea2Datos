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
  // postOrder(generarBst(n));
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

  tree = avlInsert(tree, 1);
  tree = avlInsert(tree, 3);
  tree = avlInsert(tree, 2);
  tree = avlInsert(tree, 5);
  tree = avlInsert(tree, 8);
  tree = avlInsert(tree, 4);
  tree = avlInsert(tree, 10);
  tree = avlInsert(tree, 12);
  tree = avlInsert(tree, 14);
  tree = avlInsert(tree, 16);
  tree = avlInsert(tree, 20);
  postOrder(tree);

  cout << "eliminar valor 5" << endl;
  tree = bst_eliminar(bst_buscar(tree, 10));
  // cout << bst_buscar(&tree, 10)->key;

  postOrder(tree);

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
