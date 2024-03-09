#pragma once
#include<iostream>
#include<cmath>
#include<string>

class Monom
{
protected:

	int coef;
	int index;

public:

	Monom() 
	{
		coef = 0;
		index = -1;
	}

	Monom(const int& _coef,const int& _index)
	{
		coef = _coef;
		index = _index;
	}

	Monom(const Monom& other)
	{
		coef = other.coef;
		index = other.index;
	}

	Monom operator=(const Monom& other)
	{
		coef = other.coef;
		index = other.index;
		return *this;
	}

	void createMonom(const int& _coef, const int& x_deg, const int y_deg, const int z_deg)  //»нициализаци€ полей монома, переменные передаютс€ из метода создани€ полинома
	{
		coef = _coef;
		index = 100 * x_deg + 10 * y_deg + z_deg;
	}

	bool operator==(const Monom& other)
	{
		return (std::abs(coef) == std::abs(other.coef) && index == other.index);
	}

	bool operator!=(const Monom& other)
	{
		return !(*this == other);
	}
	
	bool operator<(const Monom& other)
	{
		if (index < other.index )
		{
			return true;
		}
		else
		{
			if (index == other.index)
			{
				return std::abs(coef) < (other.coef);
			}
			else
			{
				return false;
			}
		}
	}

	bool operator>(const Monom& other)
	{
		if (*this < other || *this == other)
		{
			return false;
		}
		else {
			return true;
		}
	}

	void outputMonomFields()
	{
		std::cout << "(" << coef << "," << index << ")";
	}

	int getIndex() { return index; }

	void setIndex(const int& _index) { index = _index; }

	int getCoef() { return coef; }

	void setCoef(const int& _coef) { coef = _coef; }

	std::string monomToString() 
	{
		std::string str;
		std::string str_coef;
		if (coef == 1)
		{
			str_coef = "";
		}
		else {
			str_coef=std::to_string(coef);
		}
		std::string str_deg_x = std::to_string(index/100);
		std::string str_deg_y = std::to_string((index / 10)%10);
		std::string str_deg_z = std::to_string(index % 10);

		str = str_coef + "x^" + str_deg_x + "y^" + str_deg_y + "z^" + str_deg_z;
		return str;
	}

	friend std::istream& operator>>(std::istream& cin, Monom& monom) 
	{
		std::cout << "¬вод монома:" << std::endl << "¬ведите коэффициент:" << std::endl;
		cin >> monom.coef;
		std::cout << "¬ведите индекс монома:" << std::endl;
		cin>> monom.index;
		return cin;
	}

	friend std::ostream& operator<<(std::ostream& cout, const Monom& monom) 
	{
		cout << "(" << monom.coef << "," << monom.index << ")";
		return cout;
	}
};


