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
pii x[MAXN], y[MAXN];

bool cmp(pii a, pii b)
{
	if(a.S != b.S) return a.S < b.S;
	else return a.F < b.F;
}
void sol()
{
	int X, Y;
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++)
			cin >> x[i].F >> x[i].S;
		for(int i = 0; i < m; i++)
			cin >> y[i].F >> y[i].S;
		sort(x, x + n, cmp);
		sort(y, y + m, cmp);
		cin >> X >> Y;
		
		int cnta = 1, cntb = 1;
		int tmpa = X, tmpb = X;
		int nowa = X, nowb = X;
		for(int i = 0; i < n && nowa < Y; i++)
		{
			if(x[i].F <= tmpa)
				cmax(nowa, x[i].S);
			if(x[i].F > tmpa && x[i].S <= nowa)
			{
				cnta++;
				tmpa = nowa;
				nowa = x[i].S;
			}
		}
		
		for(int i = 0; i < m && nowb < Y; i++)
		{
			if(y[i].F <= tmpb)
				cmax(nowb, y[i].S);
			if(y[i].F > tmpb && y[i].S <= nowb)
			{
				cntb++;
				tmpb = nowb;
				nowb = y[i].S;
			}
		}
		cout << nowa << " " << nowb << endl;
		if(nowa >= Y && nowb >= Y)
			cout << (cnta <= cntb ? "A WIN" : "B WIN") << endl;
		else if(nowa >= Y || nowb >= Y)
			cout << (nowa >= Y ? "A WIN" : "B WIN") << endl;
		else
			cout << "TIE" << endl;
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