//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
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
const int MAXN = (int)1e8+100;
const int MOD = (int)1e5+100;
bitset<MAXN>isprime;
int precalcuation(int n){  // return number of primes 
    isprime.set();
    isprime[0] = false;
    isprime[1] = false;
    int counter{1};
    for(int i=4;i<=n;i+=2){
        isprime[i] = false;
    }
    long long i;
    for(i = 3; i * i <= n; ++i){
        if(isprime[i]){
            ++counter;
            for(long long j = i*i; j <= n; j+=i){
                isprime[j] = false;
            }
        }
    }
    for(;i<=n;++i){
        counter+=isprime[i];
    }
    return counter;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n,q; scanf("%d %d",&n,&q);
    printf("%d\n",precalcuation(n));
    int x;
    while(q--){
        scanf("%d",&x);
        printf("%d\n",(isprime[x])?1:0);
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
