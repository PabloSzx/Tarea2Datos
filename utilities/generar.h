#ifndef GENERAR_H
#define GENERAR_H

int* generar_arreglo(int n, int* largoArreglo);
int generar_numero();
int generar_numero(int n);
hashNode** generar_hash_desde_arreglo(int* arreglo, int n, int m);
avlNode* generar_bst_desde_arreglo(int* arreglo, int n);
lista* generar_lista_desde_arreglo(int* arreglo, int n);

int number;
int dim = 1000000;

int* generar_arreglo(int n, int* largoArreglo) {
  int* arreglo = arreglo_create(n);

  auto tiempo = chrono_now();
  for(int i = 0; i < n;i++){
    number = generar_numero();
    arreglo_insert(arreglo, i, number, largoArreglo);
  }
  chrono_get_time(tiempo);
  file_write_space();

  return arreglo;
}

int generar_numero() {
  //Retorna numero entre 0 y 1000000
  return (rand() % (dim + 1));
}

int generar_numero(int n) {
  //Retorna numero entre 0 y (n - 1)
  return (rand() % n);
}

hashNode** generar_hash_desde_arreglo(int* arreglo, int n, int m) {
  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i = 0; i < m; i++){
    ht[i] = NULL;
  }
  hash_gen_function(m);


  auto tiempo = chrono_now();
  for(int i = 0; i < n; i++){
    hash_insert(ht, arreglo[i]);
  }
  chrono_get_time(tiempo);
  file_write_space();

  return ht;
}


avlNode* generar_bst_desde_arreglo(int* arreglo, int n) {
  avlNode *bst = NULL;

  auto tiempo = chrono_now();

  for(int i = 0; i < n;i++){
    bst = bst_insert(bst, arreglo[i]);
  }

  chrono_get_time(tiempo);
  file_write_space();

  return bst;
}


lista* generar_lista_desde_arreglo(int* arreglo, int n) {

  lista *list = lista_create();

  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    lista_insert(&list, arreglo[i]);
  }

  chrono_get_time(tiempo);
  file_write_breakline();

  return list;
}

#endif
