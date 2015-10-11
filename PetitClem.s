.comment "Je suis petit et j'aime mes voisines! :-)"
.name "Petit Clem :-)"

code:
	ldi %:copy, %0, r3
	ldi %:copy, %4, r4
	ldi %:copy, %8, r5
	ldi %:copy, %12, r6
	ldi %:copy, %16, r7
	ldi %:copy, %20, r8
	ldi %:copy, %24, r9
	ldi %:copy, %28, r10
	ld %120, r12

start:
	sti r1, %:live, %1

live:
	live %42
	xor r2, %1, r2
	zjmp %:start

fork_start:
	fork %:start

copy:
	sti r3, 100, %50
	sti r4, 100, %50
	sti r5, 100, %50
	sti r6, 100, %50
	sti r7, 100, %50
	sti r8, 100, %50
	sti r9, 100, %50
	sti r10, 100, %50

end:
