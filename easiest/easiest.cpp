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
//  #include <vector>
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
int sum(int num){
    int s{};
    while(num){
        s+=(num%10);
        num/=10;
    }
    return s;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    int n; 
    while(scanf("%d",&n) && n){
        int dsum = sum(n);
        for(int i=11;;++i){
            if(dsum == sum(n*i)){
                printf("%d\n",i);
                break;
            }
        }
    }

//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
