#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long lol;
typedef long double lod;
 
const lol N=300000;
const lol M=30000000;
const lol md=(1e9)+7;
const lol mx=(1e18);
const lol mn=(1e16);
 
#define F first
#define S second
#define fi first
#define se second
#define y1 yy1
#define sqr(a) ((a)*(a))
#define time dsafgms
 
bool comp(pair<lol,lol> a,pair<lol,lol> b)
{
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
 
lol bp(lol a,lol b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return bp (a, b-1) * a;
	else { lol c = bp (a, b/2); return (c * c)%md; }
}
 
lol n,m,k,l,w,j,i,a[N],st,x,b[N],f[N];
string s,s1[N],s2[N],ss;
map<string,string> mp;
 
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("INVERSE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
 
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        mp[s2[i]]=s1[i];
    }
    for (i=1;i<=m;i++)
    {
        cin>>s>>ss;
        ss.erase(ss.size()-1,1);
        cout<<s<<" "<<ss<<"; #"<<mp[ss]<<endl;
    }
 
}
