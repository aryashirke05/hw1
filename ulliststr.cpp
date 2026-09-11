#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

using namespace std;

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
// push_back function
void ULListStr::push_back(const std::string& val){
  if(head_ == NULL){
    head_ = new Item();
    tail_ = head_;
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;

  } else if(tail_->last < ARRSIZE){
      tail_->val[tail_->last] = val;
      tail_->last++;

  } else {
      Item* newItem = new Item();
      newItem->val[0] = val;
      newItem->first = 0;
      newItem->last = 1;

      newItem->prev = tail_;
      tail_->next = newItem;
      tail_ = newItem;
  }
  size_++;
}

// push_front function
void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    head_ = new Item();
    tail_ = head_;

    head_->val[ARRSIZE - 1] = val;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;

  } else if(head_->first > 0){
      head_->first--;
      head_->val[head_->first] = val;

  } else {
      Item* newItem = new Item();
      newItem->val[ARRSIZE - 1] = val;
      newItem->first = ARRSIZE - 1;
      newItem->last = ARRSIZE;

      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
  }
  size_++;
}

// pop_back function
void ULListStr::pop_back(){
  if(size_ == 0){
    return;
  }
  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    if(tail_ == head_){
      delete tail_;
      head_ = NULL;
      tail_ = NULL;

    } else {
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = NULL;
        delete temp;
    }
  }
}

// pop_front function
void ULListStr::pop_front(){
  if(size_ == 0){
    return;
  }
  head_->first++;
  size_--;

  if(head_->first == head_->last){
    if(head_ == tail_){
      delete head_;
      head_ = NULL;
      tail_ = NULL;

    } else {
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        delete temp;
    }
  }
}

// back function
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last -1];
}

// front function
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

// Get the value at X location function
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return NULL;
  }

  Item* curr = head_;

  while(curr != NULL){
    size_t numItems = curr->last - curr->first;

    if(loc < numItems){
      return &(curr->val[curr->first + loc]);
    }

    loc -= numItems;
    curr = curr->next;
  }
  return NULL;
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
