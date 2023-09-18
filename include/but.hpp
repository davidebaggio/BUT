#ifndef BUT_H
#define BUT_H

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>

void but_init();
void but_exec_command(std::string cmd);
void but_build();
void but_error(std::string error);
void but_info(std::string info);
void but_usage();
void but_config();

#endif