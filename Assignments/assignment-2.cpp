#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findMinInRotatedSortedArray(vector<int>&arr){
    sort(arr.begin(), arr.end());
    return arr[0];
}
int main(){
    vector<int> arr = {2, 7, 4, 23, 97, 4};
    int ans = findMinInRotatedSortedArray(arr);
    cout << "minimum element is: " << ans;
    return 0;
}
