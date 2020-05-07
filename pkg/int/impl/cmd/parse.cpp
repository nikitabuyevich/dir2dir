#include <cmd/parse.h>
#include <iostream>
#include <tuple>
#include <exception>
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

namespace cmd
{
	Arg Parse(int argc, char** argv)
	{
		bpo::options_description
			desc
			("dir2dir: Copy all files located inside a directory to a different directory."
			 "\nUsage");
		try
		{
			desc.add_options()
				("help,h", "Display usage.")
				("src,s",
					bpo::value<std::string>()->value_name("string"),
					"Source directory to copy files from. Must be a full path.")
				("dst,d",
					bpo::value<std::string>()->value_name("string"),
					"Destination directory to copy contents to. Must be a full path");

			bpo::variables_map vm;
			bpo::store(bpo::parse_command_line(argc, argv, desc), vm);

			if (argc == 1 ||
				vm.count("help") ||
				!(vm.count("src") && vm.count("dst")))
			{
				std::cout << desc;
				std::exit(1);
			}

			return {
				.src = vm["src"].as<std::string>(),
				.dst = vm["dst"].as<std::string>()
			};
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << "\n";
			std::cout << desc;
			std::exit(1);
		}
	}
}

