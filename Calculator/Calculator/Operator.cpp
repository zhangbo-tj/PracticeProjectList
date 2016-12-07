#include "Operator.h"


Operator::Operator(OPERATOR opr, int prec, ASSOTY associvity)
	:p(opr), precedence(prec), assoty(associvity)
{
}


Operator::~Operator()
{
}

int Operator::getPrecedence() const{
	return precedence;
}

bool Operator::isNull() const{
	return p == OPERATOR::OPERATOR_NULL;
}

int Operator::calculate(int value1, int value2) const{
	switch (p)
	{
	case OPERATOR_NULL:
		break;
	case OPERATOR_ADDITION:
		return value1 + value2;
		break;
	case OPERATOR_SUBSTRACTION:
		return value1 - value2;
		break;
	case OPERATOR_MULTIPLICATION:
		return value1 * value2;
		break;
	case OPERATOR_DIVISION:
		return value1 / value2;
		break;
	default:
		break;
	}
}

bool Operator::isLeftAssociated() const{
	return assoty == ASSOTY::LEFT_ASSOCIVITY;
}