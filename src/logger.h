#ifndef LOGGER_H
#define LOGGER_H

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void logInt(const char* tag, int data);

void logInfo(const char* info);

#endif
