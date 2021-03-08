
bin/to_upper_lower_test:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

00000001000025e0 _gen_rand_str:
1000025e0: 55                          	pushq	%rbp
1000025e1: 48 89 e5                    	movq	%rsp, %rbp
1000025e4: 41 57                       	pushq	%r15
1000025e6: 41 56                       	pushq	%r14
1000025e8: 53                          	pushq	%rbx
1000025e9: 50                          	pushq	%rax
1000025ea: 49 89 f7                    	movq	%rsi, %r15
1000025ed: 49 89 fe                    	movq	%rdi, %r14
1000025f0: 48 85 f6                    	testq	%rsi, %rsi
1000025f3: 74 3c                       	je	60 <_gen_rand_str+0x51>
1000025f5: 31 db                       	xorl	%ebx, %ebx
1000025f7: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)
100002600: e8 19 17 00 00              	callq	5913 <dyld_stub_binder+0x100003d1e>
100002605: 48 98                       	cltq
100002607: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
10000260e: 48 c1 e9 20                 	shrq	$32, %rcx
100002612: 01 c1                       	addl	%eax, %ecx
100002614: 89 ca                       	movl	%ecx, %edx
100002616: c1 ea 1f                    	shrl	$31, %edx
100002619: c1 e9 06                    	shrl	$6, %ecx
10000261c: 01 d1                       	addl	%edx, %ecx
10000261e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002621: 29 c8                       	subl	%ecx, %eax
100002623: 04 20                       	addb	$32, %al
100002625: 41 88 04 1e                 	movb	%al, (%r14,%rbx)
100002629: 48 ff c3                    	incq	%rbx
10000262c: 49 39 df                    	cmpq	%rbx, %r15
10000262f: 75 cf                       	jne	-49 <_gen_rand_str+0x20>
100002631: 43 c6 04 3e 00              	movb	$0, (%r14,%r15)
100002636: 48 83 c4 08                 	addq	$8, %rsp
10000263a: 5b                          	popq	%rbx
10000263b: 41 5e                       	popq	%r14
10000263d: 41 5f                       	popq	%r15
10000263f: 5d                          	popq	%rbp
100002640: c3                          	retq
100002641: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000264b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100002650 _naive_to_upper:
100002650: 55                          	pushq	%rbp
100002651: 48 89 e5                    	movq	%rsp, %rbp
100002654: 48 85 f6                    	testq	%rsi, %rsi
100002657: 0f 84 6a 01 00 00           	je	362 <_naive_to_upper+0x177>
10000265d: 48 83 fe 7f                 	cmpq	$127, %rsi
100002661: 77 08                       	ja	8 <_naive_to_upper+0x1b>
100002663: 45 31 c0                    	xorl	%r8d, %r8d
100002666: e9 35 01 00 00              	jmp	309 <_naive_to_upper+0x150>
10000266b: 49 89 f0                    	movq	%rsi, %r8
10000266e: 49 83 e0 80                 	andq	$-128, %r8
100002672: 31 c9                       	xorl	%ecx, %ecx
100002674: c5 fd 6f 05 64 17 00 00     	vmovdqa	5988(%rip), %ymm0
10000267c: c5 fd 6f 0d 7c 17 00 00     	vmovdqa	6012(%rip), %ymm1
100002684: c5 fd 6f 15 94 17 00 00     	vmovdqa	6036(%rip), %ymm2
10000268c: c5 fd 6f 1d ac 17 00 00     	vmovdqa	6060(%rip), %ymm3
100002694: c5 fd 6f 25 c4 17 00 00     	vmovdqa	6084(%rip), %ymm4
10000269c: c5 fd 6f 2d dc 17 00 00     	vmovdqa	6108(%rip), %ymm5
1000026a4: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000026ae: 66 90                       	nop
1000026b0: c5 fe 6f 34 0f              	vmovdqu	(%rdi,%rcx), %ymm6
1000026b5: c5 fe 6f 7c 0f 20           	vmovdqu	32(%rdi,%rcx), %ymm7
1000026bb: c5 7e 6f 44 0f 40           	vmovdqu	64(%rdi,%rcx), %ymm8
1000026c1: c5 7e 6f 4c 0f 60           	vmovdqu	96(%rdi,%rcx), %ymm9
1000026c7: c5 4d fc d0                 	vpaddb	%ymm0, %ymm6, %ymm10
1000026cb: c5 45 fc d8                 	vpaddb	%ymm0, %ymm7, %ymm11
1000026cf: c5 3d fc e0                 	vpaddb	%ymm0, %ymm8, %ymm12
1000026d3: c5 35 fc e8                 	vpaddb	%ymm0, %ymm9, %ymm13
1000026d7: c5 2d db d1                 	vpand	%ymm1, %ymm10, %ymm10
1000026db: c5 25 db d9                 	vpand	%ymm1, %ymm11, %ymm11
1000026df: c5 1d db e1                 	vpand	%ymm1, %ymm12, %ymm12
1000026e3: c5 15 db e9                 	vpand	%ymm1, %ymm13, %ymm13
1000026e7: c5 2d fc d2                 	vpaddb	%ymm2, %ymm10, %ymm10
1000026eb: c5 25 fc da                 	vpaddb	%ymm2, %ymm11, %ymm11
1000026ef: c5 1d fc e2                 	vpaddb	%ymm2, %ymm12, %ymm12
1000026f3: c5 15 fc ea                 	vpaddb	%ymm2, %ymm13, %ymm13
1000026f7: c4 41 4d df d2              	vpandn	%ymm10, %ymm6, %ymm10
1000026fc: c4 41 45 df db              	vpandn	%ymm11, %ymm7, %ymm11
100002701: c4 41 3d df e4              	vpandn	%ymm12, %ymm8, %ymm12
100002706: c4 41 35 df ed              	vpandn	%ymm13, %ymm9, %ymm13
10000270b: c4 c1 2d 71 d2 02           	vpsrlw	$2, %ymm10, %ymm10
100002711: c5 2d db d3                 	vpand	%ymm3, %ymm10, %ymm10
100002715: c5 2d ef d4                 	vpxor	%ymm4, %ymm10, %ymm10
100002719: c5 2d f8 d4                 	vpsubb	%ymm4, %ymm10, %ymm10
10000271d: c4 c1 25 71 d3 02           	vpsrlw	$2, %ymm11, %ymm11
100002723: c5 25 db db                 	vpand	%ymm3, %ymm11, %ymm11
100002727: c5 25 ef dc                 	vpxor	%ymm4, %ymm11, %ymm11
10000272b: c5 25 f8 dc                 	vpsubb	%ymm4, %ymm11, %ymm11
10000272f: c4 c1 1d 71 d4 02           	vpsrlw	$2, %ymm12, %ymm12
100002735: c5 1d db e3                 	vpand	%ymm3, %ymm12, %ymm12
100002739: c5 1d ef e4                 	vpxor	%ymm4, %ymm12, %ymm12
10000273d: c5 1d f8 e4                 	vpsubb	%ymm4, %ymm12, %ymm12
100002741: c4 c1 15 71 d5 02           	vpsrlw	$2, %ymm13, %ymm13
100002747: c5 15 db eb                 	vpand	%ymm3, %ymm13, %ymm13
10000274b: c5 15 ef ec                 	vpxor	%ymm4, %ymm13, %ymm13
10000274f: c5 15 f8 ec                 	vpsubb	%ymm4, %ymm13, %ymm13
100002753: c5 2d db d5                 	vpand	%ymm5, %ymm10, %ymm10
100002757: c5 25 db dd                 	vpand	%ymm5, %ymm11, %ymm11
10000275b: c5 1d db e5                 	vpand	%ymm5, %ymm12, %ymm12
10000275f: c5 15 db ed                 	vpand	%ymm5, %ymm13, %ymm13
100002763: c5 ad fc f6                 	vpaddb	%ymm6, %ymm10, %ymm6
100002767: c5 a5 fc ff                 	vpaddb	%ymm7, %ymm11, %ymm7
10000276b: c4 41 1d fc c0              	vpaddb	%ymm8, %ymm12, %ymm8
100002770: c4 41 15 fc c9              	vpaddb	%ymm9, %ymm13, %ymm9
100002775: c5 fe 7f 34 0f              	vmovdqu	%ymm6, (%rdi,%rcx)
10000277a: c5 fe 7f 7c 0f 20           	vmovdqu	%ymm7, 32(%rdi,%rcx)
100002780: c5 7e 7f 44 0f 40           	vmovdqu	%ymm8, 64(%rdi,%rcx)
100002786: c5 7e 7f 4c 0f 60           	vmovdqu	%ymm9, 96(%rdi,%rcx)
10000278c: 48 83 e9 80                 	subq	$-128, %rcx
100002790: 49 39 c8                    	cmpq	%rcx, %r8
100002793: 0f 85 17 ff ff ff           	jne	-233 <_naive_to_upper+0x60>
100002799: 49 39 f0                    	cmpq	%rsi, %r8
10000279c: 74 29                       	je	41 <_naive_to_upper+0x177>
10000279e: 66 90                       	nop
1000027a0: 42 0f b6 0c 07              	movzbl	(%rdi,%r8), %ecx
1000027a5: 8d 51 05                    	leal	5(%rcx), %edx
1000027a8: 80 e2 7f                    	andb	$127, %dl
1000027ab: 80 c2 1a                    	addb	$26, %dl
1000027ae: 89 c8                       	movl	%ecx, %eax
1000027b0: f6 d0                       	notb	%al
1000027b2: 20 d0                       	andb	%dl, %al
1000027b4: c0 f8 02                    	sarb	$2, %al
1000027b7: 24 e0                       	andb	$-32, %al
1000027b9: 00 c8                       	addb	%cl, %al
1000027bb: 42 88 04 07                 	movb	%al, (%rdi,%r8)
1000027bf: 49 ff c0                    	incq	%r8
1000027c2: 4c 39 c6                    	cmpq	%r8, %rsi
1000027c5: 75 d9                       	jne	-39 <_naive_to_upper+0x150>
1000027c7: 5d                          	popq	%rbp
1000027c8: c5 f8 77                    	vzeroupper
1000027cb: c3                          	retq
1000027cc: 0f 1f 40 00                 	nopl	(%rax)

