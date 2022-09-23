#ifndef _UTIL_OS_DIRCNTL_H
#define _UTIL_OS_DIRCNTL_H

#include <sys/stat.h>

/*
 * The directory delimiter in filesystem paths.
 */
#define DIR_DELIM '/'

/*
 * Recursive mkdir: will traverse the directories named in "path" and attempt to
 * create them. If any creation failes due to it already existing as a
 * directory, it is ignored.
 *
 * Returns 0 on success, -1 on failure and sets errno.
 */
int mkdirp(const char* path, mode_t mode);

/*
 * Recursive rmdir: will recursively remove a directory and all directories it
 * contains. First checked for inodes other than directories under the given
 * path, failing if any exist.
 *
 * Returns 0 on success, -1 on failure and sets errno.
 */
int rmdirp(const char* path);

#endif /* _UTIL_OS_DIRCNTL_H */
