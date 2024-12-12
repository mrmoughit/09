/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:05:59 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/12 10:06:27 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void rpn_cul(char *r)
{
    int len = 1;
    std::string str = r;
    int value = 4;
    std::stack<int> stack;
    for (int i = 0; str[i] ; i++){
        for(int i = 0; str[i] && str[i] == ' ' ; i++);
        if (std::isdigit(str[i])){
            for (int j = 1; str[i] && std::isdigit(str[i]) ; j++){
                len = j;
                i++;
            }
            i -= len;
            std::istringstream s(str.substr(i , len));
            s >> value;
            len = 1;
            stack.push(value);
        }
        // else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*');
        // else:
            // std::cerr << "Error"  << str[i]<< std::endl;
    }
    for (int i = 7 ; i > 0 ; i--){
        std::cout << stack.top() << std::endl;
        stack.pop();

    }
}