
.intel_syntax noprefix
.global _to_upper
.global _to_lower

.data:
.align 5
# to shift all lowercase letters to the highest signed-byte range
upper_offset_array:
	.quad 0x0505050505050505
	.quad 0x0505050505050505
	.quad 0x0505050505050505
	.quad 0x0505050505050505
# to shift all uppercase letters to the highest signed-byte range
lower_offset_array:
	.quad 0x2525252525252525
	.quad 0x2525252525252525
	.quad 0x2525252525252525
	.quad 0x2525252525252525
# 1 - the value of a after being shifted by offset_array
range_min:
	.quad 0x6565656565656565
	.quad 0x6565656565656565
	.quad 0x6565656565656565
	.quad 0x6565656565656565
# amount to add to lowercase letters to make them uppercase
lower_to_upper:
	.quad 0xe0e0e0e0e0e0e0e0
	.quad 0xe0e0e0e0e0e0e0e0
	.quad 0xe0e0e0e0e0e0e0e0
	.quad 0xe0e0e0e0e0e0e0e0
# amount to add to uppercase letters to make them lowercase
upper_to_lower:
	.quad 0x2020202020202020
	.quad 0x2020202020202020
	.quad 0x2020202020202020
	.quad 0x2020202020202020

.text:
_to_upper:
	test rsi, rsi
	je _up_return

	push rbx

	lea rbx, [rdi + rsi]
	cmp rsi, 16
	jb _up_remainder_loop

	vmovdqa  ymm0, ymmword ptr upper_offset_array[rip]
	vmovdqa  ymm1, ymmword ptr range_min[rip]
	vmovdqa  ymm2, ymmword ptr lower_to_upper[rip]

	mov rcx, rsi
	and rcx, 0xfffffffffffffff0
	add rcx, rdi

	cmp rsi, 128
	jb _up_vector_loop

	mov rdx, rsi
	and rdx, 0xffffffffffffff80
	add rdx, rdi

_up_4x_vector_loop:
	vmovdqu  ymm3, ymmword ptr [rdi]
	vmovdqu  ymm5, ymmword ptr [rdi + 32]
	vmovdqu  ymm7, ymmword ptr [rdi + 64]
	vmovdqu  ymm9, ymmword ptr [rdi + 96]
	vpaddb   ymm4,  ymm3,  ymm0
	vpaddb   ymm6,  ymm5,  ymm0
	vpaddb   ymm8,  ymm7,  ymm0
	vpaddb   ymm10, ymm9,  ymm0
	vpcmpgtb ymm4,  ymm4,  ymm1
	vpcmpgtb ymm6,  ymm6,  ymm1
	vpcmpgtb ymm8,  ymm8,  ymm1
	vpcmpgtb ymm10, ymm10, ymm1
	vpand    ymm4,  ymm4,  ymm2
	vpand    ymm6,  ymm6,  ymm2
	vpand    ymm8,  ymm8,  ymm2
	vpand    ymm10, ymm10, ymm2
	vpaddb   ymm3,  ymm4,  ymm3
	vpaddb   ymm5,  ymm6,  ymm5
	vpaddb   ymm7,  ymm8,  ymm7
	vpaddb   ymm9,  ymm10, ymm9
	vmovdqu  ymmword ptr [rdi],      ymm3
	vmovdqu  ymmword ptr [rdi + 32], ymm5
	vmovdqu  ymmword ptr [rdi + 64], ymm7
	vmovdqu  ymmword ptr [rdi + 96], ymm9

	add rdi, 128

_up_4x_vector_loop_cond:
	cmp rdi, rdx
	jne _up_4x_vector_loop

_up_vector_loop_cond_1:
	cmp rdi, rcx
	je _up_remainder_loop_cond_2

_up_vector_loop:
	vmovdqu  xmm3, xmmword ptr [rdi]
	vpaddb   xmm4, xmm3, xmm0
	vpcmpgtb xmm4, xmm4, xmm1
	vpand    xmm4, xmm4, xmm2
	vpaddb   xmm3, xmm4, xmm3
	vmovdqu  xmmword ptr [rdi], xmm3

	add rdi, 16

_up_vector_loop_cond_2:
	cmp rdi, rcx
	jb _up_vector_loop

_up_remainder_loop_cond_1:
	cmp rdi, rbx
	je _up_finished

