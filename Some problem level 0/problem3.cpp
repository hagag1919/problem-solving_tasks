#include <iostream>//20216010_Ahmed maher,20216064_Essam alaa
using namespace std;
void Score(double grades[30][30], double average[30], int studNum, int quizzsNum)
{
    float sum = 0;
    for (int i = 0; i < studNum; i++)
    {
        sum = 0;
        for (int j = 0; j < quizzsNum; j++)
        {
            sum +=grades[i][j];
        }
        average[i] = sum / quizzsNum;
    }
    int maxStudScore = 0;
    float maxScore = 0;
    for (int i = 0; i < studNum; i++)
    {
        if (average[i] > maxScore)
        {
            maxScore = average[i];
            maxStudScore = i+1 ;
        }
    }
    for (int i = 0; i < quizzsNum; i++)
    {
        float sum = 0;
        for (int j = 0; j < studNum; j++)
        {
            sum += grades[j][i];

            average[i] = sum / studNum;
        }

    }
    for(int i=0;i<studNum;i++){
        for(int j=0;j<quizzsNum;j++){
            cout<<"average for student " << i + 1 <<" in quiz"<<i+1<< " = "<<grades[i][j]<<'\t'<<average[i]<<endl;
        }
    }
    cout << "The highest student is " << maxStudScore;
}
int main (){
    double grades[30][30];
    double average[30];
    int studNum,quizzsNum;
    cout<<"Enter number of student = ";
    cin>>studNum;
    cout<<"Enter number of quizzs = ";
    cin>>quizzsNum;
    for(int i=0;i<studNum;i++){
        for(int j=0;j<quizzsNum;j++){
            cout << "enter grade of quizz " << j + 1 << " " << "for student:" << i + 1 << " = ";
            cout<<"\n";
            cin >> grades[i][j];
        }
    }
    Score(grades, average, studNum, quizzsNum);
    return 0;
}
