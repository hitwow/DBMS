#include "DBMS.h"

using namespace std;

void DBMS::update(char* tableName, char* Col1, char* value1, char* Col2, char* value2)
{
    int p1, p2;
    char* tmp;
    int p;

    if (tb_is_op(tableName))
    {
        p = 0;

        p1 = get_tp_p(tableName, Col1);
        p2 = get_tp_p(tableName, Col2);

        p = Find_up_p(tableName, p1, value1);
        tmp = new char(calc_len(Col2));
        make_val(tmp, value2, calc_len(Col2));
        up_tb(tableName, p2, tmp, p);
    }
    else
        cout << "ERROR! in update" << endl;
}
