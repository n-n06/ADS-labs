#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<long long> parents;

long long find(long long v) {
    if (parents[v] == v) return v;
    return parents[v] = find(parents[v]);
}

bool merge(long long u, long long v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (rand() & 1) swap(u, v);

    parents[u] = v;

    return true;
}


int main(){

    long long int n, m, a, b, c;
    cin >> n >> m;

    parents.resize(n);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }

    vector<long long int> vertices[2 * n];
    vector<long long int> remains;
    remains.resize(n);

    for (int i = 0; i < m; i++){
        cin >> a >> b; a--; b--;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }
    
    long long current = 0;
    for(long long i = n - 1; i > 0; i--){
        for(long long v : vertices[i]) 
            if (v > i) {
                current += merge(v, i); 
            } 
        remains[i - 1] = n - i - current;
    }
    for (int i = 0 ; i< n; i++) {
        cout << remains[i] << endl;
    }
    return 0;

}