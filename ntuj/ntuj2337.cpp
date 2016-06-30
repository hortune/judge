//
//  ntuj2337.c
//  fuck
//
//  Created by +u on 2015/8/1.
//  Copyright (c) 2015年 hortune. All rights reserved.
//


#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,k;
    cin>>a;
    while(a--)
    {
        cin>>b;
        e=0;
        int motion = 0;
        if(b==2)
        {
           
            cin>>c>>d;
            cout<<"._./"<<endl;
        }
        else
        {
            cin>>c;
            b--;
            b--;
            cin>>d;
            if(c>d)e++;
            int record;
            while(b--)
            {
                cin>>k;
                if(e)
                {
                    if(motion==0)
                    {
                        if(d>k)
                            e++;
                        else if(k<c)
                        {
                            motion=1;
                            record=d;
                        }
                        else
                        {
                            motion=2;
                            record=k;
                        }
                    }
                    else
                    {
                        if(record>k||d>k)
                            e++;
                    }

                }
                else
                {
                    if(k<d)
                    {
                        e++;
                        if(c>k)
                        {
                            motion=1;
                            record=d;
                        }
                        else
                        {
                            motion=2;
                            record=k;
                        }
                    }
                }
                c=d;
                d=k;
            }
            if(e==0||e==1)cout<<"._./"<<endl;
            else cout<<"\\._."<<endl;
        }
    }
}

/*#include <iostream>
using namespace std;
int main()
{
    int a,b,c=2147483647,d;
    cin>>a;
    while(a--)
    {
                cin>>b;
        if(b==2)
        {
            int in1,in2;
            cin>>in1>>in2;
            cout<<"._./"<<endl;
        }
        else
        {
            int k;
        c=d=0;
        int fuck=0;
        bool issmall=0;
        bool hahaha=0;
        
        b--;
        int asd,asd1;
        cin>>asd;
        int issecond=1;
        while(b--)
        {
            cin>>k;
            if(issecond)
            {
                asd1=k;
                issecond=0;
            }
            else {
            if(issmall&&(fuck>k))
                d++;
            if(c>k)
            {
                d++;
                fuck=c;
                issmall=1;
            }
            }
            c=k;
        }
        
        
        
        if(((d==1)&&(asd<=asd1))||(d==0))
            cout<<"._./"<<endl;
        else
            cout<<"\\._."<<endl;
        }
    }
}*/