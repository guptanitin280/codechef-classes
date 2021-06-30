//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
void dfs(int node,vector<int>adj[],bool vis[],vector<int>&ans){
    vis[node]=true;
    ans.push_back(node);
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,adj,vis,ans);
        }
    }
}
//Function to return a list containing the DFS traversal of the graph.
vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int>ans;
    bool vis[V];
    memset(vis,false,sizeof vis);
    dfs(0,adj,vis,ans);
    return ans;

}