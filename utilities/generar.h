#ifndef GENERAR_H
#define GENERAR_H

int generar_numero();
hashNode** generar_hash(int n, int m);
avlNode* generar_bst(int n);
lista* generar_lista(int n);
int* generar_arreglo(int n);

int dim=1000000;
int number;

hashNode** generar_hash(int n, int m) {

  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i=0; i < m; i++){
    ht[i] = NULL;
  }
  hash_gen_function(m);

  file_write("--hash--");

  for(int i = 0; i < n; i++){
    number = generar_numero();
    clock_start();
    hash_insert(ht, number);
    clock_end();
  }

  return ht;
}

avlNode* generar_bst(int n) {
  avlNode *bst = NULL;

  file_write("--bst--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    clock_start();
    bst = bst_insert(bst, number);
    clock_end();
  }

  return bst;
}

lista* generar_lista(int n) {
  lista *list = lista_create();

  file_write("--lista--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    clock_start();
    lista_insert(&list, number);
    clock_end();
  }

  return list;
}

int* generar_arreglo(int n) {
  int *arreglo = arreglo_create(n);

  file_write("--arreglo--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    clock_start();
    arreglo_insert(arreglo, i, number);
    clock_end();
  }

  return arreglo;
}

int generar_numero() {
  return rand()%dim;
}

#endif
