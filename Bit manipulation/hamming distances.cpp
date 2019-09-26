#include<bits/stdc++.h>

using namespace std;

int hamming(int a,int b)
{
    return __builtin_popcount(a^b);
}
int a[10009];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        int x=0;
        for(int j=s.size()-1;j>=0;j--){
            if(s[j]=='1'){
                x|=(1<<j);
            }
        }
        a[i]=x;
    }

    int res=INT_MAX;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
         {
            if(i!=j)
            {
                int k=hamming(a[i],a[j]);
                res=min(res,k);
            }

        }
    }
    cout<<res<<endl;
    return 0;
}
