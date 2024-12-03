/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:53:52 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/03 11:55:57 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitCoinExchange.hpp"

std::tm	collectTm(std::string const & line) {
	int year = std::atoi(line.substr(0, 4).c_str());
	int month = std::atoi(line.substr(5, 2).c_str());
	int day = std::atoi(line.substr(8, 2).c_str());

	std::tm	date = {0};//initialise un tm pour y stocker la date à comparer
	date.tm_year = year - 1900;//année depuis 1900
	date.tm_mon = month - 1;//janvier = 0; decembre = 11
	date.tm_mday = day;
	return date;
}

float	collectValue(std::string const & line) {
	int size = line.size() - 13;
	float	value = std::atof(line.substr(13, size).c_str());
	return value;
}

bool	compareDate(tm const & date) {
	time_t	today = time(0);//recupere la date d'aujourd'hui
	tm	min_date = {0};
	min_date.tm_year = 0;//1900
	min_date.tm_mon = 0;//janvier
	min_date.tm_mday = 1;//1er
	time_t	min_time = mktime(const_cast<tm*>(&min_date));
	time_t	time_to_compare = mktime(const_cast<tm*>(&date));
	if (time_to_compare > min_time && time_to_compare < today)
		return true;
	return false;
}
