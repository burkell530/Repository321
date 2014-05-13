#include "sl_node.h"

// default constructor, sets value next_node_(NULL)
// and contents_ to 0;
SLNode::SLNode() {
  next_node_ = NULL;
  contents_ = 0;
}

// overloaded constructor, parameter is contents
// sets contents parameter to contents_
// sets next_node_ pointer to NULL
SLNode::SLNode(int contents) {
  contents_ = contents;
  next_node_ = NULL;
}

// empty destructor
SLNode::~SLNode() {
}

// function to set contents_ to the incoming parameter
void SLNode::set_contents(int contents) {
  contents_ = contents;
}

// function to return current contents_
int SLNode::contents() const {
  return contents_;
}

// function which gives the name next_node_ to
// the incoming pointer parameter?
void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}

// function which returns next_node_
SLNode* SLNode::next_node() const {
  return next_node_;
}
