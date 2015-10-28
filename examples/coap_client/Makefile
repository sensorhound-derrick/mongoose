PROG = coap_client
SOURCES = $(PROG).c ../../mongoose.c
CFLAGS = -W -Wall -I../.. $(CFLAGS_EXTRA) -DMG_ENABLE_COAP

all: $(PROG)

$(PROG): $(SOURCES)
	$(CC) $(SOURCES) -o $@ $(CFLAGS)

$(PROG).exe: $(SOURCES)
	cl $(SOURCES) /I../.. /MD /Fe$@

cilly: $(SOURCES)
	mkdir -p build
	mkdir -p tmp
	cilly $(CFLAGS) -DSENSORTRACER --verbose -g --save-temps=build/ --dotinytracer -o cilly_mongoose $(SOURCES)

clean:
	rm -rf *.gc* *.dSYM *.exe *.obj *.o a.out $(PROG) build/ tmp/ cilly_mongoose out.map procmap.txt
