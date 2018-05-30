#include "processyouranswer.h"
#include<cstring>

/*Ҫ���û�����𰸲������Ƚ�*/
void getresult(num res)
{
	char yourans[50];
	//cout << "������𰸣�";
	cin.getline(yourans, 50, '\n');
	int formflag = checkyouranswer(yourans);		//�жϴ𰸸�ʽ�Ƿ���ȷ
	if (formflag)
	{;								//sign����𰸷��ţ�ansnum[0]Ϊ���ӣ�[1]Ϊ��ĸ
		int ansnum[2] = { 0 , 1 };
		int sign = turntonumber(yourans, ansnum);		
		if (ansnum[1] != 0)							//�жϷ�ĸ�Ƿ�Ϊ0
		{
			num yourres(ansnum[0], ansnum[1], sign);
			if (yourres == res)
				cout << "Right" << endl;
			else
				cout << "Wrong" << endl;
		}
		else
			cout << "Math Error" << endl;
		cout << "��ȷ��Ϊ��";
		res.print();
	}
	else
		cout << "�����ʽ��ȷ�Ĵ�" << endl;
	cout << endl;
}

/*�жϴ𰸸�ʽ*/
int checkyouranswer(char * yourans)
{
	int flag[50] = {0},pos=0;
	for (int i = 0; yourans[i] == ' '; i++)		//ȥ��ǰ�ÿո�
		flag[i] = 1;
	while (yourans[pos])						//ȥ����������ո�
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
	for(int i=pos-1;i>=0&& yourans[i] == ' ';i--)		//ȥ�����ÿո�
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
	/*�жϸ�ʽ�����������ַ�,��2�������ϳ��ţ��򸺺�λ�ò���ȷ���ʽ����*/
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

/*�����ַ���תΪ����*/
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