// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;
int getX(int n){
    int sum{};
    while(n){
        int a = n%10;
        sum+=(a*a);
        n/=10;
    }
    return sum;
}
bool isprime(int a){
    for(int i=2; i*i<=a;++i){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main(void){
    int t; cin >> t; 
    while(t--){
        int a,b; cin >> a >> b; 
        cout << a << ' ' << b; 
        set<int>s;
        if(!isprime(b)){
            b=1;
        }
        while(b != 1 && s.find(b)==s.end()){
            s.insert(b);
            int x = getX(b);
            b = x;
        }
        if(b==1 && s.size()){
            cout <<" YES";
        }else{
            cout <<" NO";
        }
        cout << '\n'; 
    }
    return 0;
}
