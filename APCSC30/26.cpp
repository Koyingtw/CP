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
bool x[MAXN];
set<pii> s;
multiset<int> sum;

int f(pii a)
{
	return a.S - a.F + 1;
}

void sol()
{
	cin >> n >> m;
	pii tmp = {-1, -1};
	pii cnt = {0, 0};
	int mn = INF, mx = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if(x[i] == 1 && tmp.F == -1)
			tmp = {i, i};
		else if(x[i] == 1)
			tmp.S = i;
		else 
		{
			s.insert(tmp);
			sum.insert(tmp.S - tmp.F + 1);
			cmin(mn, tmp.S - tmp.F + 1);
			cmax(mx, tmp.S - tmp.F + 1);
			tmp = {-1, -1};
			// mn = 0;
		}
	}
	if(tmp.F != -1) s.insert(tmp);
	sum.insert(f(tmp));
	cnt.F += *(prev(sum.end()));
	cnt.S += *sum.begin();
	
	int a;
	while(m--)
	{
		cin >> a;
		if(s.size() == 0)
		{
			s.insert({a, a});
			sum.insert(1);
			cnt.F += *(prev(sum.end()));
			cnt.S += *sum.begin();
		}
		else if(s.size() == 1)
		{
			pii aaaaa = *s.begin();
			if(a == aaaaa.F - 1)
			{
				sum.erase(sum.find(f(aaaaa)));
				s.erase(s.begin());
				s.insert({a, aaaaa.S});
				sum.insert(f({a, aaaaa.S}));
			}
			else if(a == aaaaa.S + 1)
			{
				sum.erase(sum.find(f(aaaaa)));
				s.erase(s.begin());
				s.insert({aaaaa.F, a});
				sum.insert(f({a, aaaaa.S}));
			}
			else
			{
				s.insert({a, a});
				sum.insert(1);
			}
			cnt.F += *(prev(sum.end()));
			cnt.S += *sum.begin();
		}
		pii r = *(s.upper_bound({a, 0}));
		pii l = *prev(s.upper_bound({a, 0}));
		if(l.S == a - 1 && r.F == a + 1)
		{
			tmp = {l.F, r.S};
			s.erase(s.find(l));
			sum.erase(sum.find(f(l)));
			s.erase(s.find(r));
			sum.erase(sum.find(f(r)));
			s.insert(tmp);
			sum.insert(f(tmp));
		}
		else if(l.S == a - 1)
		{
			tmp = {l.F, a};
			s.erase(s.find(l));
			sum.erase(sum.find(f(l)));
			s.insert(tmp);
			sum.insert(f(tmp));
		}
		else if(r.F == a + 1)
		{
			tmp = {a, r.S};
			s.erase(s.find(r));
			sum.erase(sum.find(f(r)));
			s.insert(tmp);
			sum.insert(f(tmp));
		}
		else 
		{
			s.insert({a, a});
			sum.insert(1);
		}
		cnt.F += *(prev(sum.end()));
		cnt.S += *sum.begin();
	}
	cout << cnt.F << endl << cnt.S << endl;
	
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