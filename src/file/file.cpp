#include <file/file.h>

File::File(const std::string& name, const std::string& content)
  : name_(name), content_(content) {

}

const std::string& File::getContent() const {
  return content_;
}

const std::string& File::getName() const {
  return name_;
}