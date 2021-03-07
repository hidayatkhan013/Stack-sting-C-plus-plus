#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
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

void ULListStr::push_back(const std::string& val)
{
	
	if (empty()) {
		// is val is empty 
		Item* temp = new Item();
		tail_ = temp;
		head_ = temp;
		temp->val[0] = val;
		temp->last++;
	}
	else if (tail_->last == ARRSIZE) {
		// if tail reached the pre defined size that is 10
		Item* temp = new Item();
		temp->prev = tail_;
		tail_->next = temp;
		tail_ = temp;
		temp->val[0] = val;
		temp->last++;
	}
	else {
		// if there is space in tail
		tail_->val[tail_->last] = val;
		tail_->last++;
	}

	size_++;
}

void ULListStr::pop_back()
{
	//checking if list is empty
	if (empty()) return; 
	if (size_ == 1) {
		//list has only one element
		delete tail_;
		tail_ = NULL;
		head_ = NULL;
	}
	else if (tail_->last == 1) { 
		//item has only one element
		tail_ = tail_->prev;
		delete tail_->next;
		tail_->next = NULL;
	}
	else {
		//item has more than 1 elements
		tail_->last--;
	}
	size_--;
}

void ULListStr::push_front(const std::string& val)
{
	if (empty()) {
		// if no item present in list
		Item* it = new Item();
		head_ = it;
		tail_ = it;
		it->val[0] = val;
		it->last++;
	}
	else if (head_->first == 0) {
		// if head is full
		Item* it = new Item();
		head_->prev = it;
		it->next = head_;
		head_ = it;
		it->val[ARRSIZE - 1] = val;
		it->last = ARRSIZE;
		it->first = ARRSIZE - 1;
	}
	else { 
		// if there is space in head
		head_->val[head_->first - 1] = val;
		head_->first--;
	}
	size_++;
}

void ULListStr::pop_front()
{
	//checking if list is empty then nothing to pop
	if (empty()) return; 
	if (size_ == 1) {
		//checking if list has only one element
		Item* temp = head_;
		delete temp;
		tail_ = NULL;
		head_ = NULL;
	}
	else if (head_->first == ARRSIZE - 1) { 
		//checking item has only one element 
		head_ = head_->next;
		delete head_->prev;
		head_->prev = NULL;
	}
	else { 
		//checking if item has more than one elements
		head_->first++;
	}
	size_--;
}

std::string const& ULListStr::back() const
{
	// TODO: insert return statement here
	// return value at back
	return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const
{
	// TODO: insert return statement here
	// return value at front
	return head_->val[head_->first];
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

string& ULListStr::get(size_t loc)
{
  string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw invalid_argument("Bad location");
  }
  return *ptr;
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
	// checking if loc is invalid 
	if (loc < 0 || loc >= size_) return NULL;
	// to get right value we have to store index itrator (it will help to reach the correct index) and present index to return value
	size_t index_itrator = 0;
	size_t index_current = head_->first;
	// new item pointer to itrate over the list
	Item * temp = head_;
	// search for loc untill its not found
	while (index_itrator != loc) {
		index_itrator++;
		index_current++;
		// when one node capacity is reached than search in next node
		if (index_current == temp->last) {
			temp = temp->next;
			index_current = 0;
		}
	}
	// return  value of node when itrator reach to use enterd index
	return &temp->val[index_current];
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
