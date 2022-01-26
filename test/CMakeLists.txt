project(utils_unit_testing)

# Use boost for unit testing
find_library(check check REQUIRED)

file(GLOB_RECURSE C_TEST_SRC
	"${PROJECT_SOURCE_DIR}/test_*.c"
)
file(GLOB_RECURSE CXX_TEST_SRC
	"${PROJECT_SOURCE_DIR}/test_*.cc"
)

add_executable(utils_unit_testing
	${C_TEST_SRC} ${CXX_TEST_SRC}
)

add_custom_target(run_tests
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME} DEPENDS utils_unit_testing
)

target_compile_options(utils_unit_testing PRIVATE
	-Wpedantic -Wall -Wextra -Wno-unused-function -Wno-format
	-Wno-gnu-zero-variadic-macro-arguments -march=native -mtune=native
)
target_compile_options(utils_unit_testing PRIVATE $<$<COMPILE_LANGUAGE:C>:-std=gnu11>)
target_compile_options(utils_unit_testing PRIVATE $<$<COMPILE_LANGUAGE:CXX>:
	-std=c++17 -Wno-extra-semi
>)

target_include_directories(utils_unit_testing
	PUBLIC "/usr/local/include"
)

target_link_directories(utils_unit_testing
	PUBLIC "/usr/local/lib"
)

target_link_libraries(utils_unit_testing
	PRIVATE
		utils
	PUBLIC
		check
)

get_filename_component(UTILS_DIR ../ ABSOLUTE)

target_include_directories(utils_unit_testing
	PRIVATE
		${UTILS_DIR}/include
)

