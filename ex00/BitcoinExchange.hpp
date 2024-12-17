/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:05 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/10 13:36:26 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>


class data{
    private:
        std::map<std::string, double> data;
    public:
        int check_input_file(char *str);
        void extra_check_andGet_value(std::string line);
        void get_value(std::string string);

};
int  check_value(std::string string);
int check_year(std::string string);
int check_month(std::string string);
int check_day(std::string string);
#endif