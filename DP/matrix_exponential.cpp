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

const int N = (int) 1e6 + 5;
const int M = (int) 1e9 + 7;
const double pi=2* acos(0.0);

struct  matrix
{
	int mat[2][2];
};

matrix mul(matrix a,matrix b){
	matrix ans;
	int k;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			for(ans.mat[i][j]=k=0; k<2 ;++k){
				ans.mat[i][j]+= (a.mat[i][k] * b.mat[k][j]);
			}
		}
	}
	return ans;
}

matrix f(matrix a,int p){
	matrix ans;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			ans.mat[i][j]= (i==j);
		}
	}
	while(p>0){
		if(p&1){
			ans=mul(ans,a);
		}
        a=mul(a,a);
        p/=2;
	}
	
	return ans;
}

int main()
{

    int n;
    cin>>n;
    matrix a;
    a.mat[0][0]=a.mat[0][1]=a.mat[1][0]=1;
    a.mat[1][1]=0;

    matrix res=f(a,n-1);
    printf("%d th fibonacci number: %d\n",n,res.mat[0][0]);
    main();
    return 0;
}
