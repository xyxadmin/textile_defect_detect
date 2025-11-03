#ifndef DATETIME_H
#define DATETIME_H

#include <QObject>
#include <QCoreApplication>
#include <QDateTime>
#include <QRegularExpression>
#include <QHash>
#include <QDebug>

struct DateTimeStruct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
};

class DateTime : public QObject
{
    Q_OBJECT
public:
    explicit DateTime(QObject *parent = nullptr);
    DateTimeStruct result = {-1, -1, -1, -1, -1,-1};
    QRegularExpression regex = QRegularExpression("^\\w+\\s+(\\w+)\\s+(\\d+)\\s+(\\d+):(\\d+):(\\d+)\\s+(AM|PM)\\s+\\w+\\s+(\\d+)$");
    QString dateResult;
public:
    QString pareseDateTime(QString dateStr);

signals:
};

#endif // DATETIME_H
