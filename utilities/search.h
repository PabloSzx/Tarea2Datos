#ifndef DELETE_H
#define DELETE_H

int nrand;

int* search_arreglo(int* arreglo, int n) {
  int* arregloAux = (int*)malloc(sizeof(int)*n);

  // file_write("-- search arreglo");

  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    nrand = generar_numero();
    arregloAux[i] = arreglo_search(nrand);
  }
  chrono_get_time(tiempo);

  return arregloAux;
}

void search_lista(lista** list, int n) {
  // file_write("--search lista");

  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    nrand = generar_numero();
    nodoLista* nada = lista_search(nrand);
  }
  chrono_get_time(tiempo);
}

void search_hash(hashNode** ht, int n) {
  // file_write("--search hash");

  auto tiempo = chrono_now();
  for (size_t i = 0; i < n; i++) {
    nrand = generar_numero();
    hashNode* nada = hash_search(ht, nrand);
  }
  chrono_get_time(tiempo);
}

void search_bst(avlNode **bst, int n) {
  // file_write("--search hash");

  auto tiempo = chrono_now();
  for (size_t i = 0; i < n; i++) {
    nrand = generar_numero();
    avlNode* nada = bst_search(bst, nrand);
  }
  chrono_get_time(tiempo);
}


#endif
