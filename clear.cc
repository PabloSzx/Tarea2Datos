#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "utilities/file.h"

int main(int argc, char const *argv[]) {
  file_clear("insercion");
  file_clear("busqueda");
  file_clear("eliminacion");

  file_open("insercion");
  file_write_breakline("N Arreglo Hash Bst Lista");
  file_close();

  file_open("busqueda");
  file_write_breakline("N Arreglo Hash Bst Lista");
  file_close();

  file_open("eliminacion");
  file_write_breakline("N Arreglo Hash Bst Lista");
  file_close();

  return 0;
}
