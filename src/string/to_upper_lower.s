
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
    push rbx

	add rsi, rdi

	vmovdqa  ymm3, ymmword ptr upper_offset_array[rip]
	vmovdqa  ymm4, ymmword ptr range_min[rip]

_up_loop_init:
	mov rax, rdi
	add rax, 31
	and rax, 0xffffffffffffffe0

	# calculate the upper bound and place it in rcx
	cmp rsi, rax
	mov rcx, rax
	cmovb rcx, rsi

	jmp _up_beg_loop_cond

_up_beg_loop:
	movzx eax, byte ptr [rdi]
	lea ebx, [rax - 0x61]
	lea edx, [rax - 0x20]
	cmp ebx, 26
	cmovb eax, edx
	mov byte ptr [rdi], al

	inc rdi
_up_beg_loop_cond:
	cmp rdi, rcx
	jne _up_beg_loop

_up_vector_loop_init:
	mov rcx, rsi
	and rcx, 0xffffffffffffffe0

_up_vector_loop_cond_1:
	cmp rdi, rcx
	jae _up_remainder_loop_cond_1

_up_vector_loop:
	vmovdqa  ymm1, ymmword ptr [rdi]
	vpaddb   ymm2, ymm3, ymm1
	vpcmpgtb ymm2, ymm2, ymm4
	vpand    ymm2, ymm2, ymmword ptr lower_to_upper[rip]
	vpaddb   ymm1, ymm2, ymm1
	vmovdqa  ymmword ptr [rdi], ymm1

	add rdi, 32

_up_vector_loop_cond_2:
	cmp rdi, rcx
	jb _up_vector_loop

_up_remainder_loop_cond_1:
	cmp rdi, rsi
	je _up_finished

_up_remainder_loop:
	movzx eax, byte ptr [rdi]
	lea ebx, [rax - 0x61]
	lea edx, [rax - 0x20]
	cmp ebx, 26
	cmovb eax, edx
	mov byte ptr [rdi], al

	inc rdi

_up_remainder_loop_cond_2:
	cmp rdi, rsi
	jne _up_remainder_loop

_up_finished:
	pop rbx
	ret


_to_lower:
    push rbx

	add rsi, rdi

	vmovdqa  ymm3, ymmword ptr lower_offset_array[rip]
	vmovdqa  ymm4, ymmword ptr range_min[rip]

_lo_loop_init:
	mov rax, rdi
	add rax, 31
	and rax, 0xffffffffffffffe0

	# calculate the upper bound and place it in rcx
	cmp rsi, rax
	mov rcx, rax
	cmovb rcx, rsi

	jmp _lo_beg_loop_cond

_lo_beg_loop:
	movzx eax, byte ptr [rdi]
	lea ebx, [rax - 0x41]
	lea edx, [rax + 0x20]
	cmp ebx, 26
	cmovb eax, edx
	mov byte ptr [rdi], al

	inc rdi
_lo_beg_loop_cond:
	cmp rdi, rcx
	jne _lo_beg_loop

_lo_vector_loop_init:
	mov rcx, rsi
	and rcx, 0xffffffffffffffe0

_lo_vector_loop_cond_1:
	cmp rdi, rcx
	jae _lo_remainder_loop_cond_1

_lo_vector_loop:
	vmovdqa  ymm1, ymmword ptr [rdi]
	vpaddb   ymm2, ymm3, ymm1
	vpcmpgtb ymm2, ymm2, ymm4
	vpand    ymm2, ymm2, ymmword ptr upper_to_lower[rip]
	vpaddb   ymm1, ymm2, ymm1
	vmovdqa  ymmword ptr [rdi], ymm1

	add rdi, 32

_lo_vector_loop_cond_2:
	cmp rdi, rcx
	jb _lo_vector_loop

_lo_remainder_loop_cond_1:
	cmp rdi, rsi
	je _lo_finished

_lo_remainder_loop:
	movzx eax, byte ptr [rdi]
	lea ebx, [rax - 0x41]
	lea edx, [rax + 0x20]
	cmp ebx, 26
	cmovb eax, edx
	mov byte ptr [rdi], al

	inc rdi

_lo_remainder_loop_cond_2:
	cmp rdi, rsi
	jne _lo_remainder_loop

_lo_finished:
	pop rbx
	ret

