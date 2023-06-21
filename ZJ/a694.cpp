#include <iostream>

using namespace std;

#define MAXN 505
#define MAXM 100005
int n, m;
int a[MAXN][MAXN], pre[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << endl;
        }
    }
    return 0;
}