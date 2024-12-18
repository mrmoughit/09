/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:04:30 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/18 11:13:55 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int is_digit(std::string str){
    int size = str.size() -1;
    while(size){
        if (!std::isdigit(str[size]))
            return -1;
        size--;
    }
    return 0;
}

std::vector<int>   generateIndexes(std::vector<int> vec){
    std::vector<int> vector;
    for (std::size_t i = 3; i < vec.size(); i++){
        vector.push_back(vec[i]);
        int tmp = vec[i] -1;
        while(tmp > vec[i -1]){
            vector.push_back(tmp);
            tmp--;
        }
    }
    vector.insert(vector.begin() , 1);
    vector.insert(vector.begin() , 0);
    vector.push_back(0);
    return vector;
}

std::vector<int> JacobsthalSequence(int PainChainnSize) {
    std::vector<int> sequence;

    if (PainChainnSize > 0)
        sequence.push_back(0);
    if (PainChainnSize > 1)
        sequence.push_back(1);
    for (int i = 2; 1 ; ++i) {
        int next_value = sequence[i - 1] + (2 * sequence[i - 2]);
        if (next_value <= PainChainnSize){
            sequence.push_back(next_value);
            if (next_value == PainChainnSize)
                break;
        }
        else
            break ;
    }
    sequence = generateIndexes(sequence);
    return sequence;
}




void fordJohnsonSort_vector(std::vector<int>& arr)
{
    int last_number;
    bool pair = true;
    int n = arr.size();
    clock_t start = clock();
    std::cout << "before : " ;
    for (std::size_t i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    if (n <= 1){
        if (n == 1)
            print("std::vector" , start , arr);
        return;
    }
    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n / 2; ++i){
        pairs.push_back(std::make_pair(arr[2 * i], arr[2 * i + 1]));
    }
    if (n % 2 != 0) {
        last_number = arr[n - 1];
        pair = false;
    }
    swap_pairs(pairs);
    std::vector<int> main_chain;
    std::vector<int> pain_chain;
    recursiveSort(pairs , 0 , pairs.size() -1);
    

    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    while(it != pairs.end()){
        main_chain.push_back(it->first);
        pain_chain.push_back(it->second);
        ++it;
    }
    std::vector<int> indexes = JacobsthalSequence(arr.size());
    
    int s = pain_chain.size();
    for (std::size_t i = 0; i < indexes.size() -1 ; i++){
        if (indexes[i] < s)
            binarySearch(main_chain , 0 , main_chain.size() ,pain_chain[indexes[i]]);
    }
    if (!pair)
        binarySearch(main_chain , 0 , main_chain.size() , last_number);
    print("std::vector" , start , main_chain);
}







void fordJohnsonSort_deque(std::vector<int>& arr)
{
    int last_number;
    bool pair = true;
    int n = arr.size();
    clock_t start = clock();
    if (n <= 1){
        if (n == 1)
            print("std::deque" , start , arr);
        return;
    }
    std::deque<std::pair<int, int> > pairs;
    for (int i = 0; i < n / 2; ++i){
        pairs.push_back(std::make_pair(arr[2 * i], arr[2 * i + 1]));
    }
    if (n % 2 != 0) {
        last_number = arr[n - 1];
        pair = false;
    }
    swap_pairs(pairs);
    std::vector<int> main_chain;
    std::vector<int> pain_chain;
    recursiveSort(pairs , 0 , pairs.size() -1);
    

    std::deque<std::pair<int, int> >::iterator it = pairs.begin();
    while(it != pairs.end()){
        main_chain.push_back(it->first);
        pain_chain.push_back(it->second);
        ++it;
    }
    std::vector<int> indexes = JacobsthalSequence(arr.size());
    int s = pain_chain.size();
    for (std::size_t i = 0; i < indexes.size() -1 ; i++){
        if (indexes[i] < s)
            binarySearch(main_chain , 0 , main_chain.size() ,pain_chain[indexes[i]]);
    }
    if (!pair)
        binarySearch(main_chain , 0 , main_chain.size() , last_number);
    print("std::deque" , start , main_chain);
}