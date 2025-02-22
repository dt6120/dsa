#include <bits/stdc++.h>

using namespace std;

enum LogLevel
{
    INFO,
    DEBUG,
    ERROR
};

class LogProcessor
{
private:
    LogLevel level;
    LogProcessor *nextLogProcessor;

public:
    LogProcessor(LogLevel level, LogProcessor *next)
    {
        this->level = level;
        nextLogProcessor = next;
    }

    virtual void log(LogLevel level, string message)
    {
        if (level == this->level)
        {
            cout << "{ level: " << level << ", message: " << message << " }" << endl;
        }
        else if (nextLogProcessor != nullptr)
        {
            nextLogProcessor->log(level, message);
        }
        else
        {
            cout << "Reached the end of chain of responsibility" << endl;
        }
    }

    LogLevel getLevel() {
        return level;
    }
};

class InfoLogProcessor : public LogProcessor
{
public:
    InfoLogProcessor(LogProcessor *next) : LogProcessor(INFO, next) {}

    // void log(LogLevel level, string message) override
    // {
    //     log(level, message);
    // }
};

class DebugLogProcessor : public LogProcessor
{
public:
    DebugLogProcessor(LogProcessor *next) : LogProcessor(DEBUG, next) {}

    // void log(LogLevel level, string message) override
    // {
    //     log(level, message);
    // }
};

class ErrorLogProcessor : public LogProcessor
{
public:
    ErrorLogProcessor(LogProcessor *next) : LogProcessor(ERROR, next) {}

    void log(LogLevel level, string message) override
    {
        if (level == getLevel())
        {
            cout << "CRITICAL: " << message << " !!!" << endl;
        }
        else
        {
            cout << "Reached the end, can't handle log request" << endl;
        }
    }
};

class Logger
{
private:
    LogProcessor *logProcessor;

public:
    Logger()
    {
        logProcessor = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(nullptr)));
    }

    void log(LogLevel level, string message)
    {
        logProcessor->log(level, message);
    }
};

int main()
{
    Logger *logger = new Logger();
    logger->log(INFO, "info");
    logger->log(DEBUG, "debug");
    logger->log(ERROR, "error");
}

/*

Design Pattern
- Chain of Responsibilty
    - Commonly used in ATM/vending machines/logging systems
    - Applied when there is a client/sender who sends a request which no specific receiver
    - All receivers check sequentially if they can execute request
    - If no, request is passed ahead along the chain of responsibility
    - If yes, request is handled and chain is stopped

    - There is abstract handler and concrete handler
    - Concrete handler inherits abstract handler and defines its own implementation
    - Concrete handler also has the link to its next handler

Entities
- LogProcessor
- Logger

Inheritance
- InfoLogProcessor is LogProcessor
- DebugLogProcessor is LogProcessor
- ErrorLogProcessor is LogProcessor

Relations
- Logger has LogProcessor

*/
