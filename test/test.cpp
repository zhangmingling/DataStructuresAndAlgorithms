#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>


using namespace std;

int minInstallTime(int N, vector<int>& time, vector<vector<int>>& dependencies) {
    vector<vector<int>> graph(N);    // 邻接表，存储依赖关系
    vector<int> inDegree(N, 0);      // 入度表
    vector<int> dp(N, 0);            // dp数组，存储每个步骤的最早完成时间

    // 构建图和入度表
    for (int i = 0; i < N; i++) {
        for (int dep : dependencies[i]) {
            if (dep != -1) {
                graph[dep - 1].push_back(i);
                inDegree[i]++;
            }
        }
    }

    // 队列存放所有入度为0的步骤
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = time[i];  // 没有依赖的步骤可以立即执行，完成时间就是其本身时间
        }
    }

    // 拓扑排序
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 更新依赖于当前步骤的所有步骤
        for (int next : graph[cur]) {
            dp[next] = max(dp[next], dp[cur] + time[next]);  // 更新最早完成时间
            inDegree[next]--;                               // 减少入度
            if (inDegree[next] == 0) {
                q.push(next);  // 当入度为0时，可以开始执行
            }
        }
    }

    // 返回所有步骤的最晚完成时间，即最小安装时间
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N;

    vector<int> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    vector<vector<int>> dependencies(N);
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin >> ws, line);
        if (line == "-1") {
            dependencies[i].push_back(-1);
        } else {
            stringstream ss(line);
            int dep;
            while (ss >> dep) {
                dependencies[i].push_back(dep);
            }
        }
    }

    cout << minInstallTime(N, time, dependencies) << endl;

    return 0;
}
