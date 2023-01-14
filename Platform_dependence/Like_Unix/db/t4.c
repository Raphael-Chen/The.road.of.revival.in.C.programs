#include "apue.h"
#include "apue_db.h"
#include <fcntl.h>

// Chapter 20. A Database Library
// Figure 20.3 Create a database and write three records to it

int main(void)
{
    DBHANDLE db;
    
    db = db_open("db4", O_RDWR | O_CREAT | O_TRUNC,
                 FILE_MODE);
    if ( NULL == db )
        err_sys("db_open error");

    if (db_store(db, "Alpha", "data1", DB_INSERT) != 0)
        err_quit("db_store error for alpha");

    if (db_store(db, "beta", "Data for beta", DB_INSERT) != 0)
        err_quit("db_store error for beta");
        
    if (db_store(db, "gamma", "record3", DB_INSERT) != 0)
        err_quit("db_store error for gamma");

    db_close(db);
    exit(0);
}
