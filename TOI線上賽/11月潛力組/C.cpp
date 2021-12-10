#pragma region
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 80005
#define MAXM 80005
int n, m;
const int k = 20000;

bitset<MAXM> x[k * 2];
int in[MAXN];

void update(int i, int val)
{
	x[(i) / k][val] = true;
}

int query(int a, int b)
{
	bitset<MAXM> tmp;
	for(; a <= b && (a) % k != 0; a++)
	{
		tmp[in[a]] = true;
		// cout << in[a] << endl;
	}
	for(; a < b - (b % k); a += k)
	{
		tmp |= x[(a) / k];
		// put(a);
	}
	for(; a <= b; a++)
		tmp[in[a]] = true;
	return tmp.count();
}
void sol()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> in[i];
		update(i, in[i]);
	}
	cin >> m;
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		a--, b--;
		cout << query(a, b) << endl;
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