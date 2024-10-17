OS = $(shell uname)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           COLORS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          COMMANDS                                         _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CXX = c++
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          FOLDERS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

INC_FOLDER	= includes
SRC_FOLDER	= sources
OBJ_FOLDER	= binaries
DEP_FOLDER	= dependencies
_SUBFOLDERS	= .

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FLAGS                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CXXFLAGS	= -Wall -Wextra -Werror -O3 -pedantic -std=c++98
CPPFLAGS	= -I $(INC_FOLDER)
MAKEFLAGS	= --no-print-directory
LDFLAGS		=

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        DEPENDENCIES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

vpath %.c $(foreach subfolder, $(_SUBFOLDERS), $(SRC_FOLDER)/$(subfolder))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

MANDATORY_FILES += BitcoinExchange
MANDATORY_FILES += main

OBJS = $(patsubst %, $(OBJ_FOLDER)/%.o, $(MANDATORY_FILES))
NAME = btc

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                       CONDITIONALS                                        _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# To make use of these flags, you must define them in the command line, when
# running the make command. For instance, if you want the debug flag:
#	make DEBUG=1
# The value of 1 is a dummy value, as the make command needs an assignment
# to recognize DEBUG as a variable, otherwise it would be considered a target
# If you need both debug and sanitizer:
# 	make DEBUG=1 SAN=A

ifdef DEBUG
	CXXFLAGS += -g
endif

ifeq ($(SAN), A)
	CXXFLAGS += -fsanitize=address
else ifeq ($(SAN), L)
	CXXFLAGS += -fsanitize=leak
else ifeq ($(SAN), M)
	CXXFLAGS += -fsanitize=memory
else ifeq ($(SAN), T)
	CXXFLAGS += -fsanitize=thread
else ifeq ($(SAN), U)
	CXXFLAGS += -fsanitize=undefined
endif

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJS)
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) 
	
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	echo "[$(CYAN)Compiling$(RESET)] $(CXXFLAGS) $(GREEN)$<$(RESET)"
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean
	$(MAKE) all

clean:	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_FOLDER)$(RESET)"
	$(RM) $(OBJ_FOLDER)

fclean: clean
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        CUSTOM RULES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

fast:
	$(MAKE) re -j

run: fast
	clear
	./$(NAME) $(ARG)

brun: bfast
	clear
	./$(NAME) $(ARG)

leaks: fast
	valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log ./$(NAME) $(ARG)

.SILENT:


