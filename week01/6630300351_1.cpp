#include <iostream>
using namespace std;

int main(){
    int input_num,count_modulus = 0;
    cout << "input : ";
    cin >> input_num;

    if(input_num <= 1){
        cout << "Not prime";
        return 0;

    }else{
        for(int i=1 ;i<=input_num ;i++){
            if(input_num%i==0){
                count_modulus++;
            }
        }

        if(count_modulus == 2){
            cout << "Prime";
            return 0;
        }else{
            cout << "Not prime";
            return 0;
        }
    }


}
