#include "DBMS.h"

using namespace std;

void DBMS::del(char* tableName, char* Col, char* value)
{
    int p;
    int p1;

    if (tb_is_op(tableName))
    {
        p1 = get_tp_p(tableName, Col);
        p = Find_up_p(tableName, p1, value);
        ofstream dl;
        dl.open(tableName, ios_base::out|ios_base::binary);
        dl.seekp(p, ios_base::beg);
        dl.put('1');
    }
    else
        cout << "ERROR! in del" << endl;
}
