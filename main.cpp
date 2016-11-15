#include <iostream>

#include "list.hpp"

int main(){
	mns::list<std::string> emptylist1;
	emptylist1.print_forward();
	emptylist1.push_top("from");
	emptylist1.push_top("hello");
	emptylist1.print_forward();
	emptylist1.push_top("the");
	emptylist1.push_top("other");
	emptylist1.print_backward();

	std::cout << " -- " << std::endl;
	mns::list<std::string> emptylist2;
	emptylist2.print_forward();
	emptylist2.push_bottom("the");
	emptylist2.print_forward();
	emptylist2.print_backward();
	emptylist2.push_bottom("side");
	emptylist2.push_top("other");
	emptylist2.print_backward();
	emptylist2.print_forward();

	std::cout << " -- " << std::endl;

	mns::list<std::string> testlist("other");
	testlist.print_forward();
	std::string popped = testlist.pop_top();
	std::cout << "Popped value: " << popped << std::endl;
	testlist.print_forward();
	testlist.push_bottom("side");
	testlist.print_backward();
	popped = testlist.pop_top();
	std::cout << "Popped value: " << popped << std::endl;
	testlist.print_forward();
	testlist.push_top("other");
	testlist.push_bottom("side");
	testlist.push_top("hello");
	testlist.print_forward();
	testlist.print_backward();

	std::cout << " -- " << std::endl;

	std::cout << "List sizes: " << emptylist1.size() << " " << emptylist2.size() << " " << testlist.size() << std::endl;
	int a = 50, b = 51, c = 52, d = 53;
	mns::list<int *> * intptrlist = new mns::list<int *>();
	intptrlist->push_top(&a);
	intptrlist->push_top(&b);
	intptrlist->push_top(&c);
	intptrlist->push_top(&d);
	std::cout << "List: ";
	for(mns::list<int *>::iterator itr = intptrlist->begin(); itr != intptrlist->end(); itr+=1){
		std::cout << *(*itr) << " ";
	}
	std::cout << std::endl;
	delete intptrlist;

	std::cout << " -- " << std::endl;


	mns::list<int> intlist;
	intlist.push_bottom(4);
	int popped1 = intlist.pop_bottom();
	std::cout << "Popped value: " << popped1 << std::endl;
	intlist.push_bottom(5);
	intlist.push_bottom(6);
	intlist.pop_bottom();
	intlist.pop_bottom();
	intlist.push_top(3);
	intlist.push_top(2);
	intlist.push_top(1);
	intlist.print_forward();
	intlist.print_backward();
	intlist.clear();
	intlist.print_forward();
	intlist.print_backward();
	intlist.push_top(78);
	intlist.push_bottom(79);
	intlist.pop_top();
	intlist.push_top(80);
	intlist.push_bottom(78);
	intlist.print_forward();
	intlist.print_backward();

	std::cout << " -- " << std::endl;

	std::cout << intlist.find_forward(79) << std::endl;
	std::cout << intlist.find_forward(78) << std::endl;
	std::cout << intlist.find_forward(80) << std::endl;
	std::cout << intlist.find_backward(79) << std::endl;
	std::cout << intlist.find_backward(78) << std::endl;
	std::cout << intlist.find_backward(80) << std::endl;

	std::cout << " -- " << std::endl;

	auto node = intlist.peek_top();
	std::cout << "Top element: " << node->getValue() << std::endl;
	node = intlist.peek_bottom();
	std::cout << "Bottom element: " << node->getValue() << std::endl;

	std::cout << " -- " << std::endl;

	intlist.clear();
	node = intlist.peek_top();
	if (node == NULL) std::cout << "No elements... " << std::endl;
	node = intlist.peek_bottom();
	if (node == NULL) std::cout << "No elements... " << std::endl;

	std::cout << " -- " << std::endl;

	intlist.print_forward();
	intlist.print_backward();
	intlist.insert(0,3);
	intlist.insert(1,2);
	intlist.insert(0,1);
	intlist.insert(0,0);
	intlist.print_forward();
	intlist.print_backward();
	intlist.insert(2,10);
	intlist.insert(0,11);
	intlist.insert(intlist.size(),55);
	intlist.print_forward();
	intlist.print_backward();
	intlist.insert_after(3,42);
	intlist.print_forward();
	intlist.print_backward();

	std::cout << " -- " << std::endl;

	intlist.clear();
	intlist.insert(0,1);
	intlist.insert_after(1,2);
	intlist.print_forward();
	intlist.print_backward();
	intlist.insert_before(2,33);
	intlist.insert_before(1,6);
	intlist.print_forward();
	intlist.print_backward();
	intlist.pop_bottom();
	intlist.pop_top();
	intlist.print_forward();
	intlist.print_backward();

	std::cout << " -- " << std::endl;

	intlist.clear();
	intlist.push_top(2);
	intlist.insert_before(2,34);
	intlist.print_forward();
	intlist.print_backward();

	std::cout << " -- " << std::endl;

	intlist.clear();
	intlist.insert(0,1);
	intlist.print_forward();
	intlist.print_backward();
	intlist.insert_after(1,2);
	intlist.print_forward();
	intlist.print_backward();
	intlist.push_bottom(3);
	intlist.print_forward();
	intlist.print_backward();

	std::cout << " -- " << std::endl;

	mns::list<std::string> stringlist;
	stringlist.insert(0,"other");
	stringlist.insert_after("other", "side");
	stringlist.insert(0,"from");
	stringlist.insert_before("other","the");
	stringlist.insert_before("from", "hello");
	stringlist.print_forward();
	stringlist.print_backward();

	std::cout << " -- " << std::endl;

	auto node1 = stringlist.peek_index(0);
	std::cout << "Peeked node: " << node1->getValue() << std::endl;
	auto node2 = stringlist.peek_index(2);
	std::cout << "Peeked node: " << node2->getValue() << std::endl;
	auto node4 = stringlist.peek_index(4);
	std::cout << "Peeked node: " << node4->getValue() << std::endl;

	std::cout << " -- " << std::endl;

	stringlist.remove("hello");
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove("other");
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove("side");
	stringlist.print_forward();
	stringlist.print_backward();

	std::cout << " -- " << std::endl;

	stringlist.push_top("hello");
	stringlist.insert_after("the", "other");
	stringlist.push_bottom("side");
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove_index(1);
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove("hello");
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove_index(1);
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.remove_index(1);
	stringlist.print_forward();
	stringlist.print_backward();

	std::cout << " -- " << std::endl;

	stringlist.push_bottom("side");
	stringlist.print_forward();
	stringlist.print_backward();
	stringlist.insert_after("the", "other");
	stringlist.print_forward();
	stringlist.print_backward();

	return 0;
}
