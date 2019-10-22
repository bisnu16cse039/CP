
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
	point(){x=0,y=0;}
	point(double _x,double _y):x(_x),y(_y) {}
};
struct line
{
	double a,b,c;
};

line pointstoline(point p1,point p2){
	line l;

	if(fabs(p1.x-p2.x)<eps){
		l.a=1.0,l.b=0.0,l.c=-p1.x;
	}
	else{
		l.a =-(p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1.0;
		l.c = - p1.y - l.a*p1.x; 
	}

	return l;
}

bool areparallel(line l1,line l2){
	return (fabs(l1.a-l2.a)<eps and fabs(l1.b - l2.b)<eps);
}

bool aresame(line l1,line l2){
	return areparallel(l1,l2) and (fabs(l1.c-l2.c)<eps);
}

void intersectpoint(line l1,line l2,point &p){
	p.x=(l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);

	if(fabs(l1.b) >eps)p.y= -(l1.a*p.x + l1.c);
	else p.y=-(l2.a*p.x + l2.c);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    int t=1,te=0;
    while(t--){
    	int n;
    	cin>>n;

    	printf("INTERSECTING LINES OUTPUT\n");
    	for(int i=1;i<=n;i++){
    		double x1,y1,x2,y2,x3,y3,x4,y4;
    		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    		point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4);
    		line l1=pointstoline(p1,p2);
    		line l2=pointstoline(p3,p4);

    		if(aresame(l1,l2)){
    			printf("LINE\n");
    		}
    		else if(areparallel(l1,l2)){
    			printf("NONE\n");
    		}
    		else{
    			point p;

    			intersectpoint(l1,l2,p);

    			printf("POINT %.2f %.2f\n", p.x,p.y);
    		}

    	}
    	printf("END OF OUTPUT\n");

        //printf("Case %d: ",++te);
    }
    return 0;
}
