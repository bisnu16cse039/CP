#include<bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
pair<int,int>p[70009];

int main()
{
    int t;
    scanf("%d",&t);
    string line;
    getline(cin, line);
    getline(cin, line);
    while(t--){

        int i=1;
        int x,y;

        getline(cin, line);

        while (line.length() > 0) {

            istringstream strm(line);

            strm >> x >> y;
            p[i]={x,y};
            getline(cin, line);

            i++;

        }

        int n=i-1,res=1;
        for(i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                    int r=2;
                for(int k=j+1;k<=n;k++){
                   int area=p[i].ff*(p[j].ss - p[k].ss) - p[i].ss*(p[j].ff-p[k].ff)+ (p[j].ff*p[k].ss - p[j].ss*p[k].ff);
                   if(area==0){
                       r++;
                   }
                }
                res=max(res,r);
            }
        }
        printf("%d\n",res);
        if(t>0){
            cout<<endl;
        }
    }
    return 0;
}
