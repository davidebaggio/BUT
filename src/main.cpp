#include "but.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		but_error("Not enough arguments. Type \"help\" for usage");
		return 0;
	}
	if (strcmp(argv[1], "help") == 0)
	{
		but_usage();
	}
	else if (strcmp(argv[1], "config") == 0)
	{
		but_config();
	}
	else if (strcmp(argv[1], "init") == 0)
	{
		but_init();
	}
	else if (strcmp(argv[1], "build") == 0)
	{
		but_build();
	}
	else
	{
		but_error("Unknown aruments. Type \"help\" for USAGE");
		return 0;
	}
}