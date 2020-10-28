# Utils

A library containing common data structures/algorithms/etc. that I commonly use.


## Usage

Add as a submodule for a project
```bash
$ git submodule add https://github.com/ClaytonKnittel/Utils util
```
then add this line to your Makefile:
```make
.PHONY: util
util:
  (make -C util LIB_DIR=<path_to_lib_dir>)
```
and make util a dependency of all targets that require it.

Then, add the following to your make variable declarations:
```make
INCLUDES += -Iutil/include/
LDFLAGS  += <path_to_lib_dir>/libutil.a
```

And lastly, add this line to your clean target:
```make
clean:
  ...
  (make -C util clean)
```
