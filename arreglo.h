
using namespace std;

int* arreglo_crear(int n) {
  int *arreglo=(int*)malloc(sizeof(int)*n);
  return arreglo;
}

void arreglo_insert(int *arreglo, int i, int x) {
  arreglo[i] = x;
}

int arreglo_buscar(int *arreglo, int x, int n) {
  int i = 0;
  while (i < n) {
    if (arreglo[i] == x) {
      return i;
    }
    i++;
  }

  return -1;
}

void arreglo_delete(int *arreglo, int pos) {
  if (pos != -1) {
    arreglo[pos] = 0;
  }
}

void arreglo_print(int *arreglo, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    if (arreglo[i] > 0) {
      cout << arreglo[i];
      if (i < n - 1) {
        cout << "-";
      }
    }
  }

  cout << "]" << endl;;
}
