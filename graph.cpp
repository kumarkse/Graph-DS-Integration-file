#include<bits/stdc++.h>
using namespace std;

template <typename T> class G{

    public :
   
   struct node{
    T data;
    string name;
    node(T data, string name){
        this->data = data;
        this->name = name;
    }
   };

   vector<list<node*>> adj;
   vector<pair<pair<string,string>,pair<string,int>>> edglist;


   
  void garbagecollect(){
        
    typename vector<list<node*>> :: iterator itr ;

      for( itr = adj.begin() ; itr != adj.end() ; ++itr){
              
           if( (*itr).size() == 0 ){
             adj.erase(itr);    // removing the empty list into the adj vector
             itr--;
           }
      }
   }

//   public : 

   void add_node(T data,string name){

        // new node should be  treated as disconnected graph.
        //  until there exist a edge comprises of this node.

        list<node*> newnode;
        newnode.push_front(new node(data,name));
        adj.push_back(newnode);
   }



   void add_edge(string node1 ,string node2,string name,int weight){

       // maintaining edges list
         edglist.push_back({{node1,node2},{name,weight}});

         // according to the new edges added altering the adj list
           
           typename list<node*>:: iterator itr;
           typename vector<list<node*>> :: iterator x;
           node* temp = NULL;


           bool flag = true;

            
         for( x = adj.begin() ; x != adj.end() ; x++){

            for(itr = (*x).begin(); itr != (*x).end() ; ++itr){
                   
                   // find node2 and save its data to the temp.
                    // and delete it from the  adj_list if its an diconnected graph
                   if( (*itr)-> name == node2 ){
                       temp = (*itr);
                    //    (*x).erase(itr);
                       flag = false;
                       break;
                   }
            }



            itr = (*x).begin();

            if((*x).size() == 0 ){
                adj.erase(x);
            }

            if(flag == false)break;
         }

         if(flag){

            // node2 not found 
             cout<<"The nodes are not exist"<<endl;
             return;
         }
         

       
         
        //  typename vector<list<node*>> :: iterator x;

         for( x = adj.begin(); x != adj.end() ; x++){

             itr = (*x).begin();
                      // add the temp node to the last if the list denoting the node1.
                   if( (*itr)-> name == node1 ){
                       (*x).push_back(temp);
                       garbagecollect();
                       return;
                   }
               
         }
         
         // first node is not found;
         cout<<"The nodes are not exist"<<endl;

        //  list<node*> revert;

        //  revert.push_back(temp);    // reverting the previously deleted node
        //  adj.push_back(revert);


   }



   void delete_node(string node1){
         
       
       // deleting from the adj list

         typename vector<list<node*>> :: iterator itr;
         typename list<node*>:: iterator it;
              // auto funtion do make copy of the container and then perform the task so we use iterator instread.

       for( itr = adj.begin(); itr != adj.end(); itr++){
                 
                 // if the list denoting  the node1 then al the edges shoud be deleted from the adjlist
             if( (*((*itr).begin()))->name == node1 ){
                 adj.erase(itr);
                 itr--;  // when we delete the element the itr goes to just next element automaticaly so decrement it to stck to that place only
                 continue;
             }
             
             for(  it = (*itr).begin() ; it != (*itr).end() ; it++){

                   if( (*it)->name == node1){
                       (*itr).erase(it);
                       break;   // because an vertex will be appear only once in an list 
                   }
             }
            
       }


       // deleting the edge from the edge list
       // if the node contributing to an edge then the edge should also be deleted.
       

       typename vector<pair<pair<string,string>,pair<string,int>>> :: iterator x;

       for( x = edglist.begin(); x!= edglist.end() ; x++){
            
             
                 // if the first node or the second node of the edge matches the node we need to delete
             if( (*x).first.first == node1 || (*x).first.second == node1 ){
                 edglist.erase(x);
                 x--;
             }
             
             
       }


   }

   
    void delete_edge(string edge){

        // deleting the edge with  edge name 

        

        string node1= "";
        string node2= "";

        typename vector<pair<pair<string,string>,pair<string,int>>> :: iterator itr;

        for( itr = edglist.begin() ; itr != edglist.end() ; itr++){

            if( (*itr).second.first == edge ){
                 node1 = (*itr).first.first;
                 node2 = (*itr).first.second;
                 edglist.erase(itr);
                 break;
             }
        }

        


        if( node1 == "" || node2 == ""){
            cout<<"The nodes creating the edge does't exist "<<endl;
            return;
        }

        // deleting the egde from the adjlist.

         typename vector<list<node*>> :: iterator x;
         typename list<node*>:: iterator it;


         

        for( x = adj.begin() ; x != adj.end() ; x++){

            if( (*(*x).begin())->name == node1){

                for( it = (*x).begin() ; it != (*x).end() ; it++){
                    if( (*it)->name == node2 ){
                        (*x).erase(it); 
                        return;    // there should be exist only one edge so just after deleting the node we used to return from thr funtion 
                    }
                }
            }

        }

   }

   void delete_edge(string node1 , string node2){

        // deleting the edge ny the name of nodes which created the edge.

         typename vector<pair<pair<string,string>,pair<string,int>>> :: iterator itr;
         bool flag = true;

        for( itr = edglist.begin() ; itr != edglist.end() ; itr++){

            if( (*itr).first.first == node1 and (*itr).first.second == node2 ){
                 edglist.erase(itr);
                 flag = false;
             }
        }

        if(!flag){
            cout<<"No such edge exist's "<<endl;
            return;
        }

        //deleting the element from the adj list.

          typename vector<list<node*>> :: iterator x;
          typename list<node*>:: iterator it;

          for( x = adj.begin() ; x != adj.end() ; x++){

            if( (*((*x).begin()))->name == node1){

                for( it = (*x).begin() ; it != (*x).end() ; it++){
                    if( (*it)->name == node2 ){
                        (*x).erase(it); 
                        return;    // there should be exist only one edge so just after deleting the node we used to return from thr funtion 
                    }
                }
            }

        }

   }


   void print(){
       
       for(auto x : adj){
            
           cout<<(*(x.begin()))->data<<"->"<<" ";
           for( auto it = x.begin(); it != x.end() ; it++){
               if(it == x.begin())continue;
               cout<<((*it)->data)<<",";
           }
           
           cout<<endl;
       }
   }

};

// int main(){

//     G<int> graph;

//     graph.add_node(0,"a");
//     graph.add_node(1,"b");
//     graph.add_node(2,"c");
//     graph.add_node(3,"d");
//     graph.add_node(4,"e");
//     graph.add_node(5,"f");
//     graph.add_node(6,"g");
//     graph.add_node(7,"h");
//     graph.add_node(8,"i");
//     graph.add_node(9,"j");
//     graph.add_edge( "a" , "b" , "abs", 5);
//     graph.add_edge( "c","a","esh",5);
//     graph.add_edge( "h","f","eshi",5);
//     graph.add_edge( "j","a","eshih",5);
//     graph.add_edge( "e","f","eshis",5);
//     graph.add_edge( "i","f","eshiw",5);
       

//     graph.print();

//     // graph.delete_node("f");

//     graph.print();


//     return 0;
// }