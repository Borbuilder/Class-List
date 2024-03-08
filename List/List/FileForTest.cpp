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
  

    std::vector<Monom> v1;
    Monom m3(1, 113);
    v1.push_back(m3);
    Monom m4(2, 114);
    v1.push_back(m4);

    TPolinom p;
    //std::string str = "-x^1y^4z^2+x^1y^4z^2";
    p.createPolinomOnVector(v);
    p.output();

    TPolinom p1,p2; 
    p1.createPolinomOnVector(v1);
    //p.vectorOutput();
    p1.output();
    p2 = (p1 * p);
    p2.output();
   // p2 = p2 - p1;
    //p2.output();
}