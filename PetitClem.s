.comment "Je suis petit et j'aime mes voisines! :-)"
.name "Petit Clem :-)"

code:
	ldi %:copy, %0, r3

start:
	sti r1, %:live, %1

live:
	live %42
	xor r2, %1, r2
	zjmp %:start

fork_start:
	fork %:copy
	fork %:start
	lfork %200

coucou:
	sti r1, %:hop, %1

hop:
	live %42
	and %0, %0, r2
	zjmp %:hop

copy:
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
	sti r3, 0, %0
#	sti r5, 0, %20
#	sti r6, 0, %30
#	sti r7, 0, %40
#	sti r8, 0, %50
#	sti r9, 0, %60
#	sti r10, 0, %70

end:
