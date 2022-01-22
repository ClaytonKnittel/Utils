project(utils_unit_testing)

# Use boost for unit testing
find_package(Boost 1.23.0 REQUIRED COMPONENTS unit_test_framework)

file(GLOB_RECURSE C_TEST_SRC
	"${PROJECT_SOURCE_DIR}/*.c"
)
file(GLOB_RECURSE CXX_TEST_SRC
	"${PROJECT_SOURCE_DIR}/*.cc"
)

add_executable(utils_unit_testing
	${C_TEST_SRC} ${CXX_TEST_SRC}
)

target_compile_options(utils_unit_testing PRIVATE
	-Wpedantic -Wall -Wextra -march=native -mtune=native -Wno-unused-function -Wno-extra-semi -Wno-format-pedantic
)
target_compile_options(utils_unit_testing PRIVATE $<$<COMPILE_LANGUAGE:C>:-std=gnu11>)
target_compile_options(utils_unit_testing PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>)

target_link_libraries(utils_unit_testing
	PRIVATE
		utils
	PUBLIC
		Boost::boost
)

get_filename_component(UTILS_DIR ../ ABSOLUTE)

target_include_directories(utils_unit_testing
	PRIVATE
		${UTILS_DIR}/include
)

