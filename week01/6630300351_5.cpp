#include <iostream>
using namespace std;

int main(){
    int count_word = 0;
    char a[4][4]={ {'T','H','I','S'},
                   {'W','A','T','S'},
                   {'O','A','H','G'},
                   {'F','G','D','T'}};

    //ไม่เอาตัวซ้ำและเอา hat ออกไปหนึ่ง
    string db[16] = {"IS",  "THIS", "HIS",
                     "AT",  "YOU",  "HI",
                     "IT",  "TWO",  "OF",
                     "FAT", "THAT", "GOD",
                     "CAT", "HAT",  "AN", "FOUR"};

    string temp="";

    //left to right
    for(int row=0 ;row<4 ;row++){
        for(int i=0 ;i<4 ;i++){
            for(int j=i ;j<4 ;j++){
                for(int k=i ;k<=j;k++){
                    temp=temp+a[row][k];
                }
                cout << temp;

                for(int c=0 ;c<16 ;c++){
                    if(db[c]==temp){
                        count_word++;
                        cout << " Found " << count_word;
                        db[c]= "-";
                    }
                }
                getchar();
                temp.clear();

            }
        cout << endl;

        }
    }

    //right to left
    for(int row=0 ;row<4 ;row++){
        for(int i=3 ;i>=0 ;i--){
            for(int j=i ;j>=0 ;j--){
                for(int k=i ;k>=j;k--){
                    temp=temp+a[row][k];
                }
                cout << temp;

                for(int c=0 ;c<16 ;c++){
                    if(db[c]==temp){
                        count_word++;
                        cout << " Found " << count_word;
                        db[c]= "-";
                    }
                }
                getchar();
                temp.clear();

            }
        cout << endl;

        }
    }

    //top to bottom
    for(int columns=0 ;columns<4 ;columns++){
        for(int i=0 ;i<4 ;i++){
            for(int j=i ;j<4 ;j++){
                for(int k=i ;k<=j;k++){
                    temp=temp+a[k][columns];
                }
                cout << temp;

                for(int c=0 ;c<16 ;c++){
                    if(db[c]==temp){
                        count_word++;
                        cout << " Found " << count_word;
                        db[c]= "-";
                    }
                }
                getchar();
                temp.clear();

            }
        cout << endl;

        }
    }

    //bottom to top
    for(int columns=0 ;columns<4 ;columns++){
        for(int i=3 ;i>=0 ;i--){
            for(int j=i ;j>=0 ;j--){
                for(int k=i ;k>=j;k--){
                    temp=temp+a[k][columns];
                }
                cout << temp;

                for(int c=0 ;c<16 ;c++){
                    if(db[c]==temp){
                        count_word++;
                        cout << " Found " << count_word;
                        db[c]= "-";
                    }
                }
                getchar();
                temp.clear();

            }
        cout << endl;

        }
    }

    //NE to SW
    for(int i=0 ;i<4 ;i++){
        for(int j=i ;j<4 ;j++){
            for(int k=i ;k<=j ;k++){
                temp=temp+a[k][k];
                }
                cout << temp;

            for(int c=0 ;c<16 ;c++){
                if(db[c]==temp){
                    count_word++;
                    cout << " Found " << count_word;
                    db[c]= "-";
                }
            }
            getchar();
            temp.clear();

        }
        cout << endl;

    }

    //SW to NE
    for(int i=3 ;i>=0 ;i--){
        for(int j=i ;j>=0 ;j--){
            for(int k=i ;k>=j ;k--){
                temp=temp+a[k][k];
                }
                cout << temp;

            for(int c=0 ;c<16 ;c++){
                if(db[c]==temp){
                    count_word++;
                    cout << " Found " << count_word;
                    db[c]= "-";
                }
            }
            getchar();
            temp.clear();

        }
        cout << endl;

    }

    //NW to SE
    for(int i=0,q=3 ;i<4&&q>=0 ;i++,q--){
        for(int j=i,w=q ;j<4&&w>=0 ;j++,w--){
            for(int k=i,e=q ;k<=j&&e>=w ;k++,e--){
                temp=temp+a[k][e];
                }
                cout << temp;

            for(int c=0 ;c<16 ;c++){
                if(db[c]==temp){
                    count_word++;
                    cout << " Found " << count_word;
                    db[c]= "-";
                }
            }
            getchar();
            temp.clear();

        }
        cout << endl;

    }

    //SE to NW
    for(int i=0,q=3 ;i<4&&q>=0 ;i++,q--){
        for(int j=i,w=q ;j<4&&w>=0 ;j++,w--){
            for(int k=i,e=q ;k<=j&&e>=w ;k++,e--){
                temp=temp+a[e][k];
                }
                cout << temp;

            for(int c=0 ;c<16 ;c++){
                if(db[c]==temp){
                    count_word++;
                    cout << " Found " << count_word;
                    db[c]= "-";
                }
            }
            getchar();
            temp.clear();

        }
        cout << endl;

    }
    cout << "Total = " << count_word << endl;

    return 0;
}

