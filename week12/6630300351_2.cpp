#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100];
bool pass[100];
int d[100];
int f[100];
int pred[100];
int Time=0;
int vertex;
int edge;

void Dig(){
    cout << "Enter Vertex and Edge : ";
    cin >> vertex >> edge;
    cout << "Enter u and v :" << endl;

    int u,v;

    for(int i=0;i<edge;i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << endl << endl;
    cout << "Directed graph" << endl;

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
    d[u]=Time++;
    for(int i=0;i<adj[u].size();i++){
        if(pass[adj[u][i]]==false){
            pred[adj[u][i]]=u;
            DFS_Visit(adj[u][i]);
        }
    }
    pass[u]=true;
    f[u]=Time++;
}

void DFS(){
    int u;
    for(int i=0;i<vertex;i++){
        pass[i]=false;
        d[i]=-1;
        f[i]=-1;
        pred[i]=-1;
    }
    cout << "Enter source : ";
    cin >> u;
    pred[u]=u;
    DFS_Visit(u);
    for(int i=0;i<vertex;i++){
        if(pass[i]==false){
            pred[i]=i;
            DFS_Visit(i);
        }
    }
    cout << "Output" << endl;
    cout << "Pred" << endl;
    for(int i=0;i<vertex;i++){
        cout << i << " | " << pred[i] << endl;
    }
    cout << endl;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1. Input Graph" << endl;
    cout << "2. DFS" << endl;
    cout << "3. Exit" << endl;
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
            }else{
                cout << endl << "No Data!!!" << endl << endl;
            }
        }else if(ch=='3'){
            break;
        }
    }
    return 0;

}

/*
[Input Directed Graph]

Please choose >  1
Enter Vertex and Edge : 6 7
Enter u and v :
0 1
0 3
1 4
2 4
2 5
4 3
5 5
*/
