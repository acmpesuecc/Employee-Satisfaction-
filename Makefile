all:out

out: ESSmain.o ESS1c.o	
	gcc ESSmain.o ESS1c.o -o out

ESSmain.o:ESSmain.c
	gcc -c ESSmain.c

ESS1.o:ESS1c.c
	gcc -c ESS1c.c

clean:
	rm -rf *o out