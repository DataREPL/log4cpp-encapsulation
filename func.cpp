#include "func.h"
#include "Mylog.h"

void func()
{
	LOG_ERROR("hello,world!");
	LOG_ERROR("this is multiply params test: %d, %f", 1, 2.0);
}
