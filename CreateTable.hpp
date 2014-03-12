#include <fstream>
#include <string.h>
#include "DBMS.h"

using namespace std;

void DBMS::CreateTable(char* tableName, char* Col1, char* type1, char* Col2, char* type2,
                char* Col3, char* type3, char* Col4, char* type4)
{
    char tmp[MODEL_LEN] = ";";
    strcat(tmp, tableName);
    strcat(tmp, ":");
    strcat(tmp, Col1);
    strcat(tmp, " ");
    strcat(tmp, type1);

    ofstream fout("model", ios_base::out|ios_base::app|ios_base::binary);
    if (Col2)
    {
        strcat(tmp, ",");
        strcat(tmp, Col2);
        strcat(tmp, " ");
        strcat(tmp, type2);
    }
    if (Col3)
    {
        strcat(tmp, ",");
        strcat(tmp, Col3);
        strcat(tmp, " ");
        strcat(tmp, type3);
    }
    if (Col4)
    {
        strcat(tmp, ",");
        strcat(tmp, Col4);
        strcat(tmp, " ");
        strcat(tmp, type4);
    }
    fout.write(tmp, strlen(tmp));
    fout.close();

    ofstream fc;
    fc.open(tableName);
    fc.close();
}
