#include"maped.h"
void changeintomaped(char * formula, int * maped)
{
	int temp = -1, pos = 0, flag = 0;
	for (int i = 0; formula[i] != '\0'; i++)
	{
		if (formula[i] == ' ')		//�����ո�
			continue;
		if (formula[i] >= '0'&&formula[i] <= '9')
		{
			if (temp == -1)			//���ֿ���Ϊ0��Ϊ��������ʱ��������Ϊ-1���������ֺ�ʼ
				temp = 0;
			temp *= 10;
			temp += formula[i] - '0';
		}
		else
		{
			if (temp != -1)			//�����ֺ�������һ�������ַ��ţ���֮ǰ�ۼӵ���������
			{
				maped[pos++] = temp;
				temp = -1;
			}
			if (formula[i] == '+')
				maped[pos++] = 101;
			else if (formula[i] == '-')
				maped[pos++] = 102;
			else if (formula[i] == '*')			//�ƺź�����һ���ǿո��ַ�Ϊ�˺���Ϊ�˷�������Ϊ�˺�
			{
				int j;
				for (j = i + 1; formula[j] == ' '; j++);
				if (formula[j] == '*')
				{
					maped[pos++] = 105;
					i = j;
				}
				else
					maped[pos++] = 103;
			}
			else if (formula[i] == '/')
				maped[pos++] = 104;
			else if (formula[i] == '^')
				maped[pos++] = 105;
			else if (formula[i] == '(')
				maped[pos++] = 106;
			else if (formula[i] == ')')
				maped[pos++] = 107;
		}
	}
	if (temp != -1)
	{
		maped[pos++] = temp;
		temp = -1;
	}
}