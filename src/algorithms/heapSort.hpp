#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void heapify(int arr[], int N, int i) {

  // Initialize largest as root
  int largest = i;

  // left = 2*i + 1
  int l = 2 * i + 1;

  // right = 2*i + 2
  int r = 2 * i + 2;

  // If left child is larger than root
  if (l < N && arr[l] > arr[largest])
    largest = l;

  // If right child is larger than largest
  // so far
  if (r < N && arr[r] > arr[largest])
    largest = r;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);

    // Recursively heapify the affected
    // sub-tree
    heapify(arr, N, largest);
  }
}

inline void heapSort(int arr[], int N) {

  cout << "heap" << endl;
  // Build heap (rearrange array)
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);

  // One by one extract an element
  // from heap
  for (int i = N - 1; i > 0; i--) {

    // Move current root to end
    swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// Heapify with instruction counter.
inline void heapify(int arr[], int N, int i, long &counter) {

  // Initialize largest as root
  int largest = i;

  // left = 2*i + 1
  int l = 2 * i + 1;

  // right = 2*i + 2
  int r = 2 * i + 2;

  counter++;
  // If left child is larger than root
  if (l < N && arr[l] > arr[largest])
    largest = l;

  counter++;
  // If right child is larger than largest
  // so far
  if (r < N && arr[r] > arr[largest])
    largest = r;

  counter++;
  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    counter++;

    // Recursively heapify the affected
    // sub-tree
    heapify(arr, N, largest, counter);
  }
}

// HeapSort with instruction counter.
inline void heapSort(int arr[], int N, long &counter) {
  cout << "heap" << endl;

  // Build heap (rearrange array)
  for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i, counter);

  // One by one extract an element
  // from heap
  for (int i = N - 1; i > 0; i--) {

    // Move current root to end
    swap(arr[0], arr[i]);
    counter++;

    // call max heapify on the reduced heap
    heapify(arr, i, 0, counter);
  }
}
