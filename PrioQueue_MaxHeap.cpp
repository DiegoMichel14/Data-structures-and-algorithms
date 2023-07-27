//Implementación de estructura de datos no lineales, Árvol Heap
//Última modificación 23/07/2023
//Diego Alejandro Michel Castro | A01641907

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class MaxHeap {
    private:
        vector<int> heap;

        void heapifyUp(int index) {  //Restore the max heap property by moving up the element
            int parentIndex = (index - 1) / 2;  //Complexity: O(log n), n is the number of elements in the heap
            while (index > 0 && heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);   // Swap with parent if current element is greater
                index = parentIndex;
                parentIndex = (index - 1) / 2;  //Update parent index
            }
        };

        void heapifyDown(int index) {  //Restore the max heap property by moving down the element
            int leftChild = 2 * index + 1;    //Complexity: O(log n), n is the number of elements in the heap
            int rightChild = 2 * index + 2;
            int largestIndex = index;

            if (leftChild < heap.size() && heap[leftChild] > heap[largestIndex]) {
                largestIndex = leftChild;  // Update largest index if left child is greater
            }

            if (rightChild < heap.size() && heap[rightChild] > heap[largestIndex]) {
                largestIndex = rightChild;    // Update largest index if right child is greater
            }

            if (largestIndex != index) {
                swap(heap[index], heap[largestIndex]);  // Swap with largest child if necessary
                heapifyDown(largestIndex);  // Recursively heapify the affected child
            }
        };

    public:
        MaxHeap() {}  //Constructor for the class objet

        void push(int element) {   //Function to add an element in the tree
            heap.push_back(element);  //Complexity: O(log n), n is the number of elements in the heap
            heapifyUp(heap.size() - 1);
        };

        void pop() {   //Function for delete the highest element
            if (!isEmpty()) {   //Complexity: O(log n), n is the number of elements in the heap
                swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();    //Pop element with highest prio
                heapifyDown(0);
            }
        };

        int top() const {   //Element with the highest prio value, root of the tree, Complexity: O(1)
            if (!isEmpty()) {  
                return heap[0]; //Index 0 of the array = root of the tree
            }
 
            throw std::runtime_error("Priority queue is empty!");  //Validation for empty queue

        };

        bool isEmpty() const {  //Function for empty tree, Complexity: O(1)
            return heap.empty();
        };

        int size() const {  //Function for Heap size, Complexity: O(1)
            return heap.size();
        };

        void printHeap(){   //Complexity: O(log n), n is the number of elements in the heap
            if (isEmpty()){
                cout << "Heap is empty." << endl;  //Validation for empty queue
                return;
            }

            cout << "Heap: " << endl;

            for (int i = 0; i < heap.size(); ++i){  //Cycle for printing elements one by one
                cout << heap[i];
                if (i < heap.size() - 1){   //Heap size for printing
                    cout << " -> ";
                }
            }

            cout << endl;
        }
};

int main() {
    MaxHeap priority_Queue;

    priority_Queue.push(5);  //Element insertions
    priority_Queue.push(10);
    priority_Queue.push(3);
    priority_Queue.push(7);
    priority_Queue.push(4);
    priority_Queue.push(8);

    cout << "\n" << endl;

    priority_Queue.printHeap();  //Pint tree

    cout << "\nTop element: " << priority_Queue.top() << "\n" << endl;  //Highest prio element

    priority_Queue.pop();  //Delete root

    cout << "Top element after pop: " << priority_Queue.top() << endl;  //New highest element after the pop

    cout << "\nHeap after the pop: " << endl;
    priority_Queue.printHeap();

    cout << "\nPriority queue size: " << priority_Queue.size() << "\n"  << endl;

    priority_Queue.isEmpty();

    return 0;
}

