#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100];
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

void Undig(){
    cout << "Enter Vertex and Edge : ";
    cin >> vertex >> edge;
    cout << "Enter u and v :" << endl;

    int u,v;

    for(int i=0;i<edge;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << endl << endl;
    cout << "Undirected graph " << endl;

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

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1. Digraph" << endl;
    cout << "2. Undigraph" << endl;
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
            Undig();
        }else if(ch=='3'){
            break;
        }
    }
    return 0;

}

