геом
 
 A = P_y - Q_y, 
 B = Q_x - P_x, 
 C = - A P_x - B P_y. 
 
 точка пересечения прямых
 x=-(c1*b2-c2*b1);
 y=(a1*b2-a2*b1);
 
 пересечение окружности и прямой
 
double r, a, b, c; // входные данные
 
double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
if (c*c > r*r*(a*a+b*b)+EPS)
	puts ("no points");
else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
	puts ("1 point");
	cout << x0 << ' ' << y0 << '\n';
}
else {
	double d = r*r - c*c/(a*a+b*b);
	double mult = sqrt (d / (a*a+b*b));
	double ax,ay,bx,by;
	ax = x0 + b * mult;
	bx = x0 - b * mult;
	ay = y0 - a * mult;
	by = y0 + a * mult;
	puts ("2 points");
	cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
}
 
угол между векторами
cin>>x1>>y1>>x2>>y2;
p=(x1*x2+y1*y2)/(sqrt(sqr(x1)+sqr(y1))*sqrt(sqr(x2)+sqr(y2)));
p=acos(p);
cout<<fixed<<setprecision(10)<<p;
 
растояние от точки до прямой
cin>>x>>y>>a>>b>>c;
s=abs(a*x+b*y+c)/sqrt(sqr(a)+sqr(b));
cout<<fixed<<setprecision(10)<<s;
 
 
