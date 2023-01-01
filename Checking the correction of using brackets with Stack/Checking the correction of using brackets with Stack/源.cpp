#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;


bool WhetherbacketsBalance(string Express);
bool WhetherBalance(char Top,char current);

bool WhetherBalance(char Top, char current) {

	if (Top == '{' && current == '}') return true;
	else if (Top == '[' && current == ']') return true;
	else if (Top == '(' && current == ')') return true;
	else return false;
}

bool WhetherbacketsBalance(string Express){
	stack<char> Sstack;
	for (int ii = 0; ii < Express.length(); ii++) {
		if (Express[ii] == '{' || Express[ii] == '[' || Express[ii] == '(')
			Sstack.push(Express[ii]);

		else if (Express[ii] == '}' || Express[ii] == ']' || Express[ii] == ')') {
			if (Sstack.empty() || !WhetherBalance(Sstack.top(), Express[ii]))
				return false;
			else
				Sstack.pop();
		}
	}

	return Sstack.empty()? true:false;
}

int main() {
	string expression;	//定义一个测试字符串
	cout << "Enter an expression: ";	
	while (cin >> expression)	
	{
		if (WhetherbacketsBalance(expression))
			cout << "This expresstion using brackets is Ture！\n";
		else
			cout << "This expresstion using brackets is Not Balance！\n";

	}

}
