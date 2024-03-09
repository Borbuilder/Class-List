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
    p1.createPolinom("x^2y^2z^2+x^3y^3z^3");
    p2.createPolinom("x^2y^2z^2+x^4y^4z^4");
   // p3.createPolinom("x^4y^4z^4+x^3y^3z^3+2x^2y^2z^2");
    p3 = p2 + p1;
    std::string str=p3.polinomToString();
    std::cout << str;

    
}