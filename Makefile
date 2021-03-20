CC=gcc
CXX=g++
DEFINES=
INCLUDES=
CFLAGS=$(DEFINES) $(INCLUDES) -g -Wall -O0 -fPIC
CXXFLAGS=$(DEFINES) $(INCLUDES) -std=c++11 -g -Wall -O0 -fPIC
LDFLAGS=
LDLIBS=-lpthread

OUTDIR=build

RM=rm -f

C_SOURCES=$(wildcard *.c)
C_OBJECTS=$(patsubst %.c,%.o,$(C_SOURCES))
C_DEPS=$(C_OBJECTS:.o=.d)
C_PROGS=$(patsubst %.c,%,$(C_SOURCES))

CPP_SOURCES=$(wildcard *.cpp)
CPP_OBJECTS=$(patsubst %.cpp,%.o,$(CPP_SOURCES))
CPP_DEPS=$(CPP_OBJECTS:.o=.d)
CPP_PROGS=$(patsubst %.cpp,%,$(CPP_SOURCES))

.PHONY: all
all: $(C_PROGS) $(CPP_PROGS)
	mkdir build
	mv *.o *.d $^ $(OUTDIR)

.PHONY: vars
vars:
	@echo C_SOURCES: $(C_SOURCES)
	@echo C_DEPS: $(C_DEPS)
	@echo C_OBJECTS: $(C_OBJECTS)
	@echo C_PROGS: $(C_PROGS)
	@echo CPP_SOURCES: $(CPP_SOURCES)
	@echo CPP_DEPS: $(CPP_DEPS)
	@echo CPP_OBJECTS: $(CPP_OBJECTS)
	@echo CPP_PROGS: $(CPP_PROGS)

-include $(C_DEPS)
-include $(CPP_DEPS)

$(C_PROGS): % : %.o
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $<
	@echo ' '

$(CPP_PROGS): % : %.o
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $<
	@echo ' '

$(C_OBJECTS): %.o : %.c %.d
	@echo 'building file: $<'
	$(CC) -c $(CFLAGS) -o $@ $<
	@echo 'finish building file: $<'
	@echo ' '

$(CPP_OBJECTS): %.o : %.cpp %.d
	@echo 'building file: $<'
	$(CXX) -c $(CXXFLAGS) -o $@ $<
	@echo 'finish building file: $<'
	@echo ' '

$(C_DEPS): %.d : %.c
	@set -e; \
	$(RM) $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\(.*\)\.o[ :]*,\1.o $@: ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

$(CPP_DEPS): %.d : %.cpp
	@set -e; \
	$(RM) $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\(.*\)\.o[ :]*,\1.o $@: ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

.PHONY: clean
clean:
	-$(RM) -r $(OUTDIR)
	-$(RM) $(C_DEPS) $(CPP_DEPS)
	-$(RM) $(C_OBJECTS) $(CPP_OBJECTS)
	-$(RM) $(C_PROGS) $(CPP_PROGS)
