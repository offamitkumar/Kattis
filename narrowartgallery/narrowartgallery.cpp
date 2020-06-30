//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <chrono> 
#include <numeric> 
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(x)  (x).begin(), (x).end()

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void Log_Gen() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void Log_Gen(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define Log(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define Log(...) 0
#endif

typedef int64_t Int;

template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int64_t MOD  = (int64_t)1e9+7ll;

int dp[204][204][3];
vector<pair<int,int>>v;
int n , k; 
int sol(int row , int k_left , int State , int cost){
    if(k_left == 0){
        dp[row][k_left][State] = cost;
        return cost; 
    }
    if(row == n){
        dp[row][k_left][State] = 100000;
        return 100000;
    }
    /*
     * In the below states we are saying that, we don't know how much you have
     * paid to reach till this state but if you go ahead then you have 
     * to pay dp[row][k_left][State] unit more. 
     */

    if(dp[row][k_left][State]!=-1){
        return dp[row][k_left][State]+cost;
    }
    if(State == 0){ // no blockage in prev row 
        dp[row][k_left][State] = min({sol(row+1 , k_left-1 , 1 , v[row].first),
                                     sol(row+1 , k_left-1 , 2 , v[row].second),
                                     sol(row+1 , k_left , 0 , 0)
                });
    }else if(State == 1){
        dp[row][k_left][State] = min(sol(row+1 , k_left-1 , 1 , v[row].first),
                                     sol(row+1 , k_left , 0 , 0)
                );
    }else if(State == 2){
        dp[row][k_left][State] = min(sol(row+1 , k_left-1 , 2 , v[row].second),
                                     sol(row+1 , k_left , 0 , 0)
                );
    }
    return dp[row][k_left][State]+cost; 
}

signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    while(cin >> n >> k && (n+k)){
        memset(dp , -1 , sizeof(dp));
        v.resize(n); cin >> v; 
        Int cost{};
        for(auto&itr:v){
            cost+=itr.first;
            cost+=itr.second;
        }
        cout << cost-sol(0 , k , 0 , 0) << '\n'; 
    }


#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
