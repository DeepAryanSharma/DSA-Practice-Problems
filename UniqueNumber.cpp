#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> arr) {
  int ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    ans = ans ^ arr[i];
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the size of array";
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }

  // getting unique number

  int unique = find(arr);
  cout << "The unique number is :" << unique;

  return 0;
}
