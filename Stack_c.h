// �����: �������� �.�.
#pragma once
#include <string>
#include <iostream>
#include <sstream> // ���������� � ��������, ��������� � ����������� ��� ����������� ������ �� ��������
#include <stdexcept>
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

	/// ����� ��� ���������� ��������� � ����������� �����
	/// ����� ����������� �������� ��������, ���������, ��������� � �������
	/// ��������� ����������, ���� ������� ������ ������
	/// const string& str - ������ �� ������
	float calc_stack(const string& str)
	{
		stringstream pars_s; // ����������� ���������� ���� stringstream ��� ������� ������
		string s; // "�����" 
		if (str.empty()) // ���� ������ ������
		{
			throw length_error("������ ������"); // ������� ����������
		}

		pars_s << str;
		while (!pars_s.eof()) // ���� �� ����� ������
		{ 
			pars_s >> s; // ������� ������ �������� �� "������" �� ������� �� �������

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
			else if (isdigit(s[0]) || (s.size() > 1 && (s[0] == '-' || s[0] == '+' && isdigit(s[1]) || (s.find('.') != string::npos && isdigit(s[s.find('.')+1]))))) // s.find('.') != string::npos && isdigit(s[s.find('.')+1] - ��������� ���� �� �����, � ����� ����� ����������� ������ ���� �����, string::npos - ����. ���������, ������������ ��� ��������� ���������� ���������
			{
				onpush(s);
			}
			else if (s == "=") // ���� ������ ��� ��������(=)
			{
				return stack.top(); // ���������� ��������� �� �����
			}
		}
		return stack.top(); // ���������� ��������� �� �����
	}

	/// ����� ������� � ����
	/// ������� ����������, ���� ����� ������, ������� ������ ������������� � ����� ��� ��������� ������������� ������
	void onpush(string s)
	{
		try
		{
			float x = stof(s); // stof - �������, ������������� ������ � ����� � ��������� ������
		    stack.push(x);
		}
		catch (exception e)
		{
			throw runtime_error("���������� ������������� � �����");
		}
		
	}

	/// ����� �������
	void clear()
	{
		stack.clear();
	}
};

// �����
void test();