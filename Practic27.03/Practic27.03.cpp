#include <iostream>
#include "HomeWork.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    HomeWork h{ 2, 20 };
    
    do {
        for (int i = 0; i < 5; i++) {
            h.ArrivalBus();
        }
    } while (!h.IsInterval(10, h.avg / 5));
}
