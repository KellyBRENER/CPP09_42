/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:25:23 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/03 12:05:54 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange() {
	std::ifstream	infile("data.csv");
	if (!infile.is_open())
		throw BtcException("data.csv opening failed");
	while (std::getline(infile, _current_line)) {
		_tab_ref[collectTm(_current_line)] = collectValue(_current_line);
	}
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const & src) {
	*this = src;
}

BitCoinExchange::~BitCoinExchange() {}

BitCoinExchange &	BitCoinExchange::operator=(BitCoinExchange const & src) {
	if (this != &src) {
		_current_line = src._current_line;
		_current_value = src._current_value;
		_current_date = src._current_date;
		_tab_ref = src._tab_ref;
	}
	return *this;
}

void	BitCoinExchange::addLine(std::string & line) {
			_current_line = line;
		}

bool	BitCoinExchange::checkDate() {
	for (int i = 0; i < 10; ++i) {
		if (((i < 4 || i == 5 || i == 6 || i == 8 || i == 9) && !std::isdigit(_current_line[i]))
		|| ((i == 4 || i == 7) && _current_line[i] != '-')) {
			std::cerr<<"the format of the date must be \"YYYY-MM-DD\""<<std::endl;
			return false;//check si séparé par '-'
		}
	}
	int year = std::atoi(_current_line.substr(0, 4).c_str());
	/*range à définir*/
	if (year < 1970 || year > 2024)//check if the date is comparable
		return false;
	int month = std::atoi(_current_line.substr(5, 2).c_str());
	if (month < 0 || month > 12)
		return false;
	int day = std::atoi(_current_line.substr(8, 2).c_str());
	std::vector<int>	short_month = {4, 6, 9, 11};
	if (day < 0 || day > 31 || (month == 2 && day > 28)
	|| ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)) {
		std::cerr<<"the data format is good but not the date value"<<std::endl;
		return false;
	}
	/*date value*/
	std::tm	date_to_compare = collectTm(_current_line);
	if (compareDate(date_to_compare)) {
		std::cerr<<"the date is over min or max date"<<std::endl;
		return false;
	}
	_current_date = date_to_compare;
	return true;
}

bool	BitCoinExchange::checkNumber() {
	int size = 21;
	if (_current_line.size() > 21)
		return false;
	size = _current_line.size();
	for (int i = 13; i < size; ++i)//int ou float entre 0 et 1000, un float = 7 chiffre maxi
	{
		if (!std::isdigit(_current_line[i])) {
			if (_current_line[i] == '.' && (i == 13 || i == 20 || !std::isdigit(_current_line[i + 1])))
				return false;
			else if (_current_line[i] != '.')
				return false;
		}
	}
	float	value = std::atof(_current_line.substr(13, 7).c_str());
	if (value > 1000)
		return false;
	_current_value = value;
	true;
}

bool	BitCoinExchange::checkFormat() {
	if (checkDate() && _current_line.compare(10, 3, " | ") == 0 && checkNumber())
		return true;
	return false;
}

void	BitCoinExchange::calculChange() {
	std::map<std::tm, float, tmCompare>::iterator	it;
	it = _tab_ref.find(_current_date);
	float	change;
	if (it != _tab_ref.end())//on a trouvé la date exacte dans tab
		change = it->second * _current_value;
	else {
		it = _tab_ref.lower_bound(_current_date);
		it--;
	}
	std::cout<<_current_line.substr(0, 10)<<" => "<<_current_value<<" = "<<change<<std::endl;
}
