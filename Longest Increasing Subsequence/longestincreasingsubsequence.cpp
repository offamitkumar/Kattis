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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(cin>>n){
        vector<int>nums(n);
        for(auto&itr:nums){
            cin>>itr;
        }
        int lis=0;
        vector<int>parent(n+1);
        fill(parent.begin() , parent.end() ,-1);
        vector<int>seq(n+1);
        for(int i=0;i<(int)nums.size(); ++i){
            int low = 1;
            int high = lis;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums[seq[mid]]<nums[i]){
                    low = mid + 1;
                }else{
                    high = mid -1;
                }
            }
            int pos = low;
            parent[i] = seq[pos-1];
            seq[pos] = i;
            if( pos > lis ) 
                lis = pos;
        }
        cout<<lis<<'\n';
        vector<int>ans(100010);
        int k = seq[lis];
        for(int i=lis-1;i>=0;--i){
            ans[i] =k;
            k = parent[k];
        }
        for(int i=0;i<=lis-1;++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
