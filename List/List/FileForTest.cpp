#include<iostream>
#include "TList.h"

int main()
{
    TList<int> list;
    list.InsFirst(1);
    list.InsLast(2);
    list.InsLast(3);
    list.output();
    list.SetPos(1);
    list.InsCurrent(5);
	list.output();

	std::cout << list.GetPos();
}