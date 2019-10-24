#include<bits/stdc++.h>

#define X first
#define Y second
#define eb push_back
#define pb pop_back
#define siz(a) int(a.size())
//for traversing the container (bcoz we cannot access linked list etc with direct index)
//c stands for container and it for iterator
#define tr(c, it) \
  for(typeof(c.begin()) it=c.begin() ; it != c.end() ; it++)

#define all(c) c.begin(), c.end()
#define present(container, element) (container.find(element) != container.end()) //whether the element is present in the container

#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

#define scan(x) scanf("%lld", &x)
#define print(x) printf("%lld ", x)
#define pN printf("\n");

using namespace std;

typedef long long int ll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < ll > vll;
typedef vector < vll > vvll;

typedef pair < int , int > ii;

const int mod=1e9+7;
const int root=1e7+1;

bool check[root];
//cin is faster than scanf after sync is off bcoz scanf need to interpret their format string argument
// at runtime while with cin it happens at compilation time
vll prime, divisors;
vector<pair<ll, ll> > factors;

void sieve()
{

 for(ll i=2; i<root; i++)
 {
  if(!check[i])
  {
   prime.eb(i);

   for(ll j=i; j<root; j+=i)
    check[j]=true;
  }
 }

}

void factorization(ll n)
{
 ll size=siz(prime);

 for(ll i=0; i<size && prime[i]*prime[i] <= n; i++)
 {
  ll cnt=0;

  while(n%prime[i]==0)
  {
   n/=prime[i];
   cnt++;
  }

  if(cnt)
  {
   factors.eb(make_pair(prime[i], cnt));
   //trace4(i, prime[i], cnt, n);
  }
  if(n==1)
   break;
 }

 if(n>1)
 {
  factors.eb(make_pair(n, 1));
 }

 return ;

}

void setDivisors(ll n, ll i)
{
 ll size = siz(factors);

 for(ll j=i; j<size; j++)
 {
  ll x = n*factors[j].X;

  for(ll k=0; k<factors[j].Y; k++)
  {
   divisors.eb(x);
   setDivisors(x, j+1);
   x = x*factors[j].X;
  }
 }

 return ;
}

int main()
{
 //it off the synchronization of with stdio and thus saves time but then you cannot use scanf and cin together
 //std::ios_base::sync_with_stdio(false);

 sieve();

 ll n, i, t;
 //cin >> t;
 scan(t);
 while(t--)
 {
 // cin >> n;
  scan(n);
  factorization(n);

  setDivisors(1, 0);

  sort(divisors.begin(), divisors.end());

  ll size = siz(divisors)-1;

  for(i=0; i<size; i++)
  {
   //cout << divisors[i] << " ";
   print(divisors[i]);
  }
  pN;

  divisors.clear();
  factors.clear();
 }
 return 0;
}
