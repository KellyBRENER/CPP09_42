/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:33:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/13 12:31:26 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int argc, char** argv) {
	_list_array = list_parsing(argc, argv);
	_vector_array = vector_parsing(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe & src) {*this = src;}
PmergeMe &	PmergeMe::operator=(const PmergeMe & src) {
	if (this != &src) {
		_vector_array = src._vector_array;
		_list_array = src._list_array;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

std::list<int>	PmergeMe::list_dispatch(std::list<int> & array) {
	int lenght = array.size();
	if (lenght <= 1)
		return (array);
	int left_lenght = lenght / 2;
	int right_lenght = lenght - left_lenght;//not automatically equal to the half if number of numbers are odd
	std::list<int>	left_array(left_lenght);
	std::list<int>	right_array(right_lenght);
	for (int i = 0; i < lenght; ++i) {
		if (i < left_lenght)
			left_array.push_back(array.front());
		else
			right_array.push_back(array.front());
		array.pop_front();
	}
	left_array = list_dispatch(left_array);//in recursive until array of two numbers
	right_array = list_dispatch(right_array);
	return list_merge_sort(left_array, right_array, array);//sort the merge of two array already sorted

}
std::list<int>	PmergeMe::list_merge_sort(std::list<int> & left_array, std::list<int> & right_array, std::list<int> & array) {
	while (!left_array.empty() && !right_array.empty()) {
		if (left_array.front() < right_array.front()) {
			array.push_back(left_array.front());
			left_array.pop_front();
		}
		else {
			array.push_back(right_array.front());
			right_array.pop_front();
		}
	}
	while (!right_array.empty()) {
		array.push_back(right_array.front());
		right_array.pop_front();
	}
	while (!left_array.empty()) {
		array.push_back(left_array.front());
		left_array.pop_front();
	}
	return array;

}

//divide one array in two array (left and right) and dispatch numbers, half in each
std::vector<int>	PmergeMe::vector_dispatch(std::vector<int> & array) {
	int lenght = array.size();
	if (lenght <= 1)
		return (array);
	int left_lenght = lenght / 2;
	int right_lenght = lenght - left_lenght;//not automatically equal to the half if number of numbers are odd
	std::vector<int>	left_array(left_lenght);
	std::vector<int>	right_array(right_lenght);
	for (int i = 0; i < lenght; ++i) {
		if (i < left_lenght) {
			left_array[i] = array[i];
		}
		else
			right_array[i - left_lenght] = array[i];
	}
	left_array = vector_dispatch(left_array);//in recursive until array of two numbers
	right_array = vector_dispatch(right_array);
	return vector_merge_sort(left_array, right_array, array);//sort the merge of two array already sorted
}

//merge two array in one, numbers are insert by the smallest to the bigest
std::vector<int>	PmergeMe::vector_merge_sort(std::vector<int> & left_array, std::vector<int> & right_array, std::vector<int> & array) {
	unsigned int i = 0;
	unsigned int r = 0;
	unsigned int l = 0;
	while (l < left_array.size() && r < right_array.size()) {
		if (left_array[l] < right_array[r])
			array[i++] = left_array[l++];
		else
			array[i++] = right_array[r++];
	}
	while (r < right_array.size())
		array[i++] = right_array[r++];
	while (l < left_array.size())
		array[i++] = left_array[l++];
	return array;
}

/*parsing : only positif integer*/
std::vector<int>	PmergeMe::vector_parsing(int argc, char **argv) {
	std::vector<int>	array(0);
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
