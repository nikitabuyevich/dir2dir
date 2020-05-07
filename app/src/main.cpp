#include <cmd/parse.h>
#include <cp/dir.h>

int main(int argc, char** argv)
{
	const auto arg = cmd::Parse(argc, argv);
	cp::Dir(arg.dst, arg.src);
	return 0;
}
