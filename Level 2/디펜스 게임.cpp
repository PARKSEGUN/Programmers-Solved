우선순위 큐를 사용해서 해결
언제 큐에 넣어주어야하고 빼줘야하는지가 중요

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    pq.push(0);
    for (int i = 0; i < enemy.size(); i++) {
        if (n - enemy[i] >= 0) {
            answer++;
            pq.push(enemy[i]);
            n -= enemy[i];
        }
        else {
            if (k == 0)
                return answer;
            if (pq.top() < enemy[answer]) {
                answer++;
                k--;
            }
            else {
                pq.push(enemy[answer]);
                n+=pq.top()-enemy[answer];
                answer++;
                pq.pop();
                k--;
            }
        }
    }
}
