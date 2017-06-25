#ifndef ARREGLO_H
#define ARREGLO_H

int* arreglo_create(int n);
void arreglo_insert(int *arreglo, int i, int x);
int arreglo_search(int *arreglo, int x, int n);
void arreglo_delete(int *arreglo, int pos);
void arreglo_print(int *arreglo, int n);

int* arreglo_create(int n) {
  int *arreglo=(int*)malloc(sizeof(int)*n);
  return arreglo;
}

void arreglo_insert(int *arreglo, int i, int x) {
  arreglo[i] = x;
}

int arreglo_search(int *arreglo, int x, int n) {
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
  cout << "[ ";
  for (int i = 0; i < n; i++) {
    if (arreglo[i] > 0) {
      cout << arreglo[i];
      if (i < n - 1) {
        cout << " - ";
      }
    }
  }

  cout << " ]" << endl;
}

#endif
