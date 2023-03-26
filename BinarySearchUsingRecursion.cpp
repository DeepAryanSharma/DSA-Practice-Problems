#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int &n, int &s, int &e, int &key) {
  int mid = (s + e) / 2;
  // base case-1
  if (s > e) {
    return -1;
  }
  // base case-2 & 1 case solve kardo
  if (arr[mid] == key) {
    return mid;
  }
  // baaki recursion sambhal leaga
  if (arr[mid] < key) {
    // search in right of mid
    s = mid + 1;
    return BinarySearch(arr, n, s, e, key);
  }
  if (arr[mid] > key) {
    // search in left of mid
    e = mid - 1;
    return BinarySearch(arr, n, s, e, key);
  }
}

int main() {
  vector<int> v = {10, 50, 55, 62, 35, 86, 90};
  int n = v.size();
  int s = 0;
  int e = n - 1;
  int key = 62;

  int ans = BinarySearch(v, n, s, e, key);
  cout << "Answer is: " << ans;
}
