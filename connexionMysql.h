#ifndef CONNEXIONMYSQL_H
#define CONNEXIONMYSQL_H

#include "QSqlDatabase"
#include "QSqlQuery"

static bool vraiconnexionBD()
{
    QSqlDatabase conn= QSqlDatabase::addDatabase("QMYSQL");
    conn.setHostName("127.0.0.1");
    conn.setUserName("root");
    conn.setDatabaseName("etudbd");
    conn.setPort(3306);

    if(conn.open()){
        return true ;
    }else{
        return false;
    }
}


#endif // CONNEXIONMYSQL_H
