

class DockerService{

    getOutput(code){
        return Axios.get('host');
    }

}

export let dockerService = new DockerService();
