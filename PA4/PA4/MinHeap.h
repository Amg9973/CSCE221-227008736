#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>
using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }
	
	
	// Build the heap in linear time
	MinHeap(int* arrPassed, int sz){
		//cout << endl << "Starting correct constructor" << endl;
		int size = sz;
		arr = new int[size + 10];
		capacity = size;
		for (int i = 0; i < size; ++i){
			arr[i] = arrPassed[i];
		}
		heap_size = size;
		//cout << "Calling buildHeap" << endl;
		this->buildHeap();
		//cout << "MinHeap completed" << endl;
	}

	void buildHeap(){
		//cout << "HEAP SZ = " << heap_size << endl;
		for (int i = heap_size / 2; i >= 0; --i){
			//cout << "Calling percDown iteration: " << i << endl;
			percDown(i);
			//cout << "next i: " << i-1 << endl;
		}
		//cout << "buildHeap completed" << endl;
	}
	
	void percDown(int hole){
		int child;
		int tmp = std::move( arr[ hole ] );
		
		for( ; hole * 2 < heap_size - 1; hole = child )
		{
			//this->printHeap();
			//cout << "hole: " << hole << endl;
			//cout << "Heap sz = " << heap_size << endl;
			//cout << "tmp = " << tmp << endl;
			child = left( hole );
			//cout << "left(hole) idx = " << child << endl;
			//cout << "left = " << arr[child] << " right = " << arr[child+1] << endl;
			if( child != heap_size - 1 && arr[ child + 1 ] < arr[ child ] ){
				//cout << "child incremented " << endl;
				++child;
			}
			if( arr[ child ] < tmp ){
				arr[ hole ] = std::move( arr[ child ] );
			}
			else{
				break;
				//cout << "Heap after percDown iter: " << endl;
			}
		}
		arr[ hole ] = std::move( tmp );
		//cout << "Heap after percDown call: " << endl;
		//this->printHeap();
		//cout << endl << endl;
	}
	
	int findKthSmallest(int k){
		/*int leftToFind = k;
		int old = 0;
		int leftCurr;
		int rightCurr;
		while (k != 0){
			if (leftToFind = k){
				k -= 1;
				leftCurr = left(curr);
				rightCurr = right(curr);
				if (leftCurr < rightCurr){
					
				}
			}
			else{
				if (leftCurr < rightCurr){
					
				}
			}
		}
		*/
		//cout << endl << "Finding kth Smallest..." << endl;
		//this->printHeap();
		for (int i = 0; i < k-1; i++){
			this->deleteKey(0);
		}
		return arr[0];
	}

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
        if (heap_size == 0){
			arr[0] = k;
		}
		else{
			bool inserted = false;
			int currPos = heap_size;
			if (k > arr[parent(heap_size)]){
				arr[heap_size] = k;
			}
			while (!inserted){
				//cout << k << " is being compared against " << arr[parent(currPos)] << endl;
				//cout << "Current position is " << currPos << endl;
				//cout << "Parent of current position is: " << parent(currPos) << endl;
				if (k >= arr[parent(currPos)] || currPos == 0){
					arr[currPos] = k;
					inserted = true;
				}
				else{
					arr[currPos] = arr[parent(currPos)];
					currPos = parent(currPos);
				}
			}
		}
		heap_size += 1;
    }

    // Extract the root which is the minimum element 
    int extractMin() {
		if (heap_size == 0){
			return -1;
		}
		else if (heap_size == 1){
			int lastNum = arr[0];
			delete arr;
			arr = new int[capacity];
			return lastNum;
		}
		else{
			int min = arr[0];
			heap_size -= 1;
			int currLeftLoc = 1;
			int currRightLoc = 2;
			int numToMove = arr[heap_size];
			bool complete = false;
			while (!complete){
				//cout << "Current left loc = " << currLeftLoc << endl;
				//cout << "Value is " << arr[currLeftLoc] << endl;
				//cout << "Current right loc = " << currRightLoc << endl;
				//cout << "Value is " << arr[currRightLoc] << endl;
				//cout << "Num to move = " << numToMove << endl;
				//this->printHeap();
				if ((arr[currLeftLoc] <= numToMove && arr[currLeftLoc] <= arr[currRightLoc]) && currLeftLoc < heap_size){
					arr[parent(currLeftLoc)] = arr[currLeftLoc];
					arr[currLeftLoc] = -1;
					currRightLoc = right(currLeftLoc);
					currLeftLoc = left(currLeftLoc);
				}
				else if ((arr[currRightLoc] <= numToMove && arr[currRightLoc] <= arr[currLeftLoc]) && currLeftLoc < heap_size){
					arr[parent(currRightLoc)] = arr[currRightLoc];
					arr[currRightLoc] = -1;
					currLeftLoc = left(currRightLoc);
					currRightLoc = right(currRightLoc);
				}
				else if (currLeftLoc >= heap_size || currRightLoc >= heap_size){
					//cout << "OUT OF HEAP BOUNDS" << endl;
					//cout << "Making index " << parent(currLeftLoc) << " = " << numToMove << endl;
					arr[parent(currLeftLoc)] = numToMove;
					complete = true;
				}
				else{
					arr[parent(currLeftLoc)] = numToMove;
					complete = true;
				}
			}
			return min;
		}
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
		if (i == 0){
			arr[0] = newVal;
		}
		if (arr[parent(i)] > newVal){
			arr[i] = arr[parent(i)];
			decreaseKey(parent(i), newVal);
		}
		else {
			arr[i] = newVal;
		}
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
		/*heap_size -= 1;
		int curr = i;
		if (i < heap_size){
			int leftChildIdx = left(i);
			int rightChildIdx = right(i);
			bool complete = false;
			while (!complete){
				if (arr[leftChildIdx] <= arr[rightChildIdx] && leftChildIdx < heap_size - 1){
					cout << "Left child: " << arr[leftChildIdx] << " Smaller than right: " << arr[rightChildIdx] << endl;
					arr[curr] = arr[leftChildIdx];
					curr = leftChildIdx;
					rightChildIdx = right(curr);
					leftChildIdx = left(curr);
				}
				else if (arr[rightChildIdx] <= arr[leftChildIdx] && leftChildIdx < heap_size - 1){
					cout << "Right child: " << arr[rightChildIdx] << " Smaller than left: " << arr[leftChildIdx] << endl;					
					arr[curr] = arr[rightChildIdx];
					curr = rightChildIdx;
					leftChildIdx = left(curr);
					rightChildIdx = right(curr);
				}
				else{
					complete = true;
				}
			}
		}
		*/
		decreaseKey(i, -100000);
		int tmp = extractMin();
		//cout << "Key deleted, New heap:" << endl;
		//->printHeap();
    }
	
	//////////////////////////////////////////////////
	////////Completed part a, do part b monday////////
	//////////////////////////////////////////////////
	
	///// I ADDED TO SEE MY ARRAY //////
	void printHeap(){
		for (int i = 0; i < heap_size; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

#endif
