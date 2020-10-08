#pragma once

#include <stdio.h>
#include <mntent.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <thread>
#include <mutex>

using namespace std;

bool txt_extension(char const *name);
bool bin_extension(char const *name);
bool so_extension(char const *name);
bool a_extension(char const *name);

void statistic_function(struct mntent * m);
void analyser_func();
