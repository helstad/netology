#include <string>
#include <iostream>
#include <memory>

class Text {
public:
	virtual void render() const = 0;
};

class ConcreteText : public Text {
public:
	explicit ConcreteText(const std::string& data) : data_(data) {}
	void render() const override {
		std::cout << data_;
	}

private:
	std::string data_;
};

class DecoratedText : public Text {
public:
	explicit DecoratedText(std::unique_ptr<Text> text) : text_(std::move(text)) {}
	void render() const override {
		if (text_) {
			text_->render();
		}
	}

protected:
	std::unique_ptr<Text> text_;
};

class ItalicText : public DecoratedText {
public:
	explicit ItalicText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
	void render() const override {
		std::cout << "<i>";
		text_->render();
		std::cout << "</i>";
	}
};

class BoldText : public DecoratedText {
public:
	explicit BoldText(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
	void render() const override {
		std::cout << "<b>";
		text_->render();
		std::cout << "</b>";
	}
};

class Paragraph : public DecoratedText {
public:
	explicit Paragraph(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
	void render() const override {
		std::cout << "<p>";
		text_->render();
		std::cout << "</p>";
	}
};

class Reversed : public DecoratedText {
public:
	explicit Reversed(std::unique_ptr<Text> text) : DecoratedText(std::move(text)) {}
	void render() const override {
		std::string data;
		text_->render();
		std::reverse(data.begin(), data.end());
		std::cout << data;
	}
};

class Link : public DecoratedText {
public:
	explicit Link(std::unique_ptr<Text> text, const std::string& url)
		: DecoratedText(std::move(text)), url_(url) {}
	void render() const override {
		std::cout << "<a href=\"" << url_ << "\">";
		DecoratedText::render();
		std::cout << "</a>";
	}

private:
	std::string url_;
};

int main() {
	std::unique_ptr<Text> text_block =
		std::make_unique<Link>(
			std::make_unique<Reversed>(
				std::make_unique<Paragraph>(
					std::make_unique<ItalicText>(
						std::make_unique<BoldText>(
							std::make_unique<ConcreteText>("Hello world")
						)
					)
				)
			),
			"https://netology.ru"
		);
	text_block->render();

	return 0;
}