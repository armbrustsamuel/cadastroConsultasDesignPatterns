#include "pessoafactory.h"

pessoaFactory::pessoaFactory()
{

}

void pessoaFactory::createPessoa(tipoPessoa type){
    if (type == tipoPessoa::medico){
        // return medico
    } else {
        if (type == tipoPessoa::paciente){
            // return paciente
        }
    }
}
