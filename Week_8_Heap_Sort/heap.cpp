#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int left = (root) * 2 + 1, right = (root) * 2 + 2, largest = root;
    if (left < n && arr[left] > arr[root]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        int temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

   // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    srand(time(0));
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    cout << endl;
    int heap_arr[n];
    for (int i = 0; i < n; i++) {
        heap_arr[i] = rand() % 100;
    }
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}