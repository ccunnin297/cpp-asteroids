#include "Logger.h"

#include <iostream>
#include <string>

std::mutex Logger::s_mutex;

void Logger::log(std::string str)
{
    std::lock_guard<std::mutex> lock(s_mutex);
    std::cout << str << std::endl;
};