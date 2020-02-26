FROM node:10-alpine
WORKDIR /app

COPY ./server.js /app
RUN npm install
RUN echo $(ls -1 /tmp/dir)

COPY . /app
CMD ["node", "server.js"]
