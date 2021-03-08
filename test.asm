
bin/to_upper_lower_test:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000100002700 _gen_rand_str:
100002700: 55                          	pushq	%rbp
100002701: 48 89 e5                    	movq	%rsp, %rbp
100002704: 41 57                       	pushq	%r15
100002706: 41 56                       	pushq	%r14
100002708: 53                          	pushq	%rbx
100002709: 50                          	pushq	%rax
10000270a: 49 89 f7                    	movq	%rsi, %r15
10000270d: 49 89 fe                    	movq	%rdi, %r14
100002710: 48 85 f6                    	testq	%rsi, %rsi
100002713: 74 3c                       	je	60 <_gen_rand_str+0x51>
100002715: 31 db                       	xorl	%ebx, %ebx
100002717: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)
100002720: e8 bd 15 00 00              	callq	5565 <dyld_stub_binder+0x100003ce2>
100002725: 48 98                       	cltq
100002727: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
10000272e: 48 c1 e9 20                 	shrq	$32, %rcx
100002732: 01 c1                       	addl	%eax, %ecx
100002734: 89 ca                       	movl	%ecx, %edx
100002736: c1 ea 1f                    	shrl	$31, %edx
100002739: c1 e9 06                    	shrl	$6, %ecx
10000273c: 01 d1                       	addl	%edx, %ecx
10000273e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002741: 29 c8                       	subl	%ecx, %eax
100002743: 04 20                       	addb	$32, %al
100002745: 41 88 04 1e                 	movb	%al, (%r14,%rbx)
100002749: 48 ff c3                    	incq	%rbx
10000274c: 49 39 df                    	cmpq	%rbx, %r15
10000274f: 75 cf                       	jne	-49 <_gen_rand_str+0x20>
100002751: 43 c6 04 3e 00              	movb	$0, (%r14,%r15)
100002756: 48 83 c4 08                 	addq	$8, %rsp
10000275a: 5b                          	popq	%rbx
10000275b: 41 5e                       	popq	%r14
10000275d: 41 5f                       	popq	%r15
10000275f: 5d                          	popq	%rbp
100002760: c3                          	retq
100002761: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000276b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100002770 _naive_to_upper:
100002770: 55                          	pushq	%rbp
100002771: 48 89 e5                    	movq	%rsp, %rbp
100002774: 48 85 f6                    	testq	%rsi, %rsi
100002777: 0f 84 6a 01 00 00           	je	362 <_naive_to_upper+0x177>
10000277d: 48 83 fe 7f                 	cmpq	$127, %rsi
100002781: 77 08                       	ja	8 <_naive_to_upper+0x1b>
100002783: 45 31 c0                    	xorl	%r8d, %r8d
100002786: e9 35 01 00 00              	jmp	309 <_naive_to_upper+0x150>
10000278b: 49 89 f0                    	movq	%rsi, %r8
10000278e: 49 83 e0 80                 	andq	$-128, %r8
100002792: 31 c9                       	xorl	%ecx, %ecx
100002794: c5 fd 6f 05 04 16 00 00     	vmovdqa	5636(%rip), %ymm0
10000279c: c5 fd 6f 0d 1c 16 00 00     	vmovdqa	5660(%rip), %ymm1
1000027a4: c5 fd 6f 15 34 16 00 00     	vmovdqa	5684(%rip), %ymm2
1000027ac: c5 fd 6f 1d 4c 16 00 00     	vmovdqa	5708(%rip), %ymm3
1000027b4: c5 fd 6f 25 64 16 00 00     	vmovdqa	5732(%rip), %ymm4
1000027bc: c5 fd 6f 2d 7c 16 00 00     	vmovdqa	5756(%rip), %ymm5
1000027c4: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000027ce: 66 90                       	nop
1000027d0: c5 fe 6f 34 0f              	vmovdqu	(%rdi,%rcx), %ymm6
1000027d5: c5 fe 6f 7c 0f 20           	vmovdqu	32(%rdi,%rcx), %ymm7
1000027db: c5 7e 6f 44 0f 40           	vmovdqu	64(%rdi,%rcx), %ymm8
1000027e1: c5 7e 6f 4c 0f 60           	vmovdqu	96(%rdi,%rcx), %ymm9
1000027e7: c5 4d fc d0                 	vpaddb	%ymm0, %ymm6, %ymm10
1000027eb: c5 45 fc d8                 	vpaddb	%ymm0, %ymm7, %ymm11
1000027ef: c5 3d fc e0                 	vpaddb	%ymm0, %ymm8, %ymm12
1000027f3: c5 35 fc e8                 	vpaddb	%ymm0, %ymm9, %ymm13
1000027f7: c5 2d db d1                 	vpand	%ymm1, %ymm10, %ymm10
1000027fb: c5 25 db d9                 	vpand	%ymm1, %ymm11, %ymm11
1000027ff: c5 1d db e1                 	vpand	%ymm1, %ymm12, %ymm12
100002803: c5 15 db e9                 	vpand	%ymm1, %ymm13, %ymm13
100002807: c5 2d fc d2                 	vpaddb	%ymm2, %ymm10, %ymm10
10000280b: c5 25 fc da                 	vpaddb	%ymm2, %ymm11, %ymm11
10000280f: c5 1d fc e2                 	vpaddb	%ymm2, %ymm12, %ymm12
100002813: c5 15 fc ea                 	vpaddb	%ymm2, %ymm13, %ymm13
100002817: c4 41 4d df d2              	vpandn	%ymm10, %ymm6, %ymm10
10000281c: c4 41 45 df db              	vpandn	%ymm11, %ymm7, %ymm11
100002821: c4 41 3d df e4              	vpandn	%ymm12, %ymm8, %ymm12
100002826: c4 41 35 df ed              	vpandn	%ymm13, %ymm9, %ymm13
10000282b: c4 c1 2d 71 d2 02           	vpsrlw	$2, %ymm10, %ymm10
100002831: c5 2d db d3                 	vpand	%ymm3, %ymm10, %ymm10
100002835: c5 2d ef d4                 	vpxor	%ymm4, %ymm10, %ymm10
100002839: c5 2d f8 d4                 	vpsubb	%ymm4, %ymm10, %ymm10
10000283d: c4 c1 25 71 d3 02           	vpsrlw	$2, %ymm11, %ymm11
100002843: c5 25 db db                 	vpand	%ymm3, %ymm11, %ymm11
100002847: c5 25 ef dc                 	vpxor	%ymm4, %ymm11, %ymm11
10000284b: c5 25 f8 dc                 	vpsubb	%ymm4, %ymm11, %ymm11
10000284f: c4 c1 1d 71 d4 02           	vpsrlw	$2, %ymm12, %ymm12
100002855: c5 1d db e3                 	vpand	%ymm3, %ymm12, %ymm12
100002859: c5 1d ef e4                 	vpxor	%ymm4, %ymm12, %ymm12
10000285d: c5 1d f8 e4                 	vpsubb	%ymm4, %ymm12, %ymm12
100002861: c4 c1 15 71 d5 02           	vpsrlw	$2, %ymm13, %ymm13
100002867: c5 15 db eb                 	vpand	%ymm3, %ymm13, %ymm13
10000286b: c5 15 ef ec                 	vpxor	%ymm4, %ymm13, %ymm13
10000286f: c5 15 f8 ec                 	vpsubb	%ymm4, %ymm13, %ymm13
100002873: c5 2d db d5                 	vpand	%ymm5, %ymm10, %ymm10
100002877: c5 25 db dd                 	vpand	%ymm5, %ymm11, %ymm11
10000287b: c5 1d db e5                 	vpand	%ymm5, %ymm12, %ymm12
10000287f: c5 15 db ed                 	vpand	%ymm5, %ymm13, %ymm13
100002883: c5 ad fc f6                 	vpaddb	%ymm6, %ymm10, %ymm6
100002887: c5 a5 fc ff                 	vpaddb	%ymm7, %ymm11, %ymm7
10000288b: c4 41 1d fc c0              	vpaddb	%ymm8, %ymm12, %ymm8
100002890: c4 41 15 fc c9              	vpaddb	%ymm9, %ymm13, %ymm9
100002895: c5 fe 7f 34 0f              	vmovdqu	%ymm6, (%rdi,%rcx)
10000289a: c5 fe 7f 7c 0f 20           	vmovdqu	%ymm7, 32(%rdi,%rcx)
1000028a0: c5 7e 7f 44 0f 40           	vmovdqu	%ymm8, 64(%rdi,%rcx)
1000028a6: c5 7e 7f 4c 0f 60           	vmovdqu	%ymm9, 96(%rdi,%rcx)
1000028ac: 48 83 e9 80                 	subq	$-128, %rcx
1000028b0: 49 39 c8                    	cmpq	%rcx, %r8
1000028b3: 0f 85 17 ff ff ff           	jne	-233 <_naive_to_upper+0x60>
1000028b9: 49 39 f0                    	cmpq	%rsi, %r8
1000028bc: 74 29                       	je	41 <_naive_to_upper+0x177>
1000028be: 66 90                       	nop
1000028c0: 42 0f b6 0c 07              	movzbl	(%rdi,%r8), %ecx
1000028c5: 8d 51 05                    	leal	5(%rcx), %edx
1000028c8: 80 e2 7f                    	andb	$127, %dl
1000028cb: 80 c2 1a                    	addb	$26, %dl
1000028ce: 89 c8                       	movl	%ecx, %eax
1000028d0: f6 d0                       	notb	%al
1000028d2: 20 d0                       	andb	%dl, %al
1000028d4: c0 f8 02                    	sarb	$2, %al
1000028d7: 24 e0                       	andb	$-32, %al
1000028d9: 00 c8                       	addb	%cl, %al
1000028db: 42 88 04 07                 	movb	%al, (%rdi,%r8)
1000028df: 49 ff c0                    	incq	%r8
1000028e2: 4c 39 c6                    	cmpq	%r8, %rsi
1000028e5: 75 d9                       	jne	-39 <_naive_to_upper+0x150>
1000028e7: 5d                          	popq	%rbp
1000028e8: c5 f8 77                    	vzeroupper
1000028eb: c3                          	retq
1000028ec: 0f 1f 40 00                 	nopl	(%rax)

