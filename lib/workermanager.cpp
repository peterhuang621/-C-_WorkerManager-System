#include "workermanager.h"
#include <stdlib.h>

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "\"the file doesn't exist!!\"" << endl;
        this->m_empnum = 0;
        this->m_emparray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    };
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "\"the file doesn't exist!!\"" << endl;
        this->m_empnum = 0;
        this->m_emparray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    };

    int num = this->get_empnum();
    cout << "total: " << num << " persons" << endl;
    this->m_empnum = num;

    // test code:
    //  this->m_emparray = new Worker *[this->m_empnum];
    //  this->init_emp();
    //  for (int i = 0; i < this->m_empnum; i++)
    //  {
    //      cout << "ID is : " << this->m_emparray[i]->m_id << "\t name is: " << this->m_emparray[i]->m_name << endl;
    //      ;
    //  }
};

void WorkerManager::Showmenu()
{
    cout << "欢迎使用职工管理系统！" << endl;
    cout << "0.退出管理程序" << endl;
    cout << "1.增加职工信息" << endl;
    cout << "2.显示职工信息" << endl;
    cout << "3.删除离职职工" << endl;
    cout << "4.修改职工信息" << endl;
    cout << "5.查找职工信息" << endl;
    cout << "6.按照编号排序" << endl;
    cout << "7.清空所有文档" << endl;
    cout << "*************" << endl;
    cout << endl;
};

void WorkerManager::Add_emp()
{
    cout << "please put in the employees' num: " << endl;
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        int newsize = this->m_empnum + addnum;
        Worker **newspace = new Worker *[newsize];
        if (this->m_emparray != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                newspace[i] = this->m_emparray[i];
            }
        };
        for (int i = 0; i < addnum; i++)
        {
            int id;
            string name;
            int dselect;
            cout << "please put in the " << i + 1 << " employee id: " << endl;
            cin >> id;

            cout << "please put in the " << i + 1 << " employee name: " << endl;
            cin >> name;

            cout << "please set the post: " << endl;
            cout << "1. boss 2. manager 3. employee" << endl;
            cin >> dselect;
            while (dselect != 1 && dselect != 2 && dselect != 3)
            {
                cout << "please assign a num 1-3 again" << endl;
                cin >> dselect;
            };

            Worker *worker = NULL;

            switch (dselect)
            {
            case 1:
                worker = new Boss(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 1);
                break;
            case 3:
                worker = new Employee(id, name, 1);
                break;
            default:
                break;
            };
            newspace[this->m_empnum + i] = worker;
        }

        delete[] this->m_emparray;
        this->m_emparray = newspace;
        this->m_empnum = newsize;
        this->m_fileisempty = false;
        cout << "addin successfully with " << addnum << " persons!" << endl;

        this->Save();
    }
    else
    {
        cout << "wrong input variable" << endl;
    }
    system("pause");
    system("clear");
};

void WorkerManager::Exitsys()
{
    cout << "looking forward to your next coming" << endl;
    exit(0);
};

void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_empnum; i++)
    {
        ofs << this->m_emparray[i]->m_id << "\t"
            << this->m_emparray[i]->m_name << "\t"
            << this->m_emparray[i]->m_dept << "\t" << endl;
    }
};

int WorkerManager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dept;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dept)
    {
        num++;
    }
    return num;
};

WorkerManager::~WorkerManager(){};

void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int deptid;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> deptid)
    {
        Worker *worker = NULL;
        if (deptid == 1)
        {
            worker = new Employee(id, name, deptid);
        }
        else if (deptid == 2)
        {
            worker = new Manager(id, name, deptid);
        }
        else
        {
            worker = new Boss(id, name, deptid);
        };
        this->m_emparray[index] = worker;
        index++;
    };
    ifs.close();
};

void WorkerManager::Show_emp()
{
    if (this->m_fileisempty)
    {
        cout << "file not exist" << endl;
    }
    else
    {
        for (int i = 0; i < m_empnum; i++)
        {
            this->m_emparray[i]->showinfo();
        }
    };
};

