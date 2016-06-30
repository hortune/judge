//
//  ntuj2339.c
//  fuck
//
//  Created by +u on 2015/8/1.
//  Copyright (c) 2015年 hortune. All rights reserved.
//
#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
    int a,b,c,arr[100010],arr1[100010];
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        int one=0;
        int n1=0;
        for(int i=0;i<b;i++)
            scanf("%d",&arr[i]);
        
        sort(arr,arr+b);
        int n=1;
        c=arr[0];
        int ans=0;
        int si=1;
        int poi=0;
        for(int i=1;i<b;i++)
            if(c==arr[i])
                n++;
            else
            {
                ans+=n/2;
                if(n%2==0){arr1[poi]=n-1;
                    poi++;
                }else if(n==1)one++;
                else n1+=n-1;
                c=arr[i];
                n=1;
                si++;
            }
        ans+=n/2;
        if(n%2==0)arr1[poi]=n-1;
        else if(n==1)one++;
        else n1+=(n-1);
        printf("%d\n",ans);
        n=n1;
        int g=si;
        poi++;
        sort(arr1,arr1+poi);
        for(int i=1;i<=ans;i++)
        {
            if(n==0){
                
                poi--;
                n=arr1[poi];
                n--;
                g++;
                printf("%d ",g);
                if(n!=0)
                {
                    n--;
                    g++;
                }
                
            }
            else if(n==1)
            {
                g++;
                printf("%d ",g);
                n--;
            }
            
            else {
                
                n-=2;
                g++;
                printf("%d ",g);
                g++;
                
            }
        }
        printf("\n");
    }
}