// C program to insert a node in AVL tree

using namespace std;
// An AVL tree node
struct avlNode
{
  int key;
  struct avlNode *left;
  struct avlNode *right;
  int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int bst_height(avlNode *N)
{
  if (N == NULL)
  return 0;
  return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
  return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
NULL left and right pointers. */
avlNode* bst_crear_nodo(int key)
{
  avlNode* node = (avlNode*)
  malloc(sizeof(avlNode));
  node->key   = key;
  node->left   = NULL;
  node->right  = NULL;
  node->height = 1;  // new node is initially added at leaf
  return(node);
}

void bst_print(avlNode* p, int indent = 0)

{
  if(p != NULL) {
    if(p->right) {
      bst_print(p->right, indent+4);
    }
    if (indent) {
      cout << setw(indent) << ' ';
    }
    if (p->right) cout<<" /\n" << setw(indent) << ' ';
    cout<< p->key << "\n ";
    if(p->left) {
      cout << setw(indent) << ' ' <<" \\\n";
      bst_print(p->left, indent+4);
    }
  }
}


// A utility function to right rotate subtree rooted with y
// See the diagram given above.
avlNode *bst_right_rotate(avlNode *y)
{
  avlNode *x = y->left;
  avlNode *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(bst_height(y->left), bst_height(y->right))+1;
  x->height = max(bst_height(x->left), bst_height(x->right))+1;

  // Return new root
  return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
avlNode *bst_left_rotate(avlNode *x)
{
  avlNode *y = x->right;
  avlNode *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  //  Update heights
  x->height = max(bst_height(x->left), bst_height(x->right))+1;
  y->height = max(bst_height(y->left), bst_height(y->right))+1;

  // Return new root
  return y;
}

// Get Balance factor of node N
int bst_get_balance(avlNode *N)
{
  if (N == NULL)
  return 0;
  return bst_height(N->left) - bst_height(N->right);
}

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
avlNode* bst_insert(avlNode* node, int key)
{
  /* 1.  Perform the normal BST insertion */
  if (node == NULL)
  return(bst_crear_nodo(key));

  if (key < node->key)
  node->left  = bst_insert(node->left, key);
  else if (key > node->key)
  node->right = bst_insert(node->right, key);
  else // Equal keys are not allowed in BST
  return node;

  /* 2. Update height of this ancestor node */
  node->height = 1 + max(bst_height(node->left),
  bst_height(node->right));

  /* 3. Get the balance factor of this ancestor
  node to check whether this node became
  unbalanced */
  int balance = bst_get_balance(node);

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && key < node->left->key)
  return bst_right_rotate(node);

  // Right Right Case
  if (balance < -1 && key > node->right->key)
  return bst_left_rotate(node);

  // Left Right Case
  if (balance > 1 && key > node->left->key)
  {
    node->left =  bst_left_rotate(node->left);
    return bst_right_rotate(node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key)
  {
    node->right = bst_right_rotate(node->right);
    return bst_left_rotate(node);
  }

  /* return the (unchanged) node pointer */
  return node;
}

avlNode* bst_buscar(avlNode **r, int val){
  if ((*r) == NULL) {
    cout << "\nNodo no encontrado";
    return NULL;
  } else if ((*r)->key < val) {
    return bst_buscar(&(*r)->right, val);
  } else if ((*r)->key > val) {
    return bst_buscar(&(*r)->left, val);
  } else {
    return (*r);
  }
}


avlNode* bst_min_value_node(avlNode* node)
{
  avlNode* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL)
  current = current->left;

  return current;
}

avlNode* bst_delete( avlNode* root, int key) {
  // STEP 1: PERFORM STANDARD BST DELETE

  if (root == NULL)
  return root;

  // If the key to be deleted is smaller than the
  // root's key, then it lies in left subtree
  if ( key < root->key )
  root->left = bst_delete(root->left, key);

  // If the key to be deleted is greater than the
  // root's key, then it lies in right subtree
  else if( key > root->key )
  root->right = bst_delete(root->right, key);

  // if key is same as root's key, then This is
  // the node to be deleted
  else
  {
    // node with only one child or no child
    if( (root->left == NULL) || (root->right == NULL) )
    {
      avlNode *temp = root->left ? root->left :
      root->right;

      // No child case
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else // One child case
      *root = *temp; // Copy the contents of
      // the non-empty child
      free(temp);
    }
    else
    {
      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      avlNode* temp = bst_min_value_node(root->right);

      // Copy the inorder successor's data to this node
      root->key = temp->key;

      // Delete the inorder successor
      root->right = bst_delete(root->right, temp->key);
    }
  }

  // If the tree had only one node then return
  if (root == NULL)
  return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = 1 + max(bst_height(root->left),
  bst_height(root->right));

  // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
  // check whether this node became unbalanced)
  int balance = bst_get_balance(root);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && bst_get_balance(root->left) >= 0)
  return bst_right_rotate(root);

  // Left Right Case
  if (balance > 1 && bst_get_balance(root->left) < 0)
  {
    root->left =  bst_left_rotate(root->left);
    return bst_right_rotate(root);
  }

  // Right Right Case
  if (balance < -1 && bst_get_balance(root->right) <= 0)
  return bst_left_rotate(root);

  // Right Left Case
  if (balance < -1 && bst_get_balance(root->right) > 0)
  {
    root->right = bst_right_rotate(root->right);
    return bst_left_rotate(root);
  }

  return root;
}
