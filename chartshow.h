#ifndef CHARTSHOW_H
#define CHARTSHOW_H

#include <QWidget>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QtCharts>

class ChartShow : public QWidget
{
    Q_OBJECT
public:
    explicit ChartShow(QWidget *parent = nullptr);

signals:
private:
    void initChart();
public:
    void updateChart(int confidence,int fps);
private:
    QChart* chart;
    QLineSeries* series_confidence;
    QLineSeries* series_fps;
    QChartView* view;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QVBoxLayout *layout;
};

#endif // CHARTSHOW_H
