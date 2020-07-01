// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

using LInt = __int128;
ostream& operator<<(ostream&cout , LInt number){
    auto toString = [](LInt num){
        auto tenPow18 = 1000000000000000000;
        std::string str;
        do {
            long long digits = num % tenPow18;
            auto digitsStr = std::to_string(digits);
            auto leading0s = (digits != num) ? std::string(18 - digitsStr.length(), '0') : "";
            str = leading0s + digitsStr + str;
            num = (num - digits) / tenPow18;
        } while (num != 0);
        return str;
    };
    cout << toString(number);
    return cout;
}

istream& operator>>(istream&cin , LInt &number){
    string s; cin >> s; 
    number = 0;
    bool neg_flag =false;
    for(auto&itr:s){
        if(itr=='-'){
            neg_flag = true;
            continue;
        }
        number *= 10;
        number += (itr-'0');
    }
    if(neg_flag){
        number*=(-1);
    }
    return cin;
}

int main(void){
    LInt n ,m , t; 
    cin >> m >> n >> t; 
    LInt x = 1;
    bool ok = true;
    switch(t){
        case 1:
            for(LInt i =1; i<=n; ++i){
                x*=i;
                if(x > m){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout <<"AC";
            }else{
                cout <<"TLE";
            }
            break;
        case 2:
            for(LInt i =1; i<=n; ++i){
                x*=2;
                if(x > m){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout <<"AC";
            }else{
                cout <<"TLE";
            }
            break;
        case 3:
            if(n*n*n*n>m){
                cout << "TLE";
            }else{
                cout << "AC";
            }
            break;
        case 4:
            if(n*n*n>m){
                cout <<"TLE";
            }else{
                cout <<"AC";
            }
            break;
        case 5:
            if(n*n>m){
                cout <<"TLE";
            }else{
                cout <<"AC";
            }
            break;
        case 6:
            if((double)n * double(log2((long double)n)) > (double)m){
                cout <<"TLE";
            }else{
                cout <<"AC";
            }
            break;
        case 7:
            if(n > m){
                cout <<"TLE";
            }else{
                cout <<"AC";
            }
            break;
    }
    cout << '\n'; 
    return 0;
}
