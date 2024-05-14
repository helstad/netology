#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
	void print(const std::string& message) override {
		std::cout << message << "\n";
	}
};

class FileLogCommand : public LogCommand {
public:
	FileLogCommand(const std::string& filePath) : m_filePath(filePath) {}

	void print(const std::string& message) override {
		std::ofstream ofs(m_filePath, std::ios_base::app);
		if (ofs.is_open()) {
			ofs << message << "\n";
		}
		else {
			std::cerr << "Unable to open file: " << m_filePath << "\n";
		}
	}

private:
	std::string m_filePath;
};

static void print(LogCommand& command, const std::string& message) {
	command.print(message);
}

int main() {
	ConsoleLogCommand consoleCommand;
	FileLogCommand fileCommand("log.txt");

	print(consoleCommand, "This is a message to the console.");
	print(consoleCommand, "This is a message to the file.");

	return 0;
}