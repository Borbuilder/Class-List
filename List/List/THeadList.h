#pragma once
#include "TList.h"

template <class T>
class THeadList :public TList<T>
{
protected:
	TNode<T>* pHead;

public:
	THeadList()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pHead; 
		pFirst = pStop;
		pLast = pStop;
		pCur = pStop;
		pPrev = pStop; 
		pos = -1;
		len = 0;
	}

	~THeadList()
	{
		TList<T>::DelList();
		delete pHead;
	}

	THeadList(const THeadList<T>& object)
	{
		TNode<T>* tmp = object.pFirst;
		TNode<T>* current;

		while (tmp != pStop)
		{
			current = new TNode<T>;
			current->value = tmp->value;
			if (pFirst == pStop)
			{
				pFirst = current;
				pLast = current;
			}
			else
			{
				pLast->pNext = current;
				pLast = current;
			}
			tmp = tmp->pNext;
			len++;
		}
		pHead = new TNode<T>;
		pHead->pNext = pFirst;
		len = object.len;
		TList<T>::Reset();
	}

	THeadList<T>& operator=(const THeadList<T>& object)
	{
		if (object.pFirst == pStop)
		{
			TList<T>::DelList();
		}
		else
		{
			//ClearQueue();
			TNode<T>* tmp = object.pFirst, * current;
			while (tmp != pStop)
			{
				current = new TNode<T>;
				current->value = tmp->value;
				if (pFirst == pStop)
				{
					pFirst = current;
					pLast = current;
				}
				else
				{
					pLast->pNext = current;
					pLast = current;
				}
				tmp = tmp->pNext;
			}
			len = object.len;
		    pHead->pNext = pFirst;
		    TList<T>::Reset();
		}
		return *this;
	}

	//void InsLast(const T& _value) { TList<T>::InsLast(_value); }

	virtual void InsFirst(const T& _value)override
	{
		TList<T>::InsFirst(_value);
		pHead->pNext = pFirst;
	}

	virtual void DelFirst()override
	{
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}
};



