#pragma once
#include "TList.h"

template <class T>
class THeadList:public TList<T>
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
	void InsFirst(const T& _value);
	void InsLast(const T& _value) { TList<T>::InsLast(const T& _value); }
	void DelFirst(const T& _value);
};

template<class T>
inline void THeadList<T>::InsFirst(const T& _value)
{
	TList<T>::InsFirst(const T & _value);
	pHead->pNext = pFirst;
}

template<class T>
inline void THeadList<T>::DelFirst(const T& _value)
{
	TList<T>::DelFirst(const T & _value);
	/*
	TNode<T>* tmp = new TNode<T>;
	tmp->value = _value;
	tmp->pNext = pStop;
	pLast->pNext = tmp;
	pLast = tmp;
	*/
	pHead->pNext = pFirst;
}