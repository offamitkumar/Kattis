/*
 *
 *  check all the outcome and print those who have maximum frequency of occurring 
 *
 */
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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int arr[61] = {0};
    int n,m;
    cin>>n>>m;
    int max_frequency = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            arr[i+j]++;
            max_frequency = max(max_frequency , arr[i+j]);
        }
    }
    for(int i=1;i<=n+m;++i){
        if(arr[i]==max_frequency){
            cout<<i<<'\n';
        }
    }
    return 0;
}
