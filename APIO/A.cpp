/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;
int draw_territory(int N, int A, int B, int[] D, int[] L)
{
    
}
void sol()
{
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        int d[n],l[n];
        fr(i,0,n)
        {
            cin>>d[i];
        }
        fr(i,0,n)
        {
            cin>>l[i];
        }
        cout<<draw_territory(n,a,b,d,l)<<endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}