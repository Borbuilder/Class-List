#include "TPolinom.h"
#include<string>
#include<vector>

void TPolinom::createMomomVector(const std::string& in_str)
{
    std::vector<Monom> cur_vector;
    std::string check = "1234567890xyz+-^";
    std::string str = "+" + in_str;
    int coef,x_deg,y_deg,z_deg;

    for (int i = 0; i < str.length(); i++)
    {
        if (check.find(str[i]) != std::string::npos)                            //Проверяем, правильный ли поступил элемент
        {

            if (str[i] == '+' || str[i] == '-')                                    //Создаём моном
            {
                int stop_position = str.find_first_of("+-", i + 1);
                int current_len = stop_position - i - 1;
                std::string current_str;
                current_str = str.substr(i + 1, stop_position - 1);

                if ((current_str[i] >= '0') && (current_str[i] <= '9'))
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

                Monom current_monom;
                current_monom.createMonom(coef, x_deg, y_deg, z_deg);
                arr_monom.push_back(current_monom);
            }

        }
        else {
            std::cout << in_str[i];
            throw std::exception();
        }
    }
}

void TPolinom::createPolinom()
{
    
}
