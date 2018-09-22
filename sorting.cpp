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

void print_vector(vector<int> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    // cout << "v at " << i << " is " << v[i] << endl;
    cout << v[i] << ", ";
  }
  cout << endl;
}


void quicksort(vector<int> &data, int low_idx, int high_idx) {
  // TODO
}

int quicksort_partition(vector<int> &data, int low_idx, int high_idx) {
  // TODO
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

    // If nothing had to be resorted during this pass, our list is in order!
    if (sorted) {
      return;
    }
  }
}

void mergesort(vector<int> &data) {
  // Split in half, mergesort each half.
  // left = subvec
  // right = subvec
  // merge(left, right);

  // cout << "Full" << endl;
  // print_vector(data);
  // cout << "M1" << endl;

  if (data.size() < 2) {
    // Stopping condition!
    // cout << "Stopped." << endl;
    return;
  }

  int midpoint = data.size() / 2;
  vector<int> left = vector<int>(data.begin(), data.begin() + midpoint);
  vector<int> right = vector<int>(data.begin() + midpoint, data.end());

  
  // cout << "Splitting:" << endl;
  // cout << "Left" << endl;
  // print_vector(left);
  // cout << "Right" << endl;
  // print_vector(right); 

  mergesort(left);
  // cout << "M2" << endl;
  mergesort(right);
  // cout << "M3" << endl;

  // cout << "Left" << endl;
  // print_vector(left);
  // cout << "Right" << endl;
  // print_vector(right);
  // cout << "M1" << endl;
  // if (left.size() != right.size()) {
  //   cout << "Mismatched sizes" << endl;
  //   print_vector(left);
  //   print_vector(right);
  // }
  data = merge(left, right);
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  // !!!!!!!!! FIX TEST BEFORE SUBMITTING !!!!!!!!!
  

  vector<int> combo;
  combo.reserve(left.size() + right.size());

  // int comboIndex = 0;
  int rightIndex = 0;
  int leftIndex = 0;

  // cout << endl;
  // cout << "Left" << endl;
  // print_vector(left);
  // cout << "Right" << endl;
  // print_vector(right);
  // cout << endl;


  while (true) {
    // cout << "LI " << leftIndex << endl; 
    // cout << "RI " << rightIndex<< endl; 
  
    bool leftOutOfBounds = leftIndex >= left.size();
    bool rightOutOfBounds = rightIndex >= right.size();

    // if (leftIndex >= left.size() || ) {
    //   // Add Right
    // } else if () {

    // } else {
    //   break;
    // }
    // left[leftIndex]
    // right[rightIndex]

    // if (rightOutOfBounds && leftOutOfBounds) {
    //   break;
    // // } else if (rightOutOfBounds && !leftOutOfBounds) {
    // //   combo.push_back(left[leftIndex]);
    // //   leftIndex++;
    // // } else if (leftOutOfBounds && !rightOutOfBounds) {
    // //   combo.push_back(right[rightIndex]);
    // //   rightIndex++;
    // } else 
   if ((rightOutOfBounds && !leftOutOfBounds) || (!leftOutOfBounds && !rightOutOfBounds && left[leftIndex] < right[rightIndex])) {
      // cout << "Adding L " << left[leftIndex] << endl;
      combo.push_back(left[leftIndex]);
      leftIndex++;
    } else if (!rightOutOfBounds) {
      // cout << "Adding R " << right[rightIndex] << endl;
      combo.push_back(right[rightIndex]);
      rightIndex++;
    } else {
      break;
    }
  }

  // cout << "Combo" << endl;
  // print_vector(combo);
  // cout << endl;

  // combo.insert(combo.end(), left.begin(), left.end());
  // combo.insert(combo.end(), right.begin(), right.end());
  // compare the first element in the left and right
  // remove the smaller of the two, place it at the end of the combo result
  // if (left[0] < )
  return combo;
}

void mystery_sort(vector<int> &data) {
  // TODO
  // Algorithm implemented: ___________________
  
}