00000001000028f0 _naive_to_lower:
1000028f0: 55                          	pushq	%rbp
1000028f1: 48 89 e5                    	movq	%rsp, %rbp
1000028f4: 48 85 f6                    	testq	%rsi, %rsi
1000028f7: 0f 84 2a 01 00 00           	je	298 <_naive_to_lower+0x137>
1000028fd: 48 83 fe 7f                 	cmpq	$127, %rsi
100002901: 77 08                       	ja	8 <_naive_to_lower+0x1b>
100002903: 45 31 c0                    	xorl	%r8d, %r8d
100002906: e9 f5 00 00 00              	jmp	245 <_naive_to_lower+0x110>
10000290b: 49 89 f0                    	movq	%rsi, %r8
10000290e: 49 83 e0 80                 	andq	$-128, %r8
100002912: 31 c9                       	xorl	%ecx, %ecx
100002914: c5 fd 6f 05 44 15 00 00     	vmovdqa	5444(%rip), %ymm0
10000291c: c5 fd 6f 0d 5c 15 00 00     	vmovdqa	5468(%rip), %ymm1
100002924: c5 fd 6f 15 74 15 00 00     	vmovdqa	5492(%rip), %ymm2
10000292c: c5 fd 6f 1d 8c 15 00 00     	vmovdqa	5516(%rip), %ymm3
100002934: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000293e: 66 90                       	nop
100002940: c5 fe 6f 24 0f              	vmovdqu	(%rdi,%rcx), %ymm4
100002945: c5 fe 6f 6c 0f 20           	vmovdqu	32(%rdi,%rcx), %ymm5
10000294b: c5 fe 6f 74 0f 40           	vmovdqu	64(%rdi,%rcx), %ymm6
100002951: c5 fe 6f 7c 0f 60           	vmovdqu	96(%rdi,%rcx), %ymm7
100002957: c5 5d fc c0                 	vpaddb	%ymm0, %ymm4, %ymm8
10000295b: c5 55 fc c8                 	vpaddb	%ymm0, %ymm5, %ymm9
10000295f: c5 4d fc d0                 	vpaddb	%ymm0, %ymm6, %ymm10
100002963: c5 45 fc d8                 	vpaddb	%ymm0, %ymm7, %ymm11
100002967: c5 3d db c1                 	vpand	%ymm1, %ymm8, %ymm8
10000296b: c5 35 db c9                 	vpand	%ymm1, %ymm9, %ymm9
10000296f: c5 2d db d1                 	vpand	%ymm1, %ymm10, %ymm10
100002973: c5 25 db d9                 	vpand	%ymm1, %ymm11, %ymm11
100002977: c5 3d fc c2                 	vpaddb	%ymm2, %ymm8, %ymm8
10000297b: c5 35 fc ca                 	vpaddb	%ymm2, %ymm9, %ymm9
10000297f: c5 2d fc d2                 	vpaddb	%ymm2, %ymm10, %ymm10
100002983: c5 25 fc da                 	vpaddb	%ymm2, %ymm11, %ymm11
100002987: c4 41 5d df c0              	vpandn	%ymm8, %ymm4, %ymm8
10000298c: c4 41 55 df c9              	vpandn	%ymm9, %ymm5, %ymm9
100002991: c4 41 4d df d2              	vpandn	%ymm10, %ymm6, %ymm10
100002996: c4 41 45 df db              	vpandn	%ymm11, %ymm7, %ymm11
10000299b: c4 c1 3d 71 d0 02           	vpsrlw	$2, %ymm8, %ymm8
1000029a1: c4 c1 35 71 d1 02           	vpsrlw	$2, %ymm9, %ymm9
1000029a7: c4 c1 2d 71 d2 02           	vpsrlw	$2, %ymm10, %ymm10
1000029ad: c4 c1 25 71 d3 02           	vpsrlw	$2, %ymm11, %ymm11
1000029b3: c5 3d db c3                 	vpand	%ymm3, %ymm8, %ymm8
1000029b7: c5 35 db cb                 	vpand	%ymm3, %ymm9, %ymm9
1000029bb: c5 2d db d3                 	vpand	%ymm3, %ymm10, %ymm10
1000029bf: c5 25 db db                 	vpand	%ymm3, %ymm11, %ymm11
1000029c3: c5 bd fc e4                 	vpaddb	%ymm4, %ymm8, %ymm4
1000029c7: c5 b5 fc ed                 	vpaddb	%ymm5, %ymm9, %ymm5
1000029cb: c5 ad fc f6                 	vpaddb	%ymm6, %ymm10, %ymm6
1000029cf: c5 a5 fc ff                 	vpaddb	%ymm7, %ymm11, %ymm7
1000029d3: c5 fe 7f 24 0f              	vmovdqu	%ymm4, (%rdi,%rcx)
1000029d8: c5 fe 7f 6c 0f 20           	vmovdqu	%ymm5, 32(%rdi,%rcx)
1000029de: c5 fe 7f 74 0f 40           	vmovdqu	%ymm6, 64(%rdi,%rcx)
1000029e4: c5 fe 7f 7c 0f 60           	vmovdqu	%ymm7, 96(%rdi,%rcx)
1000029ea: 48 83 e9 80                 	subq	$-128, %rcx
1000029ee: 49 39 c8                    	cmpq	%rcx, %r8
1000029f1: 0f 85 49 ff ff ff           	jne	-183 <_naive_to_lower+0x50>
1000029f7: 49 39 f0                    	cmpq	%rsi, %r8
1000029fa: 74 2b                       	je	43 <_naive_to_lower+0x137>
1000029fc: 0f 1f 40 00                 	nopl	(%rax)
100002a00: 42 0f b6 0c 07              	movzbl	(%rdi,%r8), %ecx
100002a05: 8d 51 25                    	leal	37(%rcx), %edx
100002a08: 80 e2 7f                    	andb	$127, %dl
100002a0b: 80 c2 1a                    	addb	$26, %dl
100002a0e: 89 c8                       	movl	%ecx, %eax
100002a10: f6 d0                       	notb	%al
100002a12: 20 d0                       	andb	%dl, %al
100002a14: c0 e8 02                    	shrb	$2, %al
100002a17: 24 20                       	andb	$32, %al
100002a19: 00 c8                       	addb	%cl, %al
100002a1b: 42 88 04 07                 	movb	%al, (%rdi,%r8)
100002a1f: 49 ff c0                    	incq	%r8
100002a22: 4c 39 c6                    	cmpq	%r8, %rsi
100002a25: 75 d9                       	jne	-39 <_naive_to_lower+0x110>
100002a27: 5d                          	popq	%rbp
100002a28: c5 f8 77                    	vzeroupper
100002a2b: c3                          	retq
100002a2c: 0f 1f 40 00                 	nopl	(%rax)

