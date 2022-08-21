#include <iostream>
using namespace std;
#include "workermanager.h"
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"

int main()
{
    // test code area
    // Worker *worker = NULL;
    // worker = new Employee(1, "zhangsan", 10);
    // worker->showinfo();

    // worker = new Manager(1, "huang jingli", 1);
    // worker->showinfo();

    // worker = new Boss(1, "peter huang", 1);
    // worker->showinfo();

    int choice = 0;
    WorkerManager wm;
    while (true)
    {
        wm.Showmenu();
        cout << "please put in your num" << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
            wm.Exitsys();
            break;
        case 1:
            wm.Add_emp();
            break;
        case 2:
            wm.Show_emp();
            break;
        case 3:
            wm.Del_emp();
            break;
        case 4:
            wm.Mod_emp();
            break;
        case 5:
            wm.Find_emp();
            break;
        case 6:
            wm.Sort_emp();
            wm.Show_emp();
            break;
        case 7:
            wm.Clean_file();
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            break;
        }
    }

    system("cls");
};