#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DB {
  public:
    DB();
  private:
    bool createConnection();
    bool createTable();
};

#endif // DB_H
