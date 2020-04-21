#include<iostream>
#include<climits>
#include"MinHeap.h"


int main(){
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
	//cout << "BEFORE EXTRACT MIN: " << endl;
	//h.printHeap();
	//cout << "SAMPLE OUTPUT 1: " << endl;
    cout << h.extractMin() << " "; 
	//cout << endl;
	//h.printHeap();
	//cout << "SAMPLE OUTPUT 2: " << endl;
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
	//cout << endl;
	//cout << "SAMPLE OUTPUT 3: " << endl;
    cout << h.getMin(); 
    cout << endl;
    return 0;
}
