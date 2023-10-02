#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
public:
	string link;
	Node *next;
};

class Stack
{
private:
	Node *TOP;

public:
	Stack()
	{
		TOP = NULL;
	}
	bool checkEmpty()
	{
		if (TOP == NULL)
			return true;
		else
			return false;
	}
	Node *getTop()
	{
		return TOP;
	}
	void push(string link)
	{
		Node *newNode = new Node();
		newNode->link = link;
		newNode->next = TOP;
		TOP = newNode;
	}

	void pop()
	{
		if (checkEmpty())
		{
			cout << " * " << endl;
		return;	}
		string link = TOP->link;
		Node *temp = TOP;
		TOP = TOP->next;
		delete temp;
	}

	string top()
	{
		if (checkEmpty())
		{
			cout << " * " << endl;
			return "";
		}
		return TOP->link;
	}
};

int main()
{
	Stack backward, forward;
	int size;
	string webPage, CurrentPage,choice;
	string CurrentChose[10] = {"First ", "Second ", "Third ", "Fourth ", "Fifth ", "Sixth ", "Seventh ", "Eighth ", "Ninth ", "Tenth"};
	ifstream Llink("URLs.txt");
	if (!Llink)
	{
		cout << "Error : could not open file " << endl;
	}
	else
	{
		Llink >> size;
		for (int k = 0; k < size; k++)
		{
			Llink >> webPage;
			backward.push(webPage);
		}
	}
	cout << "The current page is :";
	CurrentPage = backward.top();
	cout << CurrentPage << endl<<endl;
	backward.pop();
	int i = 0;
	while (Llink >> choice)
	{
		transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c) { return toupper(c); });
		if (backward.checkEmpty())
		{
			cout << "No more pages to go forward" << endl;
		}
		else if (choice == "FORWARD")
		{
			backward.push(CurrentPage);
			CurrentPage = forward.top();
			forward.pop();
		}
		else if (choice == "BACKWARD")
		{
			forward.push(CurrentPage);
			CurrentPage = backward.top();
			backward.pop();
		}
		cout << CurrentChose[i] << " choice [" << choice << "]" << endl;
		cout << "The current page is :" << CurrentPage << endl;
		cout << "The next page is :" << forward.top() << endl;
		cout << "The previous page is :" << backward.top() << endl<<endl;
		i++;
	}
	Llink.close();
	return 0;
}
