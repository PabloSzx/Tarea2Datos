#ifndef DELETE_H
#define DELETE_H

void delete_arreglo(int* arreglo, int n) {
  file_write("-- delete arreglo");

  for (int i = 0; i < n; i++) {
    file_close();
    file_open("busqueda");
    int nrand = generar_numero(n);

    auto tiempo = chrono_now();

    int pos = arreglo_search(arreglo[nrand]);

    chrono_get_time(tiempo);

    file_close();
    file_open("eliminacion");

    tiempo = chrono_now();
    arreglo_delete(arreglo, pos);
    chrono_get_time(tiempo);

    // arreglo_delete(pos);

  }
}


#endif
