#include <bits/stdc++.h>



using namespace std;

using l = long long;

l n, m, a, b, c;
vector<l> edges[1234567];
l parent[1234567];
l counter[1234567];

void bfs(l x){
    queue<l> q;
    q.push(x);
    parent[x] = x;

    while(!q.empty()){
        l cur = q.front(); q.pop();
        for(l i : edges[cur]){
            if (!parent[i]){
                parent[i] = cur;
                counter[cur]++;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(l i = 0; i < m; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(l i = 1; i <= n; i++){
        if (!parent[i]) {
            bfs(i);
        }
    }
    l ans = 0;
    for(l i = 1; i <= n; i++){
        if (parent[i] != i){
            if (counter[i] > counter[parent[i]]) {
                ans++;
            }
        }
        else ans++;
    }

    
    cout << ans;
    return 0;
}