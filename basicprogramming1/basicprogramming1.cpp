//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
  #include <numeric>
//  #include <utility>

  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
  #include <array>
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
const int MAXN = (int)2*(1e6)+100;
const int MOD = (int)1e9+7;
array<long long , MAXN>arr;
bitset<MAXN>visited;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n, q; scanf("%d %d",&n , &q);
    for(int i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    long long counter{};
    bool out = false;
    switch(q){
        case 1:
            puts("7");
            break;
        case 2:
            if(arr[0] > arr[1]){
                puts("Bigger");
            }else if(arr[0] == arr[1]){
                puts("Equal");
            }else {
                puts("Smaller");
            }
            break;
        case 3:
            sort(arr.begin() , arr.begin()+3);
            printf("%lld\n",arr[1]);
            break;
        case 4:
            printf("%lld\n",(long long)accumulate(arr.begin(),arr.end(),0ll));
            break;
        case 5:
            for_each(arr.begin() , arr.end() , 
                    [&counter](int i){
                    if(!(i&1ll)){
                    counter+=i;
                    }
                    }
                );
            printf("%lld\n",counter);
            break;
        case 6:
            for(int i=0;i<n;++i){
                long long itr = arr[i];
                itr%=26ll;
                printf("%c",char(itr+int('a')));
            }
            puts("");
            break;
        case 7:
            counter = arr[0];
            if(counter > n-1){
                out = true;
            }
            while((counter != n-1) && (!visited[counter])){
                visited[counter]=true;
                counter = arr[counter];
                if(counter > n-1){
                    out = true;
                    break;
                }
            }
            if(out){
                puts("Out");
            }else if(counter == n-1){
                puts("Done");
            }else{
                puts("Cyclic");
            }
            break;
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
