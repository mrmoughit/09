/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:07 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/10 14:13:23 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int  check_value(std::string string)
{
    int size = string.size() -1;
    if (string[size] == '.')
    {
        std::cout << "invalid value "<< string << std::endl;
        return -1;
    }
    while (size >= 0)
    {
        if (string[size -1] && string[size] == '.' && string[size-1] == '.'){
            std::cout << "invalid value "<< string << std::endl;
            return -1;
        }
        if (!std::isdigit(string[size]) && string[size] != '.' && string[size] != '-'){
            std::cout << "the value must be digits" << std::endl;
            return -1;
        }
        size--;
    }
    float value;
    std::istringstream s(string);
    s >> value;
    if (s.fail())
    {
        std::cout << "kyn chi error" << std::endl;
        return -1;
    }
    if (value > 1000 || value < 0)
    {
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else
            std::cout << "Error: too large a number." << std::endl;
        return -1;
    }
    return 0;
}

int check_year(std::string string)
{
    if (!std::isdigit(string[0]) || !std::isdigit(string[1]) || !std::isdigit(string[2]) || !std::isdigit(string[3]) || string[4] != '-')
    {
        std::cout << "the year must be a digits" << std::endl;
        return -1;
    }
    int year;
    std::istringstream s(string);
    s >> year;
    if (s.fail())
    {
        std::cout << "errrorororor" << std::endl;
        return -1;
    }
    if (year < 2009 || year > 2023)
    {
        std::cout << "year error " << std::endl;
        return -1;
    }
    return 0;
}

int check_month(std::string string)
{
    if (!std::isdigit(string[0]) || !std::isdigit(string[1]) || string[2] != '-')
    {
        std::cout << "the month must be a digits" << std::endl;
        return -1;
    }
    int month;
    std::istringstream s(string);
    s >> month;
    if (s.fail()){
        std::cout << "errrorororor" << std::endl;
        return -1;
    }
    if (month > 12 || month < 1){
        std::cout << "invalid month"  << std::endl;
        return -1;
    }
    return 0;
}

int check_day(std::string string)
{
    if (!std::isdigit(string[0]) || !std::isdigit(string[1]))
    {
        std::cout << "the month must be a digits" << std::endl;
        return -1;
    }
    int day;
    std::istringstream s(string);
    s >> day;
    if (s.fail())
    {
        std::cout << "errrorororor" << std::endl;
        return -1;
    }
    if (day > 31 || day < 1)
    {
        std::cout << "day error " << std::endl;
        return -1;
    }
    return 0;
}

int data::check_input_file(char *str){
    std::ifstream input_file(str);
    if (!input_file.is_open()){
        std::cout << "Invalid input file" << std::endl;
        return -1;
    }
    std::string line;
    std::ifstream data_file("data.csv");
    if (!data_file.is_open()){
        std::cout << "Invalid data file please make sure the file named data.csv" << std::endl;
        return -1;
    }
    std::getline(data_file , line);
    double value;
    while(std::getline(data_file , line))
    {
        std::istringstream s(line.substr(11 , line.size()));
        s >>  value;
        data.insert(std::make_pair(line.substr(0 , 10) , value));

    }
    std::getline(input_file , line);
    if (line.size() != 12 || "date" != line.substr(0 , 4) || "value" != line.substr(7 , line.size()))
    {
        std::cout << "Invalid input file content format " << std::endl;
        return -1;
    }
    while(std::getline(input_file , line))
    {
        if (line.size() >= 14 && line[10] == ' ' && line[11] == '|' && line[12] == ' ' && (std::isdigit(line[13]) || line[13] == '-')){
            extra_check_andGet_value(line);
        }
        else{
            std::cout << "Error: bad input "<< line << std::endl;
        }
    }
    return 0;
}

void data::get_value(std::string line)
{
    if (line.substr(0 , 4) == "2009" && line.substr(5, 2) == "01" && line.substr(8,2) == "01"){
        std::cout << "Invalid date" << std::endl;
        return ;
    }
    if (line.substr(5, 2) == "02" && line.substr(8,2) > "29"){
        std::cout << "Invalid date " << std::endl;
        return ;
    }
    std::string string= line.substr(0,10); 
    std::multimap<std::string , double>::iterator  it = data.begin();
    std::multimap<std::string , double>::iterator  d = data.begin();
    std::multimap<std::string , double>::iterator  iit = data.end();
    double value;
    while(it != iit)
    {
        if (string == it->first){
            std::istringstream s(line.substr(13, line.size()));
            s >> value;
            std::cout  << string << " => "  << line.substr(13, line.size()) << " = " <<value * it->second << std::endl;
            return ;
        }
        ++it;
    }
    it = data.begin();
    ++it;
    while(it != iit){
        if (string.compare(it->first) < 0 && string.compare(d->first) > 0){
            std::istringstream s(line.substr(13, line.size()));
            s >> value;
            std::cout  << string << " => "  << line.substr(13, line.size()) << " = "<< value * d->second << std::endl;
            return ;
        }
        ++it;
        ++d;
    }
    std::istringstream s(line.substr(13, line.size()));
    s >> value;
    std::cout  << string << " => "  << line.substr(13, line.size()) << " = "<< value * d->second << std::endl;
}
