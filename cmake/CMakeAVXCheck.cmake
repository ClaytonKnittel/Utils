# Checks for AVX support on this hardware. Sets the result to ${AVX_SUPPORTED}
# (either ON or OFF)

set(ENABLE_AVX "CHECK" CACHE STRING "When enabled, builds certain methods using the
	AVX instruction set. Can disable this manually, but AVX support is
	automatically checked.")

if("${ENABLE_AVX}" MATCHES "CHECK")
	set(OLD_CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}")
	set(CMAKE_ASM_FLAGS "${ASM_OPTIONS}")

	# check to see if this architecture supports AVX
	try_run(AVX_RES AVX_COMPILES ${CMAKE_CURRENT_BINARY_DIR} SOURCES
		${CMAKE_CURRENT_LIST_DIR}/arch_test/test_avx.s
		${CMAKE_CURRENT_LIST_DIR}/arch_test/test_empty.c
		COMPILE_OUTPUT_VARIABLE COUT
		RUN_OUTPUT_VARIABLE ROUT)

	message("${COUT}")
	message("rout: ${ROUT}")

	set(CMAKE_ASM_FLAGS "${OLD_CMAKE_ASM_FLAGS}")
	unset(OLD_CMAKE_ASM_FLAGS)

	if(NOT ${AVX_COMPILES})
		set(AVX_SUPPORTED OFF)
	elseif(NOT ${AVX_RES} EQUAL 0)
		set(AVX_SUPPORTED OFF)
	else()
		set(AVX_SUPPORTED ON)
	endif()

	if(${AVX_SUPPORTED})
		message(STATUS "AVX is supported on this architecture/compiler config")
		set(ENABLE_AVX "ON" CACHE STRING "When enabled, builds certain methods using the
			AVX instruction set. Can disable this manually, but AVX support is
			automatically checked." FORCE)
	else()
		message(WARNING "AVX is not supported on this architecture/compiler config")
		set(ENABLE_AVX "OFF" CACHE STRING "When enabled, builds certain methods using the
			AVX instruction set. Can disable this manually, but AVX support is
			automatically checked." FORCE)
	endif()
elseif("${ENABLE_AVX}" MATCHES "ON")
	set(AVX_SUPPORTED ON)
elseif("${ENABLE_AVX}" MATCHES "OFF")
	set(AVX_SUPPORTED OFF)
else()
	message(SEND_ERROR "ENABLE_AVX must be one of \"ON\", \"OFF\", or \"CHECK\"")
endif()

