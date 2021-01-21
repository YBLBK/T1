#include "stdafx.h"
#include "CppUnitTest.h"
#include "../À„∑®—µ¡∑/1_algorithm1.h"
#include <Windows.h>
#define ini_1 "../1_algorithm1.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		void test(char *testnum)
		{
			char chSnames[200] = { 0 };
			char chkey[200] = { 0 };
			vector<int>ch;
			
			GetPrivateProfileSectionNames(chSnames, 200, ini_1);
			int i;
			int j = 0;
			for (i = 0; i < 200; i++, j++)
			{
				if (chSnames[0] == '\0')
					break;
				if (chSnames[i] == '\0')
				{
					testnum = &chSnames[i - j];

					GetPrivateProfileString(testnum, "Array", 0, chkey, 200, ini_1);
					char *p;
					p = strtok(chkey, ",");
					while (p)
					{
						ch.push_back(atoi(p));
						p = strtok(NULL, ",");
					}
					int b = GetPrivateProfileInt(testnum, "Key", 0, ini_1);
					bool output = GetPrivateProfileInt(testnum, "Output", 0, ini_1);
		
					Assert::AreEqual(output, algorithm1(ch, b));
					ch.clear();
					j = -1;
					if (chSnames[i + 1] == 0)
					{
						break;
					}
				}
			}
		}
	
		TEST_METHOD(TestMethod1)
		{
			test("Test1");
		}

	};
}