# Compile option
CC = gcc
CFLAGS = -Wall -g
LN = -lSDL2 -lSDL2_image -lSDL2_ttf -pg

#Build
BUILD = build

#Source
CDIR = src
HDIR = src/include
OBJs = $(BUILD)/gui.o $(BUILD)/gui_button.o $(BUILD)/gui_label.o $(BUILD)/gui_block.o

test: test.c $(BUILD)/libgui.a
	$(CC) $(CFLAGS) $(LN) test.c -L./$(BUILD)/ -lgui -o $(BUILD)/$@

all: $(BUILD)/libgui.a 

$(BUILD)/libgui.a: $(OBJs)
	ar r $@ $(OBJs)

$(BUILD)/gui.o: $(CDIR)/gui.c $(HDIR)/gui.h
	$(CC) $(CFLAGS) $(LN) -c $< -o $@

$(BUILD)/gui_layers.o: $(CDIR)/gui_layers.c $(HDIR)/gui_layers.h
	$(CC) $(CFLAGS) $(LN) -c $< -o $@

$(BUILD)/gui_button.o: $(CDIR)/gui_button.c $(HDIR)/gui_button.h
	$(CC) $(CFLAGS) $(LN) -c $< -o $@

$(BUILD)/gui_label.o: $(CDIR)/gui_label.c $(HDIR)/gui_label.h
	$(CC) $(CFLAGS) $(LN) -c $< -o $@

$(BUILD)/gui_block.o: $(CDIR)/gui_block.c $(HDIR)/gui_block.h
	$(CC) $(CFLAGS) $(LN) -c $< -o $@

# non-compile target
run:
	$(BUILD)/test

clear:
	rm $(BUILD)/guilib.a $(OBJs)

print:
	echo $(OBJs)
