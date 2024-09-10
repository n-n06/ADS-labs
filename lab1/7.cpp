#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int& x) { //pretty straightforward init?
    if (x == 0 || x == 1) {
        return false;
    } else {
        for (int i = 2; i < ceil(sqrt(x)); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {

    int n; cin >> n;

    if (isPrime(n)) {
        cout << "YES";
    }  else {
        cout << "NO";
    }

    return 0;
}