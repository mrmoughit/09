#include "BitcoinExchange.hpp"


void data::extra_check_andGet_value(std::string line){
    if (check_year(line.substr(0 , 5)) > -1 && check_month(line.substr(5, 3)) > -1 && check_day(line.substr(8,3)) > -1 &&  check_value(line.substr(13 , line.size())) > -1){
        get_value(line);
    }
}