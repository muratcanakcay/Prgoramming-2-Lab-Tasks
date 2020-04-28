#include <iostream>
using namespace std;
#include "queue.h"

Queue::Queue(int qs) : qsize(qs)
{
	clients = 0;
	front = rear = nullptr;
}

Queue::~Queue()
{	
	while (front && front->next)
	{
		Node* tmp = front->next;
		front->next = front->next->next;
		delete tmp;
	}
	delete front;
	front = rear = nullptr;
}

bool Queue::enqueue(const Client& client)
{
	if (!isfull())
	{
		Node* newClient = new Node;
		newClient->item = client;
		newClient->next = nullptr;
		
		if (rear)
			rear = rear->next = newClient;
		else
			rear = front = newClient;
		clients++;
		return true;
	}
	else return false;
}

bool Queue::isempty() const
{
	if (!clients) return true;	
	return false;
}

bool Queue::isfull() const
{
	if (clients == qsize) return true;
	return false;
}

bool Queue::dequeue(Client& client)
{
	if (isempty()) return false;

	client.set((front->item).what_time());
	front = front->next;
	if (!front) rear = nullptr;
	clients--;
	return true;
}

ostream& Queue::print(ostream& out) const
{
	out << "Queue:" << endl;
	
	if (isempty())
	{
		out << "Empty queue!" << endl;
		return out;
	}

	Node* current = front;
	for (int i = 0; i < clients; i++)
	{
		out << current->item;
		current = current->next;
	}
	
	return out;
}

ostream& operator<< (ostream& out, const Queue& q)
{
	q.print(out);
	return out;
}

int Queue::size() const
{
	Node* current = front;
	int size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}

	return size;
}