0000000100002a30 _calc_avg_times_upper:
100002a30: 55                          	pushq	%rbp
100002a31: 48 89 e5                    	movq	%rsp, %rbp
100002a34: 41 57                       	pushq	%r15
100002a36: 41 56                       	pushq	%r14
100002a38: 41 55                       	pushq	%r13
100002a3a: 41 54                       	pushq	%r12
100002a3c: 53                          	pushq	%rbx
100002a3d: 48 81 ec 98 00 00 00        	subq	$152, %rsp
100002a44: 4c 89 cb                    	movq	%r9, %rbx
100002a47: 44 89 45 b8                 	movl	%r8d, -72(%rbp)
100002a4b: 48 89 8d 40 ff ff ff        	movq	%rcx, -192(%rbp)
100002a52: 48 89 95 48 ff ff ff        	movq	%rdx, -184(%rbp)
100002a59: 41 89 f7                    	movl	%esi, %r15d
100002a5c: 49 89 fd                    	movq	%rdi, %r13
100002a5f: 4d 8d 24 39                 	leaq	(%r9,%rdi), %r12
100002a63: 49 ff c4                    	incq	%r12
100002a66: 48 ff c3                    	incq	%rbx
100002a69: 4c 89 e7                    	movq	%r12, %rdi
100002a6c: e8 59 12 00 00              	callq	4697 <dyld_stub_binder+0x100003cca>
100002a71: 49 89 c6                    	movq	%rax, %r14
100002a74: 4c 89 e7                    	movq	%r12, %rdi
100002a77: e8 4e 12 00 00              	callq	4686 <dyld_stub_binder+0x100003cca>
100002a7c: 48 89 45 a8                 	movq	%rax, -88(%rbp)
100002a80: 4c 89 e7                    	movq	%r12, %rdi
100002a83: e8 42 12 00 00              	callq	4674 <dyld_stub_binder+0x100003cca>
100002a88: 48 89 45 98                 	movq	%rax, -104(%rbp)
100002a8c: 44 89 7d bc                 	movl	%r15d, -68(%rbp)
100002a90: 41 d1 ef                    	shrl	%r15d
100002a93: 44 89 7d b0                 	movl	%r15d, -80(%rbp)
100002a97: 48 89 9d 50 ff ff ff        	movq	%rbx, -176(%rbp)
100002a9e: 0f 84 b0 01 00 00           	je	432 <_calc_avg_times_upper+0x224>
100002aa4: 45 31 ff                    	xorl	%r15d, %r15d
100002aa7: 4d 85 ed                    	testq	%r13, %r13
100002aaa: 0f 84 6b 05 00 00           	je	1387 <_calc_avg_times_upper+0x5eb>
100002ab0: 31 c9                       	xorl	%ecx, %ecx
100002ab2: 31 c0                       	xorl	%eax, %eax
100002ab4: eb 37                       	jmp	55 <_calc_avg_times_upper+0xbd>
100002ab6: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002ac0: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100002ac7: 4c 8b 7d c8                 	movq	-56(%rbp), %r15
100002acb: 49 01 c7                    	addq	%rax, %r15
100002ace: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002ad5: 48 01 c1                    	addq	%rax, %rcx
100002ad8: 8b 45 a4                    	movl	-92(%rbp), %eax
100002adb: ff c0                       	incl	%eax
100002add: 3b 45 b0                    	cmpl	-80(%rbp), %eax
100002ae0: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100002ae7: 0f 84 6c 01 00 00           	je	364 <_calc_avg_times_upper+0x229>
100002aed: 4c 89 7d c8                 	movq	%r15, -56(%rbp)
100002af1: 89 45 a4                    	movl	%eax, -92(%rbp)
100002af4: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002af8: e8 e5 11 00 00              	callq	4581 <dyld_stub_binder+0x100003ce2>
100002afd: 48 63 c8                    	movslq	%eax, %rcx
100002b00: 48 89 ca                    	movq	%rcx, %rdx
100002b03: 48 09 da                    	orq	%rbx, %rdx
100002b06: 48 c1 ea 20                 	shrq	$32, %rdx
100002b0a: 74 14                       	je	20 <_calc_avg_times_upper+0xf0>
100002b0c: 48 89 c8                    	movq	%rcx, %rax
100002b0f: 31 d2                       	xorl	%edx, %edx
100002b11: 48 f7 f3                    	divq	%rbx
100002b14: 49 89 d7                    	movq	%rdx, %r15
100002b17: eb 0e                       	jmp	14 <_calc_avg_times_upper+0xf7>
100002b19: 0f 1f 80 00 00 00 00        	nopl	(%rax)
100002b20: 31 d2                       	xorl	%edx, %edx
100002b22: f7 f3                       	divl	%ebx
100002b24: 41 89 d7                    	movl	%edx, %r15d
100002b27: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002b2b: 4c 01 f8                    	addq	%r15, %rax
100002b2e: 48 89 45 c0                 	movq	%rax, -64(%rbp)
100002b32: 45 31 e4                    	xorl	%r12d, %r12d
100002b35: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002b3f: 90                          	nop
100002b40: e8 9d 11 00 00              	callq	4509 <dyld_stub_binder+0x100003ce2>
100002b45: 48 98                       	cltq
100002b47: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
100002b4e: 48 c1 e9 20                 	shrq	$32, %rcx
100002b52: 01 c1                       	addl	%eax, %ecx
100002b54: 89 ca                       	movl	%ecx, %edx
100002b56: c1 ea 1f                    	shrl	$31, %edx
100002b59: c1 e9 06                    	shrl	$6, %ecx
100002b5c: 01 d1                       	addl	%edx, %ecx
100002b5e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002b61: 29 c8                       	subl	%ecx, %eax
100002b63: 04 20                       	addb	$32, %al
100002b65: 43 88 04 26                 	movb	%al, (%r14,%r12)
100002b69: 49 ff c4                    	incq	%r12
100002b6c: 4d 39 e5                    	cmpq	%r12, %r13
100002b6f: 75 cf                       	jne	-49 <_calc_avg_times_upper+0x110>
100002b71: 4c 03 7d 98                 	addq	-104(%rbp), %r15
100002b75: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002b7a: 48 8b 5d c0                 	movq	-64(%rbp), %rbx
100002b7e: 48 89 df                    	movq	%rbx, %rdi
100002b81: 4c 89 f6                    	movq	%r14, %rsi
100002b84: e8 6b 11 00 00              	callq	4459 <dyld_stub_binder+0x100003cf4>
100002b89: 4c 89 ff                    	movq	%r15, %rdi
100002b8c: 4c 89 f6                    	movq	%r14, %rsi
100002b8f: e8 60 11 00 00              	callq	4448 <dyld_stub_binder+0x100003cf4>
100002b94: bf 06 00 00 00              	movl	$6, %edi
100002b99: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002ba0: e8 19 11 00 00              	callq	4377 <dyld_stub_binder+0x100003cbe>
100002ba5: 48 89 df                    	movq	%rbx, %rdi
100002ba8: 4c 89 ee                    	movq	%r13, %rsi
100002bab: e8 c0 fb ff ff              	callq	-1088 <_naive_to_upper>
100002bb0: bf 06 00 00 00              	movl	$6, %edi
100002bb5: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002bbc: e8 fd 10 00 00              	callq	4349 <dyld_stub_binder+0x100003cbe>
100002bc1: bf 06 00 00 00              	movl	$6, %edi
100002bc6: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002bcd: e8 ec 10 00 00              	callq	4332 <dyld_stub_binder+0x100003cbe>
100002bd2: 4c 89 ff                    	movq	%r15, %rdi
100002bd5: 4c 89 ee                    	movq	%r13, %rsi
100002bd8: e8 83 0f 00 00              	callq	3971 <_to_upper>
100002bdd: bf 06 00 00 00              	movl	$6, %edi
100002be2: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002be6: e8 d3 10 00 00              	callq	4307 <dyld_stub_binder+0x100003cbe>
100002beb: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100002bf2: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100002bf9: 48 8b 45 c8                 	movq	-56(%rbp), %rax
100002bfd: 48 03 85 70 ff ff ff        	addq	-144(%rbp), %rax
100002c04: 48 2b 85 60 ff ff ff        	subq	-160(%rbp), %rax
100002c0b: 48 89 45 c8                 	movq	%rax, -56(%rbp)
100002c0f: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002c13: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002c1a: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002c1e: 48 03 4d 90                 	addq	-112(%rbp), %rcx
100002c22: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
100002c26: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
100002c2a: 0f 84 90 fe ff ff           	je	-368 <_calc_avg_times_upper+0x90>
100002c30: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100002c34: 4c 89 fe                    	movq	%r15, %rsi
100002c37: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002c3b: e8 ae 10 00 00              	callq	4270 <dyld_stub_binder+0x100003cee>
100002c40: 4c 89 fa                    	movq	%r15, %rdx
100002c43: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002c47: 85 c0                       	testl	%eax, %eax
100002c49: 0f 84 71 fe ff ff           	je	-399 <_calc_avg_times_upper+0x90>
100002c4f: e9 27 05 00 00              	jmp	1319 <_calc_avg_times_upper+0x74b>
100002c54: 31 c9                       	xorl	%ecx, %ecx
100002c56: 45 31 ff                    	xorl	%r15d, %r15d
100002c59: 8b 45 b0                    	movl	-80(%rbp), %eax
100002c5c: 3b 45 bc                    	cmpl	-68(%rbp), %eax
100002c5f: 0f 83 1e 03 00 00           	jae	798 <_calc_avg_times_upper+0x553>
100002c65: 4d 85 ed                    	testq	%r13, %r13
100002c68: 75 42                       	jne	66 <_calc_avg_times_upper+0x27c>
100002c6a: 8b 45 bc                    	movl	-68(%rbp), %eax
100002c6d: 2b 45 b0                    	subl	-80(%rbp), %eax
100002c70: e9 d1 01 00 00              	jmp	465 <_calc_avg_times_upper+0x416>
100002c75: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002c7f: 90                          	nop
100002c80: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100002c87: 49 01 c7                    	addq	%rax, %r15
100002c8a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002c91: 48 01 c1                    	addq	%rax, %rcx
100002c94: 8b 45 b0                    	movl	-80(%rbp), %eax
100002c97: ff c0                       	incl	%eax
100002c99: 89 45 b0                    	movl	%eax, -80(%rbp)
100002c9c: 3b 45 bc                    	cmpl	-68(%rbp), %eax
100002c9f: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100002ca6: 0f 84 d7 02 00 00           	je	727 <_calc_avg_times_upper+0x553>
100002cac: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002cb0: e8 2d 10 00 00              	callq	4141 <dyld_stub_binder+0x100003ce2>
100002cb5: 48 63 c8                    	movslq	%eax, %rcx
100002cb8: 48 89 ca                    	movq	%rcx, %rdx
100002cbb: 48 09 da                    	orq	%rbx, %rdx
100002cbe: 48 c1 ea 20                 	shrq	$32, %rdx
100002cc2: 74 1c                       	je	28 <_calc_avg_times_upper+0x2b0>
100002cc4: 48 89 c8                    	movq	%rcx, %rax
100002cc7: 31 d2                       	xorl	%edx, %edx
100002cc9: 48 f7 f3                    	divq	%rbx
100002ccc: 48 89 d3                    	movq	%rdx, %rbx
100002ccf: eb 15                       	jmp	21 <_calc_avg_times_upper+0x2b6>
100002cd1: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002cdb: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100002ce0: 31 d2                       	xorl	%edx, %edx
100002ce2: f7 f3                       	divl	%ebx
100002ce4: 89 d3                       	movl	%edx, %ebx
100002ce6: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002cea: 48 01 d8                    	addq	%rbx, %rax
100002ced: 48 89 45 c8                 	movq	%rax, -56(%rbp)
100002cf1: 45 31 e4                    	xorl	%r12d, %r12d
100002cf4: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002cfe: 66 90                       	nop
100002d00: e8 dd 0f 00 00              	callq	4061 <dyld_stub_binder+0x100003ce2>
100002d05: 48 98                       	cltq
100002d07: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
100002d0e: 48 c1 e9 20                 	shrq	$32, %rcx
100002d12: 01 c1                       	addl	%eax, %ecx
100002d14: 89 ca                       	movl	%ecx, %edx
100002d16: c1 ea 1f                    	shrl	$31, %edx
100002d19: c1 e9 06                    	shrl	$6, %ecx
100002d1c: 01 d1                       	addl	%edx, %ecx
100002d1e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002d21: 29 c8                       	subl	%ecx, %eax
100002d23: 04 20                       	addb	$32, %al
100002d25: 43 88 04 26                 	movb	%al, (%r14,%r12)
100002d29: 49 ff c4                    	incq	%r12
100002d2c: 4d 39 e5                    	cmpq	%r12, %r13
100002d2f: 75 cf                       	jne	-49 <_calc_avg_times_upper+0x2d0>
100002d31: 48 03 5d 98                 	addq	-104(%rbp), %rbx
100002d35: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002d3a: 49 89 dc                    	movq	%rbx, %r12
100002d3d: 48 8b 5d c8                 	movq	-56(%rbp), %rbx
100002d41: 48 89 df                    	movq	%rbx, %rdi
100002d44: 4c 89 f6                    	movq	%r14, %rsi
100002d47: e8 a8 0f 00 00              	callq	4008 <dyld_stub_binder+0x100003cf4>
100002d4c: 4c 89 e7                    	movq	%r12, %rdi
100002d4f: 4c 89 f6                    	movq	%r14, %rsi
100002d52: e8 9d 0f 00 00              	callq	3997 <dyld_stub_binder+0x100003cf4>
100002d57: bf 06 00 00 00              	movl	$6, %edi
100002d5c: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002d63: e8 56 0f 00 00              	callq	3926 <dyld_stub_binder+0x100003cbe>
100002d68: 48 89 df                    	movq	%rbx, %rdi
100002d6b: 4c 89 ee                    	movq	%r13, %rsi
100002d6e: e8 ed 0d 00 00              	callq	3565 <_to_upper>
100002d73: bf 06 00 00 00              	movl	$6, %edi
100002d78: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002d7c: e8 3d 0f 00 00              	callq	3901 <dyld_stub_binder+0x100003cbe>
100002d81: bf 06 00 00 00              	movl	$6, %edi
100002d86: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002d8d: e8 2c 0f 00 00              	callq	3884 <dyld_stub_binder+0x100003cbe>
100002d92: 4c 89 e3                    	movq	%r12, %rbx
100002d95: 4c 89 e7                    	movq	%r12, %rdi
100002d98: 4c 89 ee                    	movq	%r13, %rsi
100002d9b: e8 d0 f9 ff ff              	callq	-1584 <_naive_to_upper>
100002da0: bf 06 00 00 00              	movl	$6, %edi
100002da5: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002dac: e8 0d 0f 00 00              	callq	3853 <dyld_stub_binder+0x100003cbe>
100002db1: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100002db8: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100002dbf: 4c 03 bd 70 ff ff ff        	addq	-144(%rbp), %r15
100002dc6: 4c 2b bd 60 ff ff ff        	subq	-160(%rbp), %r15
100002dcd: 48 89 d8                    	movq	%rbx, %rax
100002dd0: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002dd4: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002ddb: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002ddf: 48 03 4d 90                 	addq	-112(%rbp), %rcx
100002de3: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
100002de7: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
100002deb: 0f 84 8f fe ff ff           	je	-369 <_calc_avg_times_upper+0x250>
100002df1: 48 8b 7d c8                 	movq	-56(%rbp), %rdi
100002df5: 48 89 45 c0                 	movq	%rax, -64(%rbp)
100002df9: 48 8b 75 c0                 	movq	-64(%rbp), %rsi
100002dfd: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002e01: e8 e8 0e 00 00              	callq	3816 <dyld_stub_binder+0x100003cee>
100002e06: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
100002e0a: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002e0e: 85 c0                       	testl	%eax, %eax
100002e10: 0f 84 6a fe ff ff           	je	-406 <_calc_avg_times_upper+0x250>
100002e16: e9 40 01 00 00              	jmp	320 <_calc_avg_times_upper+0x52b>
100002e1b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100002e20: 48 69 c0 00 ca 9a 3b        	imulq	$1000000000, %rax, %rax
100002e27: 49 01 c7                    	addq	%rax, %r15
100002e2a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002e31: 48 01 c1                    	addq	%rax, %rcx
100002e34: 8b 45 c0                    	movl	-64(%rbp), %eax
100002e37: ff c8                       	decl	%eax
100002e39: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100002e40: 0f 84 3d 01 00 00           	je	317 <_calc_avg_times_upper+0x553>
100002e46: 89 45 c0                    	movl	%eax, -64(%rbp)
100002e49: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002e4d: e8 90 0e 00 00              	callq	3728 <dyld_stub_binder+0x100003ce2>
100002e52: 48 63 c8                    	movslq	%eax, %rcx
100002e55: 48 89 ca                    	movq	%rcx, %rdx
100002e58: 48 09 da                    	orq	%rbx, %rdx
100002e5b: 48 c1 ea 20                 	shrq	$32, %rdx
100002e5f: 74 0f                       	je	15 <_calc_avg_times_upper+0x440>
100002e61: 48 89 c8                    	movq	%rcx, %rax
100002e64: 31 d2                       	xorl	%edx, %edx
100002e66: 48 f7 f3                    	divq	%rbx
100002e69: 49 89 d4                    	movq	%rdx, %r12
100002e6c: eb 09                       	jmp	9 <_calc_avg_times_upper+0x447>
100002e6e: 66 90                       	nop
100002e70: 31 d2                       	xorl	%edx, %edx
100002e72: f7 f3                       	divl	%ebx
100002e74: 41 89 d4                    	movl	%edx, %r12d
100002e77: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002e7b: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
100002e7f: 4c 03 65 98                 	addq	-104(%rbp), %r12
100002e83: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002e88: 48 89 df                    	movq	%rbx, %rdi
100002e8b: 4c 89 f6                    	movq	%r14, %rsi
100002e8e: e8 61 0e 00 00              	callq	3681 <dyld_stub_binder+0x100003cf4>
100002e93: 4c 89 e7                    	movq	%r12, %rdi
100002e96: 4c 89 f6                    	movq	%r14, %rsi
100002e99: e8 56 0e 00 00              	callq	3670 <dyld_stub_binder+0x100003cf4>
100002e9e: bf 06 00 00 00              	movl	$6, %edi
100002ea3: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002eaa: e8 0f 0e 00 00              	callq	3599 <dyld_stub_binder+0x100003cbe>
100002eaf: 48 89 5d c8                 	movq	%rbx, -56(%rbp)
100002eb3: 48 89 df                    	movq	%rbx, %rdi
100002eb6: 31 f6                       	xorl	%esi, %esi
100002eb8: e8 a3 0c 00 00              	callq	3235 <_to_upper>
100002ebd: bf 06 00 00 00              	movl	$6, %edi
100002ec2: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002ec6: e8 f3 0d 00 00              	callq	3571 <dyld_stub_binder+0x100003cbe>
100002ecb: bf 06 00 00 00              	movl	$6, %edi
100002ed0: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002ed7: e8 e2 0d 00 00              	callq	3554 <dyld_stub_binder+0x100003cbe>
100002edc: 4c 89 e7                    	movq	%r12, %rdi
100002edf: 31 f6                       	xorl	%esi, %esi
100002ee1: e8 8a f8 ff ff              	callq	-1910 <_naive_to_upper>
100002ee6: bf 06 00 00 00              	movl	$6, %edi
100002eeb: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002ef2: e8 c7 0d 00 00              	callq	3527 <dyld_stub_binder+0x100003cbe>
100002ef7: 48 8b 85 68 ff ff ff        	movq	-152(%rbp), %rax
100002efe: 48 2b 85 58 ff ff ff        	subq	-168(%rbp), %rax
100002f05: 4c 03 bd 70 ff ff ff        	addq	-144(%rbp), %r15
100002f0c: 4c 2b bd 60 ff ff ff        	subq	-160(%rbp), %r15
100002f13: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002f17: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002f1e: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002f22: 48 03 4d 90                 	addq	-112(%rbp), %rcx
100002f26: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
100002f2a: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
100002f2e: 0f 84 ec fe ff ff           	je	-276 <_calc_avg_times_upper+0x3f0>
100002f34: 48 8b 7d c8                 	movq	-56(%rbp), %rdi
100002f38: 4c 89 e6                    	movq	%r12, %rsi
100002f3b: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100002f3f: 48 89 45 b0                 	movq	%rax, -80(%rbp)
100002f43: e8 a6 0d 00 00              	callq	3494 <dyld_stub_binder+0x100003cee>
100002f48: 4c 89 e2                    	movq	%r12, %rdx
100002f4b: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100002f4f: 85 c0                       	testl	%eax, %eax
100002f51: 48 8b 45 b0                 	movq	-80(%rbp), %rax
100002f55: 0f 84 c5 fe ff ff           	je	-315 <_calc_avg_times_upper+0x3f0>
100002f5b: 48 8d 3d a6 0f 00 00        	leaq	4006(%rip), %rdi
100002f62: 48 89 d3                    	movq	%rdx, %rbx
100002f65: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
100002f69: 4c 89 f2                    	movq	%r14, %rdx
100002f6c: 31 c0                       	xorl	%eax, %eax
100002f6e: e8 5d 0d 00 00              	callq	3421 <dyld_stub_binder+0x100003cd0>
100002f73: 48 8d 3d 9e 0f 00 00        	leaq	3998(%rip), %rdi
100002f7a: 48 8b 55 c8                 	movq	-56(%rbp), %rdx
100002f7e: e9 1b 02 00 00              	jmp	539 <_calc_avg_times_upper+0x76e>
100002f83: c4 c1 f9 6e c7              	vmovq	%r15, %xmm0
100002f88: c5 f9 6f 0d 50 0f 00 00     	vmovdqa	3920(%rip), %xmm1
100002f90: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100002f94: c5 f9 28 15 54 0f 00 00     	vmovapd	3924(%rip), %xmm2
100002f9c: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100002fa0: c4 e3 79 05 d8 01           	vpermilpd	$1, %xmm0, %xmm3
100002fa6: 8b 45 bc                    	movl	-68(%rbp), %eax
100002fa9: c4 e1 db 2a e0              	vcvtsi2sd	%rax, %xmm4, %xmm4
100002fae: c5 e3 58 c0                 	vaddsd	%xmm0, %xmm3, %xmm0
100002fb2: c5 db 59 1d 46 0f 00 00     	vmulsd	3910(%rip), %xmm4, %xmm3
100002fba: c5 fb 5e c3                 	vdivsd	%xmm3, %xmm0, %xmm0
100002fbe: c5 fb 5a c0                 	vcvtsd2ss	%xmm0, %xmm0, %xmm0
100002fc2: 48 8b 85 48 ff ff ff        	movq	-184(%rbp), %rax
100002fc9: c5 fa 11 00                 	vmovss	%xmm0, (%rax)
100002fcd: c4 e1 f9 6e c1              	vmovq	%rcx, %xmm0
100002fd2: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100002fd6: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100002fda: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100002fe0: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100002fe4: c5 fb 5e c3                 	vdivsd	%xmm3, %xmm0, %xmm0
100002fe8: c5 fb 5a c0                 	vcvtsd2ss	%xmm0, %xmm0, %xmm0
100002fec: 48 8b 85 40 ff ff ff        	movq	-192(%rbp), %rax
100002ff3: c5 fa 11 00                 	vmovss	%xmm0, (%rax)
100002ff7: 48 8b 7d a8                 	movq	-88(%rbp), %rdi
100002ffb: e8 c4 0c 00 00              	callq	3268 <dyld_stub_binder+0x100003cc4>
100003000: 48 8b 7d 98                 	movq	-104(%rbp), %rdi
100003004: e8 bb 0c 00 00              	callq	3259 <dyld_stub_binder+0x100003cc4>
100003009: 48 81 c4 98 00 00 00        	addq	$152, %rsp
100003010: 5b                          	popq	%rbx
100003011: 41 5c                       	popq	%r12
100003013: 41 5d                       	popq	%r13
100003015: 41 5e                       	popq	%r14
100003017: 41 5f                       	popq	%r15
100003019: 5d                          	popq	%rbp
10000301a: c3                          	retq
10000301b: 8b 45 b0                    	movl	-80(%rbp), %eax
10000301e: 31 c9                       	xorl	%ecx, %ecx
100003020: eb 38                       	jmp	56 <_calc_avg_times_upper+0x62a>
100003022: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000302c: 0f 1f 40 00                 	nopl	(%rax)
100003030: 49 69 c7 00 ca 9a 3b        	imulq	$1000000000, %r15, %rax
100003037: 4c 8b 7d c8                 	movq	-56(%rbp), %r15
10000303b: 49 01 c7                    	addq	%rax, %r15
10000303e: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100003045: 48 01 c1                    	addq	%rax, %rcx
100003048: 8b 45 a4                    	movl	-92(%rbp), %eax
10000304b: ff c8                       	decl	%eax
10000304d: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100003054: 0f 84 ff fb ff ff           	je	-1025 <_calc_avg_times_upper+0x229>
10000305a: 89 45 a4                    	movl	%eax, -92(%rbp)
10000305d: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003061: e8 7c 0c 00 00              	callq	3196 <dyld_stub_binder+0x100003ce2>
100003066: 48 63 c8                    	movslq	%eax, %rcx
100003069: 48 89 ca                    	movq	%rcx, %rdx
10000306c: 48 09 da                    	orq	%rbx, %rdx
10000306f: 48 c1 ea 20                 	shrq	$32, %rdx
100003073: 4c 89 7d c8                 	movq	%r15, -56(%rbp)
100003077: 74 17                       	je	23 <_calc_avg_times_upper+0x660>
100003079: 48 89 c8                    	movq	%rcx, %rax
10000307c: 31 d2                       	xorl	%edx, %edx
10000307e: 48 f7 f3                    	divq	%rbx
100003081: 49 89 d4                    	movq	%rdx, %r12
100003084: eb 11                       	jmp	17 <_calc_avg_times_upper+0x667>
100003086: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100003090: 31 d2                       	xorl	%edx, %edx
100003092: f7 f3                       	divl	%ebx
100003094: 41 89 d4                    	movl	%edx, %r12d
100003097: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000309b: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
10000309f: 4c 03 65 98                 	addq	-104(%rbp), %r12
1000030a3: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
1000030a8: 48 89 df                    	movq	%rbx, %rdi
1000030ab: 4c 89 f6                    	movq	%r14, %rsi
1000030ae: e8 41 0c 00 00              	callq	3137 <dyld_stub_binder+0x100003cf4>
1000030b3: 4c 89 e7                    	movq	%r12, %rdi
1000030b6: 4c 89 f6                    	movq	%r14, %rsi
1000030b9: e8 36 0c 00 00              	callq	3126 <dyld_stub_binder+0x100003cf4>
1000030be: bf 06 00 00 00              	movl	$6, %edi
1000030c3: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
1000030ca: e8 ef 0b 00 00              	callq	3055 <dyld_stub_binder+0x100003cbe>
1000030cf: 48 89 5d c0                 	movq	%rbx, -64(%rbp)
1000030d3: 48 89 df                    	movq	%rbx, %rdi
1000030d6: 31 f6                       	xorl	%esi, %esi
1000030d8: e8 93 f6 ff ff              	callq	-2413 <_naive_to_upper>
1000030dd: bf 06 00 00 00              	movl	$6, %edi
1000030e2: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
1000030e9: e8 d0 0b 00 00              	callq	3024 <dyld_stub_binder+0x100003cbe>
1000030ee: bf 06 00 00 00              	movl	$6, %edi
1000030f3: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
1000030fa: e8 bf 0b 00 00              	callq	3007 <dyld_stub_binder+0x100003cbe>
1000030ff: 4c 89 e7                    	movq	%r12, %rdi
100003102: 31 f6                       	xorl	%esi, %esi
100003104: e8 57 0a 00 00              	callq	2647 <_to_upper>
100003109: bf 06 00 00 00              	movl	$6, %edi
10000310e: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003112: e8 a7 0b 00 00              	callq	2983 <dyld_stub_binder+0x100003cbe>
100003117: 4c 8b bd 68 ff ff ff        	movq	-152(%rbp), %r15
10000311e: 4c 2b bd 58 ff ff ff        	subq	-168(%rbp), %r15
100003125: 48 8b 45 c8                 	movq	-56(%rbp), %rax
100003129: 48 03 85 70 ff ff ff        	addq	-144(%rbp), %rax
100003130: 48 2b 85 60 ff ff ff        	subq	-160(%rbp), %rax
100003137: 48 89 45 c8                 	movq	%rax, -56(%rbp)
10000313b: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
10000313f: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100003146: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
10000314a: 48 03 4d 90                 	addq	-112(%rbp), %rcx
10000314e: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
100003152: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
100003156: 0f 84 d4 fe ff ff           	je	-300 <_calc_avg_times_upper+0x600>
10000315c: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100003160: 4c 89 e6                    	movq	%r12, %rsi
100003163: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003167: e8 82 0b 00 00              	callq	2946 <dyld_stub_binder+0x100003cee>
10000316c: 4c 89 e2                    	movq	%r12, %rdx
10000316f: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100003173: 85 c0                       	testl	%eax, %eax
100003175: 0f 84 b5 fe ff ff           	je	-331 <_calc_avg_times_upper+0x600>
10000317b: 48 8d 3d 86 0d 00 00        	leaq	3462(%rip), %rdi
100003182: 48 89 d3                    	movq	%rdx, %rbx
100003185: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
100003189: 4c 89 f2                    	movq	%r14, %rdx
10000318c: 31 c0                       	xorl	%eax, %eax
10000318e: e8 3d 0b 00 00              	callq	2877 <dyld_stub_binder+0x100003cd0>
100003193: 48 8d 3d 7e 0d 00 00        	leaq	3454(%rip), %rdi
10000319a: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
10000319e: 48 89 d6                    	movq	%rdx, %rsi
1000031a1: 31 c0                       	xorl	%eax, %eax
1000031a3: e8 28 0b 00 00              	callq	2856 <dyld_stub_binder+0x100003cd0>
1000031a8: 48 8d 3d 79 0d 00 00        	leaq	3449(%rip), %rdi
1000031af: 48 89 de                    	movq	%rbx, %rsi
1000031b2: 48 89 da                    	movq	%rbx, %rdx
1000031b5: 31 c0                       	xorl	%eax, %eax
1000031b7: e8 14 0b 00 00              	callq	2836 <dyld_stub_binder+0x100003cd0>
1000031bc: e8 f7 0a 00 00              	callq	2807 <dyld_stub_binder+0x100003cb8>
1000031c1: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000031cb: 0f 1f 44 00 00              	nopl	(%rax,%rax)

