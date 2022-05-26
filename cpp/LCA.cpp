 
void rec(lol x,lol p)
{
    timer++;
    tin[x]=timer;
    lol i=0;
    up[x][0]=p;
    for (i=1;i<=20;i++) up[x][i]=up[up[x][i-1]][i-1];
    for (i=0;i<ss[x].size();i++) if (ss[x][i]!=p) rec(ss[x][i],x);
    timer++;
    tout[x]=timer;
}
 
bool upp(lol a,lol b)
{
    return tin[a]<tin[b] && tout[a]>tout[b];
}
 
lol lca(lol a,lol b)
{
    lol i=0;
    if (upp(a,b)) return a;
    if (upp(b,a)) return b;
    for (i=20;i>=0;i--)
    {
        if (!upp(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
 
int main()
{
    tin[0]=-mx;tout[0]=mx;
    for(i=1;i<=m;i++)
    {
        cin>>p1>>p2;
        ss[p1].push_back(p2);
        ss[p2].push_back(p1);
    }
    rec(1,0);
    w=0;
    for (i=1;i<=k;i++)
    {
        cin>>p1>>p2;
        lol res=lca(p1,p2);
        cout<<res<<endl;
    }
}
 
