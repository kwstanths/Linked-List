#include <iostream>

#include "list.hpp"

int main(){
	mns::list<std::string> emptylist1;
	emptylist1.print();
	emptylist1.push_top("from");
	emptylist1.push_top("hello");
	emptylist1.print();

	mns::list<std::string> emptylist2;
	emptylist2.print();
	emptylist2.push_bottom("the");
	emptylist2.print();

	mns::list<std::string> testlist("other");
	std::string popped = testlist.pop_top();
	std::cout << "Popped value: " << popped << std::endl;
	testlist.print();
	testlist.push_bottom("side");
	testlist.print();
	popped = testlist.pop_top();
	testlist.print();

	std::cout << "List sizes: " << emptylist1.size() << " " << emptylist2.size() << " " << testlist.size() << std::endl;

	int a = 50, b = 51, c = 52, d = 53;
	mns::list<int *> * intptrlist = new mns::list<int *>();
	intptrlist->push_top(&a);
	intptrlist->push_top(&b);
	intptrlist->push_top(&c);
	intptrlist->push_top(&d);
	std::cout << "List: ";
	for(mns::list<int *>::iterator itr = intptrlist->begin(); itr != intptrlist->end(); itr+=2){
		std::cout << *(*itr) << " ";
	}
	std::cout << std::endl;
	delete intptrlist;


	mns::list<int> intlist;
	intlist.push_bottom(4);
	intlist.pop_bottom();
	intlist.push_bottom(5);
	intlist.push_bottom(6);
	intlist.pop_bottom();
	intlist.pop_bottom();
	intlist.push_top(3);
	intlist.push_top(2);
	intlist.push_top(1);
	intlist.print();
	intlist.clear();
	intlist.print();
	intlist.push_top(78);
	intlist.push_bottom(79);
	intlist.pop_top();
	intlist.push_top(80);
	intlist.push_bottom(78);
	intlist.print();
	std::cout << intlist.find(79) << std::endl;

	auto node = intlist.peek_top();
	std::cout << "Top element: " << node->getValue() << std::endl;
	node = intlist.peek_bottom();
	std::cout << "Bottom element: " << node->getValue() << std::endl;

	intlist.clear();
	node = intlist.peek_top();
	if (node == NULL) std::cout << "No elements... " << std::endl;
	node = intlist.peek_bottom();
	if (node == NULL) std::cout << "No elements... " << std::endl;


	intlist.insert(0,3);
	intlist.insert(0,2);
	intlist.insert(0,1);
	intlist.insert(0,0);
	intlist.print();
	intlist.insert(2,10);
	intlist.print();
	intlist.insert_after(3,15);
	intlist.print();

	intlist.clear();
	intlist.insert(0,1);
	intlist.insert_after(1,2);
	intlist.print();
	intlist.insert_before(2,33);
	intlist.print();

	intlist.clear();
	intlist.push_top(2);
	intlist.insert_before(2,34);
	intlist.print();

	intlist.clear();
	intlist.insert(0,1);
	intlist.print();
	intlist.insert_after(1,2);
	intlist.print();
	intlist.push_bottom(3);
	intlist.print();

	mns::list<std::string> stringlist;
	stringlist.insert(0,"other");
	stringlist.insert_after("other", "side");
	stringlist.insert(0,"from");
	stringlist.insert_before("other","the");
	stringlist.insert_before("from", "hello");
	stringlist.print();

	auto node1 = stringlist.peek_index(0);
	std::cout << "Peeked node:" << node1->getValue() << std::endl;
	auto node2 = stringlist.peek_index(2);
	std::cout << "Peeked node:" << node2->getValue() << std::endl;
	auto node4 = stringlist.peek_index(4);
	std::cout << "Peeked node:" << node4->getValue() << std::endl;

	stringlist.remove("hello");
	stringlist.print();
	stringlist.remove("other");
	stringlist.print();
	stringlist.remove_index(1);
	stringlist.print();
	stringlist.remove("hello");
	stringlist.print();
	stringlist.remove_index(1);
	stringlist.print();

	stringlist.push_bottom("side");
	stringlist.insert_after("the", "other");
	stringlist.print();



	return 0;
}
