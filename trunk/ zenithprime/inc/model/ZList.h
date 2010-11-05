#ifndef ZLIST_H
#define ZLIST_H

template <class T>
class ZListNode
{
public:
	ZListNode()
		:next(NULL)
	{}
	ZListNode(T data1)
		:data(data1), next('\0')
	{}
	ZListNode(ZListNode* next1)
		:next(next1)
	{}
	ZListNode(T data1, ZListNode* next1)
		:data(data1), next(next1)
	{}
	T getData(){return data;}
	void setData(T data1){data = data1;}
	ZListNode* getNext(){return next;}
	void setNext(ZListNode* next1){next = next1;}

private:
	ZListNode* next;
	T data;
};

template <class T>
class ZList
{
public:
	ZList()
		:head('\0'), cur('\0'), size(0)
	{}
	ZList(ZList& list)
	{
		head = cur = '\0';
		size = 0;
		ZListNode<T>* temp = list.getHead();
		while (temp != '\0')
		{
			insert(temp->getData());
			temp = temp->getNext();
		}
	}
	~ZList()
	{
		clear();
	}
	
	void insert(T item)
	{
		if (head == '\0')
		{
			head = new ZListNode<T>(item);
			cur = head;
			size++;
		}
		else
		{
			ZListNode<T>* newItem = new ZListNode<T>(item);
			cur->setNext(newItem);
			cur = cur->getNext();
			size++;
		}
	}
	void remove(T item)
	{
		if (head == '\0')
			return;

		ZListNode<T>* temp;
		if (head->getData() == item)
		{
			temp = head->getNext();
			delete head;
			size--;
			head = temp;
			return;
		}
		
		temp = head;
		while (temp->getNext() != '\0')
		{
			if (temp->getNext()->getData() == item)
			{
				ZListNode<T>* temp2 = temp->getNext();
				temp->setNext(temp->getNext()->getNext());
				if (temp2 == cur)
					cur = temp;
				delete temp2;
				size--;
				return;
			}
			temp = temp->getNext();
		}
	}
	ZListNode<T>* find(T item)
	{
		ZListNode<T>* temp = head;
		while (temp != NULL)
		{
			if (item == temp->getData())
				return temp;
			temp = temp->getNext();
		}
		return NULL;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	void clear()
	{
		ZListNode<T>* temp = head;
		
		while (temp != '\0')
		{
			ZListNode<T>* temp2 = temp;
			temp = temp->getNext();
			delete temp2;
		}
		size = 0;
		head = '\0';
		cur = '\0';
	}
	ZListNode<T>* getHead()
	{
		return head;
	}

private:
	ZListNode<T>* head;
	ZListNode<T>* cur;
	int size;
};

#endif