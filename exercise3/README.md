docker build . -t server
 docker run -it -p 9001:4000 -v /app server