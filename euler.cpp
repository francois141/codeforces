#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <queue>
#include <utility>
#include <random>
using namespace std;

class EulerianPath {
public:
    EulerianPath(int size): size(size), graph(vector<multiset<int>>(size)) {};

    bool exists() {
        return all_of(graph.begin(), graph.end(), [](const auto& s) {
            return s.size() % 2 == 0;
        });
    }

    vector<vector<int>> getEulerianPath() {
        vector<vector<int>> paths;

        for(int i = 0; i < graph.size();i++) {
            if(!graph[i].empty()) {
                path.clear();
                dfs(i);
                reverse(path.begin(), path.end());
                paths.push_back(path);
            }
        }

        return paths;
    }

    void addEdge(int from, int to) {
        graph[from].insert(to);
        graph[to].insert(from);
    }

private:
    void dfs(int at) {
        while (!graph[at].empty()) {
            // Get next edge
            int next = *graph[at].begin();

            // Erase both edges
            graph[at].erase(graph[at].begin());
            auto it = find(graph[next].begin(), graph[next].end(), at);
            if (it != graph[next].end()) {
                graph[next].erase(it);
            }

            // DFS until this one
            dfs(next);
        }
        path.push_back(at);
    }

    int size;
    vector<int> path;
    vector<multiset<int>> graph;
};



