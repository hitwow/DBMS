#include "DBMS.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool DBMS::tb_is_op(char* tablename)
{
    bool flag;
    ifstream tb;
    tb.open(tablename);
    flag = tb.is_open();
    tb.close();

    return flag;
}

void DBMS::Find_table(char* tablename, char* tablemodel)
{
    char buf[BUF_LEN]={0};
    int i, j;

    int dbg;

    ifstream md;
    md.open("model", ios_base::in);
    md.read(buf, BUF_LEN);
    cout << "c1";
    for (i=0; i<BUF_LEN; i++)//读出1000个字符到缓冲数组buf，并依此比较buf的每个字符
    {
        if (buf[i]==';')//如果字符是\0，说明是一条记录的开始，开始比较后几位是不是要用的指令
        {
            if (!memcmp(buf+i+1, tablename, sizeof(tablename)))
                break;
        }
    }
    cout << "c2";
    i++;

    //查看整个指令有多少位并将整条指令复制到tbmd
    j = 0;
    cin >> dbg;
    while (buf+i+j!='\0')
        j++;
    memcpy(tablemodel, buf+i, j+1);
}

void DBMS::Find_name(char* tablemodel, char name[][NAME_LEN])
{
    unsigned int i,j,k;

    for (i=0; i<strlen(tablemodel); i++)
    {
        if (tablemodel[i]=='(')
        {
            j=0;
            while (tablemodel[i+j+1]!=' ')
            {
                name[0][j] = tablemodel[i+j+1];
                j++;
            }
            name[0][j] = '\0';
            break;
        }
    }

    k = 1;
    for (i=0; i<strlen(tablemodel); i++)
    {
        if (tablemodel[i]==',')
        {
            j = 0;
            while (tablemodel[i+j+1]!=' ')
            {
                name[k][j] = tablemodel[i+j+1];
                j++;
            }
            name[k][j] = '\0';
            k++;
        }
    }
}

int DBMS::Find_type(char* tablemodel, char type[][TYPE_LEN])
{
    unsigned int i,j,k;

    k = 0;
    for (i=0; i<strlen(tablemodel); i++)
    {
        if (tablemodel[i]==' ')
        {
            j=0;
            while ((tablemodel[i+j+1]!=',')&&(tablemodel[i+j+1]!='/0'))
            {
                type[k][j] = tablemodel[i+j+1];
                j++;
            }
            type[k][j] = '\0';
            k++;
        }
    }

    return k;
}

void DBMS::make_val(char* tmp, char* value, int typel)
{
    int l;
    int i;

    l = strlen(value);
    strcpy(tmp, value);

    for(i=l; i<typel; i++)
        tmp[i] = '0';
}

void DBMS::write_ins(char* tablename, char* ins, int ins_l)
{
    ofstream i;
    i.open(tablename, ios_base::out|ios_base::app|ios_base::binary);

    i.write(ins, ins_l);
}

int DBMS::calc_len(char* type)
{
    int l;
    int i;
    char num[4];

    if (!strcmp(type, "INT"))
        l = 4;
    else
    {
        if (!memcmp(type, "CHAR", 4))
        {
            i=0;
            while (type[i+5]!=')')
            {
                num[i] = type[i+5];
                i++;
            }
            num[i] = '\0';
        }
        l = atoi(num);
    }

    return l;
}

int DBMS::get_tb_len(char* tablename)
{
    char type[5][10];
    char tbmd[MODEL_LEN];
    int c;
    int len;
    int i;

    ifstream tb;
    tb.open(tablename, ios_base::in);

    if (tb.is_open())
    {
        len = 1;
        Find_table(tablename, tbmd);
        c = Find_type(tbmd, type);

        for (i=0; i<c; i++)
        {
            len += calc_len(type[i]);
        }
    }
    else
    {
        cout << "ERROR! in get_tb_len." << endl;
    }

    return len;
}

int DBMS::get_tp_p(char* tablename, char* type)
{
    char md[MODEL_LEN];
    int i;
    char typetb[5][10];
    int l = 0;
    int t;

    Find_table(tablename, md);
    t = Find_type(md, typetb);
    for (i=0; i<t; i++)
    {
        if (!strcmp(type, typetb[i]))
            break;
        else
            l += calc_len(typetb[i]);
    }

    return l+1;
}

int DBMS::Find_up_p(char* tablename, int p1, char* value)
{
    char buf[BUF_LEN];
    int i;
    int p = 0;
    int tb_l;
    bool flag = 1;

    tb_l = get_tb_len(tablename);
    ifstream up;
    up.open(tablename, ios_base::in);

    i = 0;
    up.read(buf, BUF_LEN);
    while (1)
    {
        if (buf[i+p1]==EOF)
        {
            flag = 0;
            break;
        }
        else if (i+p1 > BUF_LEN)
        {
            i = 0;
            p += BUF_LEN;
            up.read(buf, BUF_LEN);
        }
        else
        {
            if (memcmp(buf+i+p1, value, strlen(value)))
                i += tb_l;
            else
            {
                p += i;
                break;
            }
        }
    }

    if (!flag)
    {
        cout << "ERROR! in find_up_p" << endl;
        exit(1);
    }
    else
        return p;
}

void DBMS::up_tb(char* tablename, int p2, char* value, int p)
{
    ofstream up;
    up.open(tablename, ios_base::out|ios_base::binary);
    up.seekp(p+p2, ios_base::beg);
    up.write(value, sizeof(value));
}
/*
void DBMS::get_cre(char cre[][20], char* s)
{
    int i;
    int c;

    for (i=0; i<strlen(s); i++)
    {
        c =
    }

}
*/
