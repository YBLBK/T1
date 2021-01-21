#include"2_algorithm2.h"

#include<Windows.h>
#define ini_2 "../2_algorithm2.ini"
#include<algorithm>
#include<vector>

string algorithm2(int n) 
{
	string result;
	if (n>0 && n<257)
	{
		while (n != 0)
		{
			n -= 1;
			result = char(n % 26+'A') + result;
			n = n / 26;
		}
		return result;
	}
	else
		return "";
	
}

/*void test(char *testnum)
{
	char chSnames[200] = { 0 };
	char chstr[50] = { 0 };
	vector<char>str;
	string CHar;
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
			GetPrivateProfileString(testnum, "Output", 0, chstr, 50, ini_2);
			//int x = 0;
			//while (chstr[x] != '\0')
			//{
				//CHar.push_back(chstr[x]);
				//x++;
			//}
			for (int x = 0; chstr[x] != '\0'; x++)
			{
				CHar.push_back(chstr[x]);
			}

			int a = GetPrivateProfileInt(testnum, "Input", 0, ini_2);
		
			CHar.clear();
			j = -1;
			if (chSnames[i + 1] == 0)
			{
				break;
			}
		}
	}
}*/

int main()
{
	/*int n=256;
	cout << algorithm2(n) << endl;*/
	
	//test("Test1");

	system("pause");
}