00000001000031d0 _calc_avg_times_lower:
1000031d0: 55                          	pushq	%rbp
1000031d1: 48 89 e5                    	movq	%rsp, %rbp
1000031d4: 41 57                       	pushq	%r15
1000031d6: 41 56                       	pushq	%r14
1000031d8: 41 55                       	pushq	%r13
1000031da: 41 54                       	pushq	%r12
1000031dc: 53                          	pushq	%rbx
1000031dd: 48 81 ec 98 00 00 00        	subq	$152, %rsp
1000031e4: 4c 89 cb                    	movq	%r9, %rbx
1000031e7: 44 89 45 b8                 	movl	%r8d, -72(%rbp)
1000031eb: 48 89 8d 40 ff ff ff        	movq	%rcx, -192(%rbp)
1000031f2: 48 89 95 48 ff ff ff        	movq	%rdx, -184(%rbp)
1000031f9: 41 89 f7                    	movl	%esi, %r15d
1000031fc: 49 89 fd                    	movq	%rdi, %r13
1000031ff: 4d 8d 24 39                 	leaq	(%r9,%rdi), %r12
100003203: 49 ff c4                    	incq	%r12
100003206: 48 ff c3                    	incq	%rbx
100003209: 4c 89 e7                    	movq	%r12, %rdi
10000320c: e8 b9 0a 00 00              	callq	2745 <dyld_stub_binder+0x100003cca>
100003211: 49 89 c6                    	movq	%rax, %r14
100003214: 4c 89 e7                    	movq	%r12, %rdi
100003217: e8 ae 0a 00 00              	callq	2734 <dyld_stub_binder+0x100003cca>
10000321c: 48 89 45 a8                 	movq	%rax, -88(%rbp)
100003220: 4c 89 e7                    	movq	%r12, %rdi
100003223: e8 a2 0a 00 00              	callq	2722 <dyld_stub_binder+0x100003cca>
100003228: 48 89 45 98                 	movq	%rax, -104(%rbp)
10000322c: 44 89 7d bc                 	movl	%r15d, -68(%rbp)
100003230: 41 d1 ef                    	shrl	%r15d
100003233: 44 89 7d b0                 	movl	%r15d, -80(%rbp)
100003237: 48 89 9d 50 ff ff ff        	movq	%rbx, -176(%rbp)
10000323e: 0f 84 b0 01 00 00           	je	432 <_calc_avg_times_lower+0x224>
100003244: 45 31 ff                    	xorl	%r15d, %r15d
100003247: 4d 85 ed                    	testq	%r13, %r13
10000324a: 0f 84 6b 05 00 00           	je	1387 <_calc_avg_times_lower+0x5eb>
100003250: 31 c9                       	xorl	%ecx, %ecx
100003252: 31 c0                       	xorl	%eax, %eax
100003254: eb 37                       	jmp	55 <_calc_avg_times_lower+0xbd>
100003256: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100003260: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100003267: 4c 8b 7d c8                 	movq	-56(%rbp), %r15
10000326b: 49 01 c7                    	addq	%rax, %r15
10000326e: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100003275: 48 01 c1                    	addq	%rax, %rcx
100003278: 8b 45 a4                    	movl	-92(%rbp), %eax
10000327b: ff c0                       	incl	%eax
10000327d: 3b 45 b0                    	cmpl	-80(%rbp), %eax
100003280: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100003287: 0f 84 6c 01 00 00           	je	364 <_calc_avg_times_lower+0x229>
10000328d: 4c 89 7d c8                 	movq	%r15, -56(%rbp)
100003291: 89 45 a4                    	movl	%eax, -92(%rbp)
100003294: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003298: e8 45 0a 00 00              	callq	2629 <dyld_stub_binder+0x100003ce2>
10000329d: 48 63 c8                    	movslq	%eax, %rcx
1000032a0: 48 89 ca                    	movq	%rcx, %rdx
1000032a3: 48 09 da                    	orq	%rbx, %rdx
1000032a6: 48 c1 ea 20                 	shrq	$32, %rdx
1000032aa: 74 14                       	je	20 <_calc_avg_times_lower+0xf0>
1000032ac: 48 89 c8                    	movq	%rcx, %rax
1000032af: 31 d2                       	xorl	%edx, %edx
1000032b1: 48 f7 f3                    	divq	%rbx
1000032b4: 49 89 d7                    	movq	%rdx, %r15
1000032b7: eb 0e                       	jmp	14 <_calc_avg_times_lower+0xf7>
1000032b9: 0f 1f 80 00 00 00 00        	nopl	(%rax)
1000032c0: 31 d2                       	xorl	%edx, %edx
1000032c2: f7 f3                       	divl	%ebx
1000032c4: 41 89 d7                    	movl	%edx, %r15d
1000032c7: 48 8b 45 a8                 	movq	-88(%rbp), %rax
1000032cb: 4c 01 f8                    	addq	%r15, %rax
1000032ce: 48 89 45 c0                 	movq	%rax, -64(%rbp)
1000032d2: 45 31 e4                    	xorl	%r12d, %r12d
1000032d5: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000032df: 90                          	nop
1000032e0: e8 fd 09 00 00              	callq	2557 <dyld_stub_binder+0x100003ce2>
1000032e5: 48 98                       	cltq
1000032e7: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
1000032ee: 48 c1 e9 20                 	shrq	$32, %rcx
1000032f2: 01 c1                       	addl	%eax, %ecx
1000032f4: 89 ca                       	movl	%ecx, %edx
1000032f6: c1 ea 1f                    	shrl	$31, %edx
1000032f9: c1 e9 06                    	shrl	$6, %ecx
1000032fc: 01 d1                       	addl	%edx, %ecx
1000032fe: 6b c9 5f                    	imull	$95, %ecx, %ecx
100003301: 29 c8                       	subl	%ecx, %eax
100003303: 04 20                       	addb	$32, %al
100003305: 43 88 04 26                 	movb	%al, (%r14,%r12)
100003309: 49 ff c4                    	incq	%r12
10000330c: 4d 39 e5                    	cmpq	%r12, %r13
10000330f: 75 cf                       	jne	-49 <_calc_avg_times_lower+0x110>
100003311: 4c 03 7d 98                 	addq	-104(%rbp), %r15
100003315: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
10000331a: 48 8b 5d c0                 	movq	-64(%rbp), %rbx
10000331e: 48 89 df                    	movq	%rbx, %rdi
100003321: 4c 89 f6                    	movq	%r14, %rsi
100003324: e8 cb 09 00 00              	callq	2507 <dyld_stub_binder+0x100003cf4>
100003329: 4c 89 ff                    	movq	%r15, %rdi
10000332c: 4c 89 f6                    	movq	%r14, %rsi
10000332f: e8 c0 09 00 00              	callq	2496 <dyld_stub_binder+0x100003cf4>
100003334: bf 06 00 00 00              	movl	$6, %edi
100003339: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100003340: e8 79 09 00 00              	callq	2425 <dyld_stub_binder+0x100003cbe>
100003345: 48 89 df                    	movq	%rbx, %rdi
100003348: 4c 89 ee                    	movq	%r13, %rsi
10000334b: e8 a0 f5 ff ff              	callq	-2656 <_naive_to_lower>
100003350: bf 06 00 00 00              	movl	$6, %edi
100003355: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
10000335c: e8 5d 09 00 00              	callq	2397 <dyld_stub_binder+0x100003cbe>
100003361: bf 06 00 00 00              	movl	$6, %edi
100003366: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000336d: e8 4c 09 00 00              	callq	2380 <dyld_stub_binder+0x100003cbe>
100003372: 4c 89 ff                    	movq	%r15, %rdi
100003375: 4c 89 ee                    	movq	%r13, %rsi
100003378: e8 8f 08 00 00              	callq	2191 <_to_lower>
10000337d: bf 06 00 00 00              	movl	$6, %edi
100003382: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003386: e8 33 09 00 00              	callq	2355 <dyld_stub_binder+0x100003cbe>
10000338b: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100003392: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100003399: 48 8b 45 c8                 	movq	-56(%rbp), %rax
10000339d: 48 03 85 70 ff ff ff        	addq	-144(%rbp), %rax
1000033a4: 48 2b 85 60 ff ff ff        	subq	-160(%rbp), %rax
1000033ab: 48 89 45 c8                 	movq	%rax, -56(%rbp)
1000033af: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
1000033b3: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
1000033ba: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000033be: 48 03 4d 90                 	addq	-112(%rbp), %rcx
1000033c2: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
1000033c6: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
1000033ca: 0f 84 90 fe ff ff           	je	-368 <_calc_avg_times_lower+0x90>
1000033d0: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
1000033d4: 4c 89 fe                    	movq	%r15, %rsi
1000033d7: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
1000033db: e8 0e 09 00 00              	callq	2318 <dyld_stub_binder+0x100003cee>
1000033e0: 4c 89 fa                    	movq	%r15, %rdx
1000033e3: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000033e7: 85 c0                       	testl	%eax, %eax
1000033e9: 0f 84 71 fe ff ff           	je	-399 <_calc_avg_times_lower+0x90>
1000033ef: e9 27 05 00 00              	jmp	1319 <_calc_avg_times_lower+0x74b>
1000033f4: 31 c9                       	xorl	%ecx, %ecx
1000033f6: 45 31 ff                    	xorl	%r15d, %r15d
1000033f9: 8b 45 b0                    	movl	-80(%rbp), %eax
1000033fc: 3b 45 bc                    	cmpl	-68(%rbp), %eax
1000033ff: 0f 83 1e 03 00 00           	jae	798 <_calc_avg_times_lower+0x553>
100003405: 4d 85 ed                    	testq	%r13, %r13
100003408: 75 42                       	jne	66 <_calc_avg_times_lower+0x27c>
10000340a: 8b 45 bc                    	movl	-68(%rbp), %eax
10000340d: 2b 45 b0                    	subl	-80(%rbp), %eax
100003410: e9 d1 01 00 00              	jmp	465 <_calc_avg_times_lower+0x416>
100003415: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000341f: 90                          	nop
100003420: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100003427: 49 01 c7                    	addq	%rax, %r15
10000342a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100003431: 48 01 c1                    	addq	%rax, %rcx
100003434: 8b 45 b0                    	movl	-80(%rbp), %eax
100003437: ff c0                       	incl	%eax
100003439: 89 45 b0                    	movl	%eax, -80(%rbp)
10000343c: 3b 45 bc                    	cmpl	-68(%rbp), %eax
10000343f: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
100003446: 0f 84 d7 02 00 00           	je	727 <_calc_avg_times_lower+0x553>
10000344c: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003450: e8 8d 08 00 00              	callq	2189 <dyld_stub_binder+0x100003ce2>
100003455: 48 63 c8                    	movslq	%eax, %rcx
100003458: 48 89 ca                    	movq	%rcx, %rdx
10000345b: 48 09 da                    	orq	%rbx, %rdx
10000345e: 48 c1 ea 20                 	shrq	$32, %rdx
100003462: 74 1c                       	je	28 <_calc_avg_times_lower+0x2b0>
100003464: 48 89 c8                    	movq	%rcx, %rax
100003467: 31 d2                       	xorl	%edx, %edx
100003469: 48 f7 f3                    	divq	%rbx
10000346c: 48 89 d3                    	movq	%rdx, %rbx
10000346f: eb 15                       	jmp	21 <_calc_avg_times_lower+0x2b6>
100003471: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000347b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100003480: 31 d2                       	xorl	%edx, %edx
100003482: f7 f3                       	divl	%ebx
100003484: 89 d3                       	movl	%edx, %ebx
100003486: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000348a: 48 01 d8                    	addq	%rbx, %rax
10000348d: 48 89 45 c8                 	movq	%rax, -56(%rbp)
100003491: 45 31 e4                    	xorl	%r12d, %r12d
100003494: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000349e: 66 90                       	nop
1000034a0: e8 3d 08 00 00              	callq	2109 <dyld_stub_binder+0x100003ce2>
1000034a5: 48 98                       	cltq
1000034a7: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
1000034ae: 48 c1 e9 20                 	shrq	$32, %rcx
1000034b2: 01 c1                       	addl	%eax, %ecx
1000034b4: 89 ca                       	movl	%ecx, %edx
1000034b6: c1 ea 1f                    	shrl	$31, %edx
1000034b9: c1 e9 06                    	shrl	$6, %ecx
1000034bc: 01 d1                       	addl	%edx, %ecx
1000034be: 6b c9 5f                    	imull	$95, %ecx, %ecx
1000034c1: 29 c8                       	subl	%ecx, %eax
1000034c3: 04 20                       	addb	$32, %al
1000034c5: 43 88 04 26                 	movb	%al, (%r14,%r12)
1000034c9: 49 ff c4                    	incq	%r12
1000034cc: 4d 39 e5                    	cmpq	%r12, %r13
1000034cf: 75 cf                       	jne	-49 <_calc_avg_times_lower+0x2d0>
1000034d1: 48 03 5d 98                 	addq	-104(%rbp), %rbx
1000034d5: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
1000034da: 49 89 dc                    	movq	%rbx, %r12
1000034dd: 48 8b 5d c8                 	movq	-56(%rbp), %rbx
1000034e1: 48 89 df                    	movq	%rbx, %rdi
1000034e4: 4c 89 f6                    	movq	%r14, %rsi
1000034e7: e8 08 08 00 00              	callq	2056 <dyld_stub_binder+0x100003cf4>
1000034ec: 4c 89 e7                    	movq	%r12, %rdi
1000034ef: 4c 89 f6                    	movq	%r14, %rsi
1000034f2: e8 fd 07 00 00              	callq	2045 <dyld_stub_binder+0x100003cf4>
1000034f7: bf 06 00 00 00              	movl	$6, %edi
1000034fc: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100003503: e8 b6 07 00 00              	callq	1974 <dyld_stub_binder+0x100003cbe>
100003508: 48 89 df                    	movq	%rbx, %rdi
10000350b: 4c 89 ee                    	movq	%r13, %rsi
10000350e: e8 f9 06 00 00              	callq	1785 <_to_lower>
100003513: bf 06 00 00 00              	movl	$6, %edi
100003518: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
10000351c: e8 9d 07 00 00              	callq	1949 <dyld_stub_binder+0x100003cbe>
100003521: bf 06 00 00 00              	movl	$6, %edi
100003526: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
10000352d: e8 8c 07 00 00              	callq	1932 <dyld_stub_binder+0x100003cbe>
100003532: 4c 89 e3                    	movq	%r12, %rbx
100003535: 4c 89 e7                    	movq	%r12, %rdi
100003538: 4c 89 ee                    	movq	%r13, %rsi
10000353b: e8 b0 f3 ff ff              	callq	-3152 <_naive_to_lower>
100003540: bf 06 00 00 00              	movl	$6, %edi
100003545: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
10000354c: e8 6d 07 00 00              	callq	1901 <dyld_stub_binder+0x100003cbe>
100003551: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100003558: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
10000355f: 4c 03 bd 70 ff ff ff        	addq	-144(%rbp), %r15
100003566: 4c 2b bd 60 ff ff ff        	subq	-160(%rbp), %r15
10000356d: 48 89 d8                    	movq	%rbx, %rax
100003570: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100003574: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
10000357b: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
10000357f: 48 03 4d 90                 	addq	-112(%rbp), %rcx
100003583: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
100003587: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
10000358b: 0f 84 8f fe ff ff           	je	-369 <_calc_avg_times_lower+0x250>
100003591: 48 8b 7d c8                 	movq	-56(%rbp), %rdi
100003595: 48 89 45 c0                 	movq	%rax, -64(%rbp)
100003599: 48 8b 75 c0                 	movq	-64(%rbp), %rsi
10000359d: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
1000035a1: e8 48 07 00 00              	callq	1864 <dyld_stub_binder+0x100003cee>
1000035a6: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
1000035aa: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000035ae: 85 c0                       	testl	%eax, %eax
1000035b0: 0f 84 6a fe ff ff           	je	-406 <_calc_avg_times_lower+0x250>
1000035b6: e9 40 01 00 00              	jmp	320 <_calc_avg_times_lower+0x52b>
1000035bb: 0f 1f 44 00 00              	nopl	(%rax,%rax)
1000035c0: 48 69 c0 00 ca 9a 3b        	imulq	$1000000000, %rax, %rax
1000035c7: 49 01 c7                    	addq	%rax, %r15
1000035ca: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
1000035d1: 48 01 c1                    	addq	%rax, %rcx
1000035d4: 8b 45 c0                    	movl	-64(%rbp), %eax
1000035d7: ff c8                       	decl	%eax
1000035d9: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
1000035e0: 0f 84 3d 01 00 00           	je	317 <_calc_avg_times_lower+0x553>
1000035e6: 89 45 c0                    	movl	%eax, -64(%rbp)
1000035e9: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
1000035ed: e8 f0 06 00 00              	callq	1776 <dyld_stub_binder+0x100003ce2>
1000035f2: 48 63 c8                    	movslq	%eax, %rcx
1000035f5: 48 89 ca                    	movq	%rcx, %rdx
1000035f8: 48 09 da                    	orq	%rbx, %rdx
1000035fb: 48 c1 ea 20                 	shrq	$32, %rdx
1000035ff: 74 0f                       	je	15 <_calc_avg_times_lower+0x440>
100003601: 48 89 c8                    	movq	%rcx, %rax
100003604: 31 d2                       	xorl	%edx, %edx
100003606: 48 f7 f3                    	divq	%rbx
100003609: 49 89 d4                    	movq	%rdx, %r12
10000360c: eb 09                       	jmp	9 <_calc_avg_times_lower+0x447>
10000360e: 66 90                       	nop
100003610: 31 d2                       	xorl	%edx, %edx
100003612: f7 f3                       	divl	%ebx
100003614: 41 89 d4                    	movl	%edx, %r12d
100003617: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000361b: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
10000361f: 4c 03 65 98                 	addq	-104(%rbp), %r12
100003623: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100003628: 48 89 df                    	movq	%rbx, %rdi
10000362b: 4c 89 f6                    	movq	%r14, %rsi
10000362e: e8 c1 06 00 00              	callq	1729 <dyld_stub_binder+0x100003cf4>
100003633: 4c 89 e7                    	movq	%r12, %rdi
100003636: 4c 89 f6                    	movq	%r14, %rsi
100003639: e8 b6 06 00 00              	callq	1718 <dyld_stub_binder+0x100003cf4>
10000363e: bf 06 00 00 00              	movl	$6, %edi
100003643: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000364a: e8 6f 06 00 00              	callq	1647 <dyld_stub_binder+0x100003cbe>
10000364f: 48 89 5d c8                 	movq	%rbx, -56(%rbp)
100003653: 48 89 df                    	movq	%rbx, %rdi
100003656: 31 f6                       	xorl	%esi, %esi
100003658: e8 af 05 00 00              	callq	1455 <_to_lower>
10000365d: bf 06 00 00 00              	movl	$6, %edi
100003662: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003666: e8 53 06 00 00              	callq	1619 <dyld_stub_binder+0x100003cbe>
10000366b: bf 06 00 00 00              	movl	$6, %edi
100003670: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100003677: e8 42 06 00 00              	callq	1602 <dyld_stub_binder+0x100003cbe>
10000367c: 4c 89 e7                    	movq	%r12, %rdi
10000367f: 31 f6                       	xorl	%esi, %esi
100003681: e8 6a f2 ff ff              	callq	-3478 <_naive_to_lower>
100003686: bf 06 00 00 00              	movl	$6, %edi
10000368b: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100003692: e8 27 06 00 00              	callq	1575 <dyld_stub_binder+0x100003cbe>
100003697: 48 8b 85 68 ff ff ff        	movq	-152(%rbp), %rax
10000369e: 48 2b 85 58 ff ff ff        	subq	-168(%rbp), %rax
1000036a5: 4c 03 bd 70 ff ff ff        	addq	-144(%rbp), %r15
1000036ac: 4c 2b bd 60 ff ff ff        	subq	-160(%rbp), %r15
1000036b3: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
1000036b7: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
1000036be: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000036c2: 48 03 4d 90                 	addq	-112(%rbp), %rcx
1000036c6: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
1000036ca: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
1000036ce: 0f 84 ec fe ff ff           	je	-276 <_calc_avg_times_lower+0x3f0>
1000036d4: 48 8b 7d c8                 	movq	-56(%rbp), %rdi
1000036d8: 4c 89 e6                    	movq	%r12, %rsi
1000036db: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
1000036df: 48 89 45 b0                 	movq	%rax, -80(%rbp)
1000036e3: e8 06 06 00 00              	callq	1542 <dyld_stub_binder+0x100003cee>
1000036e8: 4c 89 e2                    	movq	%r12, %rdx
1000036eb: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000036ef: 85 c0                       	testl	%eax, %eax
1000036f1: 48 8b 45 b0                 	movq	-80(%rbp), %rax
1000036f5: 0f 84 c5 fe ff ff           	je	-315 <_calc_avg_times_lower+0x3f0>
1000036fb: 48 8d 3d 06 08 00 00        	leaq	2054(%rip), %rdi
100003702: 48 89 d3                    	movq	%rdx, %rbx
100003705: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
100003709: 4c 89 f2                    	movq	%r14, %rdx
10000370c: 31 c0                       	xorl	%eax, %eax
10000370e: e8 bd 05 00 00              	callq	1469 <dyld_stub_binder+0x100003cd0>
100003713: 48 8d 3d fe 07 00 00        	leaq	2046(%rip), %rdi
10000371a: 48 8b 55 c8                 	movq	-56(%rbp), %rdx
10000371e: e9 1b 02 00 00              	jmp	539 <_calc_avg_times_lower+0x76e>
100003723: c4 c1 f9 6e c7              	vmovq	%r15, %xmm0
100003728: c5 f9 6f 0d b0 07 00 00     	vmovdqa	1968(%rip), %xmm1
100003730: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100003734: c5 f9 28 15 b4 07 00 00     	vmovapd	1972(%rip), %xmm2
10000373c: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100003740: c4 e3 79 05 d8 01           	vpermilpd	$1, %xmm0, %xmm3
100003746: 8b 45 bc                    	movl	-68(%rbp), %eax
100003749: c4 e1 db 2a e0              	vcvtsi2sd	%rax, %xmm4, %xmm4
10000374e: c5 e3 58 c0                 	vaddsd	%xmm0, %xmm3, %xmm0
100003752: c5 db 59 1d a6 07 00 00     	vmulsd	1958(%rip), %xmm4, %xmm3
10000375a: c5 fb 5e c3                 	vdivsd	%xmm3, %xmm0, %xmm0
10000375e: c5 fb 5a c0                 	vcvtsd2ss	%xmm0, %xmm0, %xmm0
100003762: 48 8b 85 48 ff ff ff        	movq	-184(%rbp), %rax
100003769: c5 fa 11 00                 	vmovss	%xmm0, (%rax)
10000376d: c4 e1 f9 6e c1              	vmovq	%rcx, %xmm0
100003772: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100003776: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
10000377a: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100003780: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100003784: c5 fb 5e c3                 	vdivsd	%xmm3, %xmm0, %xmm0
100003788: c5 fb 5a c0                 	vcvtsd2ss	%xmm0, %xmm0, %xmm0
10000378c: 48 8b 85 40 ff ff ff        	movq	-192(%rbp), %rax
100003793: c5 fa 11 00                 	vmovss	%xmm0, (%rax)
100003797: 48 8b 7d a8                 	movq	-88(%rbp), %rdi
10000379b: e8 24 05 00 00              	callq	1316 <dyld_stub_binder+0x100003cc4>
1000037a0: 48 8b 7d 98                 	movq	-104(%rbp), %rdi
1000037a4: e8 1b 05 00 00              	callq	1307 <dyld_stub_binder+0x100003cc4>
1000037a9: 48 81 c4 98 00 00 00        	addq	$152, %rsp
1000037b0: 5b                          	popq	%rbx
1000037b1: 41 5c                       	popq	%r12
1000037b3: 41 5d                       	popq	%r13
1000037b5: 41 5e                       	popq	%r14
1000037b7: 41 5f                       	popq	%r15
1000037b9: 5d                          	popq	%rbp
1000037ba: c3                          	retq
1000037bb: 8b 45 b0                    	movl	-80(%rbp), %eax
1000037be: 31 c9                       	xorl	%ecx, %ecx
1000037c0: eb 38                       	jmp	56 <_calc_avg_times_lower+0x62a>
1000037c2: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000037cc: 0f 1f 40 00                 	nopl	(%rax)
1000037d0: 49 69 c7 00 ca 9a 3b        	imulq	$1000000000, %r15, %rax
1000037d7: 4c 8b 7d c8                 	movq	-56(%rbp), %r15
1000037db: 49 01 c7                    	addq	%rax, %r15
1000037de: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
1000037e5: 48 01 c1                    	addq	%rax, %rcx
1000037e8: 8b 45 a4                    	movl	-92(%rbp), %eax
1000037eb: ff c8                       	decl	%eax
1000037ed: 48 8b 9d 50 ff ff ff        	movq	-176(%rbp), %rbx
1000037f4: 0f 84 ff fb ff ff           	je	-1025 <_calc_avg_times_lower+0x229>
1000037fa: 89 45 a4                    	movl	%eax, -92(%rbp)
1000037fd: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003801: e8 dc 04 00 00              	callq	1244 <dyld_stub_binder+0x100003ce2>
100003806: 48 63 c8                    	movslq	%eax, %rcx
100003809: 48 89 ca                    	movq	%rcx, %rdx
10000380c: 48 09 da                    	orq	%rbx, %rdx
10000380f: 48 c1 ea 20                 	shrq	$32, %rdx
100003813: 4c 89 7d c8                 	movq	%r15, -56(%rbp)
100003817: 74 17                       	je	23 <_calc_avg_times_lower+0x660>
100003819: 48 89 c8                    	movq	%rcx, %rax
10000381c: 31 d2                       	xorl	%edx, %edx
10000381e: 48 f7 f3                    	divq	%rbx
100003821: 49 89 d4                    	movq	%rdx, %r12
100003824: eb 11                       	jmp	17 <_calc_avg_times_lower+0x667>
100003826: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100003830: 31 d2                       	xorl	%edx, %edx
100003832: f7 f3                       	divl	%ebx
100003834: 41 89 d4                    	movl	%edx, %r12d
100003837: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000383b: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
10000383f: 4c 03 65 98                 	addq	-104(%rbp), %r12
100003843: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100003848: 48 89 df                    	movq	%rbx, %rdi
10000384b: 4c 89 f6                    	movq	%r14, %rsi
10000384e: e8 a1 04 00 00              	callq	1185 <dyld_stub_binder+0x100003cf4>
100003853: 4c 89 e7                    	movq	%r12, %rdi
100003856: 4c 89 f6                    	movq	%r14, %rsi
100003859: e8 96 04 00 00              	callq	1174 <dyld_stub_binder+0x100003cf4>
10000385e: bf 06 00 00 00              	movl	$6, %edi
100003863: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
10000386a: e8 4f 04 00 00              	callq	1103 <dyld_stub_binder+0x100003cbe>
10000386f: 48 89 5d c0                 	movq	%rbx, -64(%rbp)
100003873: 48 89 df                    	movq	%rbx, %rdi
100003876: 31 f6                       	xorl	%esi, %esi
100003878: e8 73 f0 ff ff              	callq	-3981 <_naive_to_lower>
10000387d: bf 06 00 00 00              	movl	$6, %edi
100003882: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100003889: e8 30 04 00 00              	callq	1072 <dyld_stub_binder+0x100003cbe>
10000388e: bf 06 00 00 00              	movl	$6, %edi
100003893: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000389a: e8 1f 04 00 00              	callq	1055 <dyld_stub_binder+0x100003cbe>
10000389f: 4c 89 e7                    	movq	%r12, %rdi
1000038a2: 31 f6                       	xorl	%esi, %esi
1000038a4: e8 63 03 00 00              	callq	867 <_to_lower>
1000038a9: bf 06 00 00 00              	movl	$6, %edi
1000038ae: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
1000038b2: e8 07 04 00 00              	callq	1031 <dyld_stub_binder+0x100003cbe>
1000038b7: 4c 8b bd 68 ff ff ff        	movq	-152(%rbp), %r15
1000038be: 4c 2b bd 58 ff ff ff        	subq	-168(%rbp), %r15
1000038c5: 48 8b 45 c8                 	movq	-56(%rbp), %rax
1000038c9: 48 03 85 70 ff ff ff        	addq	-144(%rbp), %rax
1000038d0: 48 2b 85 60 ff ff ff        	subq	-160(%rbp), %rax
1000038d7: 48 89 45 c8                 	movq	%rax, -56(%rbp)
1000038db: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
1000038df: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
1000038e6: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
1000038ea: 48 03 4d 90                 	addq	-112(%rbp), %rcx
1000038ee: 48 2b 4d 80                 	subq	-128(%rbp), %rcx
1000038f2: 80 7d b8 00                 	cmpb	$0, -72(%rbp)
1000038f6: 0f 84 d4 fe ff ff           	je	-300 <_calc_avg_times_lower+0x600>
1000038fc: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100003900: 4c 89 e6                    	movq	%r12, %rsi
100003903: 48 89 4d d0                 	movq	%rcx, -48(%rbp)
100003907: e8 e2 03 00 00              	callq	994 <dyld_stub_binder+0x100003cee>
10000390c: 4c 89 e2                    	movq	%r12, %rdx
10000390f: 48 8b 4d d0                 	movq	-48(%rbp), %rcx
100003913: 85 c0                       	testl	%eax, %eax
100003915: 0f 84 b5 fe ff ff           	je	-331 <_calc_avg_times_lower+0x600>
10000391b: 48 8d 3d e6 05 00 00        	leaq	1510(%rip), %rdi
100003922: 48 89 d3                    	movq	%rdx, %rbx
100003925: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
100003929: 4c 89 f2                    	movq	%r14, %rdx
10000392c: 31 c0                       	xorl	%eax, %eax
10000392e: e8 9d 03 00 00              	callq	925 <dyld_stub_binder+0x100003cd0>
100003933: 48 8d 3d de 05 00 00        	leaq	1502(%rip), %rdi
10000393a: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
10000393e: 48 89 d6                    	movq	%rdx, %rsi
100003941: 31 c0                       	xorl	%eax, %eax
100003943: e8 88 03 00 00              	callq	904 <dyld_stub_binder+0x100003cd0>
100003948: 48 8d 3d d9 05 00 00        	leaq	1497(%rip), %rdi
10000394f: 48 89 de                    	movq	%rbx, %rsi
100003952: 48 89 da                    	movq	%rbx, %rdx
100003955: 31 c0                       	xorl	%eax, %eax
100003957: e8 74 03 00 00              	callq	884 <dyld_stub_binder+0x100003cd0>
10000395c: e8 57 03 00 00              	callq	855 <dyld_stub_binder+0x100003cb8>
100003961: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000396b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100003970 _main:
100003970: 55                          	pushq	%rbp
100003971: 48 89 e5                    	movq	%rsp, %rbp
100003974: 41 57                       	pushq	%r15
100003976: 41 56                       	pushq	%r14
100003978: 41 55                       	pushq	%r13
10000397a: 41 54                       	pushq	%r12
10000397c: 53                          	pushq	%rbx
10000397d: 48 83 ec 18                 	subq	$24, %rsp
100003981: 31 ff                       	xorl	%edi, %edi
100003983: e8 72 03 00 00              	callq	882 <dyld_stub_binder+0x100003cfa>
100003988: 89 c7                       	movl	%eax, %edi
10000398a: e8 59 03 00 00              	callq	857 <dyld_stub_binder+0x100003ce8>
10000398f: bf 7b 00 00 00              	movl	$123, %edi
100003994: e8 3d 03 00 00              	callq	829 <dyld_stub_binder+0x100003cd6>
100003999: 4c 8d 7d c8                 	leaq	-56(%rbp), %r15
10000399d: 4c 8d 75 cc                 	leaq	-52(%rbp), %r14
1000039a1: bf 40 0d 03 00              	movl	$200000, %edi
1000039a6: be c8 00 00 00              	movl	$200, %esi
1000039ab: 4c 89 fa                    	movq	%r15, %rdx
1000039ae: 4c 89 f1                    	movq	%r14, %rcx
1000039b1: 41 b8 01 00 00 00           	movl	$1, %r8d
1000039b7: 45 31 c9                    	xorl	%r9d, %r9d
1000039ba: e8 71 f0 ff ff              	callq	-3983 <_calc_avg_times_upper>
1000039bf: 48 8d 3d ab 05 00 00        	leaq	1451(%rip), %rdi
1000039c6: e8 11 03 00 00              	callq	785 <dyld_stub_binder+0x100003cdc>
1000039cb: c5 fa 10 45 c8              	vmovss	-56(%rbp), %xmm0
1000039d0: c5 fa 11 45 d0              	vmovss	%xmm0, -48(%rbp)
1000039d5: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
1000039d9: 4c 8d 25 58 05 00 00        	leaq	1368(%rip), %r12
1000039e0: 4c 89 e7                    	movq	%r12, %rdi
1000039e3: b0 01                       	movb	$1, %al
1000039e5: e8 e6 02 00 00              	callq	742 <dyld_stub_binder+0x100003cd0>
1000039ea: c5 fa 10 45 cc              	vmovss	-52(%rbp), %xmm0
1000039ef: c5 fa 11 45 d4              	vmovss	%xmm0, -44(%rbp)
1000039f4: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
1000039f8: 4c 8d 2d 4c 05 00 00        	leaq	1356(%rip), %r13
1000039ff: 4c 89 ef                    	movq	%r13, %rdi
100003a02: b0 01                       	movb	$1, %al
100003a04: e8 c7 02 00 00              	callq	711 <dyld_stub_binder+0x100003cd0>
100003a09: c5 fa 10 45 d0              	vmovss	-48(%rbp), %xmm0
100003a0e: c5 fa 5e 45 d4              	vdivss	-44(%rbp), %xmm0, %xmm0
100003a13: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
100003a17: 48 8d 1d 40 05 00 00        	leaq	1344(%rip), %rbx
100003a1e: 48 89 df                    	movq	%rbx, %rdi
100003a21: b0 01                       	movb	$1, %al
100003a23: e8 a8 02 00 00              	callq	680 <dyld_stub_binder+0x100003cd0>
100003a28: bf 40 0d 03 00              	movl	$200000, %edi
100003a2d: be c8 00 00 00              	movl	$200, %esi
100003a32: 4c 89 fa                    	movq	%r15, %rdx
100003a35: 4c 89 f1                    	movq	%r14, %rcx
100003a38: 41 b8 01 00 00 00           	movl	$1, %r8d
100003a3e: 45 31 c9                    	xorl	%r9d, %r9d
100003a41: e8 8a f7 ff ff              	callq	-2166 <_calc_avg_times_lower>
100003a46: 48 8d 3d 2b 05 00 00        	leaq	1323(%rip), %rdi
100003a4d: e8 8a 02 00 00              	callq	650 <dyld_stub_binder+0x100003cdc>
100003a52: c5 fa 10 45 c8              	vmovss	-56(%rbp), %xmm0
100003a57: c5 fa 11 45 d0              	vmovss	%xmm0, -48(%rbp)
100003a5c: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
100003a60: 4c 89 e7                    	movq	%r12, %rdi
100003a63: b0 01                       	movb	$1, %al
100003a65: e8 66 02 00 00              	callq	614 <dyld_stub_binder+0x100003cd0>
100003a6a: c5 fa 10 45 cc              	vmovss	-52(%rbp), %xmm0
100003a6f: c5 fa 11 45 d4              	vmovss	%xmm0, -44(%rbp)
100003a74: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
100003a78: 4c 89 ef                    	movq	%r13, %rdi
100003a7b: b0 01                       	movb	$1, %al
100003a7d: e8 4e 02 00 00              	callq	590 <dyld_stub_binder+0x100003cd0>
100003a82: c5 fa 10 45 d0              	vmovss	-48(%rbp), %xmm0
100003a87: c5 fa 5e 45 d4              	vdivss	-44(%rbp), %xmm0, %xmm0
100003a8c: c5 fa 5a c0                 	vcvtss2sd	%xmm0, %xmm0, %xmm0
100003a90: 48 89 df                    	movq	%rbx, %rdi
100003a93: b0 01                       	movb	$1, %al
100003a95: e8 36 02 00 00              	callq	566 <dyld_stub_binder+0x100003cd0>
100003a9a: 48 8d 3d de 04 00 00        	leaq	1246(%rip), %rdi
100003aa1: e8 36 02 00 00              	callq	566 <dyld_stub_binder+0x100003cdc>
100003aa6: 31 c0                       	xorl	%eax, %eax
100003aa8: 48 83 c4 18                 	addq	$24, %rsp
100003aac: 5b                          	popq	%rbx
100003aad: 41 5c                       	popq	%r12
100003aaf: 41 5d                       	popq	%r13
100003ab1: 41 5e                       	popq	%r14
100003ab3: 41 5f                       	popq	%r15
100003ab5: 5d                          	popq	%rbp
100003ab6: c3                          	retq
100003ab7: 90                          	nop
100003ab8: 90                          	nop
100003ab9: 90                          	nop
100003aba: 90                          	nop
100003abb: 90                          	nop
100003abc: 90                          	nop
100003abd: 90                          	nop
100003abe: 90                          	nop
100003abf: 90                          	nop

