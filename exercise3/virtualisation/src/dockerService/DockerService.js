import Axios from 'axios';


class DockerService{

    getOutputNode(code){
        let json = {
            input : code,
        };

        return Axios.post('http://localhost:9001/run/node', json);
    }

}

export let dockerService = new DockerService();
