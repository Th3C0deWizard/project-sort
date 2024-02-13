#include "algorithms/heapSort.hpp"
#include "algorithms/quickSort.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>

using namespace std::chrono;

void quickSortWraper(int *arr, int N, long &counter) {
  quickSort(arr, 0, N - 1, counter);
}

void quickSortWraper(int *arr, int N) { quickSort(arr, 0, N - 1); }

int main(int argc, char *argv[]) {

  // Handling the arguments
  if (argc != 4) {
    cout << "Se esperaban solo 4 argumentos" << endl;
    return 1;
  }

  void (*sort_fun)(int *, int) = nullptr;
  void (*sort_fun_count)(int *, int, long &) = nullptr;

  if (string(argv[1]) == "heap") {
    sort_fun = &heapSort;
    sort_fun_count = &heapSort;
  } else if (string(argv[1]) == "quick") {
    sort_fun = &quickSortWraper;
    sort_fun_count = &quickSortWraper;
  } else {
    cout << "Error al determinar el algoritmo de ordenamiento" << endl;
    return 1;
  }

  int N = stoi(argv[2]);
  int *numbers{new int[N]{}};

  // Open the provided file and reading the numbers
  fstream datafile;
  datafile.open(argv[3], ios::in);
  if (datafile.is_open()) {
    string data;
    int i = 0;
    while (getline(datafile, data, ',') && i < N) {
      numbers[i] = stoi(data);
      i++;
    }
    datafile.close();
  }

  string results;
  int *numbersCopy{new int[N]};
  std::copy_n(numbers, N, numbersCopy);
  long counter = 0;
  sort_fun_count(numbersCopy, N, counter);
  delete[] numbersCopy;
  results += "instructions = " + to_string(counter) + "\n";
  // measuring the time took by the sort algorithm
  for (int i = 0; i < 10; i++) {
    int *numbersCopy{new int[N]};
    std::copy_n(numbers, N, numbersCopy);
    clock_t t;
    t = clock();
    (*sort_fun)(numbersCopy, N);
    t = clock() - t;
    double duration = ((double)t) / CLOCKS_PER_SEC;
    results += to_string(duration) + "\n";
    delete[] numbersCopy;
  }

  results += string(argv[1]) + ":" + string(argv[2]);
  system(("python src/scripts/worker.py \"" + results + "\"").c_str());
  delete[] numbers;
  return 0;
}
