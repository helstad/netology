#pragma once

#include <string>
#include <exception>

enum class MessageType {
	Warning,
	Error,
	FatalError,
	Unknown
};

class LogMessage {
public:
	LogMessage(MessageType type, const std::string& message);

	MessageType type() const;
	const std::string& message() const;

private:
	MessageType m_type;
	std::string m_message;
};

class LogHandler {
public:
	virtual ~LogHandler() = default;
	void setNextHandler(LogHandler* next);
	virtual void handle(const LogMessage& logMessage);

protected:
	virtual bool canHandle(const LogMessage& logMessage) const = 0;
	virtual void processMessage(const LogMessage& logMessage) = 0;

private:
	LogHandler* m_nextHandler = nullptr;
};

class FatalErrorHandler : public LogHandler {
protected:
	bool canHandle(const LogMessage& logMessage) const override;
	void processMessage(const LogMessage& logMessage) override;
};

class ErrorHandler : public LogHandler {
public:
	ErrorHandler(const std::string& filePath);
protected:
	bool canHandle(const LogMessage& logMessage) const override;
	void processMessage(const LogMessage& logMessage) override;

private:
	std::string m_filePath;
};

class WarningHandler : public LogHandler {
protected:
	bool canHandle(const LogMessage& logMessage) const override;
	void processMessage(const LogMessage& logMessage) override;
};

class UnknownMessageHandler : public LogHandler {
protected:
	bool canHandle(const LogMessage& logMessage) const override;
	void processMessage(const LogMessage& logMessage) override;
};
