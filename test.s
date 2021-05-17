
bin/sort_test_c:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

00000001000040c0 _linear_insertion_sort:
1000040c0: 55                          	pushq	%rbp
1000040c1: 48 89 e5                    	movq	%rsp, %rbp
1000040c4: 41 56                       	pushq	%r14
1000040c6: 53                          	pushq	%rbx
1000040c7: 83 ff 02                    	cmpl	$2, %edi
1000040ca: 0f 82 e1 00 00 00           	jb	225 <_linear_insertion_sort+0xf1>
1000040d0: 41 89 f9                    	movl	%edi, %r9d
1000040d3: 49 ff c9                    	decq	%r9
1000040d6: 45 89 c8                    	movl	%r9d, %r8d
1000040d9: 41 83 e0 01                 	andl	$1, %r8d
1000040dd: 41 be 01 00 00 00           	movl	$1, %r14d
1000040e3: 83 ff 02                    	cmpl	$2, %edi
1000040e6: 75 3a                       	jne	58 <_linear_insertion_sort+0x62>
1000040e8: 4d 85 c0                    	testq	%r8, %r8
1000040eb: 0f 84 c0 00 00 00           	je	192 <_linear_insertion_sort+0xf1>
1000040f1: 42 8b 0c b6                 	movl	(%rsi,%r14,4), %ecx
1000040f5: 44 89 f7                    	movl	%r14d, %edi
1000040f8: 0f 1f 84 00 00 00 00 00     	nopl	(%rax,%rax)
100004100: 8d 57 ff                    	leal	-1(%rdi), %edx
100004103: 8b 1c 96                    	movl	(%rsi,%rdx,4), %ebx
100004106: 89 ff                       	movl	%edi, %edi
100004108: 39 d9                       	cmpl	%ebx, %ecx
10000410a: 0f 83 9b 00 00 00           	jae	155 <_linear_insertion_sort+0xeb>
100004110: 89 1c be                    	movl	%ebx, (%rsi,%rdi,4)
100004113: 8d 47 fe                    	leal	-2(%rdi), %eax
100004116: ff cf                       	decl	%edi
100004118: 49 39 c6                    	cmpq	%rax, %r14
10000411b: 77 e3                       	ja	-29 <_linear_insertion_sort+0x40>
10000411d: e9 8c 00 00 00              	jmp	140 <_linear_insertion_sort+0xee>
100004122: 4d 29 c1                    	subq	%r8, %r9
100004125: 41 be 01 00 00 00           	movl	$1, %r14d
10000412b: 41 ba ff ff ff ff           	movl	$4294967295, %r10d
100004131: 45 31 db                    	xorl	%r11d, %r11d
100004134: eb 22                       	jmp	34 <_linear_insertion_sort+0x98>
100004136: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100004140: 48 89 df                    	movq	%rbx, %rdi
100004143: 89 0c be                    	movl	%ecx, (%rsi,%rdi,4)
100004146: 49 83 c6 02                 	addq	$2, %r14
10000414a: 41 83 c2 02                 	addl	$2, %r10d
10000414e: 41 83 c3 02                 	addl	$2, %r11d
100004152: 49 83 c1 fe                 	addq	$-2, %r9
100004156: 74 90                       	je	-112 <_linear_insertion_sort+0x28>
100004158: 42 8b 0c b6                 	movl	(%rsi,%r14,4), %ecx
10000415c: 44 89 d2                    	movl	%r10d, %edx
10000415f: 90                          	nop
100004160: 8d 7a 01                    	leal	1(%rdx), %edi
100004163: 8d 5a 02                    	leal	2(%rdx), %ebx
100004166: 8b 04 be                    	movl	(%rsi,%rdi,4), %eax
100004169: 39 c1                       	cmpl	%eax, %ecx
10000416b: 73 13                       	jae	19 <_linear_insertion_sort+0xc0>
10000416d: 89 04 9e                    	movl	%eax, (%rsi,%rbx,4)
100004170: 89 d0                       	movl	%edx, %eax
100004172: ff ca                       	decl	%edx
100004174: 49 39 c6                    	cmpq	%rax, %r14
100004177: 77 e7                       	ja	-25 <_linear_insertion_sort+0xa0>
100004179: eb 08                       	jmp	8 <_linear_insertion_sort+0xc3>
10000417b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100004180: 48 89 df                    	movq	%rbx, %rdi
100004183: 89 0c be                    	movl	%ecx, (%rsi,%rdi,4)
100004186: 42 8b 4c b6 04              	movl	4(%rsi,%r14,4), %ecx
10000418b: 44 89 da                    	movl	%r11d, %edx
10000418e: 66 90                       	nop
100004190: 8d 7a 01                    	leal	1(%rdx), %edi
100004193: 8d 5a 02                    	leal	2(%rdx), %ebx
100004196: 8b 04 be                    	movl	(%rsi,%rdi,4), %eax
100004199: 39 c1                       	cmpl	%eax, %ecx
10000419b: 73 a3                       	jae	-93 <_linear_insertion_sort+0x80>
10000419d: 89 04 9e                    	movl	%eax, (%rsi,%rbx,4)
1000041a0: 89 d0                       	movl	%edx, %eax
1000041a2: ff ca                       	decl	%edx
1000041a4: 49 39 c6                    	cmpq	%rax, %r14
1000041a7: 73 e7                       	jae	-25 <_linear_insertion_sort+0xd0>
1000041a9: eb 98                       	jmp	-104 <_linear_insertion_sort+0x83>
1000041ab: 48 89 fa                    	movq	%rdi, %rdx
1000041ae: 89 0c 96                    	movl	%ecx, (%rsi,%rdx,4)
1000041b1: 5b                          	popq	%rbx
1000041b2: 41 5e                       	popq	%r14
1000041b4: 5d                          	popq	%rbp
1000041b5: c3                          	retq
1000041b6: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)

00000001000041c0 _quick_sort_partition:
1000041c0: 55                          	pushq	%rbp
1000041c1: 48 89 e5                    	movq	%rsp, %rbp
1000041c4: 53                          	pushq	%rbx
1000041c5: 44 8d 47 ff                 	leal	-1(%rdi), %r8d
1000041c9: 89 d0                       	movl	%edx, %eax
1000041cb: 8b 14 86                    	movl	(%rsi,%rax,4), %edx
1000041ce: 42 8b 0c 86                 	movl	(%rsi,%r8,4), %ecx
1000041d2: 89 0c 86                    	movl	%ecx, (%rsi,%rax,4)
1000041d5: 42 89 14 86                 	movl	%edx, (%rsi,%r8,4)
1000041d9: 44 8b 0e                    	movl	(%rsi), %r9d
1000041dc: 31 c0                       	xorl	%eax, %eax
1000041de: 41 39 d1                    	cmpl	%edx, %r9d
1000041e1: 0f 93 c0                    	setae	%al
1000041e4: 44 89 c9                    	movl	%r9d, %ecx
1000041e7: 0f 42 ca                    	cmovbl	%edx, %ecx
1000041ea: 41 0f 42 d1                 	cmovbl	%r9d, %edx
1000041ee: 89 16                       	movl	%edx, (%rsi)
1000041f0: 42 89 0c 86                 	movl	%ecx, (%rsi,%r8,4)
1000041f4: 8d 0c 07                    	leal	(%rdi,%rax), %ecx
1000041f7: 83 c1 fe                    	addl	$-2, %ecx
1000041fa: 39 c1                       	cmpl	%eax, %ecx
1000041fc: 76 39                       	jbe	57 <_quick_sort_partition+0x77>
1000041fe: 89 c2                       	movl	%eax, %edx
100004200: 41 89 c8                    	movl	%ecx, %r8d
100004203: 42 8b 3c 86                 	movl	(%rsi,%r8,4), %edi
100004207: 41 89 c1                    	movl	%eax, %r9d
10000420a: 46 8b 14 8e                 	movl	(%rsi,%r9,4), %r10d
10000420e: 45 31 db                    	xorl	%r11d, %r11d
100004211: 41 39 fa                    	cmpl	%edi, %r10d
100004214: 41 0f 93 c3                 	setae	%r11b
100004218: 44 89 d3                    	movl	%r10d, %ebx
10000421b: 0f 42 df                    	cmovbl	%edi, %ebx
10000421e: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004222: 44 31 da                    	xorl	%r11d, %edx
100004225: 42 89 3c 8e                 	movl	%edi, (%rsi,%r9,4)
100004229: 42 89 1c 86                 	movl	%ebx, (%rsi,%r8,4)
10000422d: 01 d0                       	addl	%edx, %eax
10000422f: 01 d1                       	addl	%edx, %ecx
100004231: ff c9                       	decl	%ecx
100004233: 39 c8                       	cmpl	%ecx, %eax
100004235: 72 c9                       	jb	-55 <_quick_sort_partition+0x40>
100004237: 5b                          	popq	%rbx
100004238: 5d                          	popq	%rbp
100004239: c3                          	retq
10000423a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100004240 _quick_sort_recursive:
100004240: 55                          	pushq	%rbp
100004241: 48 89 e5                    	movq	%rsp, %rbp
100004244: 41 57                       	pushq	%r15
100004246: 41 56                       	pushq	%r14
100004248: 41 55                       	pushq	%r13
10000424a: 41 54                       	pushq	%r12
10000424c: 53                          	pushq	%rbx
10000424d: 48 83 ec 28                 	subq	$40, %rsp
100004251: 49 89 f6                    	movq	%rsi, %r14
100004254: 41 89 ff                    	movl	%edi, %r15d
100004257: 83 ff 11                    	cmpl	$17, %edi
10000425a: 73 14                       	jae	20 <_quick_sort_recursive+0x30>
10000425c: 44 89 fb                    	movl	%r15d, %ebx
10000425f: eb 42                       	jmp	66 <_quick_sort_recursive+0x63>
100004261: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
10000426b: 0f 1f 44 00 00              	nopl	(%rax,%rax)
100004270: 44 89 fa                    	movl	%r15d, %edx
100004273: d1 ea                       	shrl	%edx
100004275: 44 89 ff                    	movl	%r15d, %edi
100004278: 4c 89 f6                    	movq	%r14, %rsi
10000427b: e8 40 ff ff ff              	callq	-192 <_quick_sort_partition>
100004280: 89 c3                       	movl	%eax, %ebx
100004282: 89 c7                       	movl	%eax, %edi
100004284: 4c 89 f6                    	movq	%r14, %rsi
100004287: e8 b4 ff ff ff              	callq	-76 <_quick_sort_recursive>
10000428c: 89 d8                       	movl	%ebx, %eax
10000428e: f7 d3                       	notl	%ebx
100004290: 44 01 fb                    	addl	%r15d, %ebx
100004293: 4d 8d 34 86                 	leaq	(%r14,%rax,4), %r14
100004297: 49 83 c6 04                 	addq	$4, %r14
10000429b: 41 89 df                    	movl	%ebx, %r15d
10000429e: 83 fb 11                    	cmpl	$17, %ebx
1000042a1: 73 cd                       	jae	-51 <_quick_sort_recursive+0x30>
1000042a3: 83 c3 fe                    	addl	$-2, %ebx
1000042a6: 83 fb 0e                    	cmpl	$14, %ebx
1000042a9: 0f 87 f7 18 00 00           	ja	6391 <_quick_sort_recursive+0x1966>
1000042af: 48 8d 05 02 19 00 00        	leaq	6402(%rip), %rax
1000042b6: 48 63 0c 98                 	movslq	(%rax,%rbx,4), %rcx
1000042ba: 48 01 c1                    	addq	%rax, %rcx
1000042bd: ff e1                       	jmpq	*%rcx
1000042bf: 41 8b 06                    	movl	(%r14), %eax
1000042c2: 41 8b 4e 04                 	movl	4(%r14), %ecx
1000042c6: 39 c8                       	cmpl	%ecx, %eax
1000042c8: 89 c2                       	movl	%eax, %edx
1000042ca: 0f 42 d1                    	cmovbl	%ecx, %edx
1000042cd: 0f 42 c8                    	cmovbl	%eax, %ecx
1000042d0: 41 89 0e                    	movl	%ecx, (%r14)
1000042d3: 41 89 56 04                 	movl	%edx, 4(%r14)
1000042d7: e9 ca 18 00 00              	jmp	6346 <_quick_sort_recursive+0x1966>
1000042dc: 41 8b 06                    	movl	(%r14), %eax
1000042df: 41 8b 4e 04                 	movl	4(%r14), %ecx
1000042e3: 39 c8                       	cmpl	%ecx, %eax
1000042e5: 89 c2                       	movl	%eax, %edx
1000042e7: 0f 42 d1                    	cmovbl	%ecx, %edx
1000042ea: 0f 42 c8                    	cmovbl	%eax, %ecx
1000042ed: 41 8b 46 08                 	movl	8(%r14), %eax
1000042f1: 39 c2                       	cmpl	%eax, %edx
1000042f3: 89 d6                       	movl	%edx, %esi
1000042f5: 0f 42 f0                    	cmovbl	%eax, %esi
1000042f8: 0f 43 d0                    	cmovael	%eax, %edx
1000042fb: 41 89 76 08                 	movl	%esi, 8(%r14)
1000042ff: 39 d1                       	cmpl	%edx, %ecx
100004301: 89 c8                       	movl	%ecx, %eax
100004303: 0f 42 c2                    	cmovbl	%edx, %eax
100004306: 0f 42 d1                    	cmovbl	%ecx, %edx
100004309: 41 89 16                    	movl	%edx, (%r14)
10000430c: 41 89 46 04                 	movl	%eax, 4(%r14)
100004310: e9 91 18 00 00              	jmp	6289 <_quick_sort_recursive+0x1966>
100004315: 41 8b 06                    	movl	(%r14), %eax
100004318: 41 8b 4e 04                 	movl	4(%r14), %ecx
10000431c: 39 c8                       	cmpl	%ecx, %eax
10000431e: 89 c2                       	movl	%eax, %edx
100004320: 0f 42 d1                    	cmovbl	%ecx, %edx
100004323: 0f 42 c8                    	cmovbl	%eax, %ecx
100004326: 41 8b 46 0c                 	movl	12(%r14), %eax
10000432a: 41 8b 76 08                 	movl	8(%r14), %esi
10000432e: 39 f0                       	cmpl	%esi, %eax
100004330: 89 c7                       	movl	%eax, %edi
100004332: 0f 42 fe                    	cmovbl	%esi, %edi
100004335: 0f 42 f0                    	cmovbl	%eax, %esi
100004338: 39 f9                       	cmpl	%edi, %ecx
10000433a: 89 c8                       	movl	%ecx, %eax
10000433c: 0f 42 c7                    	cmovbl	%edi, %eax
10000433f: 0f 42 f9                    	cmovbl	%ecx, %edi
100004342: 39 f2                       	cmpl	%esi, %edx
100004344: 89 d1                       	movl	%edx, %ecx
100004346: 0f 42 ce                    	cmovbl	%esi, %ecx
100004349: 0f 42 f2                    	cmovbl	%edx, %esi
10000434c: 39 f7                       	cmpl	%esi, %edi
10000434e: 89 fa                       	movl	%edi, %edx
100004350: 0f 42 d6                    	cmovbl	%esi, %edx
100004353: 0f 42 f7                    	cmovbl	%edi, %esi
100004356: 41 89 36                    	movl	%esi, (%r14)
100004359: 41 89 56 04                 	movl	%edx, 4(%r14)
10000435d: e9 1e 01 00 00              	jmp	286 <_quick_sort_recursive+0x240>
100004362: 41 8b 0e                    	movl	(%r14), %ecx
100004365: 41 8b 46 04                 	movl	4(%r14), %eax
100004369: 39 c1                       	cmpl	%eax, %ecx
10000436b: 89 ca                       	movl	%ecx, %edx
10000436d: 0f 42 d0                    	cmovbl	%eax, %edx
100004370: 0f 42 c1                    	cmovbl	%ecx, %eax
100004373: 41 8b 7e 0c                 	movl	12(%r14), %edi
100004377: 41 8b 76 10                 	movl	16(%r14), %esi
10000437b: 39 f7                       	cmpl	%esi, %edi
10000437d: 89 f9                       	movl	%edi, %ecx
10000437f: 0f 42 ce                    	cmovbl	%esi, %ecx
100004382: 0f 42 f7                    	cmovbl	%edi, %esi
100004385: 41 8b 7e 08                 	movl	8(%r14), %edi
100004389: 39 cf                       	cmpl	%ecx, %edi
10000438b: 89 fb                       	movl	%edi, %ebx
10000438d: 0f 42 d9                    	cmovbl	%ecx, %ebx
100004390: 0f 42 cf                    	cmovbl	%edi, %ecx
100004393: 39 f1                       	cmpl	%esi, %ecx
100004395: 89 cf                       	movl	%ecx, %edi
100004397: 0f 42 fe                    	cmovbl	%esi, %edi
10000439a: 0f 43 ce                    	cmovael	%esi, %ecx
10000439d: 39 da                       	cmpl	%ebx, %edx
10000439f: 89 d6                       	movl	%edx, %esi
1000043a1: 0f 42 f3                    	cmovbl	%ebx, %esi
1000043a4: 0f 42 da                    	cmovbl	%edx, %ebx
1000043a7: 41 89 76 10                 	movl	%esi, 16(%r14)
1000043ab: 39 f8                       	cmpl	%edi, %eax
1000043ad: 89 c2                       	movl	%eax, %edx
1000043af: 0f 42 d7                    	cmovbl	%edi, %edx
1000043b2: 0f 42 f8                    	cmovbl	%eax, %edi
1000043b5: 39 cf                       	cmpl	%ecx, %edi
1000043b7: 89 f8                       	movl	%edi, %eax
1000043b9: 0f 42 c1                    	cmovbl	%ecx, %eax
1000043bc: 0f 43 f9                    	cmovael	%ecx, %edi
1000043bf: 41 89 3e                    	movl	%edi, (%r14)
1000043c2: 39 d3                       	cmpl	%edx, %ebx
1000043c4: 89 d9                       	movl	%ebx, %ecx
1000043c6: 0f 42 ca                    	cmovbl	%edx, %ecx
1000043c9: 0f 42 d3                    	cmovbl	%ebx, %edx
1000043cc: 41 89 4e 0c                 	movl	%ecx, 12(%r14)
1000043d0: 39 c2                       	cmpl	%eax, %edx
1000043d2: 89 d1                       	movl	%edx, %ecx
1000043d4: 0f 42 c8                    	cmovbl	%eax, %ecx
1000043d7: 0f 43 d0                    	cmovael	%eax, %edx
1000043da: 41 89 56 04                 	movl	%edx, 4(%r14)
1000043de: 41 89 4e 08                 	movl	%ecx, 8(%r14)
1000043e2: e9 bf 17 00 00              	jmp	6079 <_quick_sort_recursive+0x1966>
1000043e7: 41 8b 16                    	movl	(%r14), %edx
1000043ea: 41 8b 4e 04                 	movl	4(%r14), %ecx
1000043ee: 41 8b 76 08                 	movl	8(%r14), %esi
1000043f2: 39 f1                       	cmpl	%esi, %ecx
1000043f4: 89 c8                       	movl	%ecx, %eax
1000043f6: 0f 42 c6                    	cmovbl	%esi, %eax
1000043f9: 0f 42 f1                    	cmovbl	%ecx, %esi
1000043fc: 41 8b 7e 10                 	movl	16(%r14), %edi
100004400: 41 8b 5e 14                 	movl	20(%r14), %ebx
100004404: 39 df                       	cmpl	%ebx, %edi
100004406: 89 f9                       	movl	%edi, %ecx
100004408: 0f 42 cb                    	cmovbl	%ebx, %ecx
10000440b: 0f 42 df                    	cmovbl	%edi, %ebx
10000440e: 39 c2                       	cmpl	%eax, %edx
100004410: 41 89 d0                    	movl	%edx, %r8d
100004413: 44 0f 42 c0                 	cmovbl	%eax, %r8d
100004417: 0f 42 c2                    	cmovbl	%edx, %eax
10000441a: 41 8b 7e 0c                 	movl	12(%r14), %edi
10000441e: 39 cf                       	cmpl	%ecx, %edi
100004420: 89 fa                       	movl	%edi, %edx
100004422: 0f 42 d1                    	cmovbl	%ecx, %edx
100004425: 0f 42 cf                    	cmovbl	%edi, %ecx
100004428: 39 f0                       	cmpl	%esi, %eax
10000442a: 89 c7                       	movl	%eax, %edi
10000442c: 0f 42 fe                    	cmovbl	%esi, %edi
10000442f: 0f 43 c6                    	cmovael	%esi, %eax
100004432: 39 d9                       	cmpl	%ebx, %ecx
100004434: 89 ce                       	movl	%ecx, %esi
100004436: 0f 42 f3                    	cmovbl	%ebx, %esi
100004439: 0f 43 cb                    	cmovael	%ebx, %ecx
10000443c: 41 39 d0                    	cmpl	%edx, %r8d
10000443f: 44 89 c3                    	movl	%r8d, %ebx
100004442: 0f 42 da                    	cmovbl	%edx, %ebx
100004445: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100004449: 41 89 5e 14                 	movl	%ebx, 20(%r14)
10000444d: 39 c8                       	cmpl	%ecx, %eax
10000444f: 89 c3                       	movl	%eax, %ebx
100004451: 0f 42 d9                    	cmovbl	%ecx, %ebx
100004454: 0f 42 c8                    	cmovbl	%eax, %ecx
100004457: 41 89 0e                    	movl	%ecx, (%r14)
10000445a: 39 f7                       	cmpl	%esi, %edi
10000445c: 89 f8                       	movl	%edi, %eax
10000445e: 0f 42 c6                    	cmovbl	%esi, %eax
100004461: 0f 42 f7                    	cmovbl	%edi, %esi
100004464: 39 c2                       	cmpl	%eax, %edx
100004466: 89 d1                       	movl	%edx, %ecx
100004468: 0f 42 c8                    	cmovbl	%eax, %ecx
10000446b: 0f 42 c2                    	cmovbl	%edx, %eax
10000446e: 41 89 4e 10                 	movl	%ecx, 16(%r14)
100004472: 39 de                       	cmpl	%ebx, %esi
100004474: 89 f1                       	movl	%esi, %ecx
100004476: 0f 42 cb                    	cmovbl	%ebx, %ecx
100004479: 0f 43 f3                    	cmovael	%ebx, %esi
10000447c: 41 89 76 04                 	movl	%esi, 4(%r14)
100004480: 39 c8                       	cmpl	%ecx, %eax
100004482: 89 c2                       	movl	%eax, %edx
100004484: 0f 42 d1                    	cmovbl	%ecx, %edx
100004487: 0f 42 c8                    	cmovbl	%eax, %ecx
10000448a: 41 89 4e 08                 	movl	%ecx, 8(%r14)
10000448e: 41 89 56 0c                 	movl	%edx, 12(%r14)
100004492: e9 0f 17 00 00              	jmp	5903 <_quick_sort_recursive+0x1966>
100004497: 45 8b 0e                    	movl	(%r14), %r9d
10000449a: 41 8b 76 04                 	movl	4(%r14), %esi
10000449e: 41 8b 46 08                 	movl	8(%r14), %eax
1000044a2: 39 c6                       	cmpl	%eax, %esi
1000044a4: 89 f1                       	movl	%esi, %ecx
1000044a6: 0f 42 c8                    	cmovbl	%eax, %ecx
1000044a9: 0f 42 c6                    	cmovbl	%esi, %eax
1000044ac: 41 8b 76 0c                 	movl	12(%r14), %esi
1000044b0: 41 8b 5e 10                 	movl	16(%r14), %ebx
1000044b4: 39 de                       	cmpl	%ebx, %esi
1000044b6: 41 89 f2                    	movl	%esi, %r10d
1000044b9: 44 0f 42 d3                 	cmovbl	%ebx, %r10d
1000044bd: 0f 42 de                    	cmovbl	%esi, %ebx
1000044c0: 41 8b 56 14                 	movl	20(%r14), %edx
1000044c4: 41 8b 76 18                 	movl	24(%r14), %esi
1000044c8: 39 f2                       	cmpl	%esi, %edx
1000044ca: 89 d7                       	movl	%edx, %edi
1000044cc: 0f 42 fe                    	cmovbl	%esi, %edi
1000044cf: 0f 42 f2                    	cmovbl	%edx, %esi
1000044d2: 41 39 c9                    	cmpl	%ecx, %r9d
1000044d5: 45 89 c8                    	movl	%r9d, %r8d
1000044d8: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
1000044dc: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
1000044e0: 39 f3                       	cmpl	%esi, %ebx
1000044e2: 41 89 d9                    	movl	%ebx, %r9d
1000044e5: 44 0f 42 ce                 	cmovbl	%esi, %r9d
1000044e9: 0f 42 f3                    	cmovbl	%ebx, %esi
1000044ec: 39 c1                       	cmpl	%eax, %ecx
1000044ee: 89 cb                       	movl	%ecx, %ebx
1000044f0: 0f 42 d8                    	cmovbl	%eax, %ebx
1000044f3: 0f 43 c8                    	cmovael	%eax, %ecx
1000044f6: 41 39 fa                    	cmpl	%edi, %r10d
1000044f9: 44 89 d0                    	movl	%r10d, %eax
1000044fc: 0f 42 c7                    	cmovbl	%edi, %eax
1000044ff: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004503: 44 39 cf                    	cmpl	%r9d, %edi
100004506: 89 fa                       	movl	%edi, %edx
100004508: 41 0f 42 d1                 	cmovbl	%r9d, %edx
10000450c: 41 0f 43 f9                 	cmovael	%r9d, %edi
100004510: 39 f9                       	cmpl	%edi, %ecx
100004512: 41 89 c9                    	movl	%ecx, %r9d
100004515: 44 0f 42 cf                 	cmovbl	%edi, %r9d
100004519: 0f 42 f9                    	cmovbl	%ecx, %edi
10000451c: 39 f7                       	cmpl	%esi, %edi
10000451e: 89 f9                       	movl	%edi, %ecx
100004520: 0f 42 ce                    	cmovbl	%esi, %ecx
100004523: 0f 43 fe                    	cmovael	%esi, %edi
100004526: 41 89 3e                    	movl	%edi, (%r14)
100004529: 39 d3                       	cmpl	%edx, %ebx
10000452b: 89 de                       	movl	%ebx, %esi
10000452d: 0f 42 f2                    	cmovbl	%edx, %esi
100004530: 0f 42 d3                    	cmovbl	%ebx, %edx
100004533: 41 39 c0                    	cmpl	%eax, %r8d
100004536: 44 89 c7                    	movl	%r8d, %edi
100004539: 0f 42 f8                    	cmovbl	%eax, %edi
10000453c: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100004540: 41 89 7e 18                 	movl	%edi, 24(%r14)
100004544: 39 f0                       	cmpl	%esi, %eax
100004546: 89 c7                       	movl	%eax, %edi
100004548: 0f 42 fe                    	cmovbl	%esi, %edi
10000454b: 0f 43 c6                    	cmovael	%esi, %eax
10000454e: 41 89 7e 14                 	movl	%edi, 20(%r14)
100004552: 39 ca                       	cmpl	%ecx, %edx
100004554: 89 d6                       	movl	%edx, %esi
100004556: 0f 42 f1                    	cmovbl	%ecx, %esi
100004559: 0f 43 d1                    	cmovael	%ecx, %edx
10000455c: 41 89 56 04                 	movl	%edx, 4(%r14)
100004560: 44 39 c8                    	cmpl	%r9d, %eax
100004563: 89 c1                       	movl	%eax, %ecx
100004565: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
100004569: 41 0f 43 c1                 	cmovael	%r9d, %eax
10000456d: 41 89 4e 10                 	movl	%ecx, 16(%r14)
100004571: e9 7f 02 00 00              	jmp	639 <_quick_sort_recursive+0x5b5>
100004576: 41 8b 0e                    	movl	(%r14), %ecx
100004579: 41 8b 5e 04                 	movl	4(%r14), %ebx
10000457d: 39 d9                       	cmpl	%ebx, %ecx
10000457f: 41 89 c9                    	movl	%ecx, %r9d
100004582: 44 0f 42 cb                 	cmovbl	%ebx, %r9d
100004586: 0f 42 d9                    	cmovbl	%ecx, %ebx
100004589: 41 8b 76 08                 	movl	8(%r14), %esi
10000458d: 45 8b 66 0c                 	movl	12(%r14), %r12d
100004591: 44 39 e6                    	cmpl	%r12d, %esi
100004594: 89 f1                       	movl	%esi, %ecx
100004596: 41 0f 42 cc                 	cmovbl	%r12d, %ecx
10000459a: 44 0f 42 e6                 	cmovbl	%esi, %r12d
10000459e: 41 8b 76 10                 	movl	16(%r14), %esi
1000045a2: 41 8b 46 14                 	movl	20(%r14), %eax
1000045a6: 39 c6                       	cmpl	%eax, %esi
1000045a8: 41 89 f2                    	movl	%esi, %r10d
1000045ab: 44 0f 42 d0                 	cmovbl	%eax, %r10d
1000045af: 0f 42 c6                    	cmovbl	%esi, %eax
1000045b2: 45 8b 46 18                 	movl	24(%r14), %r8d
1000045b6: 41 8b 7e 1c                 	movl	28(%r14), %edi
1000045ba: 41 39 f8                    	cmpl	%edi, %r8d
1000045bd: 44 89 c6                    	movl	%r8d, %esi
1000045c0: 0f 42 f7                    	cmovbl	%edi, %esi
1000045c3: 41 0f 42 f8                 	cmovbl	%r8d, %edi
1000045c7: 44 39 e3                    	cmpl	%r12d, %ebx
1000045ca: 41 89 db                    	movl	%ebx, %r11d
1000045cd: 45 0f 42 dc                 	cmovbl	%r12d, %r11d
1000045d1: 44 0f 42 e3                 	cmovbl	%ebx, %r12d
1000045d5: 39 f8                       	cmpl	%edi, %eax
1000045d7: 41 89 c7                    	movl	%eax, %r15d
1000045da: 44 0f 42 ff                 	cmovbl	%edi, %r15d
1000045de: 0f 42 f8                    	cmovbl	%eax, %edi
1000045e1: 41 39 c9                    	cmpl	%ecx, %r9d
1000045e4: 45 89 c8                    	movl	%r9d, %r8d
1000045e7: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
1000045eb: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
1000045ef: 41 39 f2                    	cmpl	%esi, %r10d
1000045f2: 44 89 d0                    	movl	%r10d, %eax
1000045f5: 0f 42 c6                    	cmovbl	%esi, %eax
1000045f8: 41 0f 42 f2                 	cmovbl	%r10d, %esi
1000045fc: 44 39 d9                    	cmpl	%r11d, %ecx
1000045ff: 41 89 c9                    	movl	%ecx, %r9d
100004602: 45 0f 42 cb                 	cmovbl	%r11d, %r9d
100004606: 41 0f 43 cb                 	cmovael	%r11d, %ecx
10000460a: 44 39 fe                    	cmpl	%r15d, %esi
10000460d: 89 f3                       	movl	%esi, %ebx
10000460f: 41 0f 42 df                 	cmovbl	%r15d, %ebx
100004613: 41 0f 43 f7                 	cmovael	%r15d, %esi
100004617: 41 39 fc                    	cmpl	%edi, %r12d
10000461a: 44 89 e2                    	movl	%r12d, %edx
10000461d: 0f 42 d7                    	cmovbl	%edi, %edx
100004620: 41 0f 42 fc                 	cmovbl	%r12d, %edi
100004624: 41 89 3e                    	movl	%edi, (%r14)
100004627: 39 f1                       	cmpl	%esi, %ecx
100004629: 89 cf                       	movl	%ecx, %edi
10000462b: 0f 42 fe                    	cmovbl	%esi, %edi
10000462e: 0f 42 f1                    	cmovbl	%ecx, %esi
100004631: 39 d6                       	cmpl	%edx, %esi
100004633: 89 f1                       	movl	%esi, %ecx
100004635: 0f 42 ca                    	cmovbl	%edx, %ecx
100004638: 0f 43 f2                    	cmovael	%edx, %esi
10000463b: 41 89 76 04                 	movl	%esi, 4(%r14)
10000463f: 41 39 d9                    	cmpl	%ebx, %r9d
100004642: 44 89 ca                    	movl	%r9d, %edx
100004645: 0f 42 d3                    	cmovbl	%ebx, %edx
100004648: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
10000464c: 41 39 c0                    	cmpl	%eax, %r8d
10000464f: 44 89 c6                    	movl	%r8d, %esi
100004652: 0f 42 f0                    	cmovbl	%eax, %esi
100004655: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100004659: 41 89 76 1c                 	movl	%esi, 28(%r14)
10000465d: 39 d0                       	cmpl	%edx, %eax
10000465f: 89 c6                       	movl	%eax, %esi
100004661: 0f 42 f2                    	cmovbl	%edx, %esi
100004664: 0f 43 c2                    	cmovael	%edx, %eax
100004667: 41 89 76 18                 	movl	%esi, 24(%r14)
10000466b: 39 cb                       	cmpl	%ecx, %ebx
10000466d: 89 da                       	movl	%ebx, %edx
10000466f: 0f 42 d1                    	cmovbl	%ecx, %edx
100004672: 0f 43 d9                    	cmovael	%ecx, %ebx
100004675: 41 89 5e 08                 	movl	%ebx, 8(%r14)
100004679: 39 f8                       	cmpl	%edi, %eax
10000467b: 89 c1                       	movl	%eax, %ecx
10000467d: 0f 42 cf                    	cmovbl	%edi, %ecx
100004680: 0f 43 c7                    	cmovael	%edi, %eax
100004683: 41 89 4e 14                 	movl	%ecx, 20(%r14)
100004687: 39 d0                       	cmpl	%edx, %eax
100004689: 89 c1                       	movl	%eax, %ecx
10000468b: 0f 42 ca                    	cmovbl	%edx, %ecx
10000468e: 0f 43 c2                    	cmovael	%edx, %eax
100004691: 41 89 46 0c                 	movl	%eax, 12(%r14)
100004695: 41 89 4e 10                 	movl	%ecx, 16(%r14)
100004699: e9 08 15 00 00              	jmp	5384 <_quick_sort_recursive+0x1966>
10000469e: 41 8b 06                    	movl	(%r14), %eax
1000046a1: 45 8b 5e 04                 	movl	4(%r14), %r11d
1000046a5: 44 39 d8                    	cmpl	%r11d, %eax
1000046a8: 89 c7                       	movl	%eax, %edi
1000046aa: 41 0f 42 fb                 	cmovbl	%r11d, %edi
1000046ae: 44 0f 42 d8                 	cmovbl	%eax, %r11d
1000046b2: 41 8b 4e 0c                 	movl	12(%r14), %ecx
1000046b6: 41 8b 46 10                 	movl	16(%r14), %eax
1000046ba: 39 c1                       	cmpl	%eax, %ecx
1000046bc: 89 ce                       	movl	%ecx, %esi
1000046be: 0f 42 f0                    	cmovbl	%eax, %esi
1000046c1: 0f 42 c1                    	cmovbl	%ecx, %eax
1000046c4: 41 8b 5e 18                 	movl	24(%r14), %ebx
1000046c8: 41 8b 4e 1c                 	movl	28(%r14), %ecx
1000046cc: 39 cb                       	cmpl	%ecx, %ebx
1000046ce: 89 da                       	movl	%ebx, %edx
1000046d0: 0f 42 d1                    	cmovbl	%ecx, %edx
1000046d3: 0f 42 cb                    	cmovbl	%ebx, %ecx
1000046d6: 41 8b 5e 08                 	movl	8(%r14), %ebx
1000046da: 39 df                       	cmpl	%ebx, %edi
1000046dc: 41 89 f8                    	movl	%edi, %r8d
1000046df: 44 0f 42 c3                 	cmovbl	%ebx, %r8d
1000046e3: 0f 43 fb                    	cmovael	%ebx, %edi
1000046e6: 41 8b 5e 14                 	movl	20(%r14), %ebx
1000046ea: 39 de                       	cmpl	%ebx, %esi
1000046ec: 41 89 f2                    	movl	%esi, %r10d
1000046ef: 44 0f 42 d3                 	cmovbl	%ebx, %r10d
1000046f3: 0f 43 f3                    	cmovael	%ebx, %esi
1000046f6: 41 8b 5e 20                 	movl	32(%r14), %ebx
1000046fa: 39 da                       	cmpl	%ebx, %edx
1000046fc: 41 89 d1                    	movl	%edx, %r9d
1000046ff: 44 0f 42 cb                 	cmovbl	%ebx, %r9d
100004703: 0f 43 d3                    	cmovael	%ebx, %edx
100004706: 41 39 fb                    	cmpl	%edi, %r11d
100004709: 45 89 df                    	movl	%r11d, %r15d
10000470c: 44 0f 42 ff                 	cmovbl	%edi, %r15d
100004710: 41 0f 42 fb                 	cmovbl	%r11d, %edi
100004714: 39 f0                       	cmpl	%esi, %eax
100004716: 89 c3                       	movl	%eax, %ebx
100004718: 0f 42 de                    	cmovbl	%esi, %ebx
10000471b: 0f 42 f0                    	cmovbl	%eax, %esi
10000471e: 39 d1                       	cmpl	%edx, %ecx
100004720: 89 c8                       	movl	%ecx, %eax
100004722: 0f 42 c2                    	cmovbl	%edx, %eax
100004725: 0f 42 d1                    	cmovbl	%ecx, %edx
100004728: 39 f7                       	cmpl	%esi, %edi
10000472a: 89 f9                       	movl	%edi, %ecx
10000472c: 0f 42 ce                    	cmovbl	%esi, %ecx
10000472f: 0f 42 f7                    	cmovbl	%edi, %esi
100004732: 39 d1                       	cmpl	%edx, %ecx
100004734: 41 89 cb                    	movl	%ecx, %r11d
100004737: 44 0f 42 da                 	cmovbl	%edx, %r11d
10000473b: 0f 43 ca                    	cmovael	%edx, %ecx
10000473e: 39 ce                       	cmpl	%ecx, %esi
100004740: 41 89 f4                    	movl	%esi, %r12d
100004743: 44 0f 42 e1                 	cmovbl	%ecx, %r12d
100004747: 0f 42 ce                    	cmovbl	%esi, %ecx
10000474a: 41 89 0e                    	movl	%ecx, (%r14)
10000474d: 41 39 df                    	cmpl	%ebx, %r15d
100004750: 44 89 ff                    	movl	%r15d, %edi
100004753: 0f 42 fb                    	cmovbl	%ebx, %edi
100004756: 41 0f 42 df                 	cmovbl	%r15d, %ebx
10000475a: 39 c7                       	cmpl	%eax, %edi
10000475c: 89 f9                       	movl	%edi, %ecx
10000475e: 0f 42 c8                    	cmovbl	%eax, %ecx
100004761: 0f 43 f8                    	cmovael	%eax, %edi
100004764: 39 fb                       	cmpl	%edi, %ebx
100004766: 41 89 df                    	movl	%ebx, %r15d
100004769: 44 0f 42 ff                 	cmovbl	%edi, %r15d
10000476d: 0f 42 fb                    	cmovbl	%ebx, %edi
100004770: 45 39 d0                    	cmpl	%r10d, %r8d
100004773: 44 89 c2                    	movl	%r8d, %edx
100004776: 41 0f 42 d2                 	cmovbl	%r10d, %edx
10000477a: 45 0f 42 d0                 	cmovbl	%r8d, %r10d
10000477e: 44 39 ca                    	cmpl	%r9d, %edx
100004781: 89 d0                       	movl	%edx, %eax
100004783: 41 0f 42 c1                 	cmovbl	%r9d, %eax
100004787: 41 0f 43 d1                 	cmovael	%r9d, %edx
10000478b: 41 89 46 20                 	movl	%eax, 32(%r14)
10000478f: 41 39 d2                    	cmpl	%edx, %r10d
100004792: 44 89 d3                    	movl	%r10d, %ebx
100004795: 0f 42 da                    	cmovbl	%edx, %ebx
100004798: 41 0f 42 d2                 	cmovbl	%r10d, %edx
10000479c: 44 39 e7                    	cmpl	%r12d, %edi
10000479f: 89 fe                       	movl	%edi, %esi
1000047a1: 41 0f 42 f4                 	cmovbl	%r12d, %esi
1000047a5: 41 0f 43 fc                 	cmovael	%r12d, %edi
1000047a9: 41 89 7e 04                 	movl	%edi, 4(%r14)
1000047ad: 39 cb                       	cmpl	%ecx, %ebx
1000047af: 89 d8                       	movl	%ebx, %eax
1000047b1: 0f 42 c1                    	cmovbl	%ecx, %eax
1000047b4: 0f 43 d9                    	cmovael	%ecx, %ebx
1000047b7: 41 89 46 1c                 	movl	%eax, 28(%r14)
1000047bb: 44 39 da                    	cmpl	%r11d, %edx
1000047be: 89 d0                       	movl	%edx, %eax
1000047c0: 41 0f 42 c3                 	cmovbl	%r11d, %eax
1000047c4: 41 0f 43 d3                 	cmovael	%r11d, %edx
1000047c8: 41 39 c7                    	cmpl	%eax, %r15d
1000047cb: 44 89 f9                    	movl	%r15d, %ecx
1000047ce: 0f 42 c8                    	cmovbl	%eax, %ecx
1000047d1: 41 0f 42 c7                 	cmovbl	%r15d, %eax
1000047d5: 39 c2                       	cmpl	%eax, %edx
1000047d7: 89 d7                       	movl	%edx, %edi
1000047d9: 0f 42 f8                    	cmovbl	%eax, %edi
1000047dc: 0f 42 c2                    	cmovbl	%edx, %eax
1000047df: 41 89 7e 10                 	movl	%edi, 16(%r14)
1000047e3: 39 cb                       	cmpl	%ecx, %ebx
1000047e5: 89 da                       	movl	%ebx, %edx
1000047e7: 0f 42 d1                    	cmovbl	%ecx, %edx
1000047ea: 0f 42 cb                    	cmovbl	%ebx, %ecx
1000047ed: 41 89 4e 14                 	movl	%ecx, 20(%r14)
1000047f1: 41 89 56 18                 	movl	%edx, 24(%r14)
1000047f5: 39 f0                       	cmpl	%esi, %eax
1000047f7: 89 c1                       	movl	%eax, %ecx
1000047f9: 0f 42 ce                    	cmovbl	%esi, %ecx
1000047fc: 0f 43 c6                    	cmovael	%esi, %eax
1000047ff: 41 89 46 08                 	movl	%eax, 8(%r14)
100004803: 41 89 4e 0c                 	movl	%ecx, 12(%r14)
100004807: e9 9a 13 00 00              	jmp	5018 <_quick_sort_recursive+0x1966>
10000480c: 41 8b 46 10                 	movl	16(%r14), %eax
100004810: 41 8b 76 24                 	movl	36(%r14), %esi
100004814: 39 f0                       	cmpl	%esi, %eax
100004816: 41 89 c2                    	movl	%eax, %r10d
100004819: 44 0f 42 d6                 	cmovbl	%esi, %r10d
10000481d: 0f 42 f0                    	cmovbl	%eax, %esi
100004820: 41 8b 46 0c                 	movl	12(%r14), %eax
100004824: 41 8b 5e 20                 	movl	32(%r14), %ebx
100004828: 39 d8                       	cmpl	%ebx, %eax
10000482a: 41 89 c3                    	movl	%eax, %r11d
10000482d: 44 0f 42 db                 	cmovbl	%ebx, %r11d
100004831: 0f 42 d8                    	cmovbl	%eax, %ebx
100004834: 41 8b 46 08                 	movl	8(%r14), %eax
100004838: 45 8b 4e 1c                 	movl	28(%r14), %r9d
10000483c: 44 39 c8                    	cmpl	%r9d, %eax
10000483f: 41 89 c7                    	movl	%eax, %r15d
100004842: 45 0f 42 f9                 	cmovbl	%r9d, %r15d
100004846: 44 0f 42 c8                 	cmovbl	%eax, %r9d
10000484a: 41 8b 06                    	movl	(%r14), %eax
10000484d: 41 8b 7e 04                 	movl	4(%r14), %edi
100004851: 41 8b 56 18                 	movl	24(%r14), %edx
100004855: 39 d7                       	cmpl	%edx, %edi
100004857: 89 f9                       	movl	%edi, %ecx
100004859: 0f 42 ca                    	cmovbl	%edx, %ecx
10000485c: 0f 42 d7                    	cmovbl	%edi, %edx
10000485f: 41 8b 7e 14                 	movl	20(%r14), %edi
100004863: 39 f8                       	cmpl	%edi, %eax
100004865: 41 89 c0                    	movl	%eax, %r8d
100004868: 44 0f 42 c7                 	cmovbl	%edi, %r8d
10000486c: 0f 42 f8                    	cmovbl	%eax, %edi
10000486f: 44 39 d1                    	cmpl	%r10d, %ecx
100004872: 89 c8                       	movl	%ecx, %eax
100004874: 41 0f 42 c2                 	cmovbl	%r10d, %eax
100004878: 41 0f 43 ca                 	cmovael	%r10d, %ecx
10000487c: 39 f2                       	cmpl	%esi, %edx
10000487e: 41 89 d2                    	movl	%edx, %r10d
100004881: 44 0f 42 d6                 	cmovbl	%esi, %r10d
100004885: 0f 43 d6                    	cmovael	%esi, %edx
100004888: 45 39 d8                    	cmpl	%r11d, %r8d
10000488b: 45 89 c4                    	movl	%r8d, %r12d
10000488e: 45 0f 42 e3                 	cmovbl	%r11d, %r12d
100004892: 45 0f 43 c3                 	cmovael	%r11d, %r8d
100004896: 39 df                       	cmpl	%ebx, %edi
100004898: 41 89 fb                    	movl	%edi, %r11d
10000489b: 44 0f 42 db                 	cmovbl	%ebx, %r11d
10000489f: 0f 43 fb                    	cmovael	%ebx, %edi
1000048a2: 41 39 c7                    	cmpl	%eax, %r15d
1000048a5: 44 89 fe                    	movl	%r15d, %esi
1000048a8: 0f 42 f0                    	cmovbl	%eax, %esi
1000048ab: 41 0f 42 c7                 	cmovbl	%r15d, %eax
1000048af: 44 39 cf                    	cmpl	%r9d, %edi
1000048b2: 89 fb                       	movl	%edi, %ebx
1000048b4: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
1000048b8: 41 0f 43 f9                 	cmovael	%r9d, %edi
1000048bc: 41 39 cb                    	cmpl	%ecx, %r11d
1000048bf: 45 89 d9                    	movl	%r11d, %r9d
1000048c2: 44 0f 42 c9                 	cmovbl	%ecx, %r9d
1000048c6: 44 0f 43 d9                 	cmovael	%ecx, %r11d
1000048ca: 41 39 f4                    	cmpl	%esi, %r12d
1000048cd: 44 89 e1                    	movl	%r12d, %ecx
1000048d0: 0f 42 ce                    	cmovbl	%esi, %ecx
1000048d3: 41 0f 42 f4                 	cmovbl	%r12d, %esi
1000048d7: 41 89 4e 24                 	movl	%ecx, 36(%r14)
1000048db: 39 d7                       	cmpl	%edx, %edi
1000048dd: 89 f9                       	movl	%edi, %ecx
1000048df: 0f 42 ca                    	cmovbl	%edx, %ecx
1000048e2: 0f 43 fa                    	cmovael	%edx, %edi
1000048e5: 41 89 3e                    	movl	%edi, (%r14)
1000048e8: 44 39 d3                    	cmpl	%r10d, %ebx
1000048eb: 41 89 df                    	movl	%ebx, %r15d
1000048ee: 45 0f 42 fa                 	cmovbl	%r10d, %r15d
1000048f2: 41 0f 43 da                 	cmovael	%r10d, %ebx
1000048f6: 41 39 c0                    	cmpl	%eax, %r8d
1000048f9: 44 89 c2                    	movl	%r8d, %edx
1000048fc: 0f 42 d0                    	cmovbl	%eax, %edx
1000048ff: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100004903: 39 d9                       	cmpl	%ebx, %ecx
100004905: 41 89 c8                    	movl	%ecx, %r8d
100004908: 44 0f 42 c3                 	cmovbl	%ebx, %r8d
10000490c: 0f 42 d9                    	cmovbl	%ecx, %ebx
10000490f: 45 39 cf                    	cmpl	%r9d, %r15d
100004912: 44 89 f9                    	movl	%r15d, %ecx
100004915: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
100004919: 45 0f 43 f9                 	cmovael	%r9d, %r15d
10000491d: 39 f2                       	cmpl	%esi, %edx
10000491f: 41 89 d2                    	movl	%edx, %r10d
100004922: 44 0f 42 d6                 	cmovbl	%esi, %r10d
100004926: 0f 43 d6                    	cmovael	%esi, %edx
100004929: 41 39 c3                    	cmpl	%eax, %r11d
10000492c: 44 89 df                    	movl	%r11d, %edi
10000492f: 0f 42 f8                    	cmovbl	%eax, %edi
100004932: 41 0f 42 c3                 	cmovbl	%r11d, %eax
100004936: 44 39 d1                    	cmpl	%r10d, %ecx
100004939: 41 89 c9                    	movl	%ecx, %r9d
10000493c: 45 0f 42 ca                 	cmovbl	%r10d, %r9d
100004940: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
100004944: 45 89 4e 20                 	movl	%r9d, 32(%r14)
100004948: 41 39 f8                    	cmpl	%edi, %r8d
10000494b: 45 89 c1                    	movl	%r8d, %r9d
10000494e: 44 0f 42 cf                 	cmovbl	%edi, %r9d
100004952: 41 0f 42 f8                 	cmovbl	%r8d, %edi
100004956: 39 c3                       	cmpl	%eax, %ebx
100004958: 89 d9                       	movl	%ebx, %ecx
10000495a: 0f 42 c8                    	cmovbl	%eax, %ecx
10000495d: 0f 42 c3                    	cmovbl	%ebx, %eax
100004960: 41 89 46 04                 	movl	%eax, 4(%r14)
100004964: 41 39 d7                    	cmpl	%edx, %r15d
100004967: 44 89 f8                    	movl	%r15d, %eax
10000496a: 0f 42 c2                    	cmovbl	%edx, %eax
10000496d: 41 0f 42 d7                 	cmovbl	%r15d, %edx
100004971: 39 cf                       	cmpl	%ecx, %edi
100004973: 89 fe                       	movl	%edi, %esi
100004975: 0f 42 f1                    	cmovbl	%ecx, %esi
100004978: 0f 42 cf                    	cmovbl	%edi, %ecx
10000497b: 41 89 4e 08                 	movl	%ecx, 8(%r14)
10000497f: 41 39 c2                    	cmpl	%eax, %r10d
100004982: 44 89 d1                    	movl	%r10d, %ecx
100004985: 0f 42 c8                    	cmovbl	%eax, %ecx
100004988: 41 0f 42 c2                 	cmovbl	%r10d, %eax
10000498c: 41 89 4e 1c                 	movl	%ecx, 28(%r14)
100004990: 39 d6                       	cmpl	%edx, %esi
100004992: 89 f1                       	movl	%esi, %ecx
100004994: 0f 42 ca                    	cmovbl	%edx, %ecx
100004997: 0f 43 f2                    	cmovael	%edx, %esi
10000499a: 41 89 76 0c                 	movl	%esi, 12(%r14)
10000499e: 41 39 c1                    	cmpl	%eax, %r9d
1000049a1: 44 89 ca                    	movl	%r9d, %edx
1000049a4: 0f 42 d0                    	cmovbl	%eax, %edx
1000049a7: 41 0f 42 c1                 	cmovbl	%r9d, %eax
1000049ab: 41 89 56 18                 	movl	%edx, 24(%r14)
1000049af: 39 c1                       	cmpl	%eax, %ecx
1000049b1: 89 ca                       	movl	%ecx, %edx
1000049b3: 0f 42 d0                    	cmovbl	%eax, %edx
1000049b6: 0f 42 c1                    	cmovbl	%ecx, %eax
1000049b9: 41 89 46 10                 	movl	%eax, 16(%r14)
1000049bd: 41 89 56 14                 	movl	%edx, 20(%r14)
1000049c1: e9 e0 11 00 00              	jmp	4576 <_quick_sort_recursive+0x1966>
1000049c6: 41 8b 06                    	movl	(%r14), %eax
1000049c9: 45 8b 6e 04                 	movl	4(%r14), %r13d
1000049cd: 44 39 e8                    	cmpl	%r13d, %eax
1000049d0: 41 89 c2                    	movl	%eax, %r10d
1000049d3: 45 0f 42 d5                 	cmovbl	%r13d, %r10d
1000049d7: 44 0f 42 e8                 	cmovbl	%eax, %r13d
1000049db: 41 8b 46 08                 	movl	8(%r14), %eax
1000049df: 45 8b 7e 0c                 	movl	12(%r14), %r15d
1000049e3: 44 39 f8                    	cmpl	%r15d, %eax
1000049e6: 89 c7                       	movl	%eax, %edi
1000049e8: 41 0f 42 ff                 	cmovbl	%r15d, %edi
1000049ec: 44 0f 42 f8                 	cmovbl	%eax, %r15d
1000049f0: 41 8b 46 10                 	movl	16(%r14), %eax
1000049f4: 41 8b 4e 14                 	movl	20(%r14), %ecx
1000049f8: 39 c8                       	cmpl	%ecx, %eax
1000049fa: 89 c6                       	movl	%eax, %esi
1000049fc: 0f 42 f1                    	cmovbl	%ecx, %esi
1000049ff: 0f 42 c8                    	cmovbl	%eax, %ecx
100004a02: 41 8b 5e 18                 	movl	24(%r14), %ebx
100004a06: 41 8b 46 1c                 	movl	28(%r14), %eax
100004a0a: 39 c3                       	cmpl	%eax, %ebx
100004a0c: 89 da                       	movl	%ebx, %edx
100004a0e: 0f 42 d0                    	cmovbl	%eax, %edx
100004a11: 0f 42 c3                    	cmovbl	%ebx, %eax
100004a14: 41 8b 5e 20                 	movl	32(%r14), %ebx
100004a18: 45 8b 66 24                 	movl	36(%r14), %r12d
100004a1c: 44 39 e3                    	cmpl	%r12d, %ebx
100004a1f: 41 89 d9                    	movl	%ebx, %r9d
100004a22: 45 0f 42 cc                 	cmovbl	%r12d, %r9d
100004a26: 44 0f 42 e3                 	cmovbl	%ebx, %r12d
100004a2a: 41 39 fa                    	cmpl	%edi, %r10d
100004a2d: 44 89 d3                    	movl	%r10d, %ebx
100004a30: 0f 42 df                    	cmovbl	%edi, %ebx
100004a33: 89 5d d4                    	movl	%ebx, -44(%rbp)
100004a36: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004a3a: 39 d6                       	cmpl	%edx, %esi
100004a3c: 41 89 f3                    	movl	%esi, %r11d
100004a3f: 44 0f 42 da                 	cmovbl	%edx, %r11d
100004a43: 0f 42 d6                    	cmovbl	%esi, %edx
100004a46: 41 8b 5e 28                 	movl	40(%r14), %ebx
100004a4a: 41 39 dc                    	cmpl	%ebx, %r12d
100004a4d: 44 89 e6                    	movl	%r12d, %esi
100004a50: 0f 42 f3                    	cmovbl	%ebx, %esi
100004a53: 44 0f 43 e3                 	cmovael	%ebx, %r12d
100004a57: 45 39 fd                    	cmpl	%r15d, %r13d
100004a5a: 45 89 ea                    	movl	%r13d, %r10d
100004a5d: 45 0f 42 d7                 	cmovbl	%r15d, %r10d
100004a61: 45 0f 42 fd                 	cmovbl	%r13d, %r15d
100004a65: 39 c1                       	cmpl	%eax, %ecx
100004a67: 89 cb                       	movl	%ecx, %ebx
100004a69: 0f 42 d8                    	cmovbl	%eax, %ebx
100004a6c: 0f 42 c1                    	cmovbl	%ecx, %eax
100004a6f: 41 39 f1                    	cmpl	%esi, %r9d
100004a72: 44 89 c9                    	movl	%r9d, %ecx
100004a75: 0f 42 ce                    	cmovbl	%esi, %ecx
100004a78: 41 0f 42 f1                 	cmovbl	%r9d, %esi
100004a7c: 44 39 d7                    	cmpl	%r10d, %edi
100004a7f: 41 89 f9                    	movl	%edi, %r9d
100004a82: 45 0f 42 ca                 	cmovbl	%r10d, %r9d
100004a86: 44 0f 42 d7                 	cmovbl	%edi, %r10d
100004a8a: 39 da                       	cmpl	%ebx, %edx
100004a8c: 89 d7                       	movl	%edx, %edi
100004a8e: 0f 42 fb                    	cmovbl	%ebx, %edi
100004a91: 0f 42 da                    	cmovbl	%edx, %ebx
100004a94: 41 39 da                    	cmpl	%ebx, %r10d
100004a97: 44 89 d2                    	movl	%r10d, %edx
100004a9a: 0f 42 d3                    	cmovbl	%ebx, %edx
100004a9d: 41 0f 42 da                 	cmovbl	%r10d, %ebx
100004aa1: 39 cf                       	cmpl	%ecx, %edi
100004aa3: 41 89 f8                    	movl	%edi, %r8d
100004aa6: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100004aaa: 0f 43 f9                    	cmovael	%ecx, %edi
100004aad: 39 f2                       	cmpl	%esi, %edx
100004aaf: 41 89 d2                    	movl	%edx, %r10d
100004ab2: 44 0f 42 d6                 	cmovbl	%esi, %r10d
100004ab6: 0f 43 d6                    	cmovael	%esi, %edx
100004ab9: 41 39 f9                    	cmpl	%edi, %r9d
100004abc: 45 89 cd                    	movl	%r9d, %r13d
100004abf: 44 0f 42 ef                 	cmovbl	%edi, %r13d
100004ac3: 41 0f 42 f9                 	cmovbl	%r9d, %edi
100004ac7: 39 d3                       	cmpl	%edx, %ebx
100004ac9: 41 89 d9                    	movl	%ebx, %r9d
100004acc: 44 0f 42 ca                 	cmovbl	%edx, %r9d
100004ad0: 0f 42 d3                    	cmovbl	%ebx, %edx
100004ad3: 45 39 c5                    	cmpl	%r8d, %r13d
100004ad6: 44 89 e9                    	movl	%r13d, %ecx
100004ad9: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100004add: 45 0f 43 e8                 	cmovael	%r8d, %r13d
100004ae1: 41 39 c7                    	cmpl	%eax, %r15d
100004ae4: 44 89 fb                    	movl	%r15d, %ebx
100004ae7: 0f 42 d8                    	cmovbl	%eax, %ebx
100004aea: 41 0f 42 c7                 	cmovbl	%r15d, %eax
100004aee: 8b 75 d4                    	movl	-44(%rbp), %esi
100004af1: 44 39 de                    	cmpl	%r11d, %esi
100004af4: 41 89 f0                    	movl	%esi, %r8d
100004af7: 45 0f 42 c3                 	cmovbl	%r11d, %r8d
100004afb: 44 0f 42 de                 	cmovbl	%esi, %r11d
100004aff: 44 39 e3                    	cmpl	%r12d, %ebx
100004b02: 89 de                       	movl	%ebx, %esi
100004b04: 41 0f 42 f4                 	cmovbl	%r12d, %esi
100004b08: 41 0f 43 dc                 	cmovael	%r12d, %ebx
100004b0c: 39 d8                       	cmpl	%ebx, %eax
100004b0e: 41 89 c7                    	movl	%eax, %r15d
100004b11: 44 0f 42 fb                 	cmovbl	%ebx, %r15d
100004b15: 0f 42 d8                    	cmovbl	%eax, %ebx
100004b18: 41 89 1e                    	movl	%ebx, (%r14)
100004b1b: 41 39 c8                    	cmpl	%ecx, %r8d
100004b1e: 44 89 c0                    	movl	%r8d, %eax
100004b21: 0f 42 c1                    	cmovbl	%ecx, %eax
100004b24: 44 0f 43 c1                 	cmovael	%ecx, %r8d
100004b28: 41 89 46 28                 	movl	%eax, 40(%r14)
100004b2c: 44 39 fa                    	cmpl	%r15d, %edx
100004b2f: 89 d3                       	movl	%edx, %ebx
100004b31: 41 0f 42 df                 	cmovbl	%r15d, %ebx
100004b35: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100004b39: 45 89 7e 04                 	movl	%r15d, 4(%r14)
100004b3d: 41 39 f3                    	cmpl	%esi, %r11d
100004b40: 44 89 d8                    	movl	%r11d, %eax
100004b43: 0f 42 c6                    	cmovbl	%esi, %eax
100004b46: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100004b4a: 39 f7                       	cmpl	%esi, %edi
100004b4c: 89 f9                       	movl	%edi, %ecx
100004b4e: 0f 42 ce                    	cmovbl	%esi, %ecx
100004b51: 0f 42 f7                    	cmovbl	%edi, %esi
100004b54: 44 39 d0                    	cmpl	%r10d, %eax
100004b57: 89 c2                       	movl	%eax, %edx
100004b59: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100004b5d: 41 0f 43 c2                 	cmovael	%r10d, %eax
100004b61: 39 de                       	cmpl	%ebx, %esi
100004b63: 41 89 f2                    	movl	%esi, %r10d
100004b66: 44 0f 42 d3                 	cmovbl	%ebx, %r10d
100004b6a: 0f 43 f3                    	cmovael	%ebx, %esi
100004b6d: 41 89 76 08                 	movl	%esi, 8(%r14)
100004b71: 41 39 d0                    	cmpl	%edx, %r8d
100004b74: 44 89 c6                    	movl	%r8d, %esi
100004b77: 0f 42 f2                    	cmovbl	%edx, %esi
100004b7a: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100004b7e: 41 89 76 24                 	movl	%esi, 36(%r14)
100004b82: 44 39 c9                    	cmpl	%r9d, %ecx
100004b85: 89 ce                       	movl	%ecx, %esi
100004b87: 41 0f 42 f1                 	cmovbl	%r9d, %esi
100004b8b: 41 0f 43 c9                 	cmovael	%r9d, %ecx
100004b8f: 41 39 c5                    	cmpl	%eax, %r13d
100004b92: 44 89 eb                    	movl	%r13d, %ebx
100004b95: 0f 42 d8                    	cmovbl	%eax, %ebx
100004b98: 41 0f 42 c5                 	cmovbl	%r13d, %eax
100004b9c: 44 39 d1                    	cmpl	%r10d, %ecx
100004b9f: 89 cf                       	movl	%ecx, %edi
100004ba1: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004ba5: 41 0f 43 ca                 	cmovael	%r10d, %ecx
100004ba9: 41 89 4e 0c                 	movl	%ecx, 12(%r14)
100004bad: 41 89 7e 10                 	movl	%edi, 16(%r14)
100004bb1: e9 38 02 00 00              	jmp	568 <_quick_sort_recursive+0xbae>
100004bb6: 41 8b 06                    	movl	(%r14), %eax
100004bb9: 45 8b 66 04                 	movl	4(%r14), %r12d
100004bbd: 44 39 e0                    	cmpl	%r12d, %eax
100004bc0: 41 89 c1                    	movl	%eax, %r9d
100004bc3: 45 0f 42 cc                 	cmovbl	%r12d, %r9d
100004bc7: 44 0f 42 e0                 	cmovbl	%eax, %r12d
100004bcb: 41 8b 46 08                 	movl	8(%r14), %eax
100004bcf: 41 8b 4e 0c                 	movl	12(%r14), %ecx
100004bd3: 39 c8                       	cmpl	%ecx, %eax
100004bd5: 41 89 c0                    	movl	%eax, %r8d
100004bd8: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100004bdc: 0f 42 c8                    	cmovbl	%eax, %ecx
100004bdf: 89 4d d0                    	movl	%ecx, -48(%rbp)
100004be2: 41 8b 46 10                 	movl	16(%r14), %eax
100004be6: 45 8b 5e 14                 	movl	20(%r14), %r11d
100004bea: 44 39 d8                    	cmpl	%r11d, %eax
100004bed: 89 c2                       	movl	%eax, %edx
100004bef: 41 0f 42 d3                 	cmovbl	%r11d, %edx
100004bf3: 44 0f 42 d8                 	cmovbl	%eax, %r11d
100004bf7: 41 8b 5e 18                 	movl	24(%r14), %ebx
100004bfb: 41 8b 46 1c                 	movl	28(%r14), %eax
100004bff: 39 c3                       	cmpl	%eax, %ebx
100004c01: 89 d9                       	movl	%ebx, %ecx
100004c03: 0f 42 c8                    	cmovbl	%eax, %ecx
100004c06: 0f 42 c3                    	cmovbl	%ebx, %eax
100004c09: 41 8b 5e 20                 	movl	32(%r14), %ebx
100004c0d: 45 8b 7e 24                 	movl	36(%r14), %r15d
100004c11: 44 39 fb                    	cmpl	%r15d, %ebx
100004c14: 89 de                       	movl	%ebx, %esi
100004c16: 41 0f 42 f7                 	cmovbl	%r15d, %esi
100004c1a: 44 0f 42 fb                 	cmovbl	%ebx, %r15d
100004c1e: 45 8b 56 28                 	movl	40(%r14), %r10d
100004c22: 45 8b 6e 2c                 	movl	44(%r14), %r13d
100004c26: 45 39 ea                    	cmpl	%r13d, %r10d
100004c29: 44 89 d3                    	movl	%r10d, %ebx
100004c2c: 41 0f 42 dd                 	cmovbl	%r13d, %ebx
100004c30: 45 0f 42 ea                 	cmovbl	%r10d, %r13d
100004c34: 45 39 c1                    	cmpl	%r8d, %r9d
100004c37: 44 89 cf                    	movl	%r9d, %edi
100004c3a: 41 0f 42 f8                 	cmovbl	%r8d, %edi
100004c3e: 89 7d d4                    	movl	%edi, -44(%rbp)
100004c41: 45 0f 42 c1                 	cmovbl	%r9d, %r8d
100004c45: 39 ca                       	cmpl	%ecx, %edx
100004c47: 41 89 d2                    	movl	%edx, %r10d
100004c4a: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
100004c4e: 0f 42 ca                    	cmovbl	%edx, %ecx
100004c51: 39 de                       	cmpl	%ebx, %esi
100004c53: 89 f2                       	movl	%esi, %edx
100004c55: 0f 42 d3                    	cmovbl	%ebx, %edx
100004c58: 0f 42 de                    	cmovbl	%esi, %ebx
100004c5b: 8b 75 d0                    	movl	-48(%rbp), %esi
100004c5e: 41 39 f4                    	cmpl	%esi, %r12d
100004c61: 45 89 e1                    	movl	%r12d, %r9d
100004c64: 44 0f 42 ce                 	cmovbl	%esi, %r9d
100004c68: 41 0f 42 f4                 	cmovbl	%r12d, %esi
100004c6c: 41 89 f4                    	movl	%esi, %r12d
100004c6f: 41 39 c3                    	cmpl	%eax, %r11d
100004c72: 44 89 de                    	movl	%r11d, %esi
100004c75: 0f 42 f0                    	cmovbl	%eax, %esi
100004c78: 41 0f 42 c3                 	cmovbl	%r11d, %eax
100004c7c: 45 39 ef                    	cmpl	%r13d, %r15d
100004c7f: 44 89 ff                    	movl	%r15d, %edi
100004c82: 41 0f 42 fd                 	cmovbl	%r13d, %edi
100004c86: 45 0f 42 ef                 	cmovbl	%r15d, %r13d
100004c8a: 45 39 c8                    	cmpl	%r9d, %r8d
100004c8d: 45 89 c7                    	movl	%r8d, %r15d
100004c90: 45 0f 42 f9                 	cmovbl	%r9d, %r15d
100004c94: 45 0f 42 c8                 	cmovbl	%r8d, %r9d
100004c98: 39 f1                       	cmpl	%esi, %ecx
100004c9a: 41 89 c8                    	movl	%ecx, %r8d
100004c9d: 44 0f 42 c6                 	cmovbl	%esi, %r8d
100004ca1: 0f 42 f1                    	cmovbl	%ecx, %esi
100004ca4: 39 fb                       	cmpl	%edi, %ebx
100004ca6: 41 89 db                    	movl	%ebx, %r11d
100004ca9: 44 0f 42 df                 	cmovbl	%edi, %r11d
100004cad: 0f 42 fb                    	cmovbl	%ebx, %edi
100004cb0: 41 39 f1                    	cmpl	%esi, %r9d
100004cb3: 44 89 cb                    	movl	%r9d, %ebx
100004cb6: 0f 42 de                    	cmovbl	%esi, %ebx
100004cb9: 41 0f 42 f1                 	cmovbl	%r9d, %esi
100004cbd: 45 39 d8                    	cmpl	%r11d, %r8d
100004cc0: 44 89 c1                    	movl	%r8d, %ecx
100004cc3: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
100004cc7: 45 0f 42 d8                 	cmovbl	%r8d, %r11d
100004ccb: 39 fb                       	cmpl	%edi, %ebx
100004ccd: 41 89 d9                    	movl	%ebx, %r9d
100004cd0: 44 0f 42 cf                 	cmovbl	%edi, %r9d
100004cd4: 0f 43 df                    	cmovael	%edi, %ebx
100004cd7: 45 39 df                    	cmpl	%r11d, %r15d
100004cda: 45 89 f8                    	movl	%r15d, %r8d
100004cdd: 45 0f 42 c3                 	cmovbl	%r11d, %r8d
100004ce1: 45 0f 42 df                 	cmovbl	%r15d, %r11d
100004ce5: 39 de                       	cmpl	%ebx, %esi
100004ce7: 89 f7                       	movl	%esi, %edi
100004ce9: 0f 42 fb                    	cmovbl	%ebx, %edi
100004cec: 89 7d d0                    	movl	%edi, -48(%rbp)
100004cef: 0f 42 de                    	cmovbl	%esi, %ebx
100004cf2: 41 39 c8                    	cmpl	%ecx, %r8d
100004cf5: 45 89 c7                    	movl	%r8d, %r15d
100004cf8: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
100004cfc: 44 0f 43 c1                 	cmovael	%ecx, %r8d
100004d00: 41 39 c4                    	cmpl	%eax, %r12d
100004d03: 44 89 e7                    	movl	%r12d, %edi
100004d06: 0f 42 f8                    	cmovbl	%eax, %edi
100004d09: 41 0f 42 c4                 	cmovbl	%r12d, %eax
100004d0d: 41 39 d2                    	cmpl	%edx, %r10d
100004d10: 45 89 d4                    	movl	%r10d, %r12d
100004d13: 44 0f 42 e2                 	cmovbl	%edx, %r12d
100004d17: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100004d1b: 8b 4d d4                    	movl	-44(%rbp), %ecx
100004d1e: 39 d1                       	cmpl	%edx, %ecx
100004d20: 41 89 ca                    	movl	%ecx, %r10d
100004d23: 44 0f 42 d2                 	cmovbl	%edx, %r10d
100004d27: 0f 42 d1                    	cmovbl	%ecx, %edx
100004d2a: 44 39 ef                    	cmpl	%r13d, %edi
100004d2d: 89 fe                       	movl	%edi, %esi
100004d2f: 41 0f 42 f5                 	cmovbl	%r13d, %esi
100004d33: 41 0f 43 fd                 	cmovael	%r13d, %edi
100004d37: 39 f8                       	cmpl	%edi, %eax
100004d39: 89 c1                       	movl	%eax, %ecx
100004d3b: 0f 42 cf                    	cmovbl	%edi, %ecx
100004d3e: 0f 42 f8                    	cmovbl	%eax, %edi
100004d41: 41 89 3e                    	movl	%edi, (%r14)
100004d44: 45 39 e2                    	cmpl	%r12d, %r10d
100004d47: 44 89 d0                    	movl	%r10d, %eax
100004d4a: 41 0f 42 c4                 	cmovbl	%r12d, %eax
100004d4e: 45 0f 43 d4                 	cmovael	%r12d, %r10d
100004d52: 41 89 46 2c                 	movl	%eax, 44(%r14)
100004d56: 39 cb                       	cmpl	%ecx, %ebx
100004d58: 41 89 dc                    	movl	%ebx, %r12d
100004d5b: 44 0f 42 e1                 	cmovbl	%ecx, %r12d
100004d5f: 0f 42 cb                    	cmovbl	%ebx, %ecx
100004d62: 41 89 4e 04                 	movl	%ecx, 4(%r14)
100004d66: 45 39 fa                    	cmpl	%r15d, %r10d
100004d69: 44 89 d0                    	movl	%r10d, %eax
100004d6c: 41 0f 42 c7                 	cmovbl	%r15d, %eax
100004d70: 45 0f 43 d7                 	cmovael	%r15d, %r10d
100004d74: 41 89 46 28                 	movl	%eax, 40(%r14)
100004d78: 39 f2                       	cmpl	%esi, %edx
100004d7a: 89 d0                       	movl	%edx, %eax
100004d7c: 0f 42 c6                    	cmovbl	%esi, %eax
100004d7f: 0f 42 f2                    	cmovbl	%edx, %esi
100004d82: 41 39 f3                    	cmpl	%esi, %r11d
100004d85: 44 89 df                    	movl	%r11d, %edi
100004d88: 0f 42 fe                    	cmovbl	%esi, %edi
100004d8b: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100004d8f: 44 39 c8                    	cmpl	%r9d, %eax
100004d92: 89 c2                       	movl	%eax, %edx
100004d94: 41 0f 42 d1                 	cmovbl	%r9d, %edx
100004d98: 41 0f 43 c1                 	cmovael	%r9d, %eax
100004d9c: 44 39 e6                    	cmpl	%r12d, %esi
100004d9f: 41 89 f1                    	movl	%esi, %r9d
100004da2: 45 0f 42 cc                 	cmovbl	%r12d, %r9d
100004da6: 41 0f 43 f4                 	cmovael	%r12d, %esi
100004daa: 41 89 76 08                 	movl	%esi, 8(%r14)
100004dae: 41 39 d2                    	cmpl	%edx, %r10d
100004db1: 44 89 d6                    	movl	%r10d, %esi
100004db4: 0f 42 f2                    	cmovbl	%edx, %esi
100004db7: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100004dbb: 41 89 76 24                 	movl	%esi, 36(%r14)
100004dbf: 8b 4d d0                    	movl	-48(%rbp), %ecx
100004dc2: 39 cf                       	cmpl	%ecx, %edi
100004dc4: 89 fe                       	movl	%edi, %esi
100004dc6: 0f 42 f1                    	cmovbl	%ecx, %esi
100004dc9: 0f 43 f9                    	cmovael	%ecx, %edi
100004dcc: 41 39 c0                    	cmpl	%eax, %r8d
100004dcf: 44 89 c3                    	movl	%r8d, %ebx
100004dd2: 0f 42 d8                    	cmovbl	%eax, %ebx
100004dd5: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100004dd9: 44 39 cf                    	cmpl	%r9d, %edi
100004ddc: 89 f9                       	movl	%edi, %ecx
100004dde: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
100004de2: 41 0f 43 f9                 	cmovael	%r9d, %edi
100004de6: 41 89 7e 0c                 	movl	%edi, 12(%r14)
100004dea: 41 89 4e 10                 	movl	%ecx, 16(%r14)
100004dee: 39 c6                       	cmpl	%eax, %esi
100004df0: 89 f1                       	movl	%esi, %ecx
100004df2: 0f 42 c8                    	cmovbl	%eax, %ecx
100004df5: 0f 42 c6                    	cmovbl	%esi, %eax
100004df8: 41 89 46 14                 	movl	%eax, 20(%r14)
100004dfc: 41 89 4e 18                 	movl	%ecx, 24(%r14)
100004e00: 39 da                       	cmpl	%ebx, %edx
100004e02: 89 d0                       	movl	%edx, %eax
100004e04: 0f 42 c3                    	cmovbl	%ebx, %eax
100004e07: 0f 42 da                    	cmovbl	%edx, %ebx
100004e0a: 41 89 5e 1c                 	movl	%ebx, 28(%r14)
100004e0e: 41 89 46 20                 	movl	%eax, 32(%r14)
100004e12: e9 8f 0d 00 00              	jmp	3471 <_quick_sort_recursive+0x1966>
100004e17: 45 8b 16                    	movl	(%r14), %r10d
100004e1a: 41 8b 46 04                 	movl	4(%r14), %eax
100004e1e: 41 8b 56 1c                 	movl	28(%r14), %edx
100004e22: 39 d0                       	cmpl	%edx, %eax
100004e24: 89 c1                       	movl	%eax, %ecx
100004e26: 0f 42 ca                    	cmovbl	%edx, %ecx
100004e29: 89 4d d4                    	movl	%ecx, -44(%rbp)
100004e2c: 0f 42 d0                    	cmovbl	%eax, %edx
100004e2f: 41 8b 46 24                 	movl	36(%r14), %eax
100004e33: 45 8b 7e 2c                 	movl	44(%r14), %r15d
100004e37: 44 39 f8                    	cmpl	%r15d, %eax
100004e3a: 41 89 c5                    	movl	%eax, %r13d
100004e3d: 45 0f 42 ef                 	cmovbl	%r15d, %r13d
100004e41: 44 0f 42 f8                 	cmovbl	%eax, %r15d
100004e45: 41 8b 4e 0c                 	movl	12(%r14), %ecx
100004e49: 41 8b 46 10                 	movl	16(%r14), %eax
100004e4d: 39 c1                       	cmpl	%eax, %ecx
100004e4f: 89 ce                       	movl	%ecx, %esi
100004e51: 0f 42 f0                    	cmovbl	%eax, %esi
100004e54: 89 75 cc                    	movl	%esi, -52(%rbp)
100004e57: 0f 42 c1                    	cmovbl	%ecx, %eax
100004e5a: 41 8b 7e 14                 	movl	20(%r14), %edi
100004e5e: 45 8b 46 20                 	movl	32(%r14), %r8d
100004e62: 44 39 c7                    	cmpl	%r8d, %edi
100004e65: 89 f9                       	movl	%edi, %ecx
100004e67: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100004e6b: 44 0f 42 c7                 	cmovbl	%edi, %r8d
100004e6f: 41 8b 7e 30                 	movl	48(%r14), %edi
100004e73: 41 39 fa                    	cmpl	%edi, %r10d
100004e76: 44 89 d3                    	movl	%r10d, %ebx
100004e79: 0f 42 df                    	cmovbl	%edi, %ebx
100004e7c: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004e80: 41 8b 76 08                 	movl	8(%r14), %esi
100004e84: 45 8b 4e 18                 	movl	24(%r14), %r9d
100004e88: 44 39 ce                    	cmpl	%r9d, %esi
100004e8b: 41 89 f4                    	movl	%esi, %r12d
100004e8e: 45 0f 42 e1                 	cmovbl	%r9d, %r12d
100004e92: 44 0f 42 ce                 	cmovbl	%esi, %r9d
100004e96: 39 d7                       	cmpl	%edx, %edi
100004e98: 89 fe                       	movl	%edi, %esi
100004e9a: 0f 42 f2                    	cmovbl	%edx, %esi
100004e9d: 89 75 d0                    	movl	%esi, -48(%rbp)
100004ea0: 0f 43 fa                    	cmovael	%edx, %edi
100004ea3: 44 39 e9                    	cmpl	%r13d, %ecx
100004ea6: 41 89 cb                    	movl	%ecx, %r11d
100004ea9: 45 0f 42 dd                 	cmovbl	%r13d, %r11d
100004ead: 41 0f 43 cd                 	cmovael	%r13d, %ecx
100004eb1: 41 39 c1                    	cmpl	%eax, %r9d
100004eb4: 45 89 ca                    	movl	%r9d, %r10d
100004eb7: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100004ebb: 44 0f 43 c8                 	cmovael	%eax, %r9d
100004ebf: 8b 45 cc                    	movl	-52(%rbp), %eax
100004ec2: 44 39 e0                    	cmpl	%r12d, %eax
100004ec5: 41 89 c5                    	movl	%eax, %r13d
100004ec8: 45 0f 42 ec                 	cmovbl	%r12d, %r13d
100004ecc: 44 0f 42 e0                 	cmovbl	%eax, %r12d
100004ed0: 8b 45 d4                    	movl	-44(%rbp), %eax
100004ed3: 39 d8                       	cmpl	%ebx, %eax
100004ed5: 89 c2                       	movl	%eax, %edx
100004ed7: 0f 42 d3                    	cmovbl	%ebx, %edx
100004eda: 0f 42 d8                    	cmovbl	%eax, %ebx
100004edd: 45 39 f8                    	cmpl	%r15d, %r8d
100004ee0: 44 89 c0                    	movl	%r8d, %eax
100004ee3: 41 0f 42 c7                 	cmovbl	%r15d, %eax
100004ee7: 89 45 cc                    	movl	%eax, -52(%rbp)
100004eea: 45 0f 43 c7                 	cmovael	%r15d, %r8d
100004eee: 44 39 cf                    	cmpl	%r9d, %edi
100004ef1: 89 f8                       	movl	%edi, %eax
100004ef3: 41 0f 42 c1                 	cmovbl	%r9d, %eax
100004ef7: 89 45 d4                    	movl	%eax, -44(%rbp)
100004efa: 44 0f 42 cf                 	cmovbl	%edi, %r9d
100004efe: 41 8b 46 28                 	movl	40(%r14), %eax
100004f02: 44 39 d8                    	cmpl	%r11d, %eax
100004f05: 89 c7                       	movl	%eax, %edi
100004f07: 41 0f 42 fb                 	cmovbl	%r11d, %edi
100004f0b: 44 0f 42 d8                 	cmovbl	%eax, %r11d
100004f0f: 41 39 da                    	cmpl	%ebx, %r10d
100004f12: 44 89 d6                    	movl	%r10d, %esi
100004f15: 0f 42 f3                    	cmovbl	%ebx, %esi
100004f18: 41 0f 42 da                 	cmovbl	%r10d, %ebx
100004f1c: 44 8b 55 d0                 	movl	-48(%rbp), %r10d
100004f20: 45 39 e2                    	cmpl	%r12d, %r10d
100004f23: 44 89 d0                    	movl	%r10d, %eax
100004f26: 41 0f 42 c4                 	cmovbl	%r12d, %eax
100004f2a: 45 0f 42 e2                 	cmovbl	%r10d, %r12d
100004f2e: 41 39 d5                    	cmpl	%edx, %r13d
100004f31: 45 89 ef                    	movl	%r13d, %r15d
100004f34: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100004f38: 41 0f 42 d5                 	cmovbl	%r13d, %edx
100004f3c: 39 ce                       	cmpl	%ecx, %esi
100004f3e: 41 89 f2                    	movl	%esi, %r10d
100004f41: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
100004f45: 0f 43 f1                    	cmovael	%ecx, %esi
100004f48: 44 39 ff                    	cmpl	%r15d, %edi
100004f4b: 89 f9                       	movl	%edi, %ecx
100004f4d: 41 0f 42 cf                 	cmovbl	%r15d, %ecx
100004f51: 44 0f 42 ff                 	cmovbl	%edi, %r15d
100004f55: 41 89 4e 30                 	movl	%ecx, 48(%r14)
100004f59: 8b 4d cc                    	movl	-52(%rbp), %ecx
100004f5c: 39 c8                       	cmpl	%ecx, %eax
100004f5e: 89 c7                       	movl	%eax, %edi
100004f60: 0f 42 f9                    	cmovbl	%ecx, %edi
100004f63: 0f 43 c1                    	cmovael	%ecx, %eax
100004f66: 44 39 da                    	cmpl	%r11d, %edx
100004f69: 89 d1                       	movl	%edx, %ecx
100004f6b: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
100004f6f: 41 0f 43 d3                 	cmovael	%r11d, %edx
100004f73: 39 c3                       	cmpl	%eax, %ebx
100004f75: 41 89 db                    	movl	%ebx, %r11d
100004f78: 44 0f 42 d8                 	cmovbl	%eax, %r11d
100004f7c: 0f 42 c3                    	cmovbl	%ebx, %eax
100004f7f: 41 39 d0                    	cmpl	%edx, %r8d
100004f82: 45 89 c5                    	movl	%r8d, %r13d
100004f85: 44 0f 42 ea                 	cmovbl	%edx, %r13d
100004f89: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100004f8d: 41 39 fa                    	cmpl	%edi, %r10d
100004f90: 44 89 d3                    	movl	%r10d, %ebx
100004f93: 0f 42 df                    	cmovbl	%edi, %ebx
100004f96: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100004f9a: 44 39 f9                    	cmpl	%r15d, %ecx
100004f9d: 41 89 c8                    	movl	%ecx, %r8d
100004fa0: 45 0f 42 c7                 	cmovbl	%r15d, %r8d
100004fa4: 41 0f 43 cf                 	cmovael	%r15d, %ecx
100004fa8: 41 39 f4                    	cmpl	%esi, %r12d
100004fab: 45 89 e7                    	movl	%r12d, %r15d
100004fae: 44 0f 42 fe                 	cmovbl	%esi, %r15d
100004fb2: 41 0f 42 f4                 	cmovbl	%r12d, %esi
100004fb6: 44 39 c3                    	cmpl	%r8d, %ebx
100004fb9: 41 89 da                    	movl	%ebx, %r10d
100004fbc: 45 0f 42 d0                 	cmovbl	%r8d, %r10d
100004fc0: 44 0f 42 c3                 	cmovbl	%ebx, %r8d
100004fc4: 45 89 56 2c                 	movl	%r10d, 44(%r14)
100004fc8: 8b 5d d4                    	movl	-44(%rbp), %ebx
100004fcb: 44 39 eb                    	cmpl	%r13d, %ebx
100004fce: 41 89 dc                    	movl	%ebx, %r12d
100004fd1: 45 0f 42 e5                 	cmovbl	%r13d, %r12d
100004fd5: 44 0f 42 eb                 	cmovbl	%ebx, %r13d
100004fd9: 39 cf                       	cmpl	%ecx, %edi
100004fdb: 89 fb                       	movl	%edi, %ebx
100004fdd: 0f 42 d9                    	cmovbl	%ecx, %ebx
100004fe0: 0f 42 cf                    	cmovbl	%edi, %ecx
100004fe3: 39 c6                       	cmpl	%eax, %esi
100004fe5: 41 89 f2                    	movl	%esi, %r10d
100004fe8: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100004fec: 0f 43 f0                    	cmovael	%eax, %esi
100004fef: 45 39 fb                    	cmpl	%r15d, %r11d
100004ff2: 44 89 df                    	movl	%r11d, %edi
100004ff5: 41 0f 42 ff                 	cmovbl	%r15d, %edi
100004ff9: 45 0f 42 fb                 	cmovbl	%r11d, %r15d
100004ffd: 41 39 d8                    	cmpl	%ebx, %r8d
100005000: 44 89 c0                    	movl	%r8d, %eax
100005003: 0f 42 c3                    	cmovbl	%ebx, %eax
100005006: 41 0f 42 d8                 	cmovbl	%r8d, %ebx
10000500a: 41 89 46 28                 	movl	%eax, 40(%r14)
10000500e: 41 39 d1                    	cmpl	%edx, %r9d
100005011: 44 89 c8                    	movl	%r9d, %eax
100005014: 0f 42 c2                    	cmovbl	%edx, %eax
100005017: 41 0f 42 d1                 	cmovbl	%r9d, %edx
10000501b: 41 89 16                    	movl	%edx, (%r14)
10000501e: 41 39 cc                    	cmpl	%ecx, %r12d
100005021: 45 89 e0                    	movl	%r12d, %r8d
100005024: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100005028: 41 0f 42 cc                 	cmovbl	%r12d, %ecx
10000502c: 41 39 c5                    	cmpl	%eax, %r13d
10000502f: 44 89 ea                    	movl	%r13d, %edx
100005032: 0f 42 d0                    	cmovbl	%eax, %edx
100005035: 41 0f 42 c5                 	cmovbl	%r13d, %eax
100005039: 44 39 c7                    	cmpl	%r8d, %edi
10000503c: 41 89 f9                    	movl	%edi, %r9d
10000503f: 45 0f 42 c8                 	cmovbl	%r8d, %r9d
100005043: 44 0f 42 c7                 	cmovbl	%edi, %r8d
100005047: 39 c6                       	cmpl	%eax, %esi
100005049: 41 89 f3                    	movl	%esi, %r11d
10000504c: 44 0f 42 d8                 	cmovbl	%eax, %r11d
100005050: 0f 42 c6                    	cmovbl	%esi, %eax
100005053: 41 89 46 04                 	movl	%eax, 4(%r14)
100005057: 41 39 d2                    	cmpl	%edx, %r10d
10000505a: 44 89 d0                    	movl	%r10d, %eax
10000505d: 0f 42 c2                    	cmovbl	%edx, %eax
100005060: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100005064: 41 39 d9                    	cmpl	%ebx, %r9d
100005067: 44 89 ce                    	movl	%r9d, %esi
10000506a: 0f 42 f3                    	cmovbl	%ebx, %esi
10000506d: 44 0f 43 cb                 	cmovael	%ebx, %r9d
100005071: 45 89 4e 20                 	movl	%r9d, 32(%r14)
100005075: 41 89 76 24                 	movl	%esi, 36(%r14)
100005079: 41 39 cf                    	cmpl	%ecx, %r15d
10000507c: 44 89 fe                    	movl	%r15d, %esi
10000507f: 0f 42 f1                    	cmovbl	%ecx, %esi
100005082: 41 0f 42 cf                 	cmovbl	%r15d, %ecx
100005086: 41 39 d3                    	cmpl	%edx, %r11d
100005089: 44 89 df                    	movl	%r11d, %edi
10000508c: 0f 42 fa                    	cmovbl	%edx, %edi
10000508f: 41 0f 42 d3                 	cmovbl	%r11d, %edx
100005093: 41 89 56 08                 	movl	%edx, 8(%r14)
100005097: 39 c1                       	cmpl	%eax, %ecx
100005099: 89 ca                       	movl	%ecx, %edx
10000509b: 0f 42 d0                    	cmovbl	%eax, %edx
10000509e: 0f 43 c8                    	cmovael	%eax, %ecx
1000050a1: 44 39 c6                    	cmpl	%r8d, %esi
1000050a4: 89 f0                       	movl	%esi, %eax
1000050a6: 41 0f 42 c0                 	cmovbl	%r8d, %eax
1000050aa: 41 0f 43 f0                 	cmovael	%r8d, %esi
1000050ae: 41 89 46 1c                 	movl	%eax, 28(%r14)
1000050b2: 39 cf                       	cmpl	%ecx, %edi
1000050b4: 89 f8                       	movl	%edi, %eax
1000050b6: 0f 42 c1                    	cmovbl	%ecx, %eax
1000050b9: 0f 42 cf                    	cmovbl	%edi, %ecx
1000050bc: 41 89 4e 0c                 	movl	%ecx, 12(%r14)
1000050c0: 41 89 46 10                 	movl	%eax, 16(%r14)
1000050c4: 39 f2                       	cmpl	%esi, %edx
1000050c6: 89 d0                       	movl	%edx, %eax
1000050c8: 0f 42 c6                    	cmovbl	%esi, %eax
1000050cb: 0f 42 f2                    	cmovbl	%edx, %esi
1000050ce: 41 89 76 14                 	movl	%esi, 20(%r14)
1000050d2: 41 89 46 18                 	movl	%eax, 24(%r14)
1000050d6: e9 cb 0a 00 00              	jmp	2763 <_quick_sort_recursive+0x1966>
1000050db: 41 8b 06                    	movl	(%r14), %eax
1000050de: 45 8b 46 04                 	movl	4(%r14), %r8d
1000050e2: 44 39 c0                    	cmpl	%r8d, %eax
1000050e5: 89 c1                       	movl	%eax, %ecx
1000050e7: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
1000050eb: 89 4d d4                    	movl	%ecx, -44(%rbp)
1000050ee: 44 0f 42 c0                 	cmovbl	%eax, %r8d
1000050f2: 41 8b 46 08                 	movl	8(%r14), %eax
1000050f6: 41 8b 56 0c                 	movl	12(%r14), %edx
1000050fa: 39 d0                       	cmpl	%edx, %eax
1000050fc: 41 89 c7                    	movl	%eax, %r15d
1000050ff: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100005103: 0f 42 d0                    	cmovbl	%eax, %edx
100005106: 41 8b 46 10                 	movl	16(%r14), %eax
10000510a: 45 8b 4e 14                 	movl	20(%r14), %r9d
10000510e: 44 39 c8                    	cmpl	%r9d, %eax
100005111: 89 c1                       	movl	%eax, %ecx
100005113: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
100005117: 89 4d cc                    	movl	%ecx, -52(%rbp)
10000511a: 44 0f 42 c8                 	cmovbl	%eax, %r9d
10000511e: 41 8b 46 18                 	movl	24(%r14), %eax
100005122: 41 8b 76 1c                 	movl	28(%r14), %esi
100005126: 39 f0                       	cmpl	%esi, %eax
100005128: 41 89 c2                    	movl	%eax, %r10d
10000512b: 44 0f 42 d6                 	cmovbl	%esi, %r10d
10000512f: 0f 42 f0                    	cmovbl	%eax, %esi
100005132: 41 8b 7e 20                 	movl	32(%r14), %edi
100005136: 41 8b 4e 24                 	movl	36(%r14), %ecx
10000513a: 39 cf                       	cmpl	%ecx, %edi
10000513c: 41 89 fd                    	movl	%edi, %r13d
10000513f: 44 0f 42 e9                 	cmovbl	%ecx, %r13d
100005143: 0f 42 cf                    	cmovbl	%edi, %ecx
100005146: 41 8b 46 28                 	movl	40(%r14), %eax
10000514a: 41 8b 5e 2c                 	movl	44(%r14), %ebx
10000514e: 39 d8                       	cmpl	%ebx, %eax
100005150: 41 89 c3                    	movl	%eax, %r11d
100005153: 44 0f 42 db                 	cmovbl	%ebx, %r11d
100005157: 0f 42 d8                    	cmovbl	%eax, %ebx
10000515a: 45 8b 66 30                 	movl	48(%r14), %r12d
10000515e: 41 8b 7e 34                 	movl	52(%r14), %edi
100005162: 41 39 fc                    	cmpl	%edi, %r12d
100005165: 44 89 e0                    	movl	%r12d, %eax
100005168: 0f 42 c7                    	cmovbl	%edi, %eax
10000516b: 89 45 c4                    	movl	%eax, -60(%rbp)
10000516e: 41 0f 42 fc                 	cmovbl	%r12d, %edi
100005172: 41 39 d0                    	cmpl	%edx, %r8d
100005175: 44 89 c0                    	movl	%r8d, %eax
100005178: 0f 42 c2                    	cmovbl	%edx, %eax
10000517b: 89 45 bc                    	movl	%eax, -68(%rbp)
10000517e: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100005182: 41 39 f1                    	cmpl	%esi, %r9d
100005185: 45 89 c8                    	movl	%r9d, %r8d
100005188: 44 0f 42 c6                 	cmovbl	%esi, %r8d
10000518c: 41 0f 42 f1                 	cmovbl	%r9d, %esi
100005190: 39 d9                       	cmpl	%ebx, %ecx
100005192: 89 c8                       	movl	%ecx, %eax
100005194: 0f 42 c3                    	cmovbl	%ebx, %eax
100005197: 89 45 d0                    	movl	%eax, -48(%rbp)
10000519a: 0f 42 d9                    	cmovbl	%ecx, %ebx
10000519d: 8b 4d d4                    	movl	-44(%rbp), %ecx
1000051a0: 44 39 f9                    	cmpl	%r15d, %ecx
1000051a3: 41 89 cc                    	movl	%ecx, %r12d
1000051a6: 45 0f 42 e7                 	cmovbl	%r15d, %r12d
1000051aa: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
1000051ae: 8b 4d cc                    	movl	-52(%rbp), %ecx
1000051b1: 44 39 d1                    	cmpl	%r10d, %ecx
1000051b4: 41 89 c9                    	movl	%ecx, %r9d
1000051b7: 45 0f 42 ca                 	cmovbl	%r10d, %r9d
1000051bb: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
1000051bf: 45 39 dd                    	cmpl	%r11d, %r13d
1000051c2: 44 89 e8                    	movl	%r13d, %eax
1000051c5: 41 0f 42 c3                 	cmovbl	%r11d, %eax
1000051c9: 89 45 d4                    	movl	%eax, -44(%rbp)
1000051cc: 45 0f 42 dd                 	cmovbl	%r13d, %r11d
1000051d0: 39 f2                       	cmpl	%esi, %edx
1000051d2: 41 89 d5                    	movl	%edx, %r13d
1000051d5: 44 0f 42 ee                 	cmovbl	%esi, %r13d
1000051d9: 0f 42 f2                    	cmovbl	%edx, %esi
1000051dc: 39 fb                       	cmpl	%edi, %ebx
1000051de: 89 da                       	movl	%ebx, %edx
1000051e0: 0f 42 d7                    	cmovbl	%edi, %edx
1000051e3: 0f 43 df                    	cmovael	%edi, %ebx
1000051e6: 45 39 d7                    	cmpl	%r10d, %r15d
1000051e9: 44 89 f8                    	movl	%r15d, %eax
1000051ec: 41 0f 42 c2                 	cmovbl	%r10d, %eax
1000051f0: 89 45 c8                    	movl	%eax, -56(%rbp)
1000051f3: 45 0f 42 d7                 	cmovbl	%r15d, %r10d
1000051f7: 8b 45 c4                    	movl	-60(%rbp), %eax
1000051fa: 41 39 c3                    	cmpl	%eax, %r11d
1000051fd: 44 89 d9                    	movl	%r11d, %ecx
100005200: 0f 42 c8                    	cmovbl	%eax, %ecx
100005203: 44 0f 43 d8                 	cmovael	%eax, %r11d
100005207: 8b 45 bc                    	movl	-68(%rbp), %eax
10000520a: 44 39 c0                    	cmpl	%r8d, %eax
10000520d: 41 89 c7                    	movl	%eax, %r15d
100005210: 45 0f 42 f8                 	cmovbl	%r8d, %r15d
100005214: 44 0f 42 c0                 	cmovbl	%eax, %r8d
100005218: 45 39 cc                    	cmpl	%r9d, %r12d
10000521b: 44 89 e0                    	movl	%r12d, %eax
10000521e: 41 0f 42 c1                 	cmovbl	%r9d, %eax
100005222: 89 45 cc                    	movl	%eax, -52(%rbp)
100005225: 45 0f 42 cc                 	cmovbl	%r12d, %r9d
100005229: 39 de                       	cmpl	%ebx, %esi
10000522b: 41 89 f4                    	movl	%esi, %r12d
10000522e: 44 0f 42 e3                 	cmovbl	%ebx, %r12d
100005232: 0f 42 de                    	cmovbl	%esi, %ebx
100005235: 41 89 1e                    	movl	%ebx, (%r14)
100005238: 45 39 da                    	cmpl	%r11d, %r10d
10000523b: 44 89 d6                    	movl	%r10d, %esi
10000523e: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100005242: 45 0f 42 da                 	cmovbl	%r10d, %r11d
100005246: 8b 45 d0                    	movl	-48(%rbp), %eax
100005249: 41 39 c0                    	cmpl	%eax, %r8d
10000524c: 45 89 c2                    	movl	%r8d, %r10d
10000524f: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100005253: 44 0f 43 c0                 	cmovael	%eax, %r8d
100005257: 8b 5d d4                    	movl	-44(%rbp), %ebx
10000525a: 41 39 d9                    	cmpl	%ebx, %r9d
10000525d: 44 89 c8                    	movl	%r9d, %eax
100005260: 0f 42 c3                    	cmovbl	%ebx, %eax
100005263: 44 0f 43 cb                 	cmovael	%ebx, %r9d
100005267: 45 39 c3                    	cmpl	%r8d, %r11d
10000526a: 44 89 df                    	movl	%r11d, %edi
10000526d: 41 0f 42 f8                 	cmovbl	%r8d, %edi
100005271: 89 7d d0                    	movl	%edi, -48(%rbp)
100005274: 45 0f 42 c3                 	cmovbl	%r11d, %r8d
100005278: 41 39 d5                    	cmpl	%edx, %r13d
10000527b: 44 89 eb                    	movl	%r13d, %ebx
10000527e: 0f 42 da                    	cmovbl	%edx, %ebx
100005281: 41 0f 42 d5                 	cmovbl	%r13d, %edx
100005285: 8b 7d c8                    	movl	-56(%rbp), %edi
100005288: 39 cf                       	cmpl	%ecx, %edi
10000528a: 41 89 fd                    	movl	%edi, %r13d
10000528d: 44 0f 42 e9                 	cmovbl	%ecx, %r13d
100005291: 0f 42 cf                    	cmovbl	%edi, %ecx
100005294: 44 39 d1                    	cmpl	%r10d, %ecx
100005297: 89 cf                       	movl	%ecx, %edi
100005299: 41 0f 42 fa                 	cmovbl	%r10d, %edi
10000529d: 89 7d c8                    	movl	%edi, -56(%rbp)
1000052a0: 41 0f 43 ca                 	cmovael	%r10d, %ecx
1000052a4: 41 39 f7                    	cmpl	%esi, %r15d
1000052a7: 45 89 fb                    	movl	%r15d, %r11d
1000052aa: 44 0f 42 de                 	cmovbl	%esi, %r11d
1000052ae: 41 0f 42 f7                 	cmovbl	%r15d, %esi
1000052b2: 41 39 d9                    	cmpl	%ebx, %r9d
1000052b5: 44 89 cf                    	movl	%r9d, %edi
1000052b8: 0f 42 fb                    	cmovbl	%ebx, %edi
1000052bb: 89 7d d4                    	movl	%edi, -44(%rbp)
1000052be: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
1000052c2: 44 8b 55 cc                 	movl	-52(%rbp), %r10d
1000052c6: 41 39 c2                    	cmpl	%eax, %r10d
1000052c9: 45 89 d1                    	movl	%r10d, %r9d
1000052cc: 44 0f 42 c8                 	cmovbl	%eax, %r9d
1000052d0: 41 0f 42 c2                 	cmovbl	%r10d, %eax
1000052d4: 44 39 e2                    	cmpl	%r12d, %edx
1000052d7: 41 89 d7                    	movl	%edx, %r15d
1000052da: 45 0f 42 fc                 	cmovbl	%r12d, %r15d
1000052de: 41 0f 43 d4                 	cmovael	%r12d, %edx
1000052e2: 41 39 d0                    	cmpl	%edx, %r8d
1000052e5: 45 89 c4                    	movl	%r8d, %r12d
1000052e8: 44 0f 42 e2                 	cmovbl	%edx, %r12d
1000052ec: 41 0f 42 d0                 	cmovbl	%r8d, %edx
1000052f0: 41 89 56 04                 	movl	%edx, 4(%r14)
1000052f4: 44 39 e8                    	cmpl	%r13d, %eax
1000052f7: 41 89 c2                    	movl	%eax, %r10d
1000052fa: 45 0f 42 d5                 	cmovbl	%r13d, %r10d
1000052fe: 41 0f 43 c5                 	cmovael	%r13d, %eax
100005302: 8b 7d d0                    	movl	-48(%rbp), %edi
100005305: 44 39 ff                    	cmpl	%r15d, %edi
100005308: 89 fa                       	movl	%edi, %edx
10000530a: 41 0f 42 d7                 	cmovbl	%r15d, %edx
10000530e: 44 0f 42 ff                 	cmovbl	%edi, %r15d
100005312: 44 89 df                    	movl	%r11d, %edi
100005315: 44 8b 45 c8                 	movl	-56(%rbp), %r8d
100005319: 45 39 c3                    	cmpl	%r8d, %r11d
10000531c: 45 0f 42 d8                 	cmovbl	%r8d, %r11d
100005320: 41 0f 43 f8                 	cmovael	%r8d, %edi
100005324: 89 7d d0                    	movl	%edi, -48(%rbp)
100005327: 45 39 d1                    	cmpl	%r10d, %r9d
10000532a: 44 89 cf                    	movl	%r9d, %edi
10000532d: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100005331: 45 0f 42 d1                 	cmovbl	%r9d, %r10d
100005335: 41 89 7e 34                 	movl	%edi, 52(%r14)
100005339: 45 39 e7                    	cmpl	%r12d, %r15d
10000533c: 45 89 fd                    	movl	%r15d, %r13d
10000533f: 45 0f 42 ec                 	cmovbl	%r12d, %r13d
100005343: 45 0f 43 fc                 	cmovael	%r12d, %r15d
100005347: 45 89 7e 08                 	movl	%r15d, 8(%r14)
10000534b: 39 f1                       	cmpl	%esi, %ecx
10000534d: 41 89 c9                    	movl	%ecx, %r9d
100005350: 44 0f 42 ce                 	cmovbl	%esi, %r9d
100005354: 0f 42 f1                    	cmovbl	%ecx, %esi
100005357: 39 d3                       	cmpl	%edx, %ebx
100005359: 89 df                       	movl	%ebx, %edi
10000535b: 0f 42 fa                    	cmovbl	%edx, %edi
10000535e: 0f 42 d3                    	cmovbl	%ebx, %edx
100005361: 8b 5d d4                    	movl	-44(%rbp), %ebx
100005364: 39 d8                       	cmpl	%ebx, %eax
100005366: 41 89 c4                    	movl	%eax, %r12d
100005369: 44 0f 42 e3                 	cmovbl	%ebx, %r12d
10000536d: 0f 43 c3                    	cmovael	%ebx, %eax
100005370: 39 f2                       	cmpl	%esi, %edx
100005372: 41 89 d0                    	movl	%edx, %r8d
100005375: 44 0f 42 c6                 	cmovbl	%esi, %r8d
100005379: 0f 43 d6                    	cmovael	%esi, %edx
10000537c: 41 39 f9                    	cmpl	%edi, %r9d
10000537f: 45 89 cf                    	movl	%r9d, %r15d
100005382: 44 0f 42 ff                 	cmovbl	%edi, %r15d
100005386: 41 0f 42 f9                 	cmovbl	%r9d, %edi
10000538a: 45 39 e3                    	cmpl	%r12d, %r11d
10000538d: 44 89 de                    	movl	%r11d, %esi
100005390: 41 0f 42 f4                 	cmovbl	%r12d, %esi
100005394: 45 0f 42 e3                 	cmovbl	%r11d, %r12d
100005398: 44 39 ea                    	cmpl	%r13d, %edx
10000539b: 89 d3                       	movl	%edx, %ebx
10000539d: 41 0f 42 dd                 	cmovbl	%r13d, %ebx
1000053a1: 41 0f 43 d5                 	cmovael	%r13d, %edx
1000053a5: 41 89 56 0c                 	movl	%edx, 12(%r14)
1000053a9: 41 89 5e 10                 	movl	%ebx, 16(%r14)
1000053ad: 8b 4d d0                    	movl	-48(%rbp), %ecx
1000053b0: 39 c8                       	cmpl	%ecx, %eax
1000053b2: 89 c2                       	movl	%eax, %edx
1000053b4: 0f 42 d1                    	cmovbl	%ecx, %edx
1000053b7: 0f 43 c1                    	cmovael	%ecx, %eax
1000053ba: 41 39 f8                    	cmpl	%edi, %r8d
1000053bd: 44 89 c3                    	movl	%r8d, %ebx
1000053c0: 0f 42 df                    	cmovbl	%edi, %ebx
1000053c3: 41 0f 42 f8                 	cmovbl	%r8d, %edi
1000053c7: 41 89 7e 14                 	movl	%edi, 20(%r14)
1000053cb: 41 39 f2                    	cmpl	%esi, %r10d
1000053ce: 44 89 d7                    	movl	%r10d, %edi
1000053d1: 0f 42 fe                    	cmovbl	%esi, %edi
1000053d4: 41 0f 42 f2                 	cmovbl	%r10d, %esi
1000053d8: 41 89 76 2c                 	movl	%esi, 44(%r14)
1000053dc: 41 89 7e 30                 	movl	%edi, 48(%r14)
1000053e0: 44 39 f8                    	cmpl	%r15d, %eax
1000053e3: 89 c1                       	movl	%eax, %ecx
1000053e5: 41 0f 42 cf                 	cmovbl	%r15d, %ecx
1000053e9: 41 0f 43 c7                 	cmovael	%r15d, %eax
1000053ed: 44 39 e2                    	cmpl	%r12d, %edx
1000053f0: 89 d6                       	movl	%edx, %esi
1000053f2: 41 0f 42 f4                 	cmovbl	%r12d, %esi
1000053f6: 41 0f 43 d4                 	cmovael	%r12d, %edx
1000053fa: 41 89 76 28                 	movl	%esi, 40(%r14)
1000053fe: 39 c3                       	cmpl	%eax, %ebx
100005400: 89 de                       	movl	%ebx, %esi
100005402: 0f 42 f0                    	cmovbl	%eax, %esi
100005405: 0f 42 c3                    	cmovbl	%ebx, %eax
100005408: 41 89 46 18                 	movl	%eax, 24(%r14)
10000540c: 41 89 76 1c                 	movl	%esi, 28(%r14)
100005410: e9 7f 07 00 00              	jmp	1919 <_quick_sort_recursive+0x1954>
100005415: 41 8b 06                    	movl	(%r14), %eax
100005418: 45 8b 5e 04                 	movl	4(%r14), %r11d
10000541c: 44 39 d8                    	cmpl	%r11d, %eax
10000541f: 89 c1                       	movl	%eax, %ecx
100005421: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
100005425: 89 4d d4                    	movl	%ecx, -44(%rbp)
100005428: 44 0f 42 d8                 	cmovbl	%eax, %r11d
10000542c: 41 8b 46 08                 	movl	8(%r14), %eax
100005430: 45 8b 56 0c                 	movl	12(%r14), %r10d
100005434: 44 39 d0                    	cmpl	%r10d, %eax
100005437: 41 89 c7                    	movl	%eax, %r15d
10000543a: 45 0f 42 fa                 	cmovbl	%r10d, %r15d
10000543e: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100005442: 41 8b 46 10                 	movl	16(%r14), %eax
100005446: 45 8b 66 14                 	movl	20(%r14), %r12d
10000544a: 44 39 e0                    	cmpl	%r12d, %eax
10000544d: 89 c1                       	movl	%eax, %ecx
10000544f: 41 0f 42 cc                 	cmovbl	%r12d, %ecx
100005453: 89 4d d0                    	movl	%ecx, -48(%rbp)
100005456: 44 0f 42 e0                 	cmovbl	%eax, %r12d
10000545a: 41 8b 56 18                 	movl	24(%r14), %edx
10000545e: 45 8b 46 1c                 	movl	28(%r14), %r8d
100005462: 44 39 c2                    	cmpl	%r8d, %edx
100005465: 41 89 d1                    	movl	%edx, %r9d
100005468: 45 0f 42 c8                 	cmovbl	%r8d, %r9d
10000546c: 44 0f 42 c2                 	cmovbl	%edx, %r8d
100005470: 41 8b 56 20                 	movl	32(%r14), %edx
100005474: 41 8b 7e 24                 	movl	36(%r14), %edi
100005478: 39 fa                       	cmpl	%edi, %edx
10000547a: 89 d0                       	movl	%edx, %eax
10000547c: 0f 42 c7                    	cmovbl	%edi, %eax
10000547f: 89 45 c0                    	movl	%eax, -64(%rbp)
100005482: 0f 42 fa                    	cmovbl	%edx, %edi
100005485: 41 8b 56 28                 	movl	40(%r14), %edx
100005489: 41 8b 5e 2c                 	movl	44(%r14), %ebx
10000548d: 39 da                       	cmpl	%ebx, %edx
10000548f: 89 d6                       	movl	%edx, %esi
100005491: 0f 42 f3                    	cmovbl	%ebx, %esi
100005494: 0f 42 da                    	cmovbl	%edx, %ebx
100005497: 41 8b 4e 30                 	movl	48(%r14), %ecx
10000549b: 41 8b 56 34                 	movl	52(%r14), %edx
10000549f: 39 d1                       	cmpl	%edx, %ecx
1000054a1: 89 c8                       	movl	%ecx, %eax
1000054a3: 0f 42 c2                    	cmovbl	%edx, %eax
1000054a6: 89 45 cc                    	movl	%eax, -52(%rbp)
1000054a9: 0f 42 d1                    	cmovbl	%ecx, %edx
1000054ac: 45 39 d3                    	cmpl	%r10d, %r11d
1000054af: 44 89 d8                    	movl	%r11d, %eax
1000054b2: 41 0f 42 c2                 	cmovbl	%r10d, %eax
1000054b6: 89 45 c8                    	movl	%eax, -56(%rbp)
1000054b9: 45 0f 42 d3                 	cmovbl	%r11d, %r10d
1000054bd: 45 39 c4                    	cmpl	%r8d, %r12d
1000054c0: 45 89 e5                    	movl	%r12d, %r13d
1000054c3: 45 0f 42 e8                 	cmovbl	%r8d, %r13d
1000054c7: 45 0f 42 c4                 	cmovbl	%r12d, %r8d
1000054cb: 39 df                       	cmpl	%ebx, %edi
1000054cd: 89 f8                       	movl	%edi, %eax
1000054cf: 0f 42 c3                    	cmovbl	%ebx, %eax
1000054d2: 89 45 bc                    	movl	%eax, -68(%rbp)
1000054d5: 0f 42 df                    	cmovbl	%edi, %ebx
1000054d8: 41 8b 4e 38                 	movl	56(%r14), %ecx
1000054dc: 39 ca                       	cmpl	%ecx, %edx
1000054de: 41 89 d3                    	movl	%edx, %r11d
1000054e1: 44 0f 42 d9                 	cmovbl	%ecx, %r11d
1000054e5: 0f 43 d1                    	cmovael	%ecx, %edx
1000054e8: 44 89 ff                    	movl	%r15d, %edi
1000054eb: 8b 45 d4                    	movl	-44(%rbp), %eax
1000054ee: 44 39 f8                    	cmpl	%r15d, %eax
1000054f1: 41 89 c4                    	movl	%eax, %r12d
1000054f4: 45 0f 42 e7                 	cmovbl	%r15d, %r12d
1000054f8: 0f 42 f8                    	cmovbl	%eax, %edi
1000054fb: 8b 4d d0                    	movl	-48(%rbp), %ecx
1000054fe: 44 39 c9                    	cmpl	%r9d, %ecx
100005501: 41 89 cf                    	movl	%ecx, %r15d
100005504: 45 0f 42 f9                 	cmovbl	%r9d, %r15d
100005508: 44 0f 42 c9                 	cmovbl	%ecx, %r9d
10000550c: 8b 45 c0                    	movl	-64(%rbp), %eax
10000550f: 39 f0                       	cmpl	%esi, %eax
100005511: 89 c1                       	movl	%eax, %ecx
100005513: 0f 42 ce                    	cmovbl	%esi, %ecx
100005516: 89 4d c4                    	movl	%ecx, -60(%rbp)
100005519: 0f 42 f0                    	cmovbl	%eax, %esi
10000551c: 45 39 c2                    	cmpl	%r8d, %r10d
10000551f: 44 89 d1                    	movl	%r10d, %ecx
100005522: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100005526: 89 4d d0                    	movl	%ecx, -48(%rbp)
100005529: 45 0f 42 c2                 	cmovbl	%r10d, %r8d
10000552d: 39 d3                       	cmpl	%edx, %ebx
10000552f: 89 d9                       	movl	%ebx, %ecx
100005531: 0f 42 ca                    	cmovbl	%edx, %ecx
100005534: 0f 42 d3                    	cmovbl	%ebx, %edx
100005537: 44 39 cf                    	cmpl	%r9d, %edi
10000553a: 89 fb                       	movl	%edi, %ebx
10000553c: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
100005540: 44 0f 42 cf                 	cmovbl	%edi, %r9d
100005544: 8b 45 cc                    	movl	-52(%rbp), %eax
100005547: 39 c6                       	cmpl	%eax, %esi
100005549: 89 f7                       	movl	%esi, %edi
10000554b: 0f 42 f8                    	cmovbl	%eax, %edi
10000554e: 89 7d d4                    	movl	%edi, -44(%rbp)
100005551: 0f 43 f0                    	cmovael	%eax, %esi
100005554: 8b 45 c8                    	movl	-56(%rbp), %eax
100005557: 44 39 e8                    	cmpl	%r13d, %eax
10000555a: 89 c7                       	movl	%eax, %edi
10000555c: 41 0f 42 fd                 	cmovbl	%r13d, %edi
100005560: 89 7d c0                    	movl	%edi, -64(%rbp)
100005563: 44 0f 42 e8                 	cmovbl	%eax, %r13d
100005567: 44 89 ef                    	movl	%r13d, %edi
10000556a: 8b 45 bc                    	movl	-68(%rbp), %eax
10000556d: 44 39 d8                    	cmpl	%r11d, %eax
100005570: 41 89 c5                    	movl	%eax, %r13d
100005573: 45 0f 42 eb                 	cmovbl	%r11d, %r13d
100005577: 44 0f 42 d8                 	cmovbl	%eax, %r11d
10000557b: 45 39 fc                    	cmpl	%r15d, %r12d
10000557e: 44 89 e0                    	movl	%r12d, %eax
100005581: 41 0f 42 c7                 	cmovbl	%r15d, %eax
100005585: 89 45 cc                    	movl	%eax, -52(%rbp)
100005588: 45 0f 42 fc                 	cmovbl	%r12d, %r15d
10000558c: 41 39 d0                    	cmpl	%edx, %r8d
10000558f: 44 89 c0                    	movl	%r8d, %eax
100005592: 0f 42 c2                    	cmovbl	%edx, %eax
100005595: 89 45 c8                    	movl	%eax, -56(%rbp)
100005598: 41 0f 42 d0                 	cmovbl	%r8d, %edx
10000559c: 41 89 16                    	movl	%edx, (%r14)
10000559f: 41 39 f1                    	cmpl	%esi, %r9d
1000055a2: 45 89 ca                    	movl	%r9d, %r10d
1000055a5: 44 0f 42 d6                 	cmovbl	%esi, %r10d
1000055a9: 41 0f 42 f1                 	cmovbl	%r9d, %esi
1000055ad: 44 39 df                    	cmpl	%r11d, %edi
1000055b0: 41 89 f8                    	movl	%edi, %r8d
1000055b3: 45 0f 42 c3                 	cmovbl	%r11d, %r8d
1000055b7: 44 0f 42 df                 	cmovbl	%edi, %r11d
1000055bb: 8b 55 c4                    	movl	-60(%rbp), %edx
1000055be: 41 39 d7                    	cmpl	%edx, %r15d
1000055c1: 44 89 f8                    	movl	%r15d, %eax
1000055c4: 0f 42 c2                    	cmovbl	%edx, %eax
1000055c7: 44 0f 43 fa                 	cmovael	%edx, %r15d
1000055cb: 44 39 de                    	cmpl	%r11d, %esi
1000055ce: 89 f2                       	movl	%esi, %edx
1000055d0: 41 0f 42 d3                 	cmovbl	%r11d, %edx
1000055d4: 89 55 c4                    	movl	%edx, -60(%rbp)
1000055d7: 44 0f 42 de                 	cmovbl	%esi, %r11d
1000055db: 8b 55 d0                    	movl	-48(%rbp), %edx
1000055de: 39 ca                       	cmpl	%ecx, %edx
1000055e0: 89 d7                       	movl	%edx, %edi
1000055e2: 0f 42 f9                    	cmovbl	%ecx, %edi
1000055e5: 0f 42 ca                    	cmovbl	%edx, %ecx
1000055e8: 8b 55 d4                    	movl	-44(%rbp), %edx
1000055eb: 39 d3                       	cmpl	%edx, %ebx
1000055ed: 41 89 d9                    	movl	%ebx, %r9d
1000055f0: 44 0f 42 ca                 	cmovbl	%edx, %r9d
1000055f4: 0f 42 d3                    	cmovbl	%ebx, %edx
1000055f7: 8b 5d c0                    	movl	-64(%rbp), %ebx
1000055fa: 44 39 eb                    	cmpl	%r13d, %ebx
1000055fd: 41 89 dc                    	movl	%ebx, %r12d
100005600: 45 0f 42 e5                 	cmovbl	%r13d, %r12d
100005604: 44 0f 42 eb                 	cmovbl	%ebx, %r13d
100005608: 44 39 c2                    	cmpl	%r8d, %edx
10000560b: 89 d6                       	movl	%edx, %esi
10000560d: 41 0f 42 f0                 	cmovbl	%r8d, %esi
100005611: 89 75 bc                    	movl	%esi, -68(%rbp)
100005614: 41 0f 43 d0                 	cmovael	%r8d, %edx
100005618: 89 55 d4                    	movl	%edx, -44(%rbp)
10000561b: 45 39 e1                    	cmpl	%r12d, %r9d
10000561e: 44 89 ca                    	movl	%r9d, %edx
100005621: 41 0f 42 d4                 	cmovbl	%r12d, %edx
100005625: 45 0f 42 e1                 	cmovbl	%r9d, %r12d
100005629: 45 39 d5                    	cmpl	%r10d, %r13d
10000562c: 44 89 ee                    	movl	%r13d, %esi
10000562f: 41 0f 42 f2                 	cmovbl	%r10d, %esi
100005633: 89 75 d0                    	movl	%esi, -48(%rbp)
100005636: 45 0f 43 ea                 	cmovael	%r10d, %r13d
10000563a: 41 39 ff                    	cmpl	%edi, %r15d
10000563d: 44 89 fb                    	movl	%r15d, %ebx
100005640: 0f 42 df                    	cmovbl	%edi, %ebx
100005643: 41 0f 42 ff                 	cmovbl	%r15d, %edi
100005647: 44 8b 45 cc                 	movl	-52(%rbp), %r8d
10000564b: 41 39 c0                    	cmpl	%eax, %r8d
10000564e: 45 89 c1                    	movl	%r8d, %r9d
100005651: 44 0f 42 c8                 	cmovbl	%eax, %r9d
100005655: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100005659: 44 8b 45 c8                 	movl	-56(%rbp), %r8d
10000565d: 44 39 c1                    	cmpl	%r8d, %ecx
100005660: 41 89 ca                    	movl	%ecx, %r10d
100005663: 45 0f 42 d0                 	cmovbl	%r8d, %r10d
100005667: 41 0f 43 c8                 	cmovael	%r8d, %ecx
10000566b: 41 39 cb                    	cmpl	%ecx, %r11d
10000566e: 45 89 d8                    	movl	%r11d, %r8d
100005671: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100005675: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
100005679: 41 89 4e 04                 	movl	%ecx, 4(%r14)
10000567d: 44 39 e0                    	cmpl	%r12d, %eax
100005680: 89 c6                       	movl	%eax, %esi
100005682: 41 0f 42 f4                 	cmovbl	%r12d, %esi
100005686: 41 0f 43 c4                 	cmovael	%r12d, %eax
10000568a: 44 8b 7d c4                 	movl	-60(%rbp), %r15d
10000568e: 45 39 d7                    	cmpl	%r10d, %r15d
100005691: 44 89 f9                    	movl	%r15d, %ecx
100005694: 41 0f 42 ca                 	cmovbl	%r10d, %ecx
100005698: 45 0f 42 d7                 	cmovbl	%r15d, %r10d
10000569c: 41 39 d1                    	cmpl	%edx, %r9d
10000569f: 45 89 cc                    	movl	%r9d, %r12d
1000056a2: 44 0f 42 e2                 	cmovbl	%edx, %r12d
1000056a6: 44 0f 43 ca                 	cmovael	%edx, %r9d
1000056aa: 45 89 66 38                 	movl	%r12d, 56(%r14)
1000056ae: 44 8b 5d d0                 	movl	-48(%rbp), %r11d
1000056b2: 8b 55 bc                    	movl	-68(%rbp), %edx
1000056b5: 41 39 d3                    	cmpl	%edx, %r11d
1000056b8: 45 89 dc                    	movl	%r11d, %r12d
1000056bb: 44 0f 42 e2                 	cmovbl	%edx, %r12d
1000056bf: 44 0f 43 da                 	cmovael	%edx, %r11d
1000056c3: 44 89 5d d0                 	movl	%r11d, -48(%rbp)
1000056c7: 45 39 c2                    	cmpl	%r8d, %r10d
1000056ca: 45 89 d3                    	movl	%r10d, %r11d
1000056cd: 45 0f 42 d8                 	cmovbl	%r8d, %r11d
1000056d1: 45 0f 43 d0                 	cmovael	%r8d, %r10d
1000056d5: 45 89 56 08                 	movl	%r10d, 8(%r14)
1000056d9: 8b 55 d4                    	movl	-44(%rbp), %edx
1000056dc: 44 39 ea                    	cmpl	%r13d, %edx
1000056df: 41 89 d0                    	movl	%edx, %r8d
1000056e2: 45 0f 42 c5                 	cmovbl	%r13d, %r8d
1000056e6: 44 0f 42 ea                 	cmovbl	%edx, %r13d
1000056ea: 41 39 f1                    	cmpl	%esi, %r9d
1000056ed: 44 89 ca                    	movl	%r9d, %edx
1000056f0: 0f 42 d6                    	cmovbl	%esi, %edx
1000056f3: 44 0f 43 ce                 	cmovael	%esi, %r9d
1000056f7: 41 89 56 34                 	movl	%edx, 52(%r14)
1000056fb: 39 cf                       	cmpl	%ecx, %edi
1000056fd: 89 fa                       	movl	%edi, %edx
1000056ff: 0f 42 d1                    	cmovbl	%ecx, %edx
100005702: 0f 42 cf                    	cmovbl	%edi, %ecx
100005705: 89 de                       	movl	%ebx, %esi
100005707: 39 d8                       	cmpl	%ebx, %eax
100005709: 89 c7                       	movl	%eax, %edi
10000570b: 0f 42 fb                    	cmovbl	%ebx, %edi
10000570e: 0f 43 c3                    	cmovael	%ebx, %eax
100005711: 44 39 e9                    	cmpl	%r13d, %ecx
100005714: 41 89 cf                    	movl	%ecx, %r15d
100005717: 45 0f 42 fd                 	cmovbl	%r13d, %r15d
10000571b: 41 0f 43 cd                 	cmovael	%r13d, %ecx
10000571f: 41 39 d0                    	cmpl	%edx, %r8d
100005722: 45 89 c2                    	movl	%r8d, %r10d
100005725: 44 0f 42 d2                 	cmovbl	%edx, %r10d
100005729: 41 0f 42 d0                 	cmovbl	%r8d, %edx
10000572d: 41 39 fc                    	cmpl	%edi, %r12d
100005730: 44 89 e3                    	movl	%r12d, %ebx
100005733: 0f 42 df                    	cmovbl	%edi, %ebx
100005736: 41 0f 42 fc                 	cmovbl	%r12d, %edi
10000573a: 44 39 d9                    	cmpl	%r11d, %ecx
10000573d: 89 ce                       	movl	%ecx, %esi
10000573f: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100005743: 41 0f 43 cb                 	cmovael	%r11d, %ecx
100005747: 41 89 4e 0c                 	movl	%ecx, 12(%r14)
10000574b: 41 89 76 10                 	movl	%esi, 16(%r14)
10000574f: 8b 75 d0                    	movl	-48(%rbp), %esi
100005752: 39 f0                       	cmpl	%esi, %eax
100005754: 89 c1                       	movl	%eax, %ecx
100005756: 0f 42 ce                    	cmovbl	%esi, %ecx
100005759: 0f 43 c6                    	cmovael	%esi, %eax
10000575c: 41 39 d7                    	cmpl	%edx, %r15d
10000575f: 44 89 fe                    	movl	%r15d, %esi
100005762: 0f 42 f2                    	cmovbl	%edx, %esi
100005765: 41 0f 42 d7                 	cmovbl	%r15d, %edx
100005769: 41 89 56 14                 	movl	%edx, 20(%r14)
10000576d: 41 39 d9                    	cmpl	%ebx, %r9d
100005770: 44 89 ca                    	movl	%r9d, %edx
100005773: 0f 42 d3                    	cmovbl	%ebx, %edx
100005776: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
10000577a: 41 89 5e 2c                 	movl	%ebx, 44(%r14)
10000577e: 41 89 56 30                 	movl	%edx, 48(%r14)
100005782: 44 39 d0                    	cmpl	%r10d, %eax
100005785: 89 c2                       	movl	%eax, %edx
100005787: 41 0f 42 d2                 	cmovbl	%r10d, %edx
10000578b: 41 0f 43 c2                 	cmovael	%r10d, %eax
10000578f: 39 f9                       	cmpl	%edi, %ecx
100005791: 89 cb                       	movl	%ecx, %ebx
100005793: 0f 42 df                    	cmovbl	%edi, %ebx
100005796: 0f 43 cf                    	cmovael	%edi, %ecx
100005799: 41 89 5e 28                 	movl	%ebx, 40(%r14)
10000579d: 39 c6                       	cmpl	%eax, %esi
10000579f: 89 f7                       	movl	%esi, %edi
1000057a1: 0f 42 f8                    	cmovbl	%eax, %edi
1000057a4: 0f 42 c6                    	cmovbl	%esi, %eax
1000057a7: 41 89 46 18                 	movl	%eax, 24(%r14)
1000057ab: 41 89 7e 1c                 	movl	%edi, 28(%r14)
1000057af: 39 ca                       	cmpl	%ecx, %edx
1000057b1: 89 d0                       	movl	%edx, %eax
1000057b3: 0f 42 c1                    	cmovbl	%ecx, %eax
1000057b6: 0f 42 ca                    	cmovbl	%edx, %ecx
1000057b9: 41 89 4e 20                 	movl	%ecx, 32(%r14)
1000057bd: e9 e0 03 00 00              	jmp	992 <_quick_sort_recursive+0x1962>
1000057c2: 41 8b 06                    	movl	(%r14), %eax
1000057c5: 45 8b 56 04                 	movl	4(%r14), %r10d
1000057c9: 44 39 d0                    	cmpl	%r10d, %eax
1000057cc: 41 89 c5                    	movl	%eax, %r13d
1000057cf: 45 0f 42 ea                 	cmovbl	%r10d, %r13d
1000057d3: 44 0f 42 d0                 	cmovbl	%eax, %r10d
1000057d7: 41 8b 46 08                 	movl	8(%r14), %eax
1000057db: 45 8b 4e 0c                 	movl	12(%r14), %r9d
1000057df: 44 39 c8                    	cmpl	%r9d, %eax
1000057e2: 89 c1                       	movl	%eax, %ecx
1000057e4: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
1000057e8: 89 4d d4                    	movl	%ecx, -44(%rbp)
1000057eb: 44 0f 42 c8                 	cmovbl	%eax, %r9d
1000057ef: 41 8b 46 10                 	movl	16(%r14), %eax
1000057f3: 45 8b 7e 14                 	movl	20(%r14), %r15d
1000057f7: 44 39 f8                    	cmpl	%r15d, %eax
1000057fa: 89 c1                       	movl	%eax, %ecx
1000057fc: 41 0f 42 cf                 	cmovbl	%r15d, %ecx
100005800: 89 4d d0                    	movl	%ecx, -48(%rbp)
100005803: 44 0f 42 f8                 	cmovbl	%eax, %r15d
100005807: 41 8b 46 18                 	movl	24(%r14), %eax
10000580b: 45 8b 66 1c                 	movl	28(%r14), %r12d
10000580f: 44 39 e0                    	cmpl	%r12d, %eax
100005812: 89 c1                       	movl	%eax, %ecx
100005814: 41 0f 42 cc                 	cmovbl	%r12d, %ecx
100005818: 89 4d cc                    	movl	%ecx, -52(%rbp)
10000581b: 44 0f 42 e0                 	cmovbl	%eax, %r12d
10000581f: 41 8b 46 20                 	movl	32(%r14), %eax
100005823: 41 8b 76 24                 	movl	36(%r14), %esi
100005827: 39 f0                       	cmpl	%esi, %eax
100005829: 41 89 c3                    	movl	%eax, %r11d
10000582c: 44 0f 42 de                 	cmovbl	%esi, %r11d
100005830: 0f 42 f0                    	cmovbl	%eax, %esi
100005833: 41 8b 4e 28                 	movl	40(%r14), %ecx
100005837: 41 8b 56 2c                 	movl	44(%r14), %edx
10000583b: 39 d1                       	cmpl	%edx, %ecx
10000583d: 89 cb                       	movl	%ecx, %ebx
10000583f: 0f 42 da                    	cmovbl	%edx, %ebx
100005842: 0f 42 d1                    	cmovbl	%ecx, %edx
100005845: 41 8b 4e 30                 	movl	48(%r14), %ecx
100005849: 45 8b 46 34                 	movl	52(%r14), %r8d
10000584d: 44 39 c1                    	cmpl	%r8d, %ecx
100005850: 89 c8                       	movl	%ecx, %eax
100005852: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100005856: 89 45 c8                    	movl	%eax, -56(%rbp)
100005859: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
10000585d: 41 8b 46 38                 	movl	56(%r14), %eax
100005861: 41 8b 7e 3c                 	movl	60(%r14), %edi
100005865: 39 f8                       	cmpl	%edi, %eax
100005867: 89 c1                       	movl	%eax, %ecx
100005869: 0f 42 cf                    	cmovbl	%edi, %ecx
10000586c: 0f 42 f8                    	cmovbl	%eax, %edi
10000586f: 45 39 ca                    	cmpl	%r9d, %r10d
100005872: 44 89 d0                    	movl	%r10d, %eax
100005875: 41 0f 42 c1                 	cmovbl	%r9d, %eax
100005879: 89 45 c4                    	movl	%eax, -60(%rbp)
10000587c: 45 0f 42 ca                 	cmovbl	%r10d, %r9d
100005880: 45 39 e7                    	cmpl	%r12d, %r15d
100005883: 44 89 f8                    	movl	%r15d, %eax
100005886: 41 0f 42 c4                 	cmovbl	%r12d, %eax
10000588a: 89 45 b4                    	movl	%eax, -76(%rbp)
10000588d: 45 0f 42 e7                 	cmovbl	%r15d, %r12d
100005891: 39 d6                       	cmpl	%edx, %esi
100005893: 89 f0                       	movl	%esi, %eax
100005895: 0f 42 c2                    	cmovbl	%edx, %eax
100005898: 89 45 c0                    	movl	%eax, -64(%rbp)
10000589b: 0f 42 d6                    	cmovbl	%esi, %edx
10000589e: 41 39 f8                    	cmpl	%edi, %r8d
1000058a1: 45 89 c2                    	movl	%r8d, %r10d
1000058a4: 44 0f 42 d7                 	cmovbl	%edi, %r10d
1000058a8: 41 0f 42 f8                 	cmovbl	%r8d, %edi
1000058ac: 8b 45 d4                    	movl	-44(%rbp), %eax
1000058af: 41 39 c5                    	cmpl	%eax, %r13d
1000058b2: 44 89 ee                    	movl	%r13d, %esi
1000058b5: 0f 42 f0                    	cmovbl	%eax, %esi
1000058b8: 89 75 b8                    	movl	%esi, -72(%rbp)
1000058bb: 41 0f 42 c5                 	cmovbl	%r13d, %eax
1000058bf: 41 89 c7                    	movl	%eax, %r15d
1000058c2: 8b 75 cc                    	movl	-52(%rbp), %esi
1000058c5: 8b 45 d0                    	movl	-48(%rbp), %eax
1000058c8: 39 f0                       	cmpl	%esi, %eax
1000058ca: 41 89 c5                    	movl	%eax, %r13d
1000058cd: 44 0f 42 ee                 	cmovbl	%esi, %r13d
1000058d1: 0f 42 f0                    	cmovbl	%eax, %esi
1000058d4: 41 39 db                    	cmpl	%ebx, %r11d
1000058d7: 44 89 d8                    	movl	%r11d, %eax
1000058da: 0f 42 c3                    	cmovbl	%ebx, %eax
1000058dd: 89 45 d4                    	movl	%eax, -44(%rbp)
1000058e0: 41 0f 42 db                 	cmovbl	%r11d, %ebx
1000058e4: 8b 45 c8                    	movl	-56(%rbp), %eax
1000058e7: 39 c8                       	cmpl	%ecx, %eax
1000058e9: 41 89 c3                    	movl	%eax, %r11d
1000058ec: 44 0f 42 d9                 	cmovbl	%ecx, %r11d
1000058f0: 0f 42 c8                    	cmovbl	%eax, %ecx
1000058f3: 45 39 e1                    	cmpl	%r12d, %r9d
1000058f6: 44 89 c8                    	movl	%r9d, %eax
1000058f9: 41 0f 42 c4                 	cmovbl	%r12d, %eax
1000058fd: 89 45 cc                    	movl	%eax, -52(%rbp)
100005900: 45 0f 42 e1                 	cmovbl	%r9d, %r12d
100005904: 39 fa                       	cmpl	%edi, %edx
100005906: 41 89 d0                    	movl	%edx, %r8d
100005909: 44 0f 42 c7                 	cmovbl	%edi, %r8d
10000590d: 0f 42 fa                    	cmovbl	%edx, %edi
100005910: 41 39 f7                    	cmpl	%esi, %r15d
100005913: 44 89 f8                    	movl	%r15d, %eax
100005916: 0f 42 c6                    	cmovbl	%esi, %eax
100005919: 89 45 c8                    	movl	%eax, -56(%rbp)
10000591c: 41 0f 42 f7                 	cmovbl	%r15d, %esi
100005920: 39 cb                       	cmpl	%ecx, %ebx
100005922: 41 89 d9                    	movl	%ebx, %r9d
100005925: 44 0f 42 c9                 	cmovbl	%ecx, %r9d
100005929: 0f 42 cb                    	cmovbl	%ebx, %ecx
10000592c: 8b 55 b4                    	movl	-76(%rbp), %edx
10000592f: 8b 45 c4                    	movl	-60(%rbp), %eax
100005932: 39 d0                       	cmpl	%edx, %eax
100005934: 89 c3                       	movl	%eax, %ebx
100005936: 0f 42 da                    	cmovbl	%edx, %ebx
100005939: 89 5d bc                    	movl	%ebx, -68(%rbp)
10000593c: 0f 42 d0                    	cmovbl	%eax, %edx
10000593f: 8b 45 c0                    	movl	-64(%rbp), %eax
100005942: 44 39 d0                    	cmpl	%r10d, %eax
100005945: 41 89 c7                    	movl	%eax, %r15d
100005948: 45 0f 42 fa                 	cmovbl	%r10d, %r15d
10000594c: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100005950: 8b 45 b8                    	movl	-72(%rbp), %eax
100005953: 44 39 e8                    	cmpl	%r13d, %eax
100005956: 89 c3                       	movl	%eax, %ebx
100005958: 41 0f 42 dd                 	cmovbl	%r13d, %ebx
10000595c: 89 5d c4                    	movl	%ebx, -60(%rbp)
10000595f: 44 0f 42 e8                 	cmovbl	%eax, %r13d
100005963: 8b 5d d4                    	movl	-44(%rbp), %ebx
100005966: 44 39 db                    	cmpl	%r11d, %ebx
100005969: 89 d8                       	movl	%ebx, %eax
10000596b: 41 0f 42 c3                 	cmovbl	%r11d, %eax
10000596f: 44 0f 42 db                 	cmovbl	%ebx, %r11d
100005973: 41 39 fc                    	cmpl	%edi, %r12d
100005976: 44 89 e3                    	movl	%r12d, %ebx
100005979: 0f 42 df                    	cmovbl	%edi, %ebx
10000597c: 89 5d d4                    	movl	%ebx, -44(%rbp)
10000597f: 41 0f 42 fc                 	cmovbl	%r12d, %edi
100005983: 41 89 3e                    	movl	%edi, (%r14)
100005986: 39 ce                       	cmpl	%ecx, %esi
100005988: 89 f7                       	movl	%esi, %edi
10000598a: 0f 42 f9                    	cmovbl	%ecx, %edi
10000598d: 0f 42 ce                    	cmovbl	%esi, %ecx
100005990: 44 39 d2                    	cmpl	%r10d, %edx
100005993: 89 d3                       	movl	%edx, %ebx
100005995: 41 0f 42 da                 	cmovbl	%r10d, %ebx
100005999: 44 0f 42 d2                 	cmovbl	%edx, %r10d
10000599d: 45 39 dd                    	cmpl	%r11d, %r13d
1000059a0: 44 89 ea                    	movl	%r13d, %edx
1000059a3: 41 0f 42 d3                 	cmovbl	%r11d, %edx
1000059a7: 89 55 c0                    	movl	%edx, -64(%rbp)
1000059aa: 45 0f 42 dd                 	cmovbl	%r13d, %r11d
1000059ae: 44 39 d1                    	cmpl	%r10d, %ecx
1000059b1: 89 ca                       	movl	%ecx, %edx
1000059b3: 41 0f 42 d2                 	cmovbl	%r10d, %edx
1000059b7: 89 55 d0                    	movl	%edx, -48(%rbp)
1000059ba: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
1000059be: 8b 4d cc                    	movl	-52(%rbp), %ecx
1000059c1: 44 39 c1                    	cmpl	%r8d, %ecx
1000059c4: 41 89 cc                    	movl	%ecx, %r12d
1000059c7: 45 0f 42 e0                 	cmovbl	%r8d, %r12d
1000059cb: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
1000059cf: 8b 4d c8                    	movl	-56(%rbp), %ecx
1000059d2: 44 39 c9                    	cmpl	%r9d, %ecx
1000059d5: 41 89 cd                    	movl	%ecx, %r13d
1000059d8: 45 0f 42 e9                 	cmovbl	%r9d, %r13d
1000059dc: 44 0f 42 c9                 	cmovbl	%ecx, %r9d
1000059e0: 8b 55 bc                    	movl	-68(%rbp), %edx
1000059e3: 44 39 fa                    	cmpl	%r15d, %edx
1000059e6: 89 d1                       	movl	%edx, %ecx
1000059e8: 41 0f 42 cf                 	cmovbl	%r15d, %ecx
1000059ec: 44 0f 42 fa                 	cmovbl	%edx, %r15d
1000059f0: 8b 75 c4                    	movl	-60(%rbp), %esi
1000059f3: 39 c6                       	cmpl	%eax, %esi
1000059f5: 89 f2                       	movl	%esi, %edx
1000059f7: 0f 42 d0                    	cmovbl	%eax, %edx
1000059fa: 0f 42 c6                    	cmovbl	%esi, %eax
1000059fd: 41 89 56 3c                 	movl	%edx, 60(%r14)
100005a01: 41 39 d9                    	cmpl	%ebx, %r9d
100005a04: 44 89 ca                    	movl	%r9d, %edx
100005a07: 0f 42 d3                    	cmovbl	%ebx, %edx
100005a0a: 89 55 c4                    	movl	%edx, -60(%rbp)
100005a0d: 44 0f 43 cb                 	cmovael	%ebx, %r9d
100005a11: 44 89 4d c8                 	movl	%r9d, -56(%rbp)
100005a15: 41 39 cd                    	cmpl	%ecx, %r13d
100005a18: 44 89 eb                    	movl	%r13d, %ebx
100005a1b: 0f 42 d9                    	cmovbl	%ecx, %ebx
100005a1e: 41 0f 42 cd                 	cmovbl	%r13d, %ecx
100005a22: 41 39 ff                    	cmpl	%edi, %r15d
100005a25: 45 89 fd                    	movl	%r15d, %r13d
100005a28: 44 0f 42 ef                 	cmovbl	%edi, %r13d
100005a2c: 44 0f 43 ff                 	cmovael	%edi, %r15d
100005a30: 45 39 e3                    	cmpl	%r12d, %r11d
100005a33: 44 89 da                    	movl	%r11d, %edx
100005a36: 41 0f 42 d4                 	cmovbl	%r12d, %edx
100005a3a: 89 55 cc                    	movl	%edx, -52(%rbp)
100005a3d: 45 0f 42 e3                 	cmovbl	%r11d, %r12d
100005a41: 8b 55 c0                    	movl	-64(%rbp), %edx
100005a44: 39 d0                       	cmpl	%edx, %eax
100005a46: 89 c7                       	movl	%eax, %edi
100005a48: 0f 42 fa                    	cmovbl	%edx, %edi
100005a4b: 0f 43 c2                    	cmovael	%edx, %eax
100005a4e: 8b 55 d4                    	movl	-44(%rbp), %edx
100005a51: 41 39 d0                    	cmpl	%edx, %r8d
100005a54: 44 89 c6                    	movl	%r8d, %esi
100005a57: 0f 42 f2                    	cmovbl	%edx, %esi
100005a5a: 44 0f 43 c2                 	cmovael	%edx, %r8d
100005a5e: 45 39 c2                    	cmpl	%r8d, %r10d
100005a61: 45 89 d1                    	movl	%r10d, %r9d
100005a64: 45 0f 42 c8                 	cmovbl	%r8d, %r9d
100005a68: 45 0f 42 c2                 	cmovbl	%r10d, %r8d
100005a6c: 45 89 46 04                 	movl	%r8d, 4(%r14)
100005a70: 39 c8                       	cmpl	%ecx, %eax
100005a72: 41 89 c0                    	movl	%eax, %r8d
100005a75: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100005a79: 0f 43 c1                    	cmovael	%ecx, %eax
100005a7c: 8b 4d d0                    	movl	-48(%rbp), %ecx
100005a7f: 39 f1                       	cmpl	%esi, %ecx
100005a81: 89 ca                       	movl	%ecx, %edx
100005a83: 0f 42 d6                    	cmovbl	%esi, %edx
100005a86: 0f 42 f1                    	cmovbl	%ecx, %esi
100005a89: 39 df                       	cmpl	%ebx, %edi
100005a8b: 89 f9                       	movl	%edi, %ecx
100005a8d: 0f 42 cb                    	cmovbl	%ebx, %ecx
100005a90: 0f 43 fb                    	cmovael	%ebx, %edi
100005a93: 41 89 4e 38                 	movl	%ecx, 56(%r14)
100005a97: 8b 4d c4                    	movl	-60(%rbp), %ecx
100005a9a: 41 39 cd                    	cmpl	%ecx, %r13d
100005a9d: 45 89 eb                    	movl	%r13d, %r11d
100005aa0: 44 0f 42 d9                 	cmovbl	%ecx, %r11d
100005aa4: 44 0f 43 e9                 	cmovael	%ecx, %r13d
100005aa8: 44 39 ce                    	cmpl	%r9d, %esi
100005aab: 41 89 f2                    	movl	%esi, %r10d
100005aae: 45 0f 42 d1                 	cmovbl	%r9d, %r10d
100005ab2: 41 0f 43 f1                 	cmovael	%r9d, %esi
100005ab6: 41 89 76 08                 	movl	%esi, 8(%r14)
100005aba: 8b 4d c8                    	movl	-56(%rbp), %ecx
100005abd: 44 39 f9                    	cmpl	%r15d, %ecx
100005ac0: 89 cb                       	movl	%ecx, %ebx
100005ac2: 41 0f 42 df                 	cmovbl	%r15d, %ebx
100005ac6: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
100005aca: 44 39 c7                    	cmpl	%r8d, %edi
100005acd: 89 f9                       	movl	%edi, %ecx
100005acf: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100005ad3: 41 0f 43 f8                 	cmovael	%r8d, %edi
100005ad7: 41 89 4e 34                 	movl	%ecx, 52(%r14)
100005adb: 41 39 d4                    	cmpl	%edx, %r12d
100005ade: 44 89 e1                    	movl	%r12d, %ecx
100005ae1: 0f 42 ca                    	cmovbl	%edx, %ecx
100005ae4: 41 0f 42 d4                 	cmovbl	%r12d, %edx
100005ae8: 8b 75 cc                    	movl	-52(%rbp), %esi
100005aeb: 39 f0                       	cmpl	%esi, %eax
100005aed: 41 89 c4                    	movl	%eax, %r12d
100005af0: 44 0f 42 e6                 	cmovbl	%esi, %r12d
100005af4: 0f 43 c6                    	cmovael	%esi, %eax
100005af7: 44 39 fa                    	cmpl	%r15d, %edx
100005afa: 41 89 d1                    	movl	%edx, %r9d
100005afd: 45 0f 42 cf                 	cmovbl	%r15d, %r9d
100005b01: 41 0f 43 d7                 	cmovael	%r15d, %edx
100005b05: 39 cb                       	cmpl	%ecx, %ebx
100005b07: 41 89 d8                    	movl	%ebx, %r8d
100005b0a: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100005b0e: 0f 42 cb                    	cmovbl	%ebx, %ecx
100005b11: 45 39 e3                    	cmpl	%r12d, %r11d
100005b14: 44 89 db                    	movl	%r11d, %ebx
100005b17: 41 0f 42 dc                 	cmovbl	%r12d, %ebx
100005b1b: 45 0f 42 e3                 	cmovbl	%r11d, %r12d
100005b1f: 44 39 d2                    	cmpl	%r10d, %edx
100005b22: 89 d6                       	movl	%edx, %esi
100005b24: 41 0f 42 f2                 	cmovbl	%r10d, %esi
100005b28: 41 0f 43 d2                 	cmovael	%r10d, %edx
100005b2c: 41 89 56 0c                 	movl	%edx, 12(%r14)
100005b30: 41 89 76 10                 	movl	%esi, 16(%r14)
100005b34: 44 39 e8                    	cmpl	%r13d, %eax
100005b37: 89 c2                       	movl	%eax, %edx
100005b39: 41 0f 42 d5                 	cmovbl	%r13d, %edx
100005b3d: 41 0f 43 c5                 	cmovael	%r13d, %eax
100005b41: 41 39 c9                    	cmpl	%ecx, %r9d
100005b44: 44 89 ce                    	movl	%r9d, %esi
100005b47: 0f 42 f1                    	cmovbl	%ecx, %esi
100005b4a: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
100005b4e: 41 89 4e 14                 	movl	%ecx, 20(%r14)
100005b52: 39 df                       	cmpl	%ebx, %edi
100005b54: 89 f9                       	movl	%edi, %ecx
100005b56: 0f 42 cb                    	cmovbl	%ebx, %ecx
100005b59: 0f 42 df                    	cmovbl	%edi, %ebx
100005b5c: 41 89 5e 2c                 	movl	%ebx, 44(%r14)
100005b60: 41 89 4e 30                 	movl	%ecx, 48(%r14)
100005b64: 44 39 c0                    	cmpl	%r8d, %eax
100005b67: 89 c1                       	movl	%eax, %ecx
100005b69: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100005b6d: 41 0f 43 c0                 	cmovael	%r8d, %eax
100005b71: 44 39 e2                    	cmpl	%r12d, %edx
100005b74: 89 d7                       	movl	%edx, %edi
100005b76: 41 0f 42 fc                 	cmovbl	%r12d, %edi
100005b7a: 41 0f 43 d4                 	cmovael	%r12d, %edx
100005b7e: 41 89 7e 28                 	movl	%edi, 40(%r14)
100005b82: 39 c6                       	cmpl	%eax, %esi
100005b84: 89 f7                       	movl	%esi, %edi
100005b86: 0f 42 f8                    	cmovbl	%eax, %edi
100005b89: 0f 42 c6                    	cmovbl	%esi, %eax
100005b8c: 41 89 46 18                 	movl	%eax, 24(%r14)
100005b90: 41 89 7e 1c                 	movl	%edi, 28(%r14)
100005b94: 39 d1                       	cmpl	%edx, %ecx
100005b96: 89 c8                       	movl	%ecx, %eax
100005b98: 0f 42 c2                    	cmovbl	%edx, %eax
100005b9b: 0f 42 d1                    	cmovbl	%ecx, %edx
100005b9e: 41 89 56 20                 	movl	%edx, 32(%r14)
100005ba2: 41 89 46 24                 	movl	%eax, 36(%r14)
100005ba6: 48 83 c4 28                 	addq	$40, %rsp
100005baa: 5b                          	popq	%rbx
100005bab: 41 5c                       	popq	%r12
100005bad: 41 5d                       	popq	%r13
100005baf: 41 5e                       	popq	%r14
100005bb1: 41 5f                       	popq	%r15
100005bb3: 5d                          	popq	%rbp
100005bb4: c3                          	retq
100005bb5: 0f 1f 00                    	nopl	(%rax)
100005bb8: 07                          	<unknown>
100005bb9: e7 ff                       	outl	%eax, $255
100005bbb: ff 24 e7                    	jmpq	*(%rdi,%riz,8)
100005bbe: ff ff                       	<unknown>
100005bc0: 5d                          	popq	%rbp
100005bc1: e7 ff                       	outl	%eax, $255
100005bc3: ff aa e7 ff ff 2f           	ljmpl	*805306343(%rdx)
100005bc9: e8 ff ff df e8              	callq	-387973121 <dyld_stub_binder+0xe8e05bcd>
100005bce: ff ff                       	<unknown>
100005bd0: be e9 ff ff e6              	movl	$3875536873, %esi
100005bd5: ea                          	<unknown>
100005bd6: ff ff                       	<unknown>
100005bd8: 54                          	pushq	%rsp
100005bd9: ec                          	inb	%dx, %al
100005bda: ff ff                       	<unknown>
100005bdc: 0e                          	<unknown>
100005bdd: ee                          	outb	%al, %dx
100005bde: ff ff                       	<unknown>
100005be0: fe ef                       	<unknown>
100005be2: ff ff                       	<unknown>
100005be4: 5f                          	popq	%rdi
100005be5: f2 ff ff                    	<unknown>
100005be8: 23 f5                       	andl	%ebp, %esi
100005bea: ff ff                       	<unknown>
100005bec: 5d                          	popq	%rbp
100005bed: f8                          	clc
100005bee: ff ff                       	<unknown>
100005bf0: 0a fc                       	orb	%ah, %bh
100005bf2: ff ff                       	<unknown>
100005bf4: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100005bfe: 66 90                       	nop

0000000100005c00 _csort:
100005c00: 55                          	pushq	%rbp
100005c01: 48 89 e5                    	movq	%rsp, %rbp
100005c04: 5d                          	popq	%rbp
100005c05: e9 36 e6 ff ff              	jmp	-6602 <_quick_sort_recursive>
100005c0a: 66 0f 1f 44 00 00           	nopw	(%rax,%rax)

0000000100005c10 _test_quick_sort_recursive:
100005c10: 55                          	pushq	%rbp
100005c11: 48 89 e5                    	movq	%rsp, %rbp
100005c14: 41 57                       	pushq	%r15
100005c16: 41 56                       	pushq	%r14
100005c18: 41 55                       	pushq	%r13
100005c1a: 41 54                       	pushq	%r12
100005c1c: 53                          	pushq	%rbx
100005c1d: 48 83 ec 28                 	subq	$40, %rsp
100005c21: 48 39 f2                    	cmpq	%rsi, %rdx
100005c24: 0f 86 b3 1c 00 00           	jbe	7347 <_test_quick_sort_recursive+0x1ccd>
100005c2a: 49 89 d6                    	movq	%rdx, %r14
100005c2d: 49 89 fd                    	movq	%rdi, %r13
100005c30: 49 89 d7                    	movq	%rdx, %r15
100005c33: 49 f7 df                    	negq	%r15
100005c36: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100005c40: 4d 89 f1                    	movq	%r14, %r9
100005c43: 49 29 f1                    	subq	%rsi, %r9
100005c46: 49 8d 41 01                 	leaq	1(%r9), %rax
100005c4a: 48 83 f8 10                 	cmpq	$16, %rax
100005c4e: 0f 86 0b 01 00 00           	jbe	267 <_test_quick_sort_recursive+0x14f>
100005c54: 4c 89 c8                    	movq	%r9, %rax
100005c57: 48 d1 e8                    	shrq	%rax
100005c5a: 48 01 f0                    	addq	%rsi, %rax
100005c5d: 45 8b 54 85 00              	movl	(%r13,%rax,4), %r10d
100005c62: 43 8b 4c b5 00              	movl	(%r13,%r14,4), %ecx
100005c67: 41 89 4c 85 00              	movl	%ecx, (%r13,%rax,4)
100005c6c: 47 89 54 b5 00              	movl	%r10d, (%r13,%r14,4)
100005c71: 48 89 f1                    	movq	%rsi, %rcx
100005c74: 48 f7 d1                    	notq	%rcx
100005c77: 41 83 e1 01                 	andl	$1, %r9d
100005c7b: 31 c0                       	xorl	%eax, %eax
100005c7d: 49 89 f4                    	movq	%rsi, %r12
100005c80: 48 89 f7                    	movq	%rsi, %rdi
100005c83: 4c 39 f9                    	cmpq	%r15, %rcx
100005c86: 75 78                       	jne	120 <_test_quick_sort_recursive+0xf0>
100005c88: 4d 85 c9                    	testq	%r9, %r9
100005c8b: 74 23                       	je	35 <_test_quick_sort_recursive+0xa0>
100005c8d: 41 8b 4c bd 00              	movl	(%r13,%rdi,4), %ecx
100005c92: 89 ca                       	movl	%ecx, %edx
100005c94: 44 29 d2                    	subl	%r10d, %edx
100005c97: 09 d0                       	orl	%edx, %eax
100005c99: 85 d2                       	testl	%edx, %edx
100005c9b: 79 13                       	jns	19 <_test_quick_sort_recursive+0xa0>
100005c9d: 43 8b 54 a5 00              	movl	(%r13,%r12,4), %edx
100005ca2: 41 89 54 bd 00              	movl	%edx, (%r13,%rdi,4)
100005ca7: 43 89 4c a5 00              	movl	%ecx, (%r13,%r12,4)
100005cac: 49 ff c4                    	incq	%r12
100005caf: 90                          	nop
100005cb0: 43 8b 4c b5 00              	movl	(%r13,%r14,4), %ecx
100005cb5: 43 8b 54 a5 00              	movl	(%r13,%r12,4), %edx
100005cba: 43 89 54 b5 00              	movl	%edx, (%r13,%r14,4)
100005cbf: 43 89 4c a5 00              	movl	%ecx, (%r13,%r12,4)
100005cc4: 85 c0                       	testl	%eax, %eax
100005cc6: 0f 84 11 1c 00 00           	je	7185 <_test_quick_sort_recursive+0x1ccd>
100005ccc: 49 83 fc ff                 	cmpq	$-1, %r12
100005cd0: 0f 84 07 1c 00 00           	je	7175 <_test_quick_sort_recursive+0x1ccd>
100005cd6: 49 8d 54 24 ff              	leaq	-1(%r12), %rdx
100005cdb: 4c 89 ef                    	movq	%r13, %rdi
100005cde: e8 2d ff ff ff              	callq	-211 <_test_quick_sort_recursive>
100005ce3: 49 ff c4                    	incq	%r12
100005ce6: 4c 89 e6                    	movq	%r12, %rsi
100005ce9: 4d 39 f4                    	cmpq	%r14, %r12
100005cec: 0f 82 4e ff ff ff           	jb	-178 <_test_quick_sort_recursive+0x30>
100005cf2: e9 e6 1b 00 00              	jmp	7142 <_test_quick_sort_recursive+0x1ccd>
100005cf7: 66 0f 1f 84 00 00 00 00 00  	nopw	(%rax,%rax)
100005d00: 4d 89 f0                    	movq	%r14, %r8
100005d03: 4d 29 c8                    	subq	%r9, %r8
100005d06: 31 c0                       	xorl	%eax, %eax
100005d08: 49 89 f4                    	movq	%rsi, %r12
100005d0b: 48 89 f7                    	movq	%rsi, %rdi
100005d0e: eb 0f                       	jmp	15 <_test_quick_sort_recursive+0x10f>
100005d10: 09 c8                       	orl	%ecx, %eax
100005d12: 48 83 c7 02                 	addq	$2, %rdi
100005d16: 49 39 f8                    	cmpq	%rdi, %r8
100005d19: 0f 84 69 ff ff ff           	je	-151 <_test_quick_sort_recursive+0x78>
100005d1f: 41 8b 54 bd 00              	movl	(%r13,%rdi,4), %edx
100005d24: 89 d1                       	movl	%edx, %ecx
100005d26: 44 29 d1                    	subl	%r10d, %ecx
100005d29: 79 12                       	jns	18 <_test_quick_sort_recursive+0x12d>
100005d2b: 43 8b 5c a5 00              	movl	(%r13,%r12,4), %ebx
100005d30: 41 89 5c bd 00              	movl	%ebx, (%r13,%rdi,4)
100005d35: 43 89 54 a5 00              	movl	%edx, (%r13,%r12,4)
100005d3a: 49 ff c4                    	incq	%r12
100005d3d: 09 c8                       	orl	%ecx, %eax
100005d3f: 41 8b 54 bd 04              	movl	4(%r13,%rdi,4), %edx
100005d44: 89 d1                       	movl	%edx, %ecx
100005d46: 44 29 d1                    	subl	%r10d, %ecx
100005d49: 79 c5                       	jns	-59 <_test_quick_sort_recursive+0x100>
100005d4b: 43 8b 5c a5 00              	movl	(%r13,%r12,4), %ebx
100005d50: 41 89 5c bd 04              	movl	%ebx, 4(%r13,%rdi,4)
100005d55: 43 89 54 a5 00              	movl	%edx, (%r13,%r12,4)
100005d5a: 49 ff c4                    	incq	%r12
100005d5d: eb b1                       	jmp	-79 <_test_quick_sort_recursive+0x100>
100005d5f: 4d 8d 64 b5 00              	leaq	(%r13,%rsi,4), %r12
100005d64: 77 31                       	ja	49 <_test_quick_sort_recursive+0x187>
100005d66: 48 8d 0d 7f 1b 00 00        	leaq	7039(%rip), %rcx
100005d6d: 48 63 04 81                 	movslq	(%rcx,%rax,4), %rax
100005d71: 48 01 c8                    	addq	%rcx, %rax
100005d74: ff e0                       	jmpq	*%rax
100005d76: 41 8b 04 24                 	movl	(%r12), %eax
100005d7a: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100005d7f: 39 c8                       	cmpl	%ecx, %eax
100005d81: 89 ca                       	movl	%ecx, %edx
100005d83: 0f 47 d0                    	cmoval	%eax, %edx
100005d86: 0f 42 c8                    	cmovbl	%eax, %ecx
100005d89: 41 89 0c 24                 	movl	%ecx, (%r12)
100005d8d: 41 89 54 24 04              	movl	%edx, 4(%r12)
100005d92: e9 46 1b 00 00              	jmp	6982 <_test_quick_sort_recursive+0x1ccd>
100005d97: ba 01 00 00 00              	movl	$1, %edx
100005d9c: 49 c7 c3 fe ff ff ff        	movq	$-2, %r11
100005da3: eb 14                       	jmp	20 <_test_quick_sort_recursive+0x1a9>
100005da5: 41 89 3c 84                 	movl	%edi, (%r12,%rax,4)
100005da9: 49 ff c3                    	incq	%r11
100005dac: 4c 39 ca                    	cmpq	%r9, %rdx
100005daf: 48 8d 52 01                 	leaq	1(%rdx), %rdx
100005db3: 0f 84 24 1b 00 00           	je	6948 <_test_quick_sort_recursive+0x1ccd>
100005db9: 45 8b 54 94 fc              	movl	-4(%r12,%rdx,4), %r10d
100005dbe: 41 8b 3c 94                 	movl	(%r12,%rdx,4), %edi
100005dc2: 44 89 d0                    	movl	%r10d, %eax
100005dc5: 29 f8                       	subl	%edi, %eax
100005dc7: 85 c0                       	testl	%eax, %eax
100005dc9: 7e de                       	jle	-34 <_test_quick_sort_recursive+0x199>
100005dcb: 4c 8d 42 ff                 	leaq	-1(%rdx), %r8
100005dcf: 41 3b 3c 24                 	cmpl	(%r12), %edi
100005dd3: 78 4d                       	js	77 <_test_quick_sort_recursive+0x212>
100005dd5: 89 f9                       	movl	%edi, %ecx
100005dd7: 44 29 d1                    	subl	%r10d, %ecx
100005dda: 4c 89 c0                    	movq	%r8, %rax
100005ddd: 85 c9                       	testl	%ecx, %ecx
100005ddf: 7f 51                       	jg	81 <_test_quick_sort_recursive+0x222>
100005de1: 4c 89 c0                    	movq	%r8, %rax
100005de4: 48 d1 e8                    	shrq	%rax
100005de7: 31 c9                       	xorl	%ecx, %ecx
100005de9: 4c 89 c6                    	movq	%r8, %rsi
100005dec: eb 1a                       	jmp	26 <_test_quick_sort_recursive+0x1f8>
100005dee: 66 90                       	nop
100005df0: 48 89 c3                    	movq	%rax, %rbx
100005df3: 48 29 cb                    	subq	%rcx, %rbx
100005df6: 48 83 fb 02                 	cmpq	$2, %rbx
100005dfa: 72 2d                       	jb	45 <_test_quick_sort_recursive+0x219>
100005dfc: 48 89 c6                    	movq	%rax, %rsi
100005dff: 48 d1 eb                    	shrq	%rbx
100005e02: 48 01 cb                    	addq	%rcx, %rbx
100005e05: 48 89 d8                    	movq	%rbx, %rax
100005e08: 41 3b 3c 84                 	cmpl	(%r12,%rax,4), %edi
100005e0c: 78 e2                       	js	-30 <_test_quick_sort_recursive+0x1e0>
100005e0e: 48 89 f3                    	movq	%rsi, %rbx
100005e11: 48 29 c3                    	subq	%rax, %rbx
100005e14: 48 83 fb 01                 	cmpq	$1, %rbx
100005e18: 76 0c                       	jbe	12 <_test_quick_sort_recursive+0x216>
100005e1a: 48 89 c1                    	movq	%rax, %rcx
100005e1d: 48 89 f0                    	movq	%rsi, %rax
100005e20: eb da                       	jmp	-38 <_test_quick_sort_recursive+0x1ec>
100005e22: 31 c0                       	xorl	%eax, %eax
100005e24: eb 0c                       	jmp	12 <_test_quick_sort_recursive+0x222>
100005e26: 48 ff c0                    	incq	%rax
100005e29: 49 39 c0                    	cmpq	%rax, %r8
100005e2c: 0f 82 73 ff ff ff           	jb	-141 <_test_quick_sort_recursive+0x195>
100005e32: 45 89 14 94                 	movl	%r10d, (%r12,%rdx,4)
100005e36: 4d 85 c0                    	testq	%r8, %r8
100005e39: 0f 84 66 ff ff ff           	je	-154 <_test_quick_sort_recursive+0x195>
100005e3f: 48 8d 4a fe                 	leaq	-2(%rdx), %rcx
100005e43: 48 39 c1                    	cmpq	%rax, %rcx
100005e46: 0f 82 59 ff ff ff           	jb	-167 <_test_quick_sort_recursive+0x195>
100005e4c: 4c 89 d9                    	movq	%r11, %rcx
100005e4f: 90                          	nop
100005e50: 41 8b 74 8c 04              	movl	4(%r12,%rcx,4), %esi
100005e55: 41 89 74 8c 08              	movl	%esi, 8(%r12,%rcx,4)
100005e5a: 48 83 f9 ff                 	cmpq	$-1, %rcx
100005e5e: 0f 84 41 ff ff ff           	je	-191 <_test_quick_sort_recursive+0x195>
100005e64: 48 39 c1                    	cmpq	%rax, %rcx
100005e67: 48 8d 49 ff                 	leaq	-1(%rcx), %rcx
100005e6b: 73 e3                       	jae	-29 <_test_quick_sort_recursive+0x240>
100005e6d: e9 33 ff ff ff              	jmp	-205 <_test_quick_sort_recursive+0x195>
100005e72: 41 8b 04 24                 	movl	(%r12), %eax
100005e76: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100005e7b: 41 8b 54 24 08              	movl	8(%r12), %edx
100005e80: 39 d1                       	cmpl	%edx, %ecx
100005e82: 89 d6                       	movl	%edx, %esi
100005e84: 0f 47 f1                    	cmoval	%ecx, %esi
100005e87: 0f 42 d1                    	cmovbl	%ecx, %edx
100005e8a: 39 f0                       	cmpl	%esi, %eax
100005e8c: 89 f1                       	movl	%esi, %ecx
100005e8e: 0f 47 c8                    	cmoval	%eax, %ecx
100005e91: 0f 42 f0                    	cmovbl	%eax, %esi
100005e94: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
100005e99: 39 d6                       	cmpl	%edx, %esi
100005e9b: 89 d0                       	movl	%edx, %eax
100005e9d: 0f 47 c6                    	cmoval	%esi, %eax
100005ea0: 0f 43 f2                    	cmovael	%edx, %esi
100005ea3: 41 89 34 24                 	movl	%esi, (%r12)
100005ea7: 41 89 44 24 04              	movl	%eax, 4(%r12)
100005eac: e9 2c 1a 00 00              	jmp	6700 <_test_quick_sort_recursive+0x1ccd>
100005eb1: 41 8b 04 24                 	movl	(%r12), %eax
100005eb5: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100005eba: 39 c8                       	cmpl	%ecx, %eax
100005ebc: 89 ca                       	movl	%ecx, %edx
100005ebe: 0f 47 d0                    	cmoval	%eax, %edx
100005ec1: 0f 42 c8                    	cmovbl	%eax, %ecx
100005ec4: 41 8b 44 24 08              	movl	8(%r12), %eax
100005ec9: 41 8b 74 24 0c              	movl	12(%r12), %esi
100005ece: 39 f0                       	cmpl	%esi, %eax
100005ed0: 89 f7                       	movl	%esi, %edi
100005ed2: 0f 47 f8                    	cmoval	%eax, %edi
100005ed5: 0f 42 f0                    	cmovbl	%eax, %esi
100005ed8: 39 f1                       	cmpl	%esi, %ecx
100005eda: 89 f0                       	movl	%esi, %eax
100005edc: 0f 47 c1                    	cmoval	%ecx, %eax
100005edf: 0f 42 f1                    	cmovbl	%ecx, %esi
100005ee2: 41 89 34 24                 	movl	%esi, (%r12)
100005ee6: 39 fa                       	cmpl	%edi, %edx
100005ee8: 89 f9                       	movl	%edi, %ecx
100005eea: 0f 47 ca                    	cmoval	%edx, %ecx
100005eed: 0f 42 fa                    	cmovbl	%edx, %edi
100005ef0: 41 89 4c 24 0c              	movl	%ecx, 12(%r12)
100005ef5: 39 c7                       	cmpl	%eax, %edi
100005ef7: 89 c1                       	movl	%eax, %ecx
100005ef9: 0f 47 cf                    	cmoval	%edi, %ecx
100005efc: 0f 43 f8                    	cmovael	%eax, %edi
100005eff: 41 89 7c 24 04              	movl	%edi, 4(%r12)
100005f04: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
100005f09: e9 cf 19 00 00              	jmp	6607 <_test_quick_sort_recursive+0x1ccd>
100005f0e: 41 8b 0c 24                 	movl	(%r12), %ecx
100005f12: 41 8b 44 24 04              	movl	4(%r12), %eax
100005f17: 39 c1                       	cmpl	%eax, %ecx
100005f19: 89 c2                       	movl	%eax, %edx
100005f1b: 0f 47 d1                    	cmoval	%ecx, %edx
100005f1e: 0f 42 c1                    	cmovbl	%ecx, %eax
100005f21: 41 8b 4c 24 0c              	movl	12(%r12), %ecx
100005f26: 41 8b 74 24 10              	movl	16(%r12), %esi
100005f2b: 39 f1                       	cmpl	%esi, %ecx
100005f2d: 89 f7                       	movl	%esi, %edi
100005f2f: 0f 47 f9                    	cmoval	%ecx, %edi
100005f32: 0f 42 f1                    	cmovbl	%ecx, %esi
100005f35: 41 8b 4c 24 08              	movl	8(%r12), %ecx
100005f3a: 39 f9                       	cmpl	%edi, %ecx
100005f3c: 89 fb                       	movl	%edi, %ebx
100005f3e: 0f 47 d9                    	cmoval	%ecx, %ebx
100005f41: 0f 42 f9                    	cmovbl	%ecx, %edi
100005f44: 39 f7                       	cmpl	%esi, %edi
100005f46: 89 f1                       	movl	%esi, %ecx
100005f48: 0f 47 cf                    	cmoval	%edi, %ecx
100005f4b: 0f 43 fe                    	cmovael	%esi, %edi
100005f4e: 39 da                       	cmpl	%ebx, %edx
100005f50: 89 de                       	movl	%ebx, %esi
100005f52: 0f 47 f2                    	cmoval	%edx, %esi
100005f55: 0f 42 da                    	cmovbl	%edx, %ebx
100005f58: 39 c8                       	cmpl	%ecx, %eax
100005f5a: 89 ca                       	movl	%ecx, %edx
100005f5c: 0f 47 d0                    	cmoval	%eax, %edx
100005f5f: 41 89 74 24 10              	movl	%esi, 16(%r12)
100005f64: 0f 42 c8                    	cmovbl	%eax, %ecx
100005f67: 39 f9                       	cmpl	%edi, %ecx
100005f69: 89 f8                       	movl	%edi, %eax
100005f6b: 0f 47 c1                    	cmoval	%ecx, %eax
100005f6e: 0f 43 cf                    	cmovael	%edi, %ecx
100005f71: 41 89 0c 24                 	movl	%ecx, (%r12)
100005f75: 39 d3                       	cmpl	%edx, %ebx
100005f77: 89 d1                       	movl	%edx, %ecx
100005f79: 0f 47 cb                    	cmoval	%ebx, %ecx
100005f7c: 0f 42 d3                    	cmovbl	%ebx, %edx
100005f7f: 41 89 4c 24 0c              	movl	%ecx, 12(%r12)
100005f84: 39 c2                       	cmpl	%eax, %edx
100005f86: 89 c1                       	movl	%eax, %ecx
100005f88: 0f 47 ca                    	cmoval	%edx, %ecx
100005f8b: 0f 43 d0                    	cmovael	%eax, %edx
100005f8e: 41 89 54 24 04              	movl	%edx, 4(%r12)
100005f93: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
100005f98: e9 40 19 00 00              	jmp	6464 <_test_quick_sort_recursive+0x1ccd>
100005f9d: 41 8b 14 24                 	movl	(%r12), %edx
100005fa1: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100005fa6: 41 8b 74 24 08              	movl	8(%r12), %esi
100005fab: 39 f1                       	cmpl	%esi, %ecx
100005fad: 89 f0                       	movl	%esi, %eax
100005faf: 0f 47 c1                    	cmoval	%ecx, %eax
100005fb2: 0f 42 f1                    	cmovbl	%ecx, %esi
100005fb5: 41 8b 7c 24 10              	movl	16(%r12), %edi
100005fba: 41 8b 5c 24 14              	movl	20(%r12), %ebx
100005fbf: 39 df                       	cmpl	%ebx, %edi
100005fc1: 89 d9                       	movl	%ebx, %ecx
100005fc3: 0f 47 cf                    	cmoval	%edi, %ecx
100005fc6: 0f 42 df                    	cmovbl	%edi, %ebx
100005fc9: 39 c2                       	cmpl	%eax, %edx
100005fcb: 41 89 c0                    	movl	%eax, %r8d
100005fce: 44 0f 47 c2                 	cmoval	%edx, %r8d
100005fd2: 0f 42 c2                    	cmovbl	%edx, %eax
100005fd5: 41 8b 7c 24 0c              	movl	12(%r12), %edi
100005fda: 39 cf                       	cmpl	%ecx, %edi
100005fdc: 89 ca                       	movl	%ecx, %edx
100005fde: 0f 47 d7                    	cmoval	%edi, %edx
100005fe1: 0f 42 cf                    	cmovbl	%edi, %ecx
100005fe4: 39 f0                       	cmpl	%esi, %eax
100005fe6: 89 f7                       	movl	%esi, %edi
100005fe8: 0f 47 f8                    	cmoval	%eax, %edi
100005feb: 0f 43 c6                    	cmovael	%esi, %eax
100005fee: 39 d9                       	cmpl	%ebx, %ecx
100005ff0: 89 de                       	movl	%ebx, %esi
100005ff2: 0f 47 f1                    	cmoval	%ecx, %esi
100005ff5: 0f 43 cb                    	cmovael	%ebx, %ecx
100005ff8: 41 39 d0                    	cmpl	%edx, %r8d
100005ffb: 89 d3                       	movl	%edx, %ebx
100005ffd: 41 0f 47 d8                 	cmoval	%r8d, %ebx
100006001: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100006005: 41 89 5c 24 14              	movl	%ebx, 20(%r12)
10000600a: 39 c8                       	cmpl	%ecx, %eax
10000600c: 89 cb                       	movl	%ecx, %ebx
10000600e: 0f 47 d8                    	cmoval	%eax, %ebx
100006011: 0f 42 c8                    	cmovbl	%eax, %ecx
100006014: 39 f7                       	cmpl	%esi, %edi
100006016: 89 f0                       	movl	%esi, %eax
100006018: 0f 47 c7                    	cmoval	%edi, %eax
10000601b: 41 89 0c 24                 	movl	%ecx, (%r12)
10000601f: 0f 42 f7                    	cmovbl	%edi, %esi
100006022: 39 c2                       	cmpl	%eax, %edx
100006024: 89 c1                       	movl	%eax, %ecx
100006026: 0f 47 ca                    	cmoval	%edx, %ecx
100006029: 0f 42 c2                    	cmovbl	%edx, %eax
10000602c: 41 89 4c 24 10              	movl	%ecx, 16(%r12)
100006031: 39 de                       	cmpl	%ebx, %esi
100006033: 89 d9                       	movl	%ebx, %ecx
100006035: 0f 47 ce                    	cmoval	%esi, %ecx
100006038: 0f 43 f3                    	cmovael	%ebx, %esi
10000603b: 41 89 74 24 04              	movl	%esi, 4(%r12)
100006040: 39 c8                       	cmpl	%ecx, %eax
100006042: 89 ca                       	movl	%ecx, %edx
100006044: 0f 47 d0                    	cmoval	%eax, %edx
100006047: 0f 42 c8                    	cmovbl	%eax, %ecx
10000604a: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
10000604f: 41 89 54 24 0c              	movl	%edx, 12(%r12)
100006054: e9 84 18 00 00              	jmp	6276 <_test_quick_sort_recursive+0x1ccd>
100006059: 45 8b 0c 24                 	movl	(%r12), %r9d
10000605d: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100006062: 41 8b 7c 24 08              	movl	8(%r12), %edi
100006067: 39 f9                       	cmpl	%edi, %ecx
100006069: 89 f8                       	movl	%edi, %eax
10000606b: 0f 47 c1                    	cmoval	%ecx, %eax
10000606e: 0f 42 f9                    	cmovbl	%ecx, %edi
100006071: 41 8b 4c 24 0c              	movl	12(%r12), %ecx
100006076: 41 8b 5c 24 10              	movl	16(%r12), %ebx
10000607b: 39 d9                       	cmpl	%ebx, %ecx
10000607d: 41 89 d8                    	movl	%ebx, %r8d
100006080: 44 0f 47 c1                 	cmoval	%ecx, %r8d
100006084: 0f 42 d9                    	cmovbl	%ecx, %ebx
100006087: 41 8b 4c 24 14              	movl	20(%r12), %ecx
10000608c: 41 8b 74 24 18              	movl	24(%r12), %esi
100006091: 39 f1                       	cmpl	%esi, %ecx
100006093: 89 f2                       	movl	%esi, %edx
100006095: 0f 47 d1                    	cmoval	%ecx, %edx
100006098: 0f 42 f1                    	cmovbl	%ecx, %esi
10000609b: 41 39 c1                    	cmpl	%eax, %r9d
10000609e: 41 89 c2                    	movl	%eax, %r10d
1000060a1: 45 0f 47 d1                 	cmoval	%r9d, %r10d
1000060a5: 41 0f 42 c1                 	cmovbl	%r9d, %eax
1000060a9: 39 f3                       	cmpl	%esi, %ebx
1000060ab: 41 89 f1                    	movl	%esi, %r9d
1000060ae: 44 0f 47 cb                 	cmoval	%ebx, %r9d
1000060b2: 0f 42 f3                    	cmovbl	%ebx, %esi
1000060b5: 41 39 d0                    	cmpl	%edx, %r8d
1000060b8: 89 d3                       	movl	%edx, %ebx
1000060ba: 41 0f 47 d8                 	cmoval	%r8d, %ebx
1000060be: 41 0f 42 d0                 	cmovbl	%r8d, %edx
1000060c2: 39 f8                       	cmpl	%edi, %eax
1000060c4: 89 f9                       	movl	%edi, %ecx
1000060c6: 0f 47 c8                    	cmoval	%eax, %ecx
1000060c9: 0f 43 c7                    	cmovael	%edi, %eax
1000060cc: 44 39 ca                    	cmpl	%r9d, %edx
1000060cf: 44 89 cf                    	movl	%r9d, %edi
1000060d2: 0f 47 fa                    	cmoval	%edx, %edi
1000060d5: 41 0f 43 d1                 	cmovael	%r9d, %edx
1000060d9: 41 39 da                    	cmpl	%ebx, %r10d
1000060dc: 41 89 d8                    	movl	%ebx, %r8d
1000060df: 45 0f 47 c2                 	cmoval	%r10d, %r8d
1000060e3: 41 0f 42 da                 	cmovbl	%r10d, %ebx
1000060e7: 39 d0                       	cmpl	%edx, %eax
1000060e9: 41 89 d1                    	movl	%edx, %r9d
1000060ec: 44 0f 47 c8                 	cmoval	%eax, %r9d
1000060f0: 0f 42 d0                    	cmovbl	%eax, %edx
1000060f3: 39 f9                       	cmpl	%edi, %ecx
1000060f5: 89 f8                       	movl	%edi, %eax
1000060f7: 0f 47 c1                    	cmoval	%ecx, %eax
1000060fa: 0f 42 f9                    	cmovbl	%ecx, %edi
1000060fd: 39 f2                       	cmpl	%esi, %edx
1000060ff: 89 f1                       	movl	%esi, %ecx
100006101: 0f 47 ca                    	cmoval	%edx, %ecx
100006104: 45 89 44 24 18              	movl	%r8d, 24(%r12)
100006109: 0f 43 d6                    	cmovael	%esi, %edx
10000610c: 41 89 14 24                 	movl	%edx, (%r12)
100006110: 39 c3                       	cmpl	%eax, %ebx
100006112: 89 c2                       	movl	%eax, %edx
100006114: 0f 47 d3                    	cmoval	%ebx, %edx
100006117: 0f 42 c3                    	cmovbl	%ebx, %eax
10000611a: 41 89 54 24 14              	movl	%edx, 20(%r12)
10000611f: 39 cf                       	cmpl	%ecx, %edi
100006121: 89 ca                       	movl	%ecx, %edx
100006123: 0f 47 d7                    	cmoval	%edi, %edx
100006126: 0f 42 cf                    	cmovbl	%edi, %ecx
100006129: 41 89 4c 24 04              	movl	%ecx, 4(%r12)
10000612e: 44 39 c8                    	cmpl	%r9d, %eax
100006131: 44 89 c9                    	movl	%r9d, %ecx
100006134: 0f 47 c8                    	cmoval	%eax, %ecx
100006137: 41 0f 43 c1                 	cmovael	%r9d, %eax
10000613b: 41 89 4c 24 10              	movl	%ecx, 16(%r12)
100006140: 39 d0                       	cmpl	%edx, %eax
100006142: 89 d1                       	movl	%edx, %ecx
100006144: 0f 47 c8                    	cmoval	%eax, %ecx
100006147: 0f 43 c2                    	cmovael	%edx, %eax
10000614a: 41 89 44 24 08              	movl	%eax, 8(%r12)
10000614f: 41 89 4c 24 0c              	movl	%ecx, 12(%r12)
100006154: e9 84 17 00 00              	jmp	6020 <_test_quick_sort_recursive+0x1ccd>
100006159: 41 8b 04 24                 	movl	(%r12), %eax
10000615d: 41 8b 7c 24 04              	movl	4(%r12), %edi
100006162: 39 f8                       	cmpl	%edi, %eax
100006164: 41 89 f9                    	movl	%edi, %r9d
100006167: 44 0f 47 c8                 	cmoval	%eax, %r9d
10000616b: 0f 42 f8                    	cmovbl	%eax, %edi
10000616e: 41 8b 4c 24 08              	movl	8(%r12), %ecx
100006173: 41 8b 54 24 0c              	movl	12(%r12), %edx
100006178: 39 d1                       	cmpl	%edx, %ecx
10000617a: 89 d0                       	movl	%edx, %eax
10000617c: 0f 47 c1                    	cmoval	%ecx, %eax
10000617f: 0f 42 d1                    	cmovbl	%ecx, %edx
100006182: 41 8b 4c 24 10              	movl	16(%r12), %ecx
100006187: 41 8b 74 24 14              	movl	20(%r12), %esi
10000618c: 39 f1                       	cmpl	%esi, %ecx
10000618e: 41 89 f2                    	movl	%esi, %r10d
100006191: 44 0f 47 d1                 	cmoval	%ecx, %r10d
100006195: 0f 42 f1                    	cmovbl	%ecx, %esi
100006198: 45 8b 44 24 18              	movl	24(%r12), %r8d
10000619d: 41 8b 5c 24 1c              	movl	28(%r12), %ebx
1000061a2: 41 39 d8                    	cmpl	%ebx, %r8d
1000061a5: 89 d9                       	movl	%ebx, %ecx
1000061a7: 41 0f 47 c8                 	cmoval	%r8d, %ecx
1000061ab: 41 0f 42 d8                 	cmovbl	%r8d, %ebx
1000061af: 39 d7                       	cmpl	%edx, %edi
1000061b1: 41 89 d3                    	movl	%edx, %r11d
1000061b4: 44 0f 47 df                 	cmoval	%edi, %r11d
1000061b8: 0f 42 d7                    	cmovbl	%edi, %edx
1000061bb: 41 39 c1                    	cmpl	%eax, %r9d
1000061be: 41 89 c0                    	movl	%eax, %r8d
1000061c1: 45 0f 47 c1                 	cmoval	%r9d, %r8d
1000061c5: 41 0f 42 c1                 	cmovbl	%r9d, %eax
1000061c9: 39 de                       	cmpl	%ebx, %esi
1000061cb: 41 89 d9                    	movl	%ebx, %r9d
1000061ce: 44 0f 47 ce                 	cmoval	%esi, %r9d
1000061d2: 0f 42 de                    	cmovbl	%esi, %ebx
1000061d5: 41 39 ca                    	cmpl	%ecx, %r10d
1000061d8: 89 ce                       	movl	%ecx, %esi
1000061da: 41 0f 47 f2                 	cmoval	%r10d, %esi
1000061de: 41 0f 42 ca                 	cmovbl	%r10d, %ecx
1000061e2: 44 39 d8                    	cmpl	%r11d, %eax
1000061e5: 45 89 da                    	movl	%r11d, %r10d
1000061e8: 44 0f 47 d0                 	cmoval	%eax, %r10d
1000061ec: 41 0f 43 c3                 	cmovael	%r11d, %eax
1000061f0: 44 39 c9                    	cmpl	%r9d, %ecx
1000061f3: 44 89 cf                    	movl	%r9d, %edi
1000061f6: 0f 47 f9                    	cmoval	%ecx, %edi
1000061f9: 41 0f 43 c9                 	cmovael	%r9d, %ecx
1000061fd: 39 da                       	cmpl	%ebx, %edx
1000061ff: 41 89 d9                    	movl	%ebx, %r9d
100006202: 44 0f 47 ca                 	cmoval	%edx, %r9d
100006206: 0f 42 da                    	cmovbl	%edx, %ebx
100006209: 41 89 1c 24                 	movl	%ebx, (%r12)
10000620d: 41 39 f0                    	cmpl	%esi, %r8d
100006210: 41 89 f3                    	movl	%esi, %r11d
100006213: 45 0f 47 d8                 	cmoval	%r8d, %r11d
100006217: 41 0f 42 f0                 	cmovbl	%r8d, %esi
10000621b: 39 c8                       	cmpl	%ecx, %eax
10000621d: 89 cb                       	movl	%ecx, %ebx
10000621f: 0f 47 d8                    	cmoval	%eax, %ebx
100006222: 0f 42 c8                    	cmovbl	%eax, %ecx
100006225: 41 39 fa                    	cmpl	%edi, %r10d
100006228: 89 f8                       	movl	%edi, %eax
10000622a: 41 0f 47 c2                 	cmoval	%r10d, %eax
10000622e: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100006232: 44 39 c9                    	cmpl	%r9d, %ecx
100006235: 44 89 ca                    	movl	%r9d, %edx
100006238: 0f 47 d1                    	cmoval	%ecx, %edx
10000623b: 45 89 5c 24 1c              	movl	%r11d, 28(%r12)
100006240: 41 0f 43 c9                 	cmovael	%r9d, %ecx
100006244: 41 89 4c 24 04              	movl	%ecx, 4(%r12)
100006249: 39 c6                       	cmpl	%eax, %esi
10000624b: 89 c1                       	movl	%eax, %ecx
10000624d: 0f 47 ce                    	cmoval	%esi, %ecx
100006250: 0f 42 c6                    	cmovbl	%esi, %eax
100006253: 41 89 4c 24 18              	movl	%ecx, 24(%r12)
100006258: 39 d7                       	cmpl	%edx, %edi
10000625a: 89 d1                       	movl	%edx, %ecx
10000625c: 0f 47 cf                    	cmoval	%edi, %ecx
10000625f: 0f 42 d7                    	cmovbl	%edi, %edx
100006262: 41 89 54 24 08              	movl	%edx, 8(%r12)
100006267: 39 d8                       	cmpl	%ebx, %eax
100006269: 89 da                       	movl	%ebx, %edx
10000626b: 0f 47 d0                    	cmoval	%eax, %edx
10000626e: 0f 43 c3                    	cmovael	%ebx, %eax
100006271: 41 89 54 24 14              	movl	%edx, 20(%r12)
100006276: 39 c8                       	cmpl	%ecx, %eax
100006278: 89 ca                       	movl	%ecx, %edx
10000627a: 0f 47 d0                    	cmoval	%eax, %edx
10000627d: 0f 43 c1                    	cmovael	%ecx, %eax
100006280: 41 89 44 24 0c              	movl	%eax, 12(%r12)
100006285: 41 89 54 24 10              	movl	%edx, 16(%r12)
10000628a: e9 4e 16 00 00              	jmp	5710 <_test_quick_sort_recursive+0x1ccd>
10000628f: 41 8b 04 24                 	movl	(%r12), %eax
100006293: 45 8b 5c 24 04              	movl	4(%r12), %r11d
100006298: 44 39 d8                    	cmpl	%r11d, %eax
10000629b: 44 89 de                    	movl	%r11d, %esi
10000629e: 0f 47 f0                    	cmoval	%eax, %esi
1000062a1: 44 0f 42 d8                 	cmovbl	%eax, %r11d
1000062a5: 41 8b 44 24 0c              	movl	12(%r12), %eax
1000062aa: 41 8b 4c 24 10              	movl	16(%r12), %ecx
1000062af: 39 c8                       	cmpl	%ecx, %eax
1000062b1: 89 cf                       	movl	%ecx, %edi
1000062b3: 0f 47 f8                    	cmoval	%eax, %edi
1000062b6: 0f 42 c8                    	cmovbl	%eax, %ecx
1000062b9: 41 8b 5c 24 18              	movl	24(%r12), %ebx
1000062be: 41 8b 44 24 1c              	movl	28(%r12), %eax
1000062c3: 39 c3                       	cmpl	%eax, %ebx
1000062c5: 89 c2                       	movl	%eax, %edx
1000062c7: 0f 47 d3                    	cmoval	%ebx, %edx
1000062ca: 0f 42 c3                    	cmovbl	%ebx, %eax
1000062cd: 41 8b 5c 24 08              	movl	8(%r12), %ebx
1000062d2: 39 de                       	cmpl	%ebx, %esi
1000062d4: 41 89 da                    	movl	%ebx, %r10d
1000062d7: 44 0f 47 d6                 	cmoval	%esi, %r10d
1000062db: 0f 43 f3                    	cmovael	%ebx, %esi
1000062de: 41 8b 5c 24 14              	movl	20(%r12), %ebx
1000062e3: 39 df                       	cmpl	%ebx, %edi
1000062e5: 41 89 d8                    	movl	%ebx, %r8d
1000062e8: 44 0f 47 c7                 	cmoval	%edi, %r8d
1000062ec: 0f 43 fb                    	cmovael	%ebx, %edi
1000062ef: 41 8b 5c 24 20              	movl	32(%r12), %ebx
1000062f4: 39 da                       	cmpl	%ebx, %edx
1000062f6: 41 89 d9                    	movl	%ebx, %r9d
1000062f9: 44 0f 47 ca                 	cmoval	%edx, %r9d
1000062fd: 0f 43 d3                    	cmovael	%ebx, %edx
100006300: 41 39 f3                    	cmpl	%esi, %r11d
100006303: 41 89 f6                    	movl	%esi, %r14d
100006306: 45 0f 47 f3                 	cmoval	%r11d, %r14d
10000630a: 41 0f 42 f3                 	cmovbl	%r11d, %esi
10000630e: 39 f9                       	cmpl	%edi, %ecx
100006310: 89 fb                       	movl	%edi, %ebx
100006312: 0f 47 d9                    	cmoval	%ecx, %ebx
100006315: 0f 42 f9                    	cmovbl	%ecx, %edi
100006318: 39 d0                       	cmpl	%edx, %eax
10000631a: 41 89 d3                    	movl	%edx, %r11d
10000631d: 44 0f 47 d8                 	cmoval	%eax, %r11d
100006321: 0f 42 d0                    	cmovbl	%eax, %edx
100006324: 45 39 c2                    	cmpl	%r8d, %r10d
100006327: 44 89 c0                    	movl	%r8d, %eax
10000632a: 41 0f 47 c2                 	cmoval	%r10d, %eax
10000632e: 45 0f 42 c2                 	cmovbl	%r10d, %r8d
100006332: 39 fe                       	cmpl	%edi, %esi
100006334: 89 f9                       	movl	%edi, %ecx
100006336: 0f 47 ce                    	cmoval	%esi, %ecx
100006339: 0f 42 fe                    	cmovbl	%esi, %edi
10000633c: 41 39 de                    	cmpl	%ebx, %r14d
10000633f: 89 de                       	movl	%ebx, %esi
100006341: 41 0f 47 f6                 	cmoval	%r14d, %esi
100006345: 41 0f 42 de                 	cmovbl	%r14d, %ebx
100006349: 44 39 c8                    	cmpl	%r9d, %eax
10000634c: 45 89 ca                    	movl	%r9d, %r10d
10000634f: 44 0f 47 d0                 	cmoval	%eax, %r10d
100006353: 41 0f 43 c1                 	cmovael	%r9d, %eax
100006357: 39 d1                       	cmpl	%edx, %ecx
100006359: 41 89 d1                    	movl	%edx, %r9d
10000635c: 44 0f 47 c9                 	cmoval	%ecx, %r9d
100006360: 0f 43 ca                    	cmovael	%edx, %ecx
100006363: 44 39 de                    	cmpl	%r11d, %esi
100006366: 45 89 de                    	movl	%r11d, %r14d
100006369: 44 0f 47 f6                 	cmoval	%esi, %r14d
10000636d: 41 0f 43 f3                 	cmovael	%r11d, %esi
100006371: 41 39 c0                    	cmpl	%eax, %r8d
100006374: 89 c2                       	movl	%eax, %edx
100006376: 41 0f 47 d0                 	cmoval	%r8d, %edx
10000637a: 41 0f 42 c0                 	cmovbl	%r8d, %eax
10000637e: 39 cf                       	cmpl	%ecx, %edi
100006380: 41 89 c8                    	movl	%ecx, %r8d
100006383: 44 0f 47 c7                 	cmoval	%edi, %r8d
100006387: 45 89 54 24 20              	movl	%r10d, 32(%r12)
10000638c: 0f 42 cf                    	cmovbl	%edi, %ecx
10000638f: 41 89 0c 24                 	movl	%ecx, (%r12)
100006393: 39 f3                       	cmpl	%esi, %ebx
100006395: 89 f7                       	movl	%esi, %edi
100006397: 0f 47 fb                    	cmoval	%ebx, %edi
10000639a: 0f 42 f3                    	cmovbl	%ebx, %esi
10000639d: 44 39 f2                    	cmpl	%r14d, %edx
1000063a0: 45 89 f2                    	movl	%r14d, %r10d
1000063a3: 44 0f 47 d2                 	cmoval	%edx, %r10d
1000063a7: 41 0f 43 d6                 	cmovael	%r14d, %edx
1000063ab: 44 39 c8                    	cmpl	%r9d, %eax
1000063ae: 44 89 c9                    	movl	%r9d, %ecx
1000063b1: 0f 47 c8                    	cmoval	%eax, %ecx
1000063b4: 41 0f 43 c1                 	cmovael	%r9d, %eax
1000063b8: 44 39 c6                    	cmpl	%r8d, %esi
1000063bb: 44 89 c3                    	movl	%r8d, %ebx
1000063be: 0f 47 de                    	cmoval	%esi, %ebx
1000063c1: 45 89 54 24 1c              	movl	%r10d, 28(%r12)
1000063c6: 41 0f 43 f0                 	cmovael	%r8d, %esi
1000063ca: 41 89 74 24 04              	movl	%esi, 4(%r12)
1000063cf: 39 cf                       	cmpl	%ecx, %edi
1000063d1: 89 ce                       	movl	%ecx, %esi
1000063d3: 0f 47 f7                    	cmoval	%edi, %esi
1000063d6: 0f 42 cf                    	cmovbl	%edi, %ecx
1000063d9: 39 c8                       	cmpl	%ecx, %eax
1000063db: 89 cf                       	movl	%ecx, %edi
1000063dd: 0f 47 f8                    	cmoval	%eax, %edi
1000063e0: 0f 42 c8                    	cmovbl	%eax, %ecx
1000063e3: 41 89 7c 24 10              	movl	%edi, 16(%r12)
1000063e8: 39 f2                       	cmpl	%esi, %edx
1000063ea: 89 f0                       	movl	%esi, %eax
1000063ec: 0f 47 c2                    	cmoval	%edx, %eax
1000063ef: 0f 42 f2                    	cmovbl	%edx, %esi
1000063f2: 41 89 74 24 14              	movl	%esi, 20(%r12)
1000063f7: 41 89 44 24 18              	movl	%eax, 24(%r12)
1000063fc: 39 d9                       	cmpl	%ebx, %ecx
1000063fe: 89 d8                       	movl	%ebx, %eax
100006400: 0f 47 c1                    	cmoval	%ecx, %eax
100006403: 0f 43 cb                    	cmovael	%ebx, %ecx
100006406: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
10000640b: 41 89 44 24 0c              	movl	%eax, 12(%r12)
100006410: e9 c8 14 00 00              	jmp	5320 <_test_quick_sort_recursive+0x1ccd>
100006415: 41 8b 44 24 10              	movl	16(%r12), %eax
10000641a: 41 8b 4c 24 24              	movl	36(%r12), %ecx
10000641f: 39 c8                       	cmpl	%ecx, %eax
100006421: 41 89 c9                    	movl	%ecx, %r9d
100006424: 44 0f 47 c8                 	cmoval	%eax, %r9d
100006428: 0f 42 c8                    	cmovbl	%eax, %ecx
10000642b: 41 8b 54 24 0c              	movl	12(%r12), %edx
100006430: 45 8b 7c 24 20              	movl	32(%r12), %r15d
100006435: 44 39 fa                    	cmpl	%r15d, %edx
100006438: 45 89 fb                    	movl	%r15d, %r11d
10000643b: 44 0f 47 da                 	cmoval	%edx, %r11d
10000643f: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100006443: 41 8b 54 24 08              	movl	8(%r12), %edx
100006448: 45 8b 74 24 1c              	movl	28(%r12), %r14d
10000644d: 44 39 f2                    	cmpl	%r14d, %edx
100006450: 45 89 f0                    	movl	%r14d, %r8d
100006453: 44 0f 47 c2                 	cmoval	%edx, %r8d
100006457: 44 0f 42 f2                 	cmovbl	%edx, %r14d
10000645b: 41 8b 74 24 04              	movl	4(%r12), %esi
100006460: 41 8b 7c 24 18              	movl	24(%r12), %edi
100006465: 39 fe                       	cmpl	%edi, %esi
100006467: 89 fa                       	movl	%edi, %edx
100006469: 0f 47 d6                    	cmoval	%esi, %edx
10000646c: 41 8b 04 24                 	movl	(%r12), %eax
100006470: 0f 42 fe                    	cmovbl	%esi, %edi
100006473: 41 8b 5c 24 14              	movl	20(%r12), %ebx
100006478: 39 d8                       	cmpl	%ebx, %eax
10000647a: 89 de                       	movl	%ebx, %esi
10000647c: 0f 47 f0                    	cmoval	%eax, %esi
10000647f: 0f 42 d8                    	cmovbl	%eax, %ebx
100006482: 39 cf                       	cmpl	%ecx, %edi
100006484: 41 89 ca                    	movl	%ecx, %r10d
100006487: 44 0f 47 d7                 	cmoval	%edi, %r10d
10000648b: 0f 43 f9                    	cmovael	%ecx, %edi
10000648e: 44 39 ca                    	cmpl	%r9d, %edx
100006491: 44 89 c9                    	movl	%r9d, %ecx
100006494: 0f 47 ca                    	cmoval	%edx, %ecx
100006497: 41 0f 43 d1                 	cmovael	%r9d, %edx
10000649b: 44 39 fb                    	cmpl	%r15d, %ebx
10000649e: 45 89 f9                    	movl	%r15d, %r9d
1000064a1: 44 0f 47 cb                 	cmoval	%ebx, %r9d
1000064a5: 41 0f 43 df                 	cmovael	%r15d, %ebx
1000064a9: 44 39 de                    	cmpl	%r11d, %esi
1000064ac: 45 89 df                    	movl	%r11d, %r15d
1000064af: 44 0f 47 fe                 	cmoval	%esi, %r15d
1000064b3: 41 0f 43 f3                 	cmovael	%r11d, %esi
1000064b7: 44 39 f3                    	cmpl	%r14d, %ebx
1000064ba: 44 89 f0                    	movl	%r14d, %eax
1000064bd: 0f 47 c3                    	cmoval	%ebx, %eax
1000064c0: 41 0f 43 de                 	cmovael	%r14d, %ebx
1000064c4: 41 39 d1                    	cmpl	%edx, %r9d
1000064c7: 41 89 d3                    	movl	%edx, %r11d
1000064ca: 45 0f 47 d9                 	cmoval	%r9d, %r11d
1000064ce: 44 0f 43 ca                 	cmovael	%edx, %r9d
1000064d2: 41 39 c8                    	cmpl	%ecx, %r8d
1000064d5: 89 ca                       	movl	%ecx, %edx
1000064d7: 41 0f 47 d0                 	cmoval	%r8d, %edx
1000064db: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
1000064df: 39 fb                       	cmpl	%edi, %ebx
1000064e1: 41 89 f8                    	movl	%edi, %r8d
1000064e4: 44 0f 47 c3                 	cmoval	%ebx, %r8d
1000064e8: 0f 43 df                    	cmovael	%edi, %ebx
1000064eb: 41 89 1c 24                 	movl	%ebx, (%r12)
1000064ef: 44 39 d0                    	cmpl	%r10d, %eax
1000064f2: 45 89 d5                    	movl	%r10d, %r13d
1000064f5: 44 0f 47 e8                 	cmoval	%eax, %r13d
1000064f9: 41 0f 43 c2                 	cmovael	%r10d, %eax
1000064fd: 39 ce                       	cmpl	%ecx, %esi
1000064ff: 41 89 ca                    	movl	%ecx, %r10d
100006502: 44 0f 47 d6                 	cmoval	%esi, %r10d
100006506: 0f 42 ce                    	cmovbl	%esi, %ecx
100006509: 41 39 d7                    	cmpl	%edx, %r15d
10000650c: 41 89 d6                    	movl	%edx, %r14d
10000650f: 45 0f 47 f7                 	cmoval	%r15d, %r14d
100006513: 41 0f 42 d7                 	cmovbl	%r15d, %edx
100006517: 41 39 c0                    	cmpl	%eax, %r8d
10000651a: 41 89 c7                    	movl	%eax, %r15d
10000651d: 45 0f 47 f8                 	cmoval	%r8d, %r15d
100006521: 41 0f 42 c0                 	cmovbl	%r8d, %eax
100006525: 45 39 dd                    	cmpl	%r11d, %r13d
100006528: 44 89 df                    	movl	%r11d, %edi
10000652b: 41 0f 47 fd                 	cmoval	%r13d, %edi
10000652f: 45 0f 43 eb                 	cmovael	%r11d, %r13d
100006533: 41 39 d2                    	cmpl	%edx, %r10d
100006536: 41 89 d3                    	movl	%edx, %r11d
100006539: 45 0f 47 da                 	cmoval	%r10d, %r11d
10000653d: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100006541: 41 39 c9                    	cmpl	%ecx, %r9d
100006544: 89 ce                       	movl	%ecx, %esi
100006546: 41 0f 47 f1                 	cmoval	%r9d, %esi
10000654a: 41 0f 42 c9                 	cmovbl	%r9d, %ecx
10000654e: 41 39 f7                    	cmpl	%esi, %r15d
100006551: 41 89 f0                    	movl	%esi, %r8d
100006554: 45 0f 47 c7                 	cmoval	%r15d, %r8d
100006558: 45 89 74 24 24              	movl	%r14d, 36(%r12)
10000655d: 41 0f 42 f7                 	cmovbl	%r15d, %esi
100006561: 44 39 df                    	cmpl	%r11d, %edi
100006564: 45 89 d9                    	movl	%r11d, %r9d
100006567: 44 0f 47 cf                 	cmoval	%edi, %r9d
10000656b: 44 0f 42 df                 	cmovbl	%edi, %r11d
10000656f: 45 89 4c 24 20              	movl	%r9d, 32(%r12)
100006574: 39 c8                       	cmpl	%ecx, %eax
100006576: 89 cf                       	movl	%ecx, %edi
100006578: 0f 47 f8                    	cmoval	%eax, %edi
10000657b: 0f 42 c8                    	cmovbl	%eax, %ecx
10000657e: 41 39 d5                    	cmpl	%edx, %r13d
100006581: 89 d0                       	movl	%edx, %eax
100006583: 41 0f 47 c5                 	cmoval	%r13d, %eax
100006587: 41 0f 42 d5                 	cmovbl	%r13d, %edx
10000658b: 39 fe                       	cmpl	%edi, %esi
10000658d: 89 fb                       	movl	%edi, %ebx
10000658f: 0f 47 de                    	cmoval	%esi, %ebx
100006592: 41 89 4c 24 04              	movl	%ecx, 4(%r12)
100006597: 0f 42 fe                    	cmovbl	%esi, %edi
10000659a: 41 89 7c 24 08              	movl	%edi, 8(%r12)
10000659f: 41 39 c3                    	cmpl	%eax, %r11d
1000065a2: 89 c1                       	movl	%eax, %ecx
1000065a4: 41 0f 47 cb                 	cmoval	%r11d, %ecx
1000065a8: 41 0f 42 c3                 	cmovbl	%r11d, %eax
1000065ac: 41 89 4c 24 1c              	movl	%ecx, 28(%r12)
1000065b1: 39 d3                       	cmpl	%edx, %ebx
1000065b3: 89 d1                       	movl	%edx, %ecx
1000065b5: 0f 47 cb                    	cmoval	%ebx, %ecx
1000065b8: 0f 43 da                    	cmovael	%edx, %ebx
1000065bb: 41 89 5c 24 0c              	movl	%ebx, 12(%r12)
1000065c0: 41 39 c0                    	cmpl	%eax, %r8d
1000065c3: 89 c2                       	movl	%eax, %edx
1000065c5: 41 0f 47 d0                 	cmoval	%r8d, %edx
1000065c9: 41 0f 42 c0                 	cmovbl	%r8d, %eax
1000065cd: 41 89 54 24 18              	movl	%edx, 24(%r12)
1000065d2: 39 c1                       	cmpl	%eax, %ecx
1000065d4: 89 c2                       	movl	%eax, %edx
1000065d6: 0f 47 d1                    	cmoval	%ecx, %edx
1000065d9: 0f 42 c1                    	cmovbl	%ecx, %eax
1000065dc: 41 89 44 24 10              	movl	%eax, 16(%r12)
1000065e1: 41 89 54 24 14              	movl	%edx, 20(%r12)
1000065e6: e9 f2 12 00 00              	jmp	4850 <_test_quick_sort_recursive+0x1ccd>
1000065eb: 41 8b 0c 24                 	movl	(%r12), %ecx
1000065ef: 41 8b 44 24 04              	movl	4(%r12), %eax
1000065f4: 39 c1                       	cmpl	%eax, %ecx
1000065f6: 41 89 c1                    	movl	%eax, %r9d
1000065f9: 44 0f 47 c9                 	cmoval	%ecx, %r9d
1000065fd: 0f 42 c1                    	cmovbl	%ecx, %eax
100006600: 41 8b 4c 24 08              	movl	8(%r12), %ecx
100006605: 45 8b 6c 24 0c              	movl	12(%r12), %r13d
10000660a: 44 39 e9                    	cmpl	%r13d, %ecx
10000660d: 44 89 ea                    	movl	%r13d, %edx
100006610: 0f 47 d1                    	cmoval	%ecx, %edx
100006613: 44 0f 42 e9                 	cmovbl	%ecx, %r13d
100006617: 41 8b 7c 24 10              	movl	16(%r12), %edi
10000661c: 41 8b 4c 24 14              	movl	20(%r12), %ecx
100006621: 39 cf                       	cmpl	%ecx, %edi
100006623: 89 cb                       	movl	%ecx, %ebx
100006625: 0f 47 df                    	cmoval	%edi, %ebx
100006628: 0f 42 cf                    	cmovbl	%edi, %ecx
10000662b: 41 8b 74 24 18              	movl	24(%r12), %esi
100006630: 45 8b 7c 24 1c              	movl	28(%r12), %r15d
100006635: 44 39 fe                    	cmpl	%r15d, %esi
100006638: 44 89 ff                    	movl	%r15d, %edi
10000663b: 0f 47 fe                    	cmoval	%esi, %edi
10000663e: 44 0f 42 fe                 	cmovbl	%esi, %r15d
100006642: 41 8b 74 24 20              	movl	32(%r12), %esi
100006647: 45 8b 54 24 24              	movl	36(%r12), %r10d
10000664c: 44 39 d6                    	cmpl	%r10d, %esi
10000664f: 45 89 d3                    	movl	%r10d, %r11d
100006652: 44 0f 47 de                 	cmoval	%esi, %r11d
100006656: 44 0f 42 d6                 	cmovbl	%esi, %r10d
10000665a: 41 39 d1                    	cmpl	%edx, %r9d
10000665d: 89 d6                       	movl	%edx, %esi
10000665f: 41 0f 47 f1                 	cmoval	%r9d, %esi
100006663: 89 75 d0                    	movl	%esi, -48(%rbp)
100006666: 41 0f 42 d1                 	cmovbl	%r9d, %edx
10000666a: 39 fb                       	cmpl	%edi, %ebx
10000666c: 41 89 f9                    	movl	%edi, %r9d
10000666f: 44 0f 47 cb                 	cmoval	%ebx, %r9d
100006673: 0f 42 fb                    	cmovbl	%ebx, %edi
100006676: 44 39 e8                    	cmpl	%r13d, %eax
100006679: 44 89 ee                    	movl	%r13d, %esi
10000667c: 0f 47 f0                    	cmoval	%eax, %esi
10000667f: 44 0f 42 e8                 	cmovbl	%eax, %r13d
100006683: 44 39 f9                    	cmpl	%r15d, %ecx
100006686: 44 89 f8                    	movl	%r15d, %eax
100006689: 0f 47 c1                    	cmoval	%ecx, %eax
10000668c: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
100006690: 41 8b 5c 24 28              	movl	40(%r12), %ebx
100006695: 41 39 da                    	cmpl	%ebx, %r10d
100006698: 89 d9                       	movl	%ebx, %ecx
10000669a: 41 0f 47 ca                 	cmoval	%r10d, %ecx
10000669e: 44 0f 43 d3                 	cmovael	%ebx, %r10d
1000066a2: 39 f2                       	cmpl	%esi, %edx
1000066a4: 41 89 f6                    	movl	%esi, %r14d
1000066a7: 44 0f 47 f2                 	cmoval	%edx, %r14d
1000066ab: 0f 42 f2                    	cmovbl	%edx, %esi
1000066ae: 39 c7                       	cmpl	%eax, %edi
1000066b0: 41 89 c0                    	movl	%eax, %r8d
1000066b3: 44 0f 47 c7                 	cmoval	%edi, %r8d
1000066b7: 0f 42 c7                    	cmovbl	%edi, %eax
1000066ba: 41 39 cb                    	cmpl	%ecx, %r11d
1000066bd: 89 cb                       	movl	%ecx, %ebx
1000066bf: 41 0f 47 db                 	cmoval	%r11d, %ebx
1000066c3: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
1000066c7: 45 39 fd                    	cmpl	%r15d, %r13d
1000066ca: 44 89 ff                    	movl	%r15d, %edi
1000066cd: 41 0f 47 fd                 	cmoval	%r13d, %edi
1000066d1: 45 0f 42 fd                 	cmovbl	%r13d, %r15d
1000066d5: 44 8b 5d d0                 	movl	-48(%rbp), %r11d
1000066d9: 45 39 cb                    	cmpl	%r9d, %r11d
1000066dc: 44 89 ca                    	movl	%r9d, %edx
1000066df: 41 0f 47 d3                 	cmoval	%r11d, %edx
1000066e3: 89 55 d4                    	movl	%edx, -44(%rbp)
1000066e6: 45 0f 42 cb                 	cmovbl	%r11d, %r9d
1000066ea: 39 c6                       	cmpl	%eax, %esi
1000066ec: 89 c2                       	movl	%eax, %edx
1000066ee: 0f 47 d6                    	cmoval	%esi, %edx
1000066f1: 0f 42 c6                    	cmovbl	%esi, %eax
1000066f4: 41 39 d8                    	cmpl	%ebx, %r8d
1000066f7: 41 89 db                    	movl	%ebx, %r11d
1000066fa: 45 0f 47 d8                 	cmoval	%r8d, %r11d
1000066fe: 41 0f 42 d8                 	cmovbl	%r8d, %ebx
100006702: 44 39 d7                    	cmpl	%r10d, %edi
100006705: 44 89 d6                    	movl	%r10d, %esi
100006708: 0f 47 f7                    	cmoval	%edi, %esi
10000670b: 41 0f 43 fa                 	cmovael	%r10d, %edi
10000670f: 39 ca                       	cmpl	%ecx, %edx
100006711: 41 89 cd                    	movl	%ecx, %r13d
100006714: 44 0f 47 ea                 	cmoval	%edx, %r13d
100006718: 0f 43 d1                    	cmovael	%ecx, %edx
10000671b: 41 39 de                    	cmpl	%ebx, %r14d
10000671e: 41 89 da                    	movl	%ebx, %r10d
100006721: 45 0f 47 d6                 	cmoval	%r14d, %r10d
100006725: 41 0f 42 de                 	cmovbl	%r14d, %ebx
100006729: 41 39 ff                    	cmpl	%edi, %r15d
10000672c: 41 89 f8                    	movl	%edi, %r8d
10000672f: 45 0f 47 c7                 	cmoval	%r15d, %r8d
100006733: 41 0f 42 ff                 	cmovbl	%r15d, %edi
100006737: 41 39 f1                    	cmpl	%esi, %r9d
10000673a: 89 f1                       	movl	%esi, %ecx
10000673c: 41 0f 47 c9                 	cmoval	%r9d, %ecx
100006740: 41 0f 42 f1                 	cmovbl	%r9d, %esi
100006744: 39 d0                       	cmpl	%edx, %eax
100006746: 41 89 d6                    	movl	%edx, %r14d
100006749: 44 0f 47 f0                 	cmoval	%eax, %r14d
10000674d: 0f 42 d0                    	cmovbl	%eax, %edx
100006750: 45 39 da                    	cmpl	%r11d, %r10d
100006753: 44 89 d8                    	movl	%r11d, %eax
100006756: 41 0f 47 c2                 	cmoval	%r10d, %eax
10000675a: 45 0f 43 d3                 	cmovael	%r11d, %r10d
10000675e: 39 f3                       	cmpl	%esi, %ebx
100006760: 41 89 f1                    	movl	%esi, %r9d
100006763: 44 0f 47 cb                 	cmoval	%ebx, %r9d
100006767: 0f 42 f3                    	cmovbl	%ebx, %esi
10000676a: 44 39 e9                    	cmpl	%r13d, %ecx
10000676d: 45 89 eb                    	movl	%r13d, %r11d
100006770: 44 0f 47 d9                 	cmoval	%ecx, %r11d
100006774: 41 89 3c 24                 	movl	%edi, (%r12)
100006778: 41 0f 43 cd                 	cmovael	%r13d, %ecx
10000677c: 44 39 c2                    	cmpl	%r8d, %edx
10000677f: 44 89 c3                    	movl	%r8d, %ebx
100006782: 0f 47 da                    	cmoval	%edx, %ebx
100006785: 41 0f 43 d0                 	cmovael	%r8d, %edx
100006789: 41 89 54 24 04              	movl	%edx, 4(%r12)
10000678e: 8b 55 d4                    	movl	-44(%rbp), %edx
100006791: 39 c2                       	cmpl	%eax, %edx
100006793: 89 c7                       	movl	%eax, %edi
100006795: 0f 47 fa                    	cmoval	%edx, %edi
100006798: 0f 42 c2                    	cmovbl	%edx, %eax
10000679b: 45 39 f1                    	cmpl	%r14d, %r9d
10000679e: 44 89 f2                    	movl	%r14d, %edx
1000067a1: 41 0f 47 d1                 	cmoval	%r9d, %edx
1000067a5: 45 0f 43 ce                 	cmovael	%r14d, %r9d
1000067a9: 41 39 ca                    	cmpl	%ecx, %r10d
1000067ac: 41 89 c8                    	movl	%ecx, %r8d
1000067af: 45 0f 47 c2                 	cmoval	%r10d, %r8d
1000067b3: 41 89 7c 24 28              	movl	%edi, 40(%r12)
1000067b8: 41 0f 42 ca                 	cmovbl	%r10d, %ecx
1000067bc: 39 de                       	cmpl	%ebx, %esi
1000067be: 89 df                       	movl	%ebx, %edi
1000067c0: 0f 47 fe                    	cmoval	%esi, %edi
1000067c3: 0f 42 de                    	cmovbl	%esi, %ebx
1000067c6: 41 89 5c 24 08              	movl	%ebx, 8(%r12)
1000067cb: 44 39 d8                    	cmpl	%r11d, %eax
1000067ce: 44 89 de                    	movl	%r11d, %esi
1000067d1: 0f 47 f0                    	cmoval	%eax, %esi
1000067d4: 41 0f 43 c3                 	cmovael	%r11d, %eax
1000067d8: 41 89 74 24 24              	movl	%esi, 36(%r12)
1000067dd: 39 ca                       	cmpl	%ecx, %edx
1000067df: 89 ce                       	movl	%ecx, %esi
1000067e1: 0f 47 f2                    	cmoval	%edx, %esi
1000067e4: 0f 42 ca                    	cmovbl	%edx, %ecx
1000067e7: 41 89 4c 24 14              	movl	%ecx, 20(%r12)
1000067ec: 41 89 74 24 18              	movl	%esi, 24(%r12)
1000067f1: 41 39 f9                    	cmpl	%edi, %r9d
1000067f4: 89 f9                       	movl	%edi, %ecx
1000067f6: 41 0f 47 c9                 	cmoval	%r9d, %ecx
1000067fa: 41 0f 42 f9                 	cmovbl	%r9d, %edi
1000067fe: 41 89 7c 24 0c              	movl	%edi, 12(%r12)
100006803: 41 89 4c 24 10              	movl	%ecx, 16(%r12)
100006808: e9 64 02 00 00              	jmp	612 <_test_quick_sort_recursive+0xe61>
10000680d: 41 8b 04 24                 	movl	(%r12), %eax
100006811: 41 8b 4c 24 04              	movl	4(%r12), %ecx
100006816: 39 c8                       	cmpl	%ecx, %eax
100006818: 41 89 ca                    	movl	%ecx, %r10d
10000681b: 44 0f 47 d0                 	cmoval	%eax, %r10d
10000681f: 0f 42 c8                    	cmovbl	%eax, %ecx
100006822: 41 8b 44 24 08              	movl	8(%r12), %eax
100006827: 45 8b 74 24 0c              	movl	12(%r12), %r14d
10000682c: 44 39 f0                    	cmpl	%r14d, %eax
10000682f: 45 89 f3                    	movl	%r14d, %r11d
100006832: 44 0f 47 d8                 	cmoval	%eax, %r11d
100006836: 44 0f 42 f0                 	cmovbl	%eax, %r14d
10000683a: 41 8b 74 24 10              	movl	16(%r12), %esi
10000683f: 41 8b 44 24 14              	movl	20(%r12), %eax
100006844: 39 c6                       	cmpl	%eax, %esi
100006846: 41 89 c7                    	movl	%eax, %r15d
100006849: 44 0f 47 fe                 	cmoval	%esi, %r15d
10000684d: 0f 42 c6                    	cmovbl	%esi, %eax
100006850: 41 8b 74 24 18              	movl	24(%r12), %esi
100006855: 45 8b 44 24 1c              	movl	28(%r12), %r8d
10000685a: 44 39 c6                    	cmpl	%r8d, %esi
10000685d: 44 89 c7                    	movl	%r8d, %edi
100006860: 0f 47 fe                    	cmoval	%esi, %edi
100006863: 44 0f 42 c6                 	cmovbl	%esi, %r8d
100006867: 41 8b 74 24 20              	movl	32(%r12), %esi
10000686c: 45 8b 6c 24 24              	movl	36(%r12), %r13d
100006871: 44 39 ee                    	cmpl	%r13d, %esi
100006874: 44 89 eb                    	movl	%r13d, %ebx
100006877: 0f 47 de                    	cmoval	%esi, %ebx
10000687a: 44 0f 42 ee                 	cmovbl	%esi, %r13d
10000687e: 41 8b 54 24 28              	movl	40(%r12), %edx
100006883: 45 8b 4c 24 2c              	movl	44(%r12), %r9d
100006888: 44 39 ca                    	cmpl	%r9d, %edx
10000688b: 44 89 ce                    	movl	%r9d, %esi
10000688e: 0f 47 f2                    	cmoval	%edx, %esi
100006891: 44 0f 42 ca                 	cmovbl	%edx, %r9d
100006895: 45 39 da                    	cmpl	%r11d, %r10d
100006898: 44 89 da                    	movl	%r11d, %edx
10000689b: 41 0f 47 d2                 	cmoval	%r10d, %edx
10000689f: 89 55 d4                    	movl	%edx, -44(%rbp)
1000068a2: 45 0f 42 da                 	cmovbl	%r10d, %r11d
1000068a6: 41 39 ff                    	cmpl	%edi, %r15d
1000068a9: 41 89 fa                    	movl	%edi, %r10d
1000068ac: 45 0f 47 d7                 	cmoval	%r15d, %r10d
1000068b0: 41 0f 42 ff                 	cmovbl	%r15d, %edi
1000068b4: 39 f3                       	cmpl	%esi, %ebx
1000068b6: 41 89 f7                    	movl	%esi, %r15d
1000068b9: 44 0f 47 fb                 	cmoval	%ebx, %r15d
1000068bd: 0f 42 f3                    	cmovbl	%ebx, %esi
1000068c0: 44 39 f1                    	cmpl	%r14d, %ecx
1000068c3: 44 89 f2                    	movl	%r14d, %edx
1000068c6: 0f 47 d1                    	cmoval	%ecx, %edx
1000068c9: 44 0f 42 f1                 	cmovbl	%ecx, %r14d
1000068cd: 44 39 c0                    	cmpl	%r8d, %eax
1000068d0: 44 89 c1                    	movl	%r8d, %ecx
1000068d3: 0f 47 c8                    	cmoval	%eax, %ecx
1000068d6: 44 0f 42 c0                 	cmovbl	%eax, %r8d
1000068da: 45 39 cd                    	cmpl	%r9d, %r13d
1000068dd: 44 89 c8                    	movl	%r9d, %eax
1000068e0: 41 0f 47 c5                 	cmoval	%r13d, %eax
1000068e4: 45 0f 42 cd                 	cmovbl	%r13d, %r9d
1000068e8: 41 39 d3                    	cmpl	%edx, %r11d
1000068eb: 89 d3                       	movl	%edx, %ebx
1000068ed: 41 0f 47 db                 	cmoval	%r11d, %ebx
1000068f1: 89 5d d0                    	movl	%ebx, -48(%rbp)
1000068f4: 41 0f 42 d3                 	cmovbl	%r11d, %edx
1000068f8: 39 cf                       	cmpl	%ecx, %edi
1000068fa: 41 89 cd                    	movl	%ecx, %r13d
1000068fd: 44 0f 47 ef                 	cmoval	%edi, %r13d
100006901: 0f 42 cf                    	cmovbl	%edi, %ecx
100006904: 39 c6                       	cmpl	%eax, %esi
100006906: 89 c3                       	movl	%eax, %ebx
100006908: 0f 47 de                    	cmoval	%esi, %ebx
10000690b: 0f 42 c6                    	cmovbl	%esi, %eax
10000690e: 45 39 c6                    	cmpl	%r8d, %r14d
100006911: 45 89 c3                    	movl	%r8d, %r11d
100006914: 45 0f 47 de                 	cmoval	%r14d, %r11d
100006918: 45 0f 42 c6                 	cmovbl	%r14d, %r8d
10000691c: 45 39 fa                    	cmpl	%r15d, %r10d
10000691f: 44 89 ff                    	movl	%r15d, %edi
100006922: 41 0f 47 fa                 	cmoval	%r10d, %edi
100006926: 45 0f 42 fa                 	cmovbl	%r10d, %r15d
10000692a: 39 ca                       	cmpl	%ecx, %edx
10000692c: 89 ce                       	movl	%ecx, %esi
10000692e: 0f 47 f2                    	cmoval	%edx, %esi
100006931: 0f 42 ca                    	cmovbl	%edx, %ecx
100006934: 41 39 dd                    	cmpl	%ebx, %r13d
100006937: 89 da                       	movl	%ebx, %edx
100006939: 41 0f 47 d5                 	cmoval	%r13d, %edx
10000693d: 89 55 cc                    	movl	%edx, -52(%rbp)
100006940: 41 0f 42 dd                 	cmovbl	%r13d, %ebx
100006944: 8b 55 d4                    	movl	-44(%rbp), %edx
100006947: 44 39 fa                    	cmpl	%r15d, %edx
10000694a: 45 89 fa                    	movl	%r15d, %r10d
10000694d: 44 0f 47 d2                 	cmoval	%edx, %r10d
100006951: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100006955: 45 39 cb                    	cmpl	%r9d, %r11d
100006958: 44 89 ca                    	movl	%r9d, %edx
10000695b: 41 0f 47 d3                 	cmoval	%r11d, %edx
10000695f: 45 0f 43 d9                 	cmovael	%r9d, %r11d
100006963: 39 c6                       	cmpl	%eax, %esi
100006965: 41 89 c5                    	movl	%eax, %r13d
100006968: 44 0f 47 ee                 	cmoval	%esi, %r13d
10000696c: 0f 43 f0                    	cmovael	%eax, %esi
10000696f: 8b 45 d0                    	movl	-48(%rbp), %eax
100006972: 39 d8                       	cmpl	%ebx, %eax
100006974: 41 89 d9                    	movl	%ebx, %r9d
100006977: 44 0f 47 c8                 	cmoval	%eax, %r9d
10000697b: 0f 42 d8                    	cmovbl	%eax, %ebx
10000697e: 45 39 d8                    	cmpl	%r11d, %r8d
100006981: 45 89 de                    	movl	%r11d, %r14d
100006984: 45 0f 47 f0                 	cmoval	%r8d, %r14d
100006988: 45 0f 42 d8                 	cmovbl	%r8d, %r11d
10000698c: 45 89 1c 24                 	movl	%r11d, (%r12)
100006990: 41 39 fa                    	cmpl	%edi, %r10d
100006993: 41 89 fb                    	movl	%edi, %r11d
100006996: 45 0f 47 da                 	cmoval	%r10d, %r11d
10000699a: 44 0f 43 d7                 	cmovael	%edi, %r10d
10000699e: 41 39 d7                    	cmpl	%edx, %r15d
1000069a1: 89 d7                       	movl	%edx, %edi
1000069a3: 41 0f 47 ff                 	cmoval	%r15d, %edi
1000069a7: 41 0f 42 d7                 	cmovbl	%r15d, %edx
1000069ab: 39 f1                       	cmpl	%esi, %ecx
1000069ad: 41 89 f0                    	movl	%esi, %r8d
1000069b0: 44 0f 47 c1                 	cmoval	%ecx, %r8d
1000069b4: 0f 42 f1                    	cmovbl	%ecx, %esi
1000069b7: 8b 4d cc                    	movl	-52(%rbp), %ecx
1000069ba: 41 39 c9                    	cmpl	%ecx, %r9d
1000069bd: 89 c8                       	movl	%ecx, %eax
1000069bf: 41 0f 47 c1                 	cmoval	%r9d, %eax
1000069c3: 44 0f 43 c9                 	cmovael	%ecx, %r9d
1000069c7: 39 d3                       	cmpl	%edx, %ebx
1000069c9: 89 d1                       	movl	%edx, %ecx
1000069cb: 0f 47 cb                    	cmoval	%ebx, %ecx
1000069ce: 0f 42 d3                    	cmovbl	%ebx, %edx
1000069d1: 44 39 ef                    	cmpl	%r13d, %edi
1000069d4: 45 89 ef                    	movl	%r13d, %r15d
1000069d7: 44 0f 47 ff                 	cmoval	%edi, %r15d
1000069db: 45 89 5c 24 2c              	movl	%r11d, 44(%r12)
1000069e0: 41 0f 43 fd                 	cmovael	%r13d, %edi
1000069e4: 44 39 f6                    	cmpl	%r14d, %esi
1000069e7: 45 89 f5                    	movl	%r14d, %r13d
1000069ea: 44 0f 47 ee                 	cmoval	%esi, %r13d
1000069ee: 41 0f 43 f6                 	cmovael	%r14d, %esi
1000069f2: 41 89 74 24 04              	movl	%esi, 4(%r12)
1000069f7: 41 39 c2                    	cmpl	%eax, %r10d
1000069fa: 41 89 c3                    	movl	%eax, %r11d
1000069fd: 45 0f 47 da                 	cmoval	%r10d, %r11d
100006a01: 41 0f 42 c2                 	cmovbl	%r10d, %eax
100006a05: 44 39 c1                    	cmpl	%r8d, %ecx
100006a08: 44 89 c6                    	movl	%r8d, %esi
100006a0b: 0f 47 f1                    	cmoval	%ecx, %esi
100006a0e: 41 0f 43 c8                 	cmovael	%r8d, %ecx
100006a12: 41 39 f9                    	cmpl	%edi, %r9d
100006a15: 41 89 f8                    	movl	%edi, %r8d
100006a18: 45 0f 47 c1                 	cmoval	%r9d, %r8d
100006a1c: 45 89 5c 24 28              	movl	%r11d, 40(%r12)
100006a21: 41 0f 42 f9                 	cmovbl	%r9d, %edi
100006a25: 44 39 ea                    	cmpl	%r13d, %edx
100006a28: 44 89 eb                    	movl	%r13d, %ebx
100006a2b: 0f 47 da                    	cmoval	%edx, %ebx
100006a2e: 44 0f 42 ea                 	cmovbl	%edx, %r13d
100006a32: 45 89 6c 24 08              	movl	%r13d, 8(%r12)
100006a37: 44 39 f8                    	cmpl	%r15d, %eax
100006a3a: 44 89 fa                    	movl	%r15d, %edx
100006a3d: 0f 47 d0                    	cmoval	%eax, %edx
100006a40: 41 0f 43 c7                 	cmovael	%r15d, %eax
100006a44: 41 89 54 24 24              	movl	%edx, 36(%r12)
100006a49: 39 fe                       	cmpl	%edi, %esi
100006a4b: 89 fa                       	movl	%edi, %edx
100006a4d: 0f 47 d6                    	cmoval	%esi, %edx
100006a50: 0f 42 fe                    	cmovbl	%esi, %edi
100006a53: 41 89 7c 24 14              	movl	%edi, 20(%r12)
100006a58: 41 89 54 24 18              	movl	%edx, 24(%r12)
100006a5d: 39 d9                       	cmpl	%ebx, %ecx
100006a5f: 89 da                       	movl	%ebx, %edx
100006a61: 0f 47 d1                    	cmoval	%ecx, %edx
100006a64: 0f 42 d9                    	cmovbl	%ecx, %ebx
100006a67: 41 89 5c 24 0c              	movl	%ebx, 12(%r12)
100006a6c: 41 89 54 24 10              	movl	%edx, 16(%r12)
100006a71: 44 39 c0                    	cmpl	%r8d, %eax
100006a74: 44 89 c1                    	movl	%r8d, %ecx
100006a77: 0f 47 c8                    	cmoval	%eax, %ecx
100006a7a: 41 0f 43 c0                 	cmovael	%r8d, %eax
100006a7e: 41 89 44 24 1c              	movl	%eax, 28(%r12)
100006a83: 41 89 4c 24 20              	movl	%ecx, 32(%r12)
100006a88: e9 50 0e 00 00              	jmp	3664 <_test_quick_sort_recursive+0x1ccd>
100006a8d: 45 8b 14 24                 	movl	(%r12), %r10d
100006a91: 41 8b 44 24 04              	movl	4(%r12), %eax
100006a96: 45 8b 7c 24 1c              	movl	28(%r12), %r15d
100006a9b: 44 39 f8                    	cmpl	%r15d, %eax
100006a9e: 44 89 fe                    	movl	%r15d, %esi
100006aa1: 0f 47 f0                    	cmoval	%eax, %esi
100006aa4: 44 0f 42 f8                 	cmovbl	%eax, %r15d
100006aa8: 41 8b 4c 24 24              	movl	36(%r12), %ecx
100006aad: 45 8b 6c 24 2c              	movl	44(%r12), %r13d
100006ab2: 44 39 e9                    	cmpl	%r13d, %ecx
100006ab5: 45 89 e9                    	movl	%r13d, %r9d
100006ab8: 44 0f 47 c9                 	cmoval	%ecx, %r9d
100006abc: 44 0f 42 e9                 	cmovbl	%ecx, %r13d
100006ac0: 41 8b 54 24 0c              	movl	12(%r12), %edx
100006ac5: 41 8b 4c 24 10              	movl	16(%r12), %ecx
100006aca: 39 ca                       	cmpl	%ecx, %edx
100006acc: 41 89 ce                    	movl	%ecx, %r14d
100006acf: 44 0f 47 f2                 	cmoval	%edx, %r14d
100006ad3: 0f 42 ca                    	cmovbl	%edx, %ecx
100006ad6: 41 8b 54 24 14              	movl	20(%r12), %edx
100006adb: 41 8b 5c 24 20              	movl	32(%r12), %ebx
100006ae0: 39 da                       	cmpl	%ebx, %edx
100006ae2: 89 df                       	movl	%ebx, %edi
100006ae4: 0f 47 fa                    	cmoval	%edx, %edi
100006ae7: 0f 42 da                    	cmovbl	%edx, %ebx
100006aea: 89 5d d4                    	movl	%ebx, -44(%rbp)
100006aed: 41 8b 5c 24 30              	movl	48(%r12), %ebx
100006af2: 41 39 da                    	cmpl	%ebx, %r10d
100006af5: 41 89 d8                    	movl	%ebx, %r8d
100006af8: 45 0f 47 c2                 	cmoval	%r10d, %r8d
100006afc: 41 0f 42 da                 	cmovbl	%r10d, %ebx
100006b00: 41 8b 54 24 08              	movl	8(%r12), %edx
100006b05: 41 8b 44 24 18              	movl	24(%r12), %eax
100006b0a: 39 c2                       	cmpl	%eax, %edx
100006b0c: 41 89 c3                    	movl	%eax, %r11d
100006b0f: 44 0f 47 da                 	cmoval	%edx, %r11d
100006b13: 0f 42 c2                    	cmovbl	%edx, %eax
100006b16: 44 39 fb                    	cmpl	%r15d, %ebx
100006b19: 45 89 fa                    	movl	%r15d, %r10d
100006b1c: 44 0f 47 d3                 	cmoval	%ebx, %r10d
100006b20: 41 0f 43 df                 	cmovael	%r15d, %ebx
100006b24: 39 c8                       	cmpl	%ecx, %eax
100006b26: 89 ca                       	movl	%ecx, %edx
100006b28: 0f 47 d0                    	cmoval	%eax, %edx
100006b2b: 0f 43 c1                    	cmovael	%ecx, %eax
100006b2e: 45 39 de                    	cmpl	%r11d, %r14d
100006b31: 45 89 df                    	movl	%r11d, %r15d
100006b34: 45 0f 47 fe                 	cmoval	%r14d, %r15d
100006b38: 45 0f 42 de                 	cmovbl	%r14d, %r11d
100006b3c: 44 39 cf                    	cmpl	%r9d, %edi
100006b3f: 45 89 ce                    	movl	%r9d, %r14d
100006b42: 44 0f 47 f7                 	cmoval	%edi, %r14d
100006b46: 41 0f 43 f9                 	cmovael	%r9d, %edi
100006b4a: 44 39 c6                    	cmpl	%r8d, %esi
100006b4d: 45 89 c1                    	movl	%r8d, %r9d
100006b50: 44 0f 47 ce                 	cmoval	%esi, %r9d
100006b54: 44 0f 42 c6                 	cmovbl	%esi, %r8d
100006b58: 8b 4d d4                    	movl	-44(%rbp), %ecx
100006b5b: 44 39 e9                    	cmpl	%r13d, %ecx
100006b5e: 44 89 ee                    	movl	%r13d, %esi
100006b61: 0f 47 f1                    	cmoval	%ecx, %esi
100006b64: 89 75 cc                    	movl	%esi, -52(%rbp)
100006b67: 41 0f 43 cd                 	cmovael	%r13d, %ecx
100006b6b: 89 4d d4                    	movl	%ecx, -44(%rbp)
100006b6e: 39 c3                       	cmpl	%eax, %ebx
100006b70: 89 c1                       	movl	%eax, %ecx
100006b72: 0f 47 cb                    	cmoval	%ebx, %ecx
100006b75: 89 4d d0                    	movl	%ecx, -48(%rbp)
100006b78: 0f 42 c3                    	cmovbl	%ebx, %eax
100006b7b: 89 45 c8                    	movl	%eax, -56(%rbp)
100006b7e: 44 39 c2                    	cmpl	%r8d, %edx
100006b81: 44 89 c6                    	movl	%r8d, %esi
100006b84: 0f 47 f2                    	cmoval	%edx, %esi
100006b87: 44 0f 42 c2                 	cmovbl	%edx, %r8d
100006b8b: 41 8b 4c 24 28              	movl	40(%r12), %ecx
100006b90: 44 39 f1                    	cmpl	%r14d, %ecx
100006b93: 44 89 f2                    	movl	%r14d, %edx
100006b96: 0f 47 d1                    	cmoval	%ecx, %edx
100006b99: 44 0f 42 f1                 	cmovbl	%ecx, %r14d
100006b9d: 45 39 da                    	cmpl	%r11d, %r10d
100006ba0: 44 89 d9                    	movl	%r11d, %ecx
100006ba3: 41 0f 47 ca                 	cmoval	%r10d, %ecx
100006ba7: 45 0f 42 da                 	cmovbl	%r10d, %r11d
100006bab: 45 39 cf                    	cmpl	%r9d, %r15d
100006bae: 44 89 c8                    	movl	%r9d, %eax
100006bb1: 41 0f 47 c7                 	cmoval	%r15d, %eax
100006bb5: 45 0f 42 cf                 	cmovbl	%r15d, %r9d
100006bb9: 39 fe                       	cmpl	%edi, %esi
100006bbb: 41 89 fd                    	movl	%edi, %r13d
100006bbe: 44 0f 47 ee                 	cmoval	%esi, %r13d
100006bc2: 0f 43 f7                    	cmovael	%edi, %esi
100006bc5: 39 c2                       	cmpl	%eax, %edx
100006bc7: 89 c7                       	movl	%eax, %edi
100006bc9: 0f 47 fa                    	cmoval	%edx, %edi
100006bcc: 0f 42 c2                    	cmovbl	%edx, %eax
100006bcf: 8b 55 cc                    	movl	-52(%rbp), %edx
100006bd2: 39 d1                       	cmpl	%edx, %ecx
100006bd4: 41 89 d2                    	movl	%edx, %r10d
100006bd7: 44 0f 47 d1                 	cmoval	%ecx, %r10d
100006bdb: 0f 43 ca                    	cmovael	%edx, %ecx
100006bde: 45 39 f1                    	cmpl	%r14d, %r9d
100006be1: 44 89 f2                    	movl	%r14d, %edx
100006be4: 41 0f 47 d1                 	cmoval	%r9d, %edx
100006be8: 45 0f 43 ce                 	cmovael	%r14d, %r9d
100006bec: 41 39 c8                    	cmpl	%ecx, %r8d
100006bef: 41 89 ce                    	movl	%ecx, %r14d
100006bf2: 45 0f 47 f0                 	cmoval	%r8d, %r14d
100006bf6: 41 0f 42 c8                 	cmovbl	%r8d, %ecx
100006bfa: 44 8b 45 d4                 	movl	-44(%rbp), %r8d
100006bfe: 45 39 c8                    	cmpl	%r9d, %r8d
100006c01: 44 89 cb                    	movl	%r9d, %ebx
100006c04: 41 0f 47 d8                 	cmoval	%r8d, %ebx
100006c08: 45 0f 42 c8                 	cmovbl	%r8d, %r9d
100006c0c: 45 39 d5                    	cmpl	%r10d, %r13d
100006c0f: 45 89 d7                    	movl	%r10d, %r15d
100006c12: 45 0f 47 fd                 	cmoval	%r13d, %r15d
100006c16: 45 0f 42 d5                 	cmovbl	%r13d, %r10d
100006c1a: 39 c2                       	cmpl	%eax, %edx
100006c1c: 41 89 c5                    	movl	%eax, %r13d
100006c1f: 44 0f 47 ea                 	cmoval	%edx, %r13d
100006c23: 0f 43 d0                    	cmovael	%eax, %edx
100006c26: 41 39 f3                    	cmpl	%esi, %r11d
100006c29: 41 89 f0                    	movl	%esi, %r8d
100006c2c: 45 0f 47 c3                 	cmoval	%r11d, %r8d
100006c30: 41 89 7c 24 30              	movl	%edi, 48(%r12)
100006c35: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100006c39: 8b 7d d0                    	movl	-48(%rbp), %edi
100006c3c: 39 df                       	cmpl	%ebx, %edi
100006c3e: 41 89 db                    	movl	%ebx, %r11d
100006c41: 44 0f 47 df                 	cmoval	%edi, %r11d
100006c45: 0f 42 df                    	cmovbl	%edi, %ebx
100006c48: 45 39 ef                    	cmpl	%r13d, %r15d
100006c4b: 44 89 ef                    	movl	%r13d, %edi
100006c4e: 41 0f 47 ff                 	cmoval	%r15d, %edi
100006c52: 45 0f 42 ef                 	cmovbl	%r15d, %r13d
100006c56: 41 89 7c 24 2c              	movl	%edi, 44(%r12)
100006c5b: 39 ce                       	cmpl	%ecx, %esi
100006c5d: 89 cf                       	movl	%ecx, %edi
100006c5f: 0f 47 fe                    	cmoval	%esi, %edi
100006c62: 89 7d d4                    	movl	%edi, -44(%rbp)
100006c65: 0f 43 f1                    	cmovael	%ecx, %esi
100006c68: 45 39 c6                    	cmpl	%r8d, %r14d
100006c6b: 45 89 c7                    	movl	%r8d, %r15d
100006c6e: 45 0f 47 fe                 	cmoval	%r14d, %r15d
100006c72: 45 0f 42 c6                 	cmovbl	%r14d, %r8d
100006c76: 41 39 d2                    	cmpl	%edx, %r10d
100006c79: 41 89 d6                    	movl	%edx, %r14d
100006c7c: 45 0f 47 f2                 	cmoval	%r10d, %r14d
100006c80: 41 0f 42 d2                 	cmovbl	%r10d, %edx
100006c84: 8b 45 c8                    	movl	-56(%rbp), %eax
100006c87: 44 39 c8                    	cmpl	%r9d, %eax
100006c8a: 44 89 cf                    	movl	%r9d, %edi
100006c8d: 0f 47 f8                    	cmoval	%eax, %edi
100006c90: 44 0f 42 c8                 	cmovbl	%eax, %r9d
100006c94: 39 fb                       	cmpl	%edi, %ebx
100006c96: 89 f9                       	movl	%edi, %ecx
100006c98: 0f 47 cb                    	cmoval	%ebx, %ecx
100006c9b: 45 89 0c 24                 	movl	%r9d, (%r12)
100006c9f: 0f 42 fb                    	cmovbl	%ebx, %edi
100006ca2: 41 39 d3                    	cmpl	%edx, %r11d
100006ca5: 89 d3                       	movl	%edx, %ebx
100006ca7: 41 0f 47 db                 	cmoval	%r11d, %ebx
100006cab: 41 0f 42 d3                 	cmovbl	%r11d, %edx
100006caf: 45 39 f5                    	cmpl	%r14d, %r13d
100006cb2: 44 89 f0                    	movl	%r14d, %eax
100006cb5: 41 0f 47 c5                 	cmoval	%r13d, %eax
100006cb9: 45 0f 42 f5                 	cmovbl	%r13d, %r14d
100006cbd: 41 89 44 24 28              	movl	%eax, 40(%r12)
100006cc2: 39 fe                       	cmpl	%edi, %esi
100006cc4: 41 89 fa                    	movl	%edi, %r10d
100006cc7: 44 0f 47 d6                 	cmoval	%esi, %r10d
100006ccb: 0f 42 fe                    	cmovbl	%esi, %edi
100006cce: 8b 45 d4                    	movl	-44(%rbp), %eax
100006cd1: 39 c8                       	cmpl	%ecx, %eax
100006cd3: 41 89 c9                    	movl	%ecx, %r9d
100006cd6: 44 0f 47 c8                 	cmoval	%eax, %r9d
100006cda: 0f 42 c8                    	cmovbl	%eax, %ecx
100006cdd: 41 39 df                    	cmpl	%ebx, %r15d
100006ce0: 89 d8                       	movl	%ebx, %eax
100006ce2: 41 0f 47 c7                 	cmoval	%r15d, %eax
100006ce6: 41 0f 42 df                 	cmovbl	%r15d, %ebx
100006cea: 41 39 d0                    	cmpl	%edx, %r8d
100006ced: 89 d6                       	movl	%edx, %esi
100006cef: 41 0f 47 f0                 	cmoval	%r8d, %esi
100006cf3: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100006cf7: 41 39 ca                    	cmpl	%ecx, %r10d
100006cfa: 41 89 c8                    	movl	%ecx, %r8d
100006cfd: 45 0f 47 c2                 	cmoval	%r10d, %r8d
100006d01: 41 89 7c 24 04              	movl	%edi, 4(%r12)
100006d06: 41 0f 42 ca                 	cmovbl	%r10d, %ecx
100006d0a: 41 89 4c 24 08              	movl	%ecx, 8(%r12)
100006d0f: 44 39 ca                    	cmpl	%r9d, %edx
100006d12: 44 89 c9                    	movl	%r9d, %ecx
100006d15: 0f 47 ca                    	cmoval	%edx, %ecx
100006d18: 41 0f 43 d1                 	cmovael	%r9d, %edx
100006d1c: 39 de                       	cmpl	%ebx, %esi
100006d1e: 89 df                       	movl	%ebx, %edi
100006d20: 0f 47 fe                    	cmoval	%esi, %edi
100006d23: 0f 43 f3                    	cmovael	%ebx, %esi
100006d26: 41 89 7c 24 1c              	movl	%edi, 28(%r12)
100006d2b: 44 39 f0                    	cmpl	%r14d, %eax
100006d2e: 44 89 f7                    	movl	%r14d, %edi
100006d31: 0f 47 f8                    	cmoval	%eax, %edi
100006d34: 41 0f 43 c6                 	cmovael	%r14d, %eax
100006d38: 41 89 44 24 20              	movl	%eax, 32(%r12)
100006d3d: 41 89 7c 24 24              	movl	%edi, 36(%r12)
100006d42: 41 39 d0                    	cmpl	%edx, %r8d
100006d45: 89 d0                       	movl	%edx, %eax
100006d47: 41 0f 47 c0                 	cmoval	%r8d, %eax
100006d4b: 41 0f 42 d0                 	cmovbl	%r8d, %edx
100006d4f: 41 89 54 24 0c              	movl	%edx, 12(%r12)
100006d54: 41 89 44 24 10              	movl	%eax, 16(%r12)
100006d59: 39 f1                       	cmpl	%esi, %ecx
100006d5b: 89 f0                       	movl	%esi, %eax
100006d5d: 0f 47 c1                    	cmoval	%ecx, %eax
100006d60: 0f 42 f1                    	cmovbl	%ecx, %esi
100006d63: 41 89 74 24 14              	movl	%esi, 20(%r12)
100006d68: 41 89 44 24 18              	movl	%eax, 24(%r12)
100006d6d: e9 6b 0b 00 00              	jmp	2923 <_test_quick_sort_recursive+0x1ccd>
100006d72: 41 8b 04 24                 	movl	(%r12), %eax
100006d76: 41 8b 74 24 04              	movl	4(%r12), %esi
100006d7b: 39 f0                       	cmpl	%esi, %eax
100006d7d: 89 f7                       	movl	%esi, %edi
100006d7f: 0f 47 f8                    	cmoval	%eax, %edi
100006d82: 0f 42 f0                    	cmovbl	%eax, %esi
100006d85: 41 8b 44 24 08              	movl	8(%r12), %eax
100006d8a: 41 8b 5c 24 0c              	movl	12(%r12), %ebx
100006d8f: 39 d8                       	cmpl	%ebx, %eax
100006d91: 89 d9                       	movl	%ebx, %ecx
100006d93: 0f 47 c8                    	cmoval	%eax, %ecx
100006d96: 89 4d c8                    	movl	%ecx, -56(%rbp)
100006d99: 0f 42 d8                    	cmovbl	%eax, %ebx
100006d9c: 41 8b 44 24 10              	movl	16(%r12), %eax
100006da1: 45 8b 54 24 14              	movl	20(%r12), %r10d
100006da6: 44 39 d0                    	cmpl	%r10d, %eax
100006da9: 44 89 d1                    	movl	%r10d, %ecx
100006dac: 0f 47 c8                    	cmoval	%eax, %ecx
100006daf: 89 4d d0                    	movl	%ecx, -48(%rbp)
100006db2: 44 0f 42 d0                 	cmovbl	%eax, %r10d
100006db6: 41 8b 44 24 18              	movl	24(%r12), %eax
100006dbb: 41 8b 4c 24 1c              	movl	28(%r12), %ecx
100006dc0: 39 c8                       	cmpl	%ecx, %eax
100006dc2: 41 89 cd                    	movl	%ecx, %r13d
100006dc5: 44 0f 47 e8                 	cmoval	%eax, %r13d
100006dc9: 0f 42 c8                    	cmovbl	%eax, %ecx
100006dcc: 41 8b 44 24 20              	movl	32(%r12), %eax
100006dd1: 45 8b 5c 24 24              	movl	36(%r12), %r11d
100006dd6: 44 39 d8                    	cmpl	%r11d, %eax
100006dd9: 44 89 da                    	movl	%r11d, %edx
100006ddc: 0f 47 d0                    	cmoval	%eax, %edx
100006ddf: 89 55 c0                    	movl	%edx, -64(%rbp)
100006de2: 44 0f 42 d8                 	cmovbl	%eax, %r11d
100006de6: 45 8b 7c 24 28              	movl	40(%r12), %r15d
100006deb: 45 8b 44 24 2c              	movl	44(%r12), %r8d
100006df0: 45 39 c7                    	cmpl	%r8d, %r15d
100006df3: 45 89 c6                    	movl	%r8d, %r14d
100006df6: 45 0f 47 f7                 	cmoval	%r15d, %r14d
100006dfa: 45 0f 42 c7                 	cmovbl	%r15d, %r8d
100006dfe: 41 8b 54 24 30              	movl	48(%r12), %edx
100006e03: 45 8b 7c 24 34              	movl	52(%r12), %r15d
100006e08: 44 39 fa                    	cmpl	%r15d, %edx
100006e0b: 44 89 f8                    	movl	%r15d, %eax
100006e0e: 0f 47 c2                    	cmoval	%edx, %eax
100006e11: 44 0f 42 fa                 	cmovbl	%edx, %r15d
100006e15: 39 de                       	cmpl	%ebx, %esi
100006e17: 89 da                       	movl	%ebx, %edx
100006e19: 0f 47 d6                    	cmoval	%esi, %edx
100006e1c: 89 55 cc                    	movl	%edx, -52(%rbp)
100006e1f: 0f 42 de                    	cmovbl	%esi, %ebx
100006e22: 41 39 ca                    	cmpl	%ecx, %r10d
100006e25: 41 89 c9                    	movl	%ecx, %r9d
100006e28: 45 0f 47 ca                 	cmoval	%r10d, %r9d
100006e2c: 41 0f 42 ca                 	cmovbl	%r10d, %ecx
100006e30: 45 39 c3                    	cmpl	%r8d, %r11d
100006e33: 44 89 c2                    	movl	%r8d, %edx
100006e36: 41 0f 47 d3                 	cmoval	%r11d, %edx
100006e3a: 89 55 d4                    	movl	%edx, -44(%rbp)
100006e3d: 45 0f 42 c3                 	cmovbl	%r11d, %r8d
100006e41: 8b 55 c8                    	movl	-56(%rbp), %edx
100006e44: 39 d7                       	cmpl	%edx, %edi
100006e46: 41 89 d3                    	movl	%edx, %r11d
100006e49: 44 0f 47 df                 	cmoval	%edi, %r11d
100006e4d: 0f 42 d7                    	cmovbl	%edi, %edx
100006e50: 89 d6                       	movl	%edx, %esi
100006e52: 8b 55 d0                    	movl	-48(%rbp), %edx
100006e55: 44 39 ea                    	cmpl	%r13d, %edx
100006e58: 44 89 ef                    	movl	%r13d, %edi
100006e5b: 0f 47 fa                    	cmoval	%edx, %edi
100006e5e: 44 0f 42 ea                 	cmovbl	%edx, %r13d
100006e62: 44 8b 55 c0                 	movl	-64(%rbp), %r10d
100006e66: 45 39 f2                    	cmpl	%r14d, %r10d
100006e69: 44 89 f2                    	movl	%r14d, %edx
100006e6c: 41 0f 47 d2                 	cmoval	%r10d, %edx
100006e70: 89 55 d0                    	movl	%edx, -48(%rbp)
100006e73: 45 0f 42 f2                 	cmovbl	%r10d, %r14d
100006e77: 39 cb                       	cmpl	%ecx, %ebx
100006e79: 89 ca                       	movl	%ecx, %edx
100006e7b: 0f 47 d3                    	cmoval	%ebx, %edx
100006e7e: 89 55 c8                    	movl	%edx, -56(%rbp)
100006e81: 0f 42 cb                    	cmovbl	%ebx, %ecx
100006e84: 45 39 f8                    	cmpl	%r15d, %r8d
100006e87: 44 89 fb                    	movl	%r15d, %ebx
100006e8a: 41 0f 47 d8                 	cmoval	%r8d, %ebx
100006e8e: 45 0f 43 c7                 	cmovael	%r15d, %r8d
100006e92: 44 39 ee                    	cmpl	%r13d, %esi
100006e95: 44 89 ea                    	movl	%r13d, %edx
100006e98: 0f 47 d6                    	cmoval	%esi, %edx
100006e9b: 44 0f 42 ee                 	cmovbl	%esi, %r13d
100006e9f: 41 39 c6                    	cmpl	%eax, %r14d
100006ea2: 41 89 c2                    	movl	%eax, %r10d
100006ea5: 45 0f 47 d6                 	cmoval	%r14d, %r10d
100006ea9: 44 0f 43 f0                 	cmovael	%eax, %r14d
100006ead: 8b 45 cc                    	movl	-52(%rbp), %eax
100006eb0: 44 39 c8                    	cmpl	%r9d, %eax
100006eb3: 44 89 ce                    	movl	%r9d, %esi
100006eb6: 0f 47 f0                    	cmoval	%eax, %esi
100006eb9: 89 75 c4                    	movl	%esi, -60(%rbp)
100006ebc: 44 0f 42 c8                 	cmovbl	%eax, %r9d
100006ec0: 41 39 fb                    	cmpl	%edi, %r11d
100006ec3: 89 f8                       	movl	%edi, %eax
100006ec5: 41 0f 47 c3                 	cmoval	%r11d, %eax
100006ec9: 89 45 c0                    	movl	%eax, -64(%rbp)
100006ecc: 41 0f 42 fb                 	cmovbl	%r11d, %edi
100006ed0: 44 39 c1                    	cmpl	%r8d, %ecx
100006ed3: 44 89 c0                    	movl	%r8d, %eax
100006ed6: 0f 47 c1                    	cmoval	%ecx, %eax
100006ed9: 89 45 cc                    	movl	%eax, -52(%rbp)
100006edc: 44 0f 42 c1                 	cmovbl	%ecx, %r8d
100006ee0: 45 89 04 24                 	movl	%r8d, (%r12)
100006ee4: 45 39 f5                    	cmpl	%r14d, %r13d
100006ee7: 45 89 f7                    	movl	%r14d, %r15d
100006eea: 45 0f 47 fd                 	cmoval	%r13d, %r15d
100006eee: 45 0f 42 f5                 	cmovbl	%r13d, %r14d
100006ef2: 8b 45 d4                    	movl	-44(%rbp), %eax
100006ef5: 41 39 c1                    	cmpl	%eax, %r9d
100006ef8: 89 c6                       	movl	%eax, %esi
100006efa: 41 0f 47 f1                 	cmoval	%r9d, %esi
100006efe: 44 0f 43 c8                 	cmovael	%eax, %r9d
100006f02: 8b 45 d0                    	movl	-48(%rbp), %eax
100006f05: 39 c7                       	cmpl	%eax, %edi
100006f07: 89 c1                       	movl	%eax, %ecx
100006f09: 0f 47 cf                    	cmoval	%edi, %ecx
100006f0c: 0f 43 f8                    	cmovael	%eax, %edi
100006f0f: 8b 45 c8                    	movl	-56(%rbp), %eax
100006f12: 39 d8                       	cmpl	%ebx, %eax
100006f14: 41 89 d8                    	movl	%ebx, %r8d
100006f17: 44 0f 47 c0                 	cmoval	%eax, %r8d
100006f1b: 0f 42 d8                    	cmovbl	%eax, %ebx
100006f1e: 44 39 d2                    	cmpl	%r10d, %edx
100006f21: 45 89 d5                    	movl	%r10d, %r13d
100006f24: 44 0f 47 ea                 	cmoval	%edx, %r13d
100006f28: 44 0f 42 d2                 	cmovbl	%edx, %r10d
100006f2c: 41 39 f2                    	cmpl	%esi, %r10d
100006f2f: 89 f0                       	movl	%esi, %eax
100006f31: 41 0f 47 c2                 	cmoval	%r10d, %eax
100006f35: 89 45 c8                    	movl	%eax, -56(%rbp)
100006f38: 44 0f 43 d6                 	cmovael	%esi, %r10d
100006f3c: 8b 45 c4                    	movl	-60(%rbp), %eax
100006f3f: 44 39 f8                    	cmpl	%r15d, %eax
100006f42: 44 89 fa                    	movl	%r15d, %edx
100006f45: 0f 47 d0                    	cmoval	%eax, %edx
100006f48: 89 55 d4                    	movl	%edx, -44(%rbp)
100006f4b: 44 0f 42 f8                 	cmovbl	%eax, %r15d
100006f4f: 44 39 c7                    	cmpl	%r8d, %edi
100006f52: 44 89 c0                    	movl	%r8d, %eax
100006f55: 0f 47 c7                    	cmoval	%edi, %eax
100006f58: 89 45 d0                    	movl	%eax, -48(%rbp)
100006f5b: 44 0f 42 c7                 	cmovbl	%edi, %r8d
100006f5f: 8b 45 c0                    	movl	-64(%rbp), %eax
100006f62: 39 c8                       	cmpl	%ecx, %eax
100006f64: 89 ca                       	movl	%ecx, %edx
100006f66: 0f 47 d0                    	cmoval	%eax, %edx
100006f69: 89 55 c4                    	movl	%edx, -60(%rbp)
100006f6c: 0f 42 c8                    	cmovbl	%eax, %ecx
100006f6f: 45 39 ce                    	cmpl	%r9d, %r14d
100006f72: 45 89 cb                    	movl	%r9d, %r11d
100006f75: 45 0f 47 de                 	cmoval	%r14d, %r11d
100006f79: 45 0f 42 ce                 	cmovbl	%r14d, %r9d
100006f7d: 8b 45 cc                    	movl	-52(%rbp), %eax
100006f80: 39 c3                       	cmpl	%eax, %ebx
100006f82: 89 c2                       	movl	%eax, %edx
100006f84: 0f 47 d3                    	cmoval	%ebx, %edx
100006f87: 0f 43 d8                    	cmovael	%eax, %ebx
100006f8a: 41 39 d9                    	cmpl	%ebx, %r9d
100006f8d: 89 d8                       	movl	%ebx, %eax
100006f8f: 41 0f 47 c1                 	cmoval	%r9d, %eax
100006f93: 41 0f 42 d9                 	cmovbl	%r9d, %ebx
100006f97: 44 39 e9                    	cmpl	%r13d, %ecx
100006f9a: 45 89 ee                    	movl	%r13d, %r14d
100006f9d: 44 0f 47 f1                 	cmoval	%ecx, %r14d
100006fa1: 41 0f 43 cd                 	cmovael	%r13d, %ecx
100006fa5: 41 39 d3                    	cmpl	%edx, %r11d
100006fa8: 89 d6                       	movl	%edx, %esi
100006faa: 41 0f 47 f3                 	cmoval	%r11d, %esi
100006fae: 41 0f 42 d3                 	cmovbl	%r11d, %edx
100006fb2: 45 39 fa                    	cmpl	%r15d, %r10d
100006fb5: 44 89 ff                    	movl	%r15d, %edi
100006fb8: 41 0f 47 fa                 	cmoval	%r10d, %edi
100006fbc: 41 89 5c 24 04              	movl	%ebx, 4(%r12)
100006fc1: 45 0f 42 fa                 	cmovbl	%r10d, %r15d
100006fc5: 8b 5d c8                    	movl	-56(%rbp), %ebx
100006fc8: 44 8b 4d d4                 	movl	-44(%rbp), %r9d
100006fcc: 41 39 d9                    	cmpl	%ebx, %r9d
100006fcf: 41 89 db                    	movl	%ebx, %r11d
100006fd2: 45 0f 47 d9                 	cmoval	%r9d, %r11d
100006fd6: 44 0f 43 cb                 	cmovael	%ebx, %r9d
100006fda: 44 89 4d d4                 	movl	%r9d, -44(%rbp)
100006fde: 39 c2                       	cmpl	%eax, %edx
100006fe0: 41 89 c1                    	movl	%eax, %r9d
100006fe3: 44 0f 47 ca                 	cmoval	%edx, %r9d
100006fe7: 0f 43 d0                    	cmovael	%eax, %edx
100006fea: 41 89 54 24 08              	movl	%edx, 8(%r12)
100006fef: 8b 55 c4                    	movl	-60(%rbp), %edx
100006ff2: 44 39 f2                    	cmpl	%r14d, %edx
100006ff5: 44 89 f0                    	movl	%r14d, %eax
100006ff8: 0f 47 c2                    	cmoval	%edx, %eax
100006ffb: 89 45 cc                    	movl	%eax, -52(%rbp)
100006ffe: 44 0f 42 f2                 	cmovbl	%edx, %r14d
100007002: 41 39 f0                    	cmpl	%esi, %r8d
100007005: 89 f2                       	movl	%esi, %edx
100007007: 41 0f 47 d0                 	cmoval	%r8d, %edx
10000700b: 41 0f 42 f0                 	cmovbl	%r8d, %esi
10000700f: 8b 45 d0                    	movl	-48(%rbp), %eax
100007012: 39 c1                       	cmpl	%eax, %ecx
100007014: 41 89 c5                    	movl	%eax, %r13d
100007017: 44 0f 47 e9                 	cmoval	%ecx, %r13d
10000701b: 0f 43 c8                    	cmovael	%eax, %ecx
10000701e: 39 d7                       	cmpl	%edx, %edi
100007020: 41 89 d2                    	movl	%edx, %r10d
100007023: 44 0f 47 d7                 	cmoval	%edi, %r10d
100007027: 0f 42 d7                    	cmovbl	%edi, %edx
10000702a: 45 39 eb                    	cmpl	%r13d, %r11d
10000702d: 45 89 e8                    	movl	%r13d, %r8d
100007030: 45 0f 47 c3                 	cmoval	%r11d, %r8d
100007034: 45 0f 42 eb                 	cmovbl	%r11d, %r13d
100007038: 44 39 fe                    	cmpl	%r15d, %esi
10000703b: 44 89 fb                    	movl	%r15d, %ebx
10000703e: 0f 47 de                    	cmoval	%esi, %ebx
100007041: 41 0f 43 f7                 	cmovael	%r15d, %esi
100007045: 8b 7d d4                    	movl	-44(%rbp), %edi
100007048: 39 f9                       	cmpl	%edi, %ecx
10000704a: 89 f8                       	movl	%edi, %eax
10000704c: 0f 47 c1                    	cmoval	%ecx, %eax
10000704f: 0f 43 cf                    	cmovael	%edi, %ecx
100007052: 44 89 cf                    	movl	%r9d, %edi
100007055: 44 39 ce                    	cmpl	%r9d, %esi
100007058: 45 89 cb                    	movl	%r9d, %r11d
10000705b: 44 0f 47 ce                 	cmoval	%esi, %r9d
10000705f: 8b 7d cc                    	movl	-52(%rbp), %edi
100007062: 41 89 7c 24 34              	movl	%edi, 52(%r12)
100007067: 41 0f 43 f3                 	cmovael	%r11d, %esi
10000706b: 41 89 74 24 0c              	movl	%esi, 12(%r12)
100007070: 39 d3                       	cmpl	%edx, %ebx
100007072: 89 d6                       	movl	%edx, %esi
100007074: 0f 47 f3                    	cmoval	%ebx, %esi
100007077: 45 89 4c 24 10              	movl	%r9d, 16(%r12)
10000707c: 0f 43 da                    	cmovael	%edx, %ebx
10000707f: 41 89 5c 24 14              	movl	%ebx, 20(%r12)
100007084: 44 39 d1                    	cmpl	%r10d, %ecx
100007087: 44 89 d2                    	movl	%r10d, %edx
10000708a: 0f 47 d1                    	cmoval	%ecx, %edx
10000708d: 41 0f 43 ca                 	cmovael	%r10d, %ecx
100007091: 44 39 e8                    	cmpl	%r13d, %eax
100007094: 44 89 eb                    	movl	%r13d, %ebx
100007097: 0f 47 d8                    	cmoval	%eax, %ebx
10000709a: 41 0f 43 c5                 	cmovael	%r13d, %eax
10000709e: 41 89 5c 24 28              	movl	%ebx, 40(%r12)
1000070a3: 45 39 c6                    	cmpl	%r8d, %r14d
1000070a6: 44 89 c7                    	movl	%r8d, %edi
1000070a9: 41 0f 47 fe                 	cmoval	%r14d, %edi
1000070ad: 45 0f 42 c6                 	cmovbl	%r14d, %r8d
1000070b1: 45 89 44 24 2c              	movl	%r8d, 44(%r12)
1000070b6: 41 89 7c 24 30              	movl	%edi, 48(%r12)
1000070bb: 39 ce                       	cmpl	%ecx, %esi
1000070bd: 89 cf                       	movl	%ecx, %edi
1000070bf: 0f 47 fe                    	cmoval	%esi, %edi
1000070c2: 0f 42 ce                    	cmovbl	%esi, %ecx
1000070c5: 41 89 4c 24 18              	movl	%ecx, 24(%r12)
1000070ca: 41 89 7c 24 1c              	movl	%edi, 28(%r12)
1000070cf: 39 c2                       	cmpl	%eax, %edx
1000070d1: 89 c1                       	movl	%eax, %ecx
1000070d3: 0f 47 ca                    	cmoval	%edx, %ecx
1000070d6: 0f 42 c2                    	cmovbl	%edx, %eax
1000070d9: 41 89 44 24 20              	movl	%eax, 32(%r12)
1000070de: 41 89 4c 24 24              	movl	%ecx, 36(%r12)
1000070e3: e9 f5 07 00 00              	jmp	2037 <_test_quick_sort_recursive+0x1ccd>
1000070e8: 41 8b 04 24                 	movl	(%r12), %eax
1000070ec: 45 8b 4c 24 04              	movl	4(%r12), %r9d
1000070f1: 44 39 c8                    	cmpl	%r9d, %eax
1000070f4: 44 89 c9                    	movl	%r9d, %ecx
1000070f7: 0f 47 c8                    	cmoval	%eax, %ecx
1000070fa: 89 4d d4                    	movl	%ecx, -44(%rbp)
1000070fd: 44 0f 42 c8                 	cmovbl	%eax, %r9d
100007101: 41 8b 4c 24 08              	movl	8(%r12), %ecx
100007106: 41 8b 44 24 0c              	movl	12(%r12), %eax
10000710b: 39 c1                       	cmpl	%eax, %ecx
10000710d: 41 89 c6                    	movl	%eax, %r14d
100007110: 44 0f 47 f1                 	cmoval	%ecx, %r14d
100007114: 0f 42 c1                    	cmovbl	%ecx, %eax
100007117: 41 8b 4c 24 10              	movl	16(%r12), %ecx
10000711c: 45 8b 5c 24 14              	movl	20(%r12), %r11d
100007121: 44 39 d9                    	cmpl	%r11d, %ecx
100007124: 44 89 da                    	movl	%r11d, %edx
100007127: 0f 47 d1                    	cmoval	%ecx, %edx
10000712a: 89 55 d0                    	movl	%edx, -48(%rbp)
10000712d: 44 0f 42 d9                 	cmovbl	%ecx, %r11d
100007131: 41 8b 54 24 18              	movl	24(%r12), %edx
100007136: 41 8b 4c 24 1c              	movl	28(%r12), %ecx
10000713b: 39 ca                       	cmpl	%ecx, %edx
10000713d: 41 89 c8                    	movl	%ecx, %r8d
100007140: 44 0f 47 c2                 	cmoval	%edx, %r8d
100007144: 0f 42 ca                    	cmovbl	%edx, %ecx
100007147: 41 8b 5c 24 20              	movl	32(%r12), %ebx
10000714c: 41 8b 74 24 24              	movl	36(%r12), %esi
100007151: 39 f3                       	cmpl	%esi, %ebx
100007153: 89 f2                       	movl	%esi, %edx
100007155: 0f 47 d3                    	cmoval	%ebx, %edx
100007158: 0f 42 f3                    	cmovbl	%ebx, %esi
10000715b: 41 8b 5c 24 28              	movl	40(%r12), %ebx
100007160: 45 8b 7c 24 2c              	movl	44(%r12), %r15d
100007165: 44 39 fb                    	cmpl	%r15d, %ebx
100007168: 45 89 fd                    	movl	%r15d, %r13d
10000716b: 44 0f 47 eb                 	cmoval	%ebx, %r13d
10000716f: 44 0f 42 fb                 	cmovbl	%ebx, %r15d
100007173: 41 8b 5c 24 30              	movl	48(%r12), %ebx
100007178: 45 8b 54 24 34              	movl	52(%r12), %r10d
10000717d: 44 39 d3                    	cmpl	%r10d, %ebx
100007180: 44 89 d7                    	movl	%r10d, %edi
100007183: 0f 47 fb                    	cmoval	%ebx, %edi
100007186: 89 7d cc                    	movl	%edi, -52(%rbp)
100007189: 44 0f 42 d3                 	cmovbl	%ebx, %r10d
10000718d: 41 39 c1                    	cmpl	%eax, %r9d
100007190: 89 c7                       	movl	%eax, %edi
100007192: 41 0f 47 f9                 	cmoval	%r9d, %edi
100007196: 89 7d c8                    	movl	%edi, -56(%rbp)
100007199: 41 0f 42 c1                 	cmovbl	%r9d, %eax
10000719d: 41 39 cb                    	cmpl	%ecx, %r11d
1000071a0: 41 89 c9                    	movl	%ecx, %r9d
1000071a3: 45 0f 47 cb                 	cmoval	%r11d, %r9d
1000071a7: 41 0f 42 cb                 	cmovbl	%r11d, %ecx
1000071ab: 44 39 fe                    	cmpl	%r15d, %esi
1000071ae: 44 89 ff                    	movl	%r15d, %edi
1000071b1: 0f 47 fe                    	cmoval	%esi, %edi
1000071b4: 89 7d c0                    	movl	%edi, -64(%rbp)
1000071b7: 44 0f 42 fe                 	cmovbl	%esi, %r15d
1000071bb: 41 8b 5c 24 38              	movl	56(%r12), %ebx
1000071c0: 41 39 da                    	cmpl	%ebx, %r10d
1000071c3: 89 df                       	movl	%ebx, %edi
1000071c5: 41 0f 47 fa                 	cmoval	%r10d, %edi
1000071c9: 44 0f 43 d3                 	cmovael	%ebx, %r10d
1000071cd: 8b 75 d4                    	movl	-44(%rbp), %esi
1000071d0: 44 39 f6                    	cmpl	%r14d, %esi
1000071d3: 45 89 f3                    	movl	%r14d, %r11d
1000071d6: 44 0f 47 de                 	cmoval	%esi, %r11d
1000071da: 44 0f 42 f6                 	cmovbl	%esi, %r14d
1000071de: 8b 75 d0                    	movl	-48(%rbp), %esi
1000071e1: 44 39 c6                    	cmpl	%r8d, %esi
1000071e4: 44 89 c3                    	movl	%r8d, %ebx
1000071e7: 0f 47 de                    	cmoval	%esi, %ebx
1000071ea: 44 0f 42 c6                 	cmovbl	%esi, %r8d
1000071ee: 44 39 ea                    	cmpl	%r13d, %edx
1000071f1: 44 89 ee                    	movl	%r13d, %esi
1000071f4: 0f 47 f2                    	cmoval	%edx, %esi
1000071f7: 89 75 c4                    	movl	%esi, -60(%rbp)
1000071fa: 44 0f 42 ea                 	cmovbl	%edx, %r13d
1000071fe: 39 c8                       	cmpl	%ecx, %eax
100007200: 89 ca                       	movl	%ecx, %edx
100007202: 0f 47 d0                    	cmoval	%eax, %edx
100007205: 89 55 d4                    	movl	%edx, -44(%rbp)
100007208: 0f 42 c8                    	cmovbl	%eax, %ecx
10000720b: 45 39 d7                    	cmpl	%r10d, %r15d
10000720e: 44 89 d2                    	movl	%r10d, %edx
100007211: 41 0f 47 d7                 	cmoval	%r15d, %edx
100007215: 45 0f 42 d7                 	cmovbl	%r15d, %r10d
100007219: 45 39 c6                    	cmpl	%r8d, %r14d
10000721c: 44 89 c0                    	movl	%r8d, %eax
10000721f: 41 0f 47 c6                 	cmoval	%r14d, %eax
100007223: 89 45 d0                    	movl	%eax, -48(%rbp)
100007226: 45 0f 42 c6                 	cmovbl	%r14d, %r8d
10000722a: 8b 45 cc                    	movl	-52(%rbp), %eax
10000722d: 41 39 c5                    	cmpl	%eax, %r13d
100007230: 41 89 c6                    	movl	%eax, %r14d
100007233: 45 0f 47 f5                 	cmoval	%r13d, %r14d
100007237: 44 0f 43 e8                 	cmovael	%eax, %r13d
10000723b: 8b 45 c8                    	movl	-56(%rbp), %eax
10000723e: 44 39 c8                    	cmpl	%r9d, %eax
100007241: 44 89 ce                    	movl	%r9d, %esi
100007244: 0f 47 f0                    	cmoval	%eax, %esi
100007247: 89 75 bc                    	movl	%esi, -68(%rbp)
10000724a: 44 0f 42 c8                 	cmovbl	%eax, %r9d
10000724e: 8b 45 c0                    	movl	-64(%rbp), %eax
100007251: 39 f8                       	cmpl	%edi, %eax
100007253: 41 89 ff                    	movl	%edi, %r15d
100007256: 44 0f 47 f8                 	cmoval	%eax, %r15d
10000725a: 0f 42 f8                    	cmovbl	%eax, %edi
10000725d: 41 39 db                    	cmpl	%ebx, %r11d
100007260: 89 d8                       	movl	%ebx, %eax
100007262: 41 0f 47 c3                 	cmoval	%r11d, %eax
100007266: 89 45 c0                    	movl	%eax, -64(%rbp)
100007269: 41 0f 42 db                 	cmovbl	%r11d, %ebx
10000726d: 44 39 d1                    	cmpl	%r10d, %ecx
100007270: 44 89 d0                    	movl	%r10d, %eax
100007273: 0f 47 c1                    	cmoval	%ecx, %eax
100007276: 89 45 cc                    	movl	%eax, -52(%rbp)
100007279: 44 0f 42 d1                 	cmovbl	%ecx, %r10d
10000727d: 45 39 e8                    	cmpl	%r13d, %r8d
100007280: 44 89 e8                    	movl	%r13d, %eax
100007283: 41 0f 47 c0                 	cmoval	%r8d, %eax
100007287: 89 45 b8                    	movl	%eax, -72(%rbp)
10000728a: 45 0f 42 e8                 	cmovbl	%r8d, %r13d
10000728e: 41 39 f9                    	cmpl	%edi, %r9d
100007291: 89 f8                       	movl	%edi, %eax
100007293: 41 0f 47 c1                 	cmoval	%r9d, %eax
100007297: 41 0f 42 f9                 	cmovbl	%r9d, %edi
10000729b: 8b 75 c4                    	movl	-60(%rbp), %esi
10000729e: 39 f3                       	cmpl	%esi, %ebx
1000072a0: 89 f1                       	movl	%esi, %ecx
1000072a2: 0f 47 cb                    	cmoval	%ebx, %ecx
1000072a5: 0f 43 de                    	cmovael	%esi, %ebx
1000072a8: 8b 75 d4                    	movl	-44(%rbp), %esi
1000072ab: 39 d6                       	cmpl	%edx, %esi
1000072ad: 41 89 d0                    	movl	%edx, %r8d
1000072b0: 44 0f 47 c6                 	cmoval	%esi, %r8d
1000072b4: 0f 42 d6                    	cmovbl	%esi, %edx
1000072b7: 8b 75 d0                    	movl	-48(%rbp), %esi
1000072ba: 44 39 f6                    	cmpl	%r14d, %esi
1000072bd: 45 89 f1                    	movl	%r14d, %r9d
1000072c0: 44 0f 47 ce                 	cmoval	%esi, %r9d
1000072c4: 44 0f 42 f6                 	cmovbl	%esi, %r14d
1000072c8: 8b 75 bc                    	movl	-68(%rbp), %esi
1000072cb: 44 39 fe                    	cmpl	%r15d, %esi
1000072ce: 45 89 fb                    	movl	%r15d, %r11d
1000072d1: 44 0f 47 de                 	cmoval	%esi, %r11d
1000072d5: 44 0f 42 fe                 	cmovbl	%esi, %r15d
1000072d9: 41 39 c6                    	cmpl	%eax, %r14d
1000072dc: 89 c6                       	movl	%eax, %esi
1000072de: 41 0f 47 f6                 	cmoval	%r14d, %esi
1000072e2: 89 75 c8                    	movl	%esi, -56(%rbp)
1000072e5: 44 0f 43 f0                 	cmovael	%eax, %r14d
1000072e9: 8b 75 b8                    	movl	-72(%rbp), %esi
1000072ec: 41 39 f7                    	cmpl	%esi, %r15d
1000072ef: 89 f0                       	movl	%esi, %eax
1000072f1: 41 0f 47 c7                 	cmoval	%r15d, %eax
1000072f5: 89 45 d4                    	movl	%eax, -44(%rbp)
1000072f8: 44 0f 43 fe                 	cmovael	%esi, %r15d
1000072fc: 44 39 c3                    	cmpl	%r8d, %ebx
1000072ff: 44 89 c0                    	movl	%r8d, %eax
100007302: 0f 47 c3                    	cmoval	%ebx, %eax
100007305: 89 45 d0                    	movl	%eax, -48(%rbp)
100007308: 44 0f 42 c3                 	cmovbl	%ebx, %r8d
10000730c: 45 39 d9                    	cmpl	%r11d, %r9d
10000730f: 44 89 d8                    	movl	%r11d, %eax
100007312: 41 0f 47 c1                 	cmoval	%r9d, %eax
100007316: 89 45 c4                    	movl	%eax, -60(%rbp)
100007319: 45 0f 42 d9                 	cmovbl	%r9d, %r11d
10000731d: 8b 45 c0                    	movl	-64(%rbp), %eax
100007320: 39 c8                       	cmpl	%ecx, %eax
100007322: 41 89 c9                    	movl	%ecx, %r9d
100007325: 44 0f 47 c8                 	cmoval	%eax, %r9d
100007329: 0f 42 c8                    	cmovbl	%eax, %ecx
10000732c: 41 39 fd                    	cmpl	%edi, %r13d
10000732f: 89 fe                       	movl	%edi, %esi
100007331: 41 0f 47 f5                 	cmoval	%r13d, %esi
100007335: 41 0f 42 fd                 	cmovbl	%r13d, %edi
100007339: 8b 5d cc                    	movl	-52(%rbp), %ebx
10000733c: 39 da                       	cmpl	%ebx, %edx
10000733e: 89 d8                       	movl	%ebx, %eax
100007340: 0f 47 c2                    	cmoval	%edx, %eax
100007343: 0f 43 d3                    	cmovael	%ebx, %edx
100007346: 39 d7                       	cmpl	%edx, %edi
100007348: 41 89 d5                    	movl	%edx, %r13d
10000734b: 44 0f 47 ef                 	cmoval	%edi, %r13d
10000734f: 45 89 14 24                 	movl	%r10d, (%r12)
100007353: 0f 42 d7                    	cmovbl	%edi, %edx
100007356: 41 89 54 24 04              	movl	%edx, 4(%r12)
10000735b: 44 39 d9                    	cmpl	%r11d, %ecx
10000735e: 44 89 da                    	movl	%r11d, %edx
100007361: 0f 47 d1                    	cmoval	%ecx, %edx
100007364: 41 0f 43 cb                 	cmovael	%r11d, %ecx
100007368: 39 c6                       	cmpl	%eax, %esi
10000736a: 89 c3                       	movl	%eax, %ebx
10000736c: 0f 47 de                    	cmoval	%esi, %ebx
10000736f: 0f 42 c6                    	cmovbl	%esi, %eax
100007372: 8b 7d c4                    	movl	-60(%rbp), %edi
100007375: 41 39 f9                    	cmpl	%edi, %r9d
100007378: 89 fe                       	movl	%edi, %esi
10000737a: 41 0f 47 f1                 	cmoval	%r9d, %esi
10000737e: 44 0f 43 cf                 	cmovael	%edi, %r9d
100007382: 45 39 fe                    	cmpl	%r15d, %r14d
100007385: 44 89 ff                    	movl	%r15d, %edi
100007388: 41 0f 47 fe                 	cmoval	%r14d, %edi
10000738c: 41 89 74 24 38              	movl	%esi, 56(%r12)
100007391: 45 0f 42 fe                 	cmovbl	%r14d, %r15d
100007395: 8b 75 d4                    	movl	-44(%rbp), %esi
100007398: 44 8b 55 c8                 	movl	-56(%rbp), %r10d
10000739c: 44 39 d6                    	cmpl	%r10d, %esi
10000739f: 45 89 d3                    	movl	%r10d, %r11d
1000073a2: 44 0f 47 de                 	cmoval	%esi, %r11d
1000073a6: 41 0f 43 f2                 	cmovael	%r10d, %esi
1000073aa: 89 75 d4                    	movl	%esi, -44(%rbp)
1000073ad: 44 39 e8                    	cmpl	%r13d, %eax
1000073b0: 45 89 ea                    	movl	%r13d, %r10d
1000073b3: 44 0f 47 d0                 	cmoval	%eax, %r10d
1000073b7: 41 0f 43 c5                 	cmovael	%r13d, %eax
1000073bb: 41 89 44 24 08              	movl	%eax, 8(%r12)
1000073c0: 41 39 d1                    	cmpl	%edx, %r9d
1000073c3: 41 89 d5                    	movl	%edx, %r13d
1000073c6: 45 0f 47 e9                 	cmoval	%r9d, %r13d
1000073ca: 44 0f 43 ca                 	cmovael	%edx, %r9d
1000073ce: 41 39 d8                    	cmpl	%ebx, %r8d
1000073d1: 89 d8                       	movl	%ebx, %eax
1000073d3: 41 0f 47 c0                 	cmoval	%r8d, %eax
1000073d7: 41 0f 42 d8                 	cmovbl	%r8d, %ebx
1000073db: 8b 55 d0                    	movl	-48(%rbp), %edx
1000073de: 39 d1                       	cmpl	%edx, %ecx
1000073e0: 89 d6                       	movl	%edx, %esi
1000073e2: 0f 47 f1                    	cmoval	%ecx, %esi
1000073e5: 0f 43 ca                    	cmovael	%edx, %ecx
1000073e8: 39 c7                       	cmpl	%eax, %edi
1000073ea: 41 89 c6                    	movl	%eax, %r14d
1000073ed: 44 0f 47 f7                 	cmoval	%edi, %r14d
1000073f1: 0f 42 c7                    	cmovbl	%edi, %eax
1000073f4: 41 39 f3                    	cmpl	%esi, %r11d
1000073f7: 41 89 f0                    	movl	%esi, %r8d
1000073fa: 45 0f 47 c3                 	cmoval	%r11d, %r8d
1000073fe: 41 0f 42 f3                 	cmovbl	%r11d, %esi
100007402: 44 39 fb                    	cmpl	%r15d, %ebx
100007405: 44 89 ff                    	movl	%r15d, %edi
100007408: 0f 47 fb                    	cmoval	%ebx, %edi
10000740b: 41 0f 43 df                 	cmovael	%r15d, %ebx
10000740f: 44 8b 5d d4                 	movl	-44(%rbp), %r11d
100007413: 44 39 d9                    	cmpl	%r11d, %ecx
100007416: 44 89 da                    	movl	%r11d, %edx
100007419: 0f 47 d1                    	cmoval	%ecx, %edx
10000741c: 41 0f 43 cb                 	cmovael	%r11d, %ecx
100007420: 44 39 d3                    	cmpl	%r10d, %ebx
100007423: 45 89 d3                    	movl	%r10d, %r11d
100007426: 44 0f 47 db                 	cmoval	%ebx, %r11d
10000742a: 45 89 6c 24 34              	movl	%r13d, 52(%r12)
10000742f: 41 0f 43 da                 	cmovael	%r10d, %ebx
100007433: 41 89 5c 24 0c              	movl	%ebx, 12(%r12)
100007438: 39 c7                       	cmpl	%eax, %edi
10000743a: 89 c3                       	movl	%eax, %ebx
10000743c: 0f 47 df                    	cmoval	%edi, %ebx
10000743f: 45 89 5c 24 10              	movl	%r11d, 16(%r12)
100007444: 0f 43 f8                    	cmovael	%eax, %edi
100007447: 41 89 7c 24 14              	movl	%edi, 20(%r12)
10000744c: 44 39 f1                    	cmpl	%r14d, %ecx
10000744f: 44 89 f0                    	movl	%r14d, %eax
100007452: 0f 47 c1                    	cmoval	%ecx, %eax
100007455: 41 0f 43 ce                 	cmovael	%r14d, %ecx
100007459: 39 f2                       	cmpl	%esi, %edx
10000745b: 89 f7                       	movl	%esi, %edi
10000745d: 0f 47 fa                    	cmoval	%edx, %edi
100007460: 0f 43 d6                    	cmovael	%esi, %edx
100007463: 41 89 7c 24 28              	movl	%edi, 40(%r12)
100007468: 45 39 c1                    	cmpl	%r8d, %r9d
10000746b: 44 89 c6                    	movl	%r8d, %esi
10000746e: 41 0f 47 f1                 	cmoval	%r9d, %esi
100007472: 45 0f 42 c1                 	cmovbl	%r9d, %r8d
100007476: 45 89 44 24 2c              	movl	%r8d, 44(%r12)
10000747b: 41 89 74 24 30              	movl	%esi, 48(%r12)
100007480: 39 cb                       	cmpl	%ecx, %ebx
100007482: 89 ce                       	movl	%ecx, %esi
100007484: 0f 47 f3                    	cmoval	%ebx, %esi
100007487: 0f 42 cb                    	cmovbl	%ebx, %ecx
10000748a: 41 89 4c 24 18              	movl	%ecx, 24(%r12)
10000748f: 41 89 74 24 1c              	movl	%esi, 28(%r12)
100007494: 39 d0                       	cmpl	%edx, %eax
100007496: 89 d1                       	movl	%edx, %ecx
100007498: 0f 47 c8                    	cmoval	%eax, %ecx
10000749b: 0f 42 d0                    	cmovbl	%eax, %edx
10000749e: 41 89 54 24 20              	movl	%edx, 32(%r12)
1000074a3: 41 89 4c 24 24              	movl	%ecx, 36(%r12)
1000074a8: e9 30 04 00 00              	jmp	1072 <_test_quick_sort_recursive+0x1ccd>
1000074ad: 41 8b 04 24                 	movl	(%r12), %eax
1000074b1: 41 8b 5c 24 04              	movl	4(%r12), %ebx
1000074b6: 39 d8                       	cmpl	%ebx, %eax
1000074b8: 89 d9                       	movl	%ebx, %ecx
1000074ba: 0f 47 c8                    	cmoval	%eax, %ecx
1000074bd: 89 4d d0                    	movl	%ecx, -48(%rbp)
1000074c0: 0f 42 d8                    	cmovbl	%eax, %ebx
1000074c3: 41 8b 44 24 08              	movl	8(%r12), %eax
1000074c8: 41 8b 54 24 0c              	movl	12(%r12), %edx
1000074cd: 39 d0                       	cmpl	%edx, %eax
1000074cf: 89 d1                       	movl	%edx, %ecx
1000074d1: 0f 47 c8                    	cmoval	%eax, %ecx
1000074d4: 89 4d cc                    	movl	%ecx, -52(%rbp)
1000074d7: 0f 42 d0                    	cmovbl	%eax, %edx
1000074da: 41 8b 44 24 10              	movl	16(%r12), %eax
1000074df: 45 8b 7c 24 14              	movl	20(%r12), %r15d
1000074e4: 44 39 f8                    	cmpl	%r15d, %eax
1000074e7: 44 89 f9                    	movl	%r15d, %ecx
1000074ea: 0f 47 c8                    	cmoval	%eax, %ecx
1000074ed: 89 4d c8                    	movl	%ecx, -56(%rbp)
1000074f0: 44 0f 42 f8                 	cmovbl	%eax, %r15d
1000074f4: 41 8b 44 24 18              	movl	24(%r12), %eax
1000074f9: 45 8b 4c 24 1c              	movl	28(%r12), %r9d
1000074fe: 44 39 c8                    	cmpl	%r9d, %eax
100007501: 45 89 c8                    	movl	%r9d, %r8d
100007504: 44 0f 47 c0                 	cmoval	%eax, %r8d
100007508: 44 0f 42 c8                 	cmovbl	%eax, %r9d
10000750c: 41 8b 4c 24 20              	movl	32(%r12), %ecx
100007511: 41 8b 74 24 24              	movl	36(%r12), %esi
100007516: 39 f1                       	cmpl	%esi, %ecx
100007518: 89 f0                       	movl	%esi, %eax
10000751a: 0f 47 c1                    	cmoval	%ecx, %eax
10000751d: 89 45 c4                    	movl	%eax, -60(%rbp)
100007520: 0f 42 f1                    	cmovbl	%ecx, %esi
100007523: 41 8b 7c 24 28              	movl	40(%r12), %edi
100007528: 41 8b 4c 24 2c              	movl	44(%r12), %ecx
10000752d: 39 cf                       	cmpl	%ecx, %edi
10000752f: 41 89 ca                    	movl	%ecx, %r10d
100007532: 44 0f 47 d7                 	cmoval	%edi, %r10d
100007536: 0f 42 cf                    	cmovbl	%edi, %ecx
100007539: 41 8b 7c 24 30              	movl	48(%r12), %edi
10000753e: 45 8b 5c 24 34              	movl	52(%r12), %r11d
100007543: 44 39 df                    	cmpl	%r11d, %edi
100007546: 44 89 d8                    	movl	%r11d, %eax
100007549: 0f 47 c7                    	cmoval	%edi, %eax
10000754c: 89 45 b4                    	movl	%eax, -76(%rbp)
10000754f: 44 0f 42 df                 	cmovbl	%edi, %r11d
100007553: 41 8b 44 24 38              	movl	56(%r12), %eax
100007558: 45 8b 74 24 3c              	movl	60(%r12), %r14d
10000755d: 44 39 f0                    	cmpl	%r14d, %eax
100007560: 45 89 f5                    	movl	%r14d, %r13d
100007563: 44 0f 47 e8                 	cmoval	%eax, %r13d
100007567: 44 0f 42 f0                 	cmovbl	%eax, %r14d
10000756b: 39 d3                       	cmpl	%edx, %ebx
10000756d: 89 d0                       	movl	%edx, %eax
10000756f: 0f 47 c3                    	cmoval	%ebx, %eax
100007572: 89 45 c0                    	movl	%eax, -64(%rbp)
100007575: 0f 42 d3                    	cmovbl	%ebx, %edx
100007578: 45 39 cf                    	cmpl	%r9d, %r15d
10000757b: 44 89 c8                    	movl	%r9d, %eax
10000757e: 41 0f 47 c7                 	cmoval	%r15d, %eax
100007582: 89 45 d4                    	movl	%eax, -44(%rbp)
100007585: 45 0f 42 cf                 	cmovbl	%r15d, %r9d
100007589: 39 ce                       	cmpl	%ecx, %esi
10000758b: 89 c8                       	movl	%ecx, %eax
10000758d: 0f 47 c6                    	cmoval	%esi, %eax
100007590: 89 45 bc                    	movl	%eax, -68(%rbp)
100007593: 0f 42 ce                    	cmovbl	%esi, %ecx
100007596: 45 39 f3                    	cmpl	%r14d, %r11d
100007599: 45 89 f7                    	movl	%r14d, %r15d
10000759c: 45 0f 47 fb                 	cmoval	%r11d, %r15d
1000075a0: 45 0f 42 f3                 	cmovbl	%r11d, %r14d
1000075a4: 8b 45 d0                    	movl	-48(%rbp), %eax
1000075a7: 8b 75 cc                    	movl	-52(%rbp), %esi
1000075aa: 39 f0                       	cmpl	%esi, %eax
1000075ac: 89 f7                       	movl	%esi, %edi
1000075ae: 0f 47 f8                    	cmoval	%eax, %edi
1000075b1: 89 7d b8                    	movl	%edi, -72(%rbp)
1000075b4: 0f 42 f0                    	cmovbl	%eax, %esi
1000075b7: 89 f7                       	movl	%esi, %edi
1000075b9: 8b 75 c8                    	movl	-56(%rbp), %esi
1000075bc: 44 39 c6                    	cmpl	%r8d, %esi
1000075bf: 44 89 c0                    	movl	%r8d, %eax
1000075c2: 0f 47 c6                    	cmoval	%esi, %eax
1000075c5: 44 0f 42 c6                 	cmovbl	%esi, %r8d
1000075c9: 8b 75 c4                    	movl	-60(%rbp), %esi
1000075cc: 44 39 d6                    	cmpl	%r10d, %esi
1000075cf: 44 89 d3                    	movl	%r10d, %ebx
1000075d2: 0f 47 de                    	cmoval	%esi, %ebx
1000075d5: 41 89 db                    	movl	%ebx, %r11d
1000075d8: 44 0f 42 d6                 	cmovbl	%esi, %r10d
1000075dc: 8b 5d b4                    	movl	-76(%rbp), %ebx
1000075df: 44 39 eb                    	cmpl	%r13d, %ebx
1000075e2: 44 89 ee                    	movl	%r13d, %esi
1000075e5: 0f 47 f3                    	cmoval	%ebx, %esi
1000075e8: 44 0f 42 eb                 	cmovbl	%ebx, %r13d
1000075ec: 44 39 ca                    	cmpl	%r9d, %edx
1000075ef: 44 89 cb                    	movl	%r9d, %ebx
1000075f2: 0f 47 da                    	cmoval	%edx, %ebx
1000075f5: 89 5d d0                    	movl	%ebx, -48(%rbp)
1000075f8: 44 0f 42 ca                 	cmovbl	%edx, %r9d
1000075fc: 44 39 f1                    	cmpl	%r14d, %ecx
1000075ff: 44 89 f2                    	movl	%r14d, %edx
100007602: 0f 47 d1                    	cmoval	%ecx, %edx
100007605: 44 0f 42 f1                 	cmovbl	%ecx, %r14d
100007609: 44 39 c7                    	cmpl	%r8d, %edi
10000760c: 44 89 c1                    	movl	%r8d, %ecx
10000760f: 0f 47 cf                    	cmoval	%edi, %ecx
100007612: 89 4d c8                    	movl	%ecx, -56(%rbp)
100007615: 44 0f 42 c7                 	cmovbl	%edi, %r8d
100007619: 45 39 ea                    	cmpl	%r13d, %r10d
10000761c: 44 89 eb                    	movl	%r13d, %ebx
10000761f: 41 0f 47 da                 	cmoval	%r10d, %ebx
100007623: 45 0f 42 ea                 	cmovbl	%r10d, %r13d
100007627: 44 8b 55 d4                 	movl	-44(%rbp), %r10d
10000762b: 8b 7d c0                    	movl	-64(%rbp), %edi
10000762e: 44 39 d7                    	cmpl	%r10d, %edi
100007631: 44 89 d1                    	movl	%r10d, %ecx
100007634: 0f 47 cf                    	cmoval	%edi, %ecx
100007637: 89 4d c4                    	movl	%ecx, -60(%rbp)
10000763a: 44 0f 42 d7                 	cmovbl	%edi, %r10d
10000763e: 44 89 55 d4                 	movl	%r10d, -44(%rbp)
100007642: 8b 4d bc                    	movl	-68(%rbp), %ecx
100007645: 44 39 f9                    	cmpl	%r15d, %ecx
100007648: 45 89 fa                    	movl	%r15d, %r10d
10000764b: 44 0f 47 d1                 	cmoval	%ecx, %r10d
10000764f: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
100007653: 8b 4d b8                    	movl	-72(%rbp), %ecx
100007656: 39 c1                       	cmpl	%eax, %ecx
100007658: 89 c7                       	movl	%eax, %edi
10000765a: 0f 47 f9                    	cmoval	%ecx, %edi
10000765d: 89 7d c0                    	movl	%edi, -64(%rbp)
100007660: 0f 42 c1                    	cmovbl	%ecx, %eax
100007663: 44 89 df                    	movl	%r11d, %edi
100007666: 41 39 f3                    	cmpl	%esi, %r11d
100007669: 41 89 f3                    	movl	%esi, %r11d
10000766c: 44 0f 47 df                 	cmoval	%edi, %r11d
100007670: 0f 42 f7                    	cmovbl	%edi, %esi
100007673: 45 39 f1                    	cmpl	%r14d, %r9d
100007676: 44 89 f7                    	movl	%r14d, %edi
100007679: 41 0f 47 f9                 	cmoval	%r9d, %edi
10000767d: 89 7d cc                    	movl	%edi, -52(%rbp)
100007680: 45 0f 42 f1                 	cmovbl	%r9d, %r14d
100007684: 45 89 34 24                 	movl	%r14d, (%r12)
100007688: 45 39 e8                    	cmpl	%r13d, %r8d
10000768b: 45 89 e9                    	movl	%r13d, %r9d
10000768e: 45 0f 47 c8                 	cmoval	%r8d, %r9d
100007692: 45 0f 42 e8                 	cmovbl	%r8d, %r13d
100007696: 8b 4d d4                    	movl	-44(%rbp), %ecx
100007699: 44 39 f9                    	cmpl	%r15d, %ecx
10000769c: 45 89 fe                    	movl	%r15d, %r14d
10000769f: 44 0f 47 f1                 	cmoval	%ecx, %r14d
1000076a3: 44 0f 42 f9                 	cmovbl	%ecx, %r15d
1000076a7: 39 f0                       	cmpl	%esi, %eax
1000076a9: 89 f1                       	movl	%esi, %ecx
1000076ab: 0f 47 c8                    	cmoval	%eax, %ecx
1000076ae: 89 4d bc                    	movl	%ecx, -68(%rbp)
1000076b1: 0f 42 f0                    	cmovbl	%eax, %esi
1000076b4: 8b 45 d0                    	movl	-48(%rbp), %eax
1000076b7: 39 d0                       	cmpl	%edx, %eax
1000076b9: 89 d1                       	movl	%edx, %ecx
1000076bb: 0f 47 c8                    	cmoval	%eax, %ecx
1000076be: 89 4d d4                    	movl	%ecx, -44(%rbp)
1000076c1: 0f 42 d0                    	cmovbl	%eax, %edx
1000076c4: 8b 45 c8                    	movl	-56(%rbp), %eax
1000076c7: 39 d8                       	cmpl	%ebx, %eax
1000076c9: 41 89 d8                    	movl	%ebx, %r8d
1000076cc: 44 0f 47 c0                 	cmoval	%eax, %r8d
1000076d0: 0f 42 d8                    	cmovbl	%eax, %ebx
1000076d3: 8b 7d c4                    	movl	-60(%rbp), %edi
1000076d6: 44 39 d7                    	cmpl	%r10d, %edi
1000076d9: 44 89 d0                    	movl	%r10d, %eax
1000076dc: 0f 47 c7                    	cmoval	%edi, %eax
1000076df: 44 0f 42 d7                 	cmovbl	%edi, %r10d
1000076e3: 8b 7d c0                    	movl	-64(%rbp), %edi
1000076e6: 44 39 df                    	cmpl	%r11d, %edi
1000076e9: 44 89 d9                    	movl	%r11d, %ecx
1000076ec: 0f 47 cf                    	cmoval	%edi, %ecx
1000076ef: 44 0f 42 df                 	cmovbl	%edi, %r11d
1000076f3: 44 39 f3                    	cmpl	%r14d, %ebx
1000076f6: 44 89 f7                    	movl	%r14d, %edi
1000076f9: 0f 47 fb                    	cmoval	%ebx, %edi
1000076fc: 89 7d c8                    	movl	%edi, -56(%rbp)
1000076ff: 41 0f 43 de                 	cmovael	%r14d, %ebx
100007703: 89 5d c0                    	movl	%ebx, -64(%rbp)
100007706: 45 39 ca                    	cmpl	%r9d, %r10d
100007709: 45 89 ce                    	movl	%r9d, %r14d
10000770c: 45 0f 47 f2                 	cmoval	%r10d, %r14d
100007710: 45 0f 43 d1                 	cmovael	%r9d, %r10d
100007714: 44 89 55 c4                 	movl	%r10d, -60(%rbp)
100007718: 44 8b 55 d4                 	movl	-44(%rbp), %r10d
10000771c: 44 39 d6                    	cmpl	%r10d, %esi
10000771f: 44 89 d7                    	movl	%r10d, %edi
100007722: 0f 47 fe                    	cmoval	%esi, %edi
100007725: 89 7d d0                    	movl	%edi, -48(%rbp)
100007728: 44 0f 42 d6                 	cmovbl	%esi, %r10d
10000772c: 44 89 55 d4                 	movl	%r10d, -44(%rbp)
100007730: 41 39 c0                    	cmpl	%eax, %r8d
100007733: 41 89 c2                    	movl	%eax, %r10d
100007736: 45 0f 47 d0                 	cmoval	%r8d, %r10d
10000773a: 41 0f 42 c0                 	cmovbl	%r8d, %eax
10000773e: 8b 75 bc                    	movl	-68(%rbp), %esi
100007741: 41 39 f3                    	cmpl	%esi, %r11d
100007744: 89 f3                       	movl	%esi, %ebx
100007746: 41 0f 47 db                 	cmoval	%r11d, %ebx
10000774a: 44 0f 43 de                 	cmovael	%esi, %r11d
10000774e: 45 39 fd                    	cmpl	%r15d, %r13d
100007751: 44 89 ff                    	movl	%r15d, %edi
100007754: 41 0f 47 fd                 	cmoval	%r13d, %edi
100007758: 45 0f 42 fd                 	cmovbl	%r13d, %r15d
10000775c: 44 8b 4d cc                 	movl	-52(%rbp), %r9d
100007760: 44 39 ca                    	cmpl	%r9d, %edx
100007763: 44 89 ce                    	movl	%r9d, %esi
100007766: 0f 47 f2                    	cmoval	%edx, %esi
100007769: 41 0f 43 d1                 	cmovael	%r9d, %edx
10000776d: 41 39 d7                    	cmpl	%edx, %r15d
100007770: 41 89 d1                    	movl	%edx, %r9d
100007773: 45 0f 47 cf                 	cmoval	%r15d, %r9d
100007777: 41 89 4c 24 3c              	movl	%ecx, 60(%r12)
10000777c: 41 0f 42 d7                 	cmovbl	%r15d, %edx
100007780: 41 89 54 24 04              	movl	%edx, 4(%r12)
100007785: 41 39 c3                    	cmpl	%eax, %r11d
100007788: 41 89 c7                    	movl	%eax, %r15d
10000778b: 45 0f 47 fb                 	cmoval	%r11d, %r15d
10000778f: 44 0f 43 d8                 	cmovael	%eax, %r11d
100007793: 39 f7                       	cmpl	%esi, %edi
100007795: 89 f0                       	movl	%esi, %eax
100007797: 0f 47 c7                    	cmoval	%edi, %eax
10000779a: 0f 42 f7                    	cmovbl	%edi, %esi
10000779d: 44 39 d3                    	cmpl	%r10d, %ebx
1000077a0: 44 89 d7                    	movl	%r10d, %edi
1000077a3: 0f 47 fb                    	cmoval	%ebx, %edi
1000077a6: 41 0f 43 da                 	cmovael	%r10d, %ebx
1000077aa: 8b 55 c0                    	movl	-64(%rbp), %edx
1000077ad: 8b 4d c4                    	movl	-60(%rbp), %ecx
1000077b0: 39 ca                       	cmpl	%ecx, %edx
1000077b2: 41 89 ca                    	movl	%ecx, %r10d
1000077b5: 44 0f 47 d2                 	cmoval	%edx, %r10d
1000077b9: 41 89 7c 24 38              	movl	%edi, 56(%r12)
1000077be: 0f 42 ca                    	cmovbl	%edx, %ecx
1000077c1: 8b 7d c8                    	movl	-56(%rbp), %edi
1000077c4: 41 39 fe                    	cmpl	%edi, %r14d
1000077c7: 41 89 f8                    	movl	%edi, %r8d
1000077ca: 45 0f 47 c6                 	cmoval	%r14d, %r8d
1000077ce: 44 0f 43 f7                 	cmovael	%edi, %r14d
1000077d2: 45 89 f5                    	movl	%r14d, %r13d
1000077d5: 44 39 ce                    	cmpl	%r9d, %esi
1000077d8: 45 89 ce                    	movl	%r9d, %r14d
1000077db: 44 0f 47 f6                 	cmoval	%esi, %r14d
1000077df: 41 0f 43 f1                 	cmovael	%r9d, %esi
1000077e3: 41 89 74 24 08              	movl	%esi, 8(%r12)
1000077e8: 44 39 fb                    	cmpl	%r15d, %ebx
1000077eb: 44 89 fa                    	movl	%r15d, %edx
1000077ee: 0f 47 d3                    	cmoval	%ebx, %edx
1000077f1: 89 55 cc                    	movl	%edx, -52(%rbp)
1000077f4: 41 0f 43 df                 	cmovael	%r15d, %ebx
1000077f8: 8b 55 d4                    	movl	-44(%rbp), %edx
1000077fb: 39 c2                       	cmpl	%eax, %edx
1000077fd: 89 c7                       	movl	%eax, %edi
1000077ff: 0f 47 fa                    	cmoval	%edx, %edi
100007802: 0f 42 c2                    	cmovbl	%edx, %eax
100007805: 8b 55 d0                    	movl	-48(%rbp), %edx
100007808: 41 39 d3                    	cmpl	%edx, %r11d
10000780b: 89 d6                       	movl	%edx, %esi
10000780d: 41 0f 47 f3                 	cmoval	%r11d, %esi
100007811: 44 0f 43 da                 	cmovael	%edx, %r11d
100007815: 41 39 fa                    	cmpl	%edi, %r10d
100007818: 41 89 ff                    	movl	%edi, %r15d
10000781b: 45 0f 47 fa                 	cmoval	%r10d, %r15d
10000781f: 41 0f 42 fa                 	cmovbl	%r10d, %edi
100007823: 41 39 f0                    	cmpl	%esi, %r8d
100007826: 41 89 f1                    	movl	%esi, %r9d
100007829: 45 0f 47 c8                 	cmoval	%r8d, %r9d
10000782d: 41 0f 42 f0                 	cmovbl	%r8d, %esi
100007831: 39 c8                       	cmpl	%ecx, %eax
100007833: 89 ca                       	movl	%ecx, %edx
100007835: 0f 47 d0                    	cmoval	%eax, %edx
100007838: 0f 43 c1                    	cmovael	%ecx, %eax
10000783b: 45 39 eb                    	cmpl	%r13d, %r11d
10000783e: 45 89 e8                    	movl	%r13d, %r8d
100007841: 45 0f 47 c3                 	cmoval	%r11d, %r8d
100007845: 45 0f 43 dd                 	cmovael	%r13d, %r11d
100007849: 44 39 f0                    	cmpl	%r14d, %eax
10000784c: 45 89 f2                    	movl	%r14d, %r10d
10000784f: 44 0f 47 d0                 	cmoval	%eax, %r10d
100007853: 8b 4d cc                    	movl	-52(%rbp), %ecx
100007856: 41 89 4c 24 34              	movl	%ecx, 52(%r12)
10000785b: 41 0f 43 c6                 	cmovael	%r14d, %eax
10000785f: 41 89 44 24 0c              	movl	%eax, 12(%r12)
100007864: 39 fa                       	cmpl	%edi, %edx
100007866: 89 f8                       	movl	%edi, %eax
100007868: 0f 47 c2                    	cmoval	%edx, %eax
10000786b: 45 89 54 24 10              	movl	%r10d, 16(%r12)
100007870: 0f 43 d7                    	cmovael	%edi, %edx
100007873: 41 89 54 24 14              	movl	%edx, 20(%r12)
100007878: 45 39 fb                    	cmpl	%r15d, %r11d
10000787b: 44 89 fa                    	movl	%r15d, %edx
10000787e: 41 0f 47 d3                 	cmoval	%r11d, %edx
100007882: 45 0f 43 df                 	cmovael	%r15d, %r11d
100007886: 41 39 f0                    	cmpl	%esi, %r8d
100007889: 89 f7                       	movl	%esi, %edi
10000788b: 41 0f 47 f8                 	cmoval	%r8d, %edi
10000788f: 44 0f 43 c6                 	cmovael	%esi, %r8d
100007893: 41 89 7c 24 28              	movl	%edi, 40(%r12)
100007898: 44 39 cb                    	cmpl	%r9d, %ebx
10000789b: 44 89 ce                    	movl	%r9d, %esi
10000789e: 0f 47 f3                    	cmoval	%ebx, %esi
1000078a1: 44 0f 42 cb                 	cmovbl	%ebx, %r9d
1000078a5: 45 89 4c 24 2c              	movl	%r9d, 44(%r12)
1000078aa: 41 89 74 24 30              	movl	%esi, 48(%r12)
1000078af: 44 39 d8                    	cmpl	%r11d, %eax
1000078b2: 44 89 de                    	movl	%r11d, %esi
1000078b5: 0f 47 f0                    	cmoval	%eax, %esi
1000078b8: 44 0f 42 d8                 	cmovbl	%eax, %r11d
1000078bc: 45 89 5c 24 18              	movl	%r11d, 24(%r12)
1000078c1: 41 89 74 24 1c              	movl	%esi, 28(%r12)
1000078c6: 44 39 c2                    	cmpl	%r8d, %edx
1000078c9: 44 89 c0                    	movl	%r8d, %eax
1000078cc: 0f 47 c2                    	cmoval	%edx, %eax
1000078cf: 44 0f 42 c2                 	cmovbl	%edx, %r8d
1000078d3: 45 89 44 24 20              	movl	%r8d, 32(%r12)
1000078d8: 41 89 44 24 24              	movl	%eax, 36(%r12)
1000078dd: 48 83 c4 28                 	addq	$40, %rsp
1000078e1: 5b                          	popq	%rbx
1000078e2: 41 5c                       	popq	%r12
1000078e4: 41 5d                       	popq	%r13
1000078e6: 41 5e                       	popq	%r14
1000078e8: 41 5f                       	popq	%r15
1000078ea: 5d                          	popq	%rbp
1000078eb: c3                          	retq
1000078ec: f1                          	<unknown>
1000078ed: ff ff                       	<unknown>
1000078ef: ff f1                       	pushq	%rcx
1000078f1: ff ff                       	<unknown>
1000078f3: ff 8a e4 ff ff 86           	decl	-2030043164(%rdx)
1000078f9: e5 ff                       	inl	$255, %eax
1000078fb: ff c5                       	incl	%ebp
1000078fd: e5 ff                       	inl	$255, %eax
1000078ff: ff 22                       	jmpq	*(%rdx)
100007901: e6 ff                       	outb	%al, $255
100007903: ff b1 e6 ff ff 6d           	pushq	1845493734(%rcx)
100007909: e7 ff                       	outl	%eax, $255
10000790b: ff 6d e8                    	ljmpl	*-24(%rbp)
10000790e: ff ff                       	<unknown>
100007910: a3 e9 ff ff 29 eb ff ff ff  	movabsl	%eax, -89489670167
100007919: ec                          	inb	%dx, %al
10000791a: ff ff                       	<unknown>
10000791c: 21 ef                       	andl	%ebp, %edi
10000791e: ff ff                       	<unknown>
100007920: a1 f1 ff ff 86 f4 ff ff fc  	movabsl	-216172831388467215, %eax
100007929: f7 ff                       	idivl	%edi
10000792b: ff c1                       	incl	%ecx
10000792d: fb                          	sti
10000792e: ff ff                       	<unknown>

0000000100007930 _call_quick_sort:
100007930: 55                          	pushq	%rbp
100007931: 48 89 e5                    	movq	%rsp, %rbp
100007934: 83 ff 02                    	cmpl	$2, %edi
100007937: 73 02                       	jae	2 <_call_quick_sort+0xb>
100007939: 5d                          	popq	%rbp
10000793a: c3                          	retq
10000793b: 89 fa                       	movl	%edi, %edx
10000793d: 48 ff ca                    	decq	%rdx
100007940: 48 89 f7                    	movq	%rsi, %rdi
100007943: 31 f6                       	xorl	%esi, %esi
100007945: 5d                          	popq	%rbp
100007946: e9 c5 e2 ff ff              	jmp	-7483 <_test_quick_sort_recursive>
10000794b: 0f 1f 44 00 00              	nopl	(%rax,%rax)

0000000100007950 _main:
100007950: 55                          	pushq	%rbp
100007951: 48 89 e5                    	movq	%rsp, %rbp
100007954: 41 57                       	pushq	%r15
100007956: 41 56                       	pushq	%r14
100007958: 41 55                       	pushq	%r13
10000795a: 41 54                       	pushq	%r12
10000795c: 53                          	pushq	%rbx
10000795d: 50                          	pushq	%rax
10000795e: 48 8d 35 5b c7 ff ff        	leaq	-14501(%rip), %rsi
100007965: bf 80 00 00 00              	movl	$128, %edi
10000796a: e8 c1 01 00 00              	callq	449 <_bench_insert_sort>
10000796f: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
100007974: c5 f9 62 05 64 05 00 00     	vpunpckldq	1380(%rip), %xmm0, %xmm0
10000797c: c5 f9 5c 05 6c 05 00 00     	vsubpd	1388(%rip), %xmm0, %xmm0
100007984: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
10000798a: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
10000798e: c5 fb 5e 05 6a 05 00 00     	vdivsd	1386(%rip), %xmm0, %xmm0
100007996: 4c 8d 3d 79 05 00 00        	leaq	1401(%rip), %r15
10000799d: 4c 89 ff                    	movq	%r15, %rdi
1000079a0: be 80 00 00 00              	movl	$128, %esi
1000079a5: b0 01                       	movb	$1, %al
1000079a7: e8 ea 04 00 00              	callq	1258 <dyld_stub_binder+0x100007e96>
1000079ac: 4c 8d 25 4d e2 ff ff        	leaq	-7603(%rip), %r12
1000079b3: bf 80 00 00 00              	movl	$128, %edi
1000079b8: 4c 89 e6                    	movq	%r12, %rsi
1000079bb: e8 70 01 00 00              	callq	368 <_bench_insert_sort>
1000079c0: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
1000079c5: c5 f9 62 05 13 05 00 00     	vpunpckldq	1299(%rip), %xmm0, %xmm0
1000079cd: c5 f9 5c 05 1b 05 00 00     	vsubpd	1307(%rip), %xmm0, %xmm0
1000079d5: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
1000079db: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
1000079df: c5 fb 5e 05 19 05 00 00     	vdivsd	1305(%rip), %xmm0, %xmm0
1000079e7: 48 8d 1d 45 05 00 00        	leaq	1349(%rip), %rbx
1000079ee: 48 89 df                    	movq	%rbx, %rdi
1000079f1: be 80 00 00 00              	movl	$128, %esi
1000079f6: b0 01                       	movb	$1, %al
1000079f8: e8 99 04 00 00              	callq	1177 <dyld_stub_binder+0x100007e96>
1000079fd: 4c 8d 2d 2c ff ff ff        	leaq	-212(%rip), %r13
100007a04: bf 80 00 00 00              	movl	$128, %edi
100007a09: 4c 89 ee                    	movq	%r13, %rsi
100007a0c: e8 1f 01 00 00              	callq	287 <_bench_insert_sort>
100007a11: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
100007a16: c5 f9 62 05 c2 04 00 00     	vpunpckldq	1218(%rip), %xmm0, %xmm0
100007a1e: c5 f9 5c 05 ca 04 00 00     	vsubpd	1226(%rip), %xmm0, %xmm0
100007a26: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100007a2c: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100007a30: c5 fb 5e 05 c8 04 00 00     	vdivsd	1224(%rip), %xmm0, %xmm0
100007a38: 4c 8d 35 10 05 00 00        	leaq	1296(%rip), %r14
100007a3f: 4c 89 f7                    	movq	%r14, %rdi
100007a42: be 80 00 00 00              	movl	$128, %esi
100007a47: b0 01                       	movb	$1, %al
100007a49: e8 48 04 00 00              	callq	1096 <dyld_stub_binder+0x100007e96>
100007a4e: bf 00 01 00 00              	movl	$256, %edi
100007a53: 48 8d 35 66 c6 ff ff        	leaq	-14746(%rip), %rsi
100007a5a: e8 d1 00 00 00              	callq	209 <_bench_insert_sort>
100007a5f: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
100007a64: c5 f9 62 05 74 04 00 00     	vpunpckldq	1140(%rip), %xmm0, %xmm0
100007a6c: c5 f9 5c 05 7c 04 00 00     	vsubpd	1148(%rip), %xmm0, %xmm0
100007a74: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100007a7a: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100007a7e: c5 fb 5e 05 7a 04 00 00     	vdivsd	1146(%rip), %xmm0, %xmm0
100007a86: 4c 89 ff                    	movq	%r15, %rdi
100007a89: be 00 01 00 00              	movl	$256, %esi
100007a8e: b0 01                       	movb	$1, %al
100007a90: e8 01 04 00 00              	callq	1025 <dyld_stub_binder+0x100007e96>
100007a95: bf 00 01 00 00              	movl	$256, %edi
100007a9a: 4c 89 e6                    	movq	%r12, %rsi
100007a9d: e8 8e 00 00 00              	callq	142 <_bench_insert_sort>
100007aa2: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
100007aa7: c5 f9 62 05 31 04 00 00     	vpunpckldq	1073(%rip), %xmm0, %xmm0
100007aaf: c5 f9 5c 05 39 04 00 00     	vsubpd	1081(%rip), %xmm0, %xmm0
100007ab7: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100007abd: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100007ac1: c5 fb 5e 05 37 04 00 00     	vdivsd	1079(%rip), %xmm0, %xmm0
100007ac9: 48 89 df                    	movq	%rbx, %rdi
100007acc: be 00 01 00 00              	movl	$256, %esi
100007ad1: b0 01                       	movb	$1, %al
100007ad3: e8 be 03 00 00              	callq	958 <dyld_stub_binder+0x100007e96>
100007ad8: bf 00 01 00 00              	movl	$256, %edi
100007add: 4c 89 ee                    	movq	%r13, %rsi
100007ae0: e8 4b 00 00 00              	callq	75 <_bench_insert_sort>
100007ae5: c4 e1 f9 6e c0              	vmovq	%rax, %xmm0
100007aea: c5 f9 62 05 ee 03 00 00     	vpunpckldq	1006(%rip), %xmm0, %xmm0
100007af2: c5 f9 5c 05 f6 03 00 00     	vsubpd	1014(%rip), %xmm0, %xmm0
100007afa: c4 e3 79 05 c8 01           	vpermilpd	$1, %xmm0, %xmm1
100007b00: c5 f3 58 c0                 	vaddsd	%xmm0, %xmm1, %xmm0
100007b04: c5 fb 5e 05 f4 03 00 00     	vdivsd	1012(%rip), %xmm0, %xmm0
100007b0c: 4c 89 f7                    	movq	%r14, %rdi
100007b0f: be 00 01 00 00              	movl	$256, %esi
100007b14: b0 01                       	movb	$1, %al
100007b16: e8 7b 03 00 00              	callq	891 <dyld_stub_binder+0x100007e96>
100007b1b: 31 c0                       	xorl	%eax, %eax
100007b1d: 48 83 c4 08                 	addq	$8, %rsp
100007b21: 5b                          	popq	%rbx
100007b22: 41 5c                       	popq	%r12
100007b24: 41 5d                       	popq	%r13
100007b26: 41 5e                       	popq	%r14
100007b28: 41 5f                       	popq	%r15
100007b2a: 5d                          	popq	%rbp
100007b2b: c3                          	retq
100007b2c: 0f 1f 40 00                 	nopl	(%rax)

0000000100007b30 _bench_insert_sort:
100007b30: 55                          	pushq	%rbp
100007b31: 48 89 e5                    	movq	%rsp, %rbp
100007b34: 41 57                       	pushq	%r15
100007b36: 41 56                       	pushq	%r14
100007b38: 41 55                       	pushq	%r13
100007b3a: 41 54                       	pushq	%r12
100007b3c: 53                          	pushq	%rbx
100007b3d: 48 83 ec 58                 	subq	$88, %rsp
100007b41: 48 89 75 b8                 	movq	%rsi, -72(%rbp)
100007b45: 49 bd 2d 7f 95 4c 2d f4 51 58       	movabsq	$6364136223846793005, %r13
100007b4f: 89 7d d4                    	movl	%edi, -44(%rbp)
100007b52: 4c 63 f7                    	movslq	%edi, %r14
100007b55: 4a 8d 1c b5 00 00 00 00     	leaq	(,%r14,4), %rbx
100007b5d: 48 89 df                    	movq	%rbx, %rdi
100007b60: e8 2b 03 00 00              	callq	811 <dyld_stub_binder+0x100007e90>
100007b65: 49 89 c4                    	movq	%rax, %r12
100007b68: 48 89 df                    	movq	%rbx, %rdi
100007b6b: e8 20 03 00 00              	callq	800 <dyld_stub_binder+0x100007e90>
100007b70: 48 89 c3                    	movq	%rax, %rbx
100007b73: 45 89 f6                    	movl	%r14d, %r14d
100007b76: 49 8d 46 ff                 	leaq	-1(%r14), %rax
100007b7a: 89 c1                       	movl	%eax, %ecx
100007b7c: 83 e1 01                    	andl	$1, %ecx
100007b7f: 48 89 4d c0                 	movq	%rcx, -64(%rbp)
100007b83: 48 83 e0 fe                 	andq	$-2, %rax
100007b87: 48 89 45 c8                 	movq	%rax, -56(%rbp)
100007b8b: 31 c0                       	xorl	%eax, %eax
100007b8d: 45 31 ff                    	xorl	%r15d, %r15d
100007b90: 31 c9                       	xorl	%ecx, %ecx
100007b92: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100007b9c: 0f 1f 40 00                 	nopl	(%rax)
100007ba0: 48 89 4d b0                 	movq	%rcx, -80(%rbp)
100007ba4: 48 89 45 a8                 	movq	%rax, -88(%rbp)
100007ba8: 48 8d 3d 71 44 00 00        	leaq	17521(%rip), %rdi
100007baf: ff 17                       	callq	*(%rdi)
100007bb1: 48 8b 10                    	movq	(%rax), %rdx
100007bb4: 45 89 f0                    	movl	%r14d, %r8d
100007bb7: 41 83 e0 01                 	andl	$1, %r8d
100007bbb: 83 7d d4 01                 	cmpl	$1, -44(%rbp)
100007bbf: 75 0f                       	jne	15 <_bench_insert_sort+0xa0>
100007bc1: 45 31 d2                    	xorl	%r10d, %r10d
100007bc4: e9 c1 00 00 00              	jmp	193 <_bench_insert_sort+0x15a>
100007bc9: 0f 1f 80 00 00 00 00        	nopl	(%rax)
100007bd0: 4d 89 f1                    	movq	%r14, %r9
100007bd3: 4d 29 c1                    	subq	%r8, %r9
100007bd6: 45 31 d2                    	xorl	%r10d, %r10d
100007bd9: 0f 1f 80 00 00 00 00        	nopl	(%rax)
100007be0: 48 89 d1                    	movq	%rdx, %rcx
100007be3: 49 0f af d5                 	imulq	%r13, %rdx
100007be7: 48 ff c2                    	incq	%rdx
100007bea: 48 89 c8                    	movq	%rcx, %rax
100007bed: 48 c1 e8 2d                 	shrq	$45, %rax
100007bf1: 48 89 cf                    	movq	%rcx, %rdi
100007bf4: 48 c1 ef 1b                 	shrq	$27, %rdi
100007bf8: 31 f8                       	xorl	%edi, %eax
100007bfa: 48 c1 e9 3b                 	shrq	$59, %rcx
100007bfe: d3 c8                       	rorl	%cl, %eax
100007c00: 83 f8 02                    	cmpl	$2, %eax
100007c03: 72 db                       	jb	-37 <_bench_insert_sort+0xb0>
100007c05: 89 c1                       	movl	%eax, %ecx
100007c07: 48 8d 0c 49                 	leaq	(%rcx,%rcx,2), %rcx
100007c0b: 48 c1 e9 20                 	shrq	$32, %rcx
100007c0f: 89 c7                       	movl	%eax, %edi
100007c11: 29 cf                       	subl	%ecx, %edi
100007c13: d1 ef                       	shrl	%edi
100007c15: 01 cf                       	addl	%ecx, %edi
100007c17: c1 ef 1e                    	shrl	$30, %edi
100007c1a: 89 f9                       	movl	%edi, %ecx
100007c1c: c1 e1 1f                    	shll	$31, %ecx
100007c1f: 29 cf                       	subl	%ecx, %edi
100007c21: 01 c7                       	addl	%eax, %edi
100007c23: 43 89 3c 94                 	movl	%edi, (%r12,%r10,4)
100007c27: 42 89 3c 93                 	movl	%edi, (%rbx,%r10,4)
100007c2b: 4c 89 d0                    	movq	%r10, %rax
100007c2e: 48 83 c8 01                 	orq	$1, %rax
100007c32: 48 89 d1                    	movq	%rdx, %rcx
100007c35: 49 0f af d5                 	imulq	%r13, %rdx
100007c39: 48 ff c2                    	incq	%rdx
100007c3c: 48 89 cf                    	movq	%rcx, %rdi
100007c3f: 48 c1 ef 2d                 	shrq	$45, %rdi
100007c43: 48 89 ce                    	movq	%rcx, %rsi
100007c46: 48 c1 ee 1b                 	shrq	$27, %rsi
100007c4a: 31 f7                       	xorl	%esi, %edi
100007c4c: 48 c1 e9 3b                 	shrq	$59, %rcx
100007c50: d3 cf                       	rorl	%cl, %edi
100007c52: 83 ff 02                    	cmpl	$2, %edi
100007c55: 72 db                       	jb	-37 <_bench_insert_sort+0x102>
100007c57: 89 f9                       	movl	%edi, %ecx
100007c59: 48 8d 0c 49                 	leaq	(%rcx,%rcx,2), %rcx
100007c5d: 48 c1 e9 20                 	shrq	$32, %rcx
100007c61: 89 fe                       	movl	%edi, %esi
100007c63: 29 ce                       	subl	%ecx, %esi
100007c65: d1 ee                       	shrl	%esi
100007c67: 01 ce                       	addl	%ecx, %esi
100007c69: c1 ee 1e                    	shrl	$30, %esi
100007c6c: 89 f1                       	movl	%esi, %ecx
100007c6e: c1 e1 1f                    	shll	$31, %ecx
100007c71: 29 ce                       	subl	%ecx, %esi
100007c73: 01 fe                       	addl	%edi, %esi
100007c75: 41 89 34 84                 	movl	%esi, (%r12,%rax,4)
100007c79: 89 34 83                    	movl	%esi, (%rbx,%rax,4)
100007c7c: 49 83 c2 02                 	addq	$2, %r10
100007c80: 49 83 c1 fe                 	addq	$-2, %r9
100007c84: 0f 85 56 ff ff ff           	jne	-170 <_bench_insert_sort+0xb0>
100007c8a: 4d 85 c0                    	testq	%r8, %r8
100007c8d: 74 4b                       	je	75 <_bench_insert_sort+0x1aa>
100007c8f: 48 89 d1                    	movq	%rdx, %rcx
100007c92: 49 0f af d5                 	imulq	%r13, %rdx
100007c96: 48 ff c2                    	incq	%rdx
100007c99: 48 89 c8                    	movq	%rcx, %rax
100007c9c: 48 c1 e8 2d                 	shrq	$45, %rax
100007ca0: 48 89 cf                    	movq	%rcx, %rdi
100007ca3: 48 c1 ef 1b                 	shrq	$27, %rdi
100007ca7: 31 f8                       	xorl	%edi, %eax
100007ca9: 48 c1 e9 3b                 	shrq	$59, %rcx
100007cad: d3 c8                       	rorl	%cl, %eax
100007caf: 83 f8 02                    	cmpl	$2, %eax
100007cb2: 72 db                       	jb	-37 <_bench_insert_sort+0x15f>
100007cb4: 89 c1                       	movl	%eax, %ecx
100007cb6: 48 8d 0c 49                 	leaq	(%rcx,%rcx,2), %rcx
100007cba: 48 c1 e9 20                 	shrq	$32, %rcx
100007cbe: 89 c7                       	movl	%eax, %edi
100007cc0: 29 cf                       	subl	%ecx, %edi
100007cc2: d1 ef                       	shrl	%edi
100007cc4: 01 cf                       	addl	%ecx, %edi
100007cc6: c1 ef 1e                    	shrl	$30, %edi
100007cc9: 89 f9                       	movl	%edi, %ecx
100007ccb: c1 e1 1f                    	shll	$31, %ecx
100007cce: 29 cf                       	subl	%ecx, %edi
100007cd0: 01 c7                       	addl	%eax, %edi
100007cd2: 43 89 3c 94                 	movl	%edi, (%r12,%r10,4)
100007cd6: 42 89 3c 93                 	movl	%edi, (%rbx,%r10,4)
100007cda: 48 8d 3d 3f 43 00 00        	leaq	17215(%rip), %rdi
100007ce1: ff 17                       	callq	*(%rdi)
100007ce3: 48 89 10                    	movq	%rdx, (%rax)
100007ce6: b8 01 00 00 00              	movl	$1, %eax
100007ceb: 83 7d d4 02                 	cmpl	$2, -44(%rbp)
100007cef: 0f 85 eb 00 00 00           	jne	235 <_bench_insert_sort+0x2b0>
100007cf5: 48 83 7d c0 00              	cmpq	$0, -64(%rbp)
100007cfa: 74 2b                       	je	43 <_bench_insert_sort+0x1f7>
100007cfc: 8b 0c 83                    	movl	(%rbx,%rax,4), %ecx
100007cff: 48 8d 14 83                 	leaq	(%rbx,%rax,4), %rdx
100007d03: ff c8                       	decl	%eax
100007d05: 66 2e 0f 1f 84 00 00 00 00 00       	nopw	%cs:(%rax,%rax)
100007d0f: 90                          	nop
100007d10: 89 c0                       	movl	%eax, %eax
100007d12: 8b 34 83                    	movl	(%rbx,%rax,4), %esi
100007d15: 39 ce                       	cmpl	%ecx, %esi
100007d17: 76 0e                       	jbe	14 <_bench_insert_sort+0x1f7>
100007d19: 89 32                       	movl	%esi, (%rdx)
100007d1b: 89 0c 83                    	movl	%ecx, (%rbx,%rax,4)
100007d1e: 48 83 c2 fc                 	addq	$-4, %rdx
100007d22: 83 c0 ff                    	addl	$-1, %eax
100007d25: 72 e9                       	jb	-23 <_bench_insert_sort+0x1e0>
100007d27: bf 06 00 00 00              	movl	$6, %edi
100007d2c: 48 8d 75 88                 	leaq	-120(%rbp), %rsi
100007d30: e8 55 01 00 00              	callq	341 <dyld_stub_binder+0x100007e8a>
100007d35: 8b 7d d4                    	movl	-44(%rbp), %edi
100007d38: 4c 89 e6                    	movq	%r12, %rsi
100007d3b: ff 55 b8                    	callq	*-72(%rbp)
100007d3e: bf 06 00 00 00              	movl	$6, %edi
100007d43: 48 8d 75 98                 	leaq	-104(%rbp), %rsi
100007d47: e8 3e 01 00 00              	callq	318 <dyld_stub_binder+0x100007e8a>
100007d4c: 31 c0                       	xorl	%eax, %eax
100007d4e: 66 90                       	nop
100007d50: 41 8b 0c 84                 	movl	(%r12,%rax,4), %ecx
100007d54: 3b 0c 83                    	cmpl	(%rbx,%rax,4), %ecx
100007d57: 0f 85 07 01 00 00           	jne	263 <_bench_insert_sort+0x334>
100007d5d: 48 ff c0                    	incq	%rax
100007d60: 49 39 c6                    	cmpq	%rax, %r14
100007d63: 75 eb                       	jne	-21 <_bench_insert_sort+0x220>
100007d65: 48 8b 4d a0                 	movq	-96(%rbp), %rcx
100007d69: 48 2b 4d 90                 	subq	-112(%rbp), %rcx
100007d6d: 48 81 c1 00 ca 9a 3b        	addq	$1000000000, %rcx
100007d74: 48 89 c8                    	movq	%rcx, %rax
100007d77: 48 c1 e8 09                 	shrq	$9, %rax
100007d7b: 48 ba 53 5a 9b a0 2f b8 44 00       	movabsq	$19342813113834067, %rdx
100007d85: 48 f7 e2                    	mulq	%rdx
100007d88: 48 c1 ea 0b                 	shrq	$11, %rdx
100007d8c: 69 c2 00 ca 9a 3b           	imull	$1000000000, %edx, %eax
100007d92: 29 c1                       	subl	%eax, %ecx
100007d94: 48 8b 45 88                 	movq	-120(%rbp), %rax
100007d98: 48 f7 d0                    	notq	%rax
100007d9b: 48 01 d0                    	addq	%rdx, %rax
100007d9e: 48 03 45 98                 	addq	-104(%rbp), %rax
100007da2: 41 01 cf                    	addl	%ecx, %r15d
100007da5: 44 89 f9                    	movl	%r15d, %ecx
100007da8: c1 e9 09                    	shrl	$9, %ecx
100007dab: 48 69 c9 83 4b 04 00        	imulq	$281475, %rcx, %rcx
100007db2: 48 c1 e9 27                 	shrq	$39, %rcx
100007db6: 69 d1 00 ca 9a 3b           	imull	$1000000000, %ecx, %edx
100007dbc: 41 29 d7                    	subl	%edx, %r15d
100007dbf: 48 01 c1                    	addq	%rax, %rcx
100007dc2: 48 8b 45 a8                 	movq	-88(%rbp), %rax
100007dc6: 48 01 c8                    	addq	%rcx, %rax
100007dc9: 48 8b 4d b0                 	movq	-80(%rbp), %rcx
100007dcd: 48 ff c1                    	incq	%rcx
100007dd0: 48 81 f9 50 c3 00 00        	cmpq	$50000, %rcx
100007dd7: 0f 85 c3 fd ff ff           	jne	-573 <_bench_insert_sort+0x70>
100007ddd: eb 6c                       	jmp	108 <_bench_insert_sort+0x31b>
100007ddf: 90                          	nop
100007de0: b8 01 00 00 00              	movl	$1, %eax
100007de5: 45 31 c9                    	xorl	%r9d, %r9d
100007de8: 4c 8b 45 c8                 	movq	-56(%rbp), %r8
100007dec: eb 14                       	jmp	20 <_bench_insert_sort+0x2d2>
100007dee: 66 90                       	nop
100007df0: 48 83 c0 02                 	addq	$2, %rax
100007df4: 49 83 c1 02                 	addq	$2, %r9
100007df8: 49 83 c0 fe                 	addq	$-2, %r8
100007dfc: 0f 84 f3 fe ff ff           	je	-269 <_bench_insert_sort+0x1c5>
100007e02: 8b 34 83                    	movl	(%rbx,%rax,4), %esi
100007e05: 4c 89 cf                    	movq	%r9, %rdi
100007e08: 0f 1f 84 00 00 00 00 00     	nopl	(%rax,%rax)
100007e10: 89 fa                       	movl	%edi, %edx
100007e12: 8b 0c 93                    	movl	(%rbx,%rdx,4), %ecx
100007e15: 39 f1                       	cmpl	%esi, %ecx
100007e17: 76 0f                       	jbe	15 <_bench_insert_sort+0x2f8>
100007e19: 89 4c bb 04                 	movl	%ecx, 4(%rbx,%rdi,4)
100007e1d: 89 34 93                    	movl	%esi, (%rbx,%rdx,4)
100007e20: 48 ff cf                    	decq	%rdi
100007e23: 83 ff ff                    	cmpl	$-1, %edi
100007e26: 75 e8                       	jne	-24 <_bench_insert_sort+0x2e0>
100007e28: 8b 74 83 04                 	movl	4(%rbx,%rax,4), %esi
100007e2c: 4c 89 cf                    	movq	%r9, %rdi
100007e2f: 90                          	nop
100007e30: 8d 57 01                    	leal	1(%rdi), %edx
100007e33: 8b 0c 93                    	movl	(%rbx,%rdx,4), %ecx
100007e36: 39 f1                       	cmpl	%esi, %ecx
100007e38: 76 b6                       	jbe	-74 <_bench_insert_sort+0x2c0>
100007e3a: 89 4c bb 08                 	movl	%ecx, 8(%rbx,%rdi,4)
100007e3e: 89 34 93                    	movl	%esi, (%rbx,%rdx,4)
100007e41: 48 ff cf                    	decq	%rdi
100007e44: 83 ff fe                    	cmpl	$-2, %edi
100007e47: 75 e7                       	jne	-25 <_bench_insert_sort+0x300>
100007e49: eb a5                       	jmp	-91 <_bench_insert_sort+0x2c0>
100007e4b: 48 69 c0 00 ca 9a 3b        	imulq	$1000000000, %rax, %rax
100007e52: 4c 01 f8                    	addq	%r15, %rax
100007e55: 48 83 c4 58                 	addq	$88, %rsp
100007e59: 5b                          	popq	%rbx
100007e5a: 41 5c                       	popq	%r12
100007e5c: 41 5d                       	popq	%r13
100007e5e: 41 5e                       	popq	%r14
100007e60: 41 5f                       	popq	%r15
100007e62: 5d                          	popq	%rbp
100007e63: c3                          	retq
100007e64: 48 8d 3d 00 01 00 00        	leaq	256(%rip), %rdi
100007e6b: 48 8d 35 96 00 00 00        	leaq	150(%rip), %rsi
100007e72: 48 8d 0d 04 01 00 00        	leaq	260(%rip), %rcx
100007e79: ba 8c 00 00 00              	movl	$140, %edx
100007e7e: e8 01 00 00 00              	callq	1 <dyld_stub_binder+0x100007e84>

Disassembly of section __TEXT,__stubs:

0000000100007e84 __stubs:
100007e84: ff 25 76 41 00 00           	jmpq	*16758(%rip)
100007e8a: ff 25 78 41 00 00           	jmpq	*16760(%rip)
100007e90: ff 25 7a 41 00 00           	jmpq	*16762(%rip)
100007e96: ff 25 7c 41 00 00           	jmpq	*16764(%rip)

Disassembly of section __TEXT,__stub_helper:

0000000100007e9c __stub_helper:
100007e9c: 4c 8d 1d 95 41 00 00        	leaq	16789(%rip), %r11
100007ea3: 41 53                       	pushq	%r11
100007ea5: ff 25 55 01 00 00           	jmpq	*341(%rip)
100007eab: 90                          	nop
100007eac: 68 00 00 00 00              	pushq	$0
100007eb1: e9 e6 ff ff ff              	jmp	-26 <__stub_helper>
100007eb6: 68 14 00 00 00              	pushq	$20
100007ebb: e9 dc ff ff ff              	jmp	-36 <__stub_helper>
100007ec0: 68 29 00 00 00              	pushq	$41
100007ec5: e9 d2 ff ff ff              	jmp	-46 <__stub_helper>
100007eca: 68 37 00 00 00              	pushq	$55
100007ecf: e9 c8 ff ff ff              	jmp	-56 <__stub_helper>
