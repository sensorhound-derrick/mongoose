PROG = simplest_web_server
SOURCES = $(PROG).c ../../mongoose.c
CFLAGS = -g -W -Wall -pthread $(CFLAGS_EXTRA)

all: $(PROG)

$(PROG): $(SOURCES)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

$(PROG).exe: $(SOURCES)
	cl $(SOURCES) /I../.. /MD /Fe$@

cilly: $(SOURCES)
	mkdir -p build
	mkdir -p tmp
	cilly $(CFLAGS) -DSENSORTRACER -I../.. --merge --verbose --dotinytracer --save-temps=build/ -o cilly_mongoose $(SOURCES)

clean:
	rm -rf *.gc* *.dSYM *.exe *.obj *.o a.out cilly_mongoose build/ tmp/ procmap.txt out.map $(PROG)
