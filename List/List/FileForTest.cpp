#include<iostream>
#include "TList.h"
#include "TPolinom.h"
#include<vector>
#include "Monom.h"

int main()
{   
    std::vector<Monom> v;
    Monom m(1, 111);
    v.push_back(m);
    Monom m1(2, 112);
    v.push_back(m1);
    Monom m2(3, 113);
    v.push_back(m2);
   /* for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
    }*/
    
    
    TPolinom p;
    //std::string str = "-x^1y^4z^2+x^1y^4z^2";
    p.createPolinomOnVector(v);
    p.output();

    TPolinom p1,p2; 
    p1 = p;
    //p.vectorOutput();
    p1.output();
    p2 = p1 + p;
    p2.output();
    /*
     
    int rows = 2;
    int cols = 2;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.insert(v.begin(), 3);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i];

    }
    

   std::string str;
    str = "+12345+";

    int x_deg = static_cast<int>(str[1]) - '0';
    std::cout << x_deg;

    int stop_position = str.find_first_of("+*-/", 0+1);
    int current_len = stop_position - 0 - 1;
    std::cout << current_len<<" ";
    
    std::string current_str;
    current_str = str.substr(0 + 1, stop_position - 1);
    std::cout << current_str;

    //std::cout << str.length();
    std::string new_str = "+" + str + "$";
    std::cout << new_str << "  " << new_str.length()<<" "<<new_str[new_str.length()];
    std::cout << new_str[new_str.length()-1];*/
}