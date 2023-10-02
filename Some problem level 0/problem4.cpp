#include <iostream>//20216010_Ahmed maher,20216064_Essam alaa
#include <cstring>
using namespace std;
void count(int lenght,char str[100]){
    int vowelsCounter(0),consonantsCounter(0);
    for(int i=0;str[i]!='\0';i++){//check vowels and consonant
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||
           str[i]=='o' || str[i]=='u' || str[i]=='A' ||
           str[i]=='E' || str[i]=='I' || str[i]=='O' ||
           str[i]=='U')//vowels
        {
            vowelsCounter+=1;
        }
        else if((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z'))//check consonants
        {
            consonantsCounter+=1;
        }

    }
    cout<<"vowels number = "<<vowelsCounter<<endl;
    cout<<"consonants number = "<<consonantsCounter<<endl;
}
void palindrome(int lenght,int flag,char str[100]){
    for(int x=0;str[x]!='\0';x++){//to ignore space between words
        for(int i=0;i<lenght;i++){

            if(str[i]!=str[lenght-1-i]){//check if string palindrome or no
                flag=0;
                break;
            }
        }
    }
    if(flag){
        cout<<"it is Palindrome"<<endl;
    }
    else
        cout<<"it is not Palindrome"<<endl;
}

int main()
{
    char str[100];
    int flag=1;
    int lenght =0;
    cout<<"enter yor string :";
    cin.getline(str, 100);
    lenght = strlen(str);//lenght of string
    count(lenght,str);
    palindrome(lenght,flag,str);
    return 0;
}
