#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v; // solved using vector
  /*
  The stack approach could theoretically work better here, but
  I decided that it would take unnecessary operations like pushind and popping, so
  I implemented a simple pointer on a vector
  */

  for (int i = 0; i < n; i++) {
    int number; 
    int pointer = i - 1;
    
    cin >> number;
    v.push_back(number);

    while ((pointer >= 0) && (v[pointer] > number)) {
      pointer--;
    }

    if (pointer < 0) {
      cout << -1 << " ";
    } else {
      cout << v[pointer] << " ";
    }
  }
}
