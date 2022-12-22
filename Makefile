CC = gcc
CFLAGS = -g

TARGET = sos

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

GRAPHDIR = graph
TESTDIR = test

FLEXFILE = fsos
BISONFILE = bsos
CFILES := $(filter-out $(SRCDIR)/$(BISONFILE).tab.c, $(filter-out $(SRCDIR)/$(FLEXFILE).yy.c, $(wildcard $(SRCDIR)/*.c)))
OBJFILES  := $(CFILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: create_dir $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJFILES) $(OBJDIR)/$(BISONFILE).tab.o $(OBJDIR)/$(FLEXFILE).yy.o
	$(CC) $(CFLAGS) $(OBJFILES) $(OBJDIR)/$(BISONFILE).tab.o $(OBJDIR)/$(FLEXFILE).yy.o -o $(BINDIR)/$(TARGET)

$(OBJFILES): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCDIR)

$(SRCDIR)/$(BISONFILE).tab.c: $(SRCDIR)/$(BISONFILE).y
	# bison -o $(SRCDIR)/$(BISONFILE).tab.c -Wmidrule-value -Wcounterexamples --report=all --header=$(INCDIR)/$(BISONFILE).tab.h -t $< # Linux
	bison -d -t -Wmidrule-value -Wcounterexamples --report=all $<
	mv $(BISONFILE).tab.c $(SRCDIR)
	mv $(BISONFILE).tab.h $(INCDIR)

$(OBJDIR)/$(BISONFILE).tab.o: $(SRCDIR)/$(BISONFILE).tab.c
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(BISONFILE).tab.o $(SRCDIR)/$(BISONFILE).tab.c -I $(INCDIR)

$(SRCDIR)/$(FLEXFILE).yy.c: $(SRCDIR)/$(FLEXFILE).lex $(SRCDIR)/$(BISONFILE).tab.c # Dépendance pour $(FILE).tab.h
	flex -s -o $(SRCDIR)/$(FLEXFILE).yy.c $<

$(OBJDIR)/$(FLEXFILE).yy.o: $(SRCDIR)/$(FLEXFILE).yy.c
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(FLEXFILE).yy.o $(SRCDIR)/$(FLEXFILE).yy.c -I $(INCDIR)

.PHONY: create_dir clean clean_test clean_graph test
create_dir:
	mkdir -p $(BINDIR) $(SRCDIR) $(INCDIR) $(OBJDIR)

graph:
	mkdir -p $(GRAPHDIR)
	bison --graph $(SRCDIR)/$(BISONFILE).y
	rm -f $(BISONFILE).tab.c
	mv $(BISONFILE).gv $(GRAPHDIR)
	dot -Tpdf < $(GRAPHDIR)/$(BISONFILE).gv > $(GRAPHDIR)/$(TARGET).pdf

test:
	sh ./$(TESTDIR)/test.sh

clean:
	rm -f $(OBJDIR)/*.o $(SRCDIR)/$(BISONFILE).tab.c $(INCDIR)/$(BISONFILE).tab.h $(SRCDIR)/$(FLEXFILE).yy.c $(SRCDIR)/$(BISONFILE).output $(SRCDIR)/$(BISONFILE).gv $(SRCDIR)/$(BISONFILE).dot $(SRCDIR)/$(BISONFILE).pdf $(BINDIR)/$(TARGET) $(TESTDIR)/output/*

clean_graph:
	rm -r $(GRAPHDIR)
	# rm -f $(GRAPHDIR)/*.gv $(GRAPHDIR)/*.pdf

clean_test:
	rm -f $(TESTDIR)/output/*