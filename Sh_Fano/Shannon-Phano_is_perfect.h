#pragma once
#include "List.cpp"
#include "map.cpp"
#include <iostream>

using namespace std;
		class Shannon_Phano_is_perfect
		{
	   
		   public:
			Shannon_Phano_is_perfect(string&); //�����������, �����������
			~Shannon_Phano_is_perfect() {};
			string print_code(string &str);     //����� ���� � �������� ����������
			string decode(string &str);     //�������������
			void get_table();               //�������� �������� � �����������
			string get_codes_fano_list(size_t index) { return list_for_sorting.get_code_list(index); } //��� ��������

		    private:

			List <char> list_for_sorting;
			map < char> Map;
		};