#include <bits/stdc++.h>
using namespace std;
struct person {
    unsigned int id;
    char name[32];
}*people;
struct friends {
    unsigned id1;
    unsigned id2;
}*fri;
map<string,int> name_id;
vector<int> __map[10001]={};
int main () {
  FILE * pFile;
  long lSize;
  int * buffer,*P;
  P=new int();
  size_t result;
  pFile = fopen ( "friends" , "rb" );
  buffer = new int();
  // copy the file into the buffer:
  fread (buffer,1,sizeof(int),pFile);
  people = new person[*buffer];
  fread (people,1,sizeof(person)*(*buffer),pFile);
  fread (P,1,sizeof(int),pFile);
  fri = new friends[*P];
  fread (fri,1,sizeof(friends)*(*P),pFile);
  fclose (pFile);
  string str,str1;
  ios::sync_with_stdio(false);
  
  for(int i=0;i<*buffer;i++)
  {
  	str.assign(people[i].name);
	name_id[str]=people[i].id+1;	
  }
  for(int i=0;i<*P;i++)
  {
  	__map[fri[i].id1+1].push_back(fri[i].id2+1);
  	__map[fri[i].id2+1].push_back(fri[i].id1+1);
  }
  while(cin>>str&&str!="end")
  {
  	cin>>str1;
  	bool yes=0;
  	int str_id=name_id[str];
  	int str1_id=name_id[str1];
	for(int i=0;i<__map[str_id].size();i++)
	{
		if(__map[str_id][i]==str1_id)
		{
			yes=1;
			break;
		}
	}
	if(yes)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
  }
  free(P);
  free(fri);
  free(people);
  free (buffer);
  return 0;
}
