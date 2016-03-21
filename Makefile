CXX	= g++ -std=c++11 -Wall
CFLAGS	= -c -I./include -I./include/SDL2 \
	-I./include/freetype -I./include/freetype/freetype2

LDFLAGS	= -lGL -lglut -lm -lfreetype -lSDL2 -lSDL2main	#Library flags
LIBS	= -L./lib -Wl,-rpath=./lib		#Path to find libraries

EXEC	= desolation	#The name of the executable file

HDRDIR	= include
SRCDIR	= src
OBJDIR	= .obj

SOURCES	:= $(wildcard $(SRCDIR)/*.cpp)	#All .cpp files in the directory
OBJECTS	:= $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))

#Rule for linking the objects to create the executable
$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)

#Rule for creating .o files from each .cpp
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY: clean
.PHONY: run

#Removes all .o and executable files
clean:
	@rm -f $(OBJDIR)/*.o $(EXEC)

#Runs the executable
run:
	@./$(EXEC)
