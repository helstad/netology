#include <fstream>
#include <string>
#include <stdexcept>

class HTMLPrintable
{
public:
	virtual ~HTMLPrintable() = default;
	virtual std::string printAsHTML() const = 0;
};

class TextPrintable
{
public:
	virtual ~TextPrintable() = default;
	virtual std::string printAsText() const = 0;
};

class JSONPrintable
{
public:
	virtual ~JSONPrintable() = default;
	virtual std::string printAsJSON() const = 0;
};

class Data : public HTMLPrintable, public TextPrintable, public JSONPrintable
{
public:
	Data(std::string dataHTML, std::string dataText, std::string dataJSON)
		: m_dataHTML(std::move(dataHTML)), m_dataText(std::move(dataText)), m_dataJSON(std::move(dataJSON)) {}

	std::string printAsHTML() const override
	{
		return m_dataHTML;
	}

	std::string printAsText() const override
	{
		return m_dataText;
	}

	std::string printAsJSON() const override
	{
		return m_dataJSON;
	}

private:
	std::string m_dataHTML;
	std::string m_dataText;
	std::string m_dataJSON;
};

void saveTo(std::ofstream& file, const HTMLPrintable& printable)
{
	file << printable.printAsHTML();
}

void saveTo(std::ofstream& file, const TextPrintable& printable)
{
	file << printable.printAsText();
}

void saveTo(std::ofstream& file, const JSONPrintable& printable)
{
	file << printable.printAsJSON();
}