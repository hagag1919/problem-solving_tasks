#include <iostream>//20216010_Ahmed maher,20216064_Essam alaa
using namespace std;
void calMatMultip(int firstMatrix[][5], int secondMatrix[][5], int mult[][5], int row1, int column1, int row2, int column2)
{
	int i, j, k;
	// Initializing elements of matrix mult to 0.
	for(i = 0; i < row1; ++i)
	{
		for(j = 0; j < column2; ++j)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(i = 0; i < row1; ++i)
	{
		for(j = 0; j < column2; ++j)
		{
			for(k=0; k<column1; ++k)
			{
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}
void checkMatMultip(int column1,int row2,int row1,int column2){
while (column1 != row2)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		cout << "Enter rows and column for first matrix: ";
		cin >> row1 >> column1;
		cout << "Enter rows and column for second matrix: ";
		cin >> row2 >> column2;
	}
}
int main()
{
	int firstMatrix[5][5], secondMatrix[5][5], mult[5][5], row1, column1, row2, column2, i, j;
	cout << "Enter rows and column for first matrix: ";
	cin >> row1 >> column1;
	cout << "Enter rows and column for second matrix: ";
	cin >> row2 >> column2;
// If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
	checkMatMultip( column1, row2, row1, column2);
// take matrices data
        cout << endl << "Enter elements of matrix 1:" << endl;
	for(i = 0; i < row1; ++i)
	{
		for(j = 0; j < column1; ++j)
		{
			cout << "Enter elements a"<< i + 1 << j + 1 << ": ";
			cin >> firstMatrix[i][j];
		}
	}
	cout << endl << "Enter elements of matrix 2:" << endl;
	for(i = 0; i < row2; ++i)
	{
		for(j = 0; j < column2; ++j)
		{
			cout << "Enter elements b" << i + 1 << j + 1 << ": ";
			cin >> secondMatrix[i][j];
		}
	}

// Function to multiply two matrices.
        calMatMultip(firstMatrix, secondMatrix, mult, row1, column1, row2, column2);
//  display resultant matrix after multiplication.
	cout << "Output Matrix:" << endl;
	for(i = 0; i < row1; ++i)
	{
		for(j = 0; j < column2; ++j)
		{
			cout << mult[i][j] << " ";
			if(j == column2 - 1)
				cout << endl << endl;
		}
	}
	return 0;
}