0000000100003ac0 upper_offset_array:
100003ac0: 05 05 05 05 05              	addl	$84215045, %eax
100003ac5: 05 05 05 05 05              	addl	$84215045, %eax
100003aca: 05 05 05 05 05              	addl	$84215045, %eax
100003acf: 05 05 05 05 05              	addl	$84215045, %eax
100003ad4: 05 05 05 05 05              	addl	$84215045, %eax
100003ad9: 05 05 05 05 05              	addl	$84215045, %eax
100003ade: 05 05 25 25 25              	addl	$623191301, %eax
100003ae3: 25 25 25 25 25              	andl	$623191333, %eax
100003ae8: 25 25 25 25 25              	andl	$623191333, %eax
100003aed: 25 25 25 25 25              	andl	$623191333, %eax
100003af2: 25 25 25 25 25              	andl	$623191333, %eax
100003af7: 25 25 25 25 25              	andl	$623191333, %eax
100003afc: 25 25 25 25 65              	andl	$1696933157, %eax

0000000100003b00 range_min:
100003b00: 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 e0 e0       	loopne	-32
100003b22: e0 e0                       	loopne	-32
100003b24: e0 e0                       	loopne	-32
100003b26: e0 e0                       	loopne	-32
100003b28: e0 e0                       	loopne	-32
100003b2a: e0 e0                       	loopne	-32
100003b2c: e0 e0                       	loopne	-32
100003b2e: e0 e0                       	loopne	-32
100003b30: e0 e0                       	loopne	-32
100003b32: e0 e0                       	loopne	-32
100003b34: e0 e0                       	loopne	-32
100003b36: e0 e0                       	loopne	-32
100003b38: e0 e0                       	loopne	-32
100003b3a: e0 e0                       	loopne	-32
100003b3c: e0 e0                       	loopne	-32
100003b3e: e0 e0                       	loopne	-32

