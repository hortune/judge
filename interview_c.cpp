#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
using namespace std;
int main(){
    /* https://stackoverflow.com/questions/20826078/priority-queue-comparison
    // auto comp = [] (int &a, int &b) -> bool { return a < b; };
    // std::priority_queue<int,std::vector<int>, decltype(comp) > pq (comp);
    std::priority_queue<int> mypq;
    mypq.push(10);
    mypq.push(20);
    mypq.push(15);
    mypq.empty();
    mypq.pop();
    std::cout << "mypq.top() is now " << mypq.top() << '\n' 
     */
    
    /* pair
          std::pair <int,int> foo;
          std::pair <int,int> bar;

          foo = std::make_pair (10,20);
          bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

          std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
          std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    */

    /* Custom set
    auto cmp = [](int a, int b){return a < b;};

    //Returns an iterator pointing to the first element in the container which is considered to go after val.
    //Returns an iterator pointing to the first element in the container which is not considered to go before val (i.e., either it is equivalent or goes after)
    //set<int, decltype(cmp)> s(cmp);
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);

    cout << *s.begin() << endl;

    auto k = s.find(4);
    auto q = s.begin();
    q++;
    cout << *q << endl;
    */   

    /* Custom sort
    auto cmp = [](int a, int b){return a > b;};
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    sort(a.begin(), a.end(), cmp);
    cout << a[0] << endl;
    */
}
