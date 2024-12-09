#include <sys/types.h>
extern char _end;
static char* heap_end = &_end;

void* _sbrk(ptrdiff_t increment) {
    char* prev_heap_end = heap_end;
    heap_end += increment;
    return prev_heap_end;
}
