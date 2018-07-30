#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    priority_queue<int> max_heap;  // max_heap
    priority_queue<int, vector<int>, greater<int> >  min_heap;
    unordered_map <int, int> min_record, max_record;
    int n;
    while(cin >> n){
        if (cin.eof()) break;
        
        if (n == 1){
            int k;
            cin >> k;
            max_heap.push(k);
            min_heap.push(k);
        }
        else if (n == 2){
            while(1){
                int k = max_heap.top();
                max_heap.pop();
                if (max_record.count(k) == 0  || max_record[k] == 0){
                    cout << k << endl;
                    if (min_record.count(k) == 0){
                        min_record[k] = 1;
                    } else {
                        min_record[k]++;
                    }
                    break;
                } else {
                    max_record[k]--;
                }
            }
        }
        else{
            while(1){
                int k = min_heap.top();
                min_heap.pop();
                if (min_record.count(k) == 0  || min_record[k] == 0){
                    cout << k << endl;
                    if (max_record.count(k) == 0){
                        max_record[k] = 1;
                    } else {
                        max_record[k]++;
                    }
                    break;
                } else {
                    min_record[k]--;
                }
            }
        }
    }
    
    
}
