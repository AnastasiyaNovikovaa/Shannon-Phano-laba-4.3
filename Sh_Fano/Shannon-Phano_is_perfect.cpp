#include "Shannon-Phano_is_perfect.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

Shannon_Phano_is_perfect::Shannon_Phano_is_perfect(string &str)//кодировка
{
	
	
	size_t i = 0;
	if (str.empty())
	{
		throw std::exception("String is empty :c");
	}
	while (i != str.length()) //заполняем дерево элементами  
	{
		Map.insert(str[i]);
		i++;
	}
	list_for_sorting = Map.get_keys();  //забивка списка
	list_for_sorting.sorting(list_for_sorting.get_front(), list_for_sorting.get_back()); //сортируем список по возрастанию частот
	list_for_sorting.make_group(list_for_sorting.get_front(), list_for_sorting.get_back()); //группируем по среднему значению частот
	for (int j = 0; j < list_for_sorting.get_size(); j++)
		Map.set_code(list_for_sorting.get_code_list(j), list_for_sorting.get_data_list(j));//переносим все в мапу
}

string Shannon_Phano_is_perfect::print_code(string &str)// вывод кода
{
	string code_Shannon_Phano;
	size_t i = 0;
	
	while ( i != str.length())
	{
		code_Shannon_Phano = code_Shannon_Phano + Map.get_code(str[i]);
		i++;
	}
	cout << "Объем исходной фразы:" << 8 * str.length() << "бит";
	cout << endl;
	cout << "Объем закодированной фразы:" << code_Shannon_Phano.size() << "бит";
	cout << endl;
	cout << "Коэффициент сжатия:" << (float)(8 * str.length())/ (code_Shannon_Phano.size() );
	cout << endl;
	cout << code_Shannon_Phano;
	return code_Shannon_Phano;
}

string Shannon_Phano_is_perfect::decode(string &str)//декодирование
{
	string decode_of_string;

	while (str.length() != 0)
	{
		for (int j = 0; j < list_for_sorting.get_size(); j++)
		{
			int size = 0;
			if (list_for_sorting.compare_str(str, list_for_sorting.get_code_list(j), size))//код верный
			{
				std::cout << list_for_sorting.get_data_list(j);
				decode_of_string += list_for_sorting.get_data_list(j);
				str.erase(0, size);   //стираем
			}
		}
		

	}
	return decode_of_string;
	std::cout << '\n';
}

void Shannon_Phano_is_perfect::get_table()
{
	list_for_sorting.print();
}



