#include "processyouranswer.h"
#include<cstring>

/*要求用户输入答案并与结果比较*/
void getresult(num res)
{
	char yourans[50];
	//cout << "请输入答案：";
	cin.getline(yourans, 50, '\n');
	int formflag = checkyouranswer(yourans);		//判断答案格式是否正确
	if (formflag)
	{;								//sign代表答案符号，ansnum[0]为分子，[1]为分母
		int ansnum[2] = { 0 , 1 };
		int sign = turntonumber(yourans, ansnum);		
		if (ansnum[1] != 0)							//判断分母是否为0
		{
			num yourres(ansnum[0], ansnum[1], sign);
			if (yourres == res)
				cout << "Right" << endl;
			else
				cout << "Wrong" << endl;
		}
		else
			cout << "Math Error" << endl;
		cout << "正确答案为：";
		res.print();
	}
	else
		cout << "输入格式正确的答案" << endl;
	cout << endl;
}

/*判断答案格式*/
int checkyouranswer(char * yourans)
{
	int flag[50] = {0},pos=0;
	for (int i = 0; yourans[i] == ' '; i++)		//去除前置空格
		flag[i] = 1;
	while (yourans[pos])						//去除除号两侧空格
	{
		if (yourans[pos] == '/')
		{
			for (int i = pos - 1; yourans[i] == ' '; i--)
				flag[i] = 1;
			for (int i = pos + 1; yourans[i] == ' '; i++)
				flag[i] = 1;
		}
		pos++;
	}
	for(int i=pos-1;i>=0&& yourans[i] == ' ';i--)		//去除后置空格
		flag[i] = 1;
	char tempans[50] = { 0 };
	int top = 0;
	for (int i = 0; yourans[i]; i++)
	{
		if (flag[i] == 0)
			tempans[top++] = yourans[i];
	}
	strcpy(yourans, tempans);
	int formflag = 1, divisioncnt = 0;
	/*判断格式，出现其余字符,或2个及以上除号，或负号位置不正确则格式错误*/
	for (int i = 0; yourans[i] != 0; i++)
	{
		if (yourans[i] >= '0'&&yourans[i] <= '9')
			continue;
		else if (yourans[i] == '/'&&divisioncnt < 1)
		{
			divisioncnt++;
			continue;
		}
		else if (yourans[i] == '-' && (i == 0 || yourans[i - 1] == '/'|| yourans[i - 1] == '-'))
			continue;
		else
		{
			formflag = 0;
			break;
		}
	}
	return formflag;
}

/*将答案字符串转为数字*/
int turntonumber(char * yourans, int *ansnum)
{
	int pos = 0,sign=1;
	for (int i = 0; yourans[i] != '\0'; i++)
	{
		if (yourans[i] == '-')
			sign *= -1;
		if (yourans[i] >= '0'&&yourans[i] <= '9')
			ansnum[pos] = ansnum[pos] * 10 + yourans[i] - '0';
		else if (yourans[i] == '/')
		{
			pos++;
			ansnum[pos] = 0;
		}
	}
	return sign;
}