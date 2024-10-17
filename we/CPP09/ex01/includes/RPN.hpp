/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:52:14 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 19:55:25 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(str)				std::cout << RED << str << RESET "\n"
# define ERROR_WEIRD_SYMBOL(x)	ERROR("ERROR: unknown operation '" << x << "'")
# define ERROR_FEW_ARGS(x)		ERROR("ERROR: not enough args in stack to perform '" << x << "'")
# define ERROR_LEFTOVER			ERROR("ERROR: not all numbers were used")
# define ERROR_USAGE			ERROR("ERROR: ./RPN expression")

bool isOperation(char c);

bool isValidSymbol(char c);

void calculate(std::stack<int> &stack, char symbol);

bool parse(std::string expression);

#endif