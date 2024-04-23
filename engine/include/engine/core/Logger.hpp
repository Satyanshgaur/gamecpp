#pragma once
#include <string>
#include <iostream>

namespace Engine::Core {

enum class LogLevel { Info, Warning, Error, Debug };

class Logger {
public:
    static void Log(LogLevel level, const std::string& message);
    static void Info(const std::string& msg) { Log(LogLevel::Info, msg); }
    static void Warn(const std::string& msg) { Log(LogLevel::Warning, msg); }
    static void Error(const std::string& msg) { Log(LogLevel::Error, msg); }
    static void Debug(const std::string& msg) { Log(LogLevel::Debug, msg); }
};

}
