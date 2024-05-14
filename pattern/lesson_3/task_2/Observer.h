#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Observable {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);

    void warning(const std::string& message) const;
    void error(const std::string& message) const;
    void fatalError(const std::string& message) const;

private:
    std::vector<Observer*> m_observers;
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override;
};

class ErrorObserver : public Observer {
public:
    ErrorObserver(const std::string& filePath);
    void onError(const std::string& message) override;

private:
    std::string m_filePath;
};

class FatalErrorObserver : public Observer {
public:
    FatalErrorObserver(const std::string& filePath);
    void onFatalError(const std::string& message) override;

private:
    std::string m_filePath;
};