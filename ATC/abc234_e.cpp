// Problem: E - Arithmetic Number
// Contest: AtCoder - AtCoder Beginner Contest 234
// URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
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
#define putar(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
vector<int> p;

void pre() {
	for (int i = 1; i < 10; i++) {
		for (int k = -9; k < 10; k++) {
			string now = to_string(i);
			while (now[now.size() - 1] - '0' + k < 10 && now[now.size() - 1] - '0' + k >= 0 && now.size() < 18) {
				now += to_string(now[now.size() - 1] - '0' + k);
				p.pb(stoll(now));
			}
		}
	}
	sort(all(p));
	// for (int it: p)
		// cout << it << endl;
}

void sol()
{
	pre();
	string s, ans = "1";
	cin >> s;
	vector<int> v;
	for (char c: s) {
		v.pb(c - '0');
		ans += "1";
	}
	
	if (s.size() == 1) {
		cout << s << endl;
		return;
	}

	if (s.size() == 2) {
		cout << s << endl;
		return;
	}
	
	cout << *lower_bound(all(p), stoll(s)) << endl;
	return;
	bool yes = 1;
	for (int i = 2; i < v.size(); i++) {
		yes &= (v[i] - v[i - 1] == v[1] - v[0]);
	}
	if (yes) ans = s;

	int mx = 9 / (s.size() - 1);
	// cout << mx << endl;
	
	for (int k = -9; k <= 9; k++) {
		string now;
		now += s[0];
		vector<int> vv = v;
		if (k >= 0) {
			for (int i = 1; i < s.size(); i++) {
				if (vv[i - 1] + k < 10 && vv[i - 1] + k >= 0) {
					now += to_string(vv[i - 1] + k);
					vv[i] = vv[i - 1] + k;
				}
			}
			// put(now)
		}
		if (now.size() == s.size()) {
			
			if (stoll(now) >= stoll(s) && stoll(now) < stoll(ans))
				ans = now;
					
		}
		for (int t = v[0] + 1; t < 10; t++) {
			string tmp = to_string(t);
			vv = v;
			vv[0] = t;
			for (int i = 1; i < s.size(); i++) {
				if (vv[i - 1] + k < 10 && vv[i - 1] + k >= 0) {
					tmp += to_string(vv[i - 1] + k);
					vv[i] = vv[i - 1] + k;
				}
			}
			if (tmp.size() == s.size()) {
				if (stoll(tmp) >= stoll(s) && stoll(tmp) < stoll(ans))
					ans = tmp;
			}
		}
	}
	// cout << ("159" > "1111") << endl;
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}