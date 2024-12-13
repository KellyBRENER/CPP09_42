/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:39:04 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/13 13:00:59 by kbrener-         ###   ########.fr       */
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
	PmergeMe	sort_class(argc, argv);
	std::list<int>	list = sort_class.getList();
	std::vector<int>	vector = sort_class.getVector();
	if (list.empty() || vector.empty())
		return 1;
	std::cout<<"initial list of unsigned int : ";
	for (size_t i = 0; i < vector.size(); ++i)
		std::cout<<vector[i]<<", ";
	std::cout<<std::endl;
	//calculer le temps avant
	vector = sort_class.vector_dispatch(vector);
	//calculer le temps après
	//calculer le temps avant
	list = sort_class.list_dispatch(list);
	//calculer le temps après
	std::cout<<"the final sorted list of unsigned int : ";
	for (size_t i = 0; i < vector.size(); ++i)
		std::cout<<vector[i]<<", ";
	std::cout<<std::endl;
	std::cout<<"sort numbers with vector container took "<<"msec"<<std::endl;
	std::cout<<"sort numbers with list container took "<<"msec"<<std::endl;
	return 0;
}
