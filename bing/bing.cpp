// Author : Amit Kumar 

#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* arr[26];
    int counter{};
    Node(){
        counter = 0;
        for(int i=0;i < 26;++i){
            arr[i] = nullptr;
        }
    }
};
int search(Node*root , string a){
    for(auto&itr:a){
        int x = itr-'a';
        if(root -> arr[x] == nullptr){
            return 0;
        }else{
            root = root ->arr[x];
        }
    }
    return root->counter;
}

void add(Node*root , string a){
    for(auto&itr:a){
        int x = itr - 'a';
        if(root -> arr[x] == nullptr){
            root -> arr[x] = new Node();
        }
        root = root -> arr[x];
        root -> counter +=1;
    }
}

int main(void){
    int n; cin >> n; 
    Node *root = new Node();
    for(int i = 0;  i< n; ++i){
        string a; cin >> a; 
        cout << search(root,a) << '\n'; 
        add(root , a);
    }
    return 0;
}
