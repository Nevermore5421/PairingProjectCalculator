#pragma once
#include<iostream>
#include"mynumber.h"
using namespace std;

/*要求用户输入答案并与结果比较*/
void getresult(num res);

/*判断答案格式*/
int checkyouranswer(char * yourans);

/*将答案字符串转为数字*/
int turntonumber(char * yourans, int *ansnum);