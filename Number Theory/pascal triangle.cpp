#include<bits/stdc++.h>

using namespace std;
long long arr[10009];

void pascal_triangle()
{
   arr[1]=1;
   arr[2]=1;
   arr[3]=1;
   int d=3,p=1;
   int in=3;
   for(int i=3;i<=5;d+=i,p+=i-1,++i){
      for(int j=d+1;j<d+i+1;j++){
        int k=j-i;
        if(k<=p || k>=d){
            arr[++in]=1;
        }
        else{
            arr[++in]=arr[k]+arr[k+1];
        }
        //cout<<in<<" "<<arr[in]<<endl;
      }
   }
}
int main()
{
    long long n;
    pascal_triangle();

    while(scanf("%d",&n)==1){
        cout<<arr[n]<<endl;
    }

    return 0;
}
