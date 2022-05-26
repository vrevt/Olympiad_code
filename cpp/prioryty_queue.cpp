#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <complex>
#include <queue>
 
#define F first
#define S second
#define y1 yy1
#define sqr(a) (a)*(a)
#define mp make_pare
 
using namespace std;
 
typedef long long lol;
typedef pair<lol, lol> pll;
 
const lol N=5*(1e5);
const lol md=1000000007;
const lol mx=(1e18);
const long double pi=3.1415926535897932384626433832795;
 
lol n,m,k,l,w,s,j,i,f[N],x,p1,p2,p3,xx;
vector<lol> ss[N],sc[N];
priority_queue<pair<lol,lol> > q;
pair <lol,lol> pp;
 
bool comp(pll a, pll b)
{
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
 
lol bp(lol a,lol b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return (bp(a, b-1) * a)%md;
	else { lol c =(bp (a, b/2))%md; return (c * c)%md; }
}
 
int main()
{
    freopen("bparty.in","r",stdin);
    freopen("bparty.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>x;
    for (i=1;i<=m;i++)
    {
        cin>>p1>>p2>>p3;
        ss[p1].push_back(p2);sc[p1].push_back(p3);
        ss[p2].push_back(p1);sc[p2].push_back(p3);
    }
    for (i=1;i<=n;i++) f[i]=mx;
    f[x]=0;
    q.push(make_pair(lol(0),x));
    while (q.size())
    {
        pp=q.top();
        xx=pp.S;
        q.pop();
        for (j=0;j<ss[xx].size();j++)
        {
            lol e=f[xx]+sc[xx][j];
            if (e<f[ss[xx][j]]) { f[ss[xx][j]]=e; q.push(make_pair(e,ss[xx][j])); }
        }
    }
    w=0;
    for (i=1;i<=n;i++) w=max(w,f[i]);
    cout<<w*2<<endl;
}
 
