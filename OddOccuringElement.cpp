#include <iostream>
#include <vector>
using namespace std;

int oddOccuring(vector<int> arr) {
  int s = 0;
  int e = arr.size() - 1;
  int mid = s + (e - s) / 2;
  while (s <= e) {
    // if only single element is present
    if (s == e) {
      return s;
    }

    // if mid is even
    if (mid % 2 == 0) {
      if (arr[mid] == arr[mid + 1]) {
        // search in right
        s = mid + 2;
      } else {
        // search in left
        e = mid; // mid can be the answer so it must be included
      }
    }

    else {
      if (arr[mid] == arr[mid - 1]) {
        // search in right;
        s = mid + 1;
      } else {
        // search in left
        e = mid - 1;
      }
    }
    mid = s + (e - s) / 2;
  }
  return -1;
}

int main() {
  vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};

  cout << arr[oddOccuring(arr)];
}
