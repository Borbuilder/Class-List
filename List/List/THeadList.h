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
	    pStop = pHead = pFirst = pLast = pCur = pPrev;
		pos = -1;
		len = 0;
	}

	~THeadList()
	{
		TList<T>::DelList();
		delete pHead;
	}

	void InsLast(const T& _value) { TList<T>::InsLast(_value); }
	void InsFirst(const T& _value)override
	{
		TList<T>::InsFirst(_value);
		pHead->pNext = pFirst;
	}
	void DelFirst()override
	{
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}
};



