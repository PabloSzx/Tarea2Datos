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
    start_time();
    hash_insert(ht, number);
    end_time();
  }

  return ht;
}

avlNode* generar_bst(int n) {
  avlNode *bst = NULL;

  file_write("--bst--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    start_time();
    bst = bst_insert(bst, number);
    end_time();
  }

  return bst;
}

lista* generar_lista(int n) {
  lista *list = lista_crear();

  file_write("--lista--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    start_time();
    lista_insertar(&list, number);
    end_time();
  }

  return list;
}

int* generar_arreglo(int n) {
  int *arreglo = arreglo_crear(n);

  file_write("--arreglo--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    start_time();
    arreglo_insert(arreglo, i, number);
    end_time();
  }

  return arreglo;
}

int generar_numero() {
  srand(time(NULL));
  return rand()%dim;
}

#endif
