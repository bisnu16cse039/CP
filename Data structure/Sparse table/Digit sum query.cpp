#include<bits/stdc++.h>

using namespace std;
const int N=2e5+5;

int ini()
{
    int n;
    scanf("%d",&n);
    return n;
}
int MIN[N][25];
int a[N];

void preprocess(int n)
{
    for(int i=1; i<=n; i++)
    {
        MIN[i][0]=a[i];
    }
    for(int j=1; j<20; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);
        }
    }
}
int findmin(int l,int r)
{
    int mn=INT_MAX;

    for(int i=19; i>=0; i--)
    {
        if(l-1+(1<<i) <= r)
        {
            mn=min(mn,MIN[l][i]);
            l+=(1<<i);
        }
    }
    return mn;
}

int sod(int x){
    int s=0;
    while(x>0){
        s+=x%10;
        x/=10;
    }
    return s;
}

int main()
{
    int t,te=0;

    t=ini();

    while(t--)
    {
        int n;
        n=ini();
        int q;
        q=ini();
        for(int i=1; i<=n; i++)
        {
            int x=ini();
            x=sod(x);
            a[i]=x;
        }
        preprocess(n);

        printf("Case %d: ",++te);
        while(q--)
        {
            int l,r;
            l=ini(),r=ini();
            int res=findmin(l,r);
            printf("%d\n",res);
        }
    }
    return 0;
}

