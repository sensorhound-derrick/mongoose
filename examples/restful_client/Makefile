PROG = restful_client
SOURCES = $(PROG).c ../../mongoose.c
CFLAGS = -W -Wall -I../.. -pthread $(CFLAGS_EXTRA)

all: $(PROG)

$(PROG): $(SOURCES)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

$(PROG).exe: $(SOURCES)
	cl $(SOURCES) /I../.. /MD /Fe$@

cilly: $(SOURCES)
	mkdir -p build
	mkdir -p tmp
	cilly -g -pthread --save-temps=build/ --dotinytracer -I../.. -W -Wall -o cilly_mongoose $(SOURCES) ../../logging.h

clean:
	rm -rf *.gc* *.dSYM *.exe *.obj *.o a.out $(PROG) build/ tmp/ cilly_mongoose out.map procmap.txt
