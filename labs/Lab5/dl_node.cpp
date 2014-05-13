#include "dl_node.h"

DLNode::DLNode() {
  mp_previous = NULL;
  mp_next = NULL;
  m_contents = 0;
}

DLNode::~DLNode() {
}

void DLNode::SetContents(int in_contents) {
  m_contents = in_contents;
}

void DLNode::SetNext(DLNode* in_next) {
  mp_next = in_next;
}

void DLNode::SetPrevious(DLNode* in_previous) {
  mp_previous = in_previous;
}

int DLNode::GetContents() const {
  return m_contents;
}

DLNode* DLNode::GetNext() const {
  return mp_next;
}

DLNode* DLNode::GetPrevious() const {
  return mp_previous;
}

