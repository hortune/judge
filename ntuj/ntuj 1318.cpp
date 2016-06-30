//
//  ntuj 1318.c
//  fuck
//
//  Created by +u on 2015/6/19.
//  Copyright (c) 2015年 hortune. All rights reserved.
//一開始錯 冊資 4 4 4 4 4


#include <iostream>
using namespace std;
#include <algorithm>
int main()
{
    int a,b,c,d[5]={};
    cin>>a;
    while(a--)
    {
        int ans=0;
        cin>>b;
        d[1]=d[2]=d[3]=d[4]=0;
        while(b--)
        {
            cin>>c;
            ans+=c-(c/10);
            if(c%10>4)ans--;
            else d[c%10]++;
        }
        ans-=min(d[4],d[1])+min(d[3],d[2]);
        int m=min(d[4],d[1]);
        int n=min(d[3],d[2]);
        d[4]-=m;
        d[1]-=m;
        d[2]-=n;
        d[3]-=n;
        if((d[1]+d[3])==0)
        {
            ans-=min(d[2],d[4]);
            d[2]-=min(d[2],d[4]);
            d[4]-=min(d[2],d[4]);
            if(d[4])
                ans-=d[4]/2;
            else
                ans-=d[2]/3;
        }
        else if((d[1]+d[2])==0)
        {
            ans-=(d[3]+d[4])/2;
        }
        else if((d[2]+d[4])==0)
        {
            if(d[1]*2>=d[3])
            {
                ans-=d[3];
                d[1]-=d[3]*2;
                d[3]=0;
            }
            else
            {
                d[3]-=d[1]/2;
                ans-=d[1]/2;
                d[1]-=d[1]/2;
            }
            if(d[3])
                ans-=d[3]/2;
        }
        else
        {
            int e1=0,e2=0,esp,esp1;
            if(d[2]>d[1]*2)
            {
                e1+=d[1];
                esp=d[2]-d[1]*2;
                e1+=esp/3;
            }
            else
            {
                e1+=d[2]/2;
                esp=d[2]-(d[2]/2)*2;
                esp1=d[1]-d[2]/2;
                if(esp&&esp1>=3)
                {e1++;esp1-=3;}
                e1+=esp1/5;
            }
            if(d[2]*3>=d[1])
            {
                e2+=d[1]/3;
                esp=d[1]-(d[1]/3)*3;
                esp1=d[2]-(d[1]/3);
                while(esp&&esp1>1)
                {
                    esp--;
                    esp1-=2;
                    e2++;
                }
                e2+=esp1/3;
            }
            else
            {
                e2+=d[2];
                esp=d[1]-d[2]*3;
                e2+=esp/5;
            }
            ans-=max(e2,e1);
        }
        cout<<ans<<endl;
    }
}




/*#include <cstdio>

int main()
{
    int a,b,c;
    //bool head=1;
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&c);
        int ans=0,d[5]={};
        d[0]=d[1]=d[2]=d[3]=d[4]=0;
        while(c--)
        {
            scanf("%d",&b);
            ans+=(b-(b/10));
            if((b%10)>4)ans--;
            else d[b%10]++;
        }
        
        bool jump=0;
        int num=0;
        for(int i=4;i>0;i--)
            while(d[i])
            {
                jump=0;
                num+=i;
                d[i]--;
                if(num>4){
                    ans--;
                    num=0;
                    jump=1;
                }
                
                if(!jump)
                for(int j=1;j<i;j++)
                {
                    while(d[j])
                    {
                        d[j]--;
                        num+=j;
                        if(num>4)
                        {
                            ans--;
                            break;
                        }
                    }
                    if(num>4)
                    {
                        num=0;
                        break;
                    }
                }
                
            
            }
        printf("%d\n",ans);
    }
}*/