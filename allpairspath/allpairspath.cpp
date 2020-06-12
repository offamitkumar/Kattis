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
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
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

  #include <climits>
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
const int MAXN = (int)200;
const int MOD = (int)1e9+7;
long long arr[MAXN][MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n , m , q; ;
    while(scanf("%d %d %d",&n , &m , &q) && (n+q+m)){
        for(int i=0;i<MAXN;++i){
            for(int j=0;j<MAXN;++j){
                arr[i][j] = INT_MAX;
                arr[i][i] = 0;
                arr[j][j] = 0;
            }
        }
        for(int i=0;i<m;++i){
            int u , v, w; scanf("%d %d %d",&u ,&v ,&w);
            arr[u][v] = min(arr[u][v] ,(long long) w);
        }

        // keep the k before i & j
        for(int k=0;k<n;++k){
            for(int i=0;i<n; ++i){
                for(int j=0;j<n;++j){
                    if(arr[i][k] != INT_MAX && arr[k][j] != INT_MAX){
                        arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
                    }
                }
            }
        }

        // find negative cycle
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                for(int k=0;k<n;++k){
                    if(arr[k][k]<0 && arr[i][k]!=INT_MAX && arr[k][j] != INT_MAX){
                        arr[i][j] = INT_MIN;
                    }
                }
            }
        }

        while(q--){
            int u , v; scanf("%d %d",&u,&v);
            if(arr[u][v]==INT_MAX){
                puts("Impossible");
            }else if(arr[u][v]==INT_MIN){
                puts("-Infinity");
            }else{
                printf("%lld\n",arr[u][v]);
            }
        }
        puts("");
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
