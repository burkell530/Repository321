#include "bs_tree.h"
bool BSTree::Insert(int to_insert, BSTNode*& root) {
  if(root == NULL) {
    root = new BSTNode(to_insert);
    size_++;
    return true;
  } else if (to_insert < root->GetContents()) {
    return Insert(to_insert, root->GetLeftChild());
  } else if (to_insert > root->GetContents()) {
    return Insert(to_insert, root->GetRightChild());
  } else {
    return false;
  }
}
void BSTree::Clear(BSTNode*& root) {
  if(root != NULL) {
    Clear(root->GetLeftChild());
    Clear(root->GetRightChild());
    delete root;
    root = NULL;
    size_--;
  }
}
string BSTree::InOrder(BSTNode* root) {
  stringstream ss;
  if (root != NULL) {
    ss << InOrder(root->GetLeftChild());
    ss << root->GetContents() << " ";
    ss << InOrder(root->GetRightChild());
  }
  return ss.str();
}

