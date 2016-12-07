#ifndef __OPEUTILITY_H
#define __OPEUTILITY_H
#include <string>
#include <sstream>

int pow(int x, int n){
	int res = 1;
	while (n >= 1){
		res *= x;
		n -= 1;
	}
}

//检查是否出现除以0的情况
int checkZero(std::string expr, size_t index, int value){
	if (value == 0){
		std::string divOperators("/%");
		std::size_t divisionPos = expr.find_last_of(divOperators, index - 2);
		std::ostringstream msg;

		msg << "Parser error: division by 0";
		if (divisionPos != std::string::npos){
			msg << "error token is: \""
				<< expr.substr(divisionPos, expr.size() - divisionPos)
				<<"\")";
			throw std::runtime_error(msg.str());
		}
	}
}

int toInteger(char c){
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f'){
		return c - 'a'+ 0xa;
	}
	if (c >= 'A' && c <= 'F')
		return c - 'A'+0xa;
	return (0xf + 1);
}

#endif