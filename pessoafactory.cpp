#include "pessoafactory.h"

class Factory: public pessoaFactory {
public:
    Pessoa * createPessoa(tipoPessoa type){
        if (type == tipoPessoa::medico){
            return new Medico;
        } else {
            if (type == tipoPessoa::paciente){
                return new Paciente;
            }
        }
    }
};


