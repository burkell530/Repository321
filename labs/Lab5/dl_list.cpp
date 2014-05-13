#include "dl_list.h"

DLList::DLList() {
  mp_head = NULL;
  mp_tail = NULL;
  m_size = 0;
}

DLList::~DLList() {
  Clear();
}

int DLList::GetSize() const {
  return m_size;
}

void DLList::PushFront(int in_add_to_list) {
  DLNode* current = new DLNode;
  int new_contents = in_add_to_list;
  current->SetContents(new_contents);
  if (mp_head == NULL) {
    mp_head = current;
    mp_tail = current;
  } else {
    current->SetNext(mp_head);
    mp_head->SetPrevious(current);
    mp_head = current;
  }
  m_size++;
}

void DLList::PushBack(int in_add_to_List) {
  DLNode* current = new DLNode;
  int new_contents = in_add_to_List;
  current->SetContents(new_contents);
  if (mp_head == NULL) {
    mp_head = current;
    mp_tail = current;
  } else {
    current->SetPrevious(mp_tail);
    mp_tail->SetNext(current);
    mp_tail = current;
  }
  m_size++;
}

int DLList::GetFront() const {
  if (mp_head == NULL) {
    cerr << "List Empty";
    return 0;
  } else {
  return mp_head->GetContents();
  }
}

int DLList::GetBack() const {
  if (mp_tail == NULL) {
    cerr << "List Empty";
    return 0;
  } else {
  return mp_tail->GetContents();
  }
}

void DLList::PopFront() {
  if (mp_head == NULL) {
    cerr << "List Empty";
  } else if (mp_head == mp_tail) {
    delete mp_head;
    mp_head = NULL;
    mp_tail = NULL;
    m_size--;
  } else {
  mp_head = mp_head->GetNext();
  delete mp_head->GetPrevious();
  mp_head->SetPrevious(NULL);
  m_size--;
  }
}

void DLList::PopBack() {
  if (mp_head == NULL) {
    cerr << "List Empty";
  } else if (mp_head == mp_tail) {
    delete mp_head;
    mp_head = NULL;
    mp_tail = NULL;
    m_size--;
  } else {
    mp_tail = mp_tail->GetPrevious();
    delete mp_tail->GetNext();
    mp_tail->SetNext(NULL);
    m_size--;
  }
}

void DLList::RemoveFirst(int in_value_to_find) {
  for (DLNode* i = mp_head; i != NULL; i = i->GetNext()) {
    if (i->GetContents() == in_value_to_find) {
      RemoveNode(i);
      return;
    }
  }
  cerr << "Not Found";
}

void DLList::RemoveAll(int in_value_to_add) {
  bool found = false;
  for (DLNode* i = mp_head; i != NULL; i = i->GetNext()) {
      if (i->GetContents() == in_value_to_add) {
        found = true;
        RemoveNode(i);
      }
    }
    if (found == false) {
      cerr << "Not Found";
  }
}

bool DLList::Exists(int value_to_find) {
  for (DLNode* i = mp_head; i != NULL; i = i->GetNext()) {
    if (i->GetContents() == value_to_find) {
      return true;
    }
  }
  return false;
}

  // Member function #11. Named Clear.
  // Clears all nodes from the list,
  // resets size to 0 and head and
  // tail to NULL.
void DLList::Clear() {
  if (mp_head == NULL) {
    cerr << "List Empty" << endl;
  }
  while (mp_head != NULL) {
    PopFront();
  }
}

string DLList::ToStringForwards() {
  stringstream ss;
  if (mp_head == NULL) {
    cerr << "List Empty";
    return "";
  } else {
    for (DLNode* i = mp_head; i != NULL; i = i->GetNext()) {
      ss << i->GetContents();
      if (i->GetNext() != NULL) {
        ss << ", ";
      }
    }
  }
  return ss.str();
}

string DLList::ToStringBackwards() {
  stringstream ss;
  if (mp_tail == NULL) {
    cerr << "List Empty";
    return "";
  } else {
    for (DLNode* i = mp_tail; i != NULL; i = i->GetPrevious()) {
      ss << i->GetContents();
      if (i->GetPrevious() != NULL) {
        ss << ", ";
      }
    }
  }
  return ss.str();
}

// Private member function #1. Named
// RemoveNode. Takes a DLNode* pointer
// parameter. Checks to see if there
// is no node, and if there is,
// removes the node and resets the
// pointers as needed. Does not return
// anything. After deleting a node,
// decrements size.
void DLList::RemoveNode(DLNode* node_to_remove) {
  if (mp_head == NULL) {
    cerr << "List Empty";
  } else if (mp_head == mp_tail) {
    delete mp_head;
    mp_head = NULL;
    mp_tail = NULL;
    m_size--;
  } else {
    DLNode* A = node_to_remove->GetPrevious();
    DLNode* C = node_to_remove->GetNext();
    if (A != NULL) {
      A->SetNext(C);
    }
    if (C != NULL) {
      C->SetPrevious(A);
    }
    if (mp_head == node_to_remove) {
      mp_head = mp_head->GetNext();
    }
    if (mp_tail == node_to_remove) {
      mp_tail = mp_tail->GetPrevious();
    }
    delete node_to_remove;
    m_size--;
  }
}

