#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include "../homeworks-1/mergesort.h"

class Base {
    public:
        Base() {}
        virtual ~Base() {}
        virtual void foo(int t=20) {
            std::cout<<t<<std::endl;
        }
};

class D : public Base {
    public:
        virtual void foo(int t=100) {
            std::cout<<t<<std::endl;
        }
};

// class Person {

// };

/* 
Գրել std::sort-ի համար ֆունկցիա որը կսորտավորի սենց
1․ Զանգվածի առաջին կեսը զույգերը՝ մեծից փոքր
2․ Զանգվածի մյուս կեսը կենտերը՝ փոքրից մեծ
*/

bool func(int a, int b) {
    if( ( a >=0 && a % 2 == 0) && ( b >=0 && b % 2 == 0)) {
        return a > b;
    }
    if(a % 2 == 1 && b % 2 == 1) {
        return a < b;
    }
    return ( a >= 0 && a % 2 == 0);
}

// // STL -> Standart Template Library
int main() {
    // Base *obj = new D();
    // obj -> foo(); // 20, even when default value of t for D is 100.
    
    // D *ptr = new D();
    // ptr->foo(); // 100
    
    // // using cast, but this is unsafe
    // Base *b = new D();
    // ((D*)b)->foo(); // 100

    // Base* base = new Base();
    // base->foo(); // 20

    // std::vector<Person> v;
    std::vector<int> v2 {10, 2, 7, 6, 26, 34, 45, 72, 63};
    std::set<int> s2 {10, 2, 7, 9};
    std::list<int> l2 {10, 2, 7, 9};

    // for (auto& i : v2) {
    //     std::cout<< i <<" "; // 10 2 7 9
    // } 
    // std::cout<<std::endl;

    // s2.insert(-5);
    // for (auto& i : s2) {
    //     std::cout<< i <<" "; // -5 2 7 9 10
    // }
    // std::cout<<std::endl;

    
    // std::sort(v2.begin() , v2.begin() + v2.size()/2); // half-sort
    
    // std::sort(v2.rbegin() , v2.rend()); // descending sort
    
    // std::sort(v2.begin(), v2.end(), func); // full-sort
    merge_sort(v2, 0, v2.size() - 1, func); // merge sort by func logic
    for (auto& i : v2) {
        std::cout<< i <<" ";
    }
    std::cout<<std::endl;

    return 0;
}