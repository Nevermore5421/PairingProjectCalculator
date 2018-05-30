#include"maped.h"
void changeintomaped(char * formula, int * maped)
{
	int temp = -1, pos = 0, flag = 0;
	for (int i = 0; formula[i] != '\0'; i++)
	{
		if (formula[i] == ' ')		//跳过空格
			continue;
		if (formula[i] >= '0'&&formula[i] <= '9')
		{
			if (temp == -1)			//数字可能为0，为碰到数字时将计数置为-1，碰到数字后开始
				temp = 0;
			temp *= 10;
			temp += formula[i] - '0';
		}
		else
		{
			if (temp != -1)			//在数字后遇到第一个非数字符号，将之前累加的数字置入
			{
				maped[pos++] = temp;
				temp = -1;
			}
			if (formula[i] == '+')
				maped[pos++] = 101;
			else if (formula[i] == '-')
				maped[pos++] = 102;
			else if (formula[i] == '*')			//称号后若第一个非空格字符为乘号则为乘方，否则为乘号
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