#pragma once

template <class T>
class TNode {
	T value;
	TNode* pNext;
	TNode() { pNext = nullptr; }
};

template <class T>
class TList
{

protected:
	TNode* pFirst, * pLast, * pStop, * pCur, * pPrev;
	int pos, len;

public:

	TList();
	~TList() { DelList(); };
	TList(const TList<T>& list_object);
	void InsFirst(const T& _value);
	void InsLast(const T& _value);
	void DelFirst();
	//void DelLast();
	void InsCurrent(const T& _value);
	void DelCurrent();
	void DelList();
	void SetPos(const int& _pos);
	T GetCurrent() { return pCur->value; };
	
	void Reset();
	void GoNext();
	bool IsEnd();

	bool empty();
	void Push(const T& element); 
	T Pop(); 
	T Front(); 
	T Back();

	TList<T>& operator=(const TList<T>& queue_object);
	void output();
};

template<class T>
inline TList<T>::TList()
{
	pStop = nullptr;
	pFirst = pStop;
	pLast = pStop;
	pLast->pNext = pStop;
	pCur = pFirst;
	pPrev = pStop;
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
		if (pFirst == nullptr)
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
}

template<class T>
inline void TList<T>::InsLast(const T& _value)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = _value;
	tmp->pNext = pStop;
	pLast->pNext = tmp;
	pLast = tmp;
}

template<class T>
inline void TList<T>::InsCurrent(const T& _value)
{
	if (pCur == pFirst)
	{
		InsFirst(_value);
	}
	else
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->value = _value;
		pPrev->pNext = _value;
		tmp->pNext = pCur;
		pPrev = tmp;
		len++;
		pos++;
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
		throw "Trying to delete from empty list in 'DelFirst'"
	}
}

/*template<class T>
inline void TList<T>::DelLast()
{
	if (pLast != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	else
	{
		throw "Trying to delete from empty list"
	}
}*/

template<class T>
inline void TList<T>::DelCurrent()
{
	if (pCur != pStop)
	{
		if (pCur == pFirst) 
		{
			DelFirst();
			pos = 0;
		}
		else
		{   
			TNode<T>* tmp;
			if (pCur == pLast)
			{
				tmp = pCur;
				pCur = pFirst;
				pLast = pPrev;
				//pLast->pNext = pStop;
				pPrev = pStop;
				delete tmp;
				pos = 0;
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
	while (pCur != pStop)
	{
		tmp = pFirst;
		pFirst = pfirst->pNext;
		delete tmp;
	}
}

template<class T>
inline bool TList<T>::empty()
{
	return (pFirst == nullptr);
}

template<class T>
inline void TList<T>::SetPos(const int& _pos)
{
	Reset();
	while (pos < _pos)
	{
		GoNext();
	}
}


template<class T>
inline void TList<T>::Reset()
{
	PCur = pFirst;
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
inline T TList<T>::Pop()
{
	if (empty())
	{
		throw "Queue is empty, you can't pop";
	}

	TNode<T>* tmp = pFirst;
	T result = pFirst->value;
	pFirst = pFirst->pNext;
	delete tmp;
	return result;
}

template<class T>
inline void TList<T>::Push(const T& element)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = element;
	tmp->pNext = nullptr;
	if (empty())
	{
		pFirst = tmp;
		pLast = tmp;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}
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
		for (Reset();!IsEnd;GoNext())
		{
			std::cout << GetCurrent() << " ";
		}
		std::cout << ")" << std::endl;
	}
}