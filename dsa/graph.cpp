#include <bits/stdc++.h>
using namespace std;

// TODO graph notes
// **** https://leetcode.com/discuss/general-discussion/1122034/important-graph-algorithm-notes-for-interview  *****

// *** Breath first search
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V + 1, false);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int val = q.front();
                q.pop();
                ans.push_back(val);

                for (int i : adj[val])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    return ans;
}

// *** depth first search
void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int s)
{
    visited[s] = true;
    ans.push_back(s);

    for (int i : adj[s])
    {
        if (!visited[i])
        {
            dfs(adj, visited, ans, i);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    vector<int> ans;
    dfs(adj, visited, ans, 0);
    return ans;
}

// *** check if graph shows topology
// ? Ring :: condn -> 1. Number of vertices >= 3, 2. All vertices should have degree 2, 3. No of edges = No of Vertices.
// ? Star :: condn -> 1. One node (also called the central node) has degree V – 1, 2.All nodes except the central node have degree 1, 3.No of edges = No of Vertices – 1
// ? Bus  :: condn -> 1. Each node except the starting end ending ones has degree 2 while the starting and ending have degree 1, 2. No of edges = No of Vertices – 1. 

// *** cycle detection in undirected graph using bfs for connected as well as disconnected
bool isCycle(int V, vector<int> adj[])
{
    queue<pair<int, int>> q;             // ? queue will store {val,parent}
    vector<bool> visited(V + 1, false);  

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push({i, -1});        // ? starting parent's node will have parent as -1
            visited[i] = true;

            while (!q.empty())
            {
                auto valP = q.front();
                int val = valP.first;
                int pr = valP.second;
                q.pop();

                for (int v : adj[val])
                {
                    if (visited[v] && pr != v)  // ? if visited but parent is not the current then it was visited by some other node ans hence the cycle
                        return true;
                    else if (!visited[v])
                    {
                        visited[v] = true;
                        q.push({v, val});
                    }
                }
            }
        }
    }

    return false;
}

// *** cycle detection in undirected graph using dfs for connected as well as disconnected
bool dfsHelper(vector<int> adj[], vector<bool> &visited, int s, int pr)
{
    visited[s] = true;
    for (int v : adj[s])
    {
        if (visited[v] && v != pr)
        {
            return true;
        }

        if (!visited[v])
        {
            if (dfsHelper(adj, visited, v, s))
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    int ans = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            ans = dfsHelper(adj, visited, i, -1);
            if (ans)
                return true;
        }
    }
    return false;
}

// *** <------------------------ BFS/DFS questions ------------------------------------------>

// *** Find if Path Exists in Graph
bool dfsHelper(vector<int> adj[], vector<bool> &visited, int s, int d){
    visited[s]=true;
    
    for(int i:adj[s]){
        if(i==d){
            return true;
        }else if(!visited[i]){
            if(dfsHelper(adj,visited,i,d)){
                return true;
            }
        }
    }
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if(source==destination) return true;
    vector<int> adj[n];
    for(auto edge:edges){
        int s = edge[0];
        int d = edge[1];
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(dfsHelper(adj,visited,source,destination)) return true;
        }
    }
    return false;
}

// *** Keys and Rooms
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> ans;
    vector<bool> visited(n,false);
    queue<int> q;
    visited[0]=true;
    ans.push_back(0);
    for(int key:rooms[0]){
        q.push(key);
        visited[key]=true;
    }
    
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        vector<int> keyFromNode = rooms[node];
        for(int key:keyFromNode){
            if(!visited[key]){
                q.push(key);
                visited[key]=true;
            }
        }
    }
    return ans.size()==n;
}

// *** Number of islands
bool isValid(int i, int j, int m, int n){
    return (i>=0 && j>=0 && i<m && j<n);
}
void dfs(vector<vector<char>>& grid, int i, int j){
    grid[i][j]='0';
    int m = grid.size();
    int n = grid[0].size();
    if(isValid(i+1,j,m,n) && grid[i+1][j]=='1'){
        dfs(grid,i+1,j);
    }
    if(isValid(i-1,j,m,n) && grid[i-1][j]=='1'){
        dfs(grid,i-1,j);
    }
    if(isValid(i,j+1,m,n) && grid[i][j+1]=='1'){
        dfs(grid,i,j+1);
    }
    if(isValid(i,j-1,m,n) && grid[i][j-1]=='1'){
        dfs(grid,i,j-1);
    }
    
}
int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j]=='1'){
                num++;
                dfs(grid,i,j);
            }
        }
    }
    return num;
}


