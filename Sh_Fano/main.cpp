#include "Shannon-Phano_is_perfect.h"
#include <iostream>
#include <conio.h>
//������� � ��������,������� � ��������! ��� � ���? ������-��!
//����� ���� ���������� ����� ������
//� ����� ����� ����
//i love leti very much
//123456789

using namespace std;
void main() 
{  
	setlocale(LC_ALL, "Russian");
	cout << "Hello! Laboratory work #3 \n";
	cout << "by Novikova Anastasiya 7302\n";
	cout << "You are welcome!";
	cout << endl;
	cout << endl;
	string stri = "����� ���� ���������� ����� ������";
	cout << "�������� ������:\n";
	cout << stri;
	cout << endl;
	
	Shannon_Phano_is_perfect str(stri);
	cout << "�����������\n";
	cout << endl;
	string decodeg = str.print_code(stri);
	cout << endl;
	cout << endl;
	cout << "�������������\n";
	str.decode(decodeg);
	cout << endl;
	cout << "����� ������� ������ �� �����������\n";
	str.get_table();
	cout << endl;
	system("pause");
}