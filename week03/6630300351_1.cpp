#include <iostream>
using namespace std;

int Size = 0;
int arr[10];

void menu(){
    cout << "\n==========Menu========" << endl;
    cout << "    + 1) Insert +" << endl;
    cout << "    + 2) Delete + "<< endl;
    cout << "    + 3) Print + "<< endl;
    cout << "    + 4) Exit + "<< endl;
    cout << "=======================" << endl;
    cout << "   Please choose >  ";
}

void Insert(){
    int data;
    cout << "Enter : ";
    cin >> data;
    if(Size>=10){
        cout << "List Full" << endl;
        return;
    }else{
       arr[Size] = data;
       Size++;
    }

    if(Size>0){
        for(int i=0; i<Size; i++){
            int min_num = arr[i];
            int indexmin = i;
            int tmp;

            for(int j=i; j<Size; j++){
                if(arr[j]<min_num){
                    min_num = arr[j];
                    indexmin = j;
                }
                    tmp = arr[indexmin];
                    arr[indexmin] = arr[i];
                    arr[i] = tmp;
            }
        }
    }

    cout << "Output = ";
    for(int i=0; i<Size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Delete(){
    int data;
    bool check = false;
    cout << "Delete : ";
    cin >> data;

    if(Size==0){
       cout << "List Empty";
       return;
    }

    for(int i=0; i<Size; i++){
        if(arr[i]==data){
            check = true;

            for(int j=i; j<Size; j++){
                arr[j] = arr[j+1];
            }
            Size--;
            break;
        }
    }

    if(check == false){
        cout << "Not Found";
    }else{
        if(Size!=0){
            cout << "Output = ";
            for(int i=0; i<Size; i++){
                cout << arr[i] << " ";
            }
        }else{
            cout << "List Empty";
        }
    }
    cout << "\n";
}

void Print(){
    if(Size!=0){
        if(Size==1){
            cout << "Print \t\t : ";
            cout << arr[0] << " " << endl;

            cout << "Print first half : ";
            cout << arr[0] << " " << endl;

            cout << "Print second half: ";
            cout << "\n";
        }else{
            cout << "Print \t\t : ";
            for(int i=0; i<Size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";

            cout << "Print first half : ";
            for(int i=0; i<Size/2; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";

            cout <<  "Print second half: ";
            for(int i=Size/2; i<Size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }

    }else{
        cout << "List Empty" << endl;
    }
}

int main(){
    bool exit = true;

    while(exit){
        char choose;
        menu();
        cin >> choose;
        switch(choose){
            case '1' :
                Insert();
                break;
            case '2' :
                Delete();
                break;
            case '3' :
                Print();
                break;
            case '4' :
                exit = false;
            default :
                break;
        }
    }
    return 0;
}
