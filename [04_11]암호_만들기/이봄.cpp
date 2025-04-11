#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> vec;
vector<char> ans;

bool Ok(){
    int vow_cnt = 0;
    int con_cnt = 0;
    for(int i=0; i<l; i++){
        if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
            vow_cnt++;
        else
            con_cnt++;
    }
    if(vow_cnt >= 1 && con_cnt >= 2)
        return true;
    else
        return false;
}

void Print(){
    for(int i=0; i<l; i++)
        cout << ans[i];
    cout <<"\n";
}

void Backtracking(int idx, int cnt){
    if(cnt == l){
        if(Ok())
            Print();
        return;
    }
    if(idx == c)
        return;
    for(int i=idx; i<c; i++){
        ans.push_back(vec[i]);
        Backtracking(i+1, cnt+1);
        ans.pop_back();
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 입력
    cin >> l >> c;
    char ch;
    int cnt = 0;
    while(cin >> ch){
        if( ch >= 'a' && ch <= 'z'){
            vec.push_back(ch);
            cnt++;
        }
        if(cnt == c)
            break;
    }
    
    sort(vec.begin(), vec.end());
    
    //for(int i=0; i<c; i++)
    //    cout << "i : " <<i <<" "  << vec[i] <<" ";
    
    // 문제 풀기 ~
    Backtracking(0,0);
    
    
    
    return 0;
}

