#include"calculate.h"
#include<stack>
using namespace std;
extern int p;
num calculate(num num1, num num2, int opera)
{
	if (opera == 101)
		return num1 + num2;
	else if (opera == 102)
		return num1 - num2;
	else if (opera == 103)
		return num1*num2;
	else if (opera == 104)
		return num1 / num2;
	else if (opera == 105)
		return num1^num2;
}
num getans(int * operation)
{
	/*����������ӳ�䵽һ��ʮ��������0-100Ϊ��������
	101-104�ֱ����+��-��*��/��105Ϊ�˷���106Ϊ������,107Ϊ������*/
	stack <int> operators;
	stack <num> operand;
	for (int i = 0; i<p/*operation[i] != -1*/; i++)
	{
		if (operation[i] >= 0 && operation[i] <= 100)
		{
			num temp(operation[i]);
			operand.push(temp);
		}
		else if (operation[i] == 105 || operation[i] == 106)	//��������˷��ض���ջ
			operators.push(operation[i]);
		else if (operation[i] == 103 || operation[i] == 104)	//�˳��ᵯ���˷���˳�
		{
			while (!operators.empty() && (operators.top() == 103||operators.top() == 104|| operators.top() == 105))
			{
				int opera = operators.top();
				operators.pop();
				num num1 = operand.top();
				operand.pop();
				num num2 = operand.top();
				operand.pop();
				operand.push(calculate(num2, num1, opera));
			}
			operators.push(operation[i]);
		}
		else if (operation[i] == 101 || operation[i] == 102)		//�Ӽ����ܵ����˳���˷�
		{
			while (!operators.empty() && (operators.top() != 106 && operators.top() != 107))
			{
				int opera = operators.top();
				operators.pop();
				num num1 = operand.top();
				operand.pop();
				num num2 = operand.top();
				operand.pop();
				operand.push(calculate(num2, num1, opera));
			}
			operators.push(operation[i]);
		}
		else if (operation[i] == 107)				//�����Ż�һֱ����ֱ��������
		{
			while (operators.top() != 106)
			{
				int opera = operators.top();
				operators.pop();
				num num1 = operand.top();
				operand.pop();
				num num2 = operand.top();
				operand.pop();
				operand.push(calculate(num2, num1, opera));
			}
			operators.pop();
		}
	}
	while (!operators.empty())
	{
		int opera = operators.top();
		operators.pop();
		num num1 = operand.top();
		operand.pop();
		num num2 = operand.top();
		operand.pop();
		operand.push(calculate(num2, num1, opera));
	}
	return operand.top();
}