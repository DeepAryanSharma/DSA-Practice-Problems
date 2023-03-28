#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void solve(vector<int> arr, int sum, int &maxi, int i) {
  // base case
  if (i >= arr.size()) {
    // maxi update
    maxi = max(sum, maxi);
    return;
  }

  // include
  solve(arr, sum + arr[i], maxi, i + 2);

  // exclude
  solve(arr, sum, maxi, i + 1);
}

int main() {
  vector<int> arr{1, 2, 20, 35, 40};
  int sum = 0;
  int maxi = INT_MIN;
  int i = 0;
  solve(arr, sum, maxi, i);

  cout << maxi;

  return 0;
}
