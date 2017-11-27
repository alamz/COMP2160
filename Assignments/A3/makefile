# -----------------------------------------
# PROJECT: SAMPLE MAKEFILE
# AUTHOR : Stela H. Seo <stela.seo@cs.umanitoba.ca>
# -----------------------------------------

#---------------------------------------------------------------------
# C++ COMPILER, COMPILER FLAGS, AND TARGET PROGRAM NAME
#---------------------------------------------------------------------

# executable file name
TARGET   = za_HW

# directory to contain compiled objects
DIR_OBJS = .obj
CC       = clang
CX       = clang

# if you have sub-directories for header and source files have -I ../include to specify the location of header files
CCFLAGS  = -Wall -DNDEBUG -O3
CXFLAGS  = -Wall -DNDEBUG -O3


#---------------------------------------------------------------------
# FILES
#---------------------------------------------------------------------
# We list all files here to make our life easier in specifying dependencies
# \ means the line is not ended. Normally HEADER=header1.h header2.h
# But we want to separate lines so they look nicer.
HEADERS=Table.h

SOURCES=main.c \
		Table.c

OBJECTS=$(DIR_OBJS)/main.o \
		$(DIR_OBJS)/Table.o

#---------------------------------------------------------------------
# COMPILING RULES
#---------------------------------------------------------------------
# First rule is default, that is, if you don't specify specific rule, makefile will use the first rule.
default: $(TARGET)

# Link compiled objects and create an executable binary.
# It requires to have directory for objects and to compile objects
$(TARGET): make_directory $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o $@

# Clean removes every object and binary
clean:
	rm -rf $(TARGET) $(OBJECTS) $(DIR_OBJS)/

# Make directory for our objects
make_directory:
	mkdir -p $(DIR_OBJS)/

# Compile C files
$(DIR_OBJS)/%.o: %.c
	$(CC) $(CCFLAGS) -c $? -o $@

# Compile C++ files
$(DIR_OBJS)/%.o: %.cpp
	$(CX) $(CXFLAGS) -c $? -o $@


#---------------------------------------------------------------------
# END OF MAKEFILE
#---------------------------------------------------------------------
