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

void show_me() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void show_me(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "]:", show_me(__VA_ARGS__)
#else
#define show(...) 0
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

    string a,b; cin >> a >> b; 
    string o_a = a , o_b = b;
    if(a.size() > b.size()){
        string s = string(a.size()-b.size(),'0');
        b = s + b;
    }else if(a.size() < b.size()){
        string s = string(b.size() - a.size(),'0');
        a = s + a;
    }
    int yoda = 2;
    bool ok = true;
    for(int i=0;i<(int)a.size();++i){
        if(a[i] >= b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout <<"YODA" << '\n'; 
        cout << b << '\n'; 
        return 0;
    }
    ok = true;
    for(int i=0;i<(int)a.size();++i){
        if(a[i] <= b[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << a << '\n'; 
        cout <<"YODA" << '\n'; 
        return 0;
    }
    for(int i=0;i<(int)min(a.size() , b.size());++i){
        if(a[i] < b[i]){
            a[i] = '.';
        }else if(b[i] < a[i]){
            b[i] = '.';
        }
    }
    string x = "0",y = "0";
    for(auto&itr:a){
        if(itr!='.'){
            x+=itr;
        }
    }
    for(auto&itr:b){
        if(itr!='.'){
            y+=itr;
        }
    }
    cout << atoi(x.c_str()) << '\n'; 
    cout << atoi(y.c_str()) << '\n'; 

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
