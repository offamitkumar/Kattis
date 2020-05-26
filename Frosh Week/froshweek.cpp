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
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN (int)1e7+90000
array<int64_t, MAXN>arr,temp;
int64_t inversion;
void merge_(int64_t start, int64_t end) {
    int64_t mid = (start + end) / 2;
    int64_t i = start , j = mid + 1 , k = start;
    while ( i <= mid && j<=end) {
        if (arr.at(i) > arr.at(j)) {
            inversion += mid - i + 1;
            temp.at(k++) = arr.at(j++);
        }else{
            temp.at(k++) = arr.at(i++);
        }
    }
    while ( i <= mid ) {
        temp.at(k++) = arr.at(i++);
    }
    while ( j <= end ) {
        temp.at(k++) = arr.at(j++);
    }
    
    for ( k = start; k <= end; ++k ) {
        arr.at(k) = temp.at(k);
    }
    return ;
}
void merge_sort(int64_t start, int64_t end) {
    if (start >= end) {
        return ;
    }
    int64_t mid = (start + end) /2;
    merge_sort(start, mid);
    merge_sort(mid+1, end);
    merge_(start, end);
    return ;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int64_t n; cin >> n;
    for (int64_t i = 0; i < n; ++i) {
        cin >> arr.at(i);
    }
    merge_sort(0, n-1);
    cout << inversion << '\n' ;
    return 0;
}
