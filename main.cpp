#include "DBMS.h"
#include <string.h>

using namespace std;

int main()
{
    DBMS my_dbms;
    int i;
    /*
    char* in[INPUT_LEN];

    while (1)
    {
        cout << "dbms:";
        gets(in);

        if (in[strlen(in)-2]!=';')
        {
            cout << "error input" << endl;
        }
        else
        {
            trans(in);
        }
    }
    */

    char c1[10] = "student";
    char c2[15] = "1060310707";
    char c3[10] = "Bob";
    char c4[10] = "18";
    char c5[10] = "sid";
    char c6[10] = "CHAR(10)";
    char c7[10] = "name";
    char c8[10] = "CHAR(10)";
    char c9[10] = "age";
    char c10[10] = "INT";

    cout << "a";
    my_dbms.CreateTable(c1, c5, c6, c7, c8, c9, c10);
    cout << "b";
    my_dbms.Insert(c1, c2, c3, c4);

    return 0;
}
