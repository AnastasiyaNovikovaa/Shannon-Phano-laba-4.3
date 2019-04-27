#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Sh_Fano/Shannon-Phano_is_perfect.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Fano
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(encode_test_russian)
		{
			string stri = "я очень люблю лэти";
			Shannon_Phano_is_perfect str(stri);
			str.print_code(stri);
			string check = "01110101010111010111000111000100001101101000110010001111100001001";
			Assert::AreEqual(check, str.print_code(stri));
		}

		TEST_METHOD(encode_test_english)
		{
			string stri = "i love leti very much";
			Shannon_Phano_is_perfect str(stri);
			str.print_code(stri);
			string check = "100000011110010110010000111010110011000000110010110111000001011111010101111";
			Assert::AreEqual(check, str.print_code(stri));
		}

		TEST_METHOD(encode_test_numb)
		{
			
			string stri = "123456789";
			Shannon_Phano_is_perfect str(stri);
			str.print_code(stri);
			string check = "00010011010110101000000110111";
			Assert::AreEqual(check, str.print_code(stri));
		}
		TEST_METHOD(decode_test_enlish)
		{
			string stri = "i love leti very much";
			Shannon_Phano_is_perfect str(stri);
			string decodeg = str.print_code(stri);
			Assert::AreEqual(stri, str.decode(decodeg));
		}

		TEST_METHOD(decode_test_russian)
		{
			string stri = "я очень люблю лэти";
			Shannon_Phano_is_perfect str(stri);
			string decodeg = str.print_code(stri);
			Assert::AreEqual(stri, str.decode(decodeg));
		}

		TEST_METHOD(decode_test_numb)
		{

			string stri = "123456789";
			Shannon_Phano_is_perfect str(stri);
			string decodeg = str.print_code(stri);
			Assert::AreEqual(stri, str.decode(decodeg));
		}

		TEST_METHOD(encode_test_engish_codes)
		{
			string stri = "be or not to be";
			//string stri = "123";
			Shannon_Phano_is_perfect str(stri);
			str.print_code(stri);
			string check[7] = { "00", "01", "100","101","110","1110","1111" };
			for (size_t i = 0; i < 7; i++) {
				Assert::AreEqual(check[i], str.get_codes_fano_list(i));
			}
		}
		TEST_METHOD(encode_test_numb_codes)
		{

			string stri = "123";
			Shannon_Phano_is_perfect str(stri);
			str.print_code(stri);
			string check[3] = { "00", "01", "1" };
			for (size_t i = 0; i < 3; i++) {
				Assert::AreEqual(check[i], str.get_codes_fano_list(i));
			}
		}
		
	
	
	};
}
