#include <iostream>
#include <string>
#include <map>

class VeryHeavyDatabase {
public:
	std::string GetData(const std::string& key) const noexcept {
		return "Very Big Data String: " + key;
	}
};

class OneShotDB : public VeryHeavyDatabase {
public:
	explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1)
		: real_db_(real_object), shots_left_(shots) {}

	std::string GetData(const std::string& key) noexcept {
		if (shots_left_ > 0) {
			--shots_left_;
			return real_db_->GetData(key);
		}
		else {
			return "error";
		}
	}

private:
	VeryHeavyDatabase* real_db_;
	size_t shots_left_;
};

int main() {
	VeryHeavyDatabase real_db;
	OneShotDB limit_db(&real_db, 3);

	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;
	std::cout << limit_db.GetData("key") << std::endl;

	return 0;
}