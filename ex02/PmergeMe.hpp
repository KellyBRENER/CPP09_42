/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:39:22 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/16 10:55:03 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>
#include <ctime>

#ifndef PMERGEME
#define PMERGEME

class	PmergeMe {
	private:
	std::vector<int>	_vector_array;
	std::list<int>	_list_array;
	public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe & src);
	PmergeMe &	operator=(const PmergeMe & src);
	~PmergeMe();
	std::list<int>	getList() const;
	std::vector<int>	getVector() const;
	std::list<int>	list_dispatch(std::list<int> array);
	std::list<int>	list_merge_sort(std::list<int> left_array, std::list<int> right_array, std::list<int> array);
	std::vector<int>	vector_dispatch(std::vector<int> array);
	std::vector<int>	vector_merge_sort(std::vector<int> left_array, std::vector<int> right_array, std::vector<int> array);
};

unsigned int	ft_atoi(char* argv);

#endif


