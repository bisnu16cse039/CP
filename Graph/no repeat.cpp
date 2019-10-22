#include<bits/stdc++.h>

using namespace std;
int a[100009];
int main()
{
    int n,i;
    char s[109];
    cin>>n;
    cin>>s;
    int l=strlen(s);
    for(int i=0;s[i];i++){
        a[s[i]]++;
    }
    for(i=0;s[i];i++){
        if(a[s[i]]==1){
            printf("%c",s[i]);
            break;
        }
    }
    if(i==l)
        printf("-1\n");
    return 0;
}
