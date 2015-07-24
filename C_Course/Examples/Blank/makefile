
# compiler parameter
CFLAGS = -g -Wall

# the name of the program
PROGRAM_NAME = Main

# Program output directory path location
OUTPUT_DIR = ./output/

# all of the C files to include in the build
SRC = 	$(wildcard ./source/*.c)

#header to use
INCLUDE = 	./source ./header

# this append all the header with -I
INCLUDE_PARAM = $(foreach d, $(INCLUDE), -I$d)

# check if our output director exist, if not create it

all: $(SRC)

	# Check if the ouput directory exist, if not create it
	if [ ! -d $(OUTPUT_DIR) ]; \
	then mkdir $(OUTPUT_DIR); \
	fi
	
	
	gcc $(CFLAGS) -I$(INCLUDE_PARAM) -o $(OUTPUT_DIR)$(PROGRAM_NAME) $(SRC)

clean:
	# only delete the output directory if it exist
	if [ -d $(OUTPUT_DIR) ]; \
	then rm -R $(OUTPUT_DIR); \
	fi

