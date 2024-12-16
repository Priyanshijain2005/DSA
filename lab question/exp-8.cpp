#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string first,string second){
        if(first+second>second+first){
            return true;
        }
        else{
            return false;
        }
    }
string displayMax(vector<int> &arr) {
    vector<string> strArr;
    for (int i = 0; i < arr.size(); i++) {
        strArr.push_back(to_string(arr[i]));
    }

    sort(strArr.begin(), strArr.end(),cmp);

    string str = "";
   
    for (int i = 0; i < strArr.size(); i++) {
       str += strArr[i];
    }

    return str;
}

int main() {
    vector<int> arr = {10, 8, 7, 30, 9, 52};
    cout << displayMax(arr);
    return 0;
}
