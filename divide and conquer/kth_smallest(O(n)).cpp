
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

#define what_is(x)     cerr << #x << " is " << x << endl;

///*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout << endl ;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
int ini()
{
    int x;
    scanf("%d",&x);
    return x;
}
long long inl()
{
    long long x;
    scanf("%lld",&x);
    return x;
}

int set_1(int n,int pos){return n = (n | (1<<pos));}
int reset_0(int n,int pos){return n= n & ~(1<<pos);}
bool check_bit(int n,int pos){return n = n & (1<<pos);}

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

int a[N];
int partition(int l, int r) {
	int x=a[r];

	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]<=x){
			++i;
			swap(a[i],a[j]);
		}
	}	
	swap(a[i+1],a[r]);
	return i+1; 
}

int select(int l,int r,int k){
	if(l==r)return l;

	int q=partition(l,r);

	if(q==k){
		return a[q];
	}
	else if(q>k){
		return select(l,q-1,k);
	}
	else{
		return select(q+1,r,k);
	}
}
int main()
{
	int n=ini();

	for(int i=1;i<=n;i++)a[i]=ini();
    int k=ini();
	printf("%d\n", select(1,n,k));

    return 0;
}
