/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:39:04 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/13 11:22:27 by kbrener-         ###   ########.fr       */
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

/*parsing : no negatif number
			only integer*/
std::vector<unsigned int>	parsing(int argc, char **argv) {
	std::vector<unsigned int>	array(0);
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

std::vector<unsigned int>	sort_array(std::vector<unsigned int> left_array, std::vector<unsigned int> right_array, std::vector<unsigned int> array) {
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

std::vector<unsigned int>	sort(std::vector<unsigned int> array) {
	int lenght = array.size();
	if (lenght <= 1)
		return (array);
	else {
	int left_lenght = lenght / 2;
	int right_lenght = lenght - left_lenght;
	std::vector<unsigned int>	left_array(left_lenght);
	std::vector<unsigned int>	right_array(right_lenght);
	//répartition des nombres dans deux arrays
	for (int i = 0; i < lenght; ++i) {
		if (i < left_lenght) {
			left_array[i] = array[i];
		}
		else
			right_array[i - left_lenght] = array[i];
	}
	left_array = sort(left_array);
	right_array = sort(right_array);
	return sort_array(left_array, right_array, array);
	}
}

int	main(int argc, char **argv) {
	std::vector<unsigned int>	array = parsing(argc, argv);//vector ou list
	if (array.empty())
		return 1;
	std::cout<<"initial list of unsigned int : ";
	for (size_t i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	array = sort(array);
	std::cout<<"the final sorted list of unsigned int : ";
	for (size_t i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	return 0;
}
