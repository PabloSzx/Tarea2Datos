#ifndef GENERAR_H
#define GENERAR_H

int generar_numero();
int generar_numero(int n);
hashNode** generar_hash(int n, int m);
avlNode* generar_bst(int n);
lista* generar_lista(int n);
int* generar_arreglo(int n, int* largoArreglo);
hashNode** generar_hash_desde_arreglo(int* arreglo, int n, int m);
avlNode* generar_bst_desde_arreglo(int* arreglo, int n);
lista* generar_lista_desde_arreglo(int* arreglo, int n);

int number;
int dim = 1000000;

hashNode** generar_hash(int n, int m) {
  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i=0; i < m; i++){
    ht[i] = NULL;
  }
  hash_gen_function(m);

  file_write("--hash--");

  for(int i = 0; i < n; i++){
    number = generar_numero();
    auto t = chrono_now();
    hash_insert(ht, number);
    chrono_get_time(t);
  }

  return ht;
}

avlNode* generar_bst(int n) {
  avlNode *bst = NULL;

  file_write("--bst--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    auto t = chrono_now();
    bst = bst_insert(bst, number);
    chrono_get_time(t);
  }

  return bst;
}

lista* generar_lista(int n) {
  lista *list = lista_create();

  file_write("--lista--");

  for(int i = 0; i < n;i++){
    number = generar_numero();
    auto t = chrono_now();
    lista_insert(&list, number);
    chrono_get_time(t);
  }

  return list;
}

int* generar_arreglo(int n, int* largoArreglo) {
  int* arreglo = arreglo_create(n);

  // file_write_no_breakline("--arreglo con n= ");
  // file_write_no_breakline(n);
  // file_write("--");
  // file_write("--arreglo--");
  // file_write_no_breakline(n);
  // file_write(n)

  auto tiempo = chrono_now();
  for(int i = 0; i < n;i++){
    number = generar_numero();
    // auto t = chrono_now();
    arreglo_insert(arreglo, i, number, largoArreglo);
    // chrono_get_time(t);
  }
  // double n2 = n;
  // auto tiempo2 = (tiempo / n2);
  // cout << tiempo2 << endl;
  chrono_get_time(tiempo);
  // auto tiempo2 = chrono_get_time_double(tiempo1);



  // file.write((t2-t1) / n)

  return arreglo;
}

int generar_numero() {
  //Retorna numero entre 0 y 1000000
  return (rand() % (dim + 1));
}

int generar_numero(int n) {
  //Retorna numero entre 0 y (n - 1)
  return (rand() % n);
}

hashNode** generar_hash_desde_arreglo(int* arreglo, int n, int m){
  hashNode **ht = (hashNode**)malloc(sizeof(hashNode*)*m);
  for(int i = 0; i < m; i++){
    ht[i] = NULL;
  }
  hash_gen_function(m);

  // file_write("--hash--");
  // file_write_no_breakline("--hash con n= ");
  // file_write_no_breakline(n);
  // file_write("--");


  auto tiempo = chrono_now();
  for(int i = 0; i < n; i++){
    // auto t = chrono_now();
    hash_insert(ht, arreglo[i]);
    // chrono_get_time(t);
  }
  chrono_get_time(tiempo);

  return ht;
}


avlNode* generar_bst_desde_arreglo(int* arreglo, int n) {
  avlNode *bst = NULL;

  // file_write("--bst--");

  // file_write_no_breakline("--bst con n= ");
  // file_write_no_breakline(n);
  // file_write("--");

  auto tiempo = chrono_now();

  for(int i = 0; i < n;i++){
    // auto t = chrono_now();
    bst = bst_insert(bst, arreglo[i]);
    // chrono_get_time(t);
  }

  chrono_get_time(tiempo);

  return bst;
}


lista* generar_lista_desde_arreglo(int* arreglo, int n) {

  lista *list = lista_create();

  // file_write("--lista--");
  // file_write_no_breakline("--lista con n= ");
  // file_write_no_breakline(n);
  // file_write("--");


  auto tiempo = chrono_now();
  for (int i = 0; i < n; i++) {
    // auto t = chrono_now();
    lista_insert(&list, arreglo[i]);
    // chrono_get_time(t);
  }

  chrono_get_time(tiempo);

  return list;
}

#endif
