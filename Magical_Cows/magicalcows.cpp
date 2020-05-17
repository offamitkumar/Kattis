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
#define MAXN 1004
#define MAXM 54
    //    dp[day ][farm]
long long dp[MAXM][MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    memset(dp , 0 , sizeof(dp));
    int C , N , M; cin>>C>>N>>M;
    for(int farm,i=0;i<N;++i){
        cin>>farm;
        dp[0][farm]+=1LL;
    }
    for(int day=0;day<=50;++day){
        for(int farm=1;farm<=C;++farm){ // denotes farm having cows 
            if(farm*2<=C){ // just double the number of cows
                dp[day+1][2*farm]+=dp[day][farm];
            }else{ // double the number of farms 
                dp[day+1][farm]+=2LL*dp[day][farm];
            }
        }
    }
    for(int q,i=0;i<M;++i){ // query
        cin>>q;
        long long counter{};
        for(int j=0;j<=C;++j){
            counter+=dp[q][j];
        }
        cout<<counter<<'\n';
    }
    return 0;
}
