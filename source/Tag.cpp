#include "../header/Tag.h"

void Tag::setName(const std::string& newName) {
	name = newName;
}

std::string Tag::getTagInfo() const {
	return name;
}

bool Tag::operator==(const Tag& other) const {
	return this->name == other.name;  // 比较 name 字段
}