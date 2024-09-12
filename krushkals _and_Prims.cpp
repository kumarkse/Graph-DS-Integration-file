#include<bits/stdc++.h>
#include"graph.cpp"

using namespace std;

// disjoint set funtions
string findParent( unordered_map<string,string> &parent , string node){

   if( ! parent.count(node) ) return node;

   else return findParent( parent , parent[node] );

}

void unionSet( unordered_map<string,string> &parent, unordered_map<string,int> &rank , string node1 , string node2 ){
     
     string u = findParent( parent, node1 );
     string v = findParent( parent , node2 );

     if( rank[u] < rank[v] ){  
        parent[u] = v;
     }
     else if( rank[v] > rank[u] ){  
        parent[v] = u;
     }

     else{
        parent[u] = v;
        rank[v]++;
     }

}

 
  // comparision funtion for the sort function for sorting thr edge list;
bool cmp ( pair<int , pair< string ,string > > a , pair<int , pair< string ,string > > b ){
   return a.first < b.first;
}


void shortest_path( G<int> graph , int N){
  

   // databases used for dijoint set for detecting cycle in the graph;
   unordered_map<string,string> parent;
   unordered_map<string,int> rank;

   vector< pair< int,pair<string,string>> > edge_list;
   vector< pair< int,pair<string,string>> > ans;

   for(int i = 0 ; i < graph.edglist.size() ; i++){
         
          // pushing the edges into the vector
      edge_list.push_back( { graph.edglist[i].second.second ,{graph.edglist[i].first.first , graph.edglist[i].first.second }});

   }
   
   // sorting the edge list according to the weight of the edge;
   sort(edge_list.begin() , edge_list.end() , cmp);

   // minimum Cost to span the whole tree
   int minCost = 0;
  
   
   for(int i = 0;i< edge_list.size() ; i++){
        
        string u =  findParent( parent , (edge_list[i].second.first));
        string v =  findParent( parent , (edge_list[i].second.second));

        if( u != v ){
           unionSet( parent , rank, u , v); 
           minCost += edge_list[i].first;
           // saving the minimum spaning tree edges
           ans.push_back(edge_list[i]);
        }

   }


   cout<<"The minimum spaning tree is :"<<endl<<" ";

   for(auto x : ans){
      cout<<x.second.first<<" -> "<<x.second.second<<endl;
   }

   cout<<endl<<" The minimum Cost of spaning is : "<< minCost;
   return;

}

void prims( G<int> graph , int N){

       
    unordered_map< string , vector<pair< int , pair< string,string >> >> edge_list;

    for(int  i =0 ;i<graph.edglist.size() ; i++){
       edge_list[graph.edglist[i].first.first].push_back ( { graph.edglist[i].second.second , { graph.edglist[i].first.first ,graph.edglist[i].first.second }} );
    }
    

      // initializing min heap 
    priority_queue< pair<int,pair<string,string>> , vector<pair<int,pair<string,string>>> , greater<pair<int,pair<string,string>>>> pq;
    vector<pair<int,pair<string,string>> > ans;

    pq.push(edge_list["1"][0]);

    int minCost = 0;



    for(int i = 1 ; i < N ; i++){

      pair<int,pair<string,string>> Edge = pq.top();
      minCost += Edge.first;
      ans.push_back(Edge);
      pq.pop();
      
      for( auto x : edge_list[Edge.second.second] ){
            pq.push(x);
         }
     
    }

    cout<<"The minimum cost for the minimum spaning tree of thr given graph is : " <<minCost<<endl<<endl;

    cout<<"The path as follows : "<<endl;
    
    for(auto x : ans){
      cout<<x.second.first<<" -> "<<x.second.second<<endl;
    }

   
    
}


int main(){

   G<int> graph;

   graph.add_node( 34 , "1");
   graph.add_node( 34 , "2");
   graph.add_node( 34 , "3");

   graph.add_edge( "1" , "2" , "ans1" , 1);
   graph.add_edge( "2" , "3" , "ans2" , 1);
   graph.add_edge( "1" , "3" , "xxx" , 2);

   prims( graph  , 3 );

   return 0;
}