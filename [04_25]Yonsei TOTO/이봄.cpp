#include <iostream>
#include <queue>

using namespace std;

int n,m; // 과목 수 n, 주어진 마일리지 m
// pi - 신청한 사람 수, li - 과목의 수강인원
// 각 사람이 마일리지를 얼마나 넣었는지

priority_queue<int> pq_p; // 신청한 사람들의 마일리지 
priority_queue<int,vector<int>, greater<int>> pq_sj; // 성준이가 모든 과목을 신청한다고 했을 때 건 마일리지들.. 

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        int p,l;
        int sj_m;
        
        cin >> p >> l;
        
            for(int j=0; j<p; j++){
                int tmp;
                cin >> tmp;
                pq_p.push(tmp);
            }
        if(p>=l){ // 만약 신청자수가 수강인원보다 많은 경우
            for(int j=0; j<l; j++){
                sj_m = pq_p.top(); // 성공 가능한 마일리지의 최솟값을 저장
                pq_p.pop();
            }
            
            pq_sj.push(sj_m);
            
        }
        else{
            pq_sj.push(1); // 신청자수보다 수강인원이 많은 경우 -> 1을 넣음 
        }
        while(pq_p.empty() == false){
            pq_p.pop();
        }
    }
    
    int ans = 0;

    while(pq_sj.empty() == false){ 
        int tmp_m = pq_sj.top(); // 마일리지 가장 작은 것부터 출력, 가지고 있는 마일리지에서 수강할 수 있는 최대 과목 수 계산
        pq_sj.pop();
        if(m >= tmp_m){
            m -= tmp_m;
            ans++;
        }
        else
            break;
    }
    
    cout << ans;
    
    return 0;
}

/*
 마일리지를 1~36을 분배한다
 목적 - 성준이가 주어진 마일리지로 최대한 많은 과목을 신청하는 것
 단, 마일리지가 같다면 성준이에게 우선순위가 주어진다
 */
