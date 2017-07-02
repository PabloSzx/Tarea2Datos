#ifndef AVL_H
#define AVL_H

struct avlNode {
  int val;
  struct avlNode *left;
  struct avlNode *right;
  int height;
};

int bst_height(avlNode *N);
avlNode* bst_create(int val);
void bst_print(avlNode* p, int indent);
avlNode *bst_right_rotate(avlNode *y);
avlNode *bst_left_rotate(avlNode *x);
int bst_get_balance(avlNode *N);
avlNode* bst_insert(avlNode* node, int val);
avlNode* bst_search(avlNode **r, int val);
avlNode* bst_min_value_node(avlNode* node);
avlNode* bst_delete( avlNode* root, int val);

int bst_height(avlNode *N) {
  if (N == NULL)
  return 0;
  return N->height;
}

avlNode* bst_create(int val) {
  avlNode* node = (avlNode*)malloc(sizeof(avlNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return(node);
}

void bst_print(avlNode* p, int indent = 0) {
  if(p != NULL) {
    if(p->right) {
      bst_print(p->right, indent+4);
    }
    if (indent) {
      cout << setw(indent) << ' ';
    }
    if (p->right) cout<<" /\n" << setw(indent) << ' ';
    cout<< p->val << "\n ";
    if(p->left) {
      cout << setw(indent) << ' ' <<" \\\n";
      bst_print(p->left, indent+4);
    }
  }
}

avlNode *bst_right_rotate(avlNode *y) {
  avlNode *x = y->left;
  avlNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(bst_height(y->left), bst_height(y->right))+1;
  x->height = max(bst_height(x->left), bst_height(x->right))+1;

  return x;
}

avlNode *bst_left_rotate(avlNode *x) {
  avlNode *y = x->right;
  avlNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(bst_height(x->left), bst_height(x->right))+1;
  y->height = max(bst_height(y->left), bst_height(y->right))+1;

  return y;
}

int bst_get_balance(avlNode *N) {
  if (N == NULL) {
    return 0;
  }
  return bst_height(N->left) - bst_height(N->right);
}

avlNode* bst_insert(avlNode* node, int val) {
  if (node == NULL) {
    return(bst_create(val));
  }
  if (val < node->val) {
    node->left  = bst_insert(node->left, val);
  } else if (val > node->val) {
    node->right = bst_insert(node->right, val);
  } else {
    return node;
  }


  node->height = 1 + max(bst_height(node->left),
  bst_height(node->right));

  int balance = bst_get_balance(node);

  if (balance > 1 && val < node->left->val) {
    return bst_right_rotate(node);
  }
  if (balance < -1 && val > node->right->val) {
    return bst_left_rotate(node);
  }
  if (balance > 1 && val > node->left->val) {
    node->left =  bst_left_rotate(node->left);
    return bst_right_rotate(node);
  }

  if (balance < -1 && val < node->right->val) {
    node->right = bst_right_rotate(node->right);
    return bst_left_rotate(node);
  }

  return node;
}

avlNode* bst_search(avlNode **r, int val) {
  if ((*r) == NULL) {
    return NULL;
  } else if ((*r)->val < val) {
    return bst_search(&(*r)->right, val);
  } else if ((*r)->val > val) {
    return bst_search(&(*r)->left, val);
  } else {
    return (*r);
  }
}


avlNode* bst_min_value_node(avlNode* node) {
  avlNode* current = node;

  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}


avlNode* bst_delete( avlNode* root, int val) {

  if (root == NULL) {
    return root;
  }
  if ( val < root->val ) {
    root->left = bst_delete(root->left, val);
  }
  else if( val > root->val ) {
    root->right = bst_delete(root->right, val);
  }
  else {
    if( (root->left == NULL) || (root->right == NULL) ) {
      avlNode *temp = root->left ? root->left :
      root->right;

      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
      *root = *temp;
    } else {
      avlNode* temp = bst_min_value_node(root->right);

      root->val = temp->val;

      root->right = bst_delete(root->right, temp->val);
    }
  }

  if (root == NULL) {
    return root;
  }
  root->height = 1 + max(bst_height(root->left),
  bst_height(root->right));

  int balance = bst_get_balance(root);


  if (balance > 1 && bst_get_balance(root->left) >= 0) {
    return bst_right_rotate(root);
  }
  if (balance > 1 && bst_get_balance(root->left) < 0) {
    root->left =  bst_left_rotate(root->left);
    return bst_right_rotate(root);
  }

  if (balance < -1 && bst_get_balance(root->right) <= 0) {
    return bst_left_rotate(root);
  }
  if (balance < -1 && bst_get_balance(root->right) > 0) {
    root->right = bst_right_rotate(root->right);
    return bst_left_rotate(root);
  }

  return root;
}

#endif
