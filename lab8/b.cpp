#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector <int> find_target(string &s, string &target) {
    vector <int> positions;
    int pos = s.find(target);
    while (pos != string::npos) {
        positions.push_back(pos);
        pos = s.find(target, pos + 1);
    }
    return positions;
}

int count_plagiarism(string& s1, string& s2, string& target) {
    vector<int> v1 = find_target(s1, target);
    vector<int> v2 = find_target(s2, target);

    set<int> pos_set1(v1.begin(), v1.end());
    set<int> pos_set2(v2.begin(), v2.end());

    int count = 0;
    for (int pos : pos_set1) {
        if (pos_set2.count(pos) > 0) {
            count++;
        }
    }
    return count;
}


int main() {
    string s1, s2, target;
    cin >> s1 >> s2 >> target;

    cout << count_plagiarism(s1, s2, target);


}