00000001000027d0 _naive_to_lower:
1000027d0: 55                          	pushq	%rbp
1000027d1: 48 89 e5                    	movq	%rsp, %rbp
1000027d4: 48 85 f6                    	testq	%rsi, %rsi
1000027d7: 0f 84 2a 01 00 00           	je	298 <_naive_to_lower+0x137>
1000027dd: 48 83 fe 7f                 	cmpq	$127, %rsi
1000027e1: 77 08                       	ja	8 <_naive_to_lower+0x1b>
1000027e3: 45 31 c0                    	xorl	%r8d, %r8d
1000027e6: e9 f5 00 00 00              	jmp	245 <_naive_to_lower+0x110>
1000027eb: 49 89 f0                    	movq	%rsi, %r8
1000027ee: 49 83 e0 80                 	andq	$-128, %r8
1000027f2: 31 c9                       	xorl	%ecx, %ecx
1000027f4: c5 fd 6f 05 a4 16 00 00     	vmovdqa	5796(%rip), %ymm0
1000027fc: c5 fd 6f 0d bc 16 00 00     	vmovdqa	5820(%rip), %ymm1
100002804: c5 fd 6f 15 d4 16 00 00     	vmovdqa	5844(%rip), %ymm2
10000280c: c5 fd 6f 1d ec 16 00 00     	vmovdqa	5868(%rip), %ymm3
100002814: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000281e: 66 90                       	nop
100002820: c5 fe 6f 24 0f              	vmovdqu	(%rdi,%rcx), %ymm4
100002825: c5 fe 6f 6c 0f 20           	vmovdqu	32(%rdi,%rcx), %ymm5
10000282b: c5 fe 6f 74 0f 40           	vmovdqu	64(%rdi,%rcx), %ymm6
100002831: c5 fe 6f 7c 0f 60           	vmovdqu	96(%rdi,%rcx), %ymm7
100002837: c5 5d fc c0                 	vpaddb	%ymm0, %ymm4, %ymm8
10000283b: c5 55 fc c8                 	vpaddb	%ymm0, %ymm5, %ymm9
10000283f: c5 4d fc d0                 	vpaddb	%ymm0, %ymm6, %ymm10
100002843: c5 45 fc d8                 	vpaddb	%ymm0, %ymm7, %ymm11
100002847: c5 3d db c1                 	vpand	%ymm1, %ymm8, %ymm8
10000284b: c5 35 db c9                 	vpand	%ymm1, %ymm9, %ymm9
10000284f: c5 2d db d1                 	vpand	%ymm1, %ymm10, %ymm10
100002853: c5 25 db d9                 	vpand	%ymm1, %ymm11, %ymm11
100002857: c5 3d fc c2                 	vpaddb	%ymm2, %ymm8, %ymm8
10000285b: c5 35 fc ca                 	vpaddb	%ymm2, %ymm9, %ymm9
10000285f: c5 2d fc d2                 	vpaddb	%ymm2, %ymm10, %ymm10
100002863: c5 25 fc da                 	vpaddb	%ymm2, %ymm11, %ymm11
100002867: c4 41 5d df c0              	vpandn	%ymm8, %ymm4, %ymm8
10000286c: c4 41 55 df c9              	vpandn	%ymm9, %ymm5, %ymm9
100002871: c4 41 4d df d2              	vpandn	%ymm10, %ymm6, %ymm10
100002876: c4 41 45 df db              	vpandn	%ymm11, %ymm7, %ymm11
10000287b: c4 c1 3d 71 d0 02           	vpsrlw	$2, %ymm8, %ymm8
100002881: c4 c1 35 71 d1 02           	vpsrlw	$2, %ymm9, %ymm9
100002887: c4 c1 2d 71 d2 02           	vpsrlw	$2, %ymm10, %ymm10
10000288d: c4 c1 25 71 d3 02           	vpsrlw	$2, %ymm11, %ymm11
100002893: c5 3d db c3                 	vpand	%ymm3, %ymm8, %ymm8
100002897: c5 35 db cb                 	vpand	%ymm3, %ymm9, %ymm9
10000289b: c5 2d db d3                 	vpand	%ymm3, %ymm10, %ymm10
10000289f: c5 25 db db                 	vpand	%ymm3, %ymm11, %ymm11
1000028a3: c5 bd fc e4                 	vpaddb	%ymm4, %ymm8, %ymm4
1000028a7: c5 b5 fc ed                 	vpaddb	%ymm5, %ymm9, %ymm5
1000028ab: c5 ad fc f6                 	vpaddb	%ymm6, %ymm10, %ymm6
1000028af: c5 a5 fc ff                 	vpaddb	%ymm7, %ymm11, %ymm7
1000028b3: c5 fe 7f 24 0f              	vmovdqu	%ymm4, (%rdi,%rcx)
1000028b8: c5 fe 7f 6c 0f 20           	vmovdqu	%ymm5, 32(%rdi,%rcx)
1000028be: c5 fe 7f 74 0f 40           	vmovdqu	%ymm6, 64(%rdi,%rcx)
1000028c4: c5 fe 7f 7c 0f 60           	vmovdqu	%ymm7, 96(%rdi,%rcx)
1000028ca: 48 83 e9 80                 	subq	$-128, %rcx
1000028ce: 49 39 c8                    	cmpq	%rcx, %r8
1000028d1: 0f 85 49 ff ff ff           	jne	-183 <_naive_to_lower+0x50>
1000028d7: 49 39 f0                    	cmpq	%rsi, %r8
1000028da: 74 2b                       	je	43 <_naive_to_lower+0x137>
1000028dc: 0f 1f 40 00                 	nopl	(%rax)
1000028e0: 42 0f b6 0c 07              	movzbl	(%rdi,%r8), %ecx
1000028e5: 8d 51 25                    	leal	37(%rcx), %edx
1000028e8: 80 e2 7f                    	andb	$127, %dl
1000028eb: 80 c2 1a                    	addb	$26, %dl
1000028ee: 89 c8                       	movl	%ecx, %eax
1000028f0: f6 d0                       	notb	%al
1000028f2: 20 d0                       	andb	%dl, %al
1000028f4: c0 e8 02                    	shrb	$2, %al
1000028f7: 24 20                       	andb	$32, %al
1000028f9: 00 c8                       	addb	%cl, %al
1000028fb: 42 88 04 07                 	movb	%al, (%rdi,%r8)
1000028ff: 49 ff c0                    	incq	%r8
100002902: 4c 39 c6                    	cmpq	%r8, %rsi
100002905: 75 d9                       	jne	-39 <_naive_to_lower+0x110>
100002907: 5d                          	popq	%rbp
100002908: c5 f8 77                    	vzeroupper
10000290b: c3                          	retq
10000290c: 0f 1f 40 00                 	nopl	(%rax)

