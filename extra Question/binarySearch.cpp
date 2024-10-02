#include<iostream>
using namespace std;

int BinarySearch(int s,int e,int arr[],int target){
    
    while(s<=e){
        int mid = s + (e - s) / 2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            e = mid - 1;
        }
        else if(arr[mid]<target){
            s = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[10]={10,20,25,30,40,50,55,60,89,90};
    int s = 0;
    int e = 9;
    int target = 55;
    int result = BinarySearch(s, e, arr, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}