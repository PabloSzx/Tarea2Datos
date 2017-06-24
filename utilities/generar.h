int generar_numero();
hashNode** generar_hash(int n, int m);
avlNode* generar_bst(int n);
lista* generar_lista(int n);
int* generar_arreglo(int n);

int dim=1000000;


hashNode** generar_hash(int n, int m) {
  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i=0; i < m; i++){
    ht[i] = NULL;
  }
  hash_gen_function(m);

  for(int i = 0; i < n; i++){
    hash_insert(ht, generar_numero());
  }

  return ht;
}

avlNode* generar_bst(int n) {
  avlNode *bst = NULL;

  for(int i = 0; i < n;i++){
    bst = bst_insert(bst, generar_numero());
  }

  return bst;
}

lista* generar_lista(int n) {
  lista *list = lista_crear();
  for(int i = 0; i < n;i++){
    lista_insertar(&list, generar_numero());
  }


  return list;
}

int* generar_arreglo(int n) {
  int *arreglo = arreglo_crear(n);
  for(int i = 0; i < n;i++){
    arreglo_insert(arreglo, i, generar_numero());
  }

  return arreglo;
}

int generar_numero() {
  srand(time(NULL));
  return rand()%dim;
}
