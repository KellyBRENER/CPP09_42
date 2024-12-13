/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:36:45 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/13 12:42:22 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

template <typename container>
container	parsing(int argc, char **argv) {
	container	array(0);
	if (argc < 3) {
		std::cerr<<"you have to give at least two numbers to sort"<<std::endl;
		array.erase(array.begin(), array.end());
		return array;
	}
	int i = 1;
	int	nb;
	while (i < argc)
	{
		for (int j = 0; argv[i][j]; ++j) {
			if (!std::isdigit(argv[i][j])) {
				std::cerr<<"only unsigned int are allowed"<<std::endl;
				array.erase(array.begin(), array.end());
				return array;
			}
		}
		nb = ft_atoi(argv[i]);
		if (nb == -1) {
			std::cerr<<"only positive number are allowed"<<std::endl;
			array.erase(array.begin(), array.end());
			return array;
		}
		if (std::find(array.begin(), array.end(), nb) != array.end()) {
			std::cerr<<"no duplicate are allowed"<<std::endl;
			array.erase(array.begin(), array.end());
			return array;
	}
		array.push_back(nb);
		i++;
	}
	return array;
}

#endif
