#include<iostream>
#include<cstdlib>
using namespace std;
//Note this is a directed graph
//Dijkstra’s shortest path algorithm

class node{
private:
    int* edges;
    int rank;
    int length;
public:
    node();
    node(int n, int val, int rank);
    void add_neighbor(int neighbor, int price);
    void print_attributes();
    int get_distance(int k);
    int get_rank();
};
node::node(){}
node::node(int n, int val, int inrank){
    edges = new int[n + 1];
    length = n + 1;
    for (int i = 0; i < n; i++) edges[i] = -1;
    edges[n] = val;
    rank = inrank;
}
void node::add_neighbor(int neighbor, int price){
    edges[neighbor] = price;
}
void node::print_attributes(){
    cout << "neighbors: " << endl;
    for (int i = 0; i < length; i++){
        if (edges[i] != -1) cout << i << " edge_length: " << edges[i] << endl;
    }
    cout << "rank = " << rank << endl;
}
int node::get_distance(int k){
    return edges[k];
}

int node::get_rank(){
    return rank;
}

int main(){
    int M, N;
    while(cin >> M >> N){
        node* ns = new node[N + 1];
        int** node_record = new int*[N];
        int** edge_record = new int*[N * N];
        for (int i = 0; i < N; i++){
            node_record[i] = new int[2];
        }
        for (int i = 0; i < N * N; i++){
            edge_record[i] = new int[3];
        }
        int record_length = 0;
        for (int i = 0; i < N; i++){
            int val, rank, sub;
            cin >> val >> rank >> sub;
            node_record[i][0] = val;
            node_record[i][1] = rank;
            for (int k = 0; k < sub; k++){
                int neighbor, price;
                cin >> neighbor >> price;
                edge_record[record_length][0] = i;
                edge_record[record_length][1] = neighbor - 1;
                edge_record[record_length][2] = price;
                record_length++;
            }
        }
        for (int i = 0; i < N; i++){
            ns[i] = node(N, node_record[i][0], node_record[i][1]);
        }
        int end_rank = ns[0].get_rank();
        ns[N] = node(N, 0, end_rank);
        for (int i = 0; i < N; i++){
            ns[N].add_neighbor(i, node_record[i][0]);
        }
        for (int i = 0; i < record_length; i++){
            //ns[edge_record[i][0]].add_neighbor(edge_record[i][1], edge_record[i][2]);
            ns[edge_record[i][1]].add_neighbor(edge_record[i][0], edge_record[i][2]);
        }
        int end_distance = -1;
        int low = end_rank - M > 0?end_rank - M : 0;
        for(int lowest_rank = low; lowest_rank <= end_rank; lowest_rank ++){
            //cout << "low_rank = " << lowest_rank << endl;
            int* distance = new int[N + 1];
            int* out_node = new int[N + 1];
            for (int i = 0; i < N; i++){
                distance[i] = -1;
                out_node[i] = 0;
            }
            distance[N] = 0;
            out_node[N] = 1;
            while(out_node[0] == 0){
                int minimum_distance = -1;
                int minimum_node = -1;
                for (int i = 0; i < N + 1; i++){
                    if (out_node[i] == 0) continue;
                    for (int k = 0; k < N; k++){
                        if (out_node[k] == 1) continue;
                        if (ns[k].get_rank() < lowest_rank || ns[k].get_rank() > lowest_rank + M) continue;
                        int distancet = ns[i].get_distance(k);
                        if (distancet >= 0){
                            distancet += distance[i];
                            if (minimum_node < 0){
                                minimum_node = k;
                                minimum_distance = distancet;
                            }else{
                                if (distancet < minimum_distance){
                                    minimum_node = k;
                                    minimum_distance = distancet;
                                }
                            }
                        }
                    }
                }
                distance[minimum_node] = minimum_distance;
                out_node[minimum_node] = 1;
                // cout << "distance: ";
                // for (int i = 0; i < N + 1; i++) {
                //     cout << distance[i] << " ";
                // }
                // cout << "\nout_node: ";
                // for (int i = 0; i < N + 1; i++) {
                //     cout << out_node[i] << " ";
                // }
                // cout << endl;
            }
            if (end_distance < 0){
                end_distance = distance[0];
            }else{
                if (distance[0] < end_distance)
                    end_distance = distance[0];
            }
            // for (int i = 0; i < N + 1; i++) {
            //     cout << "Node " << i << ":"<< endl;
            //     ns[i].print_attributes();
            // }
            free(distance);
            free(out_node);
        }
        cout << end_distance << endl;
        free(ns);
        free(node_record);
        free(edge_record);
    }
}
