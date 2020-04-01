#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
inline void swap_int(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int Bsearch(int arra[], int target, int start, int end)
{
    if(end >= start){
    if(arra[(start + end) / 2] == target)
        return static_cast<int>((start + end) / 2);
    else if(arra[(start + end) / 2] > target)
        return Bsearch(arra, target, start, ((start + end) / 2 -1));
    else if(arra[(start + end) / 2] < target)
        return Bsearch(arra, target, ((start + end) / 2 + 1), end);
    }
    return -1;
}
void Merge(int arr[], int start, int mid, int end)
{   
    //Two array arr[start ~ mid], arr[mid + 1 ~ end]
    int ridx = 0, lidx = 0;
    int Larr[mid - start + 1], Rarr[end - mid];
    for(int i = start; i <= mid; i++, lidx++)
        Larr[lidx] = arr[i];      
    for(int i = mid + 1; i <= end; i++, ridx++)
        Rarr[ridx] = arr[i];
    ridx = 0, lidx = 0;
    Larr[mid - start + 1] = 2147483647;
	Rarr[end - mid] = 2147483647;
    for(int j = start; j <= end; j++){
        if(Larr[lidx] > Rarr[ridx]){
            arr[j] = Rarr[ridx];
            ridx++;
        }
        else{
            arr[j] = Larr[lidx];
            lidx++;
        }
    }
}
void MergeSort(int arr[], int start, int end)
{
    if(start < end){
        int mid = ((start + end) / 2);
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}
//QuickSort
int Partition(int arr[], int start, int end)
{
    int tmp, i = start -1;
    tmp = arr[end];
    for(int j = start; j < end; j++){
        if(arr[j] <= tmp){
            i = i + 1;
            swap_int(arr[i], arr[j]);
        }
    }
    swap_int(arr[i + 1], arr[end]);
    return i + 1;
}

void QuickSort(int arr[], int start, int end)
{   
    if(start < end){
        int pivot;
        pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot-1);
        QuickSort(arr, pivot + 1, end);
    }
}
void Heapify(int arr[], int node, int n)
{   
    if(node < n){
        int root, lc, rc;
        root = arr[node];   
        lc = arr[node * 2];
        rc = arr[node * 2 + 1];
        if(lc >= rc && lc >= root){
            swap_int(arr[node * 2], arr[node]);
            Heapify(arr, node * 2, n);
        }
        else if(rc >= lc && rc >= root){
            swap_int(arr[node * 2 + 1], arr[node]);
            Heapify(arr, node * 2 + 1, n);
        } 
    }
}
void Build_Heap(int arr[], int size)
{
    int nonleaf = size / 2 ;
    for(int i = nonleaf; i >= 1; i--)
        Heapify(arr, i, size);
}
int main(void)
{   srand(time(NULL));
    //Insertion sort (Ascending) (O(n^2))
    int arr[10];
    cout << "Unsorted array = " << endl;
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 50;
        cout << arr[i] << '\t';
    }
    cout <<endl << "Sorted array (Ascending) =" << endl;
    for(int i = 1; i < 10; i++)
        for(int j = i - 1; j >= 0; j--)
            if(arr[j + 1] <= arr[j])
                swap_int(arr[j + 1], arr[j]);  
    for (int i = 0; i <10; i++)
        cout << arr[i] << '\t';

    int tar, result;
    cout<< endl << "Target = ";
    cin >> tar ;
    result = Bsearch(arr, tar, 0, 9);
    if(result == -1)
        cout << endl << "Target is not in the array" <<endl;
    else
        cout << endl << "Target is at " << result;
    
    //Selective sort (Descending) (Theta(n^2))
    cout <<endl << "Sorted array (Descending) =" << endl;
    for(int i = 0 ; i < 10; i++){
        int* largest = &arr[i];
        for(int j = i + 1; j < 10; j++)
            if(arr[j] > *largest)
                largest = &arr[j];
        swap_int(arr[i], *largest);
    }
    for(int i = 0; i <10; i++)
        cout << arr[i] << '\t';
    //MergeSort
    MergeSort(arr, 0, 9);
    cout << endl << "After MergeSort =" <<endl;
    for (int i = 0; i <10; i++)
        cout << arr[i] << '\t';
    //QuickSort
    QuickSort(arr, 0, 9);
    cout << endl << "After QuickSort =" <<endl;
    for (int i = 0; i <10; i++)
        cout << arr[i] << '\t';
    //Heapify
    int arr2[11];
    cout <<endl << "Original array = " << endl;
    for(int i = 1; i < 11; i++){
        arr2[i] = rand() % 50;
        cout << arr2[i] << '\t';
    }
    Build_Heap(arr2, 10);
    cout << endl << "After Heapify = " <<endl;
    for (int i = 1; i < 11; i++)
        cout << arr2[i] << '\t';
    cout << endl <<"After Heap Sort "<<endl;
    for(int i = 10; i > 0; i--){
        swap_int(arr2[1], arr2[i]);
        Build_Heap(arr2, i - 1);
    }
    for (int i = 1; i < 11; i++)
        cout << arr2[i] << '\t';
    return 0;
}