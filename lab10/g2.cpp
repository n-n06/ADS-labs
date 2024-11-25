#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


vector<int> graph[1000];
int visited[1000];
stack<int> st;
vector<int> cyclePath;

bool dfs(int v, int a, int b) {
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (v == a && b == to) continue;
        if (!visited[to]) {
            if (dfs(to, a, b)) return true;
        } else if (visited[to] == 1) {
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

bool dfs2(int v) {
    visited[v] = 1;
    st.push(v);
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (!visited[to]) {
            if (dfs2(to)) return true;
        } else if (visited[to] == 1) {
            while (st.top() != to) {
                cyclePath.push_back(st.top());
                st.pop();
            }
            cyclePath.push_back(to);
            cyclePath.push_back(v);
            reverse(cyclePath.begin(), cyclePath.end());
            return true;
        }
    }
    visited[v] = 2;
    if (!st.empty()) st.pop();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cycle = dfs2(i);
            if (cycle) break;
        }
    }
    
    if (!cycle) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < cyclePath.size() - 1; i++) {
        int u = cyclePath[i];
        int v = cyclePath[i + 1];
        for (int j = 1; j <= n; j++) {
            visited[j] = 0;
        }
        cycle = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                cycle |= dfs(j, u, v);
            }
        }
        if (!cycle) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}