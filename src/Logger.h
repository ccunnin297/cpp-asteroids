#pragma once

#include <iostream>
#include <mutex>

class Logger
{
    public:
        static void log(std::string str)
        {
            std::lock_guard<std::mutex> lock(s_mutex);
            std::cout << str << std::endl;
        };
    private:
        static std::mutex s_mutex;
};