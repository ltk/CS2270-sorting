/*

  Lawson Kurtz
  09/21/2018
  I'm implementing Insertion Sort as my mystery sort.

  sorting.cpp

  Please refer to sorting.h for documentation on each function.

   + ------ N O T E: -- Big scary warning! -----------------------------\
   |                                                                    |
   |    We clearly can't use unit testing to ensure that you're         |
   |    actually implementing the correct algorithm. I suppose we could |
   |    write some complicated static analysis checker. But it is       |
   |    easier to just look at it with our eyeballs.                    |
   |                                                                    |
   |    After the assignment is due, we will look at the most recent    |
   |    version of your implementation that got the highest score and   |
   |    make sure you're not doing something sneaky like using a        |
   |    standard library call to sort a vector.                         |
   |                                                                    |
   |    Anyone caught doing this (even though it is kinda funny) will   |
   |    be given 0 points on the assignment.                            |
   |                                                                    |
   `--------------------------------------------------------------------/ 

 */

#include "sorting.h"
#include <iostream>

using namespace std;

// For my debugging purposes.
void print_vector(vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i] << ", ";
  }
  cout << endl;
}

void swap_values(vector<int> &v, int i1, int i2) {
  int t = v[i1];
  v[i1] = v[i2];
  v[i2] = t;
}


void quicksort(vector<int> &data, int low_idx, int high_idx) {
  if (low_idx < high_idx) {
    int p = quicksort_partition(data, low_idx, high_idx);
    quicksort(data, low_idx, p - 1);
    quicksort(data, p + 1, high_idx);
  }
}

int quicksort_partition(vector<int> &data, int low_idx, int high_idx) {
  int pivot = data[high_idx];
  int i = low_idx - 1;
  for (int j = low_idx; j < high_idx; j++) {
    if (data[j] < pivot) {
      i++;
      swap_values(data, i, j);
    }
  }
  if (data[high_idx] < data[i + 1]) {
    swap_values(data, i + 1, high_idx);
  }

  return i + 1;
}

void bubblesort(vector<int> &data) {
  while (true) {
    bool sorted = true;

    for (int i = 0; i < (int) data.size() - 1; i++) {
      if (data[i] > data[i + 1]) {
        // If anything is out of order during this pass, consider the list unsorted.
        sorted = false;
        int t = data[i];
        data[i] = data[i + 1];
        data[i + 1] = t;
      }
    }

    // If nothing had to be resorted during this pass, our list is in order! w00t.
    if (sorted) {
      return;
    }
  }
}

void mergesort(vector<int> &data) {
  if (data.size() < 2) {
    return;
  }

  int midpoint = data.size() / 2;
  vector<int> left = vector<int>(data.begin(), data.begin() + midpoint);
  vector<int> right = vector<int>(data.begin() + midpoint, data.end());

  mergesort(left);
  mergesort(right);
  data = merge(left, right);
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  vector<int> combo;
  combo.reserve(left.size() + right.size());

  int rightIndex = 0;
  int leftIndex = 0;

  while (true) {
    bool leftOutOfBounds = leftIndex >= left.size();
    bool rightOutOfBounds = rightIndex >= right.size();

   if ((rightOutOfBounds && !leftOutOfBounds) || (!leftOutOfBounds && !rightOutOfBounds && left[leftIndex] < right[rightIndex])) {
      combo.push_back(left[leftIndex]);
      leftIndex++;
    } else if (!rightOutOfBounds) {
      combo.push_back(right[rightIndex]);
      rightIndex++;
    } else {
      break;
    }
  }

  return combo;
}


void mystery_sort(vector<int> &data) {
  // Algorithm implemented: Insertion Sort
  if (data.size() < 2) {
    return;
  }

  for (int i = 1; i < data.size(); i++) {
    for (int j = i; j > 0 && data[j - 1] > data[j]; j--) {
      swap_values(data, j, j - 1);
    }
  }
}

