#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

bool check(string s) {
	while(s.size() > 1) {
		int tmp = 0;
		for(int i = 0; i < s.size(); i++)
			tmp += s[i] - '0';
		s = to_string(tmp);
	}
	return (s[0] - '0' == m);
}

void sol() {
	cin >> n >> m;
	cin.ignore();
	string s;
	cin >> s;
	vector<string> v;
	for(char k = '0'; k <= '9'; k++) {
		for(int i = 0; i < n; i++) {
			string tmp;
			for(int j = 0; j < i; j++)
				tmp += s[j];
			tmp += k;
			for(int j = i; j < s.size(); j++)
				tmp += s[j];
			if(check(tmp))
				v.pb(tmp);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i < v.size() - 1; i++)
		cout << v[i] << endl;
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