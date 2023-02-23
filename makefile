$(DEPS) = stack
compile: main.c 
	gcc main.c -o $(DEPS)
run:
	./$(DEPS) {[]}[] {[]] [] {{ }}
