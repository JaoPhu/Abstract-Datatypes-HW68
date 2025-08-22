#include <iostream>
#include <string>
using namespace std;

struct rec {
    int con;
    int pow;
    rec *next;
};

struct rec* solve(struct rec* p1) {
    string str;
    int con;
    int pow;
    int num=1;
    while(cin >> str&&str!="-99"){
        if(num%2==1){
            con=stoi(str);
            num++;
        }else{
            pow=stoi(str);
            struct rec* node=new struct rec;
            node->next=NULL;
            node->con=con;
            node->pow=pow;
            if(p1==NULL){
                p1=node;
            }else{
                node->next=p1;
                p1=node;
            }
            num=1;
        }
    }
    return p1;
}

int main() {
    struct rec* p1=NULL;
    p1=solve(p1);

    struct rec* w=p1;
    while(w!=NULL){
        cout << w->con << " " << w-> pow << " | ";
        w=w->next;
    }
}

/*
3x^3 + x^2 + 2x + 1
sort 1 + 2x + x^2 + 3x^3
input 1 0 2 1 1 2 3 3
linked lists
|3||3|->|1||2|->|2||1|->|1||0|
*/
