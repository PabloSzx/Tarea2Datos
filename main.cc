#include "dependencies.h"

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  int n = atoi(argv[1]);
  int m = sqrt(n);

  file_clear("insercion");
  file_clear("eliminacion");

  clock_t one = clock();

  file_open("insercion");

  hashNode** hash = generar_hash(n, m);

  avlNode* bst = generar_bst(n);

  lista* list = generar_lista(n);

  int* arreglo = generar_arreglo(n);

  clock_start(one);
  clock_end("Generar todos los arreglos");

  cout << endl;

  file_write("--end--");
  file_close();

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
  arreglo_print(arreglo, n);

  cout << "Terminado" << endl;
  return 0;
}
