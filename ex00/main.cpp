/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:44 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/02 16:29:15 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <fstream>
#include <vector>
#include "BitCoinExchange.hpp"
#include <algorithm>

bool	ft_checkDate(std::string const & read_line) {
	for (int i = 0; i < 10; ++i) {
		if (((i < 4 || i == 5 || i == 6 || i == 8 || i == 9) && !std::isdigit(read_line[i]))
		|| ((i == 4 || i == 7) && read_line[i] != '-')) {
			std::cerr<<"the format of the date must be \"YYYY-MM-DD\""<<std::endl;
			return false;//check si séparé par '-'
		}
	}
	int year = std::atoi(read_line.substr(0, 4).c_str());
	/*range à définir*/
	if (year < 1960 || year > 2024)//check if the date is comparable
		return false;
	int month = std::atoi(read_line.substr(5, 2).c_str());
	if (month < 0 || month > 12)
		return false;
	int day = std::atoi(read_line.substr(8, 2).c_str());
	std::vector<int>	short_month = {4, 6, 9, 11};
	if (day < 0 || day > 31 || (month == 2 && day > 28)
	|| (std::find(short_month.begin(), short_month.end(), month) == short_month.end() && day == 31)) {
		std::cerr<<"the data format is good but not the date value"<<std::endl;
		return false;
	}
	return true;
}
bool	ft_checkNumber(std::string const & read_line) {
	for (int i = 13; i < 21; ++i)//int ou float entre 0 et 1000, un float = 7 chiffre maxi
	{
		if (!std::isdigit(read_line[i]) && read_line[i])
	}
}
bool	ft_checkFormat(std::string const & read_line) {
	if (ft_checkDate(read_line) && read_line.compare(10, 3, " | ") != 0 && ft_checkNumber(read_line))
		return true;
	return false;
}

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr<<"btc programm need one file in argument"<<std::endl;
		return 1;
	}
	std::ifstream	infile_stream(argv[1]);
	if (!infile_stream.is_open()) {
		std::cerr<<"the programm cannot open "<<argv[1]<<std::endl;
		return 1;
	}
	std::string	read_line;//stock what is read in infile
	while (std::getline(infile_stream, read_line))//envoie le contenu jusqu'à \n dans read_line
	{
		if (!ft_checkFormat(read_line)) {
			std::cerr<<"one line in the infile don't respect the format : date(YYYY-MM-DD) | value(int or float between 0 to 1000)"<<std::endl;
			return 1;
		}
	}

}
