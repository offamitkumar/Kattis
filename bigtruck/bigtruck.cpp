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
  Log_Gen(T...);
}
 
#ifdef HELL_JUDGE
#define Log(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define Log(...) 0
#endif

typedef int64_t Int;

class NumberIterator : iterator<forward_iterator_tag, int> {
    public:
        int v;

        NumberIterator(int x) : v(x) {}

        operator int &() { return v; }

        int operator*() { return v; }
};

class range : pair<int,int> {
    public:
        range(int begin, int end) : pair<int,int>(begin, max(begin, end)) {}
        range(int n) : pair<int,int>(0, max(0, n)) {}
        NumberIterator begin() {
            return first;
        }
        NumberIterator end() {
            return second;
        }
};

template<typename Container , typename ValType>
bool present(const Container &t , const ValType &val){
    return (t.find(val) != t.end());
}

template<>
bool present<string>(const string &s , const char &val){
    return (s.find(val) == string::npos);
}

template<>
bool present<string>(const string &s , const string &val){
    return (s.find(val) == string::npos);
}
 
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


struct Node{
    int End{}; 
    int cost{};
    int item{};
};
bool operator<(const Node&a ,const Node&b){
    if(a.cost == b.cost){
        return a.item < b.item;
    }
    return a.cost > b.cost;
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

    int n; cin >> n; 
    vector<int>v(n); cin >> v; 
    int m; cin >> m; 
    Node temp;
    vector<vector<Node>>graph(n+1);
    // Edges are bi-directional so take a visited array 
    while(m--){
        int u , V , w; cin >> u >> V >> w; 
        temp.End = V; 
        temp.cost = w; 
        graph.at(u).push_back(temp);
        temp.End = u; 
        graph.at(V).push_back(temp);
    }
    priority_queue<Node>pq;
    temp.End = 1; 
    temp.cost = 0; 
    temp.item = v[0];
    pq.push(temp);
    vector<int>dist(n+1,10000000); 
    vector<int>item(n+1,0);
    vector<bool>visited(n+1,false);
    dist[1] = 0; 
    item[1] = v[0];
    while(!pq.empty()){
        temp = pq.top(); pq.pop(); 
        if(visited[temp.End]){
            continue;
        }
        visited[temp.End] = true;
        for(auto &itr: graph[temp.End]){
            if(dist[itr.End] > dist[temp.End] + itr.cost){
                dist[itr.End]= dist[temp.End] + itr.cost; 
                item[itr.End] = item[temp.End] + v[itr.End-1];
                pq.push({itr.End,dist[itr.End], item[itr.End] });
            }else if(dist[itr.End] == dist[temp.End] + itr.cost){
                item[itr.End] = max(item[itr.End] , item[temp.End] + v[itr.End-1]);
                pq.push({itr.End,dist[itr.End], item[itr.End] });
            }
        }
    }
    if(dist[n]==10000000){
        cout <<"impossible"<<'\n';
    }else{
        cout << dist[n] <<' ' << item[n]<<'\n';
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
