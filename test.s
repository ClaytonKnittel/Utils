
.obj/data_structs/rtree_c.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 __rtree_rect_area_increase:
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: c5 fa 6f 07                  	vmovdqu	(%rdi), %xmm0
       8: c5 fa 6f 4f 10               	vmovdqu	16(%rdi), %xmm1
       d: c5 fa 6f 16                  	vmovdqu	(%rsi), %xmm2
      11: c5 fa 6f 5e 10               	vmovdqu	16(%rsi), %xmm3
      16: c4 e2 69 37 e0               	vpcmpgtq	%xmm0, %xmm2, %xmm4
      1b: c4 e3 69 4b d0 40            	vblendvpd	%xmm4, %xmm0, %xmm2, %xmm2
      21: c4 e2 71 37 e3               	vpcmpgtq	%xmm3, %xmm1, %xmm4
      26: c4 e3 61 4b d9 40            	vblendvpd	%xmm4, %xmm1, %xmm3, %xmm3
      2c: c5 e1 fb d2                  	vpsubq	%xmm2, %xmm3, %xmm2
      30: c4 e3 f9 16 d0 01            	vpextrq	$1, %xmm2, %rax
      36: c4 e1 f9 7e d1               	vmovq	%xmm2, %rcx
      3b: 48 0f af c1                  	imulq	%rcx, %rax
      3f: c4 e1 f9 7e c9               	vmovq	%xmm1, %rcx
      44: c4 e1 f9 7e c2               	vmovq	%xmm0, %rdx
      49: c4 e3 f9 16 ce 01            	vpextrq	$1, %xmm1, %rsi
      4f: 48 29 d1                     	subq	%rdx, %rcx
      52: c4 e3 f9 16 c2 01            	vpextrq	$1, %xmm0, %rdx
      58: 48 29 d6                     	subq	%rdx, %rsi
      5b: 48 0f af f1                  	imulq	%rcx, %rsi
      5f: 48 29 f0                     	subq	%rsi, %rax
      62: 5d                           	popq	%rbp
      63: c3                           	retq
      64: 66 2e 0f 1f 84 00 00 00 00 00	nopw	%cs:(%rax,%rax)
      6e: 66 90                        	nop

0000000000000070 _rtree_init:
      70: 55                           	pushq	%rbp
      71: 48 89 e5                     	movq	%rsp, %rbp
      74: 41 57                        	pushq	%r15
      76: 41 56                        	pushq	%r14
      78: 53                           	pushq	%rbx
      79: 50                           	pushq	%rax
      7a: 41 89 d7                     	movl	%edx, %r15d
      7d: 41 89 f6                     	movl	%esi, %r14d
      80: 48 89 fb                     	movq	%rdi, %rbx
      83: 89 d0                        	movl	%edx, %eax
      85: 48 8d 3c c5 28 00 00 00      	leaq	40(,%rax,8), %rdi
      8d: e8 00 00 00 00               	callq	0 <_rtree_init+0x22>
      92: c5 f8 57 c0                  	vxorps	%xmm0, %xmm0, %xmm0
      96: c5 fc 11 00                  	vmovups	%ymm0, (%rax)
      9a: 48 c7 40 20 00 00 00 00      	movq	$0, 32(%rax)
      a2: 48 89 03                     	movq	%rax, (%rbx)
      a5: 44 89 73 08                  	movl	%r14d, 8(%rbx)
      a9: 44 89 7b 0c                  	movl	%r15d, 12(%rbx)
      ad: 48 83 c4 08                  	addq	$8, %rsp
      b1: 5b                           	popq	%rbx
      b2: 41 5e                        	popq	%r14
      b4: 41 5f                        	popq	%r15
      b6: 5d                           	popq	%rbp
      b7: c5 f8 77                     	vzeroupper
      ba: c3                           	retq

Disassembly of section __LD,__compact_unwind:

00000000000000c0 __compact_unwind:
		...
      c8: 64 00 00                     	addb	%al, %fs:(%rax)
      cb: 00 00                        	addb	%al, (%rax)
      cd: 00 00                        	addb	%al, (%rax)
      cf: 01 00                        	addl	%eax, (%rax)
		...
      dd: 00 00                        	addb	%al, (%rax)
      df: 00 70 00                     	addb	%dh, (%rax)
      e2: 00 00                        	addb	%al, (%rax)
      e4: 00 00                        	addb	%al, (%rax)
      e6: 00 00                        	addb	%al, (%rax)
      e8: 4b 00 00                     	addb	%al, (%r8)
      eb: 00 61 01                     	addb	%ah, 1(%rcx)
      ee: 03 01                        	addl	(%rcx), %eax
		...

Disassembly of section __TEXT,__eh_frame:

0000000000000100 __eh_frame:
     100: 14 00                        	adcb	$0, %al
     102: 00 00                        	addb	%al, (%rax)
     104: 00 00                        	addb	%al, (%rax)
     106: 00 00                        	addb	%al, (%rax)
     108: 01 7a 52                     	addl	%edi, 82(%rdx)
     10b: 00 01                        	addb	%al, (%rcx)
     10d: 78 10                        	js	16 <__eh_frame+0x1f>
     10f: 01 10                        	addl	%edx, (%rax)
     111: 0c 07                        	orb	$7, %al
     113: 08 90 01 00 00 24            	orb	%dl, 603979777(%rax)
     119: 00 00                        	addb	%al, (%rax)
     11b: 00 1c 00                     	addb	%bl, (%rax,%rax)
     11e: 00 00                        	addb	%al, (%rax)
     120: e0 fe                        	loopne	-2
     122: ff ff                        	<unknown>
     124: ff ff                        	<unknown>
     126: ff ff                        	<unknown>
     128: 64 00 00                     	addb	%al, %fs:(%rax)
     12b: 00 00                        	addb	%al, (%rax)
     12d: 00 00                        	addb	%al, (%rax)
     12f: 00 00                        	addb	%al, (%rax)
     131: 41 0e                        	<unknown>
     133: 10 86 02 43 0d 06            	adcb	%al, 101532418(%rsi)
     139: 00 00                        	addb	%al, (%rax)
     13b: 00 00                        	addb	%al, (%rax)
     13d: 00 00                        	addb	%al, (%rax)
     13f: 00 24 00                     	addb	%ah, (%rax,%rax)
     142: 00 00                        	addb	%al, (%rax)
     144: 44 00 00                     	addb	%r8b, (%rax)
     147: 00 28                        	addb	%ch, (%rax)
     149: ff ff                        	<unknown>
     14b: ff ff                        	<unknown>
     14d: ff ff                        	<unknown>
     14f: ff 4b 00                     	decl	(%rbx)
     152: 00 00                        	addb	%al, (%rax)
     154: 00 00                        	addb	%al, (%rax)
     156: 00 00                        	addb	%al, (%rax)
     158: 00 41 0e                     	addb	%al, 14(%rcx)
     15b: 10 86 02 43 0d 06            	adcb	%al, 101532418(%rsi)
     161: 46 83 05 8e 04 8f 03         	<unknown>
