/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:39:04 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/12 16:37:57 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

/*parsing : no negatif number
			only integer*/
std::vector<unsigned int>	parsing(int argc, char **argv) {
	if (argc < 3) {
		std::cerr<<"you have to give at least two numbers to sort"<<std::endl;
		return std::vector<unsigned int>();
	}
	int i = 1;
	while (i < argc)
	{
		for (int j = 0; argv[i][j]; ++j) {
			if (!std::isdigit(argv[i][j])) {
				std::cerr<<"only unsigned int are allowed"<<std::endl;
				return std::vector<unsigned int>();
			}
		}
		
	}

}

std::vector<unsigned int>	sort_array(std::vector<unsigned int> left_array, std::vector<unsigned int> right_array, std::vector<unsigned int> array) {
	int lenght = array.size();
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
	for (size_t i = 0; i < lenght; ++i) {
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
//une séquence d'entiers positif en argument
//utiliser l'algorithme de tri "merge-insert" pour trier les nombres
//algorithme ford-johnson
//utiliser au moins deux conteneurs
// gérer au moins 3000 entiers différents
//implémenter l'algorithme pour chaque conteneur
/*
résultats :
1ere ligne : texte explicite + séquences d'entiers positifs non triés
2eme ligne : texte explicite + séquence d'entiers triés
3eme ligne : texte explicite + temps utilisé par l'algo + conteneur utilisé
4eme ligne : idem pour le 2ème conteneur

pour tester le programme :
> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
permet de générer 3000 entiers pouvant aller de 1 à 100 000
*/
//on va séparer les nombres en paires de nombres
//on va trier chaque paire
//merger 2 paires
//comparer les plus petits de chaque paire pour sélectionner le + petit
//comparer le + grand de la 1ere paire avec le plsu petit de la seconde pour sélectionner le + petit
//puis comparer les deux derniers pour sélectionner le + petit puis le + grand
//puis comparer 2 paires merges avec 2 paires merges
//à chaque fois, on part des deux plus petits de chaque liste et on place le + petit dans une nouvelle liste
//puis on prends à nouveau les 2 plus petits et on sort le + petit des deux etc...
	std::vector<unsigned int>	array = parsing(argc, argv);//vector ou list
	if (array.empty())
		return 1;
	std::cout<<"initial list of unsigned int : ";
	for (int i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	array = sort(array);
	std::cout<<"the final sorted list of unsigned int : ";
	for (int i = 0; i < array.size(); ++i)
		std::cout<<array[i]<<", ";
	std::cout<<std::endl;
	return;
}
