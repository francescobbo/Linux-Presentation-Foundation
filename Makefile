OUTPUT := liblpf.a
OBJS := $(shell find -name "*.cpp")
OBJS := $(OBJS:.cpp=.o)

all:	$(OUTPUT)

INCLUDES := -I./Includes

$(OUTPUT): $(OBJS)
	@echo " [AR ]\t"$@
	@ar -rv $@ $(OBJS) &>/dev/null
	
.cpp.o:
	@echo " [G++]\t"$@
	@g++ $(INCLUDES) `pkg-config --cflags cairomm-1.0` $? -o $@ -c

clean:
	rm $(OBJS)

