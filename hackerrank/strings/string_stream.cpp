#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> result;
    int number;
    char for_comma;
    while(ss >> number) {
        result.push_back(number); 
        ss >> for_comma;
    }
    return result;
}

template <class T>
void print_vector(vector<T> v) {
    cout<<"Your vector: "<<endl;
    for(int i=0;i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    string s = "23,4,56,4781";
    vector<int> x = parseInts(s);
    print_vector(x);
    return 0;
}