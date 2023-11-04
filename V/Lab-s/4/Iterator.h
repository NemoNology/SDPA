#pragma once

using namespace std;

template <class T> 
class Iterator
{
protected:

	bool IterationComplete;

public:

	Iterator(void);

	virtual void Next(void) = 0;
	virtual void Reset(void) = 0;

	virtual T & Data(void) = 0;
	
	virtual bool EndOfCollection(void) const;
};

template <class T> 
class SeqListIterator : public Iterator
{
private:

	SeqList<T> *listPtr;
	Node<T> *prevPtr, *currPtr;

public:

	SeqListIterator(SeqList<T> * lst) : Iterator(), listPtr(&lst)
	{
		IterationComplete = listPtr->list.ListEmpty();
		Reset();
	}

	void Reset(void)
	{
		IterationComplete = listPtr->list.ListEmpty();
		
		if (listPtr->list.front == NULL)
		{
			return;
		}
		
		prevPtr = NULL;
		currPtr = listPtr->list.front;
	}
	
	void SetList(SeqList<T> & lst)
	{
		listPtr = lst;
		Reset();
	}
	
	T & Data(void)
	{
		if (listPtr->list.ListEmpty() || currPtr == NULL)
		{
			cerr << "Data: invalid link!\n";
			exit(1);
		}
		
		return currPtr->data;
	}
	
	void Next(void)
	{
		if (currPtr == NULL)
		{
			return;
		}
		
		prevPtr = currPtr;
		currPtr = currPtr->NextNode();
		
		if (currPtr == NULL)
		{
			IterationComplete = true;
		}
	}

}