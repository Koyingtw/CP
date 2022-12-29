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
#define MAXN 500005
#define MAXM 1000005 
int n, m;

int p[MAXN], Log[MAXN];

int fpow(int a, int b) {
    int ans = 1;
    double anslg = 0;
    double lg = log10(a);
    while (b) {
        if (b & 1) {
            ans = ans * a % P;
            anslg += lg;
        }
        a = a * a % P;
        lg *= 2;
        b >>= 1;
    }
    return ans;
}

void pre() {
    p[0] = 1;
    Log[0] = log10(1);
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] * i;
        p[i] %= P;
        Log[i] = Log[i - 1] + log10(i);
    }
}

void sol() {
    cin >> n >> m;
    pre();
    int sum = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sum += p[a];
        sum %= P;
    }

    int res = sum * fpow(p[m], P - 2) % P;

    cout << sum << ' ' << p[m] << endl;
    cout << sum * fpow(p[m], P - 2) % P << endl;
    cout << (res * p[m]) % P << endl;

    if ((res * p[m]) % P == sum) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
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