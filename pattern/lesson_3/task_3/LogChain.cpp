#include "LogChain.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

LogMessage::LogMessage(MessageType type, const std::string& message)
    : m_type(type), m_message(message) {}

MessageType LogMessage::type() const {
    return m_type;
}

const std::string& LogMessage::message() const {
    return m_message;
}

void LogHandler::setNextHandler(LogHandler* next) {
    m_nextHandler = next;
}

void LogHandler::handle(const LogMessage& logMessage) {
    if (canHandle(logMessage)) {
        processMessage(logMessage);
    }
    else if (m_nextHandler) {
        m_nextHandler->handle(logMessage);
    }
    else {
        throw std::runtime_error("Unhandled log message: " + logMessage.message());
    }
}

bool FatalErrorHandler::canHandle(const LogMessage& logMessage) const {
    return logMessage.type() == MessageType::FatalError;
}

void FatalErrorHandler::processMessage(const LogMessage& logMessage) {
    throw std::runtime_error("Fatal Error: " + logMessage.message());
}

ErrorHandler::ErrorHandler(const std::string& filePath)
    : m_filePath(filePath) {}

bool ErrorHandler::canHandle(const LogMessage& logMessage) const {
    return logMessage.type() == MessageType::Error;
}

void ErrorHandler::processMessage(const LogMessage& logMessage) {
    std::ofstream outFile(m_filePath, std::ios_base::app);
    if (outFile.is_open()) {
        outFile << "Error: " + logMessage.message() << std::endl;
    }
    else {
        throw std::runtime_error("Unable to open file: " + m_filePath);
    }
}

bool WarningHandler::canHandle(const LogMessage& logMessage) const {
    return logMessage.type() == MessageType::Warning;
}

void WarningHandler::processMessage(const LogMessage& logMessage) {
    std::cout << "Warning: " << logMessage.message() << std::endl;
}

bool UnknownMessageHandler::canHandle(const LogMessage& logMessage) const {
    return logMessage.type() == MessageType::Unknown;
}

void UnknownMessageHandler::processMessage(const LogMessage& logMessage) {
    throw std::runtime_error("Unknown Message: " + logMessage.message());
}
