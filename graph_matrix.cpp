#include <bits/stdc++.h>
using namespace std;

template <typename T>
class G
{

    struct node
    {
        int index;
        T data;
        string name;

        node(T data, string name)
        {
            this->data = data;
            this->name = name;
        }
    };

    int size;
    int count;

public:
    vector<vector<pair<int, string>>> adj;

    // taking matrix size;
    G(int size)
    {

        count = 0;
        this->size = size;
        adj = vector<vector<pair<int, string>>>(size, vector<pair<int, string>>(size, {INT_MAX, ""}));
    }

    unordered_map<int, node *> list; // storing nodes data;

    void add_node(T data, string name)
    {

        // storing the node in the map;
        list[count++] = new node(data, name);

        // creating  relation of the node with itself
        adj[count - 1][count - 1] = {0, ""};
    }

    void add_edge(string node1, string node2, string name, int weight)
    {
        int i = -1, j = -1;

        for (int k = 0; k < count; k++)
        {
            if (list.count(k))
            {

                if (((list[k]))->name == node1)
                    i = k;

                else if (((list[k]))->name == node2)
                    j = k;
            }
        }

        // check for node exixtance
        if (i == -1 || j == -1)
        {
            cout << "The nodes for the edge isn't exist" << endl;
            return;
        }

        // creating the edge
            adj[i][j] = {weight, name};
    }

    void delete_node(string name)
    {

        int nodeidx = -1;

        for (int i = 0; i < count; i++)
        {

            if (list[i].name == name)
            {
                nodeidx = i;
                break;
            }
        }

        // deleting all the edge comprises of  this node

        for (int i = 0; i < count; i++)
        {

            adj[nodeidx][i] = {INT_MAX, ""};
            adj[i][nodeidx] = {INT_MAX, ""};
        }

        // deleting the node;

        list.erase(nodeidx);
    }

    void delete_edge(string node1, string node2)
    {

        int node1_idx = -1;
        int node2_idx = -1;

        // finding the index of these nodes

        for (int k = 0; k < count; k++)
        {

            if (list[k].name == node1)
                node1_idx = k;

            else if (list[k].name == node2)
                node2_idx = k;
        }

        //  check if the node exist or not?

        if (node1_idx == -1 or node2_idx == -1)
        {
            cout << " The edge does not exist" << endl;
            return;
        }

        // finally deleting the edge

        adj[node1_idx][node2_idx] = {INT_MAX, ""};
    }

    void delete_edge(string edge_name)
    {

        // finding the edge

        for (int i = 0; i < count; i++)
        {

            for (int j = 0; j < count; j++)
            {

                if (adj[i][j].second == edge_name)
                {

                    adj[i][j] = {INT_MAX, ""};
                    return;
                }
            }
        }

        cout << "The edge does not exist" << endl;
    }

    void print()
    {

        for (int i = 0; i < size; i++)
        {

            bool flag = false;

            if (adj[i][i].first == 0)
            {
                cout << i << "->";
                flag = true;
            }

            if (flag)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == j)
                        continue;
                    if (adj[i][j].first < INT_MAX)
                    {
                        cout << j << "->";
                    }
                }
                cout << endl;
            }
        }
    }
};

// int main()
// {

//     G<int> graph(6);
//     graph.add_node(0,"a");
//     graph.add_node(1,"b");
//     graph.add_node(2,"c");
//     graph.add_node(3,"d");
//     graph.add_node(4,"e");
//     graph.add_node(5,"f");
//     graph.add_edge( "a","b","y",5);
//     graph.add_edge( "a","c","h",5);
//     graph.add_edge( "b","d","h",5);
//     graph.add_edge( "b","e","h",5);
//     graph.add_edge( "c","f","h",5);

//     graph.print();
// }