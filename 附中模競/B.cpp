// Problem: B. 培育資訊之芽 (Sprout)
// Contest: Codeforces - 110 師大附中／延平中學 競技程式讀書會 模擬競賽 I
// URL: https://codeforces.com/gym/351808/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int INF = 0x3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, t;
pii x[MAXN];
pii tp[MAXN];
bool cmp(pii a, pii b)
{
	if((a.S < 0 && b.S <= 0) || a.S * b.S <= 0) 
		return a.S < b.S;
	// if(a.F > 0 && b.F >= 0 || a.F * b.F <= 0) 
		// return ((a.S + a.F - 1) / a.F) < ((b.S + b.F - 1) / b.F);
	if(a.F == 0 || b.F == 0) return a.F != 0;
	if(-((a.S + a.F - 1) / a.F) != -((b.S + b.F - 1) / b.F))
	return -((a.S + a.F - 1) / a.F) < -((b.S + b.F - 1) / b.F);
	else return a.S < b.S;
	
}
void sol0()
{
	int ans = INF;
	int tmp = 0, mn = INF, mx = -INF, neg = -INF;

	tmp = 0, mn = 0, mx = -INF, neg = -INF;
	int k = 0;
	//put(k);
	bool allneg = 1;
	for(int j = 0; j < n; j++)
	{
		tmp += x[j].S;
		if(mn != INF)
			cmax(mx, tmp - mn);
		else cmax(mx, tmp);
		cmin(mn, tmp);
	}
	put(mx);
}
void sol1()
{
	int ans = INF;
	int tmp = 0, mn = INF, mx = -INF, neg = -INF;
	for(int i = 0; i <= t; i++)
	{
		tmp = 0, mn = 0, mx = -INF, neg = -INF;
		int k = i;
		//put(k);
		bool allneg = 1;
		for(int j = 0; j < n; j++)
		{
			tmp += x[j].S + k * (x[j].F);
			if(mn != INF)
				cmax(mx, tmp - mn);
			else cmax(mx, tmp);
			cmin(mn, tmp);
		}
		cmin(ans, mx);
	}
	put(ans);
}

void sol2()
{
	int ans = INF;
	int tmp = 0, mn = 0, mx = -INF, neg = -INF;
	for(int i = 0; i < n; i++) cmax(mx, x[i].F), cmin(mn, x[i].F);
	if(mn >= 0)
	{
		cout << 0 << endl;
	}
	else if(mx <= 0)
	{
		int k = t;
		tmp = 0, mn = 0, mx = -INF, neg = -INF;
		for(int j = 0; j < n; j++)
		{
			tmp += x[j].S + k * (x[j].F);
			if(mn != INF)
				cmax(mx, tmp - mn);
			else cmax(mx, tmp);
			cmin(mn, tmp);
			//put(mx);
		}
		put(mx);
	}
	else cout << 0 << endl;
}
void sol()
{
	cin >> n >> t;
	bool zero = 1;
	bool st = 1;
	for(int i = 0; i < n; i++)
	{
	 	cin >> x[i].F;
		if(x[i].F < 0) st = 0;
	}
	for(int i = 0; i < n; i++) 
	{
		cin >> x[i].S;
		if(x[i].S != 0) zero = 0;
	}
	if(zero)
	{
		sol2();
		return;
	}
	if(st)
	{
		sol0();
		return;
	}
	if(t <= 100)
	{
		sol1();
		return;
	}
	for(int i = 0; i < n; i++) tp[i] = x[i];
	//sort(tp, tp + n, cmp);
	set<int> s;
	s.insert(0);
	for(int i = 0; i < n; i++)
	{
		if(tp[i].S > 0 && tp[i].F < 0)
			s.insert(-((tp[i].S - tp[i].F + 1) / tp[i].F) - 1);
	}
	int ans = INF;
	int tmp = 0, mn = 0, mx = -INF, neg = -INF;
	for(int k: s)
	{
		tmp = 0, mn = 0, mx = -INF, neg = -INF;
		//for(int ouo = 0; ouo < 3; ouo++, k++)
		
		if(k > t) break;
		for(int j = 0; j < n; j++)
		{
			tmp += x[j].S + k * (x[j].F);
			if(mn != INF) cmax(mx, tmp - mn);
			else cmax(mx, tmp);
			cmin(mn, tmp);
			if(mx > ans) break;
		}
		cmin(ans, mx);
	}
	
	tmp = 0, mn = 0, mx = -INF, neg = -INF;

	int k = t;
	for(int j = 0; j < n; j++)
	{
		tmp += x[j].S + k * (x[j].F);
		if(mn != INF) cmax(mx, tmp - mn);
		else cmax(mx, tmp);
		cmin(mn, tmp);
	}
	cmin(ans, mx);
	put(ans);
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