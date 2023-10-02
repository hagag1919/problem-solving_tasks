#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node
{
public:
    string data;
    Node* next;

    Node(string value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty()
    {
        return front == nullptr && rear == nullptr;
    }

    void enqueue(string item)
    {
        Node* new_node = new Node(item);

        if (is_empty())
        {
            front = new_node;
            rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            delete front;
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    string get_front()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
        }

        return front->data;
    }

    string get_rear()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
        }

        return rear->data;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        while (temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }

    }
};

void readRecoredFromFile(string FileName)
{
    Queue q;
    string line;
    int Executed;
    int houres,minutes;
    int  executiontime;
    char colon;
    ifstream infile(FileName);
    if (!infile)
    {
        cout << "Error: Could not open file" << endl;
    }
    if (infile.is_open())
    {
        infile>>Executed;
        int Allhoures[Executed];
        int Allminutes[Executed];
        int Allexecutiontime[Executed];
        int AllTime[Executed];
        string recordRow[Executed];
        int count = 0;
        while (infile>>line>>houres>>colon>>minutes>>executiontime)
        {

            Allhoures[count] = houres;
            Allminutes[count] = minutes;
            AllTime[count] =(houres -9)*60 + minutes;
            Allexecutiontime[count] = executiontime;
            recordRow[count] = line +" "+ to_string(houres) + colon + to_string(minutes) + " " + to_string(executiontime);
            count++;

        }
        infile.close();
        for (int i = 0; i < Executed - 1; i++)
        {
            for (int j = 0; j < Executed - i - 1; j++)
            {
                if (AllTime[j] > AllTime[j + 1]||AllTime[j]==AllTime[j+1]&&Allexecutiontime[j]>Allexecutiontime[j+1])
                {
                    swap(AllTime[j], AllTime[j + 1]);
                    swap(Allexecutiontime[j], Allexecutiontime[j + 1]);
                    swap(recordRow[j], recordRow[j + 1]);
                    swap(Allhoures[j], Allhoures[j + 1]);
                    swap(Allminutes[j], Allminutes[j + 1]);
                }
            }
        }
        float AverageWaitingTime = 0.0;
        int occupied = 0;
        int witingtime[Executed];
        for(int i=0; i<Executed; i++)
        {
            q.enqueue(recordRow[i]);
            occupied+=Allexecutiontime[i];

        }
        witingtime[0]=0;

        for(int i=1; i<Executed; i++)
        {
            if(Allhoures[i]==Allhoures[i-1]&&Allminutes[i]<Allminutes[i-1]+Allexecutiontime[i-1])
            {
                witingtime[i] = Allminutes[i-1]+Allexecutiontime[i-1] - Allminutes[i];
                Allminutes[i]=Allminutes[i-1]+Allexecutiontime[i-1];
                AverageWaitingTime+=witingtime[i];

            }
            else
            {
                witingtime[i]=0;
            }

        }
        cout << "Jobs Executed: " << Executed << endl;
        for(int i=0; i<Executed; i++)
        {
            cout<<q.get_front()<<"\texecuted at "<<Allhoures[i]<<":"<<Allminutes[i]<<"\twaiting time: "<<witingtime[i]<<endl;
            q.dequeue();
        }
        cout<<"\nThe printer was occupied for "<<occupied<<" minutes"<<endl;
        cout<<"Average waiting time: "<<AverageWaitingTime/Executed<<endl;
    }
}

int main()
{
    readRecoredFromFile("Printer.txt");
    return 0;
}



