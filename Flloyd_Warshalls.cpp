#include<bits/stdc++.h>
#include"graph_matrix.cpp"

using namespace std;

void allpairShortestPath(G<int> graph , int N){


    //  cout<<" till now"<<endl;

for(int k = 0 ; k < N ; k++){

    for( int i = 0 ; i < N ; i++){

        if( i == k ) continue;

        for(int j = 0; j < N ; j++){

           if(j == k)continue;

           if( i == j ){
               graph.adj[i][j].first = 0;
           }

           else{
           graph.adj[i][j].first = min( graph.adj[i][j].first , abs(graph.adj[i][k].first + graph.adj[k][j].first));
           }
        }
    }

}

cout<<endl<<endl<<"The all pair shortest path look like :"<<endl;

for(auto x : graph.adj){

    for( auto y : x){
        cout<<y.first<<"  ";
    }cout<<endl;

  }

return;
}

int main(){

    G<int> graph(4);


    graph.add_node( 3 ,"1");
    graph.add_node( 3 ,"2");
    graph.add_node( 3 ,"3");
    graph.add_node( 3 ,"4");

    graph.add_edge( "1" , "2" , "ed" , 3);
    graph.add_edge( "2" , "1" , "ed" , 8);
    graph.add_edge( "1" , "4" , "ed" , 7);
    graph.add_edge( "4" , "1" , "ed" , 2);
    graph.add_edge( "3" , "1" , "ed" , 5);
    graph.add_edge( "2" , "3" , "ed" , 2);
    graph.add_edge( "3" , "4" , "ed" , 1);

    // graph.print();

    allpairShortestPath(graph,4);
    return 0;
}