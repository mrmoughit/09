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

int  check_value(std::multimap<std::string , std::string>::iterator start)
{
    int size = start->second.size() -1;
    while (size >= 0)
    {
        if (!std::isdigit(start->second[size]) && start->second[size] != '.'){
            std::cout << "the value must be digits" << std::endl;
            return -1;
        }
        size--;
    }
    float value;
    std::istringstream s(start->second);
    s >> value;
    if (s.fail())
    {
        std::cout << "kyn chi error" << std::endl;
        return -1;
    }
    if (value > 1000)
    {
        std::cout << "the valid value is 0-1000" << std::endl;
        return -1;
    }
    return 0;
}

int check_year(std::multimap<std::string , std::string>::iterator start)
{
    if (!std::isdigit(start->first[0]) || !std::isdigit(start->first[1]) || !std::isdigit(start->first[2]) || !std::isdigit(start->first[3]) || start->first[4] != '-')
    {
        std::cout << "the year must be a digits" << std::endl;
        return -1;
    }
    int year;
    std::istringstream s(start->first.substr(0,4));
    s >> year;
    if (s.fail())
    {
        std::cout << "errrorororor" << std::endl;
        return -1;
    }
    if (year > 2024)
    {
        std::cout << "year error " << std::endl;
        return -1;
    }
    return 0;
}

int check_month(std::multimap<std::string , std::string>::iterator start)
{
    if (!std::isdigit(start->first[5]) || !std::isdigit(start->first[6]) || start->first[7] != '-')
    {
        std::cout << "the month must be a digits" << std::endl;
        return -1;
    }
    int month;
    std::istringstream s(start->first.substr(5,7));
    s >> month;
    if (s.fail())
    {
        std::cout << "errrorororor" << std::endl;
        return -1;
    }
    if (month > 12 || month < 1)
    {
        std::cout << "month error "  << std::endl;
        return -1;
    }
    return 0;
}

int check_day(std::multimap<std::string , std::string>::iterator start)
{
    if (!std::isdigit(start->first[5]) || !std::isdigit(start->first[6]) || start->first[7] != '-')
    {
        std::cout << "the month must be a digits" << std::endl;
        return -1;
    }
    int day;
    std::istringstream s(start->first.substr(8,10));
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
    if (!input_file.is_open())
    {
        std::cout << "Invalid input file" << std::endl;
        return -1;
    }
    std::string line;
    std::getline(input_file , line);
    if (line.size() != 12 || "date" != line.substr(0 , 4) || "value" != line.substr(7 , line.size()))
    {
        std::cout << "Invalid input file content format " << std::endl;
        return -1;
    }
    while(std::getline(input_file , line))
    {
        if (line.size() >= 14 && line[10] == ' ' && line[11] == '|' && line[12] == ' ')
            input.insert(std::make_pair(line.substr(0 , 10) , line.substr(13 , line.size())));
        else{
            std::cout << "Invalid input file content format " << std::endl;
            return -1;
            //close zbal 
        }
    }
    // std::multimap<std::string, std::string >::iterator i = input.begin();
    // std::multimap<std::string, std::string >::iterator it = input.end();
    // while(i != it){
    //     std::cout << i->first << std::endl;
    //     ++i;
    // }
    std::ifstream data_file("data.csv");
    if (!data_file.is_open())
    {
        std::cout << "Invalid data file please make sure the file named data.csv" << std::endl;
        //close  
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
    return 0;
}

std::multimap<std::string , double>::iterator data::get_value(std::multimap<std::string , std::string>::iterator start)
{
    std::multimap<std::string , double>::iterator  it = data.begin();
    std::multimap<std::string , double>::iterator  d = data.begin();
    std::multimap<std::string , double>::iterator  iit = data.end();
    while(it != iit)
    {
        if (start->first == it->first)
            return it;
        ++it;
    }
    it = data.begin();
    ++it;
    while(it != iit){
        if (start->first.compare(it->first) < 0 && start->first.compare((d)->first) > 0){
            std::cout << start->first<< " " << d->first << std::endl;
            return d;
        }
        ++it;
        ++d;
    }
    return data.begin();
}
int data::extra_parsing()
{
    std::multimap<std::string , std::string>::iterator start  = input.begin();
    std::multimap<std::string , std::string>::iterator end  = input.end();
    while(start != end)
    {
        if (check_year(start) == -1 || check_month(start) == -1 || check_day(start) == -1 || check_value(start) == -1)
            return -1;
        ++start;
    }
    start = input.begin();
    double i;
    while(start != end)
    {
        std::istringstream s(start->second);
        s >> i;
        std::map<std::string , double >::iterator it = get_value(start);
        if (it == data.begin())
            std::cout << "sorry we dont have any data for this date " << std::endl;
        else{
            std::cout << start->first << " => " << start->second << " = " << i * it->second << std::endl;
        }
        ++start;
    }
    return 1;
}