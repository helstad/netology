#include <fstream>
#include <string>
#include <memory>

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

class DataHTML : public HTMLPrintable
{
public:
    DataHTML(std::string data) : m_data(std::move(data)) {}

    std::string printAsHTML() const override
    {
        return "<html>" + m_data + "</html>\n";
    }

private:
    std::string m_data;
};

class DataText : public TextPrintable
{
public:
    DataText(std::string data) : m_data(std::move(data)) {}

    std::string printAsText() const override
    {
        return m_data + "\n";
    }

private:
    std::string m_data;
};

class DataJSON : public JSONPrintable
{
public:
    DataJSON(std::string data) : data_(std::move(data)) {}

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}\n";
    }

private:
    std::string data_;
};

template<typename PrintableFormat>
void saveTo(std::ofstream& file, const PrintableFormat& printable)
{
    file << printable.print();
}

static void saveToHTML(std::ofstream& file, const HTMLPrintable& printable)
{
    file << printable.printAsHTML();
}

static void saveToText(std::ofstream& file, const TextPrintable& printable)
{
    file << printable.printAsText();
}

static void saveToJSON(std::ofstream& file, const JSONPrintable& printable)
{
    file << printable.printAsJSON();
}

int main()
{
    std::ofstream ofs("output.txt");

    std::unique_ptr<HTMLPrintable> htmlData = std::make_unique<DataHTML>("Hello, HTML!");
    std::unique_ptr<TextPrintable> textData = std::make_unique<DataText>("Hello, Text!");
    std::unique_ptr<JSONPrintable> jsonData = std::make_unique<DataJSON>("Hello, JSON!");

    saveToHTML(ofs, *htmlData);
    saveToText(ofs, *textData);
    saveToJSON(ofs, *jsonData);

    ofs.close();

    return 0;
}
