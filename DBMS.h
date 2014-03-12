#ifndef DBMS_H
#define DBMS_H

#define MODEL_LEN 100
#define BUF_LEN 1000
#define NAME_LEN 20
#define TYPE_LEN 10
#define INS_LEN 500
#define S_BUF_LEN 100
#define INPUT_LEN 100

#include <iostream>

using namespace std;

class DBMS
{
public:
    void trans();//翻译输入的命令并转到相应的函数中
    void CreateTable(char* tableName, char* Col1, char* type1, char* Col2 = NULL, char* type2 = NULL,
                     char* Col3 = NULL, char* type3 = NULL, char* Col4 = NULL, char* type4 = NULL);//创建关系
    void Insert(char* tablename, char* value1, char* value2=NULL, char* value3=NULL, char* value4=NULL);//向关系中插入元组
    void del(char* tableName, char* Col, char* value);//从关系中删除元组
    void update(char* tableName, char* Col1, char* value1, char* Col2, char* value2);//更改元组信息
    void select();//查询操作
    void display();//打印指定表文件的所有信息
    void describe();//打印model文件中输入表名的信息
    void Equi_Join();//等值连接
    void Projection();//投影操作
    void Find_table(char* tablename, char* tablemodel);
    void Find_name(char* tablemodel, char name[][NAME_LEN]);
    int Find_type(char* tablemodel, char type[][TYPE_LEN]);
    int calc_len(char* type);
    bool tb_is_op(char* tablename);
    void make_val(char* tmp, char* value, int typel);
    void write_ins(char* tablename, char* ins, int ins_l);
    int get_tb_len(char* tablename);
    int get_tp_p(char* tablename, char* type);
    int Find_up_p(char* tablename, int p1, char* value);
    void up_tb(char* tablename, int p2, char* value, int p);
    /*
    void get_ins(char ins[][20], char* s);
    void get_del(char del[][20], char* s);
    void get_dip(char* &dip, char* s);
    void get_cre(char cre[][20], char* s);
    */
};

#include "CreateTable.hpp"
#include "insert.hpp"
#include "update.hpp"
#include "delete.hpp"
//#include "trans.hpp"
#include "other.hpp"

#endif
