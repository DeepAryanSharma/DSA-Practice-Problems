#include <iostream>
using namespace std;

void Subsequence(string str, string output, int n, int i) {
  // base case
  if (i == n) {
    cout << output << endl;
    return;
  }

  // exclude
  Subsequence(str, output, n, i + 1);

  // include
  output.push_back(str[i]);
  Subsequence(str, output, n, i + 1);
}

int main() {
  string str = "abc";
  string output = "";
  int i = 0;
  int n = str.length();

  Subsequence(str, output, n, i);
}
