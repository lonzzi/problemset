#include <cstring>
#include <iostream>

using namespace std;

int R, C;
int path[60][60];
int map[60][60];
int visted[60][60];
int dx[4] = {-1, 1, 0, 0}; // N S W E
int dy[4] = {0, 0, -1, 1};

void dfs(int d) {
    memset(visted, 0, sizeof(visted));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (path[i][j] == 1 && visted[i][j] != 1) {
                path[i][j] = 0;
                visted[i][j] = 1;
                int x = i + dx[d], y = j + dy[d];
                while (map[x][y]) {
                    path[x][y] = 1;
                    visted[x][y] = 1;
                    x = x + dx[d], y = y + dy[d];
                }
            }
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                map[i][j] = 1;
            } else if (ch == 'X') {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
                path[i][j] = 1;
            }
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string direct;
        cin >> direct;
        if (direct == "NORTH") {
            dfs(0);
        } else if (direct == "SOUTH") {
            dfs(1);
        } else if (direct == "WEST") {
            dfs(2);
        } else if (direct == "EAST") {
            dfs(3);
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (path[i][j]) {
                cout << "*";
            } else if (map[i][j]) {
                cout << ".";
            } else if (map[i][j] == 0) {
                cout << "X";
            }
        }
        cout << endl;
    }

    return 0;
}