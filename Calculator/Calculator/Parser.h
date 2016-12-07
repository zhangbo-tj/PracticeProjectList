#pragma once
#include<string>
#include <stack>
#include <cctype>
#include "OperatorValue.h"
#include "opeutility.h"

class Parser
{
public:
	Parser();
	~Parser();

	//对表达式进行求值
	int evaluate(const std::string& expr);

	//判断是否解析完整个表达式
	bool isEnd() const;

	//跳过空字符
	void eatSpaces();

	//获取当前字符
	char getCharacter() const;

	//解析操作符
	Operator parseOperator();

	//解析数字
	int parseDecimal();

	//解析值
	int parseValue();

	//解析表达式
	int parseExpr();

	//计算操作值
	int calculate(int v1, int v2, const Operator& op)const;

private:
	std::string expr;
	//表达式的索引值
	std::size_t index;
	//操作数栈
	std::stack<OperatorValue> opevalStack;
};

