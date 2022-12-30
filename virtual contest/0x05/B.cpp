#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#define pii pair<int, int> 
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define pb push_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define SZ(x) ((int)x.size())
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = (a < b ? a : b))

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

#define MAXN 205
#define MAXM 35

int n, m;
int x[MAXN][MAXM];
vector<int> ghost;
vector<int> ans;
vector<int> score[MAXM];

void init() {
    ghost.clear();
    ans.clear();
    for (int i = 1; i <= m; i++)
        score[i].clear();
}

void sol() {
    cin >> n >> m;

    init();

    for (int i = 1; i <= n; i++) {
        bool isghost = true;
        for (int j = 1; j <= m; j++) {
            cin >> x[i][j];
            if (x[i][j] % 10 != (x[i][j] % 100) / 10)
                isghost = false;
        }
        if (isghost)
            ghost.pb(i);
        else {
            for (int j = 1; j <= m; j++) {
                score[j].pb(x[i][j]);
            }
        }
    }


    pii mn(INF, 0);
    for (int j = 1; j <= m; j++) {
        sort(all(score[j]), greater<int>());
        bool need = score[j][0] < 100 && !(score[j].back() == 0 && score[j][0] == 0);

        if (need) {
            ans.pb(j);

            int sum = 0;
            for (int i = 0; i < (SZ(score[j]) + 4) / 5; i++)
                sum += score[j][i];
            cmin(mn, pii(sum, j));
        }
    }

    cout << SZ(ans) << ' ' << mn.S << endl;
    for (int it: ans)
        cout << it << ' ';
    cout << endl;
}

signed main() {
    Koying
    int t = 1;
    cin >> t;
    while (t--)
        sol();
}