// *** <------------------------ questions ------------------------------------------>

// *** check if graph isBipartite using BFS
/*
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either
connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, 
or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. 

Note that it is possible to color a cycle graph with even cycle using two colors. It is not possible to color a cycle graph with odd cycle using two colors. 

*/
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    queue<int> q;

    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int n : graph[node])
                {
                    if (color[n] == -1)
                    {
                        color[n] = 1 - color[node];
                        q.push(n);
                    }
                    else if (color[n] == color[node])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

// *** check if graph isBipartite using DFS
bool dfsHelper(vector<vector<int>> &graph, vector<int> &color, int s, int pr)
{
    if (pr == -1)
        color[s] = 1;

    for (int v : graph[s])
    {
        if (color[v] == -1)
        {
            color[v] = 1 - color[s];
            bool temp = dfsHelper(graph, color, v, s);
            if (!temp)
                return false;
        }
        else if (color[v] == color[s])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);

    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == -1)
        {
            bool ans = dfsHelper(graph, color, i, -1);
            if (!ans)
                return false;
        }
    }
    return true;
}

// *** Detect cycle in directed graph using DFS since BFS uses khan's algoF
bool dfsHelper(vector<int> adj[], vector<bool> &visited, vector<bool> &dvisited, int s)
{
    visited[s] = true;
    dvisited[s] = true;

    for (int i : adj[s])
    {
        if (visited[i] && dvisited[i])
        {
            return true;
        }
        else if (!visited[i])
        {
            bool tmp = dfsHelper(adj, visited, dvisited, i);
            if (tmp)
                return true;
        }
    }

    dvisited[s] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    vector<bool> dvisited(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool temp = dfsHelper(adj, visited, dvisited, i);
            if (temp)
                return true;
        }
    }
    return false;
}

// *** topological sort using DFS
void dfsHelper(vector<int> adj[], vector<bool> &visited, stack<int> &ans, int s)
{
    visited[s] = true;

    for (int i : adj[s])
    {
        if (!visited[i])
        {
            dfsHelper(adj, visited, ans, i);
        }
    }

    ans.push(s);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, false);
    vector<int> ans;
    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsHelper(adj, visited, s, i);
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// *** topological sort using BFS using Kahn's algo / also detect cycle using BFS
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        auto v = adj[i];
        for (int e : v)
        {
            indegree[e]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        count++;
        for (int n : adj[node])
        {
            indegree[n]--;
            if (indegree[n] == 0)
                q.push(n);
        }
    }
    // if(count!=V-1) { "Not cyclic , hence topo sort doesn't exist" }
    return ans;
}

// *** <------------------------ TOPOSORT questions ------------------------------------------>

// *** Course Schedule
bool isCyclic(vector<int> adj[], vector<bool> &visited, vector<bool> &dvisited, int s){
    visited[s]=true;
    dvisited[s]=true;
    
    for(int e:adj[s]){
        if(visited[e] && dvisited[e]){
            return true;
        }
        else if(!visited[e]){
            if(isCyclic(adj,visited,dvisited,e)){
                return true;
            }
        }
    }
    dvisited[s]=false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<bool> visited(numCourses,false);
    vector<bool> dvisited(numCourses,false);
    for(auto prerequisite:prerequisites){
        adj[prerequisite[0]].push_back(prerequisite[1]);
    }
    
    for(int i=0; i<numCourses; i++){
        if(!visited[i]){
            if(isCyclic(adj,visited,dvisited,i)){
                return false;
            }
        }
    }
    return true;
}

