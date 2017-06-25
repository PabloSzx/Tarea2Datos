#include "dependencies.h"

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  int n = atoi(argv[1]);

  file_clear("insercion");
  file_clear("eliminacion");

  clock_t one = clock();

  file_open("insercion");

  hashNode** hash = generar_hash(n, sqrt(n));

  avlNode* bst = generar_bst(n);

  lista* list = generar_lista(n);

  int* arreglo = generar_arreglo(n);

  start_time(one);
  end_time("Generar todos los arreglos");
  file_write("--end--");
  file_close();

  cout << "Terminado" << endl;
  return 0;
}
