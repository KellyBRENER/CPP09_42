/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:12:23 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/09 11:12:27 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const& copy) { *this=copy; }
RPN::~RPN() {}

RPN&	RPN::operator=(RPN const& rhs) {
	if (this != &rhs) {
		_stack = rhs.getStack();
	}
	return *this;
}

 const std::stack<int>&	RPN::getStack() const { return _stack; }
