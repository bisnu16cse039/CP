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

int dp[12][2];
int n;
string s;

int digit_dp(int i,bool f){
  if(i==n){
    return 1;
  }
  if(dp[i][f]!=-1){
    return dp[i][f];
  }
  int res=1;
  for(int j=0;j<10;j++){
    if(f and s[i]-'0'==j){
      res=max(res,j*digit_dp(i+1,true));
    }
    if(f and j<s[i]-'0'){
      if(i==0 and j==0){
        j=1;
      }
      res=max(res,j * digit_dp(i+1,false));
    }
    if(!f){
      res=max(res,j*digit_dp(i+1,false));
    }
  }
  //error(res);
  return dp[i][f]=res;
}
int main()
{    
    cin>>s;
    n=s.size();
    memset(dp,-1,sizeof dp);
    int res=digit_dp(0,true);
    cout<<res<<endl;
    return 0;
}
