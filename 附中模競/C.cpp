// Problem: C. HNO3 與 Discord (Discord)
// Contest: Codeforces - 110 師大附中／延平中學 競技程式讀書會 模擬競賽 I
// URL: https://codeforces.com/gym/351808/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define MAXN 200005
#define MAXM 1000005 
int n, k;
pii x[MAXN];

bool cmp(pii a, pii b)
{
	if(a.S != b.S) return a.S < b.S;
	else return a.F < b.F;
}
void sol()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> x[i].F >> x[i].S;
	sort(x, x + n, cmp);
	bitset<MAXN> vis;
	int cnt = 0, now = 0;
	for(int t = 0; t < k && cnt < n; t++)
	{
		now = 0;
		for(int i = 0; i < n; i++)
		{
			if(vis[i]) continue;
			if(now < x[i].F)
			{
				now = x[i].S;
				cnt++;
				vis[i] = 1;
				//cout << i << " ";
			}
		}
		//cout << endl;
	}
	if(cnt == n) cout << "Yes" << endl;
	else cout << "No" << endl;
}

void sol1()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> x[i].F >> x[i].S;
	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		mp[x[i].F]++;
		mp[x[i].S + 1]--;
	} 
	int mx = 0, cnt = 0;
	for(auto [a, b]: mp)
	{
		cnt += b;
		cmax(mx, cnt);
	}
	cout << (mx <= k ? "Yes" : "No") << endl;
}
signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol1();
        }
    }
        
    return 0;
}