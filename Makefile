#-----------------------------------------------------------------------------
# project3_dalemu2_207 Makefile
#-----------------------------------------------------------------------------

CC   = gcc
OPTS = -O0
DEBUG = -g

#--------------------------------------------------------------------------

SRCDIR=./src
OBJDIR=./obj
INCDIR=./inc
BINDIR=./bin

#--------------------------------------------------------------------

SRCS=$(SRCDIR)/main.c \
     $(SRCDIR)/project3_dalemu2_207.c \
     $(SRCDIR)/itemList_dalemu2_207.c \
     $(SRCDIR)/helperfunction.c 
#--------------------------------------------------------------------

INCLUDE = $(addprefix -I,$(INCDIR))
OBJS=${SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o}
CFLAGS   = $(OPTS) $(INCLUDE) $(DEBUG)

#--------------------------------------------------------------------

TARGET = $(BINDIR)/project3_dalemu2_207

all: $(TARGET)

$(TARGET): $(OBJS) 
	${CC} ${CFLAGS} -o0 $@ $(OBJS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#--------------------------------------------------------------------

clean:
	rm -f $(OBJS)

#--------------------------------------------------------------------

cleanall:
	rm -f $(OBJS)
	rm -f project3_dalemu2_207
