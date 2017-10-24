; simpl v0.01-11/98, James Gil de Lamadrid
.class public right
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
	ldc "right"
	invokestatic simpl/registerIO(Ljava/lang/String;)V
	sipush 0
	istore 1
	ldc "a"
	invokestatic simpl/inputNum(Ljava/lang/String;)I
	istore 2
	ldc "b"
	invokestatic simpl/inputNum(Ljava/lang/String;)I
	istore 3
	ldc "c"
	invokestatic simpl/inputNum(Ljava/lang/String;)I
	istore 4
	iload 2
	iload 2
	imul
	iload 3
	iload 3
	imul
	iadd
	iload 4
	iload 4
	imul
	if_icmpeq L2
	sipush 0
	goto L3
L2:
	sipush 1
L3:
	ifeq L0
	sipush 1
	istore 1
	goto L1
L0:
	sipush 0
	istore 1
L1:
	iload 1
	invokestatic simpl/outputNum(I)V
	return
.limit stack 11
.limit locals 5
.end method
