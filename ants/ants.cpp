// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;

int main(void){
    /*
     * two ants walk towards each other and then start walking in different direction
     * let a be point of 1st ant and b be point of 2nd ant then if first ant start moving
     * towards b and 2nd ant start moving towards a then they will collide at (abs(b-a))/2
     * because of same speed. so it take same time if
     * 1. 1st ant move from a point to b 
     * 2. 2nd ant move from b point to a
     * 3. both collide and start moving in diff direction and then fall off. 
     */ 
    int t; cin >> t; 
    while(t--){
        int n , k; cin >> k  >> n;  
        int min_t , max_t; 
        for(int i=0; i< n;++i){
            int a; cin >> a; 
            if(i == 0){
                min_t = min(a , k-a); 
                max_t = max(a , k-a);
            }
            min_t = max(min_t , (int)min(a , (k-a)));
            max_t = max({max_t , a , (k-a)});
        }
        cout << min_t << ' ' << max_t << '\n'; 
    }
    return 0;
}
