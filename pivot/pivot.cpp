//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
  #include <vector>
//  #include <array>
  #include <unordered_map>
//  #include <unordered_set>
  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e5+100;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n; scanf("%d",&n);
    set<int>min_heap;
    set<int,greater<int>>max_heap;
    vector<int>v(n);
    unordered_map<int , int>hsh;
    for(int x,i=0;i<n;++i){
        scanf("%d",&x);
        v[i] = x;
        hsh[x]++;
        min_heap.insert(x);
    }
    int counter{};
    for(auto&itr:v){
        hsh[itr]--;
        if(hsh[itr]==0){
            min_heap.erase(itr);
        }
        if(min_heap.size() == 0){
            if(itr >= *max_heap.begin()){
                ++counter;
            }
        }else if(max_heap.size() == 0){
            if(itr <= *min_heap.begin()){
                ++counter;
            }
        }else{
            if(itr >= *max_heap.begin() && itr <= *min_heap.begin()){
                ++counter;
            }
        }
        max_heap.insert(itr);
    }
    cout << counter << '\n';
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
