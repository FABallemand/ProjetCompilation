CC = gcc
CFLAGS = -g

TARGET = projet

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

FLEXFILE = projet
BISONFILE = projet
CFILE = projet

$(BINDIR)/$(CFILE): $(OBJDIR)/$(CFILE).o $(OBJDIR)/$(BISONFILE).tab.o $(OBJDIR)/$(FLEXFILE).yy.o

$(SRCDIR)/$(BISONFILE).tab.c: $(SRCDIR)/$(BISONFILE).y
	bison --report=all -d -t $<

$(SRCDIR)/$(FLEXFILE).yy.c: $(SRCDIR)/$(FLEXFILE).lex $(SRCDIR)/$(BISONFILE).tab.c # Dépendance pour $(FILE).tab.h
	flex -s -o $(SRCDIR)/$(FLEXFILE).yy.c $<

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(SRCDIR)/$(BISONFILE).tab.c $(INCDIR)/$(BISONFILE).tab.h $(SRCDIR)/lex.yy.c $(SRCDIR)/$(BISONFILE).output $(SRCDIR)/$(BISONFILE).gv $(SRCDIR)/$(BISONFILE).dot $(SRCDIR)/$(BISONFILE).pdf $(SRCDIR)/$(CFILE)