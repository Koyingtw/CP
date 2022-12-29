#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
// const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 4005
#define MAXM 1000005 
int n, m;
string s[MAXN], ans1[MAXN], ans2[MAXN];
int dis[MAXN][MAXN];
pii pos1[MAXN], pos2[MAXN];
pii from[MAXN][MAXN];
bitset<MAXN> vis[MAXN];
vector<pii> p, x;

const int pa[] = {1, 0, -1, 0, 1};

int DNC(int l1, int r1, int l2, int r2) {
    // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    if (l1 == r1 && l2 == r2) {
        return 0;
    }
    if (l1 > r1 || l2 > r2) {
        return 0;
    }
    int mid1 = (l1 + r1) >> 1;
    int mid2 = (l2 + r2) >> 1;
    int cnt = 0;
    
    cnt += DNC(l1, mid1, l2, mid2);
    cnt += DNC(mid1 + 1, r1, mid2 + 1, r2);
    cnt += DNC(l1, mid1, mid2 + 1, r2);
    cnt += DNC(mid1 + 1, r1, l2, mid2);

    for (int i = l1; i <= mid1 + 1; i++) {
        if (s[i][mid2 + 1] == '.') {
            s[i][mid2 + 1] = 'O';
            cnt++;
        }
        if (s[i][l2] == '.') {
            s[i][l2] = 'O';
            cnt++;
        }
    }
    for (int j = l2; j <= mid2; j++) {
        if (s[l1][j] == '.') {
            s[l1][j] = 'O';
            cnt++;
        }
    }
    return cnt;
}

void sol2() {
    DNC(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ans1[i] = ans2[i] = s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'P') {
                p.pb({i, j});
            }
        }
    }

    int cnt1 = 0;
    int last1 = -1;
    for (int i = 0; i < n; i++) {
        pos1[i] = pii(-1, -1);
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'P' || s[i][j] == 'X') {
                if (pos1[i].F == -1)
                    pos1[i].F = pos1[i].S = j;
                pos1[i].S = j;
            }
        }
        for (int j = pos1[i].F; j <= pos1[i].S; j++) {
            if (ans1[i][j] == '.') {
                ans1[i][j] = 'O';
                cnt1++;
            }
        }

        if (last1 != -1) {
            if (pos1[i].S < pos1[last1].F) {
                for (int j = pos1[i].S; j <= pos1[last1].F; j++) {
                    if (ans1[i][j] == '.') {
                        ans1[i][j] = 'O';
                        cnt1++;
                    }
                }
                for (int j = last1; j <= i; j++) {
                    if (ans1[j][pos1[last1].F] == '.') {
                        ans1[j][pos1[last1].F] = 'O';
                        cnt1++;
                    }
                }
            }
            else if (pos1[i].F > pos1[last1].S) {
                for (int j = pos1[last1].S; j <= pos1[i].F; j++) {
                    if (ans1[i][j] == '.') {
                        ans1[i][j] = 'O';
                        cnt1++;
                    }
                }
                for (int j = last1; j <= i; j++) {
                    if (ans1[j][pos1[last1].S] == '.') {
                        ans1[j][pos1[last1].S] = 'O';
                        cnt1++;
                    }
                }
            }
            else {
                for (int j = last1; j <= i; j++) {
                    if (ans1[j][pos1[last1].F] == '.') {
                        ans1[j][pos1[last1].F] = 'O';
                        cnt1++;
                    }
                }
            }
        }
        if (pos1[i].F != -1)
            last1 = i;
        // cout << pos1[i].F << ' ' << pos1[i].S << endl;
    }

    if (cnt1 <= 2e6) {
        for (int i = 0; i < n; i++) {
            cout << ans1[i] << endl;
        }
        return;
    }

    int cnt2 = 0;
    int last2 = -1;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] == 'P' || s[i][j] == 'X') {
                if (pos2[j].F == -1)
                    pos2[j].F = pos2[j].S = i;
                pos2[j].S = i;
            }
        }
        for (int i = pos2[j].F; i <= pos2[j].S; i++) {
            if (ans2[i][j] == '.') {
                ans2[i][j] = 'O';
                cnt2++;
            }
        }

        if (last2 != -1) {
            if (pos2[j].S < pos2[last2].F) {
                for (int i = pos2[j].S; i <= pos2[last2].F; i++) {
                    if (ans2[i][j] == '.') {
                        ans2[i][j] = 'O';
                        cnt2++;
                    }
                }
                for (int i = last2; i <= j; i++) {
                    if (ans2[pos2[last2].F][i] == '.') {
                        ans2[pos2[last2].F][i] = 'O';
                        cnt2++;
                    }
                }
            }
            else if (pos2[j].F > pos2[last2].S) {
                for (int i = pos2[last2].S; i <= pos2[j].F; i++) {
                    if (ans2[i][j] == '.') {
                        ans2[i][j] = 'O';
                        cnt2++;
                    }
                }
                for (int i = last2; i <= j; i++) {
                    if (ans2[pos2[last2].S][i] == '.') {
                        ans2[pos2[last2].S][i] = 'O';
                        cnt2++;
                    }
                }
            }
            else {
                for (int i = last2; i <= j; i++) {
                    if (ans2[pos2[last2].F][i] == '.') {
                        ans2[pos2[last2].F][i] = 'O';
                        cnt2++;
                    }
                }
            }
        }
        if (pos2[j].F != -1)
            last2 = j;
    }

    if (cnt2 <= 2e6) {
        for (int i = 0; i < n; i++) {
            cout << ans2[i] << endl;
        }
        return;
    }

    assert(false);
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}