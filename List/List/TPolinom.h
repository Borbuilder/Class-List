#pragma once
#include "THeadList.h"
#include "Monom.h"
#include<vector>

class TPolinom:public THeadList<Monom>
{
public:
    std::vector<Monom> arr_monom;

	TPolinom() 
	{
		Monom HeadMonom;
		pHead->value = HeadMonom;
	}

	void createPolinom(const std::string& str);          //Создание вектора полиномов на основе входящей строки

	void createPolinomOnVector(std::vector<Monom>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			addMonom(v[i]);
		}
	}

	void addMonom(Monom& _monom);

	void vectorOutput()
	{   
		std::cout << "( ";
		for (int i = 0; i < arr_monom.size(); i++)
		{
			arr_monom[i].outputMonomFields();
			std::cout << " ";
		}
		std::cout << ")" << std::endl;
	}

	TPolinom& operator =( TPolinom& q)
	{
		if (this->GetLenght() != 0)
		{
			DelList();
		}
		
		Monom h(0,-1);
		pHead->value = h;
		for (q.Reset(); !q.IsEnd(); q.GoNext())
		{
			Monom monom = q.pCur->value;
			InsLast(monom);
		}
		return *this;
	}

	bool operator==(TPolinom& other)
	{
		if (this->GetLenght() != other.GetLenght())
		{
			return false;
		}
		else {
			this->Reset();
			other.Reset();
			while (!IsEnd())
			{
				if (this->pCur->value != other.pCur->value)
				{
					return false;
				}
				GoNext();
			}
		}
		return true;
	}

	TPolinom operator+( TPolinom& _other);

	TPolinom operator+=(TPolinom& _other);

	TPolinom operator*(const int num);

	TPolinom operator-(TPolinom& _other);

	TPolinom operator*(TPolinom& other);

	std::string polinomToString()
	{
		std::string p_str;
		for (Reset(); !IsEnd(); GoNext())
		{
			if ( (this->GetPos()!=0) && (pCur->value.getCoef() > 0))
			{
				p_str += "+";
			}
			p_str += pCur->value.monomToString();
		}
		return p_str;
	}
};

