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

const int DSIZE = 4;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};

vector<vector<char>>grid(1005, vector<char>(1005,'0'));
int n , m; 

bool check(int x, int y){
    if(x < 0 || y < 0 || x >=n+3 || y >= m+3 || grid[x][y] != '0'){
        return false;
    }
    return true;
}

int counter {};
void dfs(int x,int y){

    grid[x][y] = 'W';
    for(int i=0;i<DSIZE; ++i){
        int tx = x + X[i];
        int ty = y + Y[i];
        if(check(tx,ty)){
            dfs(tx,ty);
        }
    }



//     queue<int>q;
//     q.push(x);
//     q.push(y);
//     int max_Size = 0;
//     while(!q.empty()){
//         max_Size = max(max_Size , (int)q.size());
//         int a = q.front(); q.pop();
//         int b = q.front(); q.pop(); 
//         grid[a][b] ='W';
//         for(int i=0;i<DSIZE; ++i){
//             int tx = a + X[i];
//             int ty = b + Y[i];
//             if(check(tx,ty)){
//                 q.push(tx);
//                 q.push(ty);
//             }
//         }
//     }

}

int check3(int x, int y){
    if(x < 0 || y < 0 || x >=n+3 || y >=m+3 || grid[x][y]=='W'){
        return 0;
    }
    if(grid[x][y] == 'X' || grid[x][y]=='0'){
        return 2;
    }
    return 3;
}

void bfs1(int x, int y ){
    queue<int>q;
    q.push(x);
    q.push(y);
    grid[x][y] ='X';
    int max_Size{};
    while(!q.empty()){
        max_Size = max(max_Size , (int)q.size());
        int a = q.front(); q.pop();
        int b = q.front(); q.pop(); 
        for(int i=0;i<DSIZE; ++i){
            int tx = a + X[i];
            int ty = b + Y[i];
            int yy = check3(tx,ty);
            if(yy==3){
                grid[tx][ty] ='X';
                q.push(tx);
                q.push(ty);
            }else if(yy!=2){
                ++counter;
            }
        }
    }
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

    cin >> n >> m; 
    for(auto i:range(1 , n+1)){
        for(auto j:range(1,m+1)){
            cin >> grid[i][j];
        }
    }
    dfs(0,0);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(grid[i][j] == '1'){
                bfs1(i,j);
            }
        }
    }
    cout << counter << '\n'; 

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
