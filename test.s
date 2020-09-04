
test/.pobj/sort_test.o:	file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _main:
       0: 55                           	pushq	%rbp
       1: 48 89 e5                     	movq	%rsp, %rbp
       4: 53                           	pushq	%rbx
       5: 48 83 ec 28                  	subq	$40, %rsp
       9: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      10: 48 8b 00                     	movq	(%rax), %rax
      13: 48 89 45 f0                  	movq	%rax, -16(%rbp)
      17: 83 ff 05                     	cmpl	$5, %edi
      1a: 7d 1f                        	jge	31 <_main+0x3b>
      1c: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      23: 48 8b 38                     	movq	(%rax), %rdi
      26: 48 8d 35 a0 01 00 00         	leaq	416(%rip), %rsi
      2d: ba 04 00 00 00               	movl	$4, %edx
      32: 31 c0                        	xorl	%eax, %eax
      34: e8 00 00 00 00               	callq	0 <_main+0x39>
      39: eb 42                        	jmp	66 <_main+0x7d>
      3b: 48 89 f3                     	movq	%rsi, %rbx
      3e: 48 8b 7e 08                  	movq	8(%rsi), %rdi
      42: 48 8d 75 d8                  	leaq	-40(%rbp), %rsi
      46: ba 0a 00 00 00               	movl	$10, %edx
      4b: e8 00 00 00 00               	callq	0 <_main+0x50>
      50: 89 45 e0                     	movl	%eax, -32(%rbp)
      53: 48 8b 53 08                  	movq	8(%rbx), %rdx
      57: 80 3a 00                     	cmpb	$0, (%rdx)
      5a: 74 09                        	je	9 <_main+0x65>
      5c: 48 8b 45 d8                  	movq	-40(%rbp), %rax
      60: 80 38 00                     	cmpb	$0, (%rax)
      63: 74 3a                        	je	58 <_main+0x9f>
      65: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      6c: 48 8b 38                     	movq	(%rax), %rdi
      6f: 48 8d 35 6f 01 00 00         	leaq	367(%rip), %rsi
      76: 31 c0                        	xorl	%eax, %eax
      78: e8 00 00 00 00               	callq	0 <_main+0x7d>
      7d: bb ff ff ff ff               	movl	$4294967295, %ebx
      82: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
      89: 48 8b 00                     	movq	(%rax), %rax
      8c: 48 3b 45 f0                  	cmpq	-16(%rbp), %rax
      90: 0f 85 c4 00 00 00            	jne	196 <_main+0x15a>
      96: 89 d8                        	movl	%ebx, %eax
      98: 48 83 c4 28                  	addq	$40, %rsp
      9c: 5b                           	popq	%rbx
      9d: 5d                           	popq	%rbp
      9e: c3                           	retq
      9f: 48 8b 7b 10                  	movq	16(%rbx), %rdi
      a3: 48 8d 75 d8                  	leaq	-40(%rbp), %rsi
      a7: ba 0a 00 00 00               	movl	$10, %edx
      ac: e8 00 00 00 00               	callq	0 <_main+0xb1>
      b1: 89 45 e4                     	movl	%eax, -28(%rbp)
      b4: 48 8b 53 10                  	movq	16(%rbx), %rdx
      b8: 80 3a 00                     	cmpb	$0, (%rdx)
      bb: 74 a8                        	je	-88 <_main+0x65>
      bd: 48 8b 45 d8                  	movq	-40(%rbp), %rax
      c1: 80 38 00                     	cmpb	$0, (%rax)
      c4: 75 9f                        	jne	-97 <_main+0x65>
      c6: 48 8b 7b 18                  	movq	24(%rbx), %rdi
      ca: 48 8d 75 d8                  	leaq	-40(%rbp), %rsi
      ce: ba 0a 00 00 00               	movl	$10, %edx
      d3: e8 00 00 00 00               	callq	0 <_main+0xd8>
      d8: 89 45 e8                     	movl	%eax, -24(%rbp)
      db: 48 8b 53 18                  	movq	24(%rbx), %rdx
      df: 80 3a 00                     	cmpb	$0, (%rdx)
      e2: 74 81                        	je	-127 <_main+0x65>
      e4: 48 8b 45 d8                  	movq	-40(%rbp), %rax
      e8: 80 38 00                     	cmpb	$0, (%rax)
      eb: 0f 85 74 ff ff ff            	jne	-140 <_main+0x65>
      f1: 48 8b 7b 20                  	movq	32(%rbx), %rdi
      f5: 48 8d 75 d8                  	leaq	-40(%rbp), %rsi
      f9: ba 0a 00 00 00               	movl	$10, %edx
      fe: e8 00 00 00 00               	callq	0 <_main+0x103>
     103: 89 45 ec                     	movl	%eax, -20(%rbp)
     106: 48 8b 53 20                  	movq	32(%rbx), %rdx
     10a: 80 3a 00                     	cmpb	$0, (%rdx)
     10d: 0f 84 52 ff ff ff            	je	-174 <_main+0x65>
     113: 48 8b 45 d8                  	movq	-40(%rbp), %rax
     117: 80 38 00                     	cmpb	$0, (%rax)
     11a: 0f 85 45 ff ff ff            	jne	-187 <_main+0x65>
     120: 48 8d 7d e0                  	leaq	-32(%rbp), %rdi
     124: e8 00 00 00 00               	callq	0 <_main+0x129>
     129: 8b 75 e0                     	movl	-32(%rbp), %esi
     12c: 8b 55 e4                     	movl	-28(%rbp), %edx
     12f: 8b 4d e8                     	movl	-24(%rbp), %ecx
     132: 44 8b 45 ec                  	movl	-20(%rbp), %r8d
     136: 48 8d 3d ca 00 00 00         	leaq	202(%rip), %rdi
     13d: 31 db                        	xorl	%ebx, %ebx
     13f: 31 c0                        	xorl	%eax, %eax
     141: e8 00 00 00 00               	callq	0 <_main+0x146>
     146: 48 8b 05 00 00 00 00         	movq	(%rip), %rax
     14d: 48 8b 00                     	movq	(%rax), %rax
     150: 48 3b 45 f0                  	cmpq	-16(%rbp), %rax
     154: 0f 84 3c ff ff ff            	je	-196 <_main+0x96>
     15a: e8 00 00 00 00               	callq	0 <_main+0x15f>
     15f: 90                           	nop

