void pudg(lol vv,lol l,lol r)
{
    if (t[vv]==0 || l==r) return;
    lol mid=(l+r)/2;
    t[vv*2]+=t[vv]; s[vv*2]+=t[vv]*(mid-l+1);
    t[vv*2+1]+=t[vv]; s[vv*2+1]+=t[vv]*(r-mid);
    t[vv]=0;
}
 
void modify(lol v,lol tl,lol tr,lol l,lol r,lol val)
{
    pudg(v,tl,tr);
    if (l>r) return;
    if (l==tl && r==tr) { t[v]+=val; s[v]+=(r-l+1)*val;return; }
    lol mid=(tl+tr)/2;
    pudg(v,tl,tr);
    modify(v*2,tl,mid,l,min(r,mid),val);
    modify(v*2+1,mid+1,tr,max(mid+1,l),r,val);
    s[v]=s[v*2]+s[v*2+1];
}
 
void get(lol v,lol tl,lol tr,lol l, lol r)
{
    if (l>r) return;
    pudg(v,tl,tr);
    if (l==tl && r==tr) { w+=s[v]; return;}
    lol mid=(tl+tr)/2;
    pudg(v,tl,tr);
    get(v*2,tl,mid,l,min(r,mid));
    get(v*2+1,mid+1,tr,max(l,mid+1),r);
}
