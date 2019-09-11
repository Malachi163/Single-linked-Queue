#include "Queue.h"

int Queue::getSize() const {
	return size;
}

bool Queue::isEmpty() const {

	return size == 0;

}

char Queue::top() const {

	return head->data;
}

//defintion for default constructor
Queue::Queue()
	:head(0), tail(0), size(0)
{};

void Queue::push(char x)
{
	Node * ptr = new Node(x);

	if (size == 0) //when the queue is empty
	{
		head = ptr;
		tail = ptr;
		size = 1;
	}

	else
	{
		tail->next = ptr;
		tail = ptr;
		size++;
	}
}

//remove the first node int the queue
void Queue::pop()
{
	if (size == 0) // empth queue, nothing to pop
	{
		cout << "Empty queueu, nothing there to remove";
	}

	else if (size == 1)//one node queue
	{
		delete head;
		head = 0;
		tail = 0;
		size = 0;
	}

	else //case 3, two or more nodes int the queue
	{
		Node * ptr = head;
		//it is safe to move to next node
		head = head->next;
		//remove the first node currently pointed by ptr
		delete ptr;
		//anything else
		size--;
	}
}

Queue::~Queue()
{
	for (int i = 0; i < size; i++)
	{
		pop();
	}
}

const Queue & Queue::operator=(Queue right)
{
	swap(head, right.head);
	swap(tail, right.tail);
	swap(size, right.size);
	return *this;
}

Queue::Queue(const Queue & copy)//copy is the reference of the existing object(refers to q1)
{

	this->size = 0;

	Node * ptr = copy.head;

	int N = copy.size;

	for (int i = 0; i < N; i++)

	{

		push(ptr->data);

		ptr = ptr->next;

	}



}