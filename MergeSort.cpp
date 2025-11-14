#include <iostream>
using namespace std;

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
    if (left >= right) return;              // base case
    
    int mid = left + (right - left) / 2;    // divide
    mergeSort(A, left, mid);                // conquer
    mergeSort(A, mid + 1, right);           // conquer
    merge(A, left, mid, right);             // combine
}

int main() {
    int A[50] = {57, 8, 92, 36, 45, 67, 24, 5, 71, 3, 89, 64, 52, 1, 78, 88, 47, 30, 70, 66, 40, 61, 59, 62, 54, 25, 12, 9, 53, 79, 48, 43, 32, 18, 80, 15, 85, 74, 84, 35, 37, 13, 73, 49, 16, 23, 4, 56, 60, 26};

    cout << "Original Array: ";
    for(int i : A) {
        cout << i << " ";
    }
    cout << "\n" << endl;

    mergeSort(A, 0, 50 - 1);

    cout << "Sorted Array: ";
    for(int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}