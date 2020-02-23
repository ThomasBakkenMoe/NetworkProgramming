import React, {useEffect, useState} from 'react';
import './styles.scss';
import './css/materialize.min.css';


import AceEditor from 'react-ace';
import "ace-builds/src-noconflict/theme-monokai";
import "ace-builds/src-noconflict/mode-java";
import "ace-builds/src-noconflict/mode-javascript";
import "ace-builds/src-noconflict/mode-python";
import "ace-builds/src-noconflict/mode-ruby";
import "ace-builds/src-noconflict/mode-golang";
import "ace-builds/src-noconflict/mode-csharp";


function App() {
	const [output, setOutput] = useState("");

	function runCode(code){
		//call on code
		//setOutput with return data,
	}

  return (
    <div className="App">
      <div className="wrapper">


          <Input title={"Code input"} codeRunner={runCode}>

          </Input>

          <Output title={"Output:"} text={output}/>

      </div>
    </div>
  );
}

function Input({title, codeRunner, children}){
    const [code, setCode] = useState("");
    const [language, setLanguage] = useState("");

    function runCode(){
        codeRunner(code);
    }


    function onChangeHandler(value){
            setCode(...code, value);
    }

  return(
    <div>
      {title}

        <AceEditor
            mode="javascript"
            theme="monokai"
            className="codeInput"
            onChange={value => onChangeHandler(value)}
            showPrintMargin={false}
            enableLiveAutocompletion={true}
            enableBasicAutocompletion={true}
            enableSnippets={true}
            setOptions={{
                enableBasicAutocompletion: false,
                enableLiveAutocompletion: true,
                enableSnippets: true,
                showLineNumbers: true,
                tabSize: 2,
            }}/>

        <FileTypeStatus filetype={language}/>
        {children}
        <button className="btn" onClick={runCode}>Run code</button>
    </div>
  )
}

function Output({title, text}){
  return(
    <div className="margin-top-20">
      {title}
      <textarea disabled className="console" defaultValue={text}>

      </textarea>
    </div>
  )
}

function FileTypeStatus({filetype}) {

    return(
        <div className="fileType">
            {filetype}
        </div>
    )
}

export default App;
