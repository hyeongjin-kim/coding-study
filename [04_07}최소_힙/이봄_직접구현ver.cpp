#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100005

int n;
long long arr[MAX_N];
int heap_idx = 0;
vector<long long> vec;

void heap_push(long long value){
    // 트리의 가장 마지막 노드 다음에 현재 삽입하고자 하는 데이터 넣기.
    int idx = ++heap_idx;
    arr[idx] = value;
    
    // 부모노드와 비교하면서 부모 노드보다 더 작은 값이라면 부모 노드와 swap
    while((idx != 1) && (value < arr[idx/2])){
        swap(arr[idx], arr[idx/2]);
        idx = idx/2;
    }
}

long long heap_pop(){
    // 루트노드에 존재하는 최솟값을 저장하기
    long long min_val = arr[1];
    
    // 루트노드로 가장 마지막 노드로 옮기고 힙 크기 줄이기
    arr[1] = arr[heap_idx--];
    
    int parent = 1;
    int child = 0;
    while(true){
        child = parent * 2;
        // 오른쪽 자식이 존재하고, 왼쪽 자식보다 더 작으면 오른쪽 자식을 선택
        if(child + 1 <= heap_idx && arr[child] > arr[child+1])
            child++;
        if(child > heap_idx || arr[child] > arr[parent])
            break;
        swap(arr[child], arr[parent]);
        parent = child;
    }
    return min_val;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        if(tmp == 0){
            // 배열 가장 작은 값 출력 & pop
            // 배열 비어있으면 0 출력
            if(heap_idx == 0)
                vec.push_back(0);
            else{
                long long x = heap_pop();
                vec.push_back(x);
            }
        }
        else{
            // 배열에 값을 넣기
            heap_push(tmp);
        }
    }
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] <<"\n";
    return 0;
}

