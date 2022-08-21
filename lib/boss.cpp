#include "boss.h"

Boss::Boss(int id, string name, int did)
{
    this->m_id = id;
    this->m_dept = did;
    this->m_name = name;
};

void Boss::showinfo()
{
    cout << "ID: " << this->m_id << "\t"
         << "Name: " << this->m_name << "\t"
         << "Dept: " << this->m_dept << "\t"
         << "Respon: Manageing all company issues." << endl;
};
string Boss::getdeptname() { return "BOSS!"; };