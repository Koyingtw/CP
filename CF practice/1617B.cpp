// Problem: B. GCD Problem
// Contest: Codeforces - Codeforces Round #761 (Div. 2)
// URL: https://codeforces.com/contest/1617/problem/B
// Memory Limit: 256 MB
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
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
bool six(int n)
{
    if ((n % 6 == 1 || n % 6 == 5))
        return true;
    else
        return false;
}
vector<int> prime;
void pre()
{
    vector<bool> x(46341, true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= 46341; i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 215)
            {
                for (int j = i * i; j < 46341; j += i)
                {
                    x[j] = false;
                }
            }
            prime.push_back(i);
        }
    }
}
void sol()
{
	cin >> n;
	int a, b, c;
	if(n % 2 == 0)
	{
		cout << (n - 1) / 2 + 1 << " " << (n - 1) / 2 << " " << 1 << endl;
	}
	else if(((n - 1) / 2) % 2 == 1)
	{
		cout << n / 2 - 2 << " " << n / 2 + 2 << " " << 1 << endl;
	}
	else
	{
		cout << n / 2 - 1 << " " << n / 2 + 1 << " " << 1 << endl;
	}
	// c = __gcd(n, 3ll);
	// cout << c << endl;
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