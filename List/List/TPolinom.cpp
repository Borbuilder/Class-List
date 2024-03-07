#include "TPolinom.h"
#include<string>
#include<vector>

void TPolinom::createMomom(const std::string& in_str)
{
    std::vector<Monom> cur_vector;
    std::string check = "1234567890xyz+-^";
    std::string str;
    if (in_str[0] != '-')
    {
        str = "+" + in_str;
    }
    else {
        str = in_str;
    }
    int coef,x_deg,y_deg,z_deg;

    for (int i = 0; i < str.length(); i++)
    {
        if (check.find(str[i]) != std::string::npos)                               //Проверяем, правильный ли поступил элемент
        {

            if (str[i] == '+' || str[i] == '-')                                    //Создаём моном
            {
                int stop_position = str.find_first_of("+-", i + 1);
                int current_len = stop_position - i - 1;
                std::string current_str;
                current_str = str.substr(i + 1, stop_position - 1);

                if ((current_str[0] >= '0') && (current_str[0] <= '9'))
                {
                    if (str[i] == '+') { coef = current_str[0]; }
                    else{ coef = (-1)*(static_cast<int>(current_str[0]) - '0'); }
                }
                else {
                    if (str[i] == '+') { coef = 1; }
                    else { coef = -1; }
                }

                int x_pos = current_str.find("x", 0);
                if (x_pos == std::string::npos)
                {
                    x_deg = 0;
                }
                else {
                    if (current_str[x_pos + 1] == '^')
                    {
                        x_deg = static_cast<int>(current_str[x_pos + 2]) - '0';
                    }
                    else {
                        x_deg = 1;
                    }
                }
                int y_pos = current_str.find("y", 0);
                if (y_pos == std::string::npos)
                {
                    y_deg = 0;
                }
                else {
                    if (current_str[y_pos + 1] == '^')
                    {
                        y_deg = static_cast<int>(current_str[y_pos + 2]) - '0';
                    }
                    else {
                        y_deg = 1;
                    }
                }
                int z_pos = current_str.find("z", 0);
                if (z_pos == std::string::npos)
                {
                    z_deg = 0;
                }
                else{
                    if (current_str[z_pos + 1] == '^')
                    {
                        z_deg = static_cast<int>(current_str[z_pos + 2]) - '0';
                    }
                    else {
                       z_deg = 1;
                    }
                }

                /// <для тестов>
                Monom current_monom;
                current_monom.createMonom(coef, x_deg, y_deg, z_deg);
                arr_monom.push_back(current_monom);
                /// </для тестов>
               
                this->addMonom(current_monom);
            }

        }
        else {
            std::cout << in_str[i];
            throw std::exception();
        }
    }
}

void TPolinom::createPolinomOnVector(std::vector<Monom> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        addMonom(v[i]);
    }
}

void TPolinom::addMonom(Monom& _monom)
{
    if (this->empty())
    {
        this->InsFirst(_monom);
    }
    else {
        Reset();
        while (_monom.getIndex()<pCur->value.getIndex())
        {
            GoNext();
        }
        if (pCur->value == _monom)
        {
            if (_monom.getCoef() + pCur->value.getCoef() == 0)
            {
                DelCurrent();
            }
            else {
                pCur->value.setCoef(pCur->value.getCoef() + _monom.getCoef());
            }
        }
        else {
            InsCurrent(_monom);
        }
    }
}

TPolinom TPolinom::operator+( TPolinom& _other)
{
    TPolinom result;
    result = _other;
    this->Reset();
    result.Reset();

    while (!IsEnd())
    {
        if (result.pCur->value > pCur->value)
        {
            result.GoNext();
        }
        else if (result.pCur->value < pCur->value)
        {
            result.InsCurrent(pCur->value);
            GoNext();
        }
        else
        {
            if (pCur->value.getIndex() == -1)
            {
                break;
            }
            result.pCur->value.setCoef(result.pCur->value.getCoef() + pCur->value.getCoef());
            if (result.pCur->value.getCoef() == 0)
            {
                result.DelCurrent();
                GoNext();
            }
            else
            {
                result.GoNext();
                GoNext();
            }
        }
    }
    return result;
}
