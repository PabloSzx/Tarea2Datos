#include "dependencies.h"

int main(int argc, char const *argv[]) {

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }

  int n = atoi(argv[1]);

  file_clear("insercion");
  file_clear("eliminacion");

  file_write("insercion", "BST");
  start_time();
  avlNode *tree = NULL;

  tree = bst_insert(tree, 1);
  tree = bst_insert(tree, 3);
  tree = bst_insert(tree, 2);
  tree = bst_insert(tree, 5);
  tree = bst_insert(tree, 8);
  tree = bst_insert(tree, 4);
  tree = bst_insert(tree, 10);
  tree = bst_insert(tree, 12);
  tree = bst_insert(tree, 13);

  tree = bst_insert(tree, 14);
  tree = bst_insert(tree, 16);
  tree = bst_insert(tree, 20);
  tree = bst_insert(tree, 22);
  tree = bst_insert(tree, 32);
  tree = bst_insert(tree, 42);

  end_time("Insertar elementos en bst", "insercion");

  bst_print(tree);

  file_write("eliminacion", "Eliminar un elemento en bst");

  cout << "eliminar valor 5" << endl;
  start_time();

  tree = bst_delete(tree, 5);

  end_time("Eliminar elementos en bst", "eliminacion");

  bst_print(tree);


  return 0;
}
