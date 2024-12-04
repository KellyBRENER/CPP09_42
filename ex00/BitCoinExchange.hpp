/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:09 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/04 10:27:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstring>

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*struc à fournir à std::map pour comparer les dates au format tm et les mettres dans l'ordre croissant*/
// struct tmCompare {
//     bool operator()(const std::tm& lhs, const std::tm& rhs) const {
//         if (lhs.tm_year != rhs.tm_year) return lhs.tm_year < rhs.tm_year;
//         if (lhs.tm_mon != rhs.tm_mon) return lhs.tm_mon < rhs.tm_mon;
//         return lhs.tm_mday < rhs.tm_mday;
//     }
// };

//std::tm	collectTm(std::string const & line);
float	collectValue(std::string const & line, int i);
bool	compareDate(tm const & date);
void	print_map(std::map<std::string, float> & map);

class	BitCoinExchange {
	private:
		std::string	_current_line;
		std::string	_current_date;
		float	_current_value;
		std::map<std::string, float>	_tab_ref;
	public:
		BitCoinExchange();
		BitCoinExchange(BitCoinExchange const & src);
		BitCoinExchange &	operator=(BitCoinExchange const & src);
		~BitCoinExchange();
		void	addLine(std::string & line);
		bool	checkDate();
		bool	checkNumber();
		bool	checkFormat();
		void	calculChange();
		class	BtcException : public std::exception {
			private:
			std::string	_message;
			public:
				BtcException(std::string const & message) : _message(message) {}
				virtual ~BtcException()  throw() {}
				virtual const char*	what() const throw() {
					return _message.c_str();
				}
		};
};

#endif
