#ifndef LISTA_H
#define LISTA_H

typedef struct nodoLista {
  int val;
  struct nodoLista *next;
}nodoLista;

nodoLista* lista_crear_nodo(int x);
void lista_insert(nodoLista** list, int x);
nodoLista* lista_search(nodoLista** list, int x);
void lista_delete(nodoLista** list, nodoLista* x);
void lista_print(nodoLista *list);

nodoLista* lista_crear_nodo(int x) {
  nodoLista *nuevo = (nodoLista*)malloc(sizeof(nodoLista));
  nuevo->val = x;
  nuevo->next = NULL;
  return nuevo;
}

void lista_insert(nodoLista** list, int x) {
  if ((*list) == NULL) {
    (*list) = lista_crear_nodo(x);
  } else {
    nodoLista *insert = lista_crear_nodo(x);
    insert->next = (*list);
    (*list) = insert;
  }
}

nodoLista* lista_search(nodoLista** list, int x) {
  nodoLista* p = (nodoLista*)malloc(sizeof(nodoLista));
  p = (*list);
  while ((p != NULL) && (p->val != x)) {
    p = p->next;
  }

  return p;
}

void lista_delete(nodoLista** list, nodoLista* x) {
  nodoLista* p =(*list);
  if (x == (*list)) {
    (*list) = (*list)->next;
    free(p);
  } else {
    while (p->next != x) {
      p = p->next;
    }
    if (x != NULL) {
      p->next = x->next;
    } else {
      p->next = NULL;
    }
    free(x);
  }
}

void lista_print(nodoLista *list) {
  nodoLista *ptr = list;

  cout << endl;

  while (ptr != NULL) {
    cout << "(";
    cout << ptr->val;
    if (ptr->next != NULL) {
      cout << ") -> ";
    }
    ptr = ptr->next;
  }

  cout << ")" << endl;
}


#endif
