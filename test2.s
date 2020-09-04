
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
      26: 48 8d 35 ba 01 00 00         	leaq	442(%rip), %rsi
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
      6f: 48 8d 35 89 01 00 00         	leaq	393(%rip), %rsi
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
     136: 48 8d 3d e4 00 00 00         	leaq	228(%rip), %rdi
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
     164: 8b 0f                        	movl	(%rdi), %ecx
     166: 8b 77 04                     	movl	4(%rdi), %esi
     169: 39 f1                        	cmpl	%esi, %ecx
     16b: 7e 2f                        	jle	47 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x3c>
     16d: 89 4f 04                     	movl	%ecx, 4(%rdi)
     170: 89 37                        	movl	%esi, (%rdi)
     172: 41 89 c9                     	movl	%ecx, %r9d
     175: 8b 57 08                     	movl	8(%rdi), %edx
     178: 8b 4f 0c                     	movl	12(%rdi), %ecx
     17b: 39 d1                        	cmpl	%edx, %ecx
     17d: 7f 2c                        	jg	44 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x4b>
     17f: 89 c8                        	movl	%ecx, %eax
     181: 89 d1                        	movl	%edx, %ecx
     183: 39 ce                        	cmpl	%ecx, %esi
     185: 7f 30                        	jg	48 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x57>
     187: 41 89 c8                     	movl	%ecx, %r8d
     18a: 89 f1                        	movl	%esi, %ecx
     18c: 41 39 c1                     	cmpl	%eax, %r9d
     18f: 7f 33                        	jg	51 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x64>
     191: 89 c6                        	movl	%eax, %esi
     193: 44 89 c8                     	movl	%r9d, %eax
     196: 39 c1                        	cmpl	%eax, %ecx
     198: 7f 38                        	jg	56 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x72>
     19a: eb 3b                        	jmp	59 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x77>
     19c: 41 89 f1                     	movl	%esi, %r9d
     19f: 89 ce                        	movl	%ecx, %esi
     1a1: 8b 57 08                     	movl	8(%rdi), %edx
     1a4: 8b 4f 0c                     	movl	12(%rdi), %ecx
     1a7: 39 d1                        	cmpl	%edx, %ecx
     1a9: 7e d4                        	jle	-44 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x1f>
     1ab: 89 4f 08                     	movl	%ecx, 8(%rdi)
     1ae: 89 57 0c                     	movl	%edx, 12(%rdi)
     1b1: 89 d0                        	movl	%edx, %eax
     1b3: 39 ce                        	cmpl	%ecx, %esi
     1b5: 7e d0                        	jle	-48 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x27>
     1b7: 89 77 08                     	movl	%esi, 8(%rdi)
     1ba: 89 0f                        	movl	%ecx, (%rdi)
     1bc: 41 89 f0                     	movl	%esi, %r8d
     1bf: 41 39 c1                     	cmpl	%eax, %r9d
     1c2: 7e cd                        	jle	-51 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x31>
     1c4: 44 89 4f 0c                  	movl	%r9d, 12(%rdi)
     1c8: 89 47 04                     	movl	%eax, 4(%rdi)
     1cb: 44 89 ce                     	movl	%r9d, %esi
     1ce: 39 c1                        	cmpl	%eax, %ecx
     1d0: 7e 05                        	jle	5 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x77>
     1d2: 89 4f 04                     	movl	%ecx, 4(%rdi)
     1d5: 89 07                        	movl	%eax, (%rdi)
     1d7: 41 39 f0                     	cmpl	%esi, %r8d
     1da: 7f 02                        	jg	2 <__ZN4util12bitonic_sortIiLj4EEEvPT_+0x7e>
     1dc: 5d                           	popq	%rbp
     1dd: c3                           	retq
     1de: 44 89 47 0c                  	movl	%r8d, 12(%rdi)
     1e2: 89 77 08                     	movl	%esi, 8(%rdi)
     1e5: 5d                           	popq	%rbp
     1e6: c3                           	retq
