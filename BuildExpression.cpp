#include"BuildExpression.h"
#include<ctime>
#include<random>
#include<cmath>
#include<cstdlib>
#include<functional>
using namespace std;

default_random_engine generator(time(NULL));
normal_distribution<double> lendis(5, 3);
normal_distribution<double> numdis(5, 2);
auto lendice = bind(lendis, generator);
auto numdice = bind(numdis, generator);
int p = 0;
int Expression[50];
//mode=1 基础，mode=2 带分数，mode=3，带乘方。
int RandExpLen()
{
	int randnum = lround(lendice());
	if (randnum < 2)
		randnum = 2;
	else if (randnum > 10)
		randnum = 10;
	return randnum;
}
int RandExpNum(int maxnum)
{

	int randnum = lround(numdice());
	if (randnum < 0)
		randnum = 0;
	else if (randnum > maxnum)
		randnum = maxnum;
	return randnum;
}
int RandSymbol(int mode)
{
	int randnum;
	if (mode == 1)
		randnum = rand() % 4 + 101;
	else if (mode == 2)
		randnum = rand() % 4 + 101;
	else if (mode == 3)
		randnum = rand() % 5 + 101;
	else if (mode == 4)
		randnum = rand() % 2;
	return randnum;
}
int PownumEasy()
{
	return rand() % 3 + 1;
}
void PrintExp()
{
	for (int i = 0; i < p; i++)
	{
		if (Expression[i] == 101)
			printf(" + ");
		else if (Expression[i] == 102)
			printf(" - ");
		else if (Expression[i] == 103)
			printf(" * ");
		else if (Expression[i] == 104)
			printf(" / ");
		else if (Expression[i] == 105)
			printf(" ^ ");
		else if (Expression[i] == 106)
			printf("(");
		else if (Expression[i] == 107)
			printf(")");
		else
			printf("%d", Expression[i]);
	}
	printf("= ");
}
int* BuildExp(int mode)
{
	int lastbracket = 0;
	p = 0;
	memset(Expression, 0, sizeof(Expression));
	bool HavePow = false;
	int expnum = RandExpLen();
	for (int j = 1; j <= expnum; j++)
	{
		if (j == expnum)//最后一个数字的判断
		{
			Expression[p++] = RandExpNum(10);
			if (Expression[p - 2] == 105)
				Expression[p - 1] = PownumEasy();
			if (Expression[p - 2] == 104 && Expression[p - 1] == 0)//判断分母0
				Expression[p - 1] = 1;
			if (lastbracket != 0)//若有未匹配左括号，则最后一位强制添加右括号
				Expression[p++] = 107;
			break;
		}
		else
		{
			Expression[p++] = RandExpNum(10);//生成随机数
			if (Expression[p - 2] == 105)
				Expression[p - 1] = PownumEasy();
			if (Expression[p - 2] == 104 && Expression[p - 1] == 0)//判断分母0
				Expression[p - 1] = 1;
			if (RandSymbol(4) && lastbracket > 2)//右括号
			{
				Expression[p++] = 107;
				lastbracket = 0;
			}
			Expression[p++] = RandSymbol(mode);//生成随机符号
			{//检查乘方个数
				if (Expression[p - 1] == 105 && HavePow)
					Expression[p - 1] = RandSymbol(1);
				else if (Expression[p - 1] == 105)
					HavePow = true;
			}
			if (RandSymbol(4) && j<expnum - 1 && lastbracket == 0 && Expression[p - 1]<104)//左括号
			{
				Expression[p++] = 106;
				lastbracket = 1;
			}
		}
		if (lastbracket != 0)
			lastbracket++;
	}
	return Expression;
}
