#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int>   generateOrderIndexes(std::vector<int> vec){
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
std::vector<int> generateJacobsthalSequence(int PainChainnSize) {
    std::vector<int> sequence;

    if (PainChainnSize > 0) sequence.push_back(0);
    if (PainChainnSize > 1) sequence.push_back(1);
    for (int i = 2; 1 ; ++i) {
        int next_value = sequence[i - 1] + 2 * sequence[i - 2];
        if (next_value <= PainChainnSize){
            sequence.push_back(next_value);
            if (next_value == PainChainnSize)
                break;
        }
        else
            break ;
    }
    sequence = generateOrderIndexes(sequence);
    return sequence;
}

void recursiveSortByFirst(std::vector<std::pair<int, int> >& vec, int left, int right) {
    if (right - left + 1 <= 1) {
        return;
    }
    int pivot = vec[right].first;
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (vec[j].first <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[right]);

    recursiveSortByFirst(vec, left, i);
    recursiveSortByFirst(vec, i + 2, right);
}

void binarySearch(std::vector<int>& vec, int low, int high, int number) {
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
void fordJohnsonSort(std::vector<int>& arr)
{
    int last_number ;
    bool pair = true;
    int n = arr.size();
    if (n <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n / 2; ++i){
        pairs.push_back(std::make_pair(arr[2 * i], arr[2 * i + 1]));
    }
    if (n % 2 != 0) {
        last_number = arr[n - 1];
        pair = false;
    }
    std::vector<std::pair<int, int> >::iterator it = pairs.begin();
    while(it != pairs.end()){
        if(it->first > it->second)
        {
            int tmp = it->first ;
            it->first =  it->second;
            it->second = tmp;
        }
        ++it;
    }

    std::vector<int> main_chain;
    std::vector<int> paind_chain;
    recursiveSortByFirst(pairs , 0 , pairs.size() -1);

    it = pairs.begin();
    while(it != pairs.end()){
        main_chain.push_back(it->first);
        paind_chain.push_back(it->second);
        ++it;
    }
    std::vector<int> indexes= generateJacobsthalSequence(arr.size());
    for  (int i = 0; indexes[i] ; i++){
        std::cout << indexes[i] << " " ;
    }
    int s = paind_chain.size();
    for (std::size_t i = 0; i < indexes.size() -1 ; i++){
        if (indexes[i] < s)
            binarySearch(main_chain , 0 , main_chain.size() ,paind_chain[indexes[i]]);
    }
    if (!pair)
        binarySearch(main_chain , 0 , main_chain.size() , last_number);
    std::vector<int>::iterator tt = main_chain.begin();
    while(tt != main_chain.end()){
        std::cout << *tt << " ";
        ++tt;
    }
}

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
        std::istringstream s(str);
        s >> value;
        if (s.fail()){
            std::cout << "Error  " << std::endl;
            return 1;
        }
        vec.push_back(value);
    }
    fordJohnsonSort(vec);
    return 0;
}
