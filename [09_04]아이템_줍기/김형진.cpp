#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool table[101][101] = {};

int search(int characterX, int characterY, int itemX, int itemY){ //테두리를 돌면서 칸 세기
    int left_length = 0;
    int right_length = 0;
    int x = characterX;
    int y = characterY;
    
    int* target_length = &left_length;
    
    do{
        table[x][y] = false; //칸 비활성화
        if(x > 0 and table[x - 1][y]){
            x -=1;
        }
        else if( y > 0 and table[x][y - 1]){
            y -=1;
        }
        else if(x < 101 and table[x + 1][y]){
            x +=1;
        }
        else if (y < 101 and table[x][y + 1]){
            y +=1;
        }
        
        (*target_length)++;
        if(x == itemX and y == itemY){ //아이템이 있는 칸에 도착하면
            target_length = &right_length; //경로의 길이를 담을 포인터 변경
            table[characterX][characterY] = true; //시작점을 다시 활성화
        }
    }while(x != characterX or y != characterY); //다시 시작점에 돌아올 때까지
    return min(left_length, right_length); //두 경로 중 짧은 쪽 선택
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    //전제: 맵을 두배로 늘려야 함
    //우리는 테두리를 기준으로 돌아야 하기 때문에 배열이 사각형의 모서리를 표현해야 한다.
    //그런데 배열이 사각형의 1 * 1칸을 표현하는 식으로 표현했을 때는
    //           *****
    //     *****@*   *
    //   ***   ***   *
    //   *           *
    ///  *           *
    //   *********   *
    //           *****
    // @로 표시한 들어간 부분이 표현되지만, 이를 배열이 사각형의 모서리를 표현한 경우로 바꾸면
    //           ******
    //      ******    *
    //  *****   **    *
    //  *             *
    //  *             *
    //  *             *
    //  **********    *
    //           ******
    //이렇게 전에 @로 표시했던 곳이 없어지면서 구분하기 어려워진다.
    //그래서 모든 좌표를 2배로 만들어 한칸 틈을 만들어주면 구분할 수 있게 된다.
    //최종 거리는 구한 값을 절반으로 나누면 된다.
   
    for(int i = 0; i < rectangle.size(); i++){ //모든 사각형의 테두리 그리기
        for(int col = rectangle[i][1] * 2; col <= rectangle[i][3] * 2; col++){
            table[rectangle[i][0] * 2][col] = true;
            table[rectangle[i][2] * 2][col] = true;
        }
        for(int row = rectangle[i][0] * 2; row <= rectangle[i][2] * 2; row++){
            table[row][rectangle[i][1] * 2] = true;
            table[row][rectangle[i][3] * 2] = true;
         }
    }
    for(int i = 0; i < rectangle.size(); i++){ //모든 사각형 내부에 생긴 모서리 지우기
        for(int col = rectangle[i][1] * 2 + 1; col < rectangle[i][3] * 2; col++){
            for(int row = rectangle[i][0] * 2 + 1; row < rectangle[i][2] * 2; row++){
                table[row][col] = false;
            }   
        }
    }
    return search(characterX * 2, characterY * 2, itemX* 2, itemY * 2)/2; //구한 결과의 절반이 최종 답
}
