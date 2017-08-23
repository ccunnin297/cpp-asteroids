#include "Logger.h"

std::mutex Logger::s_mutex;

void Logger::log(std::string str)
{
    std::lock_guard<std::mutex> lock(s_mutex);
    std::cout << str << std::endl;
};