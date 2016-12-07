#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
}

int Parser::evaluate(const std::string& _expr){
	int result = 0;
	index = 0;
	expr = _expr;

	result = parseExpr();
}

//获取当前字符
char Parser::getCharacter() const{
	if (!isEnd()){
		return expr[index];
	}
	return 0;
}

//判断是否已经解析完真个表达式
bool Parser::isEnd() const{
	return index >= expr.size();
}

//跳过表达式中的空格
void Parser::eatSpaces(){
	while (isspace(getCharacter()) != 0){
		index++;
	}
}

//解析操作符
Operator Parser::parseOperator(){
	eatSpaces();
	switch (getCharacter())
	{
	case '+':
		index++;
		return Operator(OPERATOR::OPERATOR_ADDITION, 10, ASSOTY::LEFT_ASSOCIVITY);
		break;
	case '-':
		index++;
		return Operator(OPERATOR::OPERATOR_DIVISION, 10, ASSOTY::LEFT_ASSOCIVITY);
		break;
	case '*':
		index++;
		if (getCharacter() != '*'){
			return Operator(OPERATOR::OPERATOR_MULTIPLICATION, 20, ASSOTY::LEFT_ASSOCIVITY);
		}
		break;
	case '/':
		index++;
		return Operator(OPERATOR::OPERATOR_SUBSTRACTION, 20, ASSOTY::LEFT_ASSOCIVITY);
	default:
		return Operator(OPERATOR::OPERATOR_NULL, 0, ASSOTY::LEFT_ASSOCIVITY);
		break;
	}
}

//计算得到运算的结果
int Parser::calculate(int v1, int v2, const Operator& op)const{
	return op.calculate(v1, v2);
}

//解析数字
int Parser::parseDecimal(){
	int value = 0;
	for (int d; (d = toInteger(getCharacter())) <= 9; index++){
		value = value * 10 + d;
	}
	return value;
}


int Parser::parseValue(){
	int val = 0;
	eatSpaces();
	switch (getCharacter())
	{
	case '0':	case '1':	case '2':	case '3':	case '4':
	case '5':	case '6':	case '7':	case '8':	case '9':
		val = parseDecimal();
		break;
	case '(':
		index++;
		val = parseExpr();
		eatSpaces();
		if (getCharacter() != ')'){
			if (!isEnd()){
				throw std::runtime_error("')' expected at end of the expression");
			}
		}
		index++;
		break;
	case '~':
		index++;
		val = ~parseValue();
		break;
	case '+':
		index++;
		val = parseValue();
		break;
	case '-':
		index++;
		val = parseValue() * -1;
		break;
	default:
		throw std::runtime_error("value expected at end of the expression");
		break;
	}
	return val;
}

int Parser::parseExpr(){
	opevalStack.push(OperatorValue(Operator(OPERATOR::OPERATOR_NULL, 0, ASSOTY::LEFT_ASSOCIVITY), 0));
	int value = parseValue();
	while (!opevalStack.empty()){
		Operator tempOp(parseOperator());
		while (tempOp.getPrecedence() < opevalStack.top().getPrecedence() ||
			tempOp.getPrecedence() == opevalStack.top().getPrecedence() && tempOp.isLeftAssociated()){
			if (opevalStack.top().isNull()){
				opevalStack.pop();
				return value;
			}
			value = calculate(opevalStack.top().getValue(), value, opevalStack.top().getOperator());
			opevalStack.pop();
		}
		opevalStack.push(OperatorValue(tempOp, value));
		value = parseValue();
	}
	return 0;
}