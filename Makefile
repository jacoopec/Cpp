INCDIR := ./include
LINKLIBS := $(addprefix -l, $(LIBS))
LDLIBS := -pthread $(INC_DIR)

CCPSRC := $(shell find . -name "*.cpp")
OBJS := $(patsubst %.cpp, %.o, $(CPPSRC))
BUILD_DIR = build
DEPDIR := .d
OBJSDIR := objsDir
OBJS_IN_BUILD_DIR = $(addprefix $(BUILD_DIR)/, $(OBJS))
WORKINGON := circularQueue
PROG := project
ELF := $(PROG).elf
CLANG := clang++

#COMPILE.cpp = $(CXX) 

all: $(PROG)

c:
#$(STRIP) -o $(PROG) $(ELF)
	$(CLANG) -c $(WORKINGON).c
	$(CLANG)  $(WORKINGON).o -o $(WORKINGON)

$(ELF): $(OBJS_IN_BUILD_DIR)
	@echo "[Linking]" $@
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $(ELF) $^ $(LDLIBS)

project: $(WORKINGON).o  $(OBJS_IN_BUILD_DIR)
	g++ $(WORKINGON).o  -o main
	@mkdir $(OBJSDIR)
	mv *.o $(OBJSDIR)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p 'dirname $@'
	@echo "[Compiling]"
	@$(COMPILE.cpp) $< -o $@

$(DEPDIR)/%.d:
	@mkdir -p 'dirname $@'

$(WORKINGON).o:
	@echo '$@'
	@echo '$<'
	g++ $(WORKINGON).cpp -c -std=c++17
funcs.o:
	g++ funcs.cpp -c -std=c++17
Cat.o:
	g++ Cat.cpp -c -std=c++17
Animal.o:
	g++ Animal.cpp -c -std=c++17
prova:
	@echo $(CCPSRC)
	@echo $(OBJS)
clean:
	rm $(OBJSDIR)/*.o main
execute:
	./main