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
//  #include <cstring>
//  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
  #include <bitset>
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
const int MAXN = 2e6+10;
bitset<MAXN>prime;
void sieve(void){
    prime.set();
    prime.reset(0);
    prime.reset(1);
    for(int i=2;i*i<=(MAXN);++i){
        if(prime[i]==true){
            for(long long j=(long long)i*i; j<MAXN;j+=i){
                prime[j] = false;
            }
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//      auto initial_time = high_resolution_clock::now();
    vector<long long>arr,arr1;
    arr.assign(MAXN,2ll);
    arr[1]=1;
    arr1.assign(MAXN,0ll);
    sieve();
    for(int i=2;i<(MAXN);++i){
        for(long long j=i*2; j<MAXN;j+=i){
            ++arr[j];
        }
    }
    for(int i=2;i<(MAXN);++i){
        if(prime[i]==true){
            for(long long j=i; j<MAXN;j+=i){
                ++arr1[j];
            }
        }
    }
    int q; scanf("%d",&q);
    int n;
    while(q--){
        scanf("%d",&n);
        printf("%lld\n",arr[n]-arr1[n]);
    }

//      auto final_time = high_resolution_clock::now();
//      cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
