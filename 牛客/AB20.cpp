#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x1, y1, x2, y2;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


vector<vector<char>> vv;
vector<vector<int>> dist;

int BFS() {
    
    if (vv[x2][y2] == '*') {
        return -1;
    }
    queue<pair<int, int>> qu;
    qu.push(pair<int, int>(x1, y1));
    dist[x1][y1] = 0;
    while (qu.size()) {
        auto [curx, cury] = qu.front();
        qu.pop();
        if (curx == x2 && cury == y2) {
            return dist[x2][y2];
        }
        vv[curx][cury] = '*';
        for (int i = 0; i < 4; i++) {
            if (1 <= curx + dx[i] && curx + dx[i] <= n && 1 <= cury + dy[i] &&
                    cury + dy[i] <= m && vv[curx + dx[i]][cury + dy[i]] == '.' && dist[curx + dx[i]][cury + dy[i]] == -1) {
                qu.push(pair<int, int>(curx + dx[i], cury + dy[i]));
                dist[curx + dx[i]][cury + dy[i]] = dist[curx][cury] + 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vv.resize(n + 2, vector<char>(m + 2, '*'));
    dist.resize(n + 2, vector<int>(m + 2, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> vv[i][j];
        }
    }
    cout << BFS() << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")