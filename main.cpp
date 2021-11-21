#include<bits/stdc++.h>
using namespace std;

const int max_n=200001;

vector<int> graph[max_n];
int parent[max_n];
vector<int> parentVector;
queue<int> Q;




//int dfs(int start){
//    visited[start]=true;
//
//
//    if(graph[start].size()==1){
//
//        return score;
//    }
//
//    for (auto v:graph[start]){
//        if(!visited[v]){
//            total_score+=dfs(v);
//
//        }
//    }
//
//    return total_score;
//
//}


pair<int,int> bfs(int start){
    bool visited[max_n]={false};
    int level[max_n]={0};

    Q.push(start);

    pair<int,int> end_max={start,0};

    while(!Q.empty()){
        int cur = Q.front();

        Q.pop();

        visited[cur]=true;
        for(auto v: graph[cur]){
            if(!visited[v]){
                parent[v]=cur;
                level[v] = level[cur]+1;
                end_max.first=v;
                end_max.second=level[v];
                Q.push(v);
                visited[v]=true;

            }
        }
    }
    return end_max;
}

//void dfs(vector<int> adj[], int node, int l,
//         int p, int lvl[], int par[])
//{
//    lvl[node] = l;
//    par[node] = p;
//
//    for(int child : adj[node])
//    {
//        if(child != p)
//            dfs(adj, child, l+1, node, lvl, par);
//    }
//}

//int LCA(int a, int b, int par[], int lvl[])
//{
//// if node a is at deeper level than
//// node b
//    if(lvl[a] > lvl[b])
//        swap(a, b);
//
//// finding the difference in levels
//// of node a and b
//    int diff = lvl[b] - lvl[a];
//
//// moving b to the level of a
//    while(diff != 0)
//    {
//        b = par[b];
//        diff--;
//    }
//
//// means we have found the LCA
//    if(a == b)
//        return a;
//
//// finding the LCA
//    while(a != b)
//        a=par[a], b=par[b];
//
//    return a;
//}

//vector<int> printPath(vector<int> adj[], int a, int b, int n)
//{
//    // stores level of every node
//    int lvl[n+1];
//
//    // stores parent of every node
//    int par[n+1];
//
//    // running dfs to find parent and level
//    // of every node in the tree
//    dfs(adj, 1, 0, -1, lvl, par);
//
//    // finding the lowest common ancestor
//    // of the nodes a and b
//    int lca = LCA(a, b, par, lvl);
//
//    // stores path between nodes a and b
//    vector<int> path;
//
//    // traversing the path from a to lca
//    while(a != lca)
//        path.push_back(a), a = par[a];
//
//    path.push_back(a);
//
//    vector<int> temp;
//
//    // traversing the path from b to lca
//    while(b != lca)
//        temp.push_back(b), b=par[b];
//
//    // reversing the path to get actual path
//    reverse(temp.begin(), temp.end());
//
//    for(int x : temp)
//        path.push_back(x);
//
//    return path;
//}

void find(int start){
    if(start==-1){
        return ;
    }
    parentVector.push_back(start);
    find(parent[start]);
}


int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start= bfs(1).first;
    memset(parent, -1, sizeof(parent));
    int end=bfs(start).first;

    find(end);
//    for (int i = 0; i < parentVector.size(); ++i) {
//        cout<<parentVector[i];
//    }


//    cout<<graph[2].at(0);
//    remove(graph[2].begin(),graph[2].end(),1);
//    cout<<graph[2].at(0);


//    for (int i = 0; i < removed_nodes.size(); ++i) {
//        cout<<removed_nodes[i]<<endl;
//    }
//    return 0;

    if(parentVector.size()>1){
        for (int i = 0; i < parentVector.size()-1; ++i) {

            graph[parentVector[i]].erase(std::remove(graph[parentVector[i]].begin(), graph[parentVector[i]].end(), parentVector[i+1]), graph[parentVector[i]].end());
            graph[parentVector[i+1]].erase(std::remove(graph[parentVector[i+1]].begin(), graph[parentVector[i+1]].end(), parentVector[i]), graph[parentVector[i+1]].end());

        }
    }
    for (int i = 0; i < parentVector.size(); ++i) {
        Q.push(parentVector[i]);
    }
    int third_node;
    int max_length=0;
    pair<int,int> node_max= bfs(parentVector[0]);
    third_node=node_max.first;
    max_length=node_max.second;
//    for (int i = 0; i < parentVector.size(); ++i) {
//        pair<int,int> node_max= bfs(parentVector[i]);
//        if(node_max.second>max_length){
//            third_node=node_max.first;
//            max_length=node_max.second;
//        }
//    }
    cout<<max_length+parentVector.size()-1<<endl<<start<<endl<<end<<endl<<third_node;
    return 0;
}






