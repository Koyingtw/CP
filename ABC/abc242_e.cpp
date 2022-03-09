// Problem: E - (∀x∀)
// Contest: AtCoder - AtCoder Beginner Contest 242
// URL: https://atcoder.jp/contests/abc242/tasks/abc242_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int p[MAXM];

void pre() {
	p[0] = 1;
	for (int i = 1; i < MAXM; i++) {
		p[i] = p[i - 1] * 26;
		p[i] %= P;
	}
}


void sol()
{

	string s;
	cin >> n >> s;
	string tmp = s.substr(0, (n + 1) / 2);
	reverse(all(tmp));
	string ouo = s.substr(n / 2);
	int ans = 0 - (tmp > ouo);
	reverse(all(tmp));
	vector<int> v;
	for (char c: tmp) {
		v.pb(c - 'A');
	}
	int owo = v.size() - 1;
	for (int it: v) {
		ans += p[owo] * it;
		owo--;
		ans %= P;
	}
	ans++;
	cout << ans % P << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
	pre();
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}