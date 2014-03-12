#include "DBMS.h"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

void DBMS::Insert(char* tablename, char* value1, char* value2, char* value3, char* value4)
{
    char tbmd[MODEL_LEN];
    char type[5][10];
    char value[5][10];
    char ins[INS_LEN];
    int c1, c2;
    int i;
    int typel;
    char* tmp;
    int ins_l;

    if (tb_is_op(tablename))
    {
        Find_table(tablename, tbmd);
        cout << "c";
        c1 = Find_type(tbmd, type);

        cout << "d";
        strcpy(value[0], value1);
        strcpy(value[1], value2);
        strcpy(value[2], value3);
        strcpy(value[3], value4);

        for (i=3; i>=0; i++)
        {
            if (value[i])
            {
                c2 = i+1;
                break;
            }
        }

        if (c1 == c2)
        {
            ins[0] = 0;
            ins_l = 1;
            for (i=0; i<c1; i++)
            {
                typel = calc_len(type[i]);
                tmp = new char(typel);
                make_val(tmp, value[i], typel);
                strcat(ins+ins_l, tmp);
                ins_l += typel;
            }
            write_ins(tablename, ins, ins_l);
        }
        else
            cout << "ERROR: Table Student has been inserted with " << c2 << " column values, it requires exactly " << c1
             << " column values." << endl;
    }
    else
        cout << "ERROR!" << endl;
}
