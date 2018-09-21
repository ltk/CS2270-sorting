/*

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


void quicksort(vector<int> &data, int low_idx, int high_idx) {
  // TODO
}

int quicksort_partition(vector<int> &data, int low_idx, int high_idx) {
  // TODO
}

void bubblesort(vector<int> &data) {
  while (true) {
    bool sorted = true;

    for (int i = 0; i < data.size() - 1; i++) {
      if (data[i] > data[i + 1]) {
        sorted = false;
        int t = data[i];
        data[i] = data[i + 1];
        data[i + 1] = t;
      }
    }

    if (sorted) {
      return;
    }
  }
}

void mergesort(vector<int> &data) {
  // TODO
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  // TODO
}

void mystery_sort(vector<int> &data) {
  // TODO
  // Algorithm implemented: ___________________
  
}

