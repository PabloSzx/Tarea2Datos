#ifndef ARREGLO_H
#define ARREGLO_H

int* arreglo_create(int n);
void arreglo_insert(int* arreglo, int i, int x, int* n);
int arreglo_search(int* arreglo, int x, int n);
void arreglo_delete(int* arreglo, int pos, int *n);
void arreglo_print(int* arreglo, int n);

int* arreglo_create(int n) {
  int *arreglo=(int*)malloc(sizeof(int)*n);
  return arreglo;
}

void arreglo_insert(int* arreglo, int i, int x, int* n) {
  (*n)++;
  arreglo[i] = x;
}

int arreglo_search(int* arreglo, int x, int n) {
  int i = 0;
  while (i < n) {
    if (arreglo[i] == x) {
      return i;
    }
    i++;
  }

  return -1;
}

void arreglo_delete(int* arreglo, int pos, int *n) {
  if (pos != -1) {
    int *aux=(int*)malloc(sizeof(int)*(*n - 1));

    int i = 0;
    int j = 0;
    while (i != *n) {
      if (i != pos) {
        aux[j] = (arreglo)[i];
        j++;
      }
      i++;
    }
    (*n) = (*n) - 1;

    copy(aux, aux + *n, arreglo);
  }
}

void arreglo_print(int* arreglo, int n) {
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
