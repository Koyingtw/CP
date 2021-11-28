// Problem: F. Keep talking and nobody explodes – easy
// Contest: Codeforces - AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)
// URL: https://codeforces.com/contest/1302/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int x[6];
void spin(int i, int val)
{
	x[i] = (x[i] + val) % 10;
}
void sol()
{
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) x[i + 1] = s[i] - '0';
	if(x[1] + x[4] > 10) spin(1, 3);
	else spin(4, 8);
	
	if(x[3] + x[2] > 8) spin(4, 9);
	else spin(5, 8);
	
	if(x[3] & 1) spin(3, 3);
	else spin(3, 4);
	
	if(x[5] > x[2]) spin(4, 1);
	else spin(2, 7);
	
	if(x[1] & 1) spin(1, 3);
	else spin(3, 5);
	
	if(x[4] & 1) spin(4, 7);
	else spin(1, 9);
	
	if(x[4] > x[1]) spin(4, 9);
	else spin(4, 2);
	
	if(x[1] > x[3]) spin(2, 1);
	else spin(3, 1);
	
	if(x[5] > x[3]) spin(4, 5);
	else spin(5, 8);
	
	if(x[1] + x[3] > 8) spin(4, 5);
	else spin(2, 5);
	
	if(x[1] > x[4]) spin(4, 3);
	else spin(2, 3);
	
	if(x[3] + x[1] > 9) spin(2, 9);
	else spin(2, 2);
	
	if(x[4] + x[3] > 10) spin(4, 7);
	else spin(5, 7);
	
	if(x[3] > x[2]) spin(3, 2);
	else spin(4, 6);
	
	if(x[1] > x[3]) spin(1, 9);
	else spin(2, 9);
	
	if(x[3] & 1) spin(3, 9);
	else spin(1, 5);
	
	if(x[3] + x[5] > 9) spin(3, 4);
	spin(3, 9);
	
	if(x[3] > x[1]) spin(5, 1);
	else spin(5, 7);
	
	if(x[1] > x[3]) spin(2, 9);
	else spin(4, 6);
	
	if(x[2] + x[3] > 10) spin(2, 2);
	else spin(3, 6);
	
	for(int i = 1; i <= 5; i++) cout << x[i];
	cout << endl;
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