0000000100003b40 upper_to_lower:
100003b40: 20 20                       	andb	%ah, (%rax)
100003b42: 20 20                       	andb	%ah, (%rax)
100003b44: 20 20                       	andb	%ah, (%rax)
100003b46: 20 20                       	andb	%ah, (%rax)
100003b48: 20 20                       	andb	%ah, (%rax)
100003b4a: 20 20                       	andb	%ah, (%rax)
100003b4c: 20 20                       	andb	%ah, (%rax)
100003b4e: 20 20                       	andb	%ah, (%rax)
100003b50: 20 20                       	andb	%ah, (%rax)
100003b52: 20 20                       	andb	%ah, (%rax)
100003b54: 20 20                       	andb	%ah, (%rax)
100003b56: 20 20                       	andb	%ah, (%rax)
100003b58: 20 20                       	andb	%ah, (%rax)
100003b5a: 20 20                       	andb	%ah, (%rax)
100003b5c: 20 20                       	andb	%ah, (%rax)
100003b5e: 20 20                       	andb	%ah, (%rax)

0000000100003b60 _to_upper:
100003b60: 53                          	pushq	%rbx
100003b61: 48 01 fe                    	addq	%rdi, %rsi
100003b64: c5 fd 6f 1d 54 ff ff ff     	vmovdqa	-172(%rip), %ymm3
100003b6c: c5 fd 6f 25 8c ff ff ff     	vmovdqa	-116(%rip), %ymm4

