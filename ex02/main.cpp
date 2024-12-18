/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:16:11 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/18 11:13:53 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac , char **av) {
    if (ac < 2){
        std::cout << "Error" << std::endl; 
        return 1;
    }
    std::vector<int> vec;
    int value;
    std::string str;
    for (int i = 1; av[i] ; i++){
        str = av[i];
        if (is_digit(str)){
            std::cout << "Error  " << std::endl;
            return 1;
        }
        std::istringstream s(str);
        s >> value;
        if (s.fail()){
            std::cout << "Error  " << std::endl;
            return 1;
        }
        if (value < 0){
            std::cout << "Error " << std::endl; 
            return 1;
        }
        vec.push_back(value);
    }
    fordJohnsonSort_vector(vec);
    fordJohnsonSort_deque(vec);
    return 0;
}

