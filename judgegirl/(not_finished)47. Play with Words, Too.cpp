#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node{
	int num;
	char cha;
	node *pre,*next;
}*head,*last;
void print(){
	node *temp=head;
	while(temp!=last)
	{
		printf("%c %d ",temp->cha,temp->num);
		temp=temp->next;
	}
	printf("$\n");
}
int main()
{
	ios_base::sync_with_stdio(0);
	string temp;
	string origin;
	int num;
	head = new node();
	last = head;
	while(cin>>temp)
	{
	//	cout<<temp<<endl;
	//	if(cin.eof())break;
		if(temp=="print")
		{
			print();
	//		printf("ass");
		}
		else {
			cin>>temp;
			if(temp=="left"){
				cin>>temp;
				cin>>num;
				if(head!=last&&head->cha==temp[0])
				{
					head->num+=num;
				}
				else{
				head->pre=new node();
									//shift			
				node * temp_n;
				temp_n = head->pre;
				temp_n->next = head;
				head = temp_n;
				
				head->cha=temp[0];
				head->num=num;
				
				}
			}
			else if(temp=="right")
			{
				cin>>temp;
				cin>>num;
				if(last!=head&&last->pre->cha==temp[0])
				{		
					last->pre->num+=num;
				}
			 	else{
				last->cha=temp[0];
				last->num=num;
				node * temp_n;
				temp_n = last;
				last->next=new node();
				last=last->next;
				last->pre = temp_n; 
				}
			}
			else{
				 num = atoi(temp.c_str());
				 cin>>temp;
				 int num2;
				 num--;
				 cin>>num2;
				 int total = 0;
				 node * temp_n;
				 temp_n = head;
				 while(1)
				 {
				 //	printf("hello\n");
				//	printf("total: %d num: %d\n",total,num);
				 	if(total>num)
				 	{
				 		if(temp[0]==temp_n->pre->cha)
				 		{
							temp_n->pre->num+=num2;
							break;
						}
				 		int temp_num;
				 		node * k1 = new node();
				 		node * k2 = new node();
				 		k1->num=num2;
				 		k1->cha=temp[0];
						k2->num=total-num;
						k2->cha=temp_n->pre->cha;
						temp_n->pre->num-=(total-num);
						temp_n->pre->next=k1;
						k1->pre=temp_n->pre;
						k1->next=k2;
						k2->pre=k1;
						k2->next=temp_n;
						temp_n->pre=k2;
						break;	
					}
					else if(total==num)
					{
						node * temp_pre,*temp_next;
						if(temp_n!=head) {
							if(temp_n->pre->cha==temp[0])
							{
								temp_n->pre->num+=num2;
								break;
							}
							if(temp_n->cha==temp[0])
							{
								temp_n->num+=num2;
								break;
							}
							temp_pre = temp_n->pre;
							temp_n = new node();
							temp_pre->next->pre=temp_n;
							temp_n->next=temp_pre->next;
							temp_n->pre=temp_pre;
							temp_pre->next= temp_n;
							temp_n->cha=temp[0];
							temp_n->num=num2; 
						}
						else
						{
							if(head->cha==temp[0])
								{
									head->num+=num2;
									break;
								}
							head->pre = new node();
							head=head->pre;
							head->next=temp_n;
							head->num=num2;
							head->cha=temp[0];
						}
						break;
					}
					
					if(temp_n==last)break;
					total+=temp_n->num;
				 	temp_n=temp_n->next;
				 }
			}
		}
	}
}
