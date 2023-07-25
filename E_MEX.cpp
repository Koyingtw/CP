#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
string s;
int x[MAXN];
int M[MAXN][3], X[MAXN][3];

int MEX(int i, int j, int k) {
    for (int mex = 0; mex < 4; mex++) {
        if (mex != i && mex != j && mex != k)
            return mex;
    }
    return 3;
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M')
            M[i][x[i]]++;
        else
            X[i][x[i]]++;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] += M[i - 1][j];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            X[i][j] += X[i + 1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'E') {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int mex = MEX(x[i], j, k);
                ans += mex * M[i][j]* X[i][k];
            }
        }
    }
    put(ans);
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