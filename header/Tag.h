#ifndef TAG_H_
#define TAG_H_

#include <string>

class Tag {
private:
	std::string name;  // 标签名称

public:
	void setName(const std::string& newName);
	std::string getTagInfo() const;
	bool operator==(const Tag& other) const;
};

#endif  // TAG_H_