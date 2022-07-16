#!/bin/sh
OUTPUT=$1
TEXT="server { \n
        listen 8080;\n
        listen [::]:8080;\n
        \n
        server_name whatever.diego.com;\n
        \n
        root $OUTPUT;\n
        index index.html;\n
\n
        location / {\n
               try_files \$uri \$uri/ =404;\n
       }\n
       \n

}"
echo $TEXT > website

sudo apt-get install nginx
sudo mv website /etc/nginx/sites-enabled
systemctl reload nginx