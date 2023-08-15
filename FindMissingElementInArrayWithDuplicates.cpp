#include <iostream>
#include <vector>
using namespace std;

void findMissing(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    int index = abs(arr[i]);

    if (arr[index - 1] > 0) {
      // marking visited
      arr[index - 1] *= -1;
    }
  }

  //all positive indexes are missing
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      cout<< i + 1<<" ";
    }
  }
}

int main() {
  int n = 5;
  vector<int> arr = {1, 3, 5, 3, 4};

  cout << "missing elements: " ;
  findMissing(arr);


}
