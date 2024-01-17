#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // Make a new Node if there are none present
  if (size_ == 0)
  {
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;
  }
  // If the last index of the tail is full, create a new node to put the value in
  else if (tail_->last == 10) 
  {
    Item* newItem = new Item;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  // Make a new Node if there are none present
  if (size_ == 0)
  {
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;
    head_->last++;
  }
  // If the Node is not empty at the first index, create a new node
  else if (head_->first == 0 && head_->last != 0) 
  {
    Item* newItem = new Item;
    head_->prev = newItem;
    newItem->next = head_;
    head_ = newItem;
    head_->last = 10;
    head_->first = 10;
  }
  if (head_->first != 0) {head_->first--;}
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_back()
{
  // Move the last pointer back of the tail
  tail_->last--;
  // If the Node is Empty, remove the node
  if (tail_->last == tail_->first)
  {
    Item* temp = tail_;
    // If there are more nodes, update pointers
    if (head_ != tail_)
    {
      tail_ = temp->prev;
      tail_->next = nullptr;
    }
    // If this was the only node, then head_ and tail_ -> nullptr
    else
    {
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete temp;
  }
  size_--;
}

void ULListStr::pop_front()
{
  // Move the first pointer forward of the head
  head_->first++;
  // If the Node is Empty, remove the node
  if (head_->last == head_->first)
  {
    Item* temp = head_;
    // If there are more nodes, update pointers
    if (head_ != tail_)
    {
      head_ = temp->next;
      head_->prev = nullptr;
    }
    // If this was the only node, then head_ and tail_ -> nullptr
    else
    {
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete temp;
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  unsigned int iter = head_->first; // Used  to track where in the Node we are
  Item* node = head_; // Used to track which node we are in
  //unsigned int node_tracker = 0; // For Debugging: To make sure we are in the correct node
  for (unsigned int i=0; i < size_; i++)
  {
    if (loc == i)
    {
      return &(node->val[iter]);
    }

    if (iter + 1 != node->last) 
    {
      iter++;
    }
    else
    {
      node = node->next;
      if (node != nullptr) {iter = node->first;}
      //node_tracker++;
    }
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
