//LCS 輸入很tricky
#include <iostream>
#include <cstdio>

using namespace std;
int a[21][21]={};
int main()
{
    int k;
    int b,c[21]={},d[21]={};
    cin>>b;
    for(int i=0;i<b;i++)
    {
        cin>>k;
        d[k-1]=i;
    }
    while(cin>>k)
        {
            if(cin.eof())break;
            
            c[k-1]=0;
            for(int i=1;i<b;i++)
            {
                cin>>k;
                c[k-1]=i;
            }
            for(int i=1;i<=b;i++)
                for(int j=1;j<=b;j++)
                    if(c[i-1]==d[j-1])
                        a[i][j]=a[i-1][j-1]+1;
                    else
                        a[i][j]=max(a[i-1][j],a[i][j-1]);
            cout<<a[b][b]<<endl;
        }
}