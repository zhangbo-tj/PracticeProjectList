#pragma once

#include "Operator.h"

class OperatorValue
{
public:
	OperatorValue(const Operator& opr,int val);
	~OperatorValue();
	int getPrecedence() const;
	bool isNull() const;
	bool isLeftAssociated() const;
	int getValue() const;
	Operator& getOperator();

private:
	Operator op;
	int value;
};

