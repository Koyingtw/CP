// Problem: F. 等價交換
// Contest: Codeforces - 2021 AA 競程 秋季 Level 1 期末測驗
// URL: https://codeforces.com/gym/356593/problem/F
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
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
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
    vector<bool> x((1 << 11), true);
    prime.push_back(2);
    prime.push_back(3);
    x[0] = 0;
    x[1] = 0;
    for (int i = 5; i <= (1 << 11); i += 2)
    {
        if (six(i) == false)
            i += 2;
        if (x[i])
        {
            if (i < 215)
            {
                for (int j = i * i; j < (1 << 11); j += i)
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
	pre();
	cin >> n;
	map<int, int> ma, mb;
	for(int i = 0, in; i < n; i++)
	{
		cin >> in;
		for(int it: prime)
		{
			if(in == 1) break;
			while(in % it == 0)
			{
				ma[it]++;
				in /= it;
			}
		}
	}
	for(int i = 0, in; i < n; i++)
	{
		cin >> in;
		for(int it: prime)
		{
			if(in == 1) break;
			while(in % it == 0)
			{
				mb[it]++;
				in /= it;
			}
		}
	}
	bool yes = (ma.size() == mb.size());
	// put(yes)
	for(auto [F, R]: ma)
	{
		yes &= (ma[F] == mb[F]);
		//cout << F << " " << ma[F] <<  " " << mb[F] << endl;
	}
	if(yes) cout << "Yes" << endl;
	else cout << "No" << endl;
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