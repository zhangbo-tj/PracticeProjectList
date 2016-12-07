#pragma once
enum ASSOTY{
	LEFT_ASSOCIVITY,
	RIGHT_ASSOCIVITY
};

enum OPERATOR{
	OPERATOR_NULL,
	OPERATOR_ADDITION,
	OPERATOR_SUBSTRACTION,
	OPERATOR_MULTIPLICATION,
	OPERATOR_DIVISION
};

class Operator
{
public:
	Operator(OPERATOR opr, int prec, ASSOTY associvity);
	~Operator();
	int getPrecedence() const;
	bool isNull() const;
	int calculate(int value1, int value2) const;
	bool isLeftAssociated() const;

private:
	//操作符
	OPERATOR p;

	//优先级
	int precedence;
	
	//操作符的关联性
	ASSOTY assoty;
};

