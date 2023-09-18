#include "but.hpp"

void but_exec_command(std::string cmd)
{
	std::cout << "[EXEC]: " + cmd + "\n";
	system(cmd.c_str());
}

void but_error(std::string error)
{
	std::cout << "[ERROR]: " + error + "\n";
}

void but_info(std::string info)
{
	std::cout << "[INFO]: " + info + "\n";
}

void but_usage()
{
	std::cout << "[USAGE]: but <command>\n Commands: \n\tconfig\t to configure building recipe;\n\tinit\t to initialize the project;\n\tbuild\t to build the project;\n\thelp\t to get usage informations\n";
}

void but_init()
{
	but_exec_command("mkdir build");
	but_exec_command("mkdir src");
	but_exec_command("mkdir include");

	std::ofstream config;
	config.open("config.txt");
	config << "include=\nsrc=\nbuild=\nlinking=";
	config.close();
	but_info("Type \"but config\" to configure the building recipe otherwise the building tool uses default compilation options");
}

void but_config()
{
	std::string args[4];
	but_info("Modify those fields, otherwise skip by pressing enter");
	std::cout << "Include path: ";
	getline(std::cin, args[0]);
	std::cout << "Source path: ";
	getline(std::cin, args[1]);
	std::cout << "Build path: ";
	getline(std::cin, args[2]);
	std::cout << "linking libs: ";
	getline(std::cin, args[3]);

	std::ofstream config;
	config.open("config.txt");
	if (!config.is_open())
	{
		but_error("Could not open config.txt; did you initialize the project?");
		return;
	}
	/* for (size_t i = 0; i < 4; i++)
	{
		but_info(args[i]);
	} */

	config << "include=" + args[0] + "\nsrc=" + args[1] + "\nbuild=" + args[2] + "\nlinking=" + args[3];
	config.close();
}

void but_build()
{
	std::string args[4];
	std::string line, word;
	std::ifstream config;
	config.open("config.txt");
	if (!config.is_open())
	{
		but_error("Could not open \"config.txt\"; did you initialize the project?");
		return;
	}
	int i = 0, j = 0;
	while (getline(config, line))
	{
		i = 0;
		std::stringstream str(line);
		while (getline(str, word, '='))
		{
			if (i == 1)
				args[j] = word;
			i++;
		}
		j++;
	}
	/* for (size_t i = 0; i < 4; i++)
	{
		but_info(args[i]);
	} */
	config.close();
	std::string inc = (strcmp(args[0].c_str(), "") != 0 ? args[0] : "./include");
	std::string src = (strcmp(args[1].c_str(), "") != 0 ? args[1] : "./src/");
	std::string build = (strcmp(args[2].c_str(), "") != 0 ? args[2] : "./build/");
	std::string link = (strcmp(args[3].c_str(), "") != 0 ? args[3] : "");
	std::string cmd = "g++ -I" + inc + " -o " + build + "main " + src + "*.cpp " + link;
	but_exec_command(cmd);
}