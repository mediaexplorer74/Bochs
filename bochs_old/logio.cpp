#include "pch.h"
#include "logio.h"

logfunctions::logfunctions(void)
{
}

logfunctions::logfunctions(iofunctions*)
{
}

logfunctions::~logfunctions(void)
{
}

void logfunctions::fatal(int level, const char* prefix, const char* fmt, va_list ap, int exit_status)
{
}

void logfunctions::warn(int level, const char* prefix, const char* fmt, va_list ap)
{
}

void logfunctions::ask(int level, const char* prefix, const char* fmt, va_list ap)
{
}

void logfunctions::put(const char* p)
{
}

void logfunctions::put(const char* n, const char* p)
{
}

void logfunctions::setio(iofunctions*)
{
}
