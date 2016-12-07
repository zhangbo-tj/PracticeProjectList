#include "OperatorValue.h"


OperatorValue::OperatorValue(const Operator& opr, int val)
	:op(opr), value(val)
{
}


OperatorValue::~OperatorValue()
{
}

int OperatorValue::getPrecedence() const{
	return op.getPrecedence();
}

bool OperatorValue::isNull() const{
	return op.isNull();
}

bool OperatorValue::isLeftAssociated() const{
	return op.isLeftAssociated();
}

int OperatorValue::getValue() const{
	return value;
}

Operator& OperatorValue::getOperator(){
	return op;
}