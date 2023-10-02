#include <iostream>//Ahmed Maher_20216010,Essam Alaa_20216064
#include <cstdlib>
#include <stdlib.h>
using namespace std ;
void welcome()
{
    cout<<"Welcome to FCI bank! \n";
    cout<<"Hello user , please choose an option from menu below \n";
    cout<<"1) show your current accounts \n";
    cout<< "2)create new account \n";
    cout<< "3)withdraw/deposit money \n";
    cout<< "4)Exit \n";
}
void newaccount(string **arr) {
    // Array[code, currency, amount, type]
    static int counter = 0;
    int code;
    code=rand() % 200 + 10;
    arr[counter][0] = to_string(code);
    cout<<"pleas choose the currency 1) EGP 2) USD \n";
    cin>> arr[counter][1];
    if (arr[counter][1] == "1") {
        arr[counter][1]  = "EGP";
    } else {
        arr[counter][1]  = "USD";
    }
    // Amount of money
    cout << "Please specify amount you will deposit for initial balance \n";
    cin >> arr[counter][2];
    // The Type
    cout << "Please specify type of account 1-savings/2-recurring deposit \n";
    cin >> arr[counter][3];
    if (arr[counter][3] == "1") {
        arr[counter][3] = "savings";
    } else {
        arr[counter][3] = "recurring";
    }
    cout << "You have successfully created a bank account! its details as follows:\n";
    cout << "currency: " <<arr[counter][1] << " balance: " << arr[counter][2] << " type : " << arr[counter][3] <<"\tCode " <<code<<endl;
    counter++;
}
int checkCode(string code, string **arr){
    for(int i =0; i <50; ++i){
        if(code == arr[i][0])
            return i;
    }
    return -1;
}
int withdraw(string **arr){
    string code;
    int amount;
    cout<<"Please specify account code that will withdraw/deposit from\n";
    cin>>code;
    int accountIndex = checkCode(code, arr);
    if(accountIndex == -1){
        return 0;
    }
    int choice;
    cout<<"Please specify either you will 1-withdraw or 2-deposit\n";
    cin>>choice;

    cout<<"Please specify amount\n";
    cin >> amount;
    if(choice == 1){
        arr[accountIndex][2] = to_string(stoi(arr[accountIndex][2]) - amount);
    } else{
        arr[accountIndex][2] = to_string(stoi(arr[accountIndex][2]) + amount);
    }
}

int main() {
    // For Dynamic Memory
    string **arr = new string*[50];
    for(int i =0; i < 50; ++i){
        arr[i] = new string[4];
    }
    for(int i =0; i < 50; ++i){
        for(int j =0; j < 4; ++j)
            arr[i][j] = "None";
    }
    int option = 0;
    while (option != 4) {
        welcome();
        cin >> option;
        if (option == 1) {
            for(int i =0; i < 4; ++i){
                cout << i+1 << " - " << "[code, currency, amount, type]\n";
                for(int j=0; j < 4; ++j){
                    cout << arr[i][j] << "\t";
                }
                cout << endl;
            }
        } else if (option == 2) {
            newaccount(arr);
        } else if (option == 3) {
            if(!withdraw(arr)){
                cout<< "Invalid Code\n\n";
            }
        } else if (option == 4) {
            cout << "EXIT \n";
        } else { cout << "choose a correct option \n"; }
    }
}