0000000100002910 _calc_avg_times_upper:
100002910: 55                          	pushq	%rbp
100002911: 48 89 e5                    	movq	%rsp, %rbp
100002914: 41 57                       	pushq	%r15
100002916: 41 56                       	pushq	%r14
100002918: 41 55                       	pushq	%r13
10000291a: 41 54                       	pushq	%r12
10000291c: 53                          	pushq	%rbx
10000291d: 48 81 ec 98 00 00 00        	subq	$152, %rsp
100002924: 4d 89 cc                    	movq	%r9, %r12
100002927: 44 89 45 b0                 	movl	%r8d, -80(%rbp)
10000292b: 48 89 8d 40 ff ff ff        	movq	%rcx, -192(%rbp)
100002932: 48 89 95 48 ff ff ff        	movq	%rdx, -184(%rbp)
100002939: 41 89 f7                    	movl	%esi, %r15d
10000293c: 49 89 fd                    	movq	%rdi, %r13
10000293f: 49 8d 1c 39                 	leaq	(%r9,%rdi), %rbx
100002943: 48 ff c3                    	incq	%rbx
100002946: 49 ff c4                    	incq	%r12
100002949: 48 89 df                    	movq	%rbx, %rdi
10000294c: e8 b5 13 00 00              	callq	5045 <dyld_stub_binder+0x100003d06>
100002951: 49 89 c6                    	movq	%rax, %r14
100002954: 48 89 df                    	movq	%rbx, %rdi
100002957: e8 aa 13 00 00              	callq	5034 <dyld_stub_binder+0x100003d06>
10000295c: 48 89 45 a8                 	movq	%rax, -88(%rbp)
100002960: 48 89 df                    	movq	%rbx, %rdi
100002963: e8 9e 13 00 00              	callq	5022 <dyld_stub_binder+0x100003d06>
100002968: 48 89 45 98                 	movq	%rax, -104(%rbp)
10000296c: 44 89 7d b4                 	movl	%r15d, -76(%rbp)
100002970: 41 d1 ef                    	shrl	%r15d
100002973: 44 89 7d d4                 	movl	%r15d, -44(%rbp)
100002977: 4c 89 a5 50 ff ff ff        	movq	%r12, -176(%rbp)
10000297e: 0f 84 b0 01 00 00           	je	432 <_calc_avg_times_upper+0x224>
100002984: 31 c9                       	xorl	%ecx, %ecx
100002986: 4d 85 ed                    	testq	%r13, %r13
100002989: 0f 84 65 05 00 00           	je	1381 <_calc_avg_times_upper+0x5e4>
10000298f: 45 31 ff                    	xorl	%r15d, %r15d
100002992: 31 c0                       	xorl	%eax, %eax
100002994: eb 37                       	jmp	55 <_calc_avg_times_upper+0xbd>
100002996: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000029a0: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
1000029a7: 48 01 c1                    	addq	%rax, %rcx
1000029aa: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
1000029b1: 4c 8b 7d c0                 	movq	-64(%rbp), %r15
1000029b5: 49 01 c7                    	addq	%rax, %r15
1000029b8: 8b 45 a4                    	movl	-92(%rbp), %eax
1000029bb: ff c0                       	incl	%eax
1000029bd: 3b 45 d4                    	cmpl	-44(%rbp), %eax
1000029c0: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
1000029c7: 0f 84 6c 01 00 00           	je	364 <_calc_avg_times_upper+0x229>
1000029cd: 4c 89 7d c0                 	movq	%r15, -64(%rbp)
1000029d1: 89 45 a4                    	movl	%eax, -92(%rbp)
1000029d4: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000029d8: e8 41 13 00 00              	callq	4929 <dyld_stub_binder+0x100003d1e>
1000029dd: 48 63 c8                    	movslq	%eax, %rcx
1000029e0: 48 89 ca                    	movq	%rcx, %rdx
1000029e3: 4c 09 e2                    	orq	%r12, %rdx
1000029e6: 48 c1 ea 20                 	shrq	$32, %rdx
1000029ea: 74 14                       	je	20 <_calc_avg_times_upper+0xf0>
1000029ec: 48 89 c8                    	movq	%rcx, %rax
1000029ef: 31 d2                       	xorl	%edx, %edx
1000029f1: 49 f7 f4                    	divq	%r12
1000029f4: 49 89 d7                    	movq	%rdx, %r15
1000029f7: eb 0f                       	jmp	15 <_calc_avg_times_upper+0xf8>
1000029f9: 0f 1f 80 00 00 00 00        	nopl	(%rax)
100002a00: 31 d2                       	xorl	%edx, %edx
100002a02: 41 f7 f4                    	divl	%r12d
100002a05: 41 89 d7                    	movl	%edx, %r15d
100002a08: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002a0c: 4c 01 f8                    	addq	%r15, %rax
100002a0f: 48 89 45 b8                 	movq	%rax, -72(%rbp)
100002a13: 45 31 e4                    	xorl	%r12d, %r12d
100002a16: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002a20: e8 f9 12 00 00              	callq	4857 <dyld_stub_binder+0x100003d1e>
100002a25: 48 98                       	cltq
100002a27: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
100002a2e: 48 c1 e9 20                 	shrq	$32, %rcx
100002a32: 01 c1                       	addl	%eax, %ecx
100002a34: 89 ca                       	movl	%ecx, %edx
100002a36: c1 ea 1f                    	shrl	$31, %edx
100002a39: c1 e9 06                    	shrl	$6, %ecx
100002a3c: 01 d1                       	addl	%edx, %ecx
100002a3e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002a41: 29 c8                       	subl	%ecx, %eax
100002a43: 04 20                       	addb	$32, %al
100002a45: 43 88 04 26                 	movb	%al, (%r14,%r12)
100002a49: 49 ff c4                    	incq	%r12
100002a4c: 4d 39 e5                    	cmpq	%r12, %r13
100002a4f: 75 cf                       	jne	-49 <_calc_avg_times_upper+0x110>
100002a51: 4c 03 7d 98                 	addq	-104(%rbp), %r15
100002a55: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002a5a: 48 8b 5d b8                 	movq	-72(%rbp), %rbx
100002a5e: 48 89 df                    	movq	%rbx, %rdi
100002a61: 4c 89 f6                    	movq	%r14, %rsi
100002a64: e8 c7 12 00 00              	callq	4807 <dyld_stub_binder+0x100003d30>
100002a69: 4c 89 ff                    	movq	%r15, %rdi
100002a6c: 4c 89 f6                    	movq	%r14, %rsi
100002a6f: e8 bc 12 00 00              	callq	4796 <dyld_stub_binder+0x100003d30>
100002a74: bf 06 00 00 00              	movl	$6, %edi
100002a79: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002a80: e8 75 12 00 00              	callq	4725 <dyld_stub_binder+0x100003cfa>
100002a85: 48 89 df                    	movq	%rbx, %rdi
100002a88: 4c 89 ee                    	movq	%r13, %rsi
100002a8b: e8 c0 fb ff ff              	callq	-1088 <_naive_to_upper>
100002a90: bf 06 00 00 00              	movl	$6, %edi
100002a95: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002a9c: e8 59 12 00 00              	callq	4697 <dyld_stub_binder+0x100003cfa>
100002aa1: bf 06 00 00 00              	movl	$6, %edi
100002aa6: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002aad: e8 48 12 00 00              	callq	4680 <dyld_stub_binder+0x100003cfa>
100002ab2: 4c 89 ff                    	movq	%r15, %rdi
100002ab5: 4c 89 ee                    	movq	%r13, %rsi
100002ab8: e8 e3 0f 00 00              	callq	4067 <_to_upper>
100002abd: bf 06 00 00 00              	movl	$6, %edi
100002ac2: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002ac6: e8 2f 12 00 00              	callq	4655 <dyld_stub_binder+0x100003cfa>
100002acb: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100002ad2: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100002ad9: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002add: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100002ae4: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100002aeb: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002aef: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002af6: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
100002afa: 48 03 55 90                 	addq	-112(%rbp), %rdx
100002afe: 48 2b 55 80                 	subq	-128(%rbp), %rdx
100002b02: 48 89 55 c0                 	movq	%rdx, -64(%rbp)
100002b06: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
100002b0a: 0f 84 90 fe ff ff           	je	-368 <_calc_avg_times_upper+0x90>
100002b10: 48 8b 7d b8                 	movq	-72(%rbp), %rdi
100002b14: 4c 89 fe                    	movq	%r15, %rsi
100002b17: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002b1b: e8 0a 12 00 00              	callq	4618 <dyld_stub_binder+0x100003d2a>
100002b20: 4c 89 fa                    	movq	%r15, %rdx
100002b23: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002b27: 85 c0                       	testl	%eax, %eax
100002b29: 0f 84 71 fe ff ff           	je	-399 <_calc_avg_times_upper+0x90>
100002b2f: e9 18 05 00 00              	jmp	1304 <_calc_avg_times_upper+0x73c>
100002b34: 45 31 ff                    	xorl	%r15d, %r15d
100002b37: 31 c9                       	xorl	%ecx, %ecx
100002b39: 8b 45 d4                    	movl	-44(%rbp), %eax
100002b3c: 3b 45 b4                    	cmpl	-76(%rbp), %eax
100002b3f: 0f 83 1f 03 00 00           	jae	799 <_calc_avg_times_upper+0x554>
100002b45: 4d 85 ed                    	testq	%r13, %r13
100002b48: 75 42                       	jne	66 <_calc_avg_times_upper+0x27c>
100002b4a: 8b 45 b4                    	movl	-76(%rbp), %eax
100002b4d: 2b 45 d4                    	subl	-44(%rbp), %eax
100002b50: e9 d1 01 00 00              	jmp	465 <_calc_avg_times_upper+0x416>
100002b55: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002b5f: 90                          	nop
100002b60: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100002b67: 48 01 c1                    	addq	%rax, %rcx
100002b6a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002b71: 49 01 c7                    	addq	%rax, %r15
100002b74: 8b 45 d4                    	movl	-44(%rbp), %eax
100002b77: ff c0                       	incl	%eax
100002b79: 89 45 d4                    	movl	%eax, -44(%rbp)
100002b7c: 3b 45 b4                    	cmpl	-76(%rbp), %eax
100002b7f: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
100002b86: 0f 84 d8 02 00 00           	je	728 <_calc_avg_times_upper+0x554>
100002b8c: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002b90: e8 89 11 00 00              	callq	4489 <dyld_stub_binder+0x100003d1e>
100002b95: 48 63 c8                    	movslq	%eax, %rcx
100002b98: 48 89 ca                    	movq	%rcx, %rdx
100002b9b: 4c 09 e2                    	orq	%r12, %rdx
100002b9e: 48 c1 ea 20                 	shrq	$32, %rdx
100002ba2: 74 1c                       	je	28 <_calc_avg_times_upper+0x2b0>
100002ba4: 48 89 c8                    	movq	%rcx, %rax
100002ba7: 31 d2                       	xorl	%edx, %edx
100002ba9: 49 f7 f4                    	divq	%r12
100002bac: 48 89 d3                    	movq	%rdx, %rbx
100002baf: eb 16                       	jmp	22 <_calc_avg_times_upper+0x2b7>
100002bb1: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002bbb: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100002bc0: 31 d2                       	xorl	%edx, %edx
100002bc2: 41 f7 f4                    	divl	%r12d
100002bc5: 89 d3                       	movl	%edx, %ebx
100002bc7: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002bcb: 48 01 d8                    	addq	%rbx, %rax
100002bce: 48 89 45 c0                 	movq	%rax, -64(%rbp)
100002bd2: 45 31 e4                    	xorl	%r12d, %r12d
100002bd5: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002bdf: 90                          	nop
100002be0: e8 39 11 00 00              	callq	4409 <dyld_stub_binder+0x100003d1e>
100002be5: 48 98                       	cltq
100002be7: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
100002bee: 48 c1 e9 20                 	shrq	$32, %rcx
100002bf2: 01 c1                       	addl	%eax, %ecx
100002bf4: 89 ca                       	movl	%ecx, %edx
100002bf6: c1 ea 1f                    	shrl	$31, %edx
100002bf9: c1 e9 06                    	shrl	$6, %ecx
100002bfc: 01 d1                       	addl	%edx, %ecx
100002bfe: 6b c9 5f                    	imull	$95, %ecx, %ecx
100002c01: 29 c8                       	subl	%ecx, %eax
100002c03: 04 20                       	addb	$32, %al
100002c05: 43 88 04 26                 	movb	%al, (%r14,%r12)
100002c09: 49 ff c4                    	incq	%r12
100002c0c: 4d 39 e5                    	cmpq	%r12, %r13
100002c0f: 75 cf                       	jne	-49 <_calc_avg_times_upper+0x2d0>
100002c11: 48 03 5d 98                 	addq	-104(%rbp), %rbx
100002c15: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002c1a: 49 89 dc                    	movq	%rbx, %r12
100002c1d: 48 8b 5d c0                 	movq	-64(%rbp), %rbx
100002c21: 48 89 df                    	movq	%rbx, %rdi
100002c24: 4c 89 f6                    	movq	%r14, %rsi
100002c27: e8 04 11 00 00              	callq	4356 <dyld_stub_binder+0x100003d30>
100002c2c: 4c 89 e7                    	movq	%r12, %rdi
100002c2f: 4c 89 f6                    	movq	%r14, %rsi
100002c32: e8 f9 10 00 00              	callq	4345 <dyld_stub_binder+0x100003d30>
100002c37: bf 06 00 00 00              	movl	$6, %edi
100002c3c: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002c43: e8 b2 10 00 00              	callq	4274 <dyld_stub_binder+0x100003cfa>
100002c48: 48 89 df                    	movq	%rbx, %rdi
100002c4b: 4c 89 ee                    	movq	%r13, %rsi
100002c4e: e8 4d 0e 00 00              	callq	3661 <_to_upper>
100002c53: bf 06 00 00 00              	movl	$6, %edi
100002c58: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002c5c: e8 99 10 00 00              	callq	4249 <dyld_stub_binder+0x100003cfa>
100002c61: bf 06 00 00 00              	movl	$6, %edi
100002c66: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002c6d: e8 88 10 00 00              	callq	4232 <dyld_stub_binder+0x100003cfa>
100002c72: 4c 89 e3                    	movq	%r12, %rbx
100002c75: 4c 89 e7                    	movq	%r12, %rdi
100002c78: 4c 89 ee                    	movq	%r13, %rsi
100002c7b: e8 d0 f9 ff ff              	callq	-1584 <_naive_to_upper>
100002c80: bf 06 00 00 00              	movl	$6, %edi
100002c85: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002c8c: e8 69 10 00 00              	callq	4201 <dyld_stub_binder+0x100003cfa>
100002c91: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100002c98: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100002c9f: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002ca3: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100002caa: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100002cb1: 48 89 d8                    	movq	%rbx, %rax
100002cb4: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002cb8: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002cbf: 4c 03 7d 90                 	addq	-112(%rbp), %r15
100002cc3: 4c 2b 7d 80                 	subq	-128(%rbp), %r15
100002cc7: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
100002ccb: 0f 84 8f fe ff ff           	je	-369 <_calc_avg_times_upper+0x250>
100002cd1: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100002cd5: 48 89 45 b8                 	movq	%rax, -72(%rbp)
100002cd9: 48 8b 75 b8                 	movq	-72(%rbp), %rsi
100002cdd: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002ce1: e8 44 10 00 00              	callq	4164 <dyld_stub_binder+0x100003d2a>
100002ce6: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
100002cea: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002cee: 85 c0                       	testl	%eax, %eax
100002cf0: 0f 84 6a fe ff ff           	je	-406 <_calc_avg_times_upper+0x250>
100002cf6: e9 41 01 00 00              	jmp	321 <_calc_avg_times_upper+0x52c>
100002cfb: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100002d00: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100002d07: 48 01 c1                    	addq	%rax, %rcx
100002d0a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002d11: 49 01 c7                    	addq	%rax, %r15
100002d14: 8b 45 d4                    	movl	-44(%rbp), %eax
100002d17: ff c8                       	decl	%eax
100002d19: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
100002d20: 0f 84 3e 01 00 00           	je	318 <_calc_avg_times_upper+0x554>
100002d26: 89 45 d4                    	movl	%eax, -44(%rbp)
100002d29: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002d2d: e8 ec 0f 00 00              	callq	4076 <dyld_stub_binder+0x100003d1e>
100002d32: 48 63 c8                    	movslq	%eax, %rcx
100002d35: 48 89 ca                    	movq	%rcx, %rdx
100002d38: 4c 09 e2                    	orq	%r12, %rdx
100002d3b: 48 c1 ea 20                 	shrq	$32, %rdx
100002d3f: 74 0f                       	je	15 <_calc_avg_times_upper+0x440>
100002d41: 48 89 c8                    	movq	%rcx, %rax
100002d44: 31 d2                       	xorl	%edx, %edx
100002d46: 49 f7 f4                    	divq	%r12
100002d49: 48 89 d3                    	movq	%rdx, %rbx
100002d4c: eb 09                       	jmp	9 <_calc_avg_times_upper+0x447>
100002d4e: 66 90                       	nop
100002d50: 31 d2                       	xorl	%edx, %edx
100002d52: 41 f7 f4                    	divl	%r12d
100002d55: 89 d3                       	movl	%edx, %ebx
100002d57: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002d5b: 4c 8d 24 18                 	leaq	(%rax,%rbx), %r12
100002d5f: 48 03 5d 98                 	addq	-104(%rbp), %rbx
100002d63: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002d68: 4c 89 e7                    	movq	%r12, %rdi
100002d6b: 4c 89 f6                    	movq	%r14, %rsi
100002d6e: e8 bd 0f 00 00              	callq	4029 <dyld_stub_binder+0x100003d30>
100002d73: 48 89 df                    	movq	%rbx, %rdi
100002d76: 4c 89 f6                    	movq	%r14, %rsi
100002d79: e8 b2 0f 00 00              	callq	4018 <dyld_stub_binder+0x100003d30>
100002d7e: bf 06 00 00 00              	movl	$6, %edi
100002d83: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002d8a: e8 6b 0f 00 00              	callq	3947 <dyld_stub_binder+0x100003cfa>
100002d8f: 4c 89 65 c0                 	movq	%r12, -64(%rbp)
100002d93: 4c 89 e7                    	movq	%r12, %rdi
100002d96: 31 f6                       	xorl	%esi, %esi
100002d98: e8 03 0d 00 00              	callq	3331 <_to_upper>
100002d9d: bf 06 00 00 00              	movl	$6, %edi
100002da2: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002da6: e8 4f 0f 00 00              	callq	3919 <dyld_stub_binder+0x100003cfa>
100002dab: bf 06 00 00 00              	movl	$6, %edi
100002db0: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002db7: e8 3e 0f 00 00              	callq	3902 <dyld_stub_binder+0x100003cfa>
100002dbc: 48 89 df                    	movq	%rbx, %rdi
100002dbf: 31 f6                       	xorl	%esi, %esi
100002dc1: e8 8a f8 ff ff              	callq	-1910 <_naive_to_upper>
100002dc6: bf 06 00 00 00              	movl	$6, %edi
100002dcb: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002dd2: e8 23 0f 00 00              	callq	3875 <dyld_stub_binder+0x100003cfa>
100002dd7: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100002dde: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100002de5: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002de9: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100002df0: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100002df7: 48 89 d8                    	movq	%rbx, %rax
100002dfa: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100002dfe: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100002e05: 4c 03 7d 90                 	addq	-112(%rbp), %r15
100002e09: 4c 2b 7d 80                 	subq	-128(%rbp), %r15
100002e0d: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
100002e11: 0f 84 e9 fe ff ff           	je	-279 <_calc_avg_times_upper+0x3f0>
100002e17: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100002e1b: 48 89 45 b8                 	movq	%rax, -72(%rbp)
100002e1f: 48 8b 75 b8                 	movq	-72(%rbp), %rsi
100002e23: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002e27: e8 fe 0e 00 00              	callq	3838 <dyld_stub_binder+0x100003d2a>
100002e2c: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
100002e30: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002e34: 85 c0                       	testl	%eax, %eax
100002e36: 0f 84 c4 fe ff ff           	je	-316 <_calc_avg_times_upper+0x3f0>
100002e3c: 48 8d 3d 05 11 00 00        	leaq	4357(%rip), %rdi
100002e43: 48 89 d3                    	movq	%rdx, %rbx
100002e46: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
100002e4a: 4c 89 f2                    	movq	%r14, %rdx
100002e4d: 31 c0                       	xorl	%eax, %eax
100002e4f: e8 b8 0e 00 00              	callq	3768 <dyld_stub_binder+0x100003d0c>
100002e54: 48 8d 3d fd 10 00 00        	leaq	4349(%rip), %rdi
100002e5b: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
100002e5f: e9 0b 02 00 00              	jmp	523 <_calc_avg_times_upper+0x75f>
100002e64: c4 e1 f9 6e c1              	vmovq	%rcx, %xmm0
100002e69: c5 f9 6f 0d af 10 00 00     	vmovdqa	4271(%rip), %xmm1
100002e71: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100002e75: c5 f9 28 15 b3 10 00 00     	vmovapd	4275(%rip), %xmm2
100002e7d: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100002e81: c4 e3 79 05 d8 01           	vpermilpd	$1, %xmm0, %xmm3
100002e87: 8b 45 b4                    	movl	-76(%rbp), %eax
100002e8a: c4 e1 db 2a e0              	vcvtsi2sd	%rax, %xmm4, %xmm4
100002e8f: c5 db 59 25 a9 10 00 00     	vmulsd	4265(%rip), %xmm4, %xmm4
100002e97: c5 e3 58 c0                 	vaddsd	%xmm0, %xmm3, %xmm0
100002e9b: c5 fb 5e c4                 	vdivsd	%xmm4, %xmm0, %xmm0
100002e9f: 48 8b 85 48 ff ff ff        	movq	-184(%rbp), %rax
100002ea6: c5 fb 11 00                 	vmovsd	%xmm0, (%rax)
100002eaa: c4 c1 f9 6e c7              	vmovq	%r15, %xmm0
100002eaf: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100002eb3: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100002eb7: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100002ebd: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100002ec1: c5 fb 5e c4                 	vdivsd	%xmm4, %xmm0, %xmm0
100002ec5: 48 8b 85 40 ff ff ff        	movq	-192(%rbp), %rax
100002ecc: c5 fb 11 00                 	vmovsd	%xmm0, (%rax)
100002ed0: 48 8b 7d a8                 	movq	-88(%rbp), %rdi
100002ed4: e8 27 0e 00 00              	callq	3623 <dyld_stub_binder+0x100003d00>
100002ed9: 48 8b 7d 98                 	movq	-104(%rbp), %rdi
100002edd: e8 1e 0e 00 00              	callq	3614 <dyld_stub_binder+0x100003d00>
100002ee2: 48 81 c4 98 00 00 00        	addq	$152, %rsp
100002ee9: 5b                          	popq	%rbx
100002eea: 41 5c                       	popq	%r12
100002eec: 41 5d                       	popq	%r13
100002eee: 41 5e                       	popq	%r14
100002ef0: 41 5f                       	popq	%r15
100002ef2: 5d                          	popq	%rbp
100002ef3: c3                          	retq
100002ef4: 8b 45 d4                    	movl	-44(%rbp), %eax
100002ef7: 45 31 ff                    	xorl	%r15d, %r15d
100002efa: eb 2e                       	jmp	46 <_calc_avg_times_upper+0x61a>
100002efc: 0f 1f 40 00                 	nopl	(%rax)
100002f00: 49 69 c7 00 ca 9a 3b        	imulq	$1000000000, %r15, %rax
100002f07: 48 01 c1                    	addq	%rax, %rcx
100002f0a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100002f11: 4c 8b 7d c0                 	movq	-64(%rbp), %r15
100002f15: 49 01 c7                    	addq	%rax, %r15
100002f18: 8b 45 a4                    	movl	-92(%rbp), %eax
100002f1b: ff c8                       	decl	%eax
100002f1d: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
100002f24: 0f 84 0f fc ff ff           	je	-1009 <_calc_avg_times_upper+0x229>
100002f2a: 89 45 a4                    	movl	%eax, -92(%rbp)
100002f2d: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100002f31: e8 e8 0d 00 00              	callq	3560 <dyld_stub_binder+0x100003d1e>
100002f36: 48 63 c8                    	movslq	%eax, %rcx
100002f39: 48 89 ca                    	movq	%rcx, %rdx
100002f3c: 4c 09 e2                    	orq	%r12, %rdx
100002f3f: 48 c1 ea 20                 	shrq	$32, %rdx
100002f43: 4c 89 7d c0                 	movq	%r15, -64(%rbp)
100002f47: 74 17                       	je	23 <_calc_avg_times_upper+0x650>
100002f49: 48 89 c8                    	movq	%rcx, %rax
100002f4c: 31 d2                       	xorl	%edx, %edx
100002f4e: 49 f7 f4                    	divq	%r12
100002f51: 49 89 d4                    	movq	%rdx, %r12
100002f54: eb 12                       	jmp	18 <_calc_avg_times_upper+0x658>
100002f56: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100002f60: 31 d2                       	xorl	%edx, %edx
100002f62: 41 f7 f4                    	divl	%r12d
100002f65: 41 89 d4                    	movl	%edx, %r12d
100002f68: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100002f6c: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
100002f70: 4c 03 65 98                 	addq	-104(%rbp), %r12
100002f74: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100002f79: 48 89 df                    	movq	%rbx, %rdi
100002f7c: 4c 89 f6                    	movq	%r14, %rsi
100002f7f: e8 ac 0d 00 00              	callq	3500 <dyld_stub_binder+0x100003d30>
100002f84: 4c 89 e7                    	movq	%r12, %rdi
100002f87: 4c 89 f6                    	movq	%r14, %rsi
100002f8a: e8 a1 0d 00 00              	callq	3489 <dyld_stub_binder+0x100003d30>
100002f8f: bf 06 00 00 00              	movl	$6, %edi
100002f94: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100002f9b: e8 5a 0d 00 00              	callq	3418 <dyld_stub_binder+0x100003cfa>
100002fa0: 48 89 5d b8                 	movq	%rbx, -72(%rbp)
100002fa4: 48 89 df                    	movq	%rbx, %rdi
100002fa7: 31 f6                       	xorl	%esi, %esi
100002fa9: e8 a2 f6 ff ff              	callq	-2398 <_naive_to_upper>
100002fae: bf 06 00 00 00              	movl	$6, %edi
100002fb3: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100002fba: e8 3b 0d 00 00              	callq	3387 <dyld_stub_binder+0x100003cfa>
100002fbf: bf 06 00 00 00              	movl	$6, %edi
100002fc4: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
100002fcb: e8 2a 0d 00 00              	callq	3370 <dyld_stub_binder+0x100003cfa>
100002fd0: 4c 89 e7                    	movq	%r12, %rdi
100002fd3: 31 f6                       	xorl	%esi, %esi
100002fd5: e8 c6 0a 00 00              	callq	2758 <_to_upper>
100002fda: bf 06 00 00 00              	movl	$6, %edi
100002fdf: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100002fe3: e8 12 0d 00 00              	callq	3346 <dyld_stub_binder+0x100003cfa>
100002fe8: 4c 8b bd 68 ff ff ff        	movq	-152(%rbp), %r15
100002fef: 4c 2b bd 58 ff ff ff        	subq	-168(%rbp), %r15
100002ff6: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100002ffa: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100003001: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100003008: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
10000300c: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100003013: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
100003017: 48 03 55 90                 	addq	-112(%rbp), %rdx
10000301b: 48 2b 55 80                 	subq	-128(%rbp), %rdx
10000301f: 48 89 55 c0                 	movq	%rdx, -64(%rbp)
100003023: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
100003027: 0f 84 d3 fe ff ff           	je	-301 <_calc_avg_times_upper+0x5f0>
10000302d: 48 8b 7d b8                 	movq	-72(%rbp), %rdi
100003031: 4c 89 e6                    	movq	%r12, %rsi
100003034: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100003038: e8 ed 0c 00 00              	callq	3309 <dyld_stub_binder+0x100003d2a>
10000303d: 4c 89 e2                    	movq	%r12, %rdx
100003040: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100003044: 85 c0                       	testl	%eax, %eax
100003046: 0f 84 b4 fe ff ff           	je	-332 <_calc_avg_times_upper+0x5f0>
10000304c: 48 8d 3d f5 0e 00 00        	leaq	3829(%rip), %rdi
100003053: 48 89 d3                    	movq	%rdx, %rbx
100003056: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
10000305a: 4c 89 f2                    	movq	%r14, %rdx
10000305d: 31 c0                       	xorl	%eax, %eax
10000305f: e8 a8 0c 00 00              	callq	3240 <dyld_stub_binder+0x100003d0c>
100003064: 48 8d 3d ed 0e 00 00        	leaq	3821(%rip), %rdi
10000306b: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
10000306f: 48 89 d6                    	movq	%rdx, %rsi
100003072: 31 c0                       	xorl	%eax, %eax
100003074: e8 93 0c 00 00              	callq	3219 <dyld_stub_binder+0x100003d0c>
100003079: 48 8d 3d e8 0e 00 00        	leaq	3816(%rip), %rdi
100003080: 48 89 de                    	movq	%rbx, %rsi
100003083: 48 89 da                    	movq	%rbx, %rdx
100003086: 31 c0                       	xorl	%eax, %eax
100003088: e8 7f 0c 00 00              	callq	3199 <dyld_stub_binder+0x100003d0c>
10000308d: e8 62 0c 00 00              	callq	3170 <dyld_stub_binder+0x100003cf4>
100003092: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000309c: 0f 1f 40 00                 	nopl	(%rax)