0000000000000160 __ZN4util12bitonic_sortIiLj4EEEvPT_:
     160: 55                           	pushq	%rbp
     161: 48 89 e5                     	movq	%rsp, %rbp
     164: 8b 07                        	movl	(%rdi), %eax
     166: 8b 4f 04                     	movl	4(%rdi), %ecx
     169: 39 c8                        	cmpl	%ecx, %eax
     16b: 41 89 c0                     	movl	%eax, %r8d
     16e: 44 0f 4c c1                  	cmovll	%ecx, %r8d
     172: 39 c1                        	cmpl	%eax, %ecx
     174: 0f 4e c1                     	cmovlel	%ecx, %eax
     177: 8b 4f 0c                     	movl	12(%rdi), %ecx
     17a: 8b 77 08                     	movl	8(%rdi), %esi
     17d: 39 f1                        	cmpl	%esi, %ecx
     17f: 89 ca                        	movl	%ecx, %edx
     181: 0f 4c d6                     	cmovll	%esi, %edx
     184: 39 ce                        	cmpl	%ecx, %esi
     186: 0f 4e ce                     	cmovlel	%esi, %ecx
     189: 39 d0                        	cmpl	%edx, %eax
     18b: 89 c6                        	movl	%eax, %esi
     18d: 0f 4c f2                     	cmovll	%edx, %esi
     190: 39 c2                        	cmpl	%eax, %edx
     192: 0f 4f d0                     	cmovgl	%eax, %edx
     195: 41 39 c8                     	cmpl	%ecx, %r8d
     198: 44 89 c0                     	movl	%r8d, %eax
     19b: 0f 4c c1                     	cmovll	%ecx, %eax
     19e: 44 39 c1                     	cmpl	%r8d, %ecx
     1a1: 41 0f 4f c8                  	cmovgl	%r8d, %ecx
     1a5: 39 ca                        	cmpl	%ecx, %edx
     1a7: 41 89 d0                     	movl	%edx, %r8d
     1aa: 44 0f 4c c1                  	cmovll	%ecx, %r8d
     1ae: 39 d1                        	cmpl	%edx, %ecx
     1b0: 0f 4f ca                     	cmovgl	%edx, %ecx
     1b3: 89 0f                        	movl	%ecx, (%rdi)
     1b5: 44 89 47 04                  	movl	%r8d, 4(%rdi)
     1b9: 39 c6                        	cmpl	%eax, %esi
     1bb: 89 f1                        	movl	%esi, %ecx
     1bd: 0f 4c c8                     	cmovll	%eax, %ecx
     1c0: 39 f0                        	cmpl	%esi, %eax
     1c2: 0f 4f c6                     	cmovgl	%esi, %eax
     1c5: 89 47 08                     	movl	%eax, 8(%rdi)
     1c8: 89 4f 0c                     	movl	%ecx, 12(%rdi)
     1cb: 5d                           	popq	%rbp
     1cc: c3                           	retq
