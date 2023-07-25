#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int x[MAXN], p[4][4];
int cnt[6][4];
string s;

void sol() {
	cin >> s;
    n = s.size();
    vector<int> foo(3), mp(4);
    for (int i = 0; i < 3; i++)
        foo[i] = i + 1;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> p[i][j];

    int ans = INF, now = 0;
    do {
        for (int i = 0; i < 3; i++)
            mp[foo[i]] = i + 1;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            x[i] = foo[s[i] - 'a'];
            if (x[i] == 1) {
                int a = cnt[now][3];
                int b = cnt[now][2];
                sum += a * p[mp[3]][mp[1]];
                sum += b * p[mp[2]][mp[1]];
            }
            else if (x[i] == 2) {
                int a = cnt[now][3];
                sum += a * p[mp[3]][mp[2]];
            }
            cnt[now][x[i]]++;
        }   

        cmin(ans, sum);
        now++;
    } while (next_permutation(all(foo)));
    cout << ans << endl;
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