00000001000030a0 _calc_avg_times_lower:
1000030a0: 55                          	pushq	%rbp
1000030a1: 48 89 e5                    	movq	%rsp, %rbp
1000030a4: 41 57                       	pushq	%r15
1000030a6: 41 56                       	pushq	%r14
1000030a8: 41 55                       	pushq	%r13
1000030aa: 41 54                       	pushq	%r12
1000030ac: 53                          	pushq	%rbx
1000030ad: 48 81 ec 98 00 00 00        	subq	$152, %rsp
1000030b4: 4d 89 cc                    	movq	%r9, %r12
1000030b7: 44 89 45 b0                 	movl	%r8d, -80(%rbp)
1000030bb: 48 89 8d 40 ff ff ff        	movq	%rcx, -192(%rbp)
1000030c2: 48 89 95 48 ff ff ff        	movq	%rdx, -184(%rbp)
1000030c9: 41 89 f7                    	movl	%esi, %r15d
1000030cc: 49 89 fd                    	movq	%rdi, %r13
1000030cf: 49 8d 1c 39                 	leaq	(%r9,%rdi), %rbx
1000030d3: 48 ff c3                    	incq	%rbx
1000030d6: 49 ff c4                    	incq	%r12
1000030d9: 48 89 df                    	movq	%rbx, %rdi
1000030dc: e8 25 0c 00 00              	callq	3109 <dyld_stub_binder+0x100003d06>
1000030e1: 49 89 c6                    	movq	%rax, %r14
1000030e4: 48 89 df                    	movq	%rbx, %rdi
1000030e7: e8 1a 0c 00 00              	callq	3098 <dyld_stub_binder+0x100003d06>
1000030ec: 48 89 45 a8                 	movq	%rax, -88(%rbp)
1000030f0: 48 89 df                    	movq	%rbx, %rdi
1000030f3: e8 0e 0c 00 00              	callq	3086 <dyld_stub_binder+0x100003d06>
1000030f8: 48 89 45 98                 	movq	%rax, -104(%rbp)
1000030fc: 44 89 7d b4                 	movl	%r15d, -76(%rbp)
100003100: 41 d1 ef                    	shrl	%r15d
100003103: 44 89 7d d4                 	movl	%r15d, -44(%rbp)
100003107: 4c 89 a5 50 ff ff ff        	movq	%r12, -176(%rbp)
10000310e: 0f 84 b0 01 00 00           	je	432 <_calc_avg_times_lower+0x224>
100003114: 31 c9                       	xorl	%ecx, %ecx
100003116: 4d 85 ed                    	testq	%r13, %r13
100003119: 0f 84 65 05 00 00           	je	1381 <_calc_avg_times_lower+0x5e4>
10000311f: 45 31 ff                    	xorl	%r15d, %r15d
100003122: 31 c0                       	xorl	%eax, %eax
100003124: eb 37                       	jmp	55 <_calc_avg_times_lower+0xbd>
100003126: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100003130: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100003137: 48 01 c1                    	addq	%rax, %rcx
10000313a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100003141: 4c 8b 7d c0                 	movq	-64(%rbp), %r15
100003145: 49 01 c7                    	addq	%rax, %r15
100003148: 8b 45 a4                    	movl	-92(%rbp), %eax
10000314b: ff c0                       	incl	%eax
10000314d: 3b 45 d4                    	cmpl	-44(%rbp), %eax
100003150: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
100003157: 0f 84 6c 01 00 00           	je	364 <_calc_avg_times_lower+0x229>
10000315d: 4c 89 7d c0                 	movq	%r15, -64(%rbp)
100003161: 89 45 a4                    	movl	%eax, -92(%rbp)
100003164: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100003168: e8 b1 0b 00 00              	callq	2993 <dyld_stub_binder+0x100003d1e>
10000316d: 48 63 c8                    	movslq	%eax, %rcx
100003170: 48 89 ca                    	movq	%rcx, %rdx
100003173: 4c 09 e2                    	orq	%r12, %rdx
100003176: 48 c1 ea 20                 	shrq	$32, %rdx
10000317a: 74 14                       	je	20 <_calc_avg_times_lower+0xf0>
10000317c: 48 89 c8                    	movq	%rcx, %rax
10000317f: 31 d2                       	xorl	%edx, %edx
100003181: 49 f7 f4                    	divq	%r12
100003184: 49 89 d7                    	movq	%rdx, %r15
100003187: eb 0f                       	jmp	15 <_calc_avg_times_lower+0xf8>
100003189: 0f 1f 80 00 00 00 00        	nopl	(%rax)
100003190: 31 d2                       	xorl	%edx, %edx
100003192: 41 f7 f4                    	divl	%r12d
100003195: 41 89 d7                    	movl	%edx, %r15d
100003198: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000319c: 4c 01 f8                    	addq	%r15, %rax
10000319f: 48 89 45 b8                 	movq	%rax, -72(%rbp)
1000031a3: 45 31 e4                    	xorl	%r12d, %r12d
1000031a6: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000031b0: e8 69 0b 00 00              	callq	2921 <dyld_stub_binder+0x100003d1e>
1000031b5: 48 98                       	cltq
1000031b7: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
1000031be: 48 c1 e9 20                 	shrq	$32, %rcx
1000031c2: 01 c1                       	addl	%eax, %ecx
1000031c4: 89 ca                       	movl	%ecx, %edx
1000031c6: c1 ea 1f                    	shrl	$31, %edx
1000031c9: c1 e9 06                    	shrl	$6, %ecx
1000031cc: 01 d1                       	addl	%edx, %ecx
1000031ce: 6b c9 5f                    	imull	$95, %ecx, %ecx
1000031d1: 29 c8                       	subl	%ecx, %eax
1000031d3: 04 20                       	addb	$32, %al
1000031d5: 43 88 04 26                 	movb	%al, (%r14,%r12)
1000031d9: 49 ff c4                    	incq	%r12
1000031dc: 4d 39 e5                    	cmpq	%r12, %r13
1000031df: 75 cf                       	jne	-49 <_calc_avg_times_lower+0x110>
1000031e1: 4c 03 7d 98                 	addq	-104(%rbp), %r15
1000031e5: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
1000031ea: 48 8b 5d b8                 	movq	-72(%rbp), %rbx
1000031ee: 48 89 df                    	movq	%rbx, %rdi
1000031f1: 4c 89 f6                    	movq	%r14, %rsi
1000031f4: e8 37 0b 00 00              	callq	2871 <dyld_stub_binder+0x100003d30>
1000031f9: 4c 89 ff                    	movq	%r15, %rdi
1000031fc: 4c 89 f6                    	movq	%r14, %rsi
1000031ff: e8 2c 0b 00 00              	callq	2860 <dyld_stub_binder+0x100003d30>
100003204: bf 06 00 00 00              	movl	$6, %edi
100003209: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100003210: e8 e5 0a 00 00              	callq	2789 <dyld_stub_binder+0x100003cfa>
100003215: 48 89 df                    	movq	%rbx, %rdi
100003218: 4c 89 ee                    	movq	%r13, %rsi
10000321b: e8 b0 f5 ff ff              	callq	-2640 <_naive_to_lower>
100003220: bf 06 00 00 00              	movl	$6, %edi
100003225: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
10000322c: e8 c9 0a 00 00              	callq	2761 <dyld_stub_binder+0x100003cfa>
100003231: bf 06 00 00 00              	movl	$6, %edi
100003236: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000323d: e8 b8 0a 00 00              	callq	2744 <dyld_stub_binder+0x100003cfa>
100003242: 4c 89 ff                    	movq	%r15, %rdi
100003245: 4c 89 ee                    	movq	%r13, %rsi
100003248: e8 7c 09 00 00              	callq	2428 <_to_lower>
10000324d: bf 06 00 00 00              	movl	$6, %edi
100003252: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003256: e8 9f 0a 00 00              	callq	2719 <dyld_stub_binder+0x100003cfa>
10000325b: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100003262: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100003269: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
10000326d: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100003274: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
10000327b: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
10000327f: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100003286: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
10000328a: 48 03 55 90                 	addq	-112(%rbp), %rdx
10000328e: 48 2b 55 80                 	subq	-128(%rbp), %rdx
100003292: 48 89 55 c0                 	movq	%rdx, -64(%rbp)
100003296: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
10000329a: 0f 84 90 fe ff ff           	je	-368 <_calc_avg_times_lower+0x90>
1000032a0: 48 8b 7d b8                 	movq	-72(%rbp), %rdi
1000032a4: 4c 89 fe                    	movq	%r15, %rsi
1000032a7: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000032ab: e8 7a 0a 00 00              	callq	2682 <dyld_stub_binder+0x100003d2a>
1000032b0: 4c 89 fa                    	movq	%r15, %rdx
1000032b3: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
1000032b7: 85 c0                       	testl	%eax, %eax
1000032b9: 0f 84 71 fe ff ff           	je	-399 <_calc_avg_times_lower+0x90>
1000032bf: e9 18 05 00 00              	jmp	1304 <_calc_avg_times_lower+0x73c>
1000032c4: 45 31 ff                    	xorl	%r15d, %r15d
1000032c7: 31 c9                       	xorl	%ecx, %ecx
1000032c9: 8b 45 d4                    	movl	-44(%rbp), %eax
1000032cc: 3b 45 b4                    	cmpl	-76(%rbp), %eax
1000032cf: 0f 83 1f 03 00 00           	jae	799 <_calc_avg_times_lower+0x554>
1000032d5: 4d 85 ed                    	testq	%r13, %r13
1000032d8: 75 42                       	jne	66 <_calc_avg_times_lower+0x27c>
1000032da: 8b 45 b4                    	movl	-76(%rbp), %eax
1000032dd: 2b 45 d4                    	subl	-44(%rbp), %eax
1000032e0: e9 d1 01 00 00              	jmp	465 <_calc_avg_times_lower+0x416>
1000032e5: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000032ef: 90                          	nop
1000032f0: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
1000032f7: 48 01 c1                    	addq	%rax, %rcx
1000032fa: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
100003301: 49 01 c7                    	addq	%rax, %r15
100003304: 8b 45 d4                    	movl	-44(%rbp), %eax
100003307: ff c0                       	incl	%eax
100003309: 89 45 d4                    	movl	%eax, -44(%rbp)
10000330c: 3b 45 b4                    	cmpl	-76(%rbp), %eax
10000330f: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
100003316: 0f 84 d8 02 00 00           	je	728 <_calc_avg_times_lower+0x554>
10000331c: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100003320: e8 f9 09 00 00              	callq	2553 <dyld_stub_binder+0x100003d1e>
100003325: 48 63 c8                    	movslq	%eax, %rcx
100003328: 48 89 ca                    	movq	%rcx, %rdx
10000332b: 4c 09 e2                    	orq	%r12, %rdx
10000332e: 48 c1 ea 20                 	shrq	$32, %rdx
100003332: 74 1c                       	je	28 <_calc_avg_times_lower+0x2b0>
100003334: 48 89 c8                    	movq	%rcx, %rax
100003337: 31 d2                       	xorl	%edx, %edx
100003339: 49 f7 f4                    	divq	%r12
10000333c: 48 89 d3                    	movq	%rdx, %rbx
10000333f: eb 16                       	jmp	22 <_calc_avg_times_lower+0x2b7>
100003341: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000334b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100003350: 31 d2                       	xorl	%edx, %edx
100003352: 41 f7 f4                    	divl	%r12d
100003355: 89 d3                       	movl	%edx, %ebx
100003357: 48 8b 45 a8                 	movq	-88(%rbp), %rax
10000335b: 48 01 d8                    	addq	%rbx, %rax
10000335e: 48 89 45 c0                 	movq	%rax, -64(%rbp)
100003362: 45 31 e4                    	xorl	%r12d, %r12d
100003365: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000336f: 90                          	nop
100003370: e8 a9 09 00 00              	callq	2473 <dyld_stub_binder+0x100003d1e>
100003375: 48 98                       	cltq
100003377: 48 69 c8 85 91 76 ac        	imulq	$-1401515643, %rax, %rcx
10000337e: 48 c1 e9 20                 	shrq	$32, %rcx
100003382: 01 c1                       	addl	%eax, %ecx
100003384: 89 ca                       	movl	%ecx, %edx
100003386: c1 ea 1f                    	shrl	$31, %edx
100003389: c1 e9 06                    	shrl	$6, %ecx
10000338c: 01 d1                       	addl	%edx, %ecx
10000338e: 6b c9 5f                    	imull	$95, %ecx, %ecx
100003391: 29 c8                       	subl	%ecx, %eax
100003393: 04 20                       	addb	$32, %al
100003395: 43 88 04 26                 	movb	%al, (%r14,%r12)
100003399: 49 ff c4                    	incq	%r12
10000339c: 4d 39 e5                    	cmpq	%r12, %r13
10000339f: 75 cf                       	jne	-49 <_calc_avg_times_lower+0x2d0>
1000033a1: 48 03 5d 98                 	addq	-104(%rbp), %rbx
1000033a5: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
1000033aa: 49 89 dc                    	movq	%rbx, %r12
1000033ad: 48 8b 5d c0                 	movq	-64(%rbp), %rbx
1000033b1: 48 89 df                    	movq	%rbx, %rdi
1000033b4: 4c 89 f6                    	movq	%r14, %rsi
1000033b7: e8 74 09 00 00              	callq	2420 <dyld_stub_binder+0x100003d30>
1000033bc: 4c 89 e7                    	movq	%r12, %rdi
1000033bf: 4c 89 f6                    	movq	%r14, %rsi
1000033c2: e8 69 09 00 00              	callq	2409 <dyld_stub_binder+0x100003d30>
1000033c7: bf 06 00 00 00              	movl	$6, %edi
1000033cc: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
1000033d3: e8 22 09 00 00              	callq	2338 <dyld_stub_binder+0x100003cfa>
1000033d8: 48 89 df                    	movq	%rbx, %rdi
1000033db: 4c 89 ee                    	movq	%r13, %rsi
1000033de: e8 e6 07 00 00              	callq	2022 <_to_lower>
1000033e3: bf 06 00 00 00              	movl	$6, %edi
1000033e8: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
1000033ec: e8 09 09 00 00              	callq	2313 <dyld_stub_binder+0x100003cfa>
1000033f1: bf 06 00 00 00              	movl	$6, %edi
1000033f6: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
1000033fd: e8 f8 08 00 00              	callq	2296 <dyld_stub_binder+0x100003cfa>
100003402: 4c 89 e3                    	movq	%r12, %rbx
100003405: 4c 89 e7                    	movq	%r12, %rdi
100003408: 4c 89 ee                    	movq	%r13, %rsi
10000340b: e8 c0 f3 ff ff              	callq	-3136 <_naive_to_lower>
100003410: bf 06 00 00 00              	movl	$6, %edi
100003415: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
10000341c: e8 d9 08 00 00              	callq	2265 <dyld_stub_binder+0x100003cfa>
100003421: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
100003428: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
10000342f: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100003433: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
10000343a: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100003441: 48 89 d8                    	movq	%rbx, %rax
100003444: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
100003448: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
10000344f: 4c 03 7d 90                 	addq	-112(%rbp), %r15
100003453: 4c 2b 7d 80                 	subq	-128(%rbp), %r15
100003457: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
10000345b: 0f 84 8f fe ff ff           	je	-369 <_calc_avg_times_lower+0x250>
100003461: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
100003465: 48 89 45 b8                 	movq	%rax, -72(%rbp)
100003469: 48 8b 75 b8                 	movq	-72(%rbp), %rsi
10000346d: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
100003471: e8 b4 08 00 00              	callq	2228 <dyld_stub_binder+0x100003d2a>
100003476: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
10000347a: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
10000347e: 85 c0                       	testl	%eax, %eax
100003480: 0f 84 6a fe ff ff           	je	-406 <_calc_avg_times_lower+0x250>
100003486: e9 41 01 00 00              	jmp	321 <_calc_avg_times_lower+0x52c>
10000348b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100003490: 49 69 c4 00 ca 9a 3b        	imulq	$1000000000, %r12, %rax
100003497: 48 01 c1                    	addq	%rax, %rcx
10000349a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
1000034a1: 49 01 c7                    	addq	%rax, %r15
1000034a4: 8b 45 d4                    	movl	-44(%rbp), %eax
1000034a7: ff c8                       	decl	%eax
1000034a9: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
1000034b0: 0f 84 3e 01 00 00           	je	318 <_calc_avg_times_lower+0x554>
1000034b6: 89 45 d4                    	movl	%eax, -44(%rbp)
1000034b9: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000034bd: e8 5c 08 00 00              	callq	2140 <dyld_stub_binder+0x100003d1e>
1000034c2: 48 63 c8                    	movslq	%eax, %rcx
1000034c5: 48 89 ca                    	movq	%rcx, %rdx
1000034c8: 4c 09 e2                    	orq	%r12, %rdx
1000034cb: 48 c1 ea 20                 	shrq	$32, %rdx
1000034cf: 74 0f                       	je	15 <_calc_avg_times_lower+0x440>
1000034d1: 48 89 c8                    	movq	%rcx, %rax
1000034d4: 31 d2                       	xorl	%edx, %edx
1000034d6: 49 f7 f4                    	divq	%r12
1000034d9: 48 89 d3                    	movq	%rdx, %rbx
1000034dc: eb 09                       	jmp	9 <_calc_avg_times_lower+0x447>
1000034de: 66 90                       	nop
1000034e0: 31 d2                       	xorl	%edx, %edx
1000034e2: 41 f7 f4                    	divl	%r12d
1000034e5: 89 d3                       	movl	%edx, %ebx
1000034e7: 48 8b 45 a8                 	movq	-88(%rbp), %rax
1000034eb: 4c 8d 24 18                 	leaq	(%rax,%rbx), %r12
1000034ef: 48 03 5d 98                 	addq	-104(%rbp), %rbx
1000034f3: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
1000034f8: 4c 89 e7                    	movq	%r12, %rdi
1000034fb: 4c 89 f6                    	movq	%r14, %rsi
1000034fe: e8 2d 08 00 00              	callq	2093 <dyld_stub_binder+0x100003d30>
100003503: 48 89 df                    	movq	%rbx, %rdi
100003506: 4c 89 f6                    	movq	%r14, %rsi
100003509: e8 22 08 00 00              	callq	2082 <dyld_stub_binder+0x100003d30>
10000350e: bf 06 00 00 00              	movl	$6, %edi
100003513: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000351a: e8 db 07 00 00              	callq	2011 <dyld_stub_binder+0x100003cfa>
10000351f: 4c 89 65 c0                 	movq	%r12, -64(%rbp)
100003523: 4c 89 e7                    	movq	%r12, %rdi
100003526: 31 f6                       	xorl	%esi, %esi
100003528: e8 9c 06 00 00              	callq	1692 <_to_lower>
10000352d: bf 06 00 00 00              	movl	$6, %edi
100003532: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003536: e8 bf 07 00 00              	callq	1983 <dyld_stub_binder+0x100003cfa>
10000353b: bf 06 00 00 00              	movl	$6, %edi
100003540: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
100003547: e8 ae 07 00 00              	callq	1966 <dyld_stub_binder+0x100003cfa>
10000354c: 48 89 df                    	movq	%rbx, %rdi
10000354f: 31 f6                       	xorl	%esi, %esi
100003551: e8 7a f2 ff ff              	callq	-3462 <_naive_to_lower>
100003556: bf 06 00 00 00              	movl	$6, %edi
10000355b: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
100003562: e8 93 07 00 00              	callq	1939 <dyld_stub_binder+0x100003cfa>
100003567: 4c 8b a5 68 ff ff ff        	movq	-152(%rbp), %r12
10000356e: 4c 2b a5 58 ff ff ff        	subq	-168(%rbp), %r12
100003575: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
100003579: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100003580: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100003587: 48 89 d8                    	movq	%rbx, %rax
10000358a: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
10000358e: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
100003595: 4c 03 7d 90                 	addq	-112(%rbp), %r15
100003599: 4c 2b 7d 80                 	subq	-128(%rbp), %r15
10000359d: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
1000035a1: 0f 84 e9 fe ff ff           	je	-279 <_calc_avg_times_lower+0x3f0>
1000035a7: 48 8b 7d c0                 	movq	-64(%rbp), %rdi
1000035ab: 48 89 45 b8                 	movq	%rax, -72(%rbp)
1000035af: 48 8b 75 b8                 	movq	-72(%rbp), %rsi
1000035b3: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000035b7: e8 6e 07 00 00              	callq	1902 <dyld_stub_binder+0x100003d2a>
1000035bc: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
1000035c0: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
1000035c4: 85 c0                       	testl	%eax, %eax
1000035c6: 0f 84 c4 fe ff ff           	je	-316 <_calc_avg_times_lower+0x3f0>
1000035cc: 48 8d 3d 75 09 00 00        	leaq	2421(%rip), %rdi
1000035d3: 48 89 d3                    	movq	%rdx, %rbx
1000035d6: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
1000035da: 4c 89 f2                    	movq	%r14, %rdx
1000035dd: 31 c0                       	xorl	%eax, %eax
1000035df: e8 28 07 00 00              	callq	1832 <dyld_stub_binder+0x100003d0c>
1000035e4: 48 8d 3d 6d 09 00 00        	leaq	2413(%rip), %rdi
1000035eb: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
1000035ef: e9 0b 02 00 00              	jmp	523 <_calc_avg_times_lower+0x75f>
1000035f4: c4 e1 f9 6e c1              	vmovq	%rcx, %xmm0
1000035f9: c5 f9 6f 0d 1f 09 00 00     	vmovdqa	2335(%rip), %xmm1
100003601: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100003605: c5 f9 28 15 23 09 00 00     	vmovapd	2339(%rip), %xmm2
10000360d: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100003611: c4 e3 79 05 d8 01           	vpermilpd	$1, %xmm0, %xmm3
100003617: 8b 45 b4                    	movl	-76(%rbp), %eax
10000361a: c4 e1 db 2a e0              	vcvtsi2sd	%rax, %xmm4, %xmm4
10000361f: c5 db 59 25 19 09 00 00     	vmulsd	2329(%rip), %xmm4, %xmm4
100003627: c5 e3 58 c0                 	vaddsd	%xmm0, %xmm3, %xmm0
10000362b: c5 fb 5e c4                 	vdivsd	%xmm4, %xmm0, %xmm0
10000362f: 48 8b 85 48 ff ff ff        	movq	-184(%rbp), %rax
100003636: c5 fb 11 00                 	vmovsd	%xmm0, (%rax)
10000363a: c4 c1 f9 6e c7              	vmovq	%r15, %xmm0
10000363f: c5 f9 62 c1                 	vpunpckldq	%xmm1, %xmm0, %xmm0
100003643: c5 f9 5c c2                 	vsubpd	%xmm2, %xmm0, %xmm0
100003647: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
10000364d: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100003651: c5 fb 5e c4                 	vdivsd	%xmm4, %xmm0, %xmm0
100003655: 48 8b 85 40 ff ff ff        	movq	-192(%rbp), %rax
10000365c: c5 fb 11 00                 	vmovsd	%xmm0, (%rax)
100003660: 48 8b 7d a8                 	movq	-88(%rbp), %rdi
100003664: e8 97 06 00 00              	callq	1687 <dyld_stub_binder+0x100003d00>
100003669: 48 8b 7d 98                 	movq	-104(%rbp), %rdi
10000366d: e8 8e 06 00 00              	callq	1678 <dyld_stub_binder+0x100003d00>
100003672: 48 81 c4 98 00 00 00        	addq	$152, %rsp
100003679: 5b                          	popq	%rbx
10000367a: 41 5c                       	popq	%r12
10000367c: 41 5d                       	popq	%r13
10000367e: 41 5e                       	popq	%r14
100003680: 41 5f                       	popq	%r15
100003682: 5d                          	popq	%rbp
100003683: c3                          	retq
100003684: 8b 45 d4                    	movl	-44(%rbp), %eax
100003687: 45 31 ff                    	xorl	%r15d, %r15d
10000368a: eb 2e                       	jmp	46 <_calc_avg_times_lower+0x61a>
10000368c: 0f 1f 40 00                 	nopl	(%rax)
100003690: 49 69 c7 00 ca 9a 3b        	imulq	$1000000000, %r15, %rax
100003697: 48 01 c1                    	addq	%rax, %rcx
10000369a: 48 69 c3 00 ca 9a 3b        	imulq	$1000000000, %rbx, %rax
1000036a1: 4c 8b 7d c0                 	movq	-64(%rbp), %r15
1000036a5: 49 01 c7                    	addq	%rax, %r15
1000036a8: 8b 45 a4                    	movl	-92(%rbp), %eax
1000036ab: ff c8                       	decl	%eax
1000036ad: 4c 8b a5 50 ff ff ff        	movq	-176(%rbp), %r12
1000036b4: 0f 84 0f fc ff ff           	je	-1009 <_calc_avg_times_lower+0x229>
1000036ba: 89 45 a4                    	movl	%eax, -92(%rbp)
1000036bd: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000036c1: e8 58 06 00 00              	callq	1624 <dyld_stub_binder+0x100003d1e>
1000036c6: 48 63 c8                    	movslq	%eax, %rcx
1000036c9: 48 89 ca                    	movq	%rcx, %rdx
1000036cc: 4c 09 e2                    	orq	%r12, %rdx
1000036cf: 48 c1 ea 20                 	shrq	$32, %rdx
1000036d3: 4c 89 7d c0                 	movq	%r15, -64(%rbp)
1000036d7: 74 17                       	je	23 <_calc_avg_times_lower+0x650>
1000036d9: 48 89 c8                    	movq	%rcx, %rax
1000036dc: 31 d2                       	xorl	%edx, %edx
1000036de: 49 f7 f4                    	divq	%r12
1000036e1: 49 89 d4                    	movq	%rdx, %r12
1000036e4: eb 12                       	jmp	18 <_calc_avg_times_lower+0x658>
1000036e6: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
1000036f0: 31 d2                       	xorl	%edx, %edx
1000036f2: 41 f7 f4                    	divl	%r12d
1000036f5: 41 89 d4                    	movl	%edx, %r12d
1000036f8: 48 8b 45 a8                 	movq	-88(%rbp), %rax
1000036fc: 4a 8d 1c 20                 	leaq	(%rax,%r12), %rbx
100003700: 4c 03 65 98                 	addq	-104(%rbp), %r12
100003704: 43 c6 04 2e 00              	movb	$0, (%r14,%r13)
100003709: 48 89 df                    	movq	%rbx, %rdi
10000370c: 4c 89 f6                    	movq	%r14, %rsi
10000370f: e8 1c 06 00 00              	callq	1564 <dyld_stub_binder+0x100003d30>
100003714: 4c 89 e7                    	movq	%r12, %rdi
100003717: 4c 89 f6                    	movq	%r14, %rsi
10000371a: e8 11 06 00 00              	callq	1553 <dyld_stub_binder+0x100003d30>
10000371f: bf 06 00 00 00              	movl	$6, %edi
100003724: 48 8d b5 58 ff ff ff        	leaq	-168(%rbp), %rsi
10000372b: e8 ca 05 00 00              	callq	1482 <dyld_stub_binder+0x100003cfa>
100003730: 48 89 5d b8                 	movq	%rbx, -72(%rbp)
100003734: 48 89 df                    	movq	%rbx, %rdi
100003737: 31 f6                       	xorl	%esi, %esi
100003739: e8 92 f0 ff ff              	callq	-3950 <_naive_to_lower>
10000373e: bf 06 00 00 00              	movl	$6, %edi
100003743: 48 8d b5 68 ff ff ff        	leaq	-152(%rbp), %rsi
10000374a: e8 ab 05 00 00              	callq	1451 <dyld_stub_binder+0x100003cfa>
10000374f: bf 06 00 00 00              	movl	$6, %edi
100003754: 48 8d b5 78 ff ff ff        	leaq	-136(%rbp), %rsi
10000375b: e8 9a 05 00 00              	callq	1434 <dyld_stub_binder+0x100003cfa>
100003760: 4c 89 e7                    	movq	%r12, %rdi
100003763: 31 f6                       	xorl	%esi, %esi
100003765: e8 5f 04 00 00              	callq	1119 <_to_lower>
10000376a: bf 06 00 00 00              	movl	$6, %edi
10000376f: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100003773: e8 82 05 00 00              	callq	1410 <dyld_stub_binder+0x100003cfa>
100003778: 4c 8b bd 68 ff ff ff        	movq	-152(%rbp), %r15
10000377f: 4c 2b bd 58 ff ff ff        	subq	-168(%rbp), %r15
100003786: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
10000378a: 48 03 8d 70 ff ff ff        	addq	-144(%rbp), %rcx
100003791: 48 2b 8d 60 ff ff ff        	subq	-160(%rbp), %rcx
100003798: 48 8b 5d 88                 	movq	-120(%rbp), %rbx
10000379c: 48 2b 9d 78 ff ff ff        	subq	-136(%rbp), %rbx
1000037a3: 48 8b 55 c0                 	movq	-64(%rbp), %rdx
1000037a7: 48 03 55 90                 	addq	-112(%rbp), %rdx
1000037ab: 48 2b 55 80                 	subq	-128(%rbp), %rdx
1000037af: 48 89 55 c0                 	movq	%rdx, -64(%rbp)
1000037b3: 80 7d b0 00                 	cmpb	$0, -80(%rbp)
1000037b7: 0f 84 d3 fe ff ff           	je	-301 <_calc_avg_times_lower+0x5f0>
1000037bd: 48 8b 7d b8                 	movq	-72(%rbp), %rdi
1000037c1: 4c 89 e6                    	movq	%r12, %rsi
1000037c4: 48 89 4d c8                 	movq	%rcx, -56(%rbp)
1000037c8: e8 5d 05 00 00              	callq	1373 <dyld_stub_binder+0x100003d2a>
1000037cd: 4c 89 e2                    	movq	%r12, %rdx
1000037d0: 48 8b 4d c8                 	movq	-56(%rbp), %rcx
1000037d4: 85 c0                       	testl	%eax, %eax
1000037d6: 0f 84 b4 fe ff ff           	je	-332 <_calc_avg_times_lower+0x5f0>
1000037dc: 48 8d 3d 65 07 00 00        	leaq	1893(%rip), %rdi
1000037e3: 48 89 d3                    	movq	%rdx, %rbx
1000037e6: 48 8b 75 a8                 	movq	-88(%rbp), %rsi
1000037ea: 4c 89 f2                    	movq	%r14, %rdx
1000037ed: 31 c0                       	xorl	%eax, %eax
1000037ef: e8 18 05 00 00              	callq	1304 <dyld_stub_binder+0x100003d0c>
1000037f4: 48 8d 3d 5d 07 00 00        	leaq	1885(%rip), %rdi
1000037fb: 48 8b 55 b8                 	movq	-72(%rbp), %rdx
1000037ff: 48 89 d6                    	movq	%rdx, %rsi
100003802: 31 c0                       	xorl	%eax, %eax
100003804: e8 03 05 00 00              	callq	1283 <dyld_stub_binder+0x100003d0c>
100003809: 48 8d 3d 58 07 00 00        	leaq	1880(%rip), %rdi
100003810: 48 89 de                    	movq	%rbx, %rsi
100003813: 48 89 da                    	movq	%rbx, %rdx
100003816: 31 c0                       	xorl	%eax, %eax
100003818: e8 ef 04 00 00              	callq	1263 <dyld_stub_binder+0x100003d0c>
10000381d: e8 d2 04 00 00              	callq	1234 <dyld_stub_binder+0x100003cf4>
100003822: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000382c: 0f 1f 40 00                 	nopl	(%rax)

