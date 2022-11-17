CC = gcc
CFLAGS = -g

TARGET = sos

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

GRAPHDIR = graph

FLEXFILE = fsos
BISONFILE = bsos
CFILE = csos

$(BINDIR)/$(TARGET): $(OBJDIR)/$(CFILE).o $(OBJDIR)/$(BISONFILE).tab.o $(OBJDIR)/$(FLEXFILE).yy.o
	$(CC) $(CFLAGS) $(OBJDIR)/$(CFILE).o $(OBJDIR)/$(BISONFILE).tab.o $(OBJDIR)/$(FLEXFILE).yy.o -o $(BINDIR)/$(TARGET)

$(OBJDIR)/$(CFILE).o:
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(CFILE).o $(SRCDIR)/$(CFILE).c

$(SRCDIR)/$(BISONFILE).tab.c: $(SRCDIR)/$(BISONFILE).y
	bison --report=all -d -t $<
	# bison -o $(SRCDIR)/$(BISONFILE).tab.c -Wcounterexamples --report=all --header=$(INCDIR)/$(BISONFILE).tab.h -t $<
	mv $(BISONFILE).tab.c $(SRCDIR)
	mv $(BISONFILE).tab.h $(INCDIR)

$(OBJDIR)/$(BISONFILE).tab.o: $(SRCDIR)/$(BISONFILE).tab.c
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(BISONFILE).tab.o $(SRCDIR)/$(BISONFILE).tab.c -I $(INCDIR)

$(SRCDIR)/$(FLEXFILE).yy.c: $(SRCDIR)/$(FLEXFILE).lex $(SRCDIR)/$(BISONFILE).tab.c # Dépendance pour $(FILE).tab.h
	flex -s -o $(SRCDIR)/$(FLEXFILE).yy.c $<

$(OBJDIR)/$(FLEXFILE).yy.o: $(SRCDIR)/$(FLEXFILE).yy.c
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(FLEXFILE).yy.o $(SRCDIR)/$(FLEXFILE).yy.c -I $(INCDIR)

graph:
	bison --graph $(SRCDIR)/$(BISONFILE).y
	dot -Tpdf < $(GRAPHDIR)/$(TARGET).gv > $(GRAPHDIR)/$(TARGET).pdf

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(SRCDIR)/$(BISONFILE).tab.c $(INCDIR)/$(BISONFILE).tab.h $(SRCDIR)/$(FLEXFILE).yy.c $(SRCDIR)/$(BISONFILE).output $(SRCDIR)/$(BISONFILE).gv $(SRCDIR)/$(BISONFILE).dot $(SRCDIR)/$(BISONFILE).pdf $(SRCDIR)/$(CFILE)

clean_test:
	rm -f test/output/*