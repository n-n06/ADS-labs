#include <iostream>
#include <queue>
#include <map>
using namespace std;

void test() {
    int n; cin >> n;

    queue<char> q;
    map <char, int> freq;
    string result;

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result += "-1 ";
        } else {
            result += q.front();
            result += " ";
        }
    }

    cout << result << endl;

}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        test();
    }
    return 0;
}