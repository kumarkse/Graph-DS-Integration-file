#include<bits/stdc++.h>
#include"graph.cpp"

using namespace std;

void dijkstra( G<int> graph , int N , string src){

    unordered_map<string,int> d;
    unordered_map<string,bool> visited;
    unordered_map< string , vector< pair < int ,pair<int ,string> > >> list;


    for( int i = 0; i < graph.edglist.size() ; i++ ){
        
        // pushing all edges start with that node along with its diatance and weigth of the edge;
        list[graph.edglist[i].first.first] . push_back( { INT_MAX, { graph.edglist[i].second.second , graph.edglist[i].first.second} });
        
    }


    priority_queue<pair<int,string> , vector< pair<int,string>> , greater<pair<int,string>> > que;
   
    // pushing thr source node in the priority queue;
    que.push( { 0 , src} );


    while(! que.empty() ){
      
      pair<int,string> node = que.top();
      visited[node.second] = true;
      que.pop();

      for( auto neighbour : list[node.second]){

          if( ! visited.count(neighbour.second.second) ){

             
                // incase the nodes distance space not initialize yet
              if(!d.count(neighbour.second.second)){
                 
                      // relaxation of the node
                d[neighbour.second.second]  = d[node.second] + neighbour.second.first;

                   // selected node go for the funrther expansion
                que.push( {d[neighbour.second.second] , neighbour.second.second } );

              }
                
                 // if its initialized then we need to check this;
              else if( d[neighbour.second.second] > d[node.second] + neighbour.first ){
                   
                   // relaxation of the node
                d[neighbour.second.second]  = d[node.second] + neighbour.second.first;

                   // selected node go for the funrther expansion
                que.push( {d[neighbour.second.second] , neighbour.second.second } );

              }
          }
      }


      cout<<endl<<endl<<"The minimum distance of all node from the sourse are :"<<endl;

      for( auto x : d){  
           cout<< x.first <<" -> " <<x.second<<endl;
      }

      return ;

      
    }

}


void bellman( G<int> graph , int N , string src){


    vector< pair< pair<string ,string> , pair<int ,int> > > list;
    unordered_map <string ,int > d;

    for(int i = 0;i< graph.edglist.size() ; i++){

          // preparint the edge list for the following operation

        list.push_back( { { graph.edglist[i].first.first ,graph.edglist[i].first.second },{ graph.edglist[i].second.second , INT_MAX }  });
    } 

    d[src] = 0; // source node distance should be zero;


   
    // flag which denotes the presecnce of negative cycle;
   bool flag = false;

    for(int i = 0;i< N ; i++){

        flag = false;
        

        for(int j = 0; j< list.size() ; j++){

            string u = list[j].first.first;
            string v = list[j].first.second;
            int weight = list[j].second.first;

            if( (! d.count(u)) and (!d.count(v)) ) continue; // both distance is infinite;

            else if( !d.count(v) ){

                d[v] = d[u] + weight;
                // denotes relaxation occures;
                flag = true; 
            }

            else if( d.count(u)  and  d[v] > d[u] + weight ){

                d[v] = d[u] + weight;
                // denotes relaxation occures;
                flag = true;
            }
        }

    }


    if( flag ){
        cout << " The graph contains negative cycle !!!"<<endl;
        return;
    }

    cout<<" The shortest path to all the nodes from the source is :"<<endl;

    for( auto x : d){
        cout<< x.first<<" -> "<<x.second<<endl;
    }

    return;
}

int main(){

    G<int> graph;

    
   graph.add_node( 34 , "1");
   graph.add_node( 34 , "2");
   graph.add_node( 34 , "3");

   graph.add_edge( "1" , "2" , "ans1" , 1);
   graph.add_edge( "2" , "3" , "ans2" , 1);
   graph.add_edge( "1" , "3" , "xxx" , 1);
//    graph.add_edge( "3" , "1" , "xxx" , -3);

   dijkstra( graph  , 3 , "1" );

   return 0;
}