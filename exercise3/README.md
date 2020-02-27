# Run this first to setup

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
