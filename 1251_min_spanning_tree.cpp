#include <iostream>
#include <stdlib.h>
using namespace std;
/*
3
A 2 B 99 C 99
B 1 C 99
*/
class Node{
private:
    int val;
    int* neighbors;
    int* weights;
    int ns;
public:
    Node();
    void assign_val(int);
    void print_attributes();
    void add_neighbor(int, int);
    void init(int);
    int get_min_weight(int*);
    int get_neighbor_weight(int, int*);
};
Node::Node(){

}
void Node::assign_val(int c){
    val = c;
}
void Node::print_attributes(){
    cout << val << endl;
    cout << "neighbors: ";
    for (int i = 0; i < ns; i++){
        cout << neighbors[i] << " ";
    }
    cout << endl;
    cout << "weights: ";
    for (int i = 0; i < ns; i++){
        cout << weights[i] << " ";
    }
    cout << endl;
}
void Node::init(int n){
    neighbors = (int*)malloc(n * sizeof(int));
    weights = (int*)malloc(n * sizeof(int));
    ns = 0;
}
void Node::add_neighbor(int node, int w){
    neighbors[ns] = node;
    weights[ns] = w;
    ns++;
}
int Node::get_min_weight(int* covered){
    int min_weight = -1;
    for (int i = 0; i < ns; i++){
        if (covered[neighbors[i]] == 1) continue;
        if (min_weight < 0 || min_weight > weights[i])
            min_weight = weights[i];
    }
    return min_weight;
}
int Node::get_neighbor_weight(int w, int* covered){
    for (int i = 0; i < ns; i++){
        if (covered[neighbors[i]] == 1) continue;
        if (weights[i] == w) return neighbors[i];
    }
    return -1;
}
void update(int* covered, int &sum, Node* nodes, int n){
    int min_node = -1;
    int min_weight = -1;
    for (int i = 0; i < n; i++){
        if(covered[i] == 0) continue;
        int w = nodes[i].get_min_weight(covered);
        if (w > 0 && (min_weight < 0 || min_weight > w)){
            min_weight = w;
            min_node = i;
        }
    }
    //cout << "min_other_node = " << min_node << endl;
    min_node = nodes[min_node].get_neighbor_weight(min_weight, covered);
    //cout << "min_weight = " << min_weight << " min_node = " << min_node << endl;
    sum += min_weight;
    covered[min_node] = 1;
}
int main(){
    int n;
    while (cin >> n){
        if (n == 0) break;
        Node* nodes = new Node[n];
        for (int i = 0; i < n; i++){
            nodes[i].assign_val(i);
            nodes[i].init(n);
        }
        for (int k = 0; k < n - 1; k++){
            char c;
            int e;
            cin >> c >> e;
            for (int i = 0; i < e; i++){
                char ct;
                int et;
                cin >> ct >> et;
                nodes[(int) (c - 65)].add_neighbor((int) (ct - 65), et);
                nodes[(int) (ct - 65)].add_neighbor((int) (c - 65), et);
            }
        }
        // for (int i = 0; i< n; i++){
        //     cout << "node[" << i << "]: ";
        //     nodes[i].print_attributes();
        // }
        int* covered = new int[n];
        int cover_num = 0;
        int min_node = -1;
        int min_weight = -1;
        for (int i = 0; i < n; i++) covered[i] = 0;
        for (int i = 0; i < n; i++){
            int w = nodes[i].get_min_weight(covered);
            if (min_weight < 0 || min_weight > w){
                min_weight = w;
                min_node = i;
            }
        }
        //cout << min_node << " " << min_weight << endl;
        int sum = min_weight;
        covered[min_node] = 1;
        covered[nodes[min_node].get_neighbor_weight(min_weight, covered)] = 1;
        cover_num += 2;
        while(cover_num != n){
            update(covered, sum, nodes, n);
            cover_num++;
            // cout << "covered = ";
            // for (int i = 0; i < n; i++) cout << covered[i] << " ";
            // cout << endl;
        }
        cout << sum << endl;
    }
}
