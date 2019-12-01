#
#
# date: 2019/11/30
# authors: Roger Shanahan, Ciara Sookarry

# all: polynomial

# compile, link and run project
all: polynomial
		./polynomial		

# link object files together
polynomial: assignment.o assignmentMain.o
		gcc -o $@ $^

# compile assignment.c into an object file
assignment.o: assignment.c assignment.h 
	gcc -Wall -ggdb -o $@ -c $<

# compile assignmentMain.c into an object file
assignmentMain.o: assignmentMain.c assignment.h
	gcc -Wall -ggdb -o $@ -c $<

# remove unnecessary files
clean:
		rm -f polynomial *.o *~ *#

