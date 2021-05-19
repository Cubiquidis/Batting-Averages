// Michael Lewis
// CSIS 123
// 0382602
// 12/13/15.
// Final
// Class file

#ifndef STACK
#define STACK

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Stack : public vector < T > 
{
private:
	typename vector<T>::iterator pEnd;
	T getElement(bool erase);
public:
	Stack();
	T pop();
	T peek();
	void push(T elem);
	void erases();
};

template <class T>
Stack<T>::Stack()
{

}

template <class T>
T Stack<T>::getElement(bool erase)
{
	this->pEnd = this->end() - 1;
	T tmp;

	if (this->size() > 0)
	{
		tmp = *pEnd;
		if (erase)
			this->erase(pEnd);
	}
	return tmp;
}

template <class T>
void Stack<T>::push(T elem)
{
	this->push_back(elem);
}

template <class T>
T Stack<T>::pop()
{
	return this->getElement(true);
}

template <class T>
T Stack<T>::peek()
{
	return this->getElement(false);
}

template <class T>
void Stack<T>::erases()
{
	for (int i = 0; i < this->size(); i++)
	{
		this->pop();
	}
}
#endif