#pragma once
#include "List.cpp"
#include "map.cpp"
#include <iostream>

using namespace std;
		class Shannon_Phano_is_perfect
		{
	   
		   public:
			Shannon_Phano_is_perfect(string&); //конструктор, кодирование
			~Shannon_Phano_is_perfect() {};
			string print_code(string &str);     //вывод кода и полезной информации
			string decode(string &str);     //декодирование
			void get_table();               //красивая табличка с результатом
			string get_codes_fano_list(size_t index) { return list_for_sorting.get_code_list(index); } //для юнитиков

		    private:

			List <char> list_for_sorting;
			map < char> Map;
		};
