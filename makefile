#makefile
#
# date: 2019/12/05
# authors: Roger Shanahan, Ciara Sookarry

# link object files together
polynomial: assignment.o assignmentMain.o
		gcc -o $@ $^

# compile assignment.c into an object file
assignment.o: assignment.c assignment.h 
	gcc -Wall -ggdb -std=c11 -o $@ -c $<

# compile assignmentMain.c into an object file
assignmentMain.o: assignmentMain.c assignment.h
	gcc -Wall -ggdb -std=c11 -o $@ -c $<

# remove unnecessary files
clean:
		rm -f polynomial *.o *~ *#

