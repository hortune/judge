#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef pair<long long, int> tpe;

long long primes[] = {2,3,5,7};
int main(){
    long long humbles[6000];
    tpe ele;
    priority_queue<tpe,vector<tpe>,greater<tpe>> pq;
    pq.push(make_pair(1,-1));
    for(int i = 0; i < 6000; i++){
        ele = pq.top();
        humbles[i] = ele.first;
        pq.pop();
        if (ele.second == -1){
            pq.push(make_pair(ele.first*primes[0],0));
        }
        else if (ele.second == 3){
            pq.push(make_pair(ele.first*primes[3],3));
        }
        else{
            pq.push(make_pair(ele.first*primes[ele.second],ele.second));
            pq.push(make_pair((ele.first/primes[ele.second])*primes[ele.second+1], ele.second+1));
        }
    }
    
    int n;
    while(cin>>n){
        if (n == 0)
            break;
        if(n % 100 < 20 && n % 100 > 3){
            cout << "The "<< n <<"th humble number is "<< humbles[n-1] << "." << endl;
        }
        else if(n % 10 == 1){
            cout << "The "<< n <<"st humble number is "<< humbles[n-1] << "." << endl;
        }
        else if(n % 10 == 2){
            cout << "The "<< n <<"nd humble number is "<< humbles[n-1] << "." << endl;
        }
        else if(n % 10 == 3){
            cout << "The "<< n <<"rd humble number is "<< humbles[n-1] << "." << endl;
        }
        else{
            cout << "The "<< n <<"th humble number is "<< humbles[n-1] << "." << endl;
        }
    }
}
