
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stack>
#include <string>
#include <cctype>


using namespace std;

struct Node {

	char data;
	Node * next;

	Node(char c = 'a', Node * nptr = 0)
		: data(c), next(nptr)
	{};

};

class Queue {
public:
	//default constructor
	Queue();

	//copy constructor, do not forget the '&'
	//you must use passing by reference otherwise infinite recursion
	Queue(const Queue & copy);

	//destructor
	~Queue();

	//overload assigment operator
	const Queue & operator = (Queue right);

	void push(char x);
	void pop();

	int getSize() const;

	bool isEmpty() const;
	char top() const;

private:
	Node * head;
	Node * tail;
	int size;
};



#endif