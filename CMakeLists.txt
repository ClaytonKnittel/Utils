cmake_minimum_required(VERSION 3.18)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'RelWithDebInfo' as none was specified")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "RelWithDebInfo" "MinSizeRel")
endif()

if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  find_program(LSB_RELEASE_EXEC lsb_release REQUIRED)
  execute_process(COMMAND ${LSB_RELEASE_EXEC} -is
    OUTPUT_VARIABLE LINUX_DISTR
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  if("${LINUX_DISTR}" MATCHES "Ubuntu")
    list(APPEND LINK_LIBS "rt;pthread")
  endif()
else()
  set(LINUX_DISTR "")
endif()


############################################################
# Utils Library
############################################################

project(utils VERSION 0.1)


############################################################
# Options
############################################################

set(BUILD_SHARED_LIBS ON CACHE BOOL "When enabled, builds libutils as a
  shared library, otherwise building as a static library")
set(ENABLE_TESTING OFF CACHE BOOL "When enabled, build all unit tests. The
  unit tests can then be run from within the build directory with
  'make run_tests'.")


############################################################
# Build Rules
############################################################

file(GLOB_RECURSE C_SRC
  "${PROJECT_SOURCE_DIR}/src/*.c"
)
file(GLOB_RECURSE CXX_SRC
  "${PROJECT_SOURCE_DIR}/src/*.cc"
)
file(GLOB_RECURSE ASM_SRC
  "${PROJECT_SOURCE_DIR}/src/*.s"
)

# remove test_empty.c
list(FILTER C_SRC EXCLUDE REGEX "^${PROJECT_SOURCE_DIR}/src/arch_test/.*")
list(FILTER CXX_SRC EXCLUDE REGEX "^${PROJECT_SOURCE_DIR}/src/arch_test/.*")
list(FILTER ASM_SRC EXCLUDE REGEX "^${PROJECT_SOURCE_DIR}/src/arch_test/.*")

if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "x86_64")
  enable_language(ASM)
  if(CMAKE_ASM_COMPILER_WORKS)
    set(can_use_assembler TRUE)
  endif()
endif()

if(NOT can_use_assembler)
  message(SEND_ERROR "No assembler found")
endif()

if("${CMAKE_ASM_COMPILER_ID}" MATCHES "GNU")
  set(ASM_OPTIONS -Wa,--64 -Wa,-msyntax=intel -Wa,-mnaked-reg)
elseif("${CMAKE_ASM_COMPILER_ID}" MATCHES "Clang")
  set(ASM_OPTIONS -masm=intel)
else()
  message(SEND_ERROR "Unsupported assembler (${CMAKE_ASM_COMPILER_ID})")
endif()

include(${PROJECT_SOURCE_DIR}/cmake/CMakeAVXCheck.cmake)

if (NOT AVX_SUPPORTED)
  list(FILTER ASM_SRC EXCLUDE REGEX "^${PROJECT_SOURCE_DIR}/src/.+_avx.s")
endif()

if(${BUILD_SHARED_LIBS})
  add_library(utils SHARED
    ${C_SRC} ${CXX_SRC} ${ASM_SRC}
  )
else()
  add_library(utils STATIC
    ${C_SRC} ${CXX_SRC} ${ASM_SRC}
  )
endif()

target_compile_options(utils PRIVATE
  $<$<NOT:$<COMPILE_LANGUAGE:ASM>>:-Werror -Wpedantic -Wall -Wextra
	-Wno-unused-function -Wno-format -Wno-format-pedantic -Wno-array-bounds
	-Wno-maybe-uninitialized -Wno-unknown-warning-option
  -march=native -mtune=native>
)
target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:C>:-std=gnu11>)
target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wno-extra-semi -Wno-c99-extensions>)

target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:ASM>:${ASM_OPTIONS}>)

if("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
  # Enable strchrnul on Linux
  target_compile_definitions(utils
    PUBLIC _GNU_SOURCE
  )
endif()

if (${ENABLE_TESTING})
  target_compile_definitions(utils
    PRIVATE DO_TESTING
    PUBLIC DEBUG
  )
elseif("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
  target_compile_definitions(utils
    PUBLIC DEBUG
  )
endif()

if ("${CMAKE_BUILD_TYPE}" MATCHES "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT IPO_SUPPORT_CHECK_OUTPUT LANGUAGES C;CXX)

  if (NOT IPO_SUPPORTED)
    message(WARNING "Interprocedural optimization not supported: ${IPO_SUPPORT_CHECK_OUTPUT}")
  else()
    # enable link-time optimization
    set_property(TARGET utils PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
  endif()
endif()

if (${AVX_SUPPORTED})
  target_compile_definitions(utils PUBLIC AVX_SUPPORTED)
endif()

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)

if (COMPILER_SUPPORTS_CXX17)
  target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)
else()
  message(SEND_ERROR "The compiler ${CMAKE_CXX_COMPILER} does not support "
    "c++17, please use a different compiler")
endif()

target_include_directories(utils
  PUBLIC
    $<$<NOT:$<COMPILE_LANGUAGE:ASM>>:${PROJECT_SOURCE_DIR}/include>
    "/usr/local/include"
)

if (${ENABLE_TESTING})

  if("${CMAKE_BUILD_TYPE}" MATCHES "Release")
    message(WARNING "Enabling testing in Release mode is discouraged. This leaves in some debugging functionality that may slow/bloat the library.")
  endif()
  target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wno-gnu-zero-variadic-macro-arguments>)

  find_library(check check REQUIRED)

  target_link_directories(utils
    PUBLIC "/usr/local/lib"
  )

  target_link_libraries(utils
    PRIVATE check
  )

  enable_testing()

  add_subdirectory(test)
endif()

target_link_libraries(utils
  PUBLIC "${LINK_LIBS}"
)


############################################################
# Installation Rules
############################################################

# Library
if(${BUILD_SHARED_LIBS})
  install(TARGETS utils LIBRARY DESTINATION lib)
else()
  install(TARGETS utils ARCHIVE DESTINATION lib)
endif()

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
  DESTINATION include)

if (NOT TARGET uninstall)
  # make uninstall
  add_custom_target("uninstall" COMMENT "Uninstall installed files")
  add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
    install_manifest.txt to be uninstalled!
  )
endif()

