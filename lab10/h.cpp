#include <iostream>

using namespace std;

int rows, columns, count;

void dfs(char **map, int i, int j) {
    if (i >= rows || j >= columns || i < 0 || j < 0 || map[i][j] == '0')
        return;
    map[i][j] = '0';

    dfs(map, i + 1, j);
    dfs(map, i - 1, j);
    dfs(map, i, j + 1);
    dfs(map, i, j - 1);
}

int main() {
    cin >> rows >> columns;
    char **map = new char *[rows];

    for (int i = 0; i < rows; i++) {
        map[i] = new char[columns];
        for (int j = 0; j < columns; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j] == '1') {
                dfs(map, i, j);
                count++;
            }
        }
    }
    cout << count;
    delete[] map;
    return 0;
}