// Автор: Высоцкая И.Д.
#pragma once
#include <string>
#include <iostream>
#include <sstream> // библиотека с классами, функциями и переменными для организации работы со строками
#include <stdexcept>
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

	/// Метод для вычислений выражений в постфиксной форме
	/// Могут выполняться операции сложения, вычитания, умножения и деления
	/// Бросается исключение, если введена пустая строка
	/// const string& str - ссылка на строку
	float calc_stack(const string& str)
	{
		stringstream pars_s; // специальная переменная типа stringstream для разбора строки
		string s; // "слово" 
		if (str.empty()) // если строка пустая
		{
			throw length_error("Пустая строка"); // бросаем исключение
		}

		pars_s << str;
		while (!pars_s.eof()) // пока не конец строки
		{ 
			pars_s >> s; // входная строка читается по "словам" от пробела до пробела

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
			else if (isdigit(s[0]) || (s.size() > 1 && (s[0] == '-' || s[0] == '+' && isdigit(s[1]) || (s.find('.') != string::npos && isdigit(s[s.find('.')+1]))))) // s.find('.') != string::npos && isdigit(s[s.find('.')+1] - проверяем есть ли точка, и после точки обязательно должно быть число, string::npos - спец. константа, используется для индикации отсутствия подстроки
			{
				onpush(s);
			}
			else if (s == "=") // если символ это оператор(=)
			{
				return stack.top(); // возвращаем результат со стека
			}
		}
		return stack.top(); // возвращаем результат со стека
	}

	/// Метод вставки в стек
	/// Бросает исключение, если введён символ, который нельзя преобразовать в число при отдельном использовании метода
	void onpush(string s)
	{
		try
		{
			float x = stof(s); // stof - функция, преобразующая строку в число в плавающей точкой
		    stack.push(x);
		}
		catch (exception e)
		{
			throw runtime_error("Невозможно преобразовать в число");
		}
		
	}

	/// Метод очистки
	void clear()
	{
		stack.clear();
	}
};

// тесты
void test();