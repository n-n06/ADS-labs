#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, m, a, b, c;
ll arr[11000];

void bfs(ll a) {
    queue<ll> q;
    q.push(a);
    while (!arr[b]) {
        ll node = q.front();
        q.pop();
        if (node >= 2 && arr[node - 1] == 0) {
            arr[node - 1] = node;
            q.push(node - 1);
        }
        if (node * 2 <= 10000 && arr[node * 2] == 0) {
            arr[node * 2] = node;
            q.push(node * 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    bfs(a);
    vector<ll> ans;
    while (b != a) {
        ans.push_back(b);
        b = arr[b];
    }

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (ll i : ans) {
        cout << i << " ";
    }
    return 0;
}