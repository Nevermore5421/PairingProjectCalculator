#pragma once

#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;

class num {
private:
	int numerator;		//����
	int denominator;	//��ĸ
	int mygcd;			//��Լ��
	int mysign;			//����
	int flag;			//��ֹ������ж�Σ����û����־
	void gcd(int x, int y)
	{
		if (y == 0)
			mygcd = x;
		else
			gcd(y, x%y);
	}
	void reduction()	//����
	{
		if (numerator != 0)		//���Ӳ�Ϊ0
		{
			mysign = mysign*(numerator / abs(numerator))*(denominator / abs(denominator));
			numerator = abs(numerator);
			denominator = abs(denominator);
			gcd(numerator, denominator);
		}
		else                   //����Ϊ0
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
	friend num operator ^(num &a, num &b);	//��֤b�ķ�ĸΪ1
	friend int operator == (num &a, num &b);
};
