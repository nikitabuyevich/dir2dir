#ifndef CP_FILE_H_
#define CP_FILE_H_

#include <vector>
#include <string>

// Perform basic operations around copying.
namespace cp
{
	// Copy all files located at a directory to a different directory.
	void Dir(std::string_view dst, std::string_view src);
}

#endif //CP_FILE_H_
