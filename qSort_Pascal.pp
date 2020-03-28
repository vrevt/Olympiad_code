uses math;
var
 a,b,f1,f2:array[0..300000]of int64;
 m,n,k,l,w,s,j,r,c,l1,r1,c1,p1,p2,res,c2,l2,r2,c3:int64;
 i:longint;
 
procedure qsort1(l,r:longint);
var
 i,j,m,t:longint;
begin
 i:=l;j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  t:=a[i]; a[i]:=a[j]; a[j]:=t;
  inc(i); dec(j);
 until i>j;
 if j>l then qsort1(l,j);
 if i<r then qsort1(i,r);
end;
 
procedure qsort2(l,r:longint);
var
 i,j,m,t:longint;
begin
 i:=l;j:=r;
 m:=b[l+random(r-l+1)];
 repeat
  while b[i]<m do inc(i);
  while b[j]>m do dec(j);
  if i>j then break;
  t:=b[i]; b[i]:=b[j]; b[j]:=t;
  inc(i); dec(j);
 until i>j;
 if j>l then qsort2(l,j);
 if i<r then qsort2(i,r);
end;
 
function check(s:int64):int64;
begin
 w:=0;
 for i:=1 to n do if a[i]<s then inc(w,abs(a[i]-s));
 for i:=1 to m do if b[i]>s then inc(w,abs(b[i]-s));
 check:=w;
end;
 
begin
 readln(n,m);
 for i:=1 to n do read(a[i]); qsort1(1,n); for i:=1 to n do f1[i]:=f1[i-1]+a[i];
 for i:=1 to m do read(b[i]); qsort2(1,m); for i:=1 to m do f2[i]:=f2[i-1]+b[i];
 res:=high(int64);
 l:=1;
 r:=1000000000;
 while (r-l)>1 do
 begin
  c1:=(l+l+r)div 3;
  c2:=(r+r+l)div 3;
  if check(c1)<check(c2) then r:=c2 else l:=c1+1;
 end;
 l2:=l; r2:=r;
 c1:=check(l2);
 c2:=check(r2);
 writeln(min(c1,c2));
end.
