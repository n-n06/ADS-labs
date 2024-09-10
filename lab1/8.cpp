#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> generatePrimes(int limit) {
    //Generating primes using the Sieve of Eratosthenes
    vector <int> primes;

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    //If a number is prime it is sufficient to check if it is 
    //not divisible by numbers less than its square root (rounded ofc)
    for (int i = 2; i < sqrt(limit); i++) {
        if (isPrime[i]) {
            //by Eratosthenes' method, we go over every multiple of prime numbers
            //and mark then as composite
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            //creating a list of primes
            primes.push_back(i);
        }
    }

    return primes;
}



int main() {

    vector<int> primeNumbers = generatePrimes(10000);
    vector<int> primeIndices = generatePrimes(1000);

    vector <int> superPrimes;

    for (int primeIndex : primeIndices) {
        superPrimes.push_back(primeNumbers[primeIndex - 1]);
    }

    int n; cin >> n;
    cout << superPrimes[n - 1];
}