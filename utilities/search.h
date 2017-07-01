#ifndef SEARCH_H
#define SEARCH_H

void search_arreglo(int* arreglo, int n);
void search_lista(lista** list, int n);
void search_hash(hashNode** ht, int n);
void search_bst(avlNode **bst, int n);

void search_arreglo(int* arreglo, int n) {
  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    int nada = arreglo_search(arreglo, generar_numero(), n);
  }
  chrono_get_time(tiempo);
}

void search_lista(lista** list, int n) {

  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    nodoLista* nada = lista_search(list, generar_numero());
  }
  chrono_get_time(tiempo);
}

void search_hash(hashNode** ht, int n) {
  auto tiempo = chrono_now();
  for (size_t i = 0; i < n; i++) {
    hashNode* nada = hash_search(ht, generar_numero());
  }
  chrono_get_time(tiempo);
}

void search_bst(avlNode **bst, int n) {
  auto tiempo = chrono_now();
  for (size_t i = 0; i < n; i++) {
    avlNode* nada = bst_search(bst, generar_numero());
  }
  chrono_get_time(tiempo);
}


#endif
