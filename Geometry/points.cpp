
#include<bits/stdc++.h>
using namespace std;
/**
********************************************************************
******************* Author:Bisnu sarkar ****************************
********************************************************************
**/
#define ull            unsigned long long
#define ll             long long
#define vi             vector<int>
#define pb             push_back
#define mp             make_pair
#define pii            pair<int,int>
#define vit            vector<int> :: iterator
#define sit            set<int> :: iterator
#define vrit           vector<int> :: reverse iterator
#define ff             first
#define ss             second
#define endl           '\n';
#define what_is(x)     cerr << #x << " is " << x << endl;
///*....Debugger....*/
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it){   cout << endl ;}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}
int ini(){int x; scanf("%d",&x);return x;}
long long inl(){ long long x;scanf("%lld",&x); return x;}
double ind(){double x; scanf("%lf",&x);return x;}
#define Iin ini();
#define Lin inl();
#define Din ind();

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);
const double eps=1e-9;


struct point
{
	double x,y;
	point(){x=y=0.0;};
	point(double _x,double _y): x(_x),y(_y){}

	bool operator <(point other) const {
		if(fabs(x - other.x)>eps)return x<other.x;
		return y < other.y;
	}
	bool operator ==(point other)const{
		return (fabs(x-other.x)< eps and fabs(y-other.y)< eps);
	}
};
point p[N];

double dis(point p1,point p2){
	return hypot(p1.x - p2.x, p1.y-p2.y);
}
point rotate(point p,double theta){
	double rad = (theta*pi)/180.0;
	return point(p.x*cos(rad) - p.y*(sin(rad)), p.x*sin(rad) + p.y*sin(rad));
}

int main()
{
	int n=ini();

	for(int i=1;i<=n;i++){
		double x,y;
		x=Din;y=Din;
		p[i]={x,y};
	}
	sort(p+1,p+n+1);

	for(int i=1;i<=n;i++){
		cout<<p[i].x<<" "<<p[i].y<<endl;
	}

	printf("%d\n", p[1]==p[2]);   	
	printf("%f\n", dis(p[1],p[2]));
	point xx=rotate(p[1],90);
	printf("%f %f\n",xx.x,xx.y);

    return 0;
}
