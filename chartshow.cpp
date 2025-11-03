#include "chartshow.h"

ChartShow::ChartShow(QWidget *parent)
    : QWidget{parent}
{
    initChart();
}

void ChartShow::initChart()
{
    chart = new QChart();
    chart->setAnimationDuration(50);
    chart->setAnimationOptions(QChart::AllAnimations);
    series_confidence = new QLineSeries(this);
    series_fps = new QLineSeries(this);
    series_confidence->setName("confidence");
    series_fps->setName("fps");
    chart->addSeries(series_confidence);
    chart->addSeries(series_fps);
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    axisX->setMax(100);
    axisY->setMin(0);
    axisY->setMax(100);
    axisX->setTickCount(8);
    axisY->setTickCount(8);
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);
    axisX->setMinorGridLineVisible(true);
    axisY->setMinorGridLineVisible(true);
    axisX->setMinorTickCount(3);
    axisY->setMinorTickCount(3);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series_confidence->attachAxis(axisX);
    series_confidence->attachAxis(axisY);
    series_fps->attachAxis(axisX);
    series_fps->attachAxis(axisY);
    view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    layout = new QVBoxLayout(this);
    layout->addWidget(view);

}

void ChartShow::updateChart(int confidence, int fps)
{
    static int count = 0;
    if(count > 100){
        series_confidence->remove(0);
        series_fps->remove(0);
        chart->axisX()->setMin(count - 100);
        chart->axisX()->setMax(count+3);
    }
    series_confidence->append(QPointF(count,confidence));
    series_fps->append(QPointF(count,fps));
    count++;
}
