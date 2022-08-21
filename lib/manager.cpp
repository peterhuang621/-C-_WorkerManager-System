#include "manager.h"

Manager::Manager(int id, string name, int did)
{
    this->m_id = id;
    this->m_dept = did;
    this->m_name = name;
};

void Manager::showinfo()
{
    cout << "ID: " << this->m_id << "\t"
         << "Name: " << this->m_name << "\t"
         << "Dept: " << this->m_dept << "\t"
         << "Respon: Assign a job each worker to achieve the boss's needs." << endl;
};
string Manager::getdeptname() { return "A senior manager."; };