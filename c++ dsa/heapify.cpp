#include <iostream>
using namespace std;

class MaxHeap {
    private:
    int heap[100];
    int size;

    public:
    //Constructor
    MaxHeap(){
        size = 0; 
        heap[0] = -1;
    }
    void heapify(int heap[], int size , int index){
        int left = 2* index ;
        int right = 2 * index + 1;
        int largest = index; 

        if(left <= size && heap[left] > heap[largest]){
            largest = left;
        }
        if(right <= size && heap[right] > heap[largest] ){
            largest = right;
        }
        
        if(largest != index){
            swap(heap[largest], heap[index]);
            heapify(heap, size, largest);
        }
    };
};