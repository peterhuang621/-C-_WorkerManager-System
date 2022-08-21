#pragma once
#include <iostream>
using namespace std;
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empfile.t"

class WorkerManager
{
public:
    WorkerManager();
    void Showmenu();
    void Exitsys();
    int m_empnum;
    Worker **m_emparray;
    void Add_emp();
    void Save();
    bool m_fileisempty;
    void init_emp();
    int get_empnum();
    void Show_emp();
    void Del_emp();
    int isexist(int id);
    void Mod_emp();
    void Find_emp();
    void Sort_emp();
    void Clean_file();
    ~WorkerManager();
};