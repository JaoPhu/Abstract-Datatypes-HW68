#include <iostream>
using namespace std;

int main(){
    int a[10] = {3,8,6,5,1,9,4,10,7,2};

    for(int i=0 ;i<10 ;i++){
        int min_num = a[i];
        int indexmin = i;
        int tmp;

        for(int j=i ;j<10 ;j++){
            if(a[j] < min_num){
                min_num = a[j];
                indexmin = j;
            }
        }
        tmp = a[indexmin];
        a[indexmin] = a[i];
        a[i] = tmp;
    }

    for(int i=0 ;i<10 ;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
