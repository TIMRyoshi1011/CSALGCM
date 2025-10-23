#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

int scores[MAX_N];

// Upper Bound Binary Search: (Reference: https://www.geeksforgeeks.org/c/implementing-upper_bound-and-lower_bound-in-c/)
int upperBoundBinarySearch(int A[], int lo, int hi, int key) {
    if (lo >= hi) return lo;  
    
    int mid = lo + (hi - lo) / 2;

    if (A[mid] <= key) return upperBoundBinarySearch(A, mid + 1, hi, key);

    else return upperBoundBinarySearch(A, lo, mid, key);
}

// Merge Sort: (Reference: https://www.geeksforgeeks.org/dsa/merge-sort/)
void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0;  
    int j = 0; 
    int k = left;  

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } 
        
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

/*
This function solves a single test case.

Parameters:
n      : int - number of scores except Gandalf's
x      : int - Gandalf's score

Returns Gandalf's rank
*/
int solve(int n, int x) {
    // compute and return answer here
    int R = n - upperBoundBinarySearch(scores, 0, n, x) + 1;

    return R;
}

int main(){
    int q, n, x;

    cin >> q >> n;

    for(int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    mergeSort(scores, 0, n - 1);

    for(int i = 0; i < q; i++) {
        cin >> x;
        cout << solve(n,x) << endl;
    }
}

/*
// Recursive function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    // Base case: If the element is not found
    if (low > high) {
        return -1;
    }

    // Calculate mid index
    int mid = low + (high - low) / 2;

    // If target is present at mid
    if (arr[mid] == key) {
        return mid;
    }
    
    // If target is smaller, search the left half
    if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    }
    
    // If target is larger, search the right half
    return binarySearch(arr, mid + 1, high, key);
}

// Quick Sort: (Reference: https://www.programiz.com/dsa/quick-sort)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int lo, int hi) {
    int pivot = A[hi]; 
    int i = (lo - 1);

    for (int j = lo; j <= hi - 1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[hi]);
    return (i + 1); 
}

void quickSort(int A[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(A, lo, hi);

        quickSort(A, lo, p - 1);
        quickSort(A, p + 1, hi);
    }
}
*/