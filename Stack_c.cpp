// �����:�������� �.�.
#include <cassert>
#include "Stack_c.h"

void test()
{
	// ���� ��� ��������
	Stack_Calc rez;
	string str_1 = "3 4 +";
	assert(rez.calc_stack(str_1) == 7);
	rez.clear();

	// ���� ��� ���������
	string str_2 = "10 2 - =";
	assert(rez.calc_stack(str_2) == -8);
	rez.clear();

	// ���� ��� ���������
	string str_3 = "10 2 *";
	assert(rez.calc_stack(str_3) == 20);
	rez.clear();

	// ���� ��� �������
	string str_4 = "10 2 / =";
	assert(rez.calc_stack(str_4) == 0.2);
	rez.clear();

	// ���� ��� �������� ���������
	string str_5 = "4 2 3 + *";
	assert(rez.calc_stack(str_5) == 20);
	rez.clear();

	// ���� ��� �������� ���������
	string str_6 = "8 -15 10 3 * - +";
	assert(rez.calc_stack(str_6) == 53);
	rez.clear();

	// ���� ��� �������� ���������
	string str_7 = "800 -15 10 3 * - +";
	assert(rez.calc_stack(str_7) == 845);
	rez.clear();

	// ���� ��� ��������� � ����������� �������
	string str_10 = "3.5 3.5 *";
	assert(rez.calc_stack(str_10) == 12.25);
	rez.clear();

	// ���� ��� ��������� � ����������� �������
	string str_11 = "3.5 3 *";
	assert(rez.calc_stack(str_11) == 10.5);
	rez.clear();

	// ���� �� �������� ���������� ��� ����� ������ ������
	try
	{
		string str_8 = "";
		assert(false);
	}
	catch (length_error)
	{

	}

	// ���� ��� ����� �������, ������� ������ ������������� � �����
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