0000000100003b74 _up_loop_init:
100003b74: 48 89 f8                    	movq	%rdi, %rax
100003b77: 48 83 c0 1f                 	addq	$31, %rax
100003b7b: 48 83 e0 e0                 	andq	$-32, %rax
100003b7f: 48 39 c6                    	cmpq	%rax, %rsi
100003b82: 48 89 c1                    	movq	%rax, %rcx
100003b85: 48 0f 42 ce                 	cmovbq	%rsi, %rcx
100003b89: e9 14 00 00 00              	jmp	20 <_up_beg_loop_cond>

0000000100003b8e _up_beg_loop:
100003b8e: 0f b6 07                    	movzbl	(%rdi), %eax
100003b91: 8d 58 9f                    	leal	-97(%rax), %ebx
100003b94: 8d 50 e0                    	leal	-32(%rax), %edx
100003b97: 83 fb 1a                    	cmpl	$26, %ebx
100003b9a: 0f 42 c2                    	cmovbl	%edx, %eax
100003b9d: 88 07                       	movb	%al, (%rdi)
100003b9f: 48 ff c7                    	incq	%rdi

0000000100003ba2 _up_beg_loop_cond:
100003ba2: 48 39 cf                    	cmpq	%rcx, %rdi
100003ba5: 0f 85 e3 ff ff ff           	jne	-29 <_up_beg_loop>

