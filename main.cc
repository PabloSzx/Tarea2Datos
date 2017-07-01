#include "dependencies.h"

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  int n = atoi(argv[1]);
  if (n < 50) {
    dim = n;
  }
  // cout << n << endl;
  int m = sqrt(n);
  int largoArreglo = 0;


  // file_clear("insercion");
  // file_clear("eliminacion");



  // auto one = chrono_now();
  //
  // file_open("insercion");
  //
  // hashNode** hash = generar_hash(n, m);
  //
  // avlNode* bst = generar_bst(n);
  //
  // lista* list = generar_lista(n);
  //
  // int* arreglo = generar_arreglo(n, &largoArreglo);
  //
  // chrono_get_time(one, "Generar todas las estructuras");
  //
  // cout << endl;
  //
  // file_write("--end--");
  // file_close();
  //
  // cout << "HASH" << endl;
  // hash_print(hash, m);
  // cout << endl;
  // cout << "BST" << endl;
  // bst_print(bst);
  // cout << endl;
  // cout << "LISTA" << endl;
  // lista_print(list);
  // cout << endl;
  // cout << "ARREGLO" << endl;
  // arreglo_print(arreglo, n);

  cout << "N = " << n << endl << endl;

  file_open("insercion");
  file_write_space(n);
  auto todoInsertar = chrono_now();
  chrono_start();
  int* arreglo = generar_arreglo(n, &largoArreglo);
  chrono_end("Generar el arreglo random");
  chrono_start();
  hashNode** hash = generar_hash_desde_arreglo(arreglo, n, m);
  chrono_end("Generar el hash desde el arreglo previo");
  chrono_start();
  avlNode* bst = generar_bst_desde_arreglo(arreglo, n);
  chrono_end("Generar el bst desde el arreglo previo");
  chrono_start();
  nodoLista* list = generar_lista_desde_arreglo(arreglo, n);
  chrono_end("Generar la lista desde el arreglo previo");

  chrono_get_time(todoInsertar, "Generar todas las estructuras");

  if (n < 50) {
    cout << "HASH" << endl;
    hash_print(hash, m);
    cout << endl;
    cout << "BST" << endl;
    bst_print(bst);
    cout << endl;
    cout << "LISTA" << endl;
    lista_print(list);
    cout << endl;
    cout << "ARREGLO" << endl;
    arreglo_print(arreglo, largoArreglo);
  }

  file_close();

  cout << endl << endl << endl;

  file_open("busqueda");
  file_write_space(n / 100);


  auto todoBuscar = chrono_now();

  chrono_start();
  search_arreglo(arreglo, n/100);
  chrono_end("Busqueda en el arreglo");

  chrono_start();
  search_hash(hash, n/100);
  chrono_end("Busqueda en el hash");

  chrono_start();
  search_bst(&bst, n/100);
  chrono_end("Busqueda en el bst");

  chrono_start();
  search_lista(&list, n/100);
  chrono_end("Busqueda en la lista");

  chrono_get_time(todoBuscar, "Buscar en todas las estructuras");

  file_close();

  cout << endl << endl << endl;

  file_open("eliminacion");
  file_write_space(n / 100);


  auto todoEliminar = chrono_now();

  chrono_start();
  delete_arreglo(arreglo, n/100, &largoArreglo);
  chrono_end("Eliminacion en el arreglo");

  chrono_start();
  delete_hash(hash, n/100);
  chrono_end("Eliminacion en el hash");

  chrono_start();
  delete_bst(&bst, n/100);
  chrono_end("Eliminacion en el bst");

  chrono_start();
  delete_lista(&list, n/100);
  chrono_end("Eliminacion en la lista");

  chrono_get_time(todoEliminar, "Eliminar en todas las estructuras");

  if (n < 50) {
    cout << "HASH" << endl;
    hash_print(hash, m);
    cout << endl;
    cout << "BST" << endl;
    bst_print(bst);
    cout << endl;
    cout << "LISTA" << endl;
    lista_print(list);
    cout << endl;
    cout << "ARREGLO" << endl;
    arreglo_print(arreglo, largoArreglo);
  }

  cout << endl << endl << endl << "Terminado!!" << endl << endl;
  return 0;
}
