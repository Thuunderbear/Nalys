
SHELL = /bin/sh
CC 	= g++
CFLAGS = -g -Wall
TITLE = "This is the title of the document ..."
FOOTER = "This is a footer"
TEXT = "This is a text times 10. "
COUNT = "10"
OUTPUT = "/home/diego/Nalys/web/"

all : compile
	./output --title $(TITLE) --text $(TEXT) --count $(COUNT) --footer $(FOOTER) --output $(OUTPUT)
	./setup.sh $(OUTPUT)

compile : main.cpp
	$(CC) $(CFLAGS) -o output main.cpp


#mv /etc/nginx/site-enabled/