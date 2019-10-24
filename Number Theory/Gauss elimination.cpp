#include<bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,k;
    double mat[5][5];

    for(i=0;i<3;i++){
        for(j=0;j<=3;j++){
            cin>>mat[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        int id=i;
        for(j=i+1;j<3;j++){
            if(fabs(mat[j][i])>mat[id][i])
                id=j;
                //cout<<id<<endl;
        }

        if(id!=i){
            for(j=i;j<=3;j++){
                swap(mat[i][j], mat[id][j]);
               // cout<<mat[id][j]<<endl;
            }
        }
        for(j=0;j<3;j++){
            if(j!=i){
                double factor=mat[j][i]/mat[i][i];
                cout<<factor<<endl;
                for(k=i;k<=3;k++){
                    mat[j][k]-=(factor*mat[i][k]);
                }
            }
        }
        cout<<mat[0][3]<<endl<<mat[1][3]<<endl<<mat[2][3]<<endl;
    }
    for(i=0;i<3;i++)
            cout<<mat[i][3]<<endl;

    return 0;
}
