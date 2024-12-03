/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:44 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/03 12:08:23 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <fstream>
#include <vector>
#include <ctime>
#include "BitCoinExchange.hpp"
#include <algorithm>

/*check le .csv / empty file */

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
	BitCoinExchange	btc;
	std::string	read_line;//stock what is read in infile
	while (std::getline(infile_stream, read_line))//envoie le contenu jusqu'à \n dans read_line
	{
		btc.addLine(read_line);
		if (btc.checkFormat())
			btc.calculChange();
	}
}
