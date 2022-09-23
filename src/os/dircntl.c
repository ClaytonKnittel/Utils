
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <utils/os/dircntl.h>
#include <utils/string/string.h>

int mkdirp(const char* path, mode_t mode) {
  char tmp[PATH_MAX + 1];
  size_t pos = 0;
  size_t path_len = strlen(path);
  struct stat dir_stat;

  if (path_len == 0) {
    errno = ENOENT;
    return -1;
  }

  if (path_len > PATH_MAX) {
    errno = ENAMETOOLONG;
    return -1;
  }

  while (pos < path_len) {
    char* next_delim = strchrnul(path + pos, DIR_DELIM);

    if (next_delim == path + pos) {
      // skip repeated delimiters/root directory
      tmp[pos] = DIR_DELIM;
      pos++;
    } else {
      ptrdiff_t dirname_len = next_delim - (path + pos);
      memcpy(tmp + pos, path + pos, dirname_len);
      pos += dirname_len;
      tmp[pos] = '\0';

      if (stat(tmp, &dir_stat) == 0) {
        if (!S_ISDIR(dir_stat.st_mode)) {
          errno = ENOTDIR;
          return -1;
        }
      } else {
        if (mkdir(tmp, mode) != 0) {
          return -1;
        }
      }

      // This path must have ended with a delimiter, or be the end of the
      // string. Write the directory delimiter to tmp in anticipation of it
      // being there.
      tmp[pos] = DIR_DELIM;
      pos++;
    }
  }

  return 0;
}

static int _check_empty(const char* path) {
  char tmp_path[PATH_MAX + 1];
  DIR* dir;
  struct dirent* dirent;
  size_t path_len = strlen(path);
  size_t dirent_name_len;

  dir = opendir(path);
  if (dir == NULL) {
    return -1;
  }

  memcpy(tmp_path, path, path_len);
  tmp_path[path_len] = DIR_DELIM;

  errno = 0;
  while ((dirent = readdir(dir)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0) {
      continue;
    }
    if (strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    if (dirent->d_type != DT_DIR) {
      errno = ENOTEMPTY;
      return -1;
    }

    dirent_name_len = strlen(dirent->d_name);
    if (path_len + 1 + dirent_name_len > PATH_MAX) {
      errno = ENAMETOOLONG;
      return -1;
    }

    strcpy(tmp_path + path_len + 1, dirent->d_name);
    if (_check_empty(tmp_path) != 0) {
      return -1;
    }
  }
  if (errno != 0) {
    return -1;
  }

  return 0;
}

static int _rmdir_rec(const char* path) {
  char tmp_path[PATH_MAX + 1];
  DIR* dir;
  struct dirent* dirent;
  size_t path_len = strlen(path);
  size_t dirent_name_len;

  dir = opendir(path);
  if (dir == NULL) {
    return -1;
  }

  memcpy(tmp_path, path, path_len);
  tmp_path[path_len] = DIR_DELIM;

  errno = 0;
  while ((dirent = readdir(dir)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0) {
      continue;
    }
    if (strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    // This is unlikely because we just checked for it, but a race condition
    // exists on insertion of a file after we checked for it.
    if (dirent->d_type != DT_DIR) {
      errno = ENOTEMPTY;
      return -1;
    }

    dirent_name_len = strlen(dirent->d_name);
    if (path_len + 1 + dirent_name_len > PATH_MAX) {
      errno = ENAMETOOLONG;
      return -1;
    }

    strcpy(tmp_path + path_len + 1, dirent->d_name);
    if (_rmdir_rec(tmp_path) != 0) {
      return -1;
    }
    if (rmdir(tmp_path) != 0) {
      return -1;
    }
  }
  if (errno != 0) {
    return -1;
  }

  return 0;
}

int rmdirp(const char* path) {
  if (_check_empty(path) != 0) {
    return -1;
  }
  if (_rmdir_rec(path) != 0) {
    return -1;
  }
  return rmdir(path);
}
