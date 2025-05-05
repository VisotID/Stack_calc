#pragma once
#include <string>
#include <iostream>
#include "..\Stack\Stack_class.h"

using namespace std;

/// Класс постфиксного(стекового) калькулятора
class Stack_Calc
{
private:
	Temp_Stack<float> stack;

public:
	/// Метод для сложения
	void plus()
	{
		if (stack.get_size() < 2)
		{
			cout << "Операция невозможна, операндов менее 2";
			return;
		}
		float num_1 = stack.top();
		stack.pop();
		float num_2 = stack.top();
		stack.pop();
		float rez;
		rez = num_1 + num_2;
		stack.push(rez);
	}

	/// Метод для разности
	void min()
	{
		if (stack.get_size() < 2)
		{
			cout << "Операция невозможна, операндов менее 2";
			return;
		}
		float num_1 = stack.top();
		stack.pop();
		float num_2 = stack.top();
		stack.pop();
		float rez;
		rez = num_1 - num_2;
		stack.push(rez);
	}

	/// Метод для умножения
	void mult()
	{
		if (stack.get_size() < 2)
		{
			cout << "Операция невозможна, операндов менее 2";
			return;
		}
		float num_1 = stack.top();
		stack.pop();
		float num_2 = stack.top();
		stack.pop();
		float rez;
		rez = num_1 * num_2;
		stack.push(rez);
	}

	/// Метод для деления
	void div()
	{
		if (stack.get_size() < 2)
		{
			cout << "Операция невозможна, операндов менее 2";
			return;
		}
		float num_1 = stack.top();
		stack.pop();
		float num_2 = stack.top();
		stack.pop();
		if (num_2 == 0)
		{
			cout << "Операция невозможна, делить на 0 нельзя";
			return;
		}
		float rez;
		rez = num_1 / num_2;
		stack.push(rez);
	}

	/// Метод для вычислений
	void calc_stack()
	{
		while (true)
		{
			string s; // строка
			cin >> s;
			if (s.size() == 0)
			{
				return;
			}

			if (s == "+") // если символ это оператор(+)
			{
				plus();
			}
			else if (s == "-") // если символ это оператор(-)
			{
				min();
			}
			else if (s == "*") // если символ это оператор(*)
			{
				mult();
			}
			else if (s == "/") // если символ это оператор(/)
			{
				div();
			}
			else if (isdigit(s[0]) || (s.size() > 1 && (s[0] == '-' || s[0] == '+') && isdigit(s[1])))
			{
				onpush(s);
			}
			else if (s == "exit")
			{
				return;
			}
			else if (s == "=") // если символ это оператор(=)
			{
				cout<< "\n= " << stack.top() << "\n";
			}
		}
	}

	/// Метод вставки в стек
	void onpush(string s)
	{
		float x = stof(s);
		stack.push(x);
	}
};