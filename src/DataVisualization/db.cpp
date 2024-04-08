#include "db.h"

DB::DB() {
    createConnection();
    createTable();
}
bool DB::createConnection() {
    // 添加一个SQLite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库文件的名称
    db.setDatabaseName("data.db");

    // 尝试打开数据库
    if(!db.open()) {
        qDebug() << "Cannot open database: Unable to establish a database connection.";
        return false;
    }

    return true;
}
bool DB::createTable() {
    // 假设数据库连接已经成功建立
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS contacts ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "name TEXT NOT NULL, "
                              "phone TEXT NOT NULL)");

    if(!success) {
        qDebug() << "Cannot create table: " << query.lastError();
        return false;
    }

    return true;
}
