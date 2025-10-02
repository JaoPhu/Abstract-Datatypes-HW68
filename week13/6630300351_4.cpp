#include <iostream>
#include <vector>
#include <string>
#include<list>

using namespace std;

vector<int> adj[100];
vector<string> des={"Undershorts","Pants","Belt","Shirt","Tie","Jacket","Sock","Shoes","Watch"};
bool pass[100];
int d[100];
int f[100];
int pred[100];
int Time=0;
int vertex;
int edge;

list<int> l;
bool passofmax[100];

void Dig(){
    cout << "Enter Vertex and Edge : ";
    cin >> vertex >> edge;
    cout << "Enter u and v :" << endl;
    int u,v;
    for(int i=0;i<edge;i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << endl << "Directed graph" << endl;
    for(int i=0;i<vertex;i++){
        cout << "#" << i << " : ";
        for(int j=0;j<adj[i].size();j++){
            if(j==adj[i].size()-1){
                cout << adj[i][j];
            }else{
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void DFS_Visit(int u){
    pass[u]=true;
    d[u]=++Time;
    for(int i=0;i<adj[u].size();i++){
        if(pass[adj[u][i]]==false){
            pred[adj[u][i]]=u;
            DFS_Visit(adj[u][i]);
        }
    }
    f[u]=++Time;
}

void DFS(){
    int u=0;
    for(int i=0;i<vertex;i++){
        pass[i]=false;
        d[i]=-1;
        f[i]=-1;
        pred[i]=-1;
    }
    pred[u]=u;
    DFS_Visit(u);
    for(int i=0;i<vertex;i++){
        if(pass[i]==false){
            pred[i]=i;
            DFS_Visit(i);
        }
    }
}


void Topological_Sort(){
    for(int i=0;i<vertex;i++){
        passofmax[i]=false;
    }
    l.clear();
    for(int i=0;i<vertex;i++){
        int Max=-1;
        int index=-1;
        for(int j=0;j<vertex;j++){
            if(f[j]>Max&&!passofmax[j]){
                Max=f[j];
                index=j;
            }
        }
        passofmax[index]=true;
        l.push_back(index);
    }
    int no=0;
    for(auto i : l){
        cout << endl;
        cout<< no+1 << "." << des[i];
        no++;
    }
    cout << endl;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Input Graph" << endl;
    cout << "2) DFS" << endl;
    cout << "3) Topological sort" << endl;
    cout << "4) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    char ch;
    while(true){
        ch=menu();
        if(ch=='1'){
            Dig();
        }else if(ch=='2'){
            if(vertex>0){
                DFS();
                cout << endl;
            }else{
                cout << endl << "No Data!!!" << endl << endl;
            }
        }else if(ch=='3'){
            cout << endl;
            Topological_Sort();
            cout << endl;
        }else if(ch=='4'){
            break;
        }
    }
    return 0;

}

/*

Node number | Description
        0       Undershorts
        1       Pants
        2       Belt
        3       Shirt
        4       Tie
        5       Jacket
        6       Sock
        7       Shoes
        8       Watch

[Input Directed Graph]

Please choose >  1
Enter Vertex and Edge : 9 9
Enter u and v :
0 1 Undershorts -> Pants
0 7 Undershorts -> Shoes
1 2 Pants -> Belt
1 7 Pants -> Shoes
2 5 Belt -> Jacket
3 2 Shirt -> Belt
3 4 Shirt -> Tie
4 5 Tie -> Jacket
6 7 Sock -> Shoes

test 1 9 9 0 1 0 7 1 2 1 7 2 5 3 2 3 4 4 5 6 7 2 3

f[0-8]
10 9 6 14 13 5 16 8 18
 0 1 2  3  4 5  6 7  8

Topological_Sort time max -> min
18(8) 16(6) 14(3) 13(4) 10(0) 9(1) 8(7) 6(2) 5(5)

1.Watch
2.Sock
3.Shirt
4.Tie
5.Undershorts
6.Pants
7.Shoes
8.Belt
9.Jacket

*/
