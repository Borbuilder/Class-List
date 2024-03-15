#include<iostream>
#include "TList.h"
#include "TPolinom.h"
#include<vector>
#include "Monom.h"
#include<string>

int main()
{   
   
    TPolinom p1;
    TPolinom p2;
    TPolinom p3;
    p1.createPolinom("x^2y^2z^2+x^4y^4z^4");
    p2.createPolinom("5x^2y^2z^2+5x^4y^4z^4");
    p3 = p1 * 5;
    p2.output();
    p3.output();
    //p4 = p1 + p2;
    //std::string str=p3.polinomToString();
    //std::cout << str;
     /*std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::cout << v[v.size() - 1];*/

    
}