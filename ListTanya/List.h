#pragma once
#include<iostream>
using  std::cout;
using  std::endl;
using std::cin;
template<typename T>
struct Node
{
	T data;
	Node* next, * prev;
	Node(const  T& data = T{}, Node* prev = nullptr, Node* next = nullptr)
		: data(data), prev(prev), next(next)
	{}
};

template<typename T>
class List
{
public:
	List() = default;
	List(const size_t& size, const T value = T())
	{
		for (size_t i = 0; i < size; i++)
		{
			addTail(value);
		}
	}
	void addHead(const T& data);
	void addTail(const T & data);
	void removeHead();
	void removeTail();
	void print() const; // left  to right
	void printR() const; // right to  left
	bool isEmpty() const { return head == nullptr; }
	void insertAfter(const T& data, const T& newData);
	void insertBefore(const T& data, const T& newData);
	void removeByData(const T& data);
	T& operator ()(const T&  data);
private:
	Node <T>* findNode(const T& data);
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t  size = 0;
};

template<typename T>
inline void List<T>::addHead(const T& data)
{
	Node <T>* tmp = new Node<T>(data, nullptr, head); // створили новий вузол
	if (isEmpty())
		tail = tmp;
	else
		head->prev = tmp;
	head = tmp; // призначили головою списку
	++size;
}

template<typename T>
inline void List<T>::addTail(const T& data)
{
	Node <T>* tmp = new Node<T>(data,  tail, nullptr); // створили новий вузол
	if (isEmpty())
		head = tmp;
	else
		tail->next = tmp;
	tail = tmp; // призначили хвіст списку
	++size;
}

template<typename T>
inline void List<T>::removeHead()
{
	if (isEmpty())
		return;
	auto tmp = head; // запамятали старий head
	head = head->next; // змістили head на наступний вузол
	delete tmp; // вилучили старий head
	if (isEmpty())
		tail = nullptr;
	else
		head->prev = nullptr;
	--size;
}

template<typename T>
inline void List<T>::removeTail()
{
	if (isEmpty())
		return;
	auto tmp = tail; // запамятали старий head
	tail = tail->prev; // змістили head на наступний вузол
	delete tmp; // вилучили старий head
	if (isEmpty())
		head = nullptr;
	else
		tail->next = nullptr;
	--size;
}


template<typename T>
inline void List<T>::print() const
{
	if (isEmpty())
	{
		cout << "No list found. Please create it " << endl;
		return;
	}
	auto tmp = head;
	cout << "List in direct :\t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void List<T>::printR() const
{
	if (isEmpty())
	{
		cout << "No list found. Please create it " << endl;
		return;
	}
	auto tmp = tail;
	cout << "List in reverse :\t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline void List<T>::insertAfter(const T& data, const T& newData)
{
	auto find = findNode(data);
	if (find == nullptr) // якщо  шуканого вузла немає
		return;
	if (find == head) {
		addHead(newData);
		return;
	}
	Node <T>* tmp = new Node<T>(newData, find->prev, find);
	find->prev->next = tmp;
	find->prev = tmp;
	size++;
}

template<typename T>
inline void List<T>::insertBefore(const T& data, const T& newData)
{
	auto find = findNode(data);
	if (find == nullptr) // якщо  шуканого вузла немає
		return;
	if (find == tail) {
		addTail(newData);
		return;
	}
	Node <T>* tmp = new Node<T>(newData,  find, find->next);
	find->next->prev = tmp;
	find->next = tmp;
	size++;
}

template<typename T>
inline void List<T>::removeByData(const T& data)
{
	auto find = findNode(data);
	if (find == nullptr) // якщо  шуканого вузла немає
		return;
	//інакше :  вузол знайдено
	if (find == head) {
		removeHead();
		return;
	}
	if (find == tail)
	{
		removeTail();
		return;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;
	delete find;
	--size;
}

template<typename T>
inline T& List<T>::operator()(const T& data)
{
	auto find = findNode(data);
	if (find == nullptr)
		throw std::exception("element not found");
	return find->data;
}

template<typename T>
inline Node<T>* List<T>::findNode(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}



