// Автор:Высоцкая И.Д.
#include <cassert>
#include "Stack_c.h"

void test()
{
	// тест для сложения
	Stack_Calc rez;
	string str_1 = "3 4 +";
	assert(rez.calc_stack(str_1) == 7);
	rez.clear();

	// тест для вычитания
	string str_2 = "10 2 - =";
	assert(rez.calc_stack(str_2) == -8);
	rez.clear();

	// тест для умножения
	string str_3 = "10 2 *";
	assert(rez.calc_stack(str_3) == 20);
	rez.clear();

	// тест для деления
	string str_4 = "10 2 / =";
	assert(rez.calc_stack(str_4) == 0.2);
	rez.clear();

	// тест для сложного выражения
	string str_5 = "4 2 3 + *";
	assert(rez.calc_stack(str_5) == 20);
	rez.clear();

	// тест для сложного выражения
	string str_6 = "8 -15 10 3 * - +";
	assert(rez.calc_stack(str_6) == 53);
	rez.clear();

	// тест для сложного выражения
	string str_7 = "800 -15 10 3 * - +";
	assert(rez.calc_stack(str_7) == 845);
	rez.clear();

	// тест для выражения с десятичными числами
	string str_10 = "3.5 3.5 *";
	assert(rez.calc_stack(str_10) == 12.25);
	rez.clear();

	// тест для выражения с десятичными числами
	string str_11 = "3.5 3 *";
	assert(rez.calc_stack(str_11) == 10.5);
	rez.clear();

	// тест на бросание исключения при вводе пустой строки
	try
	{
		string str_8 = "";
		assert(false);
	}
	catch (length_error)
	{

	}

	// тест при вводе символа, который нельзя преобразовать в число
	try
	{
		string str_9 = "a";
		rez.onpush(str_9);
		assert(false);
	}
	catch (runtime_error)
	{

	}
}



