#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

vector<int> get_sizes(vector<int> input) {
    int n = input.size();
    vector<int> offsets(n);
    int offset = 0;
    for(int i=0;i<n;i++) {
        int s = input[i];
        while(offset % s != 0) {
            offset ++;
        }
        offsets[i] = offset;
        offset += s;
    }

    int max_align = 0;
    for(int i=0;i<n;i++) {
        if(input[i] > max_align) {
            max_align = input[i];
        }
    }
    while(offset % max_align != 0) {
        offset++;
    }
    cout<<"Total size: "<<offset<<endl;

    return offsets;
}

class C {
    char x;
    char y;
    int32_t a;
    int64_t b;
    char c;
    int8_t d;
};

int main() {
    vector<int> arr = {1,1,4,8,1,2};
    vector<int> res = get_sizes(arr);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<" "<<endl; 
    }
    cout<<"C size: "<<sizeof(C)<<endl;
    return 0;
}