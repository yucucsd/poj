#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


class node{
private:
    string* rel;
    int* weights;
    int len;
public:
    node();
    void init(int);
    void add_neighbor(string, int);
    string get_neighbor(int);
    int get_weight(int);
    int get_num_nei();
};

node::node(){

}

void node::init(int r){
    len = 0;
    rel = new string[r];
    weights = new int[r];
}
void node::add_neighbor(string s, int w){
    rel[len] = s;
    weights[len] = w;
    len++;
}

string node::get_neighbor(int k){
    return rel[k];
}

int node::get_weight(int i){
    return weights[i];
}

int node::get_num_nei(){
    return len;
}

bool compare(pair<int, string> a, pair<int, string> b){
    if (a.first > b.first){ return true;}
    else if (a.first < b.first){ return false;}
    else{
        if (a.second < b.second){
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    int d;
    cin >> d;
    for(int k = 0; k < d; k++){
        int r;
        int n = 0;
        cin >> r;
        map<string, int> m;
        node* v = new node[r + 1];
        for (int i = 0; i < r + 1; i++){
            v[i].init(r);
        }
        queue<int> q;
        m.insert(pair<string, int>("Ted", n));
        n++;
        for(int i = 0; i < r; i++){
            string f, c;
            int w;
            cin >> f >> c >> w;
            if (m.find(f) == m.end()){
                m.insert(pair<string, int>(f, n));
                n++;
            }
            if (m.find(c) == m.end()){
                m.insert(pair<string, int>(c, n));
                n++;
            }
            v[m[f]].add_neighbor(c, w);
            v[m[c]].add_neighbor(f, -w);
        }
        int* status = new int[r + 1];
        int* ages = new int[r + 1];
        for (int i = 0; i < r + 1; i++){
            status[i] = 0;
            ages[i] = 0;
        }
        status[0] = 1;
        ages[0] = 100;
        q.push(0);
        while(!q.empty()){
            int index = q.front();
            int num_neighbor = v[index].get_num_nei();
            for (int i = 0; i < num_neighbor; i++){
                string s = v[index].get_neighbor(i);
                if(status[m[s]] == 0){
                    q.push(m[s]);
                    ages[m[s]] = ages[index] - v[index].get_weight(i);
                    status[m[s]] = 1;
                }
            }
            q.pop();
        }
        cout << "DATASET " << k + 1 << endl;
        pair<int, string>* out = new pair<int, string>[r];
        int i = 0;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            if (it->first.compare("Ted") != 0){
                out[i] = pair<int, string>(ages[it->second], it->first);
                i++;
            }
        }
        sort(out, out + r, compare);
        for (int i = 0; i < r; i++){
            cout << out[i].second << " " << out[i].first << endl;
        }
    }
}
