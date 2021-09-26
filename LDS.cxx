#include <iostream>
#include <vector>
#include <iterator>
#include <climits>
#include <ctime>
#include <chrono>

using vec_int = std::vector<int>;

int iter_LDS(vec_int vec) {

    int length = INT_MIN;
    vec_int sub(vec.size(),0);
    sub[0] = 1;
    for (int i = 1; i < vec.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[i] && sub[j] > sub[i])
                sub[i] = sub[j];
        }sub[i]++;
    }
 
    
    for (auto p : sub)
        length = std::max(length, p);
 
    return length;
}
 


int rec_LDS(vec_int vec, int i, int n, int prev) {

    if (i == n)
        return 0;

    int exclude = rec_LDS(vec, i + 1, n, prev);
    int include = 0;
    if (vec[i] < prev)
        include = 1 + rec_LDS(vec, i + 1, n, vec[i]);
 
    return std::max(include, exclude);
}
 
int main() {
    vec_int vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );

    for(auto p : vec)std::cout<<p<<" ";
    std::cout<<'\n';
    
    auto start1 = std::chrono::high_resolution_clock::now();
        std::cout << "iterative O(n^2) Longest Decreasing Subsequence = " << iter_LDS(vec) << '\n';
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bruteForce = end1 - start1;
    std::cerr << "iterative elapsed time[s] = " << bruteForce.count() << std::endl;
    std::cout<<"------------\n";
    auto start2 = std::chrono::high_resolution_clock::now();
        std::cout << "recursive O(2^n) Longest Decreasing Subsequence = " << rec_LDS(vec, 0, vec.size(), INT_MAX) <<'\n';
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> closest = end2 - start2;
    std::cerr << "recursive elapsed time[s] = " << closest.count() << std::endl;


    return 0;
}







