#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>

namespace mns{
	template <typename T> class list;

	template <typename T> class list_iterator;

	template <typename T> class list_node{
		friend class list<T>;
		friend class list_iterator<T>;
		private:
			list_node(const T& _value, list_node<T> * _next): value(_value), next(_next){ }
			T value;
			list_node<T> * next;
		public:
			T getValue(){
				return value;
			}
	};

	template <class T> class list{
	private:
		list_node<T> * top, * bot;

	public:
		/*
			list's iterator
		*/
		typedef list_iterator<T> iterator;

		/*
			Default constructor. Initializes an empty list
		*/
		list(): top(NULL), bot(NULL){ }

		/*
			Initializes a list with a single element
		*/
		list(T _value){
			list_node<T> * new_node = new list_node<T>(_value,NULL);
			top = new_node;
			bot = new_node;
		}

		/*
			Destroys the list
		*/
		~list(){
			clear();
		}

		/*
			Returns if the list is empty
			@return true if empty, false if not
		*/
		bool empty(){
			return ((top == NULL) || (bot == NULL));
		}

		/*
			Returns the size of the list
			@return the size of the list
		*/
		int size(){
			list_node<T> * temp_node = top;
			int sum = 0;
			while(temp_node != NULL){
				sum++;
				temp_node = temp_node->next;
			}
			return sum;
		}

		/*
			Removes every element in the list
		*/
		void clear(){
			list_node<T> * temp_node;
			while(top != NULL){
				temp_node = top;
				top = top->next;
				delete temp_node;
			}
			top = bot = NULL;
		}

		/*
			Searches in the list to find _value
			@parapm _value the element to find
			@return index of the element if found, otherwise -1
		*/
		int find(T _value){
			if (empty()) return -1;
			int index = 0;
			list_node<T> * temp_node = top;
			do{
				if (temp_node->value == _value) return index;
				temp_node = temp_node->next;
				index++;
			}while(temp_node != NULL);

			return -1;
		}

		/*
			Inserts at the top of the list
			@param _value the element to insert
		*/
		void push_top(T _value){
			list_node<T> * new_node = new list_node<T>(_value,top);
			top = new_node;
			if (bot == NULL) bot = new_node;
		}

		/*
			Inserts at the bottom of the list
			@param _value the element to insert
		*/
		void push_bottom(T _value){
			list_node<T> * new_node = new list_node<T>(_value,NULL);
			if (top == NULL) {
				top = new_node;
				bot = new_node;
				return;
			}
			bot->next = new_node;
			bot = new_node;
			return;
		}

		/*
			Removes an element from the top of the list
			@return the value removed
		*/
		T pop_top(){
			if (empty()) return T();

			list_node<T> * temp_node = top;
			T temp_value = temp_node->value;
			top = top->next;
			if (top == NULL) bot = NULL;
			delete temp_node;
			return temp_value;

		}

		/*
			Removes an element from the bottom of the list
			@return the value removed
		*/
		T pop_bottom(){
			if (empty()) return T();

			if (top == bot){
				list_node<T> * temp_node = top;
				T temp_value = temp_node->value;
				delete temp_node;
				top = bot = NULL;
				return temp_value;
			}

			list_node<T> * current, * previous;
			previous = top;
			current = top->next;
			while(current->next != NULL){
				previous = current;
				current = current->next;
			}
			list_node<T> * temp_node = current;
			previous->next = NULL;
			bot = previous;
			T temp_value = temp_node->value;
			delete temp_node;
			return temp_value;
		}

		/*
			Inserts an element in the list at a certain index
			@param position the index to insert the element
			@param _value the element to insert
			@return true if inserted, false if not
		*/
		bool insert(int _position, T _value){
			if (empty() && _position != 0) return false;

			if (_position == 0) {
				push_top(_value);
				return true;
			}
			int index = 1;
			list_node<T> * previous, * current;
			previous = top;
			current = top->next;
			while((index < _position) && (current != NULL)){
				index++;
				previous = current;
				current = current->next;
			}
			if((current == NULL) && (index < _position)) return false;
			if((current == NULL) && (index == _position)) {
				push_bottom(_value);
				return true;
			}
			if((current != NULL) && (index == _position)){
				list_node<T> * temp_node = new list_node<T>(_value,current);
				previous->next = temp_node;
				return true;
			}

		}

		/*
			Inserts an element in the list after a specific value
			@param _previous_value the value after of which the elemen will be inserted
			@param _value the element to insert
			@return true if inserted, false if not
		*/
		bool insert_after(T _previous_value, T _value){
			if (empty()) return false;

			if (bot->value  == _previous_value) {
				push_bottom(_value);
				return true;
			}
			list_node<T> * previous, * current, * temp_node;
			previous = top;
			current = top->next;
			while(current != NULL){
				if (previous->value == _previous_value) {
					temp_node = new list_node<T>(_value, current);
					previous->next = temp_node;
					return true;
				};
				previous = current;
				current = current->next;
			}

			if (previous->value == _previous_value) push_bottom(_value);
			return false;
		}

		/*
			Insert an element in the list before a specific value
			@param _next_value the value before of which the elemened will be inserted
			@param _value the element to insert
			@return true if inserted, false if not
		*/
		bool insert_before(T _next_value, T _value){
			if (empty()) return false;

			if (top->value == _next_value) {
				push_top(_value);
				return true;
			}
			list_node<T> * previous, * current, * temp_node;
			previous = top;
			current = top->next;
			while(current != NULL){
				if (current->value == _next_value){
					temp_node = new list_node<T>(_value,current);
					previous->next = temp_node;
					return true;
				}
				previous = current;
				current = current->next;
			}

			return false;
		}

		/*
			Remove an element from the list_node
			@param _value the element to remove
			@return true if removed, false if not
		*/
		bool remove(T _value){
			if (empty()) return false;

			if (top->value == _value) {
				pop_top();
				return true;
			}
			if (bot->value == _value){
				pop_bottom();
				return true;
			}

			list_node<T> * previous, * current, * temp_node;
			previous = top;
			current = top->next;
			while(current != NULL){
				if (current->value == _value){
					temp_node = current;
					previous->next = current->next;
					delete temp_node;
					return true;
				}
				previous = current;
				current = current->next;
			}

			return false;
		}

		/*

		*/
		bool remove_index(int _index){
			if (empty()) return false;

			if (_index == 0) {
				pop_top();
				return false;
			}

			list_node<T> * current, * previous, * temp_node;
			int i = 1;
			previous = top;
			current = top->next;
			while(current != NULL && i < _index){
				previous = current;
				current = current->next;
				i++;
			}

			if (current == NULL) return false;

			temp_node = current;
			previous->next = current->next;
			delete temp_node;
			if (current->next == NULL) {
				bot = previous;
			}
			return true;
		}

		/*
			Get the iterator start
		*/
		iterator begin() {
			return list_iterator<T>(top);
		}

		/*
			Get the iterator end
		*/
		iterator end(){
			return list_iterator<T>(NULL);
		}

		/*
			Returns a pointer the top node
		*/
		auto peek_top() -> list_node<T> *{
			return top;
		}

		/*
			Returns a pointer to the last node
		*/
		auto peek_bottom() ->list_node<T> *{
			return bot;
		}

		/*
			Returns a pointer to the index or NULL
		*/
		auto peek_index(int _index) -> list_node<T> * {

			if (empty()) return NULL;

			if (_index == 0) return top;

			list_node<T> * current, * previous;
			int i = 1;
			previous = top;
			current = top->next;
			while(current != NULL && i < _index){
				previous = current;
				current = current->next;
				i++;
			}
			return current;
		}

		/*
			Prints the elements in the list
		*/
		void print(){
			list_node<T> * temp = top;
			std::cout << "List: ";
			while(temp != NULL){
				std::cout << temp->value << " " ;
				temp = temp->next;
			}
			std::cout << std::endl;
		}

	};

	template <typename T> class list_iterator : public std::iterator<std::forward_iterator_tag, T>{
		friend class list<T>;
	private:
		list_node<T> *pointed;
		list_iterator(list_node<T> * _pointed): pointed(_pointed){ }

	public:
		T& operator*(){
			return pointed->value;
		}

		const list_iterator<T>& operator++(){
			pointed = pointed->next;
			return *this;
		}

		const list_iterator<T>& operator+=(int amount){
			int i = 0;
			while(i++ < amount) {
				pointed = pointed->next;
			}
		}

		bool operator!=(const list_iterator<T>& other) const {
			return this->pointed != other.pointed;
		}

	};
}
#endif
