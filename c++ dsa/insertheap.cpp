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
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.printHeap(); // Output should reflect max-heap property

    return 0;
}