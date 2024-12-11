/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:51:09 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/10 13:04:33 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int __attribute__((unused))ac , char **av)
{
    data object;
    if (ac != 2)
        return (std::cout << "Error: could not open file." , 1);
    object.check_input_file(av[1]);
    // object.extra_parsing();
    
}