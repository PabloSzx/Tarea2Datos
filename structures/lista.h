#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>

using namespace std;

typedef struct nodoLista {
  int val;
  struct nodoLista *prev;
  struct nodoLista *next;
}nodoLista;

typedef struct lista {
  nodoLista *start;
  int length;
} lista;

lista* lista_crear() {
  lista *l = (lista*)malloc(sizeof(lista));
  l->length = 0;
  l->start = NULL;
  return (l);
}

void lista_insertar(lista **lista, int number) {
  nodoLista *n = (nodoLista *)malloc(sizeof(nodoLista));
  n->val = number;
  if ((*lista)->start == NULL) {
    n->next = NULL;
    n->prev = NULL;
    (*lista)->start = n;
    (*lista)->length++;
  } else {
    ((*lista)->start)->prev = n;
    n->next = (*lista)->start;
    (*lista)->start = n;
    (*lista)->length++;
  }
}

void lista_imprimir(lista *lista) {
  // cout << "\n El length de la lista es: " << (lista)->length;

  nodoLista *ptr = (lista)->start;
  cout << "\n|";

  while (ptr != NULL) {
    if (ptr->prev != NULL) {
      cout << "| <- |";
    }
    cout << ptr->val << "-";
    if (ptr->next != NULL) {
      cout << "| -> |";
    }
    ptr = ptr->next;
  }

  cout << "|\n";
}

nodoLista* lista_buscar(lista **lista, int x) {
  nodoLista *ptr = (*lista)->start;

  while (ptr != NULL) {
    if (ptr->val == x) {
      return ptr;
    }

    ptr = ptr->next;
  }

  return NULL;
}

void lista_eliminar(nodoLista **nodo) {
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

#endif
