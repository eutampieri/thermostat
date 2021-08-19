#include "portable_time.h"

#ifdef __unix__
#include <time.h>
uint64_t get_current_time_sec()
{
    return (uint64_t)(time(NULL));
}
#endif
#ifdef __APPLE__
#include <time.h>
uint64_t get_current_time_sec()
{
    return (uint64_t)(time(NULL));
}
#endif
#ifdef __AVR__
uint64_t get_current_time_sec()
{
    return (uint64_t)(millis() / 1000);
}
#endif