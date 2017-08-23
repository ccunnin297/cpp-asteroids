#pragma once

#include <iostream>
#include <mutex>

class Logger
{
    public:
        static void log(std::string str);
    private:
        static std::mutex s_mutex;
};