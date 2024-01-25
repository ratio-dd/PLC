#include "datamodel.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

DataModel::DataModel(QObject *parent) : QObject(parent)
{

};

void DataModel::loadDataFromFile(const QString &filePath){
    QFile file(filePath);

    // 尝试打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading: " << file.errorString();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(','); // 使用逗号分隔行中的每个字段
        data.append(fields);
    }

    file.close();
}

QString DataModel::getDataAsText() const {
    QString text;
    for (const QStringList &row : data) {
        text += row.join(", ") + "\n";
    }
    return text;
}