0000000100003830 _main:
100003830: 55                          	pushq	%rbp
100003831: 48 89 e5                    	movq	%rsp, %rbp
100003834: 41 57                       	pushq	%r15
100003836: 41 56                       	pushq	%r14
100003838: 41 54                       	pushq	%r12
10000383a: 53                          	pushq	%rbx
10000383b: b8 20 40 00 00              	movl	$16416, %eax
100003840: e8 a3 04 00 00              	callq	1187 <dyld_stub_binder+0x100003ce8>
100003845: 48 29 c4                    	subq	%rax, %rsp
100003848: 48 8b 05 b1 07 00 00        	movq	1969(%rip), %rax
10000384f: 48 8b 00                    	movq	(%rax), %rax
100003852: 48 89 45 d8                 	movq	%rax, -40(%rbp)
100003856: 31 ff                       	xorl	%edi, %edi
100003858: e8 d9 04 00 00              	callq	1241 <dyld_stub_binder+0x100003d36>
10000385d: 89 c7                       	movl	%eax, %edi
10000385f: e8 c0 04 00 00              	callq	1216 <dyld_stub_binder+0x100003d24>
100003864: 49 89 e4                    	movq	%rsp, %r12
100003867: bb 01 00 00 00              	movl	$1, %ebx
10000386c: 4c 8d b5 c0 bf ff ff        	leaq	-16448(%rbp), %r14
100003873: 4c 8d bd c8 bf ff ff        	leaq	-16440(%rbp), %r15
10000387a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)
100003880: 48 89 df                    	movq	%rbx, %rdi
100003883: be d0 07 00 00              	movl	$2000, %esi
100003888: 4c 89 f2                    	movq	%r14, %rdx
10000388b: 4c 89 f9                    	movq	%r15, %rcx
10000388e: 41 b8 01 00 00 00           	movl	$1, %r8d
100003894: 45 31 c9                    	xorl	%r9d, %r9d
100003897: e8 74 f0 ff ff              	callq	-3980 <_calc_avg_times_upper>
10000389c: 48 8b 85 c0 bf ff ff        	movq	-16448(%rbp), %rax
1000038a3: 48 89 84 dd c8 df ff ff     	movq	%rax, -8248(%rbp,%rbx,8)
1000038ab: 48 8b 85 c8 bf ff ff        	movq	-16440(%rbp), %rax
1000038b2: 48 89 84 dd c8 bf ff ff     	movq	%rax, -16440(%rbp,%rbx,8)
1000038ba: 48 89 df                    	movq	%rbx, %rdi
1000038bd: be d0 07 00 00              	movl	$2000, %esi
1000038c2: 4c 89 f2                    	movq	%r14, %rdx
1000038c5: 4c 89 f9                    	movq	%r15, %rcx
1000038c8: 41 b8 01 00 00 00           	movl	$1, %r8d
1000038ce: 45 31 c9                    	xorl	%r9d, %r9d
1000038d1: e8 ca f7 ff ff              	callq	-2102 <_calc_avg_times_lower>
1000038d6: 48 ff c3                    	incq	%rbx
1000038d9: 48 81 fb 00 04 00 00        	cmpq	$1024, %rbx
1000038e0: 75 9e                       	jne	-98 <_main+0x50>
1000038e2: 48 8d 3d 8f 06 00 00        	leaq	1679(%rip), %rdi
1000038e9: 31 c0                       	xorl	%eax, %eax
1000038eb: e8 1c 04 00 00              	callq	1052 <dyld_stub_binder+0x100003d0c>
1000038f0: c5 fb 10 85 d0 df ff ff     	vmovsd	-8240(%rbp), %xmm0
1000038f8: 4c 8d 35 7c 06 00 00        	leaq	1660(%rip), %r14
1000038ff: 4c 89 f7                    	movq	%r14, %rdi
100003902: 31 f6                       	xorl	%esi, %esi
100003904: b0 01                       	movb	$1, %al
100003906: e8 01 04 00 00              	callq	1025 <dyld_stub_binder+0x100003d0c>
10000390b: bb 01 00 00 00              	movl	$1, %ebx
100003910: bf 2c 00 00 00              	movl	$44, %edi
100003915: e8 f8 03 00 00              	callq	1016 <dyld_stub_binder+0x100003d12>
10000391a: c5 fb 10 84 dd d0 df ff ff  	vmovsd	-8240(%rbp,%rbx,8), %xmm0
100003923: 4c 89 f7                    	movq	%r14, %rdi
100003926: 89 de                       	movl	%ebx, %esi
100003928: b0 01                       	movb	$1, %al
10000392a: e8 dd 03 00 00              	callq	989 <dyld_stub_binder+0x100003d0c>
10000392f: 48 ff c3                    	incq	%rbx
100003932: 48 81 fb ff 03 00 00        	cmpq	$1023, %rbx
100003939: 75 d5                       	jne	-43 <_main+0xe0>
10000393b: 48 8d 3d 44 06 00 00        	leaq	1604(%rip), %rdi
100003942: 31 c0                       	xorl	%eax, %eax
100003944: e8 c3 03 00 00              	callq	963 <dyld_stub_binder+0x100003d0c>
100003949: bf 7b 00 00 00              	movl	$123, %edi
10000394e: e8 bf 03 00 00              	callq	959 <dyld_stub_binder+0x100003d12>
100003953: c5 fb 10 85 d0 bf ff ff     	vmovsd	-16432(%rbp), %xmm0
10000395b: 4c 8d 35 19 06 00 00        	leaq	1561(%rip), %r14
100003962: 4c 89 f7                    	movq	%r14, %rdi
100003965: 31 f6                       	xorl	%esi, %esi
100003967: b0 01                       	movb	$1, %al
100003969: e8 9e 03 00 00              	callq	926 <dyld_stub_binder+0x100003d0c>
10000396e: bb 01 00 00 00              	movl	$1, %ebx
100003973: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000397d: 0f 1f 00                    	nopl	(%rax)
100003980: bf 2c 00 00 00              	movl	$44, %edi
100003985: e8 88 03 00 00              	callq	904 <dyld_stub_binder+0x100003d12>
10000398a: c5 fb 10 84 dd d0 bf ff ff  	vmovsd	-16432(%rbp,%rbx,8), %xmm0
100003993: 4c 89 f7                    	movq	%r14, %rdi
100003996: 89 de                       	movl	%ebx, %esi
100003998: b0 01                       	movb	$1, %al
10000399a: e8 6d 03 00 00              	callq	877 <dyld_stub_binder+0x100003d0c>
10000399f: 48 ff c3                    	incq	%rbx
1000039a2: 48 81 fb ff 03 00 00        	cmpq	$1023, %rbx
1000039a9: 75 d5                       	jne	-43 <_main+0x150>
1000039ab: 48 8d 3d d7 05 00 00        	leaq	1495(%rip), %rdi
1000039b2: e8 61 03 00 00              	callq	865 <dyld_stub_binder+0x100003d18>
1000039b7: 4c 89 e4                    	movq	%r12, %rsp
1000039ba: 48 8b 05 3f 06 00 00        	movq	1599(%rip), %rax
1000039c1: 48 8b 00                    	movq	(%rax), %rax
1000039c4: 48 3b 45 d8                 	cmpq	-40(%rbp), %rax
1000039c8: 75 12                       	jne	18 <_main+0x1ac>
1000039ca: 31 c0                       	xorl	%eax, %eax
1000039cc: 48 81 c4 20 40 00 00        	addq	$16416, %rsp
1000039d3: 5b                          	popq	%rbx
1000039d4: 41 5c                       	popq	%r12
1000039d6: 41 5e                       	popq	%r14
1000039d8: 41 5f                       	popq	%r15
1000039da: 5d                          	popq	%rbp
1000039db: c3                          	retq
1000039dc: e8 0d 03 00 00              	callq	781 <dyld_stub_binder+0x100003cee>
1000039e1: 90                          	nop
1000039e2: 90                          	nop
1000039e3: 90                          	nop
1000039e4: 90                          	nop
1000039e5: 90                          	nop
1000039e6: 90                          	nop
1000039e7: 90                          	nop
1000039e8: 90                          	nop
1000039e9: 90                          	nop
1000039ea: 90                          	nop
1000039eb: 90                          	nop
1000039ec: 90                          	nop
1000039ed: 90                          	nop
1000039ee: 90                          	nop
1000039ef: 90                          	nop
1000039f0: 90                          	nop
1000039f1: 90                          	nop
1000039f2: 90                          	nop
1000039f3: 90                          	nop
1000039f4: 90                          	nop
1000039f5: 90                          	nop
1000039f6: 90                          	nop
1000039f7: 90                          	nop
1000039f8: 90                          	nop
1000039f9: 90                          	nop
1000039fa: 90                          	nop
1000039fb: 90                          	nop
1000039fc: 90                          	nop
1000039fd: 90                          	nop
1000039fe: 90                          	nop
1000039ff: 90                          	nop

