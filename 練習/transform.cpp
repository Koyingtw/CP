#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

string f(string s,int a,int b)
{
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        int j=s.size()-i-1;
        if(s[i]>='a') int a=s[i]-'a'+10;
        else int a=s[i]-'0';
        sum+=a*pow(a,i);
    }
    cout<<a<<endl;
    vector<char> v;
    while(sum)
    {
        if(sum%b<10)
        {
            v.push_back(sum%b+'0');
        }
        else
        {
            char c=sum%b-10+'a';
            v.push_back(c);
        }
        sum/=b;
    }
    string ans;
    for(int i=v.size()-1;i>0;i--)
    {
        ans+=v[i];
    }
    return ans;
}

void sol()
{
    int a,b;
    string n;
    while(cin>>n>>a>>b)
    {
        cout<<f(n,a,b)<<endl;
    }
}

signed main()
{
    Koying 
    sol();
    return 0;
}