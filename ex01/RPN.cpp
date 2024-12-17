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

int is_operator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return 1;
    return 0;
}

int check_stack(std::stack<std::string> stack){
    bool nu = false;
    int number;
    while(!stack.empty()){
        std::string val = stack.top();
        stack.pop();
        std::istringstream s(val);
        s >> number;
        if (s.fail() && !is_operator(val[0])){
            std::cout << "Error1111 "<< val << std::endl;
            return 1;
        }
        else if (!s.fail()){
            if (number > 9){
                std::cout << "Error " << std::endl;
                return 1;
            }
        }
        else
            nu = true;
    }
    if (!nu)
        return 1;
    return 0;
}
int is_digits(std::string str){
    int len = str.size() -1;
    while(len >= 0)
    {
        if (!std::isdigit(str[len])){
            return 0;
        }
        len--;
    }
    return 1;
}
void rpn_cul(char *r)
{
    int len = 1;
    std::string str = r;
    if (str.size() < 1)
        return ;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (i > 0 && str[i - 1] != ' ') {
                str.insert(i, " ");
                i++;
            }
            if (i + 1 < str.size() && str[i + 1] != ' ') {
                str.insert(i + 1, " ");
                i++;
            }
        }
    }
    int v = str.size() -1;
    std::stack<std::string> stack;
    std::stack<double> stack_operation;
    for (int i = v; i >= 0 ; i--){
        for(int i = v; str[i] && str[i] == ' ' ; i--);
        if (std::isdigit(str[i]) || is_operator(str[i])){
            for (int j = 1; i >= 0 && (std::isdigit(str[i]) || is_operator(str[i]) ) ; j++){
                len = j;
                i--;
            }
            if (len == 1)
                i += len;
            else
                i += (len - (len -1));
            stack.push(str.substr(i ,len));
            len = 1;
        }
        else if (i >= 0 && str[i] != ' ' && str[i] != '+'  &&  str[i] != '-' &&  str[i] != '/' &&  str[i] != '*'){
            std::cerr << "Error "<< std::endl;
            return ;
        }
    }
    if (check_stack(stack))
        return ;
    int value;
    double one = 0;
    double two = 0;
    double result;
    while(!stack.empty()){
        if (!is_digits(stack.top())){
            if (stack_operation.size() < 2)
            {
                std::cerr << "Error " << std::endl;
                return ;
            }
            one = stack_operation.top();
            stack_operation.pop();
            two = stack_operation.top();
            stack_operation.pop();
            if (stack.top().size() == 1 && stack.top()[0] == '+')
                result = two + one;
            else if (stack.top().size() == 1 && stack.top()[0] == '-')
                result = two - one;
            else if (stack.top().size() == 1 && stack.top()[0] == '/'){
                if (one == 0){
                    std::cerr << "devision sur 0 Error " << std::endl;
                    return ;
                }
                result = two / one;
            }
            else if (stack.top().size() == 1 && stack.top()[0] == '*')
                result = two * one;
            else{
                std::cerr << "Error " << std::endl;
                return ;
            }

            stack_operation.push(result);
        }
        else{
            std::istringstream s(stack.top());
            s >> value;
            stack_operation.push(value);
        }
        stack.pop();
    }
    if (stack_operation.size() > 1)
        std::cerr << "Error " << std::endl;
    else
        std::cout << stack_operation.top() << std::endl;
}