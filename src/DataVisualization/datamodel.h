#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>

class DataModel : public QObject
{
    Q_OBJECT

public:
    DataModel(QObject *parent = nullptr);
    void loadDataFromFile(const QString &filePath);
    QString getDataAsText() const;

private:
    QVector<QStringList> data;  // 存储解析后的数据


};



#endif // DATAMODEL_H
