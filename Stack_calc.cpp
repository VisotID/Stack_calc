// Автор:Высоцкая И.Д.
#include <iostream>
#include "Stack_c.h"
#include <string>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Stack_Calc r;
    string s;
    getline(cin, s);
    cout << "= " << r.calc_stack(s);
}