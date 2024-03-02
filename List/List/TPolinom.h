#pragma once
#include "THeadList.h"
#include "Monom.h"
#include<vector>

class TPolinom:public THeadList<Monom>
{
private:
	std::vector<Monom> arr_monom;

public:

	//TPolinom() 
	//{
		//Monom HeadMonom;
		//pHead->value = HeadMonom;
	//}

	void createMomomVector(const std::string& str);          //Создание вектора полиномов на основе входящей строки

	void createPolinom();

	void addMonom( Monom& _monom);

	void vectorOutput()
	{   
		std::cout << "( ";
		for (int i = 0; i < arr_monom.size(); i++)
		{
			arr_monom[i].outputMonomFields();
			std::cout << " ";
		}
		std::cout << " )";
	}
};

