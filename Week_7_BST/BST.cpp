#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    if (root == nullptr) {
        root = new node();
        root->key = key;
        return root;
    }
    node **temp = &root;
    while (*temp != nullptr) {
        if ((*temp)->key > key) {
            temp = &(*temp)->left;
        } else if ((*temp)->key < key) {
            temp = &(*temp)->right;
        } else {
            return root;
        }
    }
    *temp = new node();
    (*temp)->key = key;
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) {
        return root;
    }
    node **temp = &root;
    while (*temp != nullptr) {
        if ((*temp)->key > key) {
            temp = &(*temp)->left;
        } else if ((*temp)->key < key) {
            temp = &(*temp)->right;
        } else if ((*temp)->key == key){
            if ((*temp)->right != nullptr) {
                if ((*temp)->key == (*temp)->right->key) {
                    temp = &(*temp)->right;
                }
            }
            if ((*temp)->left == nullptr && (*temp)->right == nullptr) {
                (*temp) = nullptr;
                return root;
            }
            if ((*temp)->right == nullptr) {
                if ((*temp)->left->left == nullptr && (*temp)->left->right == nullptr) {
                    (*temp) = (*temp)->left;
                    return root;
                }
            }
            if ((*temp)->left == nullptr) {
                if ((*temp)->right->right == nullptr && (*temp)->right->left == nullptr) {
                    (*temp) = (*temp)->right;
                    return root;
                }
            }
            int nextRem = (*temp)->right->key;
            (*temp)->key = nextRem;
            root = deleteNode(root, nextRem);
            return root;
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}