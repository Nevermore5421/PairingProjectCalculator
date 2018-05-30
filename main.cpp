#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include"mynumber.h"
#include"calculate.h"
#include"processyouranswer.h"
#include"maped.h"
#include"BuildExpression.h"
using namespace std;
int main(int argc ,char * argv[])
{
	if (!strcmp(argv[1],"-s"))
	{
		ifstream filein(argv[2]);
		ofstream outtofile("answer.txt");
		int maped[30];
		char formula[100];
		while (!filein.eof())
		{
			filein.getline(formula, 100, '\n');
			memset(maped, -1, sizeof(maped));
			changeintomaped(formula, maped);		//将字符串转换为可处理的整形序列
			num res = getans(maped);
			cout << formula << " = " << endl;
			res.print();
			res.print(formula, outtofile);			//额外输出运算式与答案到文件中
		}
	}
	if (!strcmp(argv[1], "-i"))
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < atoi(argv[2]); i++)
		{
			num useranswer;
			int * save=BuildExp(3);
			PrintExp();
			getresult(getans(save));
		}
	}
	return 0;
}