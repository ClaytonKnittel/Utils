
#include <string.h>

#include <utils/string/string.h>

#ifdef __APPLE__

char* strchrnul(const char* s, int c) {
  const char* inst = strchr(s, c);
  if (inst == NULL) {
    inst = s + strlen(s);
  }
  return (char*) inst;
}

#endif /* __APPLE__ */
