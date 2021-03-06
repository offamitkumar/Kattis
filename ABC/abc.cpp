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
#include <unordered_map>
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
    array<int,3>arr;
    for(auto&itr:arr)
        cin>>itr;
    sort(arr.begin(),arr.end());
    string s; cin>>s;
    for(auto&itr:s){
        if(itr=='A'){
            cout<<arr[0]<<' ';
        }else if(itr=='B'){
            cout<<arr[1]<<' ';
        }else{
            cout<<arr[2]<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
