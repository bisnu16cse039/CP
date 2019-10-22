
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

int cross_P[N];

int dot_product(int vec_A[],int vec_B[]){
	int product=0;

	for(int i=0;i<3;i++){
		product+= vec_A[i]*vec_B[i];
	}
	return product;
}
void cross_product(int vec_A[],int vec_B[]){
	cross_P[0]=vec_A[1]*vec_B[2] - vec_A[2]*vec_B[1];
	cross_P[1]=vec_A[0]*vec_B[2] - vec_A[2]*vec_B[0];
	cross_P[2]=vec_A[0]*vec_B[1] - vec_A[1]*vec_B[0];
}

int main()
{
	int vec_A[]={3,-5,4};  
	int vec_B[]={2,6,5};

    cout<<dot_product(vec_A,vec_B)<<endl;;

    cross_product(vec_A,vec_B);

    cout<<cross_P[0]<<" "<<cross_P[1]<<" "<<cross_P[2]<<endl;

    return 0;
}
