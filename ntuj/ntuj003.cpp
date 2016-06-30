//
//  ntuj003.c
//  fuck
//
//  Created by +u on 2015/6/2.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <map>
int main()
{

    string str[1012];
    int i=0;
    map<int,string> structure;
    map<string,string> struct2;
    while(cin>>str[i])
    {
        structure[i]=str[i];
        //if(str[i]=="#")break;
        if(cin.eof())break;
        i++;
    }
    int samenum[1001]={};
    sort(str,str+i);
    for(int j=0;j<i-1;j++)
    {
        for(int a=0;a<max(str[j].size(),str[j+1].size());a++)
            if(str[j][a]==str[j+1][a])samenum[j]++;
            else break;
    }
    if(str[0].size()==samenum[0])struct2[str[0]]=str[0].substr(0,samenum[0]);
    else struct2[str[0]]=str[0].substr(0,samenum[0]+1);

    
    for(int index=1;index<i-1;index++)
    {
        int k=max(samenum[index],samenum[index-1]);
        if(str[index].size()==k)struct2[str[index]]=str[index].substr(0,k);
        else struct2[str[index]]=str[index].substr(0,k+1);
    }
    
    struct2[str[i-1]]=str[i-1].substr(0,samenum[i-2]+1);
    for(int k=0;k<i;k++)
        cout<<structure[k]<<" "<<struct2[structure[k]]<<endl;
}
