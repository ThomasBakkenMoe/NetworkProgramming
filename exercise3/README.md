# Online code runner
A site for running and compiling code online.
Only supports Javascript code atm.

## Run this first to setup

From root directory:
```
cd client
npm install
```

### Build Dockerfile:

From root directory:
 ```
 cd server
 docker build . -t server
 ```
 
 ### Run dockerfile with webserver:
 ```
 docker run -it -p 9001:4000 -v /app server
```

### And finally start client while in client directory:
```
npm start
```
