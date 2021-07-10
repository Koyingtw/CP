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

void OUT(string s) {cout<<s; return;} 

void sol()
{
    string a,b;
    string A={"SHDC"}, B={"A23456789TJQK"};
    while(cin >> a >> b)
    {
        fr(i,0,4)
        {
            if(a[0]==A[i])
            {
                if(i==0)
                {
                    if(b[0]=='K')
                    {
                        OUT("IMPOSSIBLE");
                        cout<<endl;
                    }
                    else
                    {
                        fr(j,0,12)
                        {
                            if(b[0]==B[j])
                            {
                                cout << A[3] << " "<<B[j+1] <<endl;
                            }
                        }
                        
                    }
                }
                else
                {
                    cout<<A[i-1]<<" "<<b<<endl;
                }
            }
        }
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}