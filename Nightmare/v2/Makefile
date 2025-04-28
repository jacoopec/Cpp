CPPFLAGS := -pthread
OBJS := canvas Circle Point Rectangle Shape main
CC := gcc
all: pjt

%.o: %.c
	#@echo["Compiling $< -> $@"]
	$(CC) $(CFLAGS) -c $< -o $@

pjt: $(OBJS)
	# @echo["Linking $^"]
	$(CC) $(CFLAGS) $(OFLAGS) -o pjt $^
