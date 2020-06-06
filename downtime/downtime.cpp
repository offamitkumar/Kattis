//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
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
//  #include <vector>
//  #include <array>
  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
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
    long long n,k; scanf("%lld%lld",&n,&k);
    unordered_map<long long , long long > mp;
    for(long long temp,i=0;i<n;++i){
        scanf("%lld",&temp);
        mp[temp]++;
    }
    long long current{};
    for(int i=0;i<1000;++i){
        current += mp[i];
    }
    long long seen = current;
    for(int i=1000;i<=100000;++i){
        current += mp[i];
        current -= mp[i - 1000];
        seen = max(seen , current);
    }
    cout << (seen+k-1) / k << '\n'; 

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
