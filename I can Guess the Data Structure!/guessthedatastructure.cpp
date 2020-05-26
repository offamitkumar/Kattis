#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    while(cin>>n){
        priority_queue<int>pq; 
        int arr[3]= {1,2,3}; 
        /*
         * 0 => it is a stack
         * 1 => it is a queue
         * 2 => it is a priority queue
         *
         * for each output provided to us , we will mark all of those 0 
         * which don't follow the output , as they are no more in the race now 
         *
         * so at last , if we remain with just one index true then that is our final answer
         * if more than one are contains there true value that means not sure will be answer 
         * if none of these are containing there true value then you know what to print 
         *
         */ 
        queue<int>q;
        stack<int>s;
        int x , y;
        for(int i=0;i<n;++i){
            cin>>x>>y;
            if(x == 1){
                pq.push(y);
                s.push(y);
                q.push(y);
            }else{
                // if these are empty and still there exist an output then , none 
                if(s.size() == 0){
                    arr[0] = false;
                }
                if(q.size() == 0){
                    arr[1] = false;
                }
                if(pq.size() == 0){
                    arr[2] = false;
                }
                if(arr[0] && y == s.top()){
                    s.pop();
                }else{
                    arr[0] = false;
                }
                if(arr[1] && y == q.front()){
                    q.pop();
                }else{
                    arr[1]= false;
                }
                if(arr[2] && y == pq.top()){ // if condition followed let it be in the answer
                    pq.pop();
                }else{
                    arr[2] = false;
                }
            }
        }
        int X = arr[0]+arr[1]+arr[2];
        if(X==1){
            puts("stack");
        }else if(X == 2){
            puts("queue");
        }else if(X == 3 && arr[2]){
            puts("priority queue");
        }else if(X == 0){
            puts("impossible");
        }else{
            puts("not sure");
        }
    }
    return 0;
}
