#
#
# date: 2019/11/30
# authors: Roger Shanahan, Ciara Sookarry

# all: polynomial

all: polynomial
		./polynomial		

polynomial: assignment.o assignmentMain.o
		gcc -o $@ $^

assignment.o: assignment.c assignment.h
	gcc -Wall -ggbd -o $@ -c $<

assignmentMain.o: assignmentMain.c assignment.h
	gcc -Wall -ggdb -o $@ -c $<

clean:
		rm -f polynomial *.o *~ *#

