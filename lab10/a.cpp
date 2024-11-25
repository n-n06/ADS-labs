#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n);
    vector<pair<int, int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> marq;

    int mushrooms = 0;
    int time = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            if (num == 1) {
                mushrooms++;
            } else if (num == 2) {
                marq.push({i, j});
            }
            matrix[i].push_back(num);
        }
    }

    while (!marq.empty()) {
        int mar_num = marq.size();
        for (int i = 0; i < mar_num; i++) {
            pair<int, int> cur_pos = marq.front();
            marq.pop();

            for (pair<int, int> dir : dirs) {
                int x = cur_pos.first + dir.first;
                int y = cur_pos.second + dir.second;

                if (x >= 0 && x < n && y >= 0 & y < m && matrix[x][y] == 1) {
                    matrix[x][y] = 2;
                    marq.push({x,y});
                    mushrooms--;
                }
            }
        }

        time++;
    }

    if (mushrooms > 0) {
        cout << -1 ;
    } else if (time == -1) {
        cout << 0;
    } else {
        cout << time;
    }






}