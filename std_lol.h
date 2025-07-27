#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>

void intro();
int judge();

#define printf(...) AI_printf(__VA_ARGS__)
int AI_printf(const char *format, ...);
