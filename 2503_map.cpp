#include<cstdio>
#include<string>
#include<map>
//#include<sstream>
//#include<iterator>
//#include<iostream>
//#include<boost/algorithm/string.hpp>
//if use boost compile with g++ -std=c++11 2503.cpp -o 2503.out
//sstream can only use " " as token
using namespace std;
/*
void* split(string line, vector<string>& v){
    //boost::split(v, line, [](char c){return c == ' ';});
    istringstream iss(line);
    v.assign((istream_iterator<string>(iss)), (istream_iterator<string>()));
}
*/
int main(){

    map<string, string> m;
    char input[200];
    while(1){
        size_t size;
        gets(input);
        if (input[0] == '\0'){
            break;
        }
        char a[50], b[50];
        sscanf(input, "%s %s", a, b);
        m[b] = a;
    }
    while(gets(input)){
        if (input[0] == '\0'){
            break;
        }
        if (m[input] == "\0") printf("eh\n");
        else{printf("%s\n", m[input].c_str());}
    }
    return 0;
}
