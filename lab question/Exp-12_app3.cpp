#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,-1);
        for(int i=0;i<n;i++){
            v[nums[i]]=nums[i];
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==-1)return i;
        }
        return 0;
    }
    int main() {
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    cout << "Missing number: " << missingNumber(arr) << endl;
    return 0;
}