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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
pii x[MAXN];
bool cmp(pii a, pii b)
{
	if(a.F != b.F) return a.F < b.F;
	else return a.S < b.S;
}

bool cmp1(pii a, pii b)
{
	if(a.F != b.F) return a.F > b.F;
	else return a.S < b.S;
}
int s[MAXN];
void sol()
{
	cin >> n;
	int all = 0;
	for(int i = 0; i < n; i++) 
	{
		cin >> x[i].F;
		all += x[i].F;
	}
	vector<int> v;
	for(int i = 0; i < n; i++) cin >> x[i].S;
	sort(x, x + n, cmp);
	multiset<pii> st1, st2;
	multiset<pii> in;
	for(int i = 0; i < n; i++)
	{
		st1.insert({x[i].F, x[i].S});
		st2.insert({x[i].S, x[i].F});
	}
	int now = 0;
	int ouo = 0, ouo1 = 0;
	for(int i = 0; i < n; i++)
	{
		//cout << "I" << endl;
		//put(in.size() + in.size());
		//put(ouo)
		
		
		//cout << (*st2.begin()).F << " " << (*st2.begin()).S << endl;
		if((*st2.begin()).F <= i) // no add
		{
			auto tmp = *(--st2.upper_bound({i, INF}));
			//cout << tmp.S << " " << tmp.F << endl;
			st2.erase(st2.find(tmp));
			st1.erase(st1.find({tmp.S, tmp.F}));
			if(tmp.F >= ouo)
			{
				ouo1 = ouo;
				ouo = tmp.F;
			}
			// cmax(ouo, tmp.F);
			//cout << "no add" << endl;
		}
		else
		{
			auto tmp = *st1.begin();
			now += tmp.F;
			st1.erase(st1.find(tmp));
			st2.erase(st2.find({tmp.S, tmp.F}));
			in.insert({tmp.F, tmp.S});
			if(tmp.S >= ouo)
			{
				ouo1 = ouo;
				ouo = tmp.S;
			}
			//cout << tmp.F << " " << tmp.S << endl;
			//cout << "add" << endl;
		}
		auto ii = --in.end();
		pii mx = {-1, -1}, mx2 = {-1, -1};
		bool awa = 0;
		vii EEE;
		ouo = INF;
		for(pii it: in)
		{
			//put(it.F);
			cmin(ouo, it.S);
		}
		//put(ouo);
		if(ouo < i) ouo = INF;
		//put(ouo);
		while(in.size())
		{
			pii it = *ii;
			//cout << it.F << " " << it.S << endl;
			if(it.S <= i && it.S != ouo)
			{
				if(it.F > mx.F)
				{
					mx.F = it.F, mx.S = it.S;
					mx2 = mx;
				}
				//cmax(mx, {it.S, it.F});
				//EEE.pb({it});

				//break;
			}
			else if(it.S <= i)
			{
				if(it.F > mx2.F)
				{
					mx = mx2;
					mx2.F = it.F, mx2.S = it.S;
				}
				if(awa) 
				{
					//EEE.pb({it});
				}
				//awa = 1;
			}
			if(ii != in.begin())
				ii--;
			else break;
		}
		if(mx.F != -1)
		{
			//cout << mx.F << " " << mx.S << endl;
			now -= mx.F;
			in.erase(in.find({mx.F, mx.S}));
		}
		
		// for(pii it: EEE)
		// {
			// now -= it.S;
			// cout << it.F << " " << it.S << endl;
			// in.erase(in.find(it));
		// }
		//cout << endl;
		v.pb({all - now});
	}
	for(int i = 0; i < n; i++)
	{
		cout << v[i] << " \n"[i == n - 1];
	}
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