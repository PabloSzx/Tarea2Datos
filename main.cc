#include <iostream>
#include <iomanip>
#include <math.h>
#include "arreglo.h"
#include "avl.h"
#include "lista.h"
#include "hash.h"

int dim=1000000;
int seed;

int getRandomNumber() {
  return rand()%dim;
}
int* generarArreglo(int n) {
  int *arreglo = arreglo_crear(n);
  for(int i = 0; i < n;i++){
    arreglo_insert(arreglo, i, getRandomNumber());
  }

  return arreglo;
}

lista* generarLista(int n) {
  lista *list = lista_crear();
  for(int i = 0; i < n;i++){
    lista_insertar(&list, getRandomNumber());
  }


  return list;
}

avlNode* generarBst(int n) {
  avlNode *bst = NULL;

  for(int i = 0; i < n;i++){
    bst = avlInsert(bst, getRandomNumber());
  }

  return bst;
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

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  int n = atoi(argv[1]);
  seed = time(NULL);
  srand(seed);

  arreglo_print(generarArreglo(n), n);

  cout << endl << endl;
  postOrder(generarBst(n));
  cout << endl << endl;
  lista_imprimir(generarLista(n));
  cout << endl << endl;
  int m = sqrt(n);
  hash_print(generarHash(n, m), m);

  return 0;
}
