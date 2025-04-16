#include <iostream>

using namespace std;

#define MAX_HW 505

int h,w;
int block[MAX_HW][MAX_HW];

void Print(){
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << block[i][j] <<" ";
        }
        cout <<"\n";
    }
    
}

bool Ok(int r, int c){
    bool flag_left = false;
    bool flag_right = false;
    for(int i = c; i >= 0 ; i--){
        if(block[r][i] == 1 || block[r][i] == 2){
            flag_left = true;        }
    }
    for(int i=c; i<w; i++){
        if(block[r][i] == 1 || block[r][i] == 2){
            flag_right = true;
        }
    }
    if(flag_left && flag_right)
        return true;
    else
        return false;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> h >> w;
    
    for(int i=0 ; i<w; i++){
        int tmp_h;
        cin >> tmp_h;
        int x = h-1;
        while(tmp_h--){
            block[x--][i] = 1;
        }
    }
    
    //Print();
    
    int cnt = 0;
    for(int i = h-1; i >=0 ; i--){
        for(int j=1; j<w-1; j++){
            if(block[i][j] == 0){
                if(Ok(i,j)){
                    cnt++;
                    block[i][j] = 2;
                }
            }
        }
    }
    //Print();
    cout << cnt;
    return 0;
}
