#include <iostream>

using namespace std;

class MyArray{
private:
    int *arr;
    int size;
public:
    MyArray(int SIZE){//Parameterized constructor
        this->size = SIZE;
        this->arr = new int [SIZE];
        for(int i = 0;i<SIZE;i++){
            *(arr+i)=0;
        }
    }
    MyArray();
    MyArray(const MyArray &obj){//Copy constructor
        size = obj.size;
        for(int i = 0;i<size;i++){
            *(arr + i) = *(obj.arr + i);
        }
    }
    ~MyArray(){//destructor
        if(size>0){
            delete[] arr;
        }
    };
    int getSize(){//get size
        return this->size;
    }
    int & operator[](const int sub){
        if(sub <0 || sub > size){//Check index range
            cout<<"Error, subscript out of range "<<endl;
            exit(0);
        }
        return this->arr[sub];
    }
    MyArray & operator+(const MyArray &secondArray){//Overload operator +
        int NextIndex =size;
        resize(size+secondArray.size);
        for(int count =0 ;count<secondArray.size;count++){
            arr[count+NextIndex] = secondArray.arr[count];
        }
        return *this;
    }
    MyArray & operator=(const MyArray &right ){ //Overload operator =
        size = right.size;
        for(int i =0 ;i < size;i++){
            arr[i] = right.arr[i];
        }
        return *this;
    }

    MyArray & operator*(const int Num){//Overload operator *integer

        for(int count = 0;count < size;count++){
            arr[count] = arr[count] * Num;
        }
        return reinterpret_cast<MyArray &>(arr);
    }
    MyArray & operator-(const MyArray &secondArray){//Overload operator -
        int Msize = size ;
        MyArray Marr(Msize);
        bool check = false;
        int scount = 0;
        for(int i = 0;i<Marr.size;i++){
            for(int j = 0;j < secondArray.size;j++ ){
                if(arr[i] == secondArray.arr[j]){
                    check = true;
                    Msize--;
                }
            }
            if(check == false){
                Marr.arr[scount] = arr[i];
                scount++;
            }
            check = false;
        }
        for(int i = 0 ;i<Marr.size;i++){
            if(Marr[i] !=0){
                arr[i] = Marr.arr[i];
            }
        }
        size = Msize ;
        return *this;
    }
    bool resize(const int newSize){//resize
        if(newSize > size){
            int *tempArr = new int [newSize];
            for(int count = 0;count < size;count++){
                *(tempArr + count) = *(arr + count);
            }
            delete []arr;
            int nextIndex = newSize - size;
            nextIndex=newSize-nextIndex;
            arr = tempArr;
            size = newSize;
            for(int i =nextIndex;i<newSize;i++){
                arr[i]=0;
            }
            return true;
        }
        return false;
    }

    friend ostream & operator <<(ostream & os,const MyArray &obj);
};
ostream & operator<<(ostream & os ,const MyArray & obj)
{
    for(int count = 0;count < obj.size;count++){
        os<<obj.arr[count]<<'\t';
    }
    cout<<endl;
    return os;
}
void menu(){
    int size;
    cout<<"Enter Size of Array = ";
    cin>>size;
     MyArray arr(size);
    bool close = true;
    while(close){
        int option;
        cout<<"Create Array ,Enter: 1 \n";
        cout<<"Enter array elements, Enter : 2 \n";
        cout<<"Copy array into a new array and display the new array, Enter : 3 \n";
        cout<<"Display an element in array  by index, Enter : 4 \n";
        cout<<"Set an element in array  by index, Enter : 5 \n";
        cout<<" Display array,  Enter : 6 \n";
        cout<<"Concatenate 2 arrays into array, Enter : 7 \n";
        cout<<"Subtract 2 arrays into array, Enter : 8 \n";
        cout<<"Multiply array elements of Array by an integer, Enter : 9 \n";
        cout<<" Expand array, Enter : 10 \n";
        cout<<"Get size of array, Enter : 11 \n";
        cout<<"Exit : 12 \n";
        cin>>option;
        if(option==1){
            MyArray arr(arr.getSize());
            cout<<"A array is created ! \n\n";
        }
        if(option == 2){
            for(int i = 0;i < arr.getSize();i++){
                cout<<"Enter element "<<i+1<<" of Array = ";
                cin>>arr[i];
            }
            cout<<"\n\n";
        }
        if(option == 3){
            MyArray CopyArr (arr.getSize());
            CopyArr = arr;
            cout<<"Copy Array : \t"<<CopyArr<<"\n\n";
        }
        if(option == 4){
            int IndexDisplay;
            cout<<"Enter index = ";
            cin>>IndexDisplay;
            if(IndexDisplay >= 0 && IndexDisplay < arr.getSize()){
                cout<<arr[IndexDisplay];
            }
            cout<<"\n\n";
        }
        if (option == 5){
            int Index;
            int value;
            cout<<"Enter Index number = ";
            cin>>Index;
            if(Index >= 0 && Index < arr.getSize()){
                cout<<"Enter value = ";
                cin>>value;
                arr[Index] = value;
            }
            else{
                cout<<"Error, please Enter valid index.... ";
            }
            cout<<"\n\n";
        }
        if(option == 6){
            cout<<"Array :\t"<<arr<<"\n\n";
        }
        if(option == 7){
            int sizeArr1;
            cout<<"Enter Size of Array1 = ";
            cin>>sizeArr1;
            MyArray arr1(sizeArr1);
            for(int i = 0;i < sizeArr1;i++){
                cout<<"Enter element "<<i+1<<" of Array1 = ";
                cin>>arr1[i];
            }
            int sizeArr2;
            cout<<"Enter Size of Array2 = ";
            cin>>sizeArr2;
            MyArray arr2(sizeArr2);
            for(int i = 0;i < sizeArr2;i++){
                cout<<"Enter element "<<i+1<<" of Array2 = ";
                cin>>arr2[i];
            }
            arr.resize(sizeArr1+sizeArr2);
            arr = arr1+arr2;
            cout<<"\n\n";
        }
        if(option == 8){
            int sizeArr1;
            cout<<"Enter Size of Array1 = ";
            cin>>sizeArr1;
            MyArray arr1(sizeArr1);
            for(int i = 0;i < sizeArr1;i++){
                cout<<"Enter element "<<i+1<<" of Array1 = ";
                cin>>arr1[i];
            }
            int sizeArr2;
            cout<<"Enter Size of Array2 = ";
            cin>>sizeArr2;
            MyArray arr2(sizeArr2);
            for(int i = 0;i < sizeArr2;i++){
                cout<<"Enter element "<<i+1<<" of Array2 = ";
                cin>>arr2[i];
            }
            arr.resize(sizeArr1+sizeArr2);
            arr = arr1-arr2;
            cout<<"\n\n";
        }
        if(option == 9){
            int TimesNum;
            cout<<"Enter integer Number = ";
            cin>>TimesNum;
            arr.operator*(TimesNum);
            cout<<"\n\n";
        }
        if(option == 10){
            int NewSize;
            cout<<"Enter new Size = ";
            cin>>NewSize;
            arr.resize(NewSize);
            cout<<"\n\n";
        }
        if(option == 11){
            cout<<arr.getSize()<<"\n\n";
        }
        if(option==12){
            close = false;
        }
    }
}
int main() {
    menu();
    return 0;
}