0000000100003a00 upper_offset_array:
100003a00: 05 05 05 05 05              	addl	$84215045, %eax
100003a05: 05 05 05 05 05              	addl	$84215045, %eax
100003a0a: 05 05 05 05 05              	addl	$84215045, %eax
100003a0f: 05 05 05 05 05              	addl	$84215045, %eax
100003a14: 05 05 05 05 05              	addl	$84215045, %eax
100003a19: 05 05 05 05 05              	addl	$84215045, %eax
100003a1e: 05 05 25 25 25              	addl	$623191301, %eax
100003a23: 25 25 25 25 25              	andl	$623191333, %eax
100003a28: 25 25 25 25 25              	andl	$623191333, %eax
100003a2d: 25 25 25 25 25              	andl	$623191333, %eax
100003a32: 25 25 25 25 25              	andl	$623191333, %eax
100003a37: 25 25 25 25 25              	andl	$623191333, %eax
100003a3c: 25 25 25 25 65              	andl	$1696933157, %eax

0000000100003a40 range_min:
100003a40: 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 65 e0 e0       	loopne	-32
100003a62: e0 e0                       	loopne	-32
100003a64: e0 e0                       	loopne	-32
100003a66: e0 e0                       	loopne	-32
100003a68: e0 e0                       	loopne	-32
100003a6a: e0 e0                       	loopne	-32
100003a6c: e0 e0                       	loopne	-32
100003a6e: e0 e0                       	loopne	-32
100003a70: e0 e0                       	loopne	-32
100003a72: e0 e0                       	loopne	-32
100003a74: e0 e0                       	loopne	-32
100003a76: e0 e0                       	loopne	-32
100003a78: e0 e0                       	loopne	-32
100003a7a: e0 e0                       	loopne	-32
100003a7c: e0 e0                       	loopne	-32
100003a7e: e0 e0                       	loopne	-32

