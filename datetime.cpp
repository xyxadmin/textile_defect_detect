#include "datetime.h"

DateTime::DateTime(QObject *parent)
    : QObject{parent}
{
}

QString DateTime::pareseDateTime(QString dateStr)
{
    QRegularExpressionMatch match = regex.match(dateStr);
    if (!match.hasMatch()) return "-1";

    // 提取捕获组
    QString monthStr = match.captured(1);
    int day = match.captured(2).toInt();
    int hour = match.captured(3).toInt();
    int minute = match.captured(4).toInt();
    int second = match.captured(5).toInt();
    QString ampm = match.captured(6);
    int year = match.captured(7).toInt();

    // 将月份缩写映射为数字
    static QHash<QString, int> monthMap = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    int month = monthMap.value(monthStr, -1);
    if (month == -1) return "-1";

    // 转换12小时制为24小时制
    if (ampm == "PM" && hour != 12) {
        hour += 12;
    } else if (ampm == "AM" && hour == 12) {
        hour = 0;
    }

    // 验证日期和时间有效性
    QDate date(year, month, day);
    QTime time(hour, minute, second);
    if (!date.isValid() || !time.isValid()) return "-1";

    // 返回结果
    result = {year, month, day, hour, minute, second};

    if (result.year != -1) {
        // qDebug() << "解析成功：";
        // qDebug() << "年:" << result.year;
        // qDebug() << "月:" << result.month;
        // qDebug() << "日:" << result.day;
        // qDebug() << "时:" << result.hour;
        // qDebug() << "分:" << result.minute;
        // qDebug() << "秒:" << result.seconds;
        dateResult = QString("%1年%2月%3日 %4时%5分").arg(result.year).arg(result.month).arg(result.day).arg(result.hour).arg(result.minute);
    } else {
        qDebug() << "解析失败";
        return "-1";
    }
    return dateResult;
}
