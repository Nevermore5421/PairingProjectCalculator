#pragma once

#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;

class num {
private:
	int numerator;		//分子
	int denominator;	//分母
	int mygcd;			//公约数
	int mysign;			//符号
	int flag;			//防止化简进行多次，设置化简标志
	void gcd(int x, int y)
	{
		if (y == 0)
			mygcd = x;
		else
			gcd(y, x%y);
	}
	void reduction()	//化简
	{
		if (numerator != 0)		//分子不为0
		{
			mysign = mysign*(numerator / abs(numerator))*(denominator / abs(denominator));
			numerator = abs(numerator);
			denominator = abs(denominator);
			gcd(numerator, denominator);
		}
		else                   //分子为0
		{
			denominator = 1;
			mygcd = 1;
			mysign = 1;
		}
		flag = 1;
	}
public:
	num();
	num(int x);
	num(int x, int y,int sign);
	void print();
	void print(char * formula,ofstream & outtofile);
	friend num operator +(num &a, num &b);
	friend num operator -(num &a, num &b);
	friend num operator *(num &a, num &b);
	friend num operator /(num &a, num &b);
	friend num operator ^(num &a, num &b);	//保证b的分母为1
	friend int operator == (num &a, num &b);
};
