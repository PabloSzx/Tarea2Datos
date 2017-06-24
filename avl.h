#include <stdlib.h>
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
int height(struct avlNode *N)
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
struct avlNode* newAvlNode(int key)
{
  struct avlNode* node = (struct avlNode*)
  malloc(sizeof(struct avlNode));
  node->key   = key;
  node->left   = NULL;
  node->right  = NULL;
  node->height = 1;  // new node is initially added at leaf
  return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct avlNode *rightRotate(struct avlNode *y)
{
  struct avlNode *x = y->left;
  struct avlNode *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  // Return new root
  return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct avlNode *leftRotate(struct avlNode *x)
{
  struct avlNode *y = x->right;
  struct avlNode *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  //  Update heights
  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;

  // Return new root
  return y;
}

// Get Balance factor of node N
int getBalance(struct avlNode *N)
{
  if (N == NULL)
  return 0;
  return height(N->left) - height(N->right);
}

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct avlNode* avlInsert(struct avlNode* node, int key)
{
  /* 1.  Perform the normal BST insertion */
  if (node == NULL)
  return(newAvlNode(key));

  if (key < node->key)
  node->left  = avlInsert(node->left, key);
  else if (key > node->key)
  node->right = avlInsert(node->right, key);
  else // Equal keys are not allowed in BST
  return node;

  /* 2. Update height of this ancestor node */
  node->height = 1 + max(height(node->left),
  height(node->right));

  /* 3. Get the balance factor of this ancestor
  node to check whether this node became
  unbalanced */
  int balance = getBalance(node);

  // If this node becomes unbalanced, then
  // there are 4 cases

  // Left Left Case
  if (balance > 1 && key < node->left->key)
  return rightRotate(node);

  // Right Right Case
  if (balance < -1 && key > node->right->key)
  return leftRotate(node);

  // Left Right Case
  if (balance > 1 && key > node->left->key)
  {
    node->left =  leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && key < node->right->key)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
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

// struct avlNode* deleteNode(struct avlNode* root, int key)
// {
//   // STEP 1: PERFORM STANDARD BST DELETE
//
//   if (root == NULL)
//   return root;
//
//   // If the key to be deleted is smaller than the
//   // root's key, then it lies in left subtree
//   if ( key < root->key )
//   root->left = deleteNode(root->left, key);
//
//   // If the key to be deleted is greater than the
//   // root's key, then it lies in right subtree
//   else if( key > root->key )
//   root->right = deleteNode(root->right, key);
//
//   // if key is same as root's key, then This is
//   // the node to be deleted
//   else
//   {
//     // node with only one child or no child
//     if( (root->left == NULL) || (root->right == NULL) )
//     {
//       struct Node *temp = root->left ? root->left :
//       root->right;
//
//       // No child case
//       if (temp == NULL)
//       {
//         temp = root;
//         root = NULL;
//       }
//       else // One child case
//       *root = *temp; // Copy the contents of
//       // the non-empty child
//       free(temp);
//     }
//     else
//     {
//       // node with two children: Get the inorder
//       // successor (smallest in the right subtree)
//       struct Node* temp = minValueNode(root->right);
//
//       // Copy the inorder successor's data to this node
//       root->key = temp->key;
//
//       // Delete the inorder successor
//       root->right = deleteNode(root->right, temp->key);
//     }
//   }
//
//   // If the tree had only one node then return
//   if (root == NULL)
//   return root;
//
//   // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
//   root->height = 1 + max(height(root->left),
//   height(root->right));
//
//   // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
//   // check whether this node became unbalanced)
//   int balance = getBalance(root);
//
//   // If this node becomes unbalanced, then there are 4 cases
//
//   // Left Left Case
//   if (balance > 1 && getBalance(root->left) >= 0)
//   return rightRotate(root);
//
//   // Left Right Case
//   if (balance > 1 && getBalance(root->left) < 0)
//   {
//     root->left =  leftRotate(root->left);
//     return rightRotate(root);
//   }
//
//   // Right Right Case
//   if (balance < -1 && getBalance(root->right) <= 0)
//   return leftRotate(root);
//
//   // Right Left Case
//   if (balance < -1 && getBalance(root->right) > 0)
//   {
//     root->right = rightRotate(root->right);
//     return leftRotate(root);
//   }
//
//   return root;
// }


void postOrder(avlNode* p, int indent = 0)
{
  if(p != NULL) {
    if(p->right) {
      postOrder(p->right, indent+4);
    }
    if (indent) {
      std::cout << std::setw(indent) << ' ';
    }
    if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
    std::cout<< p->key << "\n ";
    if(p->left) {
      std::cout << std::setw(indent) << ' ' <<" \\\n";
      postOrder(p->left, indent+4);
    }
  }
}
