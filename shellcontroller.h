#ifndef SHELLCONTROLLER_H
#define SHELLCONTROLLER_H

#include <QObject>

#include <cstdio>
#include <iostream>
#include <memory>
#include <array>
#include <string>

class ShellController : public QObject
{
    Q_OBJECT
public:
    explicit ShellController(QObject *parent = nullptr);
private:
     std::string command = "ls";
public:
     void setCommand(std::string m_command);
     std::string getResult();

signals:
};

#endif // SHELLCONTROLLER_H
