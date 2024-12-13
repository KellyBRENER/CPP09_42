/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:39:04 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/13 12:26:27 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

unsigned int	ft_atoi(char* argv) {
	std::string	str = argv;

	std::stringstream ss(str);
	double nb;
	ss >> nb;
	if (nb < 0 || nb > std::numeric_limits<int>::max()) {
		std::cerr<<"argument have to be unsigned int"<<std::endl;
		return -1;
	}
	return nb;
}

int	main(int argc, char **argv) {
	std::vector<unsigned int>	array = parsing(argc, argv);//vector ou list
	if (array.empty())
		return 1;
	std::cout<<"initial list of unsigned int : ";
	for (size_t i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	array = dispatch(array);
	std::cout<<"the final sorted list of unsigned int : ";
	for (size_t i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	return 0;
}
