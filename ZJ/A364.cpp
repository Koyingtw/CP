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
int a[20];


void pre()
{
	a[0] = 1;
	for(int i = 1; i < 20; i++)
	{
		a[i] = a[i - 1] * i;
	}
}

int f(int i, int j)
{
	if(j > i) return 0;
	else return a[i] / (a[j] * a[i - j]);
}

void sol()
{
	cin >> n;
	bool ans = 0;
	for(int i = 2; i < 20 && !ans; i++)
	{
		for(int j = 1; j < i && !ans; j++)
		{
			for(int k = 0; k < j && !ans; k++)
			{
				if(f(i, 3) + f(j, 2) + f(k, 1) == n)
				{
					cout << i << j << k << endl;
					ans = 1;
					return;
				}
			}
		}
	}
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