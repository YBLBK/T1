#include "stdafx.h"
#include "CppUnitTest.h"
#include<Windows.h>
#include"../À„∑®—µ¡∑/2_algorithm2.h"
#define ini_2 "../2_algorithm2.ini"
#include<algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		void test(char *testnum)
		{
			char chSnames[200] = { 0 };
			char chstr[50] = { 0 };
			string CHar ;
			GetPrivateProfileSectionNames(chSnames, 200, ini_2);
			int i;
			int j = 0;
			for (i = 0; i < 200; i++, j++)
			{
				if (chSnames[0] == '\0')
					break;
				if (chSnames[i] == '\0')
				{
					testnum = &chSnames[i - j];
					GetPrivateProfileString(testnum, "Output", 0, chstr, 200, ini_2);
					for (int x = 0; chstr[x]!='\0'; x++)
					{
						CHar.push_back(chstr[x]);
					}
					/*CHar.erase(
						remove_if(CHar.begin(), CHar.end(), static_cast<int(*)(int)>(&ispunct)),
						CHar.end());*/

					int a = GetPrivateProfileInt(testnum, "Input", 0, ini_2);

					Assert::AreEqual(CHar,algorithm2(a));

					CHar.clear();
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