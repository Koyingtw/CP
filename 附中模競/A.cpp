// Problem: A. 有沒有出題者不知道要出什麼題目的八卦 (Bagua)
// Contest: Codeforces - 110 師大附中／延平中學 競技程式讀書會 模擬競賽 I
// URL: https://codeforces.com/gym/351808/problem/A
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

void sol()
{
	cin >> n;
	cin.ignore();
	string s;
	cin >> s;
	int len = 2 * n + 1;
	reverse(s.begin(), s.end());
	for(int i = 0; i < len; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = 0; j < len; j++)
				cout << '.';
			cout << endl;
		}
		else
		{
			cout << '.';
			for(int j = 1; j < len - 1; j++)
			{
				if(j == n)
				{
					cout << (s[i / 2] == '1' ? '#' : '.');
				}
				else cout << '#';
			}
			cout << '.' << endl;
		}
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