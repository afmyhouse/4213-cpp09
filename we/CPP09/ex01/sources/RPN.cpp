/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:56:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/16 16:56:34 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

bool isOperation(char c)
{
	return ((c == '-') || (c == '+') || (c == '*') || (c == '/'));
}

bool isValidSymbol(char c)
{
	return ((c >= '0' && c <= '9') || isOperation(c));
}

void calculate(std::stack<int> &stack, char symbol)
{
	int	first; 
	int	second;

	second = stack.top();
	stack.pop();
	first = stack.top();
	stack.pop();
	
	if (symbol == '+')
		stack.push(first + second);
	else if (symbol == '-')
		stack.push(first - second);
	else if (symbol == '*')
		stack.push(first * second);
	else
		stack.push(first / second);
	std::cout << first << symbol << second << "=" << stack.top() << std::endl;
}

bool parse(std::string expression)
{
	char				symbol;	
	std::stack<int>		stack;
	std::stringstream	stream(expression);

	while (stream >> symbol)
	{
		if (!isValidSymbol(symbol))
			return (ERROR_WEIRD_SYMBOL(symbol), false);
		if (isOperation(symbol) && stack.size() < 2)
			return (ERROR_FEW_ARGS(symbol), false);
		if (!isOperation(symbol))
		{
			stack.push(symbol - '0');
			continue;
		}
		else
			calculate(stack, symbol);
	}
	if (stack.size() != 1)
		return (ERROR_LEFTOVER, false);
	std::cout << stack.top() << std::endl;
	return (true);
}