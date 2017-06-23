#ifndef HASH_H
#define HASH_H

typedef struct hashNode{
  int val;
  struct hashNode* next;
} hashNode;

hashNode* crear_nodo(int x){
  hashNode *aux = (hashNode*)malloc(sizeof(hashNode));
  aux->val = x;
  aux->next = NULL;
  return aux;
}

int a, b, p, m;

// int h1(int x){
//   return x % m;
// }
//
int h2(int x){
  return (( (a*x + b) % p) % m);
}

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

void hash_print(hashNode **ht, int m){
  for(int i=0; i<m; ++i) {
    hashNode *aux = ht[i];
    cout << "ht[" << i << "] = ";
    // printf("ht[%i] = ", i);
    while(aux != NULL){
      cout << "(" << aux->val << ") --> ";
      // printf("(%i) --> ", aux->val);
      aux = aux->next;
    }
    cout << "NULL" << endl;
    // printf("NULL\n");
  }
}



// 1) encuentra el menor primo mayor que m
int mprimo(int n){
  int c = n;
  while (!esprimo(c)) {
    c += 1;
  }
  return c;
}

void gen_hashfunc(int n){
  m = n;
  p = mprimo(n);
  a = (rand() % p) + 1;
  b = rand() % p;
}



// 3) inserta un elemento x en ht donde corresponde
void hash_insert(hashNode **ht, int x){
  int pos = h2(x);

  hashNode *a = crear_nodo(x);
  hashNode *aux = ht[pos];
  a->next = aux;
  ht[pos] = a;
}

// 4) retorna 1 si x existe en ht, de lo contrario 0
int hash_exists(hashNode **ht, int x){
  // int pos = h1(x);
  int pos = h2(x);
  hashNode *aux = ht[pos];
  while (aux != NULL) {
    if (aux->val == x) {
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}



#endif
