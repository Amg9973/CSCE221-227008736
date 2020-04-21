#include<iostream>
#include<climits>
#include <vector>
#include"MinHeap.h"
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    MinHeap h(arr, n);
	return h.findKthSmallest(k);
}

int main(){
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int* arr = new int[n];
    cout << "Enter n integers space separated: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Kth Smallest Integer: " << kthSmallest(arr, n, k) << endl;
    return 0;
}
