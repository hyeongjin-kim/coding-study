#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<string, string>, bool>> sortTicket;
vector<bool> vis;
vector<string> path;

bool dfs(int depth) {
    if (depth == sortTicket.size()) return true;

    string cur = path.back();
    auto start = lower_bound(sortTicket.begin(), sortTicket.end(), make_pair(make_pair(cur, string("AAA")), false));
    auto end = upper_bound(sortTicket.begin(), sortTicket.end(), make_pair(make_pair(cur, string("ZZZ")), true));
    for (auto it = start; it != end; ++it) {
        if (it->second) continue;
        it->second = true;
        path.push_back(it->first.second);
        if (dfs(depth + 1)) return true;
        path.pop_back();
        it->second = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    for (auto it = tickets.begin(); it != tickets.end(); ++it)
        sortTicket.push_back({ {(*it)[0], (*it)[1] }, false });

    sort(sortTicket.begin(), sortTicket.end());
    vis.resize(sortTicket.size(), false);

    path.push_back("ICN");

    dfs(0);

    return path;
}
