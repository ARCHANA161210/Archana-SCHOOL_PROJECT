; simpl v0.01-11/98, James Gil de Lamadrid
.class public fibonaci
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
	ldc "fibonaci"
	invokestatic simpl/registerIO(Ljava/lang/String;)V
	sipush 0
	istore 1
	ldc "n"
	invokestatic simpl/inputNum(Ljava/lang/String;)I
	istore 2
	sipush 0
	istore 3
	sipush 0
	istore 4
	sipush 0
	istore 5
	sipush 0
	istore 6
	sipush 0
	istore 3
	sipush 1
	istore 4
	sipush 1
	istore 5
	iload 2
	sipush 0
	if_icmpgt L4
	sipush 0
	goto L5
L4:
	sipush 1
L5:
	sipush 0
	if_icmpeq L2
	sipush 0
	goto L3
L2:
	sipush 1
L3:
	ifeq L0
	iload 2
	istore 1
	goto L1
L0:
L1:
	sipush 1
	iload 2
	if_icmpgt L10
	sipush 0
	goto L11
L10:
	sipush 1
L11:
	sipush 0
	if_icmpeq L8
	sipush 0
	goto L9
L8:
	sipush 1
L9:
	ifeq L6
L12:
	iload 5
	iload 2
	if_icmpgt L16
	sipush 0
	goto L17
L16:
	sipush 1
L17:
	sipush 0
	if_icmpeq L14
	sipush 0
	goto L15
L14:
	sipush 1
L15:
	ifeq L13
	iload 4
	iload 3
	iadd
	istore 6
	iload 4
	istore 3
	iload 6
	istore 4
	iload 5
	sipush 1
	iadd
	istore 5
	goto L12
L13:
	goto L7
L6:
	iload 2
	istore 1
L7:
	iload 6
	istore 1
	iload 1
	invokestatic simpl/outputNum(I)V
	return
.limit stack 32
.limit locals 7
.end method
