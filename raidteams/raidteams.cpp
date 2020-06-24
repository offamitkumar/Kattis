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
const int MOD  = (int)1e9+7;

struct Data{
    string name; 
    int64_t skill1, skill2, skill3;
    friend istream& operator>>(istream&cin , Data &d){
        cin >> d.name >> d.skill1 >> d.skill2 >> d.skill3;
        return cin;
    }
};

bool compare1(const Data&d1 , const Data&d2){
    if(d1.skill1 == d2.skill1){
        return d1.name < d2.name;
    }
    return d1.skill1 > d2.skill1;
}

bool compare2(const Data&d1 , const Data&d2){
    if(d1.skill2 == d2.skill2)
        return d1.name < d2.name;
    return d1.skill2 > d2.skill2;
}

bool compare3(const Data&d1 , const Data&d2){
    if(d1.skill3 == d2.skill3)
        return d1.name < d2.name;
    return d1.skill3 > d2.skill3;
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
    int64_t n; cin >> n; 
    vector<Data>v1(n),v2(n),v3(n);
    for(int64_t i=0;i<n;++i){
        cin >> v1[i]; 
        v2[i] = v1[i];
        v3[i] = v1[i];
    }
    sort(v1.begin() , v1.end() , compare1);
    sort(v2.begin() , v2.end() , compare2);
    sort(v3.begin() , v3.end() , compare3);
    int64_t i{}, j{}, k{};
    set<string>taken;
    while(i<(int64_t)v1.size() && j<(int64_t)v2.size() && k<(int64_t)v3.size()){
        vector<string>res;
        while(i<(int64_t)v1.size() && taken.find(v1[i].name)!=taken.end()){
            ++i;
        }
        if(i>=(int64_t)v1.size()){
            break;
        }
        taken.insert(v1[i].name);
        res.push_back(v1[i++].name);
        while(j<(int64_t)v2.size() && taken.find(v2[j].name)!=taken.end()){
            ++j;
        }
        if(j>=(int64_t)v2.size()){
            break;
        }
        taken.insert(v2[j].name);
        res.push_back(v2[j++].name);
        while(k<(int64_t)v3.size() && taken.find(v3[k].name)!=taken.end()){
            ++k;
        }
        if(k>=(int64_t)v3.size()){
            break;
        }
        taken.insert(v3[k].name);
        res.push_back(v3[k++].name);
        sort(res.begin() , res.end());
        cout << res << '\n';
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
