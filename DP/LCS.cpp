#include<bits/stdc++.h>
#define fo freopen("inlcs.txt","r",stdin)
#define N cout<<endl
#define MAX 1009
#define inf 999999
using namespace std;

int lcs[MAX][MAX],n;
char dir[MAX][MAX];
string s1,s2;

void LCS(void)
{
    memset(dir,'A',sizeof(dir));
    n=0;
    for(int i=0;i<=s2.size();i++)
    {
        for(int j=0;j<=s1.size();j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s1[j-1]==s2[i-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                dir[i][j]='C';
                n=max(n,lcs[i][j]);
            }
            else
            {
                if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
                else if(lcs[i-1][j]<lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i][j-1];
                    dir[i][j]='L';
                }
                else
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }
            }
        }
    }
}

void display(int j,int i)
{
    if(dir[i][j]=='A')
        return;
    else if(dir[i][j]=='L')
    {
        display(j-1,i);
    }
    else if(dir[i][j]=='U')
    {
        display(j,i-1);
    }
    else if(dir[i][j]=='C')
    {
        display(j-1,i-1);
        printf("%c",s1[j-1]);
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--){
    //fo;
    
    cin>>s1;
    
    cin>>s2;

    LCS();
    
    display(s1.size(),s2.size());
    N;
    }
    return 0;
}