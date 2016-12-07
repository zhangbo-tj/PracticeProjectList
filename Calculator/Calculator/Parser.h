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

	//�Ա��ʽ������ֵ
	int evaluate(const std::string& expr);

	//�ж��Ƿ�������������ʽ
	bool isEnd() const;

	//�������ַ�
	void eatSpaces();

	//��ȡ��ǰ�ַ�
	char getCharacter() const;

	//����������
	Operator parseOperator();

	//��������
	int parseDecimal();

	//����ֵ
	int parseValue();

	//�������ʽ
	int parseExpr();

	//�������ֵ
	int calculate(int v1, int v2, const Operator& op)const;

private:
	std::string expr;
	//���ʽ������ֵ
	std::size_t index;
	//������ջ
	std::stack<OperatorValue> opevalStack;
};

