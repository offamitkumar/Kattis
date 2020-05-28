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
#include <unordered_map>
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
        int64_t ,
        null_type ,
        less<int64_t> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN (int64_t)1e6+10
int64_t temp[MAXN];
int64_t arr[MAXN];
int64_t inversion{};
void merge(int64_t start , int64_t end){
    int64_t mid = (start + end) /2;
    int64_t i = start , j = mid+1 , k = start;
    while(i<=mid && j <=end){
        if(arr[i] > arr[j]){
            inversion+=(mid - i +1);
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(int64_t t = start; t<=end; ++t){
        arr[t] = temp[t];
    }
}
void merge_sort(int64_t start , int64_t end ){
    if(start >= end){
        return ;
    }
    int64_t mid = (start + end )/2;
    merge_sort(start , mid);
    merge_sort(mid + 1  , end );
    merge(start , end);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int64_t n; cin>>n;
    for(int64_t i=0;i<n;++i){
        cin>>arr[i];
    }
    merge_sort(0 , n-1);
    cout<<inversion<<'\n';
    return 0;
}
