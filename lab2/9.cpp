#include <iostream>
#include <queue>
#include <map>

using namespace std;

void test() {
    int n; cin >> n;
    queue <string> word_queue;
    map <string, int> word_count;
    string word;

    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word == word_queue.front()) {
            while (word_count[word_queue.front()] > 1) {
                word_queue.pop();
            }
        } else {
            word_queue.push(word);
            word_count[word] += 1;
        }
    

        if (!word_queue.empty()) {
            cout << word_queue.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        test();
    }
    return 0;
}