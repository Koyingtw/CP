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

char f(char c)
{
	if(c == '0') return '1';
	else return '0';
}

void sol()
{
	cin >> n;
	cin.ignore();
	string s;
	cin >> s;
	if(n == 1)
	{
		cout << "Yes" << endl;
		return;
	}
	if(n <= 2 && s[0] != s[1])
	{
		cout << "No" << endl;
		return;
	}
	if(n == 3)
	{
		cout << "Yes" << endl;
		return;
	}
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == '1')
		{
			s[i] = f(s[i]);
			s[i + 1] = f(s[i + 1]);
			if(i + 2 != n) s[i + 2] = f(s[i + 2]);
		}
	}
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0') cnt0++;
		else cnt1++;
	}
	if(cnt0 % 3 == 1 && cnt1 % 3 == 1) cout << "No" << endl;
	else cout << "Yes" << endl;
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