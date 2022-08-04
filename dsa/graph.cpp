#include <bits/stdc++.h>
using namespace std;

// *** Breath first search
// ! in gfg they ask for just connected component therefore it wont work there
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

// *** cycle detection in undirected graph using bfs for connected as well as disconnected
bool isCycle(int V, vector<int> adj[])
{
    queue<pair<int, int>> q;
    vector<bool> visited(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push({i, -1});
            visited[i] = true;

            while (!q.empty())
            {
                auto valP = q.front();
                int val = valP.first;
                int pr = valP.second;
                q.pop();

                for (int v : adj[val])
                {
                    if (visited[v] && pr != v)
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

// *** check if graph isBipartite using BFS
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

// *** Shortest Path in (Undirected) graph using BFS , unweighted
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
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
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