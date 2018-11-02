CC = g++
SRCEXT = cpp
CFLAGS = -c -std=c++11 -Wall
LFLAGS = -Wall

TARGET = eternity

SRCDIR = src
INCDIR = inc
OBJDIR = obj

SRCS = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJS = $(SRCS:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)

$(TARGET): $(OBJS)
	@echo [LINKING]  All files . . .
	@$(CC) $(LFLAGS) $(OBJS) -o $@
	@echo [SUCCESS]  File Name: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	@echo [BUILDING] $< . . .
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ $<

run:
	@./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)