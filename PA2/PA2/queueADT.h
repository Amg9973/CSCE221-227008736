#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;  

template <typename T>
struct Node {
	T element;
	Node* next;
};

template <typename T>
class customQueue
{
	public:
		customQueue();
		void push(T x);
		T pop();		
		bool isEmpty();
		//void print();
				
	private:
		Node<T>* head;
		Node<T>* tail;
		int length;
};

template <typename T>
customQueue<T>::customQueue(){
	 head = nullptr;
	 tail = nullptr;
	 length = 0;
}

template <typename T>
void customQueue<T>::push(T x){
	 Node<T>* current = this->head;
	 if (current == nullptr){
		Node<T> n = new Node<T> { x, nullptr };
		current->head = n;
		this->tail = this->head;
	 }
	 else{
		for (int i = 0; i < length - 1; i++){ 
			current = current->next;
		}
		Node<T> n = new Node<T> { x, nullptr };
		current->next = n;
		tail = current->next;
	 }
	 this->length += 1;
}

template <typename T>
T customQueue<T>::pop(){
	 Node<T>* current = *(this->head);
	 this->head = head->next;
	 this->length -= 1;
	 return current;
}

template <typename T>
bool customQueue<T>::isEmpty(){
	return length == 0;
}

//template <typename T>
//void customQueue::print(){
//}

#endif