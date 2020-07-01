// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

const int N = 33000;
int lp[N+1];
vector<int> pr;


int main(void){

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        map<int , int>f;
        for(int i=0;i<(int)pr.size();++i){
            for(int j=i;j<(int)pr.size();++j){
                const int &m = pr.at(i) + pr.at(j);
                if(m > n){
                    break;
                }else if(m == n){
                    if(pr.at(i) < pr.at(j)){
                        f[pr.at(i)] = pr.at(j);
                    }else{
                        f[pr.at(j)] = pr.at(i);
                    }
                }
            }
        }
        printf("%d has %d representation(s)\n" , n , (int)f.size());
        for(auto&itr:f){
            cout << itr.first <<"+" << itr.second << '\n'; 
        }
        cout << '\n'; 
    }
    return 0;
}
