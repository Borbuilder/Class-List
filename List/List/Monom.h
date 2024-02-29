#pragma once
#include<iostream>

class Monom
{
private:

	double coef;
	int index;

public:

	Monom() 
	{
		coef = -1;
		index = 0;
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
		return (coef == other.coef && index == other.index);
	}

	bool operator!=(const Monom& other)
	{
		return !(*this == other);
	}
	
	bool operator<(const Monom& other)
	{
		if (index < other.index)
		{
			return true;
		}
		else
		{
			if (index == other.index)
			{
				return coef < other.coef;
			}
			else
			{
				return false;
			}
		}
	}

	bool operator>(const Monom& other)
	{
		return !(*this < other);
	}

	friend std::istream& operator>>(std::istream& cin, Monom& monom) 
	{
		std::cout << "¬вод монома:" << std::endl << "¬ведите коэффициент:" << std::endl;
		cin >> monom.coef;
		std::cout << "¬ведите индекс монома:" << std::endl;
		cin>> monom.index;
		return cin;
	}

	friend std::ostream& operator<<(std::ostream& cout, const Monom& monom) {
		int x_deg = monom.index / 100;
		int y_deg = monom.index / 10;
		int z_deg = monom.index % 10;
		cout << monom.coef << "*X^(" << x_deg << ")Y^(" << y_deg << ")Z^(" << z_deg << ")" << std::endl;
		return cout;
	}
};


