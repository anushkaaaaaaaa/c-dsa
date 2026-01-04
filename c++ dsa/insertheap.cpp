#include <iostream>
using namespace std;

//Insertion in Heaps

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




void insert(int val){
    size = size + 1;
    heap[size] = val; //step 1:  insert at last index

    int index = size;

    //step 2 : heapify up

    while(index > 1){
        int parent = index /2 ;
        if(heap[ parent ] < heap [ index])
    {
            swap( heap[parent], heap[index]);
            index = parent;
    }   
    else{
        return;
    }
}
}

void printHeap(){
    for(int i = 1; i <= size; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}   

};

int main() {
    MaxHeap h;
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);

    h.printHeap(); // Output should reflect max-heap property

    h.insert(60);
    h.printHeap(); // Output should reflect max-heap property after inserting 60

    return 0;
}