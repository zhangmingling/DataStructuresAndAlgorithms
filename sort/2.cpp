#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 使用命令结构来表示每个程序的命令
struct Command {
    string type;
    string arg1;
    string arg2;
};

// 记录是否在执行路径中访问过某个标签，避免死循环
bool dfs(int index, unordered_map<string, int>& label_to_index, const vector<Command>& commands, unordered_set<int>& visited, unordered_set<int>& current_path) {
    if (index >= commands.size()) return false;  // 结束情况，正常执行完
    if (current_path.count(index)) return true;  // 在当前路径中已经访问过，说明有循环
    if (visited.count(index)) return false;      // 已经检查过，不再需要重复检查

    visited.insert(index);
    current_path.insert(index);

    const Command& cmd = commands[index];

    if (cmd.type == "halt") {
        return false;  // 结束程序
    } else if (cmd.type == "goto") {
        int next_index = label_to_index[cmd.arg1];
        return dfs(next_index, label_to_index, commands, visited, current_path);
    } else if (cmd.type == "gotorand") {
        // 随机跳转两个标签中的一个
        int next_index1 = label_to_index[cmd.arg1];
        int next_index2 = label_to_index[cmd.arg2];
        return dfs(next_index1, label_to_index, commands, visited, current_path) ||
               dfs(next_index2, label_to_index, commands, visited, current_path);
    } else {
        // 其他命令，继续下一条命令
        return dfs(index + 1, label_to_index, commands, visited, current_path);
    }

    current_path.erase(index);  // 回溯
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Command> commands(n);
    unordered_map<string, int> label_to_index;  // 标签到命令行的映射

    // 读取输入命令
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "label") {
            string label;
            cin >> label;
            label_to_index[label] = i;  // 记录标签位置
            commands[i] = {cmd, label, ""};
        } else if (cmd == "print") {
            string message;
            cin >> message;
            commands[i] = {cmd, message, ""};
        } else if (cmd == "goto") {
            string label;
            cin >> label;
            commands[i] = {cmd, label, ""};
        } else if (cmd == "gotorand") {
            string label1, label2;
            cin >> label1 >> label2;
            commands[i] = {cmd, label1, label2};
        } else if (cmd == "halt") {
            commands[i] = {cmd, "", ""};
        }
    }

    // 使用 DFS 检查是否有循环
    unordered_set<int> visited;
    unordered_set<int> current_path;

    bool has_loop = dfs(0, label_to_index, commands, visited, current_path);

    if (has_loop) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
