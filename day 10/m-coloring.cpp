// level - hard
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// tc : O(m^v)
// sc : O(v + e)

class Solution {
  public:
    bool isSafe(int node, vector<vector<int>>& graph, int color, vector<int>& colors) {
        for(auto& neighbor: graph[node]) {
            if(colors[neighbor] == color) {
                return false;
            }
        }
        
        return true;
    }
    
    bool coloring(int node, vector<vector<int>>& graph, int m, vector<int>& colors) {
        if(node == graph.size()) {
            return true;
        }
        
        for(int color=1;color<=m;color++) {
            if(isSafe(node, graph, color, colors)) {
                colors[node] = color;
                if(coloring(node+1, graph, m, colors))
                    return true;
                colors[node] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> graph(v);
        for(auto& edge: edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        
        vector<int> colors(v, 0);
        return coloring(0, graph, m, colors);
    }
};