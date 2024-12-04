/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:53:52 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/04 10:55:18 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitCoinExchange.hpp"

bool	is_title(std::string const & line) {
	for (size_t i = 0; i < line.size(); ++i) {
		if (std::isdigit(line[i]))
			return false;
	}
	return true;
}
std::tm	collectTm(std::string const & line) {
	int year = std::atoi(line.substr(0, 4).c_str());
	int month = std::atoi(line.substr(5, 2).c_str());
	int day = std::atoi(line.substr(8, 2).c_str());

	std::tm	date;
	std::memset(&date, 0, sizeof(date));//initialise un tm pour y stocker la date à comparer
	date.tm_year = year - 1900;//année depuis 1900
	date.tm_mon = month - 1;//janvier = 0; decembre = 11
	date.tm_mday = day;
	return date;
}

float	collectValue(std::string const & line, int i) {
	int size = line.size() - i;
	float	value = std::atof(line.substr(i, size).c_str());
	return value;
}

bool	compareDate(tm const & date) {
	time_t	today = time(0);//recupere la date d'aujourd'hui
	tm	min_date;
	std::memset(&min_date, 0, sizeof(min_date));
	min_date.tm_year = 2009 - 1900;//2009
	min_date.tm_mon = 0;//janvier
	min_date.tm_mday = 2;//2
	time_t	min_time = mktime(const_cast<tm*>(&min_date));
	time_t	time_to_compare = mktime(const_cast<tm*>(&date));
	if (time_to_compare > min_time && time_to_compare < today)
		return true;
	return false;
}
