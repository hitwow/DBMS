#include "DBMS.h"

using namespace std;

void DBMS::trans(char* in)
{
    char* ins[6][20];
    char* cre[11][20];
    char* del[6][20];
    char* dip[20];

    if (in[0]=='I')
    {
        get_ins(ins, in);
    }
    else if (in[0]=='C')
        get_cre(cre, in);
    else if (in[0]=='D')
    {
        if (in[1]=='E')
            get_del(del, in);
        else if (in[1]=="I")
            get_dip(dip, in);
    }
    else
        cout << "ERROR! IN TRANS" << endl;
}
