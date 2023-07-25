#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define MS(x,y) memset(x,y,sizeof(x))
#define SZ(x) ((int)x.size())
#define MIN -0x3f3f3f3f
#define MAX 0x3f3f3f3f
#define iofast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 


signed main() {
    iofast;
    int t=1;
    cin>>t;
    while(t--){
        int n;
        int a,b,c;
        cin >> n;
        //s0常數，s1分數，s2複數
        set<int>s0;
        set<pair<int,int>>s1;
        set<pair<pair<int,int>,int>>s2;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            if(a==0&&b==0){
                continue;
            }
            else if(a==0){
                int g=abs(__gcd(b,c));
                b/=g;c/=g;
                if(c==1)
                    s0.insert(b);
                else if(c==-1)
                    s0.insert(-b);
                else{
                    if(b<0)
                        b*=-1,c*=-1;
                    s1.insert({c,b});
                }
            }
            else{
                int x,y,z;
                x=a*2;
                y=-b;
                z=b*b-4*a*c;
                if(z>0&&sqrt(z)*sqrt(z)==z){
                    y+=sqrt(z);
                    z=0;
                }
                int g=abs(__gcd(x,y));
                g=abs(__gcd(g,z));
                x/=g;y/=g;z/=g;
                if(z==0){
                    if(x==1)
                        s0.insert(y);
                    else if(x==-1)
                        s0.insert(-y);
                    else{
                        if(x<0)
                            x*=-1,y*=-1;
                        s1.insert({y,x});
                    }
                }
                else{
                    if(z<0)
                        z*=-1,x*=-1,y*=-1;
                    s2.insert({{y,z},x});
                }
            }
        }
        cout<<s0.size()+s1.size()+s2.size()<<'\n';
    }
 
    return 0;
}
 

/*
4
4
1 -1 1
1 2 0
1 -2 1
-50 100 0
5
0 0 45510
0 45 510
4 55 10
45 5 10
455 1 0
3
0 1 -2
0 2 -3
0 4 -6
2
0 0 1
0 0 -1
*/