#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <cstdlib>
#include <complex>
#include <vector>
 
using namespace std;
 
typedef long long lol;
typedef pair<lol, lol> pll;
typedef long double lod;
 
const lol N=4000200;
const lol M=100000;
const lol md=4294967296;
const lol mn=(1e16);
 
#define F first
#define S second
#define y1 yy1
#define sqr(a) (a)*(a)
 
bool comp(pll a, pll b)
{
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
 
lol bp(lol a,lol b)
{
	if (b == 0) return 1;
	if (b % 2 == 1) return (bp(a, b-1) * a)%md;
	else { lol c =(bp (a, b/2))%md; return (c * c)%md; }
}
 
struct item
{
    int key,prior;
    item * l, *r;
    item() {}
    item(lol key,lol prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};
typedef item * pitem;
 
void split(pitem t, lol key, pitem &l, pitem &r)
{
    if (!t) l=r=NULL;
    else if (key < t->key) {
            pitem ll , rr;
            split(t->l, key, ll, rr);
 
            r=t;
    }
    else {
        pitem ll , rr;
        split(t->r, key, ll , rr);
        r->r = ll;
        r = rr;
        l=t;
    }
}
 
void merge(pitem & t, pitem l, pitem r)
{
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior) { merge(l->r, l->r, r); t=l; }
    else { merge(r->l, l, r->l); t=r; }
}
 
void insert(pitem & t, pitem it)
{
    if (!t) t=it;
    pitem l,r;
    split(t, it->key, l, r);
    merge(t, l, it);
    merge(t, t, r);
}
 
void print(pitem q)
{
    if (!q) return;
    cout << q->key << endl;
    print(q->l);
    cout<<q->key<<" ";
    print(q->r);
}
 
lol i,m,n,j,k,l;
 
int main()
{
    //freopen("sort.in","r",stdin);
    //freopen("sort.out","w",stdout);
    ios_base::sync_with_stdio(0);
 
    cin>>n;
    pitem root = NULL;
    for (i=1;i<=n;i++) {
        cin>>m;
        cout << i << endl;
        pitem z=new item(m,rand());
        insert(root, z);
    }
    cout << "Hello" <<  endl;
    print(root);
}
