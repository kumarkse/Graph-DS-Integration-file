#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left =NULL;
        right = NULL;
    }
};


void permute(vector<vector<int>> & trees,vector<int> arr, int indx){

    if( indx == arr.size()){
        trees.push_back(arr);
        return;
    }

    for(int i = indx ;i < arr.size() ;i++ ){
        swap(arr[i] , arr[indx]);
        permute(trees,arr,indx+1);
        swap(arr[i] , arr[indx]);
    }

    return;
}

node* insertIntoTree(node* root , int data){

    if(root == NULL){
        return  new node(data);
    }

    if(root -> data  < data){
        root->left = insertIntoTree(root->left,data);
    }
    else if(root -> data  > data){
        root->right = insertIntoTree(root->right,data);
    }

}


node* create_trees( vector<int> arr ){

    node* root = NULL;

    for(int  i =0; i< arr.size() ; i++){
        root = insertIntoTree(root,arr[i]);
    }

    return root;

}

void genrtCode(node* root,vector<int> &rootCode){
    
    if(root == NULL)return;

     rootCode.push_back(1);
     genrtCode(root->left,rootCode);
     rootCode.push_back(0);
     genrtCode(root->right,rootCode);

}

bool duplicate_struct(node* root , vector<vector<int>>& treeCodes){
     vector<int> rootCode;
     genrtCode(root,rootCode);

    //  for(auto s: rootCode)
    //   cout<<s;
    //   cout<<endl;

     for(int i = 0;i < treeCodes.size() ; i++){
        if(  rootCode == treeCodes[i]) return true;
     }
     
     treeCodes.push_back(rootCode);
     return false;
}

void remove_same_structure(vector<node*> &roots){

    vector<vector<int>> treeCodes;
    vector<node*> :: iterator it;

    for( it = roots.begin() ; it!= roots.end() ; it++){
         if(  duplicate_struct( (*it) , treeCodes) ){
             roots.erase(it);
             it--;
         }
    }

}





void printTree(node* root, int space = 0, int levels = 3) {
    if (root == nullptr)
        return;

    // Increase the space between levels
    space += levels;

    // Print right child first
    printTree(root->right, space);

    // Print current node after space
    cout<<endl;
    for (int i = levels; i < space; i++)
         cout << " ";
    cout << root->data << endl;

    // Print left child
    printTree(root->left, space);
}

// void print_tree(node* root,int width){

//     if( root == NULL ) return;

    
//     if(root->left)
//     cout<<setw(width-3)<<root->left->data;
//     if(root->right)
//     cout<<setw(6)<<root->right->data;
//     cout<<endl;

//     // if(root->left)
//     // cout<<setw(width-2)<<"/";
//     // if(root->right and root->left)
//     // cout<<setw(8)<<"\\"<<endl;
//     // else if(root->right)
//     //  cout<<setw(width+4)<<"\\"<<endl;

//     print_tree(root->left,width-3);
//     print_tree(root->right,width+3);
// }

void insert_trees(vector<vector<int>> & trees , int n){
      
      vector<int> arr;
      for(int i = 1; i<= n ; i++)
       arr.push_back(i);

      permute(trees,arr,0);

      vector<node*> roots;
      
      for(auto x: trees)
         roots.push_back(create_trees(x));


      for(auto y : roots){
         printTree(y);
         cout<<endl<<endl<<endl<<endl<<endl<<endl;
      }


      
      remove_same_structure(roots);



      

    //   cout<<"size == " <<roots.size();
}



void BST(int n){

    vector<vector<int>> trees;
    insert_trees(trees,n);
  
}

int main(){
    
    BST(4);

}