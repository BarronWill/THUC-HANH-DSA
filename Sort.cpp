#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

const int mx = 10000;
const int size_graph = 9;

void bubble_sort(int arr[],int sz){
    for(int i = 1; i < sz; i++)
            for(int j = sz - 1; j>=i; j--){
                if(arr[j] < arr[j-1])
                    swap(arr[j], arr[j-1]);
            }
}

void insert_sort(int arr[], int sz){
    for(int i =1 ;i<sz; i++)
        for(int j = i; j>0; j --){
            if(arr[j]<arr[j-1])
                swap(arr[j], arr[j-1]);
    }
}

void selection_sort(int arr[],int sz){
    for(int i = 0; i < sz-1; i++){
        int k = i;
        for(int j = i+1; j < sz; j++)
            if(arr[j] < arr[k])   k=j;
        swap(arr[i], arr[k]);
    }
}

void mergex(int arr[], const int left, const int mid, const int right){
    int b[right-left+1];
    int b_count = 0;
    int lcount = left;
    int rcount = mid + 1;
    while((lcount <= mid) && (rcount <= right)){
        if(arr[lcount] <= arr[rcount])
            b[b_count++] = arr[lcount++];
        else
            b[b_count++] = arr[rcount++];
    }
    if(lcount > mid)
        while(rcount <= right)
            b[b_count++] = arr[rcount++];
    else
        while(lcount <= mid)
            b[b_count++] = arr[lcount++];
    for(b_count = 0; b_count < right-left+1; b_count++)
        arr[left+b_count] = b[b_count];
}

void merge_sort(int arr[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        mergex(arr, left, mid, right);
    }
}

int search_machine(int arr[], int sz, int n){
    int left = 0;
    int right = sz - 1;
    while(left < right){
        int mid = (left + right)/2;
        if(arr[mid] < n) left = mid+1;
        else right =mid;
    }
    if(arr[left] == n)  return left;
    return -1;
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7 };
    int sz = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, sz - 1); // Corrected the range of indices
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
