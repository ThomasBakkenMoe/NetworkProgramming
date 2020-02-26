

const express = require("express");
const bodyParser  = require('body-parser');
const app = express();
app.use(bodyParser.json());
app.use ( bodyParser.json( { type: '*/*' } ));

let cors = require("cors");
app.use(cors());



const fs = require('fs');

const port =  4000;





app.post('/run/node', (req, res) => {
	console.log('Running javascript code');
	let msg = req.body.input;
	console.log(msg);
});


app.get('/run/python', (req, res) => {
	console.log('Running python code');
});

app.get('/run/java', (req, res) => {
	console.log("Running java code");
});

app.get('/run/cpp', (req, res) => {
	console.log('Running c++ code');
});

app.get('/run/csharp', (req, res) => {
	console.log('Running C# code');
});



app.listen(port, () => {
	console.log('Server running on port ' + port);
});