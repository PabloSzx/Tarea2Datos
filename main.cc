#include "dependencies.h"

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  int n = atoi(argv[1]);
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
  file_write_no_breakline("-- n=");
  file_write(n);
  auto todo = chrono_now();
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
  lista* list = generar_lista_desde_arreglo(arreglo, n);
  chrono_end("Generar la lista desde el arreglo previo");

  chrono_get_time(todo, "Generar todas las estructuras");

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
  // file_clear("eliminacion");
  file_open("eliminacion");


  cout << endl << endl << endl;


  
  // int nrand = generar_numero(n);
  // int x = arreglo[nrand];
  // cout << "Se eliminara la posicion " << nrand << " del arreglo" << endl;
  // cout << "Y el elemento a eliminar es " << x << endl << endl;


  // file_write("--hash--");
  // chrono_start();
  // hash_delete(hash_search(hash, x));
  // chrono_end();
  // chrono_end("Eliminacion en hash");
  //
  //
  // file_write("--bst--");
  // chrono_start();
  // bst = bst_delete(bst, x);
  // chrono_end();
  // chrono_end("Eliminacion en bst");
  //
  // file_write("--lista--");
  // chrono_start();
  // lista_delete(lista_search(&list, x));
  // chrono_end();
  // chrono_end("Eliminacion en lista");
  //
  // file_write("--arreglo--");
  // chrono_start();
  // arreglo_delete(arreglo, arreglo_search(arreglo, x, largoArreglo), &largoArreglo);
  // chrono_end();
  // chrono_end("Eliminacion en arreglo");


  // if (n < 50) {
  //   cout << "HASH" << endl;
  //   hash_print(hash, m);
  //   cout << endl;
  //   cout << "BST" << endl;
  //   bst_print(bst);
  //   cout << endl;
  //   cout << "LISTA" << endl;
  //   lista_print(list);
  //   cout << endl;
  //   cout << "ARREGLO" << endl;
  //   arreglo_print(arreglo, largoArreglo);
  // }

  cout << endl << endl << endl << "Terminado!!" << endl;
  return 0;
}