_up_remainder_loop:
	movzx eax, byte ptr [rdi]
	lea ecx, [rax - 0x61]
	lea edx, [rax - 0x20]
	cmp ecx, 26
	cmovb eax, edx
	#lea ecx, [eax + 0x05]
	#and cl, 0x7f
	#add cl, 0x1a
	#andn ecx, eax, ecx
	#sar cl, 2
	#and cl, 0xe0
	#add al, cl
	mov byte ptr [rdi], al

	inc rdi

_up_remainder_loop_cond_2:
	cmp rdi, rbx
	jne _up_remainder_loop

_up_finished:
	pop rbx
_up_return:
	ret


_to_lower:
	test rsi, rsi
	je _lo_return

	push rbx

	lea rbx, [rdi + rsi]
	cmp rsi, 16
	jb _lo_remainder_loop

	vmovdqa  ymm0, ymmword ptr lower_offset_array[rip]
	vmovdqa  ymm1, ymmword ptr range_min[rip]
	vmovdqa  ymm2, ymmword ptr upper_to_lower[rip]

	mov rcx, rsi
	and rcx, 0xffffffffffffffe0
	add rcx, rdi

	cmp rsi, 128
	jb _lo_vector_loop

	mov rdx, rsi
	and rdx, 0xffffffffffffff80
	add rdx, rdi

_lo_4x_vector_loop:
	vmovdqu  ymm3, ymmword ptr [rdi]
	vmovdqu  ymm5, ymmword ptr [rdi + 32]
	vmovdqu  ymm7, ymmword ptr [rdi + 64]
	vmovdqu  ymm9, ymmword ptr [rdi + 96]
	vpaddb   ymm4,  ymm3,  ymm0
	vpaddb   ymm6,  ymm5,  ymm0
	vpaddb   ymm8,  ymm7,  ymm0
	vpaddb   ymm10, ymm9,  ymm0
	vpcmpgtb ymm4,  ymm4,  ymm1
	vpcmpgtb ymm6,  ymm6,  ymm1
	vpcmpgtb ymm8,  ymm8,  ymm1
	vpcmpgtb ymm10, ymm10, ymm1
	vpand    ymm4,  ymm4,  ymm2
	vpand    ymm6,  ymm6,  ymm2
	vpand    ymm8,  ymm8,  ymm2
	vpand    ymm10, ymm10, ymm2
	vpaddb   ymm3,  ymm4,  ymm3
	vpaddb   ymm5,  ymm6,  ymm5
	vpaddb   ymm7,  ymm8,  ymm7
	vpaddb   ymm9,  ymm10, ymm9
	vmovdqu  ymmword ptr [rdi],      ymm3
	vmovdqu  ymmword ptr [rdi + 32], ymm5
	vmovdqu  ymmword ptr [rdi + 64], ymm7
	vmovdqu  ymmword ptr [rdi + 96], ymm9

	add rdi, 128

_lo_4x_vector_loop_cond:
	cmp rdi, rdx
	jne _lo_4x_vector_loop

_lo_vector_loop_cond_1:
	cmp rdi, rcx
	je _lo_remainder_loop_cond_2

_lo_vector_loop:
	vmovdqu  xmm3, xmmword ptr [rdi]
	vpaddb   xmm4, xmm3, xmm0
	vpcmpgtb xmm4, xmm4, xmm1
	vpand    xmm4, xmm4, xmm2
	vpaddb   xmm3, xmm4, xmm3
	vmovdqu  xmmword ptr [rdi], xmm3

	add rdi, 16

_lo_vector_loop_cond_2:
	cmp rdi, rcx
	jb _lo_vector_loop

_lo_remainder_loop_cond_1:
	cmp rdi, rbx
	je _lo_finished

_lo_remainder_loop:
	movzx eax, byte ptr [rdi]
	lea ecx, [rax - 0x41]
	lea edx, [rax + 0x20]
	cmp ecx, 26
	cmovb eax, edx
	#lea ecx, [eax + 0x25]
	#and cl, 0x7f
	#add cl, 0x1a
	#andn ecx, eax, ecx
	#shr cl, 2
	#and cl, 0x20
	#add al, cl
	mov byte ptr [rdi], al

	inc rdi

_lo_remainder_loop_cond_2:
	cmp rdi, rbx
	jne _lo_remainder_loop

_lo_finished:
	pop rbx
_lo_return:
	ret

