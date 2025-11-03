#include "shellcontroller.h"

ShellController::ShellController(QObject *parent)
    : QObject{parent}
{}

void ShellController::setCommand(std::string m_command)
{
    this->command = m_command;
}

std::string ShellController::getResult()
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        std::cerr << "popen failed!" << std::endl;
        return "NULL";
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    //pipe.reset(pipe.get()); // 正常结束时关闭管道
    //std::cout << result << std::endl; // 输出结果
    return result;
}