0000000100003a80 upper_to_lower:
100003a80: 20 20                       	andb	%ah, (%rax)
100003a82: 20 20                       	andb	%ah, (%rax)
100003a84: 20 20                       	andb	%ah, (%rax)
100003a86: 20 20                       	andb	%ah, (%rax)
100003a88: 20 20                       	andb	%ah, (%rax)
100003a8a: 20 20                       	andb	%ah, (%rax)
100003a8c: 20 20                       	andb	%ah, (%rax)
100003a8e: 20 20                       	andb	%ah, (%rax)
100003a90: 20 20                       	andb	%ah, (%rax)
100003a92: 20 20                       	andb	%ah, (%rax)
100003a94: 20 20                       	andb	%ah, (%rax)
100003a96: 20 20                       	andb	%ah, (%rax)
100003a98: 20 20                       	andb	%ah, (%rax)
100003a9a: 20 20                       	andb	%ah, (%rax)
100003a9c: 20 20                       	andb	%ah, (%rax)
100003a9e: 20 20                       	andb	%ah, (%rax)

0000000100003aa0 _to_upper:
100003aa0: 48 85 f6                    	testq	%rsi, %rsi
100003aa3: 0f 84 1f 01 00 00           	je	287 <_up_return>
100003aa9: 53                          	pushq	%rbx
100003aaa: 48 8d 1c 37                 	leaq	(%rdi,%rsi), %rbx
100003aae: 48 83 fe 10                 	cmpq	$16, %rsi
100003ab2: 0f 82 e7 00 00 00           	jb	231 <_up_remainder_loop>
100003ab8: c5 fd 6f 05 40 ff ff ff     	vmovdqa	-192(%rip), %ymm0
100003ac0: c5 fd 6f 0d 78 ff ff ff     	vmovdqa	-136(%rip), %ymm1
100003ac8: c5 fd 6f 15 90 ff ff ff     	vmovdqa	-112(%rip), %ymm2
100003ad0: 48 89 f1                    	movq	%rsi, %rcx
100003ad3: 48 83 e1 f0                 	andq	$-16, %rcx
100003ad7: 48 01 f9                    	addq	%rdi, %rcx
100003ada: 48 81 fe 80 00 00 00        	cmpq	$128, %rsi
100003ae1: 0f 82 8a 00 00 00           	jb	138 <_up_vector_loop>
100003ae7: 48 89 f2                    	movq	%rsi, %rdx
100003aea: 48 83 e2 80                 	andq	$-128, %rdx
100003aee: 48 01 fa                    	addq	%rdi, %rdx

0000000100003af1 _up_4x_vector_loop:
100003af1: c5 fe 6f 1f                 	vmovdqu	(%rdi), %ymm3
100003af5: c5 fe 6f 6f 20              	vmovdqu	32(%rdi), %ymm5
100003afa: c5 fe 6f 7f 40              	vmovdqu	64(%rdi), %ymm7
100003aff: c5 7e 6f 4f 60              	vmovdqu	96(%rdi), %ymm9
100003b04: c5 e5 fc e0                 	vpaddb	%ymm0, %ymm3, %ymm4
100003b08: c5 d5 fc f0                 	vpaddb	%ymm0, %ymm5, %ymm6
100003b0c: c5 45 fc c0                 	vpaddb	%ymm0, %ymm7, %ymm8
100003b10: c5 35 fc d0                 	vpaddb	%ymm0, %ymm9, %ymm10
100003b14: c5 dd 64 e1                 	vpcmpgtb	%ymm1, %ymm4, %ymm4
100003b18: c5 cd 64 f1                 	vpcmpgtb	%ymm1, %ymm6, %ymm6
100003b1c: c5 3d 64 c1                 	vpcmpgtb	%ymm1, %ymm8, %ymm8
100003b20: c5 2d 64 d1                 	vpcmpgtb	%ymm1, %ymm10, %ymm10
100003b24: c5 dd db e2                 	vpand	%ymm2, %ymm4, %ymm4
100003b28: c5 cd db f2                 	vpand	%ymm2, %ymm6, %ymm6
100003b2c: c5 3d db c2                 	vpand	%ymm2, %ymm8, %ymm8
100003b30: c5 2d db d2                 	vpand	%ymm2, %ymm10, %ymm10
100003b34: c5 dd fc db                 	vpaddb	%ymm3, %ymm4, %ymm3
100003b38: c5 cd fc ed                 	vpaddb	%ymm5, %ymm6, %ymm5
100003b3c: c5 bd fc ff                 	vpaddb	%ymm7, %ymm8, %ymm7
100003b40: c4 41 2d fc c9              	vpaddb	%ymm9, %ymm10, %ymm9
100003b45: c5 fe 7f 1f                 	vmovdqu	%ymm3, (%rdi)
100003b49: c5 fe 7f 6f 20              	vmovdqu	%ymm5, 32(%rdi)
100003b4e: c5 fe 7f 7f 40              	vmovdqu	%ymm7, 64(%rdi)
100003b53: c5 7e 7f 4f 60              	vmovdqu	%ymm9, 96(%rdi)
100003b58: 48 81 c7 80 00 00 00        	addq	$128, %rdi

