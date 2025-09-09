#include <iostream>
using namespace std;

void BackToFront(int n){
    if(n<10){
        cout << n;
        return;
    }
    cout << n%10;
    BackToFront(n/10);
}

void BackToFrontAndCut(int n){
    n=n/10;
    if(n>=10){
        BackToFront(n);
    }
}

void FrontToBack(int n){
    if(n>=10){
        FrontToBack(n/10);
    }
    cout << n%10;
}

void FrontToBackAndCut(int n){
    n=n/10;
    if(n>=10){
        FrontToBack(n);
    }
}

int main(){

    int n;

    cout << "Input : ";
    cin >> n;
    cout << "Output : " << endl;

    cout << "1) ";
    BackToFront(n);
    cout << endl << "2) ";
    BackToFrontAndCut(n);
    cout << endl << "3) ";
    FrontToBack(n);
    cout << endl << "4) ";
    FrontToBackAndCut(n);

    return 0;
}
