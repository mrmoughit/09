/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:15:34 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/18 11:05:39 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGRME_HPP
#define PMERGRME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime> 

template <typename T>
void print(std::string name, clock_t start, const T container) {
    if (name == "std::deque"){
        clock_t end = clock();
        double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << "Time to process a range of " << container.size() << " elements with " << name << ": " << duration << " us." << std::endl;
        return ;
    }
    std::cout << "after : " ;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << container.size() << " elements with " << name << ": " << duration << " us." << std::endl;
}

template <typename T>
void recursiveSort(T& container, int left, int right) {
    if (right - left + 1 <= 1) {
        return;
    }
    int pivot = container[right].first;
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (container[j].first <= pivot) {
            i++;
            std::swap(container[i], container[j]);
        }
    }
    std::swap(container[i + 1], container[right]);

    recursiveSort(container, left, i);
    recursiveSort(container, i + 2, right);
}

template <typename T>
void binarySearch(T& vec, int low, int high, int number) {
    int size = vec.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] <= number && (mid + 1 >= size || vec[mid + 1] > number)) {
            vec.insert(vec.begin() + mid + 1, number);
            return;
        }

        if (vec[mid] < number)
            low = mid + 1;
        else
            high = mid - 1;
    }
    vec.insert(vec.begin() + low, number);
}

template <typename T>
void swap_pairs(T& container){
    size_t  i = 0;
    while(i < container.size() -1){
        if(container[i].first > container[i].second)
        {
            int tmp = container[i].first ;
            container[i].first =  container[i].second;
            container[i].second = tmp;
        }
       i++;
    }
}

int is_digit(std::string str);
void fordJohnsonSort_vector(std::vector<int>& arr);
void fordJohnsonSort_deque(std::vector<int>& arr);
#endif