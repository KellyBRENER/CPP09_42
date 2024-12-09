/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:58:52 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/09 11:15:50 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>

#ifndef RPN_HPP
#define RPN_HPP

class RPN {

	public:

	std::stack<int>	_stack;

	RPN();
	RPN(RPN const& copy);
	~RPN();

	RPN&	operator=(RPN const& rhs);
	const std::stack<int>&	getStack() const;

};

#endif
