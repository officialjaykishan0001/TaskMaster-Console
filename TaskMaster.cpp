/* Description :
| * Give Description to This Program .
| * PROGRAMMER : Jay Kishan Kharwar.
| * DATE & TIME : 01-11-23 & 12:44 PM.
*/

// Required Header Files.
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Class Starts Here & named as To_Do_List.
class To_Do_List
{
public:
    vector<string> Tasks; // Data Stucture Declaration, required for Storing Tasks (Publicy Available Throughout class)
    vector<bool> Status;
    // this funciton stands for the command "add"
    void add(string task)
    {
        // Adding task in to Data structure.
        this->Tasks.push_back(task);
        this->Status.push_back(0);
        cout << endl;
        return;
    }

    // This Function Stands for removing Particular Task from List.
    void remove(string TaskToBeRemove)
    {
        // Condition evaluate if  Data Structure is empty.
        if (this->Tasks.size() == 0)
        {
            cout << " \"No, tasks are added right now.\" " << endl;
            cout << endl;
            return;
        }

        // Flag set to true, this will Rquire further.
        bool flag = true;

        // Searching for Task that need to be Removed.
        for (int i = 0; i < this->Tasks.size(); i++)
        {
            // Condition evaluate if Task(that need to be  Removed) is Present in Data Strucuture.
            if (this->Tasks[i] == TaskToBeRemove)
            {
                flag = false;                               // Updating Flag.
                this->Tasks.erase(this->Tasks.begin() + i); // Removing Task from DATA STRUCTURE.
                this->Status.erase(this->Status.begin() + i);
                break;
            }
        }

        // Condition Evaluates if Flag is True.
        if (flag)
            cout << "NO, such Task found .." << endl;

        cout << endl; // New Line.
        return;
    }

    // This function stands for the commands "view"
    void view()
    {
        // Condition Evaluates if DATA STRUCTURE is Empty.
        if (this->Tasks.size() == 0)
        {
            cout << "No, Tasks presented in \"To Do List\" yet.";
            cout << endl
                 << endl;
            return;
        }

        // Printing Status of all Tasks.
        cout << "Serial No.        Tasks" << endl;
        cout << "----------       --------  " << endl;
        for (int i = 0; i < this->Tasks.size(); i++)
        {
            cout << "  " << i + 1 << ".              " << this->Tasks[i] << " (" << ((this->Status[i] == 1) ? "*Completed" : "*Incomplete") << ") " << endl;
        }
        cout << endl;

        // Below Code for Marking Incomplete Task to Complete Task.
        string Input;
        cout << " --> Mark Task As Completed [Yes/No] : ";
        cin >> Input;

        if (Input == "yes" or Input == "Yes" or Input == "YES")
        {
            int Sr_No;
            cout << " --> Enter Task's Serial No : ";
            cin >> Sr_No;

            if (Sr_No <= this->Status.size() and Sr_No > 0)
            {
                this->Status[Sr_No - 1] = 1;
                cout << " --> Proccess Done. !\n";
            }
            else
            {
                cout << " --> Invalid Serial No !! \n";
            }
        }

        cout << endl;
        return;
    }

    // This function stands for the command "help".
    void help()
    {

        cout << "COMMANDS                           WORKING" << endl;
        cout << "---------                         ------" << endl;
        cout << "add                      Asemble of new task" << endl;
        cout << "remove                   Resemble of task   " << endl;
        cout << "view                     To do list veiw" << endl;
        cout << "exit                     For exiting to the terminal" << endl;

        cout << endl;

        return;
    }
};

// This Function Stands for Controlling the Process b/w User and Computer.
void controller()
{
    //'list' Declared as To_Do_List class.
    To_Do_List list;

    // Loop for Repetition.
    while (1)
    {
        // Taking input of User's Entered Commands.
        string UserPromts;
        cout << "terminal :\\> to do list >> ";
        cin >> UserPromts;

        // Condition Evaluates if User's given Command is 'add'
        if (UserPromts == "add")
        {
            string task;
            cout << "Enter Task : ";
            cin >> task;

            list.add(task);
        }

        // Condition Evaluates if User's given Command is 'add'
        else if (UserPromts == "remove")
        {
            string TaskToBeRemove;
            cout << "Enter Task Name : ";
            cin >> TaskToBeRemove;

            list.remove(TaskToBeRemove);
        }

        // Condition Evaluates if User's given Command is 'add'
        else if (UserPromts == "view")
        {
            list.view();
        }

        // Condition Evaluates if User's given Command is 'add'
        else if (UserPromts == "help")
        {
            list.help();
        }

        // Condition Evaluates if User's given Command is 'add'
        else if (UserPromts == "exit")
        {
            cout << "LogOut()" << endl;
            break;
        }

        // Condition Evaluates if User's given Command is 'add'
        else
        {
            cout << "No Command Found !! \n\n";
        }
    }
    return;
}

int main()
{
    // Calling The controller Function.
    controller();
    return 0;
}