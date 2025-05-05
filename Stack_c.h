#pragma once
#include <string>
#include <iostream>
#include "..\Stack\Stack_class.h"

using namespace std;

/// ����� ������������(���������) ������������
class Stack_Calc
{
private:
	Temp_Stack<float> stack;

public:
	/// ����� ��� ��������
	void plus()
	{
		if (stack.get_size() < 2)
		{
			cout << "�������� ����������, ��������� ����� 2";
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

	/// ����� ��� ��������
	void min()
	{
		if (stack.get_size() < 2)
		{
			cout << "�������� ����������, ��������� ����� 2";
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

	/// ����� ��� ���������
	void mult()
	{
		if (stack.get_size() < 2)
		{
			cout << "�������� ����������, ��������� ����� 2";
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

	/// ����� ��� �������
	void div()
	{
		if (stack.get_size() < 2)
		{
			cout << "�������� ����������, ��������� ����� 2";
			return;
		}
		float num_1 = stack.top();
		stack.pop();
		float num_2 = stack.top();
		stack.pop();
		if (num_2 == 0)
		{
			cout << "�������� ����������, ������ �� 0 ������";
			return;
		}
		float rez;
		rez = num_1 / num_2;
		stack.push(rez);
	}

	/// ����� ��� ����������
	void calc_stack()
	{
		while (true)
		{
			string s; // ������
			cin >> s;
			if (s.size() == 0)
			{
				return;
			}

			if (s == "+") // ���� ������ ��� ��������(+)
			{
				plus();
			}
			else if (s == "-") // ���� ������ ��� ��������(-)
			{
				min();
			}
			else if (s == "*") // ���� ������ ��� ��������(*)
			{
				mult();
			}
			else if (s == "/") // ���� ������ ��� ��������(/)
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
			else if (s == "=") // ���� ������ ��� ��������(=)
			{
				cout<< "\n= " << stack.top() << "\n";
			}
		}
	}

	/// ����� ������� � ����
	void onpush(string s)
	{
		float x = stof(s);
		stack.push(x);
	}
};