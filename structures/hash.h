#ifndef HASH_H
#define HASH_H

typedef struct hashNode{
  int val;
  struct hashNode* next;
  struct hashNode* prev;
} hashNode;

hashNode* hash_create(int x);
int hash_function(int x);
int hash_es_primo(int n);
void hash_print(hashNode **ht, int m);
int hash_mprimo(int n);
void hash_gen_function(int n);
void hash_insert(hashNode **ht, int x);
hashNode* hash_search(hashNode **ht, int x);
void hash_delete(hashNode **nodo);
int hash_exists(hashNode **ht, int x);

int a, b, p, m;

hashNode* hash_create(int x) {
  hashNode *aux = (hashNode*)malloc(sizeof(hashNode));
  aux->val = x;
  aux->next = NULL;
  aux->prev = NULL;
  return aux;
}

int hash_function(int x) {
  return (( (a*x + b) % p) % m);
}

int hash_es_primo(int n) {
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

void hash_print(hashNode **ht, int m) {
  for(int i=0; i<m; ++i) {
    hashNode *aux = ht[i];
    cout << endl << "h[" << i << "] = ";
    // printf("ht[%i] = ", i);
    while(aux != NULL){
      cout << "(" << aux->val << ")";
      if (aux->next != NULL) {
        cout << " --> ";
      }
      // printf("(%i) --> ", aux->val);
      aux = aux->next;
    }
    cout << endl;
    // printf("NULL\n");
  }
}



// 1) encuentra el menor primo mayor que m
int hash_mprimo(int n) {
  int c = n;
  while (!hash_es_primo(c)) {
    c += 1;
  }
  return c;
}

void hash_gen_function(int n) {
  m = n;
  p = hash_mprimo(n);
  a = (rand() % p) + 1;
  b = rand() % p;
}



// 3) inserta un elemento x en ht donde corresponde
void hash_insert(hashNode **ht, int x) {
  int pos = hash_function(x);

  hashNode *n = hash_create(x);

  hashNode **ptr = &ht[pos];

  if ((*ptr) == NULL) {
    ht[pos] = n;
    // (*ptr) = n;
  } else {
    (*ptr)->prev = n;
    n->next = (*ptr);
    // ((*lista)->start)->prev = n;
    // n->next = (*lista)->start;
    ht[pos] = n;
    // (*lista)->start = n;
  }
}

hashNode* hash_search(hashNode **ht, int x) {
  int pos = hash_function(x);

  hashNode *ptr = ht[pos];

  while (ptr != NULL) {
    if (ptr->val == x) {
      return ptr;
    }
    ptr = ptr->next;
  }

  return NULL;
}

void hash_delete(hashNode **nodo) {
  if ((*nodo)->next == NULL && (*nodo)->prev == NULL) {
    (*nodo) = NULL;
    // (*lista)->start = NULL;
  } else {
    if ((*nodo)->next != NULL) {
      ((*nodo)->next)->prev = (*nodo)->prev;
    } else {
      ((*nodo)->prev)->next = NULL;
    }

    if ((*nodo)->prev != NULL) {
      ((*nodo)->prev)->next = (*nodo)->next;
    } else {
      (*nodo) = (*nodo)->next;
      // (*lista)->start = (*nodo)->next;
    }
  }
}

// 4) retorna 1 si x existe en ht, de lo contrario 0
int hash_exists(hashNode **ht, int x) {
  int pos = hash_function(x);
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