void WorkerManager::Del_emp()
{
    if (this->m_fileisempty)
    {
        cout << "file doesn't exist" << endl;
    }
    else
    {
        cout << "please put in the id you'd like to remove" << endl;
        int id = 0;
        cin >> id;
        int index = this->isexist(id);
        if (index != -1)
        {
            for (int i = 0; i < this->m_empnum - 1; i++)
            {
                this->m_emparray[i] = this->m_emparray[i + 1];
            };
            this->m_empnum--;
            this->Save();
            cout << "delet successfully!" << endl;
        }
        else
        {
            cout << "can't find this person with the id" << endl;
        }
    }
};

int WorkerManager::isexist(int id)
{
    int index = -1;
    for (int i = 0; i < m_empnum; i++)
    {
        if (this->m_emparray[i]->m_id == id)
        {
            index = i;
            break;
        };
    };
    return index;
};

void WorkerManager::Mod_emp()
{
    if (this->m_fileisempty)
    {
        cout << "file doesn't exist" << endl;
    }
    else
    {
        cout << "please put in the id: " << endl;
        int id;
        cin >> id;

        int ret = this->isexist(id);
        if (ret != -1)
        {
            // delete this->m_emparray[ret];
            int newid = 0;
            string newname = "";
            int dselect = 0;

            cout << "ID: " << id << " please put in the new employee id: " << endl;
            cin >> newid;
            cout << "please put in the new name: " << endl;
            cin >> newname;

            cout << "please put in the career: " << endl;
            cout << "1. boss 2. manager 3. employee" << endl;
            cin >> dselect;
            Worker *worker = NULL;

            switch (dselect)
            {
            case 1:
                worker = new Boss(newid, newname, dselect);
                break;
            case 2:
                worker = new Manager(newid, newname, dselect);
                break;
            case 3:
                worker = new Employee(newid, newname, dselect);
                break;
            default:
                break;
            };

            this->m_emparray[ret] = worker;
            cout << "modified successfully!!" << this->m_emparray[ret]->m_dept << endl;

            this->Save();
        }
        else
        {
            cout << "can't find this person!" << endl;
        }
    }
};

void WorkerManager::Find_emp()
{
    if (this->m_fileisempty)
    {
        cout << "doesn't exist!" << endl;
    }
    else
    {
        cout << "please put in the way you want to search" << endl;
        cout << "1. by id  |  2. by name" << endl;

        int select = 0;
        cin >> select;
        if (select == 1)
        {
            int id;
            cout << "id you'll search for: " << endl;
            cin >> id;
            int ret = isexist(id);
            if (ret != -1)
            {
                cout << "bingo, the information is :" << endl;
                this->m_emparray[ret]->showinfo();
            }
            else
            {
                cout << "can't find this person" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "please put int the name:" << endl;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < m_empnum; i++)
            {
                if (this->m_emparray[i]->m_name == name)
                {
                    cout << "bingo! the information is for id--" << this->m_emparray[i]->m_id << " , as below:" << endl;
                    this->m_emparray[i]->showinfo();
                    flag = true;
                };
            };
            if (flag == false)
            {
                cout << "can't find this person" << endl;
            };
        }
        else
        {
            cout << "wrong input!" << endl;
        };
    }
};

void WorkerManager::Sort_emp()
{
    if (this->m_fileisempty)
    {
        cout << "file doesn't exist" << endl;
    }
    else
    {
        cout << "please select the sort way:" << endl;
        cout << "1. by ascending order | 2. by descending order" << endl;

        int select = 0;
        cin >> select;
        for (int i = 0; i < m_empnum; i++)
        {
            int minormax = i;
            for (int j = i + 1; j < this->m_empnum; j++)
            {
                if (select == 1)
                {
                    if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)
                    {
                        minormax = j;
                    }
                }
                else
                {
                    if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)
                    {
                        minormax = j;
                    }
                };
            };
            if (i != minormax)
            {
                Worker *temp = this->m_emparray[i];
                this->m_emparray[i] = this->m_emparray[minormax];
                this->m_emparray[minormax] = temp;
            };
        };
    };
    cout << "sort successfully" << endl;
    this->Save();
};

void WorkerManager::Clean_file()
{
    cout << "please CONFIRM that purging the all sys?" << endl;
    cout << "1. Y | 2. N" << endl;
    int select = 0;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_emparray != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                delete this->m_emparray[i];
                this->m_emparray[i] = NULL;
            }
            delete[] this->m_emparray;
            this->m_emparray = NULL;
            this->m_empnum = 0;
            this->m_fileisempty = true;
        }
        cout << "Purge successfully!" << endl;
    }
};
