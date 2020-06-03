//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  #include <iostream>
//  #include <chrono>
//  #include <string>
//  #include <utility>
//  #include <queue>
//  #include <stack>
//  #include <cmath>
//  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
//  #include <bitset>
//  #include <numeric>
  #include <vector>
//  #include <array>
//  #include <algorithm>
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
#define MOD 1000000007

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    int t; scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        vector<vector<int>>graph(n);
        vector<int>cash(n);
        for(int i=0;i<n;++i){
            int temp; scanf("%d",&temp);
            for(int j=0;j<temp;++j){
                int x; scanf("%d",&x);
                graph[i].push_back(x);
            }
            scanf("%d",&cash[i]);
        }
        vector<int>freq(31,0);
        for(int i=0;i<m;++i){
            int x; scanf("%d",&x);
            freq[i+1]=x;
        }
        int prof = 0;
        for(int i=0;i<n;++i){
            int min_=100000000;
            for(auto&itr:graph[i]){
                min_ = (min_ > freq[itr])?freq[itr]:min_;
            }
            prof += min_*cash[i];
        }
        printf("%d\n",prof);
    }

//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
