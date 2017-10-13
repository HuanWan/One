#include <iostream>
#include<stdio.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<math.h>
using namespace std;

int main()
{
	int game_num;
	map<string, double>mp;
	int i, n;
	double num, sum, ave, G;
	int temp = 0;
	string name;
	printf("请输入游戏的人数：");
	scanf_s("%d", &n);
	printf("\n");
	printf("请输入此次游戏进行的轮数：");
	scanf("%d", &game_num);
	printf("\n");

	while (game_num--)
	{
		++temp;
		mp.clear();   //清空map中的数据
		sum = 0; ave = 0; G = 0;
		printf("第%d轮开始：\n", temp);
		printf("请输入每人的姓名和有理数（空格隔开）：\n");
		for (i = 0; i<n; i++)
		{

			cin >> name >> num;
			if (num>0.0&&num<100.0)
			{
				mp[name] = num;   //建立map的关系
				sum = sum + num;
			}
			else
			{
				printf("请输入（0-100）的有理数\n");
				i--;
			}
		}

		map<string, double>::iterator iter, result_high, result_low;

		printf("总和为：%.4lf\n", sum);
		ave = sum / n;
		printf("平均值：%.4lf\n", ave);
		G = ave*0.618;
		printf("G点值：%.4lf\n", G);

		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			iter->second = (double)fabs(G - (double)iter->second);    //iter存的是差值

		}

		for (iter = mp.begin(), result_high = mp.begin(), result_low = mp.begin(); iter != mp.end(); iter++)
		{
			if (iter->second<result_high->second)
				result_high = iter;
			if (iter->second>result_low->second)
				result_low = iter;
		}

		cout << endl;
		cout << "姓名" << "\t" << "差值" << endl;
		cout << result_high->first << "\t" << result_high->second << "\t" << "得到" << n << "分" << endl;
		cout << result_low->first << "\t" << result_low->second << "\t" << "得到-2分" << endl;
		cout << endl;

		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			iter->second = 0;
		}

		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			if (iter == result_high)
				iter->second += n;
			if (iter == result_low)
				iter->second += -2;
		}
		cout << "第" << temp << "轮结果：" << endl;
		cout << "姓名" << "\t" << "分数" << endl;
		for (iter = mp.begin(); iter != mp.end(); iter++)
			cout << iter->first << "\t" << iter->second << endl;
		cout << endl;
	}
	return 0;
}

