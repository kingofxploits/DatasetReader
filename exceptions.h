#ifndef EXEPTIONS_H
#define EXEPTIONS_H
#include <stdexcept>

class FileNotFound : public std::runtime_error {
public:
	FileNotFound() : std::runtime_error{"Incorrect file path!"}{}
};
#endif // !EXEPTIONS_H
