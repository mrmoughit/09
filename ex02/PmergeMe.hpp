/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:15:34 by abechcha          #+#    #+#             */
/*   Updated: 2024/12/17 12:12:02 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGRME_HPP
#define PMERGRME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime> 

template <typename T>
void print(std::string name, clock_t start, const T& container) {
    std::cout << "after : " ;
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Time to process a range of " << container.size() << " elements with " << name << ": " << duration << " us." << std::endl;
}

template <typename Container>
void recursiveSort(Container& container, int left, int right) {
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
#endif