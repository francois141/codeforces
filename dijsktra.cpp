#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

class Dijskstra
{
public:
    Dijskstra(vector<vector<pair<int,int>>> &adj)
    {
        this->adj = adj;
    }

    Dijskstra(vector<vector<pair<int,int>>>&& adj)
    {
        this->adj = std::move(adj);
    }

    [[nodiscard]] vector<int> run(int start) {
        int n = adj.size();
        vector<int> d(n);
    
        d[start] = 0;
        set<pair<int, int>> q;
        q.insert({0, start});
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase(q.begin());
    
            for (auto edge : adj[v])
            {
                int to = edge.first;
                int len = edge.second;
    
                if (d[v] + len < d[to])
                {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    q.insert({d[to], to});
                }
            }
        }

        return d;
    }
    
private:
    vector<vector<pair<int,int>>> adj;
    const long long int INF = LLONG_MAX;
};
