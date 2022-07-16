# Technical task
## [C/C++] Generate webpage
Write a C/C++ application that generates a simple HTML-file based on the arguments given. The app should accept 4 mandatory options:
- --title TITLE: specifies the title of the page
- --text TEXT: specifies a short sentence to display on the page
- --count COUNT: specifies how many times TEXT should be repeated on the page
- --output OUTPUT: specifies the path to the generated file
The app also takes one optional argument:
- --footer FOOTER: specifies an optional piece of text that should be displayed under the main TEXT

The output of the app should be a simple HTML-file containing the specified content. Format the title as a header, but otherwise style is not important.

## [Linux] Install and setup an nginx server
Write a bash script to install and setup an nginx-server on a linux system. The script should:
- Install nginx if it's not available.
- Set up the nginx server to serve the generated file from the first part (with the file already generated), so that it's accessible on http://localhost:8080

## [Python] Test script
Write a Python script that tests the behaviour from the first two parts. The script should:
- Call the HTML-generation with a few valid and invalid arguments and verify that the file gets generated in the correct cases.
- Verify that the file is accessible on the URL specified in the second part after the server is started manually.

## [Makefile]
Write a simple makefile to easily trigger all implemented behaviour. It should contain the following targets:
- generator: compile the app from the first part into a binary called "generator"
- index.html: generate an index.html with the app from the first part with some default values for the options
- server: run the script from the second part
- test: run all tests implemented in the third part

## Practical details
You can upload your code to a GitHub or Gitlab repository and invite use for it:
Gitlab: @pmariman and @tgeypens
GitHub: @pmariman and @getim

If you have any other questions, you can contact us on:
tgeypens@nalys-group.com
pmariman@nalys-group.com
rhaxhiaj@nalys-group.com
