문제를 보고 문제에서 알려주는 조건에 맞춰서 코딩하면 해결할 수 있다고 생각했다.
제거하는 부분에서 어려움이 있었다.
제거를 시킨후에 내가 지금까지 설치한 건물들이 설치가 가능한지를 보는 방법
제거해야되는 구조물을과 연결되어있는 구조물들을 있다면 다시 설치가 가능한지 확인해보는 방법
이렇게 두가지가 있는거 같다.
또한 이 문제는 얼마나 코딩을 알아보기쉽게 구조적으로 작성할 수가 있는지가 중요한 점이였던것 같다.
코딩을 할때 무작정 써내려가는 것이 아닌 얼마나 보기쉬운 코드를 작성할 수 있는지도 확인하자.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool column[111][111];   //기둥
bool beam[111][111]; //보
int N;

bool install_column(int x, int y) {
    if (x == 0) { return true; }
    if (column[x - 1][y] == 1) { return true; }
    if (beam[x][y] == 1) { return true; }
    if (y - 1 >= 0 && beam[x][y - 1] == true) { return true; }
    return false;  //이 구문 빼먹어서 1시간
}

bool install_beam(int x, int y) {
    if (column[x - 1][y] == 1) { return true; }
    if (column[x - 1][y + 1] == 1) { return true; }
    if (y - 1 >= 0 && y + 1 <= N && beam[x][y - 1] == 1 && beam[x][y + 1] == 1) { return true; }
    return false;
}
bool remove(int x, int y, int a) {

}




vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][1];
        int y = build_frame[i][0];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (b == 1) {
            if (a == 0) {
                if (install_column(x, y) == true) {
                    column[x][y] = 1;
                }
            }
            else {
                if (install_beam(x, y) == true) {
                    beam[x][y] = 1;
                }
            }
        }
    }
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            cout << column[i][j] << " ";
        }cout << endl;
    }
    cout << endl << endl;
    for (int i = N; i >= 0; i--) {
        for (int j = 0; j <= n; j++) {
            cout << beam[i][j] << " ";
        }cout << endl;
    }
    return answer;
}
