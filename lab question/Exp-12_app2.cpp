#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int missing_num(vector<int>&arr){
    int xor_full = 0;
    int n = arr.size();
    int xor_arr = 0;
    for (int i = 0; i <=n;i++){
        xor_full ^= i;
    }
    for (int i = 0; i < n;i++){
        xor_arr ^= arr[i];
    }
    return xor_full ^ xor_arr;
}
int main() {
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    cout << "Missing number: " << missing_num(arr) << endl;
    return 0;
}