0000000100003bab _up_vector_loop_init:
100003bab: 48 89 f1                    	movq	%rsi, %rcx
100003bae: 48 83 e1 e0                 	andq	$-32, %rcx

0000000100003bb2 _up_vector_loop_cond_1:
100003bb2: 48 39 cf                    	cmpq	%rcx, %rdi
100003bb5: 0f 83 29 00 00 00           	jae	41 <_up_remainder_loop_cond_1>

0000000100003bbb _up_vector_loop:
100003bbb: c5 fd 6f 0f                 	vmovdqa	(%rdi), %ymm1
100003bbf: c5 e5 fc d1                 	vpaddb	%ymm1, %ymm3, %ymm2
100003bc3: c5 ed 64 d4                 	vpcmpgtb	%ymm4, %ymm2, %ymm2
100003bc7: c5 ed db 15 51 ff ff ff     	vpand	-175(%rip), %ymm2, %ymm2
100003bcf: c5 ed fc c9                 	vpaddb	%ymm1, %ymm2, %ymm1
100003bd3: c5 fd 7f 0f                 	vmovdqa	%ymm1, (%rdi)
100003bd7: 48 83 c7 20                 	addq	$32, %rdi

0000000100003bdb _up_vector_loop_cond_2:
100003bdb: 48 39 cf                    	cmpq	%rcx, %rdi
100003bde: 0f 82 d7 ff ff ff           	jb	-41 <_up_vector_loop>

0000000100003be4 _up_remainder_loop_cond_1:
100003be4: 48 39 f7                    	cmpq	%rsi, %rdi
100003be7: 0f 84 1d 00 00 00           	je	29 <_up_finished>

0000000100003bed _up_remainder_loop:
100003bed: 0f b6 07                    	movzbl	(%rdi), %eax
100003bf0: 8d 58 9f                    	leal	-97(%rax), %ebx
100003bf3: 8d 50 e0                    	leal	-32(%rax), %edx
100003bf6: 83 fb 1a                    	cmpl	$26, %ebx
100003bf9: 0f 42 c2                    	cmovbl	%edx, %eax
100003bfc: 88 07                       	movb	%al, (%rdi)
100003bfe: 48 ff c7                    	incq	%rdi

0000000100003c01 _up_remainder_loop_cond_2:
100003c01: 48 39 f7                    	cmpq	%rsi, %rdi
100003c04: 0f 85 e3 ff ff ff           	jne	-29 <_up_remainder_loop>

0000000100003c0a _up_finished:
100003c0a: 5b                          	popq	%rbx
100003c0b: c3                          	retq

0000000100003c0c _to_lower:
100003c0c: 53                          	pushq	%rbx
100003c0d: 48 01 fe                    	addq	%rdi, %rsi
100003c10: c5 fd 6f 1d c8 fe ff ff     	vmovdqa	-312(%rip), %ymm3
100003c18: c5 fd 6f 25 e0 fe ff ff     	vmovdqa	-288(%rip), %ymm4

0000000100003c20 _lo_loop_init:
100003c20: 48 89 f8                    	movq	%rdi, %rax
100003c23: 48 83 c0 1f                 	addq	$31, %rax
100003c27: 48 83 e0 e0                 	andq	$-32, %rax
100003c2b: 48 39 c6                    	cmpq	%rax, %rsi
100003c2e: 48 89 c1                    	movq	%rax, %rcx
100003c31: 48 0f 42 ce                 	cmovbq	%rsi, %rcx
100003c35: e9 14 00 00 00              	jmp	20 <_lo_beg_loop_cond>

0000000100003c3a _lo_beg_loop:
100003c3a: 0f b6 07                    	movzbl	(%rdi), %eax
100003c3d: 8d 58 bf                    	leal	-65(%rax), %ebx
100003c40: 8d 50 20                    	leal	32(%rax), %edx
100003c43: 83 fb 1a                    	cmpl	$26, %ebx
100003c46: 0f 42 c2                    	cmovbl	%edx, %eax
100003c49: 88 07                       	movb	%al, (%rdi)
100003c4b: 48 ff c7                    	incq	%rdi

0000000100003c4e _lo_beg_loop_cond:
100003c4e: 48 39 cf                    	cmpq	%rcx, %rdi
100003c51: 0f 85 e3 ff ff ff           	jne	-29 <_lo_beg_loop>

0000000100003c57 _lo_vector_loop_init:
100003c57: 48 89 f1                    	movq	%rsi, %rcx
100003c5a: 48 83 e1 e0                 	andq	$-32, %rcx

0000000100003c5e _lo_vector_loop_cond_1:
100003c5e: 48 39 cf                    	cmpq	%rcx, %rdi
100003c61: 0f 83 29 00 00 00           	jae	41 <_lo_remainder_loop_cond_1>

0000000100003c67 _lo_vector_loop:
100003c67: c5 fd 6f 0f                 	vmovdqa	(%rdi), %ymm1
100003c6b: c5 e5 fc d1                 	vpaddb	%ymm1, %ymm3, %ymm2
100003c6f: c5 ed 64 d4                 	vpcmpgtb	%ymm4, %ymm2, %ymm2
100003c73: c5 ed db 15 c5 fe ff ff     	vpand	-315(%rip), %ymm2, %ymm2
100003c7b: c5 ed fc c9                 	vpaddb	%ymm1, %ymm2, %ymm1
100003c7f: c5 fd 7f 0f                 	vmovdqa	%ymm1, (%rdi)
100003c83: 48 83 c7 20                 	addq	$32, %rdi

0000000100003c87 _lo_vector_loop_cond_2:
100003c87: 48 39 cf                    	cmpq	%rcx, %rdi
100003c8a: 0f 82 d7 ff ff ff           	jb	-41 <_lo_vector_loop>

0000000100003c90 _lo_remainder_loop_cond_1:
100003c90: 48 39 f7                    	cmpq	%rsi, %rdi
100003c93: 0f 84 1d 00 00 00           	je	29 <_lo_finished>

0000000100003c99 _lo_remainder_loop:
100003c99: 0f b6 07                    	movzbl	(%rdi), %eax
100003c9c: 8d 58 bf                    	leal	-65(%rax), %ebx
100003c9f: 8d 50 20                    	leal	32(%rax), %edx
100003ca2: 83 fb 1a                    	cmpl	$26, %ebx
100003ca5: 0f 42 c2                    	cmovbl	%edx, %eax
100003ca8: 88 07                       	movb	%al, (%rdi)
100003caa: 48 ff c7                    	incq	%rdi

0000000100003cad _lo_remainder_loop_cond_2:
100003cad: 48 39 f7                    	cmpq	%rsi, %rdi
100003cb0: 0f 85 e3 ff ff ff           	jne	-29 <_lo_remainder_loop>

0000000100003cb6 _lo_finished:
100003cb6: 5b                          	popq	%rbx
100003cb7: c3                          	retq

Disassembly of section __TEXT,__stubs:

0000000100003cb8 __stubs:
100003cb8: ff 25 42 43 00 00           	jmpq	*17218(%rip)
100003cbe: ff 25 44 43 00 00           	jmpq	*17220(%rip)
100003cc4: ff 25 46 43 00 00           	jmpq	*17222(%rip)
100003cca: ff 25 48 43 00 00           	jmpq	*17224(%rip)
100003cd0: ff 25 4a 43 00 00           	jmpq	*17226(%rip)
100003cd6: ff 25 4c 43 00 00           	jmpq	*17228(%rip)
100003cdc: ff 25 4e 43 00 00           	jmpq	*17230(%rip)
100003ce2: ff 25 50 43 00 00           	jmpq	*17232(%rip)
100003ce8: ff 25 52 43 00 00           	jmpq	*17234(%rip)
100003cee: ff 25 54 43 00 00           	jmpq	*17236(%rip)
100003cf4: ff 25 56 43 00 00           	jmpq	*17238(%rip)
100003cfa: ff 25 58 43 00 00           	jmpq	*17240(%rip)

Disassembly of section __TEXT,__stub_helper:

0000000100003d00 __stub_helper:
100003d00: 4c 8d 1d 59 43 00 00        	leaq	17241(%rip), %r11
100003d07: 41 53                       	pushq	%r11
100003d09: ff 25 f1 02 00 00           	jmpq	*753(%rip)
100003d0f: 90                          	nop
100003d10: 68 00 00 00 00              	pushq	$0
100003d15: e9 e6 ff ff ff              	jmp	-26 <__stub_helper>
100003d1a: 68 0d 00 00 00              	pushq	$13
100003d1f: e9 dc ff ff ff              	jmp	-36 <__stub_helper>
100003d24: 68 22 00 00 00              	pushq	$34
100003d29: e9 d2 ff ff ff              	jmp	-46 <__stub_helper>
100003d2e: 68 2e 00 00 00              	pushq	$46
100003d33: e9 c8 ff ff ff              	jmp	-56 <__stub_helper>
100003d38: 68 3c 00 00 00              	pushq	$60
100003d3d: e9 be ff ff ff              	jmp	-66 <__stub_helper>
100003d42: 68 4a 00 00 00              	pushq	$74
100003d47: e9 b4 ff ff ff              	jmp	-76 <__stub_helper>
100003d4c: 68 59 00 00 00              	pushq	$89
100003d51: e9 aa ff ff ff              	jmp	-86 <__stub_helper>
100003d56: 68 65 00 00 00              	pushq	$101
100003d5b: e9 a0 ff ff ff              	jmp	-96 <__stub_helper>
100003d60: 68 71 00 00 00              	pushq	$113
100003d65: e9 96 ff ff ff              	jmp	-106 <__stub_helper>
100003d6a: 68 7e 00 00 00              	pushq	$126
100003d6f: e9 8c ff ff ff              	jmp	-116 <__stub_helper>
100003d74: 68 8c 00 00 00              	pushq	$140
100003d79: e9 82 ff ff ff              	jmp	-126 <__stub_helper>
100003d7e: 68 9a 00 00 00              	pushq	$154
100003d83: e9 78 ff ff ff              	jmp	-136 <__stub_helper>
