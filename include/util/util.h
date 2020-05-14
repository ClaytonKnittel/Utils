#ifndef _STDUTIL_H
#define _STDUTIL_H

#include <stdio.h>


#define printerr(f, fmt, ...) \
    fprintf((f), __FILE__ ":%d " fmt, __LINE__, __VA_ARGS__)


#endif /* _STDUTIL_H */
