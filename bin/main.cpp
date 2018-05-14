#include <iostream>

#include "myList.hpp"

struct teststruct{
	int number;
	std::string str;
	teststruct(int _number, std::string _str): number(_number), str(_str){};
	bool operator==(const teststruct& a) const{
		return a.number == number;
	}
};
typedef struct teststruct teststructtype;

int main(){
	mns::List<std::string> emptylist1;
	emptylist1.PrintForward();
	emptylist1.PushTop("from");
	emptylist1.PushTop("hello");
	emptylist1.PrintForward();
	emptylist1.PushTop("the");
	emptylist1.PushTop("other");
	emptylist1.PrintBackward();

	std::cout << " -- " << std::endl;

	mns::List<std::string> emptylist2;
	emptylist2.PrintForward();
	emptylist2.PushBottom("the");
	emptylist2.PrintForward();
	emptylist2.PrintBackward();
	emptylist2.PushBottom("side");
	emptylist2.PushTop("other");
	emptylist2.PrintBackward();
	emptylist2.PrintForward();

	std::cout << " -- " << std::endl;

	mns::List<std::string> testlist("other");
	testlist.PrintForward();
	std::string * popped = testlist.PeekTop();
	std::cout << "Popped value: " << *popped << std::endl;
	testlist.PopTop();
	testlist.PrintForward();
	testlist.PushBottom("side");
	testlist.PrintBackward();
	popped = testlist.PeekTop();
	std::cout << "Popped value: " << *popped << std::endl;
	testlist.PopTop();
	testlist.PrintForward();
	testlist.PushTop("other");
	testlist.PushBottom("side");
	testlist.PushTop("hello");
	testlist.PrintForward();
	testlist.PrintBackward();

	std::cout << " -- " << std::endl;

	std::cout << "List sizes: " << emptylist1.Size() << " " << emptylist2.Size() << " " << testlist.Size() << std::endl;
	int a = 50, b = 51, c = 52, d = 53;
	mns::List<int *> * intptrlist = new mns::List<int *>();
	intptrlist->PushTop(&a);
	intptrlist->PushTop(&b);
	intptrlist->PushTop(&c);
	intptrlist->PushTop(&d);
	std::cout << "List: ";
	for(mns::List<int *>::iterator itr = intptrlist->begin(); itr != intptrlist->end(); itr+=1){
		std::cout << *(*itr) << " ";
	}
	std::cout << std::endl;
	delete intptrlist;

	std::cout << " -- " << std::endl;

	mns::List<int> intlist;
	intlist.PushBottom(4);
	int * popped1 = intlist.PeekBottom();
	std::cout << "Popped value: " << *popped1 << std::endl;
	intlist.PopBottom();
	intlist.PushBottom(5);
	intlist.PushBottom(6);
	intlist.PopBottom();
	intlist.PopBottom();
	intlist.PushTop(3);
	intlist.PushTop(2);
	intlist.PushTop(1);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.Clear();
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.PushTop(78);
	intlist.PushBottom(79);
	intlist.PopTop();
	intlist.PushTop(80);
	intlist.PushBottom(78);
	intlist.PrintForward();
	intlist.PrintBackward();

	std::cout << " -- " << std::endl;

	std::cout << std::distance(intlist.begin(), intlist.FindForward(79)) << std::endl;
	std::cout << std::distance(intlist.begin(), intlist.FindForward(78)) << std::endl;
	std::cout << std::distance(intlist.begin(), intlist.FindForward(80)) << std::endl;
	std::cout << std::distance(intlist.begin(), intlist.FindBackward(79)) << std::endl;
	std::cout << std::distance(intlist.begin(), intlist.FindBackward(78)) << std::endl;
	std::cout << std::distance(intlist.begin(), intlist.FindBackward(80)) << std::endl;

	std::cout << " -- " << std::endl;

	auto node = intlist.PeekTop();
	std::cout << "Top element: " << *node << std::endl;
	node = intlist.PeekBottom();
	std::cout << "Bottom element: " << *node << std::endl;

	std::cout << " -- " << std::endl;

	mns::List<teststructtype> structlist;
	teststructtype struct0(0,"hello1");
	teststructtype struct1(1,"hello2");
	teststructtype struct2(2,"hello3");
	teststructtype struct3(3,"hello4");
	structlist.PushTop(struct0);
	structlist.PushTop(struct3);
	structlist.PushTop(struct1);
	structlist.PushTop(struct2);
	for(mns::List<teststructtype>::iterator itr = structlist.begin(); itr != structlist.end(); itr+=1){
		std::cout << (*itr).number << " ";
	}
	std::cout << std::endl;
	std::cout << std::distance(structlist.begin(), structlist.FindForward(struct1)) << std::endl;
	std::cout << std::distance(structlist.begin(), structlist.FindForward(struct3)) << std::endl;
	std::cout << std::distance(structlist.begin(), structlist.FindForward(struct2)) << std::endl;
	std::cout << std::distance(structlist.begin(), structlist.FindForward(struct0)) << std::endl;

	std::cout << " -- " << std::endl;

	intlist.Clear();
	node = intlist.PeekTop();
	if (node == NULL) std::cout << "No elements... " << std::endl;
	node = intlist.PeekBottom();
	if (node == NULL) std::cout << "No elements... " << std::endl;

	std::cout << " -- " << std::endl;

	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.Insert(0,3);
	intlist.Insert(1,2);
	intlist.Insert(0,1);
	intlist.Insert(0,0);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.Insert(2,10);
	intlist.Insert(0,11);
	intlist.Insert(intlist.Size(),55);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.InsertAfter(3,42);
	intlist.PrintForward();
	intlist.PrintBackward();

	std::cout << " -- " << std::endl;

	intlist.Clear();
	intlist.Insert(0,1);
	intlist.InsertAfter(1,2);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.InsertBefore(2,33);
	intlist.InsertBefore(1,6);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.PopBottom();
	intlist.PopTop();
	intlist.PrintForward();
	intlist.PrintBackward();

	std::cout << " -- " << std::endl;

	intlist.Clear();
	intlist.PushTop(2);
	intlist.InsertBefore(2,34);
	intlist.PrintForward();
	intlist.PrintBackward();

	std::cout << " -- " << std::endl;

	intlist.Clear();
	intlist.Insert(0,1);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.InsertAfter(1,2);
	intlist.PrintForward();
	intlist.PrintBackward();
	intlist.PushBottom(3);
	intlist.PrintForward();
	intlist.PrintBackward();

	std::cout << " -- " << std::endl;

	mns::List<std::string> stringlist;
	stringlist.Insert(0,"other");
	stringlist.InsertAfter("other", "side");
	stringlist.Insert(0,"from");
	stringlist.InsertBefore("other","the");
	stringlist.InsertBefore("from", "hello");
	stringlist.PrintForward();
	stringlist.PrintBackward();

	std::cout << " -- " << std::endl;

	auto node1 = stringlist.PeekIndex(0);
	std::cout << "Peeked node: " << *node1 << std::endl;
	auto node2 = stringlist.PeekIndex(2);
	std::cout << "Peeked node: " << *node2 << std::endl;
	auto node4 = stringlist.PeekIndex(4);
	std::cout << "Peeked node: " << *node4 << std::endl;

	std::cout << " -- " << std::endl;

	stringlist.Remove("hello");
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.Remove("other");
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.Remove("side");
	stringlist.PrintForward();
	stringlist.PrintBackward();

	std::cout << " -- " << std::endl;

	stringlist.PushTop("hello");
	stringlist.InsertAfter("the", "other");
	stringlist.PushBottom("side");
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.RemoveIndex(1);
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.Remove("hello");
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.RemoveIndex(1);
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.RemoveIndex(1);
	stringlist.PrintForward();
	stringlist.PrintBackward();

	std::cout << " -- " << std::endl;

	stringlist.PushBottom("side");
	stringlist.PrintForward();
	stringlist.PrintBackward();
	stringlist.InsertAfter("the", "other");
	stringlist.PrintForward();
	stringlist.PrintBackward();

	std::cout << " -- " << std::endl;

	intlist.Clear();
	intlist.PrintForward();
	intlist.PushTop(2);
	intlist.PushTop(4);
	intlist.PushTop(5);
	intlist.PushTop(29);
	intlist.PushTop(12);
	intlist.PrintForward();
	*intlist.PeekTop() -= *intlist.PeekBottom();
	intlist.PrintForward();
	
	auto elem = intlist.FindForward(10);
	/* delete *elem */
	intlist.Remove(10);
	intlist.PrintForward();

	std::cout << std::endl;
	return 0;
}
