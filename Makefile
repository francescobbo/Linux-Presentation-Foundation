OUTPUT := liblpf.a
OBJS := $(shell find -name "*.cpp")
OBJS := $(OBJS:.cpp=.o)

all:	$(OUTPUT)

INCLUDES := -I./Includes

$(OUTPUT): $(OBJS)
	@echo " [AR ]\t"$@
	@ar -rv $@ $(OBJS) >/dev/null 2>&1
	
.cpp.o:
	@echo " [G++]\t"$@
	@g++ $(INCLUDES) `pkg-config --cflags cairomm-1.0` -g -O3 $? -o $@ -c

clean:
	rm $(OBJS)

test:	$(OUTPUT)
	g++ `pkg-config --libs cairomm-1.0` -g -O3 $(OUTPUT) -o a.out
	
