#include<stdio.h>
#include<map>
#include<string.h>
#include<iterator>
using namespace std;
//union find + eulerian path
void add_degree(string s, map<string, int> &m){
    if (m.find(s) == m.end()){
        m[s] = 1;
    }else{
        m[s] += 1;
    }
}

string find(string s, map<string, string> & m){
    if (m.find(s) == m.end()){
        m[s] = s;
    }
    if(m[s] == s){
        return s;
    }else{
        return find(m[s], m);
    }
    //return m[s] == s ? s:find(m[s], m);
}

void node_union(string c1, string c2, map<string, string> & m){
    c1 = find(c1, m);
    c2 = find(c2, m);
    m[c1] = c2;
}


int main(){
    char c1[11], c2[11];
    map<string, int> m_degree;
    map<string, string> m_union;
    while(scanf("%s %s", c1, c2)){
        add_degree(c1, m_degree);
        add_degree(c2, m_degree);
        node_union(c1, c2, m_union);
    }
    int oddnum = 0;
    int union_num = 0;
    for (map<string, int>::iterator it = m_degree.begin(); it != m_degree.end(); it++){
        int num = it->second;
        string s = it->first;
        //printf("m_degree[%s] = %d, m_union[%s] = %s\n", s.c_str(), num, s.c_str(), m_union[s].c_str());
        if (num % 2 == 1) oddnum++;
        if (m_union[s] == s) union_num++;
        if (union_num == 2 || oddnum == 3){
            printf("Impossible\n");
            return 0;
        }
    }
    if (oddnum == 0 || oddnum == 2) printf("Possible\n");
    return 0;
}
