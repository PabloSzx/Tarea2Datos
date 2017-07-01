#ifndef DELETE_H
#define DELETE_H

void delete_arreglo(int* arreglo, int n, int* largoArreglo) {
  double sumTiempo;

  for (int i = 0; i < n; i++) {
    int pos = arreglo_search(arreglo, generar_numero(), n);
    auto tiempo = chrono_now();
    arreglo_delete(arreglo, pos, largoArreglo);
    sumTiempo = sumTiempo + chrono_get_time_return(tiempo);
  }

  // duration<double> time_span = duration_cast<duration<double>>(sumTiempo);

  // file_write_space(time_span.count());
  file_write_space(sumTiempo);
}

void delete_lista(nodoLista **list, int n) {
  double sumTiempo;

  for (int i = 0; i < n; i++) {
    nodoLista* x = lista_search(list, generar_numero());
    auto tiempo = chrono_now();
    lista_delete(list, x);
    sumTiempo = sumTiempo + chrono_get_time_return(tiempo);
  }

  // duration<double> time_span = duration_cast<duration<double>>(sumTiempo);

  // file_write_breakline(time_span.count());
  file_write_breakline(sumTiempo);

}

void delete_hash(hashNode** ht, int n) {
  double sumTiempo;

  for (int i = 0; i < n; i++) {
    hashNode* x = hash_search(ht, generar_numero());
    auto tiempo = chrono_now();
    hash_delete(x);
    sumTiempo = sumTiempo + chrono_get_time_return(tiempo);
  }

  // duration<double> time_span = duration_cast<duration<double>>(sumTiempo);

  // file_write_space(time_span.count());
  file_write_space(sumTiempo);
}

void delete_bst(avlNode** bst, int n) {
  double sumTiempo;

  for (int i = 0; i < n; i++) {
    int nrand = generar_numero();

    // cout << "nrand resulto ser: " << nrand << endl;

    auto t = chrono_now();
    avlNode* x = bst_search(bst, nrand);
    auto tBusqueda = chrono_get_time_return(t);

    auto tiempo = chrono_now();
    *bst = bst_delete(*bst, nrand);
    auto tDeleteConBusqueda = chrono_get_time_return(tiempo);

    sumTiempo = sumTiempo + (tDeleteConBusqueda - tBusqueda);
  }

  // duration<double> time_span = duration_cast<duration<double>>(sumTiempo);

  // file_write_space(time_span.count());
  file_write_space(sumTiempo);
}


#endif
