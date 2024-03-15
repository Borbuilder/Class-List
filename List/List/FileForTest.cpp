#include<iostream>
#include "TList.h"
#include "TPolinom.h"
#include<vector>
#include "Monom.h"
#include<string>

int main()
{   
    std::string input_str2 = "(1111111111)";
    int constanta=0;
    if (input_str2[0] == '(' && input_str2[input_str2.size() - 1] == ')')
    {
        std::string const_str = input_str2.substr(1, input_str2.size() - 2);
        constanta = std::stoi(const_str);
    }
    std::cout << constanta;
     /*std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::cout << v[v.size() - 1];*/

    
}