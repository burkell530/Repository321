#include "bs_tree.h"

BSTree::BSTree() {
  m_root = NULL;
  m_size = 0;
}

BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int data_to_insert) {
  return Insert(data_to_insert, m_root);
}

void BSTree::Clear() {
  Clear(m_root);
}

unsigned int BSTree::GetSize() const {
  return m_size;
}

string BSTree::InOrder() {
  return InOrder(m_root);
}

// string InOrder (BSTNode*), Creates a
// string of the data in all
// nodes in the tree, in ascending order,
// separate by spaces (there should be a
// space after the last output value).
string BSTree::InOrder(BSTNode* m_root) {
  stringstream ss;
  if (m_root != NULL) {
    ss << InOrder(m_root->GetLeftChild());
    ss << m_root->GetContents() << " ";
    ss << InOrder(m_root->GetRightChild());
  }
  return ss.str();
}

// void Clear (BSTNode*&), Clear the
// entire contents of the tree,
// freeing all memory associated
// with all nodes.
void BSTree::Clear(BSTNode*& m_root) {
  if (m_root != NULL) {
    Clear(m_root->GetLeftChild());
    Clear(m_root->GetRightChild());
    delete m_root;
    m_root = NULL;
    m_size--;
  }
}

// bool Insert (int, BSTNode*&), Create a new
// BSTNode and insert it into the tree, returns
// true; if integer is already in the true,
// does not insert, returns false.
bool BSTree::Insert(int data_to_insert, BSTNode*& m_root) {
  if (m_root == NULL) {
    m_root = new BSTNode(data_to_insert);
    m_size++;
    return true;
  } else if (data_to_insert < m_root->GetContents()) {
    return Insert(data_to_insert, m_root->GetLeftChild());
  } else if (data_to_insert > m_root->GetContents()) {
    return Insert(data_to_insert, m_root->GetRightChild());
  } else {
    return false;
  }
}

