#include <iostream>
#include "Stack_c.h"
#include <string>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Stack_Calc r;
    r.calc_stack();
}