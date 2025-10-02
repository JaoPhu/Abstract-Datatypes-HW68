#include <iostream> //use input output
#include <array> //use array
#include <utility> //can use exchange and swap

using namespace std;
int heapsize=0;
int normal=49;
int priority=100;

int parents(int i){
    return i/2;
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

void Heapify(array<int,101> &A,int i){
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(l<=heapsize&&A[l]>A[i]){
        largest=l;
    }
    if(r<=heapsize&&A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]); //swap A[parents] and A[child]
        Heapify(A,largest); //heapify index node child
    }
}

void Heap_Insert(array<int,101> &A,int key){
    heapsize++;
    int i=heapsize;
    while(i>1&&A[parents(i)]<key){
        A[i]=A[parents(i)];
        i=parents(i);
    }
    A[i]=key;
}

int Heap_Exact_Max(array<int,101> &A){
    if(A[1]>49){
        priority++;
    }else{
        normal++;
    }
    int Max=A[1];
    A[1]=A[heapsize];
    heapsize--;
    Heapify(A,1);
    return Max;
}

void Enqueue(array<int,101> &A){
    char nrq;
    cout << "Normal or Priority (N/P) : ";
    cin >> nrq;
    if(nrq=='N'){
        if(normal!=0){
            Heap_Insert(A,normal);
            cout << "Your queue is : "  << normal << endl << endl;
            normal--;
        }else{
            cout << endl << "The normal queue is full.." << endl << endl;
        }
    }else if(nrq=='P'){
        if(priority!=49){
            Heap_Insert(A,priority);
            cout << "Your queue is : " << priority << endl << endl;
            priority--;
        }else{
            cout << endl << "The priority queue is full.." << endl << endl;
        }
    }else{
        cout << endl << "No Options!!!" << endl << endl;
    }
}

void Dequeue(array<int,101> &A){
    if(heapsize<1){
        cout << endl << "Dequeue# Empty" << endl << endl;
        return;
    }
    cout << endl << "Dequeue# " << Heap_Exact_Max(A) << endl << endl;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Enqueue" << endl;
    cout << "2) Dequeue" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    array<int,101> A;
    char ch;

    while(true){
        ch=menu();
        if(ch=='1'){
            Enqueue(A);
        }else if(ch=='2'){
            Dequeue(A);
        }else if(ch=='3'){
            break;
        }else{
            cout << endl << "No Options!!!" << endl << endl;
        }
    }
    return 0;

}
