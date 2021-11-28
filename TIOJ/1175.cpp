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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
struct BIT{
	int arr[MAXN];
	int query(int x)
	{
		int sum = 0;
		while(x > 0)
		{
			cmax(sum, arr[x]);
			x -= lowbit(x);
		}
		return sum;
	}
	void update(int x, int val)
	{
		while(x < MAXN)
		{
			cmax(arr[x], val);
			x += lowbit(x);
		}
	}
}LIS;
vector<int> v;
void sol()
{
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		v.pb(x[i]);
	}
	MEM(LIS.arr, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 0; i < n; i++)
		x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		//assert(x[i] > 0);
		int tmp = LIS.query(x[i]);
		cmax(ans, tmp);
		//qput(tmp);
		LIS.update(x[i], tmp + 1);
	}
	cout << ans + 1 << endl;
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