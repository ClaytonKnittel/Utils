cmake_minimum_required(VERSION 3.3)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message("Setting build type to 'RelWithDebInfo' as none was specified")
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build" FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
		"RelWithDebInfo")
endif()


############################################################
# Utils Library
############################################################

project(utils VERSION 0.1)


############################################################
# Options
############################################################

set(BUILD_SHARED_LIBRARY ON CACHE BOOL "When enabled, builds libutils as a
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

if(${BUILD_SHARED_LIBRARY})
	add_library(utils SHARED
		${C_SRC} ${CXX_SRC} ${ASM_SRC}
	)
else()
	add_library(utils STATIC
		${C_SRC} ${CXX_SRC} ${ASM_SRC}
	)
endif()

if("${CMAKE_SYSTEM_PROCESSOR}" MATCHES "x86_64")
	enable_language(ASM-ATT)
	if(CMAKE_ASM-ATT_COMPILER_WORKS)
		set(can_use_assembler TRUE)
	endif()
endif()

if(NOT can_use_assembler)
	message(SEND_ERROR "No as/gas assembler found")
endif()

target_compile_options(utils PRIVATE
	$<$<NOT:$<COMPILE_LANGUAGE:ASM-ATT>>:-Wpedantic -Wall -Wextra
	-Wno-unused-function -Wno-format
	-march=native -mtune=native>
)
target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:C>:-std=gnu11>)
target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wno-extra-semi>)
target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:ASM-ATT>:--64 -msyntax=intel -mnaked-reg>)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)

if (COMPILER_SUPPORTS_CXX17)
	target_compile_options(utils PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)
else()
	message(SEND_ERROR "The compiler ${CMAKE_CXX_COMPILER} does not support "
		"c++17, please use a different compiler")
endif()

target_include_directories(utils
	PRIVATE
		$<$<NOT:$<COMPILE_LANGUAGE:ASM-ATT>>:${PROJECT_SOURCE_DIR}/include>
)

if (${ENABLE_TESTING})
    enable_testing()

	add_subdirectory(test)
endif()


############################################################
# Installation Rules
############################################################

# Library
if(${BUILD_SHARED_LIBRARY})
	install(TARGETS utils LIBRARY DESTINATION lib)
else()
	install(TARGETS utils ARCHIVE DESTINATION lib)
endif()

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)

# make uninstall
add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
            install_manifest.txt to be uninstalled!
)

