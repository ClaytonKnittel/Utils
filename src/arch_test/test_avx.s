.global _test_avx

_test_avx:
	vaddpd ymm0, ymm1, ymm2
	ret

