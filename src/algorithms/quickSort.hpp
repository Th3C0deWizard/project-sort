#pragma once
#include <bits/stdc++.h>

using namespace std;

inline int partition(int arr[], int start, int end) {

  int pivot = arr[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex) {

    while (arr[i] <= pivot) {
      i++;
    }

    while (arr[j] > pivot) {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}

inline void quickSort(int arr[], int start, int end) {

  // base case
  if (start >= end)
    return;

  // partitioning the array
  int p = partition(arr, start, end);

  // Sorting the left part
  quickSort(arr, start, p - 1);

  // Sorting the right part
  quickSort(arr, p + 1, end);
}

inline int partition(int arr[], int start, int end, long &counter) {

  int pivot = arr[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      counter++;
    count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(arr[pivotIndex], arr[start]);
  counter++;

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex) {

    counter++;

    while (arr[i] <= pivot) {
      counter++;
      i++;
    }

    while (arr[j] > pivot) {
      counter++;
      j--;
    }

    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
      counter++;
    }
  }

  return pivotIndex;
}

inline void quickSort(int arr[], int start, int end, long &counter) {

  counter++;
  // base case
  if (start >= end)
    return;

  // partitioning the array
  int p = partition(arr, start, end, counter);

  // Sorting the left part
  quickSort(arr, start, p - 1, counter);

  // Sorting the right part
  quickSort(arr, p + 1, end, counter);
}
