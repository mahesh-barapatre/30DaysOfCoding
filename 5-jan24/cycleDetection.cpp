class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]){
        visited[node]=1;
        for(auto i: adj[node]){
            if(!visited[i]){
                bool checkcycle = dfs(i,node,visited,adj);
                if(checkcycle) return 1;
            }
            else if(i!=parent) return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector <int> visited(V,0);
       for(int i=0; i<V; i++){
           if(!visited[i]){
               if(dfs(i, -1, visited, adj)==1)
               return 1;
           }
       }
       return 0;
    }
};