#include <iostream>
#include <string>

using namespace std;

#define MAX_N 2000000

int n;
bool prime[MAX_N];

void Prime_num(){
    prime[0] = false;
    prime[1] = false;
    
    for(int i=2; i*i <= MAX_N; i++){
        if(prime[i]){
            for(int j= i*i; j < MAX_N; j += i){
                prime[j] = false;
            }
        }
    }
}


bool Palindrome(string str){
    
    int sz = (int) str.size();
    
    for(int i=0; i<sz/2; i++){
        if(str[i] != str[sz-i-1])
            return false;
    }

    return true;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fill(prime, prime+MAX_N, true);
    
    cin >> n;
    
    Prime_num();
    
    while(true){
        int tmp = n++;
        string str = to_string(tmp);
        if(prime[tmp] && Palindrome(str)){
            cout << str;
            break;
        }
    }
    return 0;
}

