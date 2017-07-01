#ifndef LISTA_H
#define LISTA_H

// typedef struct nodoLista {
//   int val;
//   struct nodoLista *prev;
//   struct nodoLista *next;
// }nodoLista;
typedef struct nodoLista {
  int val;
  // struct nodoLista *prev;
  struct nodoLista *next;
}nodoLista;

nodoLista* lista_crear_nodo(int x);
void lista_insert(nodoLista** list, int x);
nodoLista* lista_search(nodoLista** list, int x);
void lista_delete(nodoLista** list, nodoLista* x);


// typedef struct lista {
//   nodoLista *start;
//   int length;
// } lista;

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




// lista* lista_create();
// void lista_insert(lista **lista, int number);
// void lista_print(lista *lista);
// nodoLista* lista_search(lista **lista, int x);
// void lista_delete(nodoLista *nodo);

// lista* lista_create() {
//   lista *l = (lista*)malloc(sizeof(lista));
//   l->length = 0;
//   l->start = NULL;
//   return (l);
// }
//
// void lista_insert(lista **lista, int number) {
//   nodoLista *n = (nodoLista *)malloc(sizeof(nodoLista));
//   n->val = number;
//   if ((*lista)->start == NULL) {
//     n->next = NULL;
//     n->prev = NULL;
//     (*lista)->start = n;
//   } else {
//     ((*lista)->start)->prev = n;
//     n->next = (*lista)->start;
//     (*lista)->start = n;
//   }
//
//   (*lista)->length++;
// }
//
// void lista_print(lista *lista) {
//   nodoLista *ptr = (lista)->start;
//
//   cout << endl;
//
//   while (ptr != NULL) {
//     cout << "(";
//     cout << ptr->val;
//     if (ptr->next != NULL) {
//       cout << ") -> ";
//     }
//     ptr = ptr->next;
//   }
//
//   cout << ")" << endl;
// }
//
// nodoLista* lista_search(lista **lista, int x) {
//   nodoLista *ptr = (*lista)->start;
//
//   while (ptr != NULL) {
//     if (ptr->val == x) {
//       return ptr;
//     }
//
//     ptr = ptr->next;
//   }
//
//   return NULL;
// }
//
// void lista_delete(nodoLista *nodo) {
//   if (nodo != NULL) {
//     if ((nodo)->next == NULL && (nodo)->prev == NULL) {
//       (nodo) = NULL;
//     } else {
//       if ((nodo)->next != NULL) {
//         ((nodo)->next)->prev = (nodo)->prev;
//       } else {
//         ((nodo)->prev)->next = NULL;
//       }
//
//       if ((nodo)->prev != NULL) {
//         ((nodo)->prev)->next = (nodo)->next;
//       } else {
//         (nodo) = (nodo)->next;
//       }
//     }
//   }
// }


#endif
