#ifndef HASH_H
#define HASH_H

int h1(int x){
  return x % m;
}

// mapeo universal hashing
int h2(int x);

int esprimo(int n){
  int i,root;
  if (n%2 == 0 || n%3 == 0)
  return 0;

  root = (int)sqrt(n);
  for (i=5; i<=root; i+=6){
    if (n%i == 0)
    return 0;
  }
  for (i=7; i<=root; i+=6){
    if (n%i == 0)
    return 0;
  }
  return 1;
}

void print_ht(nodo **ht, int m){
  for(int i=0; i<m; ++i) {
    nodo *aux = ht[i];
    printf("ht[%i] = ", i);
    while(aux != NULL){
      printf("(%i) --> ", aux->val);
      aux = aux->next;
    }
    printf("NULL\n");
  }
}



// 1) encuentra el menor primo mayor que m
int mprimo(int m){
  int c = m;
  while (!esprimo(c)) {
    c += 1;
  }
  return c;
}

// 2) genera los parametros de una funcion hash
void gen_hashfunc(int m, int *a, int *b, int *p){
  *p = mprimo(m);
  *a = (rand() % *p) + 1;
  *b = rand() % *p;
}


// 3) inserta un elemento x en ht donde corresponde
void inserta(nodo **ht, int x){
  // int pos = h1(x);
  int pos = h2(x);

  nodo *a = crear_nodo(x);
  nodo *aux = ht[pos];
  a->next = aux;
  ht[pos] = a;
}

// 4) retorna 1 si x existe en ht, de lo contrario 0
int existe(nodo **ht, int x){
  // int pos = h1(x);
  int pos = h2(x);
  nodo *aux = ht[pos];
  while (aux != NULL) {
    if (aux->val == x) {
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}

// 5) universal hashing
int h2(int x){
  return (( (a*x + b) % p) % m);
}


#endif
