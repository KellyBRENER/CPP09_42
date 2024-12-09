/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:22 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/09 11:15:23 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr<<"error : RPN need one argument"<<std::endl;
		return 1;
	}
	std::string	ope("+-/*");
	size_t	length = std::strlen(argv[1]);
	RPN	rpn;//pour stocker les chiffres
	int	number = 0;//char converti en int puis envoye dans la stack
	int nb1 = 0;
	int nb2 = 0;
	for (size_t i = 0; i < length; ++i) {
		if (i % 2 == 1) {
			if (argv[1][i] != ' ') {
			std::cerr<<"the RPN argument have to be : int between 0 and 9 and operand \'+-*/\'"<<std::endl;
			return 1;
		}
		}
		else {
			if (std::isdigit(argv[1][i])) {
				number = argv[1][i] - '0';
				rpn._stack.push(number);
			}
			else if (ope.find(argv[1][i]) != std::string::npos) {//on a trouve l'un des operateur
				if (!rpn._stack.empty()) {
					nb2 = rpn._stack.top();
					rpn._stack.pop();
					if (!rpn._stack.empty()) {
						nb1 = rpn._stack.top();
						rpn._stack.pop();
					}
					else {
						std::cerr<<"not enough number to apply \'"<<argv[1][i]<<"\'"<<std::endl;
						return 1;
					}
				}
				else {
					std::cerr<<"not enough number to apply \'"<<argv[1][i]<<"\'"<<std::endl;
					return 1;
				}
				switch (argv[1][i])
				{
				case '+':
					number = nb1 + nb2;
					break;
				case '-':
					number = nb1 - nb2;
					break;
				case '/':
					number = nb1 / nb2;
					break;
				case '*':
					number = nb1 * nb2;
					break;
				}
				rpn._stack.push(number);
			}
			else {
				std::cerr<<"the RPN argument have to be : int between 0 and 9 and operand \'+-*/\'"<<std::endl;
				return 1;
			}
		}
	}
	number = rpn._stack.top();
	rpn._stack.pop();
	if (!rpn._stack.empty()) {
		std::cerr<<"too many number compared to operand, the ratio must be n numbers for n - 1 operand"<<std::endl;
		return 1;
	}
	std::cout<<"the result of RPN = "<<number<<std::endl;
	return 0;
}
