#include <iostream>

void heapify(int arr[], int size, int parentNode) {
    int largest = parentNode;
    int leftChild = 2*parentNode + 1;
    int rightChild = 2*parentNode + 2;

    if(leftChild < size && arr[largest] <= arr[leftChild]) {
        largest = leftChild;
    }

    if(rightChild < size && arr[largest] <= arr[rightChild]) {
        largest = rightChild;
    }

    if(parentNode != largest) {
        int temp = arr[parentNode];
        arr[parentNode] = arr[largest];
        arr[largest] = temp;
    
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for(int i = 0; i < (size-1)/2; i++) {
        heapify(arr, size, i);
    }

    for(int i = size-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

}

int main() {
    int size = 10;
    int arr[size] = {1,2,29,23,12,12,10,1,19,20};

    heapSort(arr, size);

    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}