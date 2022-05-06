.global _test_avx

.data
# align by 32 bytes for vmovdqa read
.balign 32
# to shift all lowercase letters to the highest signed-byte range
upper_offset_array:
	.quad 0x0505050505050505
	.quad 0x0505050505050505
	.quad 0x0505050505050505
	.quad 0x0505050505050505

.text
_test_avx:
	vmovdqa  ymm0, ymmword ptr upper_offset_array[rip]
	vaddpd ymm0, ymm1, ymm2
	ret

