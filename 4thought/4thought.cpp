//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
  #include <iostream>
//  #include <chrono>
  #include <string>
//  #include <utility>
//  #include <queue>
  #include <stack>
//  #include <cmath>
  #include <map>
//  #include <unordered_map>
//  #include <deque>
//  #include <unordered_set>
//  #include <set>
//  #include <climits>
//  #include <sstream>
//  #include <iomanip>
//  #include <cassert>
//  #include <bitset>
//  #include <numeric>
//  #include <vector>
//  #include <array>
//  #include <algorithm>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
#define MOD 1000000007
map<int , string > dp;
char operation[]= {'+' , '-' , '/' , '*'};
int precedence(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
} 
int evaluate(string tokens){ 
    int i; 
    stack <int> values; 
    stack <char> ops; 
    for(i = 0; i < tokens.length(); i++){ 
        if(tokens[i] == ' ') 
            continue; 
        else if(tokens[i] == '('){ 
            ops.push(tokens[i]); 
        } 
        else if(isdigit(tokens[i])){ 
            int val = 0; 
            while(i < tokens.length() &&  isdigit(tokens[i])) { 
                val = (val*10) + (tokens[i]-'0'); 
                i++; 
            } 
            values.push(val); 
        } 
        else if(tokens[i] == ')') { 
            while(!ops.empty() && ops.top() != '(') { 
                int val2 = values.top(); 
                values.pop(); 
                int val1 = values.top(); 
                values.pop(); 
                char op = ops.top(); 
                ops.pop(); 
                values.push(applyOp(val1, val2, op)); 
            } 
            if(!ops.empty()) 
               ops.pop(); 
        } else { 
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                int val1 = values.top(); 
                values.pop(); 
                char op = ops.top(); 
                ops.pop(); 
                values.push(applyOp(val1, val2, op)); 
            } 
            ops.push(tokens[i]); 
        } 
    } 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
        int val1 = values.top(); 
        values.pop(); 
        char op = ops.top(); 
        ops.pop(); 
        values.push(applyOp(val1, val2, op)); 
    } 
    return values.top(); 
} 
void pre(int operator_used, string s){
    if(operator_used == 3){
        int value = evaluate(s);
        dp[value] = s + " = " + to_string(value);
        return;
    }
    for(int i=0,temp;i<4; ++i){
        switch(operation[i]){
            case '+':
                pre(operator_used+1,s+" + 4");
                break;
            case '-':
                pre(operator_used+1,s+" - 4");
                break;
            case '*':
                pre(operator_used+1,s+" * 4");
                break;
            case '/':
                pre(operator_used+1,s+" / 4");
                break;
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    dp[0] = "4 * 4 - 4 * 4 = 0";
    pre(0,"4");
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        if(dp.find(n) != dp.end()){
            cout << dp[n] << '\n'; 
        }else{
            puts("no solution");
        }
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
