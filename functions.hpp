#pragma once

#include <stdio.h>
#include <mntent.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

bool txt_extension(char const *name);
bool bin_extension(char const *name);
bool so_extension(char const *name);
bool a_extension(char const *name);

void * thread_func(void * arg);
