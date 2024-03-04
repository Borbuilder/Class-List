#pragma once
#include<iostream>
#include <algorithm>

template <class T>
struct TNode {
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};

template <class T>
class TList
{

protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCur, * pPrev;
	int pos, len;
	int SetPos_key = 0; //»спользуетс€ в InsFirst(если не устанавливали pos заранее, то pCur = pFirst)

public:

	TList();
	~TList() { DelList(); };
	TList(const TList<T>& list_object);
	virtual void InsFirst(const T& _value);
	virtual void InsLast(const T& _value);
	virtual void DelFirst();
	virtual void InsCurrent(const T& _value);
	virtual void DelCurrent();
	virtual void DelList();
	void SetPos(const int& _pos);
	T GetCurrentValue() { return pCur->value; };
	T GetLenght() { return len; }
	TNode<T>* GetpCur() { return pCur; }
	T GetPos() { return pos; }

	void Reset();
	void GoNext();
	bool IsEnd();

	bool empty(); 
	T Front(); 
	T Back();
	
	TList<T>& operator=(const TList<T>& object);
	void output();
};


template<class T>
inline TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	//pLast->pNext = pStop;
	pCur = pStop;
	pPrev = pStop;
	//pPrev->pNext = pCur;
	len = 0;
	pos = -1;
}

template<class T>
inline TList<T>::TList(const TList<T>& object)
{
	TNode<T>* tmp = object.pFirst;
	TNode<T>* current;

	while (tmp != nullptr)
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
	pCur = pFirst;
	pos = 0;
	pPrev = pStop;
}

template<class T>
inline void TList<T>::InsFirst(const T& _value)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = _value;
	tmp->pNext = pFirst;
	pFirst = tmp;
	if (len == 0)
	{
		pLast = tmp;
	}
	if (SetPos_key == 0)
	{
		pCur = pFirst;
	}
	len++;
}

template<class T>
inline void TList<T>::InsLast(const T& _value)
{
	if (pFirst == pStop)
	{
		InsFirst(_value);
	}
	else 
	{
		TNode<T>* tmp = new TNode<T>;
	    tmp->value = _value;
	    pLast->pNext = tmp;
	    pLast = tmp;
		tmp->pNext = pStop;
	    len++;
	}
	
}

template<class T>
inline  void TList<T>::InsCurrent(const T& _value) 
{
	if (pCur == pFirst || len == 0)
	{
		InsFirst(_value);
	}
	else
	{
		if (pCur == pStop && pPrev == pLast)
		{
			InsLast(_value);
		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _value;
			pPrev->pNext = tmp;
			tmp->pNext = pCur;
			pPrev = tmp;
			len++;
			pos++;
		}
	}
}

template<class T>
inline void TList<T>::DelFirst()
{
	if (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		pPrev = pStop;
		delete tmp;
		len--;
	}
	else
	{
		throw "Trying to delete from empty list in 'DelFirst'";
	}
}

template<class T>
inline void TList<T>::DelCurrent()
{
	if (pCur != pStop)
	{
		if (pCur == pFirst) 
		{
			DelFirst();
			pCur = pFirst;
			pos = 0;
		}
		else
		{   
			TNode<T>* tmp;
			if (pCur == pLast)
			{
				tmp = pCur;
				pCur = pCur->pNext;
				pLast = pPrev;
				pPrev->pNext = pCur;
				delete tmp;
			}
			else
		    {
			    tmp = pCur;
			    pCur = pCur->pNext;
				pPrev->pNext = pCur;
				delete tmp;
		    }
		}
		len--;
	}
	else
	{
		throw "Trying to delete from empty list in 'DelCurrent'";
	}
}

template<class T>
inline void TList<T>::DelList()
{
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop)
	{
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	len = 0;
	pos = -1;
}

template<class T>
inline bool TList<T>::empty()
{
	return (pFirst == pStop);
}

template<class T>
inline void TList<T>::SetPos(const int& _pos)
{
	SetPos_key = 1;
	if (_pos<0 || pos>len)
	{
		throw "Trying to set the wrong position";
	}
	Reset();
	while (pos < _pos)
	{
		GoNext();
	}
}


template<class T>
inline void TList<T>::Reset()
{
	pCur = pFirst;
	pPrev = pStop;
	pos = 0;
}

template<class T>
inline void TList<T>::GoNext()
{
	if (pCur != pStop)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
		pos++;
	}
	else {
		throw "You can't go next";
	}
}

template<class T>
inline bool TList<T>::IsEnd()
{
	return (pCur==pStop);
}

template<class T>
inline T TList<T>::Front()
{
	if (empty())
	{
		throw "List is empty, you can't get front";
	}
	return pFirst->value;
}

template<class T>
inline T TList<T>::Back()
{
	if (empty())
	{
		throw "List is empty, you can't get back";
	}
	return pLast->value;
}

template<class T>
inline TList<T>& TList<T>::operator=(const TList<T>& object)
{
	if (object.pFirst == pStop)
	{
		DelList();
	}
	else
	{
		DelList();
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
	}
	len = object.len;
	return *this;
}

template<class T>
inline void TList<T>::output()
{
	if (empty())
	{
		std::cout << "(empty)";
	}
	else
	{
		std::cout << "( ";
		for (Reset();!IsEnd();GoNext())
		{
			std::cout << GetCurrentValue() << " ";
		}
		std::cout << ")" << std::endl;
	}
}