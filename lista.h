
using namespace std;

typedef struct nodoLista {
  int n;
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
  n->n = number;
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
    cout << ptr->n << "-";
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
    if (ptr->n == x) {
      return ptr;
    }

    ptr = ptr->next;
  }

  return NULL;
}

void lista_eliminar(lista **lista, nodoLista **ptr) {
  if ((*ptr)->next == NULL && (*ptr)->prev == NULL) {
    (*lista)->start = NULL;
  } else {
    if ((*ptr)->next != NULL) {
      ((*ptr)->next)->prev = (*ptr)->prev;
    } else {
      ((*ptr)->prev)->next = NULL;
    }

    if ((*ptr)->prev != NULL) {
      ((*ptr)->prev)->next = (*ptr)->next;
    } else {
      (*lista)->start = (*ptr)->next;
    }
  }
}
