#include <cp/dir.h>
#include <exception>
#include <iostream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

/// allFilesInDir searches and returns all files
/// located in a directory recursively.
std::vector<std::string> allFilesInDir(const std::filesystem::path& dir) {
	std::vector<std::string> files;
	for(const auto& p: std::filesystem::recursive_directory_iterator(dir)) {
		if (!std::filesystem::is_directory(p)) {
			files.push_back(p.path().string());
		}
	}
	return files;
}

void cp::Dir(std::string_view dst, std::string_view src)
{
	try
	{
		// Recursively create target directory if not existing.
		fs::create_directories(dst);

		const auto& files = allFilesInDir(src);
		for (const auto& f : files)
		{
			std::stringstream dirFile;
			fs::path srcFile = f;
			dirFile << dst << "/" << srcFile.filename().string();
			fs::copy_file(f, dirFile.str(), fs::copy_options::overwrite_existing);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::exit(1);
	}
}

