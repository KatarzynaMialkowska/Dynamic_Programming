#include <iostream>
#include <vector>
#include <iterator>
#include "Stack.hxx"
#include <cstdio> 
#include <ctime>
#include <chrono>

using Vec = std::vector<std::vector<char>>;
using vec_char = std::vector<char>;
using vec_int = std::vector<int>;

int max_areaInHist(const vec_int &hist, const int &size) {
    Stack<int,1000000> s; 
    int max_area = 0, top, area_top, i = 0;

    while (i <= size) {
        if (s.empty() || hist[s.top()] <= hist[i]) s.push(i++); 
        else { 
            top = s.top();
            s.pop();
            area_top = hist[top] * ((s.empty())? i : (i-s.top()-1)); 
            if (area_top > max_area) max_area = area_top; 
        } 
    }
    while (!s.empty()) { 
        top = s.top(); 
        s.pop(); 
        area_top = hist[top] * ((s.empty())? i : (i-s.top()-1)); 
        if (area_top > max_area) max_area = area_top; 
    }

    return max_area; 
}

void countHist(const vec_char &cv, vec_int &v){
    for(int i = 0; i < cv.size(); i++){
        if(cv[i]=='1') ++v[i];
        else v[i] = 0;
    //std::cout<<v[i]<<" ";
    }//std::cout<<'\n';
       
}

int maxRect(Vec &A) {
    vec_int count(A.size(),0);
    countHist(A[0], count);
    int result = max_areaInHist(count, A[0].size());

    for (int i = 1; i < A.size(); i++) {
        countHist(A[i], count);
        result = std::max(result, max_areaInHist(count, A[0].size()));
        //std::cout<<"result: "<<result<<'\n';
    }

    return result;
}

int bruteRectArea(vec_int &hist) {
        int max_area = 0;
        for(int i = 0; i < hist.size(); i++) {
            int min_height = hist[i];
            max_area = std::max(max_area, min_height * 1);
            for(int j = i + 1; j < hist.size(); j++) {
                min_height = std::min(min_height, hist[j]);
                max_area = std::max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
}

int brute_maxRect(Vec &A) {
    int result = 0;
    vec_int count(A.size(),0);
    countHist(A[0], count);
    result = bruteRectArea(count);

    for(int i = 1; i < A.size(); i++) {
        countHist(A[i], count);
        result = std::max(result, bruteRectArea(count));    
    }

    return result;
}
 
int main() {

    int N, M; 
    char s;
    std::cin >> N;
    std::cin >> M;
    Vec A(N, vec_char(M)); 
    for(int i = 0; i < N; i++) {
         for(int j = 0; j < M; j++) {
            std::cin >> s;
            A[i][j] = s;  
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << '\n';
    }
    // std::cout << brute_maxRect(A) <<'\n';
    // std::cout << maxRect(A) <<'\n';
    auto start1 = std::chrono::high_resolution_clock::now();
        std::cout << "alg brute, the maximum area of the rectangle is = " << brute_maxRect(A) <<'\n';
    auto end1 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> bruteForce = end1 - start1;
    std::cerr << "bruteForce elapsed time[s] = " << bruteForce.count() << std::endl;
    std::cout<<"------------\n";
    auto start2 = std::chrono::high_resolution_clock::now();
        std::cout << "alg O(nm), the maximum area of the rectangle is = " << maxRect(A) <<'\n'; 
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> closest = end2 - start2;
    std::cerr << "maxRect elapsed time[s] = " << closest.count() << std::endl;

    return 0;
}