0000000100003b5f _up_4x_vector_loop_cond:
100003b5f: 48 39 d7                    	cmpq	%rdx, %rdi
100003b62: 0f 85 89 ff ff ff           	jne	-119 <_up_4x_vector_loop>

0000000100003b68 _up_vector_loop_cond_1:
100003b68: 48 39 cf                    	cmpq	%rcx, %rdi
100003b6b: 0f 84 4d 00 00 00           	je	77 <_up_remainder_loop_cond_2>

0000000100003b71 _up_vector_loop:
100003b71: c5 fa 6f 1f                 	vmovdqu	(%rdi), %xmm3
100003b75: c5 e1 fc e0                 	vpaddb	%xmm0, %xmm3, %xmm4
100003b79: c5 d9 64 e1                 	vpcmpgtb	%xmm1, %xmm4, %xmm4
100003b7d: c5 d9 db e2                 	vpand	%xmm2, %xmm4, %xmm4
100003b81: c5 d9 fc db                 	vpaddb	%xmm3, %xmm4, %xmm3
100003b85: c5 fa 7f 1f                 	vmovdqu	%xmm3, (%rdi)
100003b89: 48 83 c7 10                 	addq	$16, %rdi

0000000100003b8d _up_vector_loop_cond_2:
100003b8d: 48 39 cf                    	cmpq	%rcx, %rdi
100003b90: 0f 82 db ff ff ff           	jb	-37 <_up_vector_loop>

0000000100003b96 _up_remainder_loop_cond_1:
100003b96: 48 39 df                    	cmpq	%rbx, %rdi
100003b99: 0f 84 28 00 00 00           	je	40 <_up_finished>

0000000100003b9f _up_remainder_loop:
100003b9f: 0f b6 07                    	movzbl	(%rdi), %eax
100003ba2: 67 8d 48 05                 	leal	5(%eax), %ecx
100003ba6: 80 e1 7f                    	andb	$127, %cl
100003ba9: 80 c1 1a                    	addb	$26, %cl
100003bac: c4 e2 78 f2 c9              	andnl	%ecx, %eax, %ecx
100003bb1: c0 f9 02                    	sarb	$2, %cl
100003bb4: 80 e1 e0                    	andb	$-32, %cl
100003bb7: 00 c8                       	addb	%cl, %al
100003bb9: 88 07                       	movb	%al, (%rdi)
100003bbb: 48 ff c7                    	incq	%rdi

0000000100003bbe _up_remainder_loop_cond_2:
100003bbe: 48 39 df                    	cmpq	%rbx, %rdi
100003bc1: 0f 85 d8 ff ff ff           	jne	-40 <_up_remainder_loop>

0000000100003bc7 _up_finished:
100003bc7: 5b                          	popq	%rbx

0000000100003bc8 _up_return:
100003bc8: c3                          	retq

0000000100003bc9 _to_lower:
100003bc9: 48 85 f6                    	testq	%rsi, %rsi
100003bcc: 0f 84 14 01 00 00           	je	276 <_lo_return>
100003bd2: 53                          	pushq	%rbx
100003bd3: 48 8d 1c 37                 	leaq	(%rdi,%rsi), %rbx
100003bd7: 48 83 fe 20                 	cmpq	$32, %rsi
100003bdb: 0f 82 e7 00 00 00           	jb	231 <_lo_remainder_loop>
100003be1: c5 fd 6f 05 37 fe ff ff     	vmovdqa	-457(%rip), %ymm0
100003be9: c5 fd 6f 0d 4f fe ff ff     	vmovdqa	-433(%rip), %ymm1
100003bf1: c5 fd 6f 15 87 fe ff ff     	vmovdqa	-377(%rip), %ymm2
100003bf9: 48 89 f1                    	movq	%rsi, %rcx
100003bfc: 48 83 e1 e0                 	andq	$-32, %rcx
100003c00: 48 01 f9                    	addq	%rdi, %rcx
100003c03: 48 81 fe 80 00 00 00        	cmpq	$128, %rsi
100003c0a: 0f 82 8a 00 00 00           	jb	138 <_lo_vector_loop>
100003c10: 48 89 f2                    	movq	%rsi, %rdx
100003c13: 48 83 e2 80                 	andq	$-128, %rdx
100003c17: 48 01 fa                    	addq	%rdi, %rdx

0000000100003c1a _lo_4x_vector_loop:
100003c1a: c5 fe 6f 1f                 	vmovdqu	(%rdi), %ymm3
100003c1e: c5 fe 6f 6f 20              	vmovdqu	32(%rdi), %ymm5
100003c23: c5 fe 6f 7f 40              	vmovdqu	64(%rdi), %ymm7
100003c28: c5 7e 6f 4f 60              	vmovdqu	96(%rdi), %ymm9
100003c2d: c5 e5 fc e0                 	vpaddb	%ymm0, %ymm3, %ymm4
100003c31: c5 d5 fc f0                 	vpaddb	%ymm0, %ymm5, %ymm6
100003c35: c5 45 fc c0                 	vpaddb	%ymm0, %ymm7, %ymm8
100003c39: c5 35 fc d0                 	vpaddb	%ymm0, %ymm9, %ymm10
100003c3d: c5 dd 64 e1                 	vpcmpgtb	%ymm1, %ymm4, %ymm4
100003c41: c5 cd 64 f1                 	vpcmpgtb	%ymm1, %ymm6, %ymm6
100003c45: c5 3d 64 c1                 	vpcmpgtb	%ymm1, %ymm8, %ymm8
100003c49: c5 2d 64 d1                 	vpcmpgtb	%ymm1, %ymm10, %ymm10
100003c4d: c5 dd db e2                 	vpand	%ymm2, %ymm4, %ymm4
100003c51: c5 cd db f2                 	vpand	%ymm2, %ymm6, %ymm6
100003c55: c5 3d db c2                 	vpand	%ymm2, %ymm8, %ymm8
100003c59: c5 2d db d2                 	vpand	%ymm2, %ymm10, %ymm10
100003c5d: c5 dd fc db                 	vpaddb	%ymm3, %ymm4, %ymm3
100003c61: c5 cd fc ed                 	vpaddb	%ymm5, %ymm6, %ymm5
100003c65: c5 bd fc ff                 	vpaddb	%ymm7, %ymm8, %ymm7
100003c69: c4 41 2d fc c9              	vpaddb	%ymm9, %ymm10, %ymm9
100003c6e: c5 fe 7f 1f                 	vmovdqu	%ymm3, (%rdi)
100003c72: c5 fe 7f 6f 20              	vmovdqu	%ymm5, 32(%rdi)
100003c77: c5 fe 7f 7f 40              	vmovdqu	%ymm7, 64(%rdi)
100003c7c: c5 7e 7f 4f 60              	vmovdqu	%ymm9, 96(%rdi)
100003c81: 48 81 c7 80 00 00 00        	addq	$128, %rdi

0000000100003c88 _lo_4x_vector_loop_cond:
100003c88: 48 39 d7                    	cmpq	%rdx, %rdi
100003c8b: 0f 85 89 ff ff ff           	jne	-119 <_lo_4x_vector_loop>

0000000100003c91 _lo_vector_loop_cond_1:
100003c91: 48 39 cf                    	cmpq	%rcx, %rdi
100003c94: 0f 84 42 00 00 00           	je	66 <_lo_remainder_loop_cond_2>

0000000100003c9a _lo_vector_loop:
100003c9a: c5 fe 6f 1f                 	vmovdqu	(%rdi), %ymm3
100003c9e: c5 e5 fc e0                 	vpaddb	%ymm0, %ymm3, %ymm4
100003ca2: c5 dd 64 e1                 	vpcmpgtb	%ymm1, %ymm4, %ymm4
100003ca6: c5 dd db e2                 	vpand	%ymm2, %ymm4, %ymm4
100003caa: c5 dd fc db                 	vpaddb	%ymm3, %ymm4, %ymm3
100003cae: c5 fe 7f 1f                 	vmovdqu	%ymm3, (%rdi)
100003cb2: 48 83 c7 20                 	addq	$32, %rdi

0000000100003cb6 _lo_vector_loop_cond_2:
100003cb6: 48 39 cf                    	cmpq	%rcx, %rdi
100003cb9: 0f 82 db ff ff ff           	jb	-37 <_lo_vector_loop>

0000000100003cbf _lo_remainder_loop_cond_1:
100003cbf: 48 39 df                    	cmpq	%rbx, %rdi
100003cc2: 0f 84 1d 00 00 00           	je	29 <_lo_finished>

0000000100003cc8 _lo_remainder_loop:
100003cc8: 0f b6 07                    	movzbl	(%rdi), %eax
100003ccb: 8d 48 bf                    	leal	-65(%rax), %ecx
100003cce: 8d 50 20                    	leal	32(%rax), %edx
100003cd1: 83 f9 1a                    	cmpl	$26, %ecx
100003cd4: 0f 42 c2                    	cmovbl	%edx, %eax
100003cd7: 88 07                       	movb	%al, (%rdi)
100003cd9: 48 ff c7                    	incq	%rdi

0000000100003cdc _lo_remainder_loop_cond_2:
100003cdc: 48 39 df                    	cmpq	%rbx, %rdi
100003cdf: 0f 85 e3 ff ff ff           	jne	-29 <_lo_remainder_loop>

0000000100003ce5 _lo_finished:
100003ce5: 5b                          	popq	%rbx

0000000100003ce6 _lo_return:
100003ce6: c3                          	retq

Disassembly of section __TEXT,__stubs:

0000000100003ce8 __stubs:
100003ce8: ff 25 12 43 00 00           	jmpq	*17170(%rip)
100003cee: ff 25 14 43 00 00           	jmpq	*17172(%rip)
100003cf4: ff 25 16 43 00 00           	jmpq	*17174(%rip)
100003cfa: ff 25 18 43 00 00           	jmpq	*17176(%rip)
100003d00: ff 25 1a 43 00 00           	jmpq	*17178(%rip)
100003d06: ff 25 1c 43 00 00           	jmpq	*17180(%rip)
100003d0c: ff 25 1e 43 00 00           	jmpq	*17182(%rip)
100003d12: ff 25 20 43 00 00           	jmpq	*17184(%rip)
100003d18: ff 25 22 43 00 00           	jmpq	*17186(%rip)
100003d1e: ff 25 24 43 00 00           	jmpq	*17188(%rip)
100003d24: ff 25 26 43 00 00           	jmpq	*17190(%rip)
100003d2a: ff 25 28 43 00 00           	jmpq	*17192(%rip)
100003d30: ff 25 2a 43 00 00           	jmpq	*17194(%rip)
100003d36: ff 25 2c 43 00 00           	jmpq	*17196(%rip)

Disassembly of section __TEXT,__stub_helper:

0000000100003d3c __stub_helper:
100003d3c: 4c 8d 1d 2d 43 00 00        	leaq	17197(%rip), %r11
100003d43: 41 53                       	pushq	%r11
100003d45: ff 25 bd 02 00 00           	jmpq	*701(%rip)
100003d4b: 90                          	nop
100003d4c: 68 00 00 00 00              	pushq	$0
100003d51: e9 e6 ff ff ff              	jmp	-26 <__stub_helper>
100003d56: 68 18 00 00 00              	pushq	$24
100003d5b: e9 dc ff ff ff              	jmp	-36 <__stub_helper>
100003d60: 68 30 00 00 00              	pushq	$48
100003d65: e9 d2 ff ff ff              	jmp	-46 <__stub_helper>
100003d6a: 68 3d 00 00 00              	pushq	$61
100003d6f: e9 c8 ff ff ff              	jmp	-56 <__stub_helper>
100003d74: 68 52 00 00 00              	pushq	$82
100003d79: e9 be ff ff ff              	jmp	-66 <__stub_helper>
100003d7e: 68 5e 00 00 00              	pushq	$94
100003d83: e9 b4 ff ff ff              	jmp	-76 <__stub_helper>
100003d88: 68 6c 00 00 00              	pushq	$108
100003d8d: e9 aa ff ff ff              	jmp	-86 <__stub_helper>
100003d92: 68 7a 00 00 00              	pushq	$122
100003d97: e9 a0 ff ff ff              	jmp	-96 <__stub_helper>
100003d9c: 68 89 00 00 00              	pushq	$137
100003da1: e9 96 ff ff ff              	jmp	-106 <__stub_helper>
100003da6: 68 95 00 00 00              	pushq	$149
100003dab: e9 8c ff ff ff              	jmp	-116 <__stub_helper>
100003db0: 68 a1 00 00 00              	pushq	$161
100003db5: e9 82 ff ff ff              	jmp	-126 <__stub_helper>
100003dba: 68 ae 00 00 00              	pushq	$174
100003dbf: e9 78 ff ff ff              	jmp	-136 <__stub_helper>
100003dc4: 68 bc 00 00 00              	pushq	$188
100003dc9: e9 6e ff ff ff              	jmp	-146 <__stub_helper>
100003dce: 68 ca 00 00 00              	pushq	$202
100003dd3: e9 64 ff ff ff              	jmp	-156 <__stub_helper>
