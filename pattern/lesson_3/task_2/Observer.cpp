#include "Observer.h"

void Observable::addObserver(Observer* observer) {
    m_observers.push_back(observer);
}

void Observable::removeObserver(Observer* observer) {
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
}

void Observable::warning(const std::string& message) const {
    for (Observer* observer : m_observers) {
        if (observer) {
            observer->onWarning(message);
        }
    }
}

void Observable::error(const std::string& message) const {
    for (Observer* observer : m_observers) {
        if (observer) {
            observer->onError(message);
        }
    }
}

void Observable::fatalError(const std::string& message) const {
    for (Observer* observer : m_observers) {
        if (observer) {
            observer->onFatalError(message);
        }
    }
}

void WarningObserver::onWarning(const std::string& message) {
    std::cout << "Warning: " << message << std::endl;
}

ErrorObserver::ErrorObserver(const std::string& filePath)
    : m_filePath(filePath) {}

void ErrorObserver::onError(const std::string& message) {
    std::ofstream outFile(m_filePath, std::ios_base::app);
    if (outFile.is_open()) {
        outFile << "Error: " << message << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << m_filePath << std::endl;
    }
}

FatalErrorObserver::FatalErrorObserver(const std::string& filePath)
    : m_filePath(filePath) {}

void FatalErrorObserver::onFatalError(const std::string& message) {
    std::cout << "Fatal Error: " << message << std::endl;
    std::ofstream outFile(m_filePath, std::ios_base::app);
    if (outFile.is_open()) {
        outFile << "Fatal Error: " << message << std::endl;
    }
    else {
        std::cerr << "Unable to open file: " << m_filePath << std::endl;
    }
}