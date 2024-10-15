#include <iostream>
#include <algorithm>

using namespace std;

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool comparator(char a, char b) {
	if (isVowel(a) && !isVowel(b)) {
		return true;
	} else if (!isVowel(a) && isVowel(b)) {
		return false;
	} else {
		return a < b;
	}
}

int main() {
	int n; cin >> n;
	string s; cin >> s;

	sort(s.begin(), s.end(), comparator);
	cout << s;

}



