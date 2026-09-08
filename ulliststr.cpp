#include <cstddef>
#include <stdexcept>
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

void ULListStr::push_back(const std::string& val){
  if(tail_ == NULL){
    tail_ = head_ = new Item();
  } else{
    if(tail_->last == ARRSIZE){
      Item* temp = new Item();
      tail_->next = temp;
      temp->prev = tail_;
      tail_ = temp;
    }
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_ || head_ == NULL) {
    return NULL;
  }
  Item* temp_ = head_;
  size_t runningTotal = (temp_->last -  temp_->first);
  while ((runningTotal) <= loc){
    temp_ = temp_->next;
    runningTotal += (temp_->last -  temp_->first);
  }

    runningTotal -= loc;

    return &(temp_->val[temp_->last - runningTotal]);
}

string const & ULListStr::back() const{
  if (tail_ == NULL) {
    throw runtime_error("No Valid Back");
  } else {
    return tail_->val[(tail_->last - 1)];
  }
}

string const & ULListStr::front() const{
  if (head_ == NULL) {
    throw runtime_error("No Valid Front");
  } else {
    return head_->val[(head_->first)];
  }
}

void ULListStr::push_front(const std::string& val){
  if (head_ == NULL) {
    head_ = tail_ = new Item();
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }else {
    if (head_->first == 0) {
      Item* temp = new Item();
      temp->first = ARRSIZE;
      temp->last = ARRSIZE;
      head_->prev = temp;
      temp->next = head_;
      head_ = temp;
    }
  }

  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_back(){
  if(tail_ == NULL){
    return;
  } else{
    if((tail_->last - tail_->first) == 1){
      tail_->val[(tail_->last - 1)]  = "";
      if(tail_->prev != NULL){
        Item* temp = tail_->prev;
        delete tail_;
        tail_ = temp;
        tail_->next = NULL;
      } else{
        delete tail_;
        head_ = tail_ = NULL;
      }
    } else{
      tail_->val[(tail_->last - 1)]  = "";
      tail_->last--;
    }
  }

  size_--;
}

void ULListStr::pop_front(){
  if(head_ == NULL){
    return;
  } else{
    if((head_->last - head_->first) == 1){
      head_->val[(head_->first)]  = "";
      if(head_->next != NULL){
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
        head_->prev = NULL;
      } else{
        delete head_;
        head_ = tail_ = NULL;
      }
    } else{
      head_->val[(head_->first)]  = "";
      head_->first++;
    }
  }

  size_--;
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
