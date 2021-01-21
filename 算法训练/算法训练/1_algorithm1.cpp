#include"1_algorithm1.h"
#include <Windows.h>
#define ini_1 "../1_algorithm1.ini"

bool algorithm1(vector<int> &nums, int k) 
{
	if (nums.size() < 2 || k < 1)
		return false;
	unordered_map<int, int>numap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (numap.count(nums[i]) == true)
		{
			if (i - numap[nums[i]] <= k)
				return true;
			else
				numap[nums[i]] = i;
		}
		numap.insert(pair<int, int>(nums[i], i));
	}
	return false;
}





/*void test(char *testnum)
{
	char chSnames[200] = { 0 };
	char chkey[200] = { 0 };
	vector<int> nums;

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
				nums.push_back(atoi(p));
				p = strtok(NULL, ",");
			}
			int b = GetPrivateProfileInt(testnum, "Key", 0, ini_1);
			bool output = GetPrivateProfileInt(testnum, "Output", 0, ini_1);

			cout << b << " " << output << endl;
			nums.clear();
			j = -1;
			if (chSnames[i + 1] == 0)
			{
				break;
			}
		}
	}
} */


int main()
{
	vector<int>nums;
	int k = 3;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(1);
	bool result = algorithm1(nums, k);
	if (!result)
	{
	cout << "该数组不存在两个相同数的索引值相减的绝对值小于等于k" << endl;
	}
	else
	cout << "True" << endl;
	
	
	//test("Test1");

	system("pause");
}