// *** Course Schedule II
bool topoSort(vector<int> adj[],vector<bool> &visited,vector<bool> &dvisited, stack<int> &st, int s){
    visited[s]=true;
    dvisited[s]=true;
    
    for(int e:adj[s]){
        if(visited[e] && dvisited[e]){
            return true;
        }
        else if(!visited[e]){
            if(topoSort(adj,visited,dvisited,st,e)){
                return true;
            }
        }
    }
    
    dvisited[s]=false;
    st.push(s);
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<bool> visited(numCourses,false);
    vector<bool> dvisited(numCourses,false);
    stack<int> st;
    vector<int> ans;
    for(auto prerequisite:prerequisites){
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }
    
    for(int i=0; i<numCourses; i++){
        if(!visited[i]){
            if(topoSort(adj,visited,dvisited,st,i)){
                return ans;
            }   
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// *** Alien Dictionary
void topoSort(vector<int> adj[],vector<bool> &visited,stack<int> &st,int s){
    visited[s]=true;
    
    for(int e:adj[s]){
        if(!visited[e]){
            visited[e]=true;
            topoSort(adj,visited,st,e);
        }
    }
    
    st.push(s);
}
string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    string prev = dict[0];
    for(int i=1; i<N; i++){
        string s1 = dict[i-1];
        string s2 = dict[i];
        
        for(int j=0; j<min(s1.length(),s2.length()); j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    stack<int> st;
    string ans;
    vector<bool> visited(K,false);
    for(int i=0; i<K; i++){
        if(!visited[i]){
            topoSort(adj,visited,st,i);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top()+'a');
        st.pop();
    }
    
    
    return ans;
}

// *** <------------------------ questions ------------------------------------------>

// *** <------------------------- Shortest Path algorithms ------------------------------------->

// ? 1. Undirected Graph -> dijsktra's algo
// TODO            -> for unweighted graph dijsktra modifies to just simple bfs i.e. priority queue replaces with just queue(since weight is 1)

// ? 2. Directed Graph -> Topological Sort

// *** Dijsktra's algorithm
// ? it doesn't work in case of negative edge, check bellman ford instead
void dijsktra(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,node)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
}


// *** Shortest Path in (Undirected) graph using BFS , unweighted (Modified Dijsktra's)
vector<int> shortestPath(int V, vector<int> adj[])
{
    vector<bool> visited(V + 1, INT_MAX);
    queue<pair<int, int>> q;
    vector<int> distance(V + 1, 0);
    q.push({0, 0});
    visited[0] = true;
    distance[0] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int n : adj[node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push({n, d + 1});
                distance[n] = d + 1;
            }
        }
    }
    return distance;
}

// *** Shortest Path in (Directed) graph using DFS, weighted
void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}
void shortestPath(int src, int N, vector<pair<int, int>> adj[])
{
    int vis[N] = {0};
    stack<int> st;
    for (int i = 0; i < N; i++)
        if (!vis[i])
            findTopoSort(i, vis, st, adj);

    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;
    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        (dist[i] == 1e9) ? cout << "INF " : cout << dist[i] << " ";
}


// *** <----------------- Minimum spannig Tree ------------------->

// *** Prim's Algorithm
#define V 5
// A utility function to find the vertex with 
// minimum key value, from the set of vertices 
// not yet included in MST 
int minKey(int key[], bool mstSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 
  
// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
  
// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(int graph[V][V]) 
{ 
    // Array to store constructed MST 
    int parent[V]; 
      
    // Key values used to pick minimum weight edge in cut 
    int key[V]; 
      
    // To represent set of vertices included in MST 
    bool mstSet[V]; 
  
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; // First node is always root of MST 
  
    // The MST will have V vertices 
    for (int count = 0; count < V - 1; count++)
    { 
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
  
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
  
        // Update key value and parent index of 
        // the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not 
        // yet included in MST 
        for (int v = 0; v < V; v++) 
  
            // graph[u][v] is non zero only for adjacent vertices of m 
            // mstSet[v] is false for vertices not yet included in MST 
            // Update the key only if graph[u][v] is smaller than key[v] 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
  
    // print the constructed MST 
    printMST(parent, graph); 
} 
  

// *** Union Find Algorithm
// *** Kruskals's Algorithm
// *** Bellman ford Algorithm


int main()
{
    vector<int> input[9];
    input[0].push_back(1);
    input[0].push_back(3);
    input[1].push_back(0);
    input[1].push_back(2);
    input[1].push_back(3);
    input[2].push_back(1);
    input[2].push_back(6);
    input[3].push_back(4);
    input[3].push_back(0);
    input[4].push_back(5);
    input[4].push_back(3);
    input[5].push_back(6);
    input[5].push_back(4);
    input[6].push_back(2);
    input[6].push_back(5);
    input[6].push_back(7);
    input[6].push_back(8);
    input[7].push_back(6);
    input[7].push_back(8);
    input[8].push_back(6);
    input[8].push_back(7);
    vector<int> ans = shortestPath(9, input);
    for (int i = 0; i < 9; i++)
    {
        cout << i << " " << ans[i] << endl;
    }
    return 0;
}