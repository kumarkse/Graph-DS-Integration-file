#include<bits/stdc++.h>
using namespace std;
#include"graph.cpp"


 void Dfs( G<int> graph , int N, int src){

    vector<vector<int>> adj_list(N);

    for(int i = 0 ; i < graph.adj.size(); i++){

         list< G<int> :: node*> :: iterator it = graph.adj[0].begin();

        for( it = graph.adj[i].begin(); it != graph.adj[i].end() ; it++){

             if( it == graph.adj[i].begin() ) continue;

             adj_list[(*(graph.adj[i].begin()))->data].push_back((*it)->data);
        }
    } 

   
     vector<bool> visit(N,true);
     stack<int> que;
     que.push(src);

     while(!que.empty()){

        int node = que.top();
        cout<<node<<"->";   // the data in bfs order
        que.pop();
        visit[node] = false;

        for(auto neighbour : adj_list[node]){
            if(visit[neighbour]){
                que.push(neighbour);
            }
        }
     }

     return ;
} 

int main(){

    G<int> graph;
    graph.add_node(0,"a");
    graph.add_node(1,"b");
    graph.add_node(2,"c");
    graph.add_node(3,"d");
    graph.add_node(4,"e");
    graph.add_node(5,"f");
    graph.add_edge( "a","b","y",5);
    graph.add_edge( "b","d","h",5);
    graph.add_edge( "a","c","h",5);
    graph.add_edge( "b","e","h",5);
    graph.add_edge( "c","f","h",5);
    graph.print();
    Dfs( graph , 6 , 0);
}