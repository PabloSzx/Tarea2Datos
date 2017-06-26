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

  file_clear("insercion");
  file_clear("eliminacion");

  // clock_t one = clock();

  // file_open("insercion");

  // hashNode** hash = generar_hash(n, m);
  //
  // avlNode* bst = generar_bst(n);
  //
  // lista* list = generar_lista(n);
  //
  // int* arreglo = generar_arreglo(n);
  //
  // clock_start(one);
  // clock_end("Generar todos los arreglos");
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
  //

  //CORTE ES ACA
  file_clear("insercion");
  file_open("insercion");

  int largoArreglo = 0;
  int* arreglo = generar_arreglo(n, &largoArreglo);


  hashNode** hash = generar_hash_desde_arreglo(arreglo, n, m);

  avlNode* bst = generar_bst_desde_arreglo(arreglo, n);

  lista* list = generar_lista_desde_arreglo(arreglo, n);


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

  file_close();
  file_clear("eliminacion");
  file_open("eliminacion");

  cout << "VAMOS A ELIMINAR EL N/2 VALOR DEL ARREGLO, EN TODAS LAS ESTRUCTURAS" << endl;

  int x = arreglo[n/2];
  cout << "x es " << x << endl;


  file_write("--hash--");
  clock_start();
  hash_delete(hash_search(hash, x));
  clock_end();
  clock_end("Eliminacion en hash");


  file_write("--bst--");
  clock_start();
  bst = bst_delete(bst, x);
  clock_end();
  clock_end("Eliminacion en bst");

  file_write("--lista--");
  clock_start();
  lista_delete(lista_search(&list, x));
  clock_end();
  clock_end("Eliminacion en lista");

  file_write("--arreglo--");
  clock_start();
  arreglo_delete(arreglo, arreglo_search(arreglo, x, largoArreglo), &largoArreglo);
  clock_end();
  clock_end("Eliminacion en arreglo");


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


  cout << "Terminado" << endl;
  return 0;
}
