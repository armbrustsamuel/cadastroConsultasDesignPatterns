#include "mainwindow.h"
#include <QApplication>

#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "exame.h"
#include "consultorio.h"
#include "pessoafactory.h"
#include "novoexameobserver.h"
#include "examefacade.h"
#include "alerta.h"

//remove (TEST)
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    // WORKING OK
//    pessoaFactory * factory;
//    factory = new Factory();

//    Pessoa * paciente =
//       factory->createPessoa(tipoPessoa::paciente);
//    paciente->setNome("Samuel");
//    paciente->setGenero(Genero::masculino);

//    // Crir um médico
//    Pessoa * medico =
//        factory->createPessoa(tipoPessoa::medico);
//    medico->setNome("Arthur Afonso");
//    medico->setGenero(Genero::masculino);

//    // Criar exame
//    Exame * visao = new Exame("04/04/2018", "oftalmologia", "Hospital Central", medico->getNome());
//    Exame * audicao = new Exame("01/04/2018", "otorrinolaringologia", "Consultorio Albernaz", medico->getNome());

//    // Criar consulta
//    Consulta * consulta = Consulta::getInstance();

//    // Adicionar paciente
//    consulta->setPaciente(new Paciente(paciente));
//    consulta->getPaciente()->setEnfermo("Diarreia");
//    consulta->getPaciente()->descreverCaso();

//    // Adiciona médico
//    consulta->setMedico(new Medico(medico));
//    consulta->getMedico()->setEspecialidade("Gastro");
//    consulta->getMedico()->setPrescricao("Tomar bastante água");
//    consulta->getMedico()->atender();

//    // Criar histórico
//    QList<Exame> *list = new QList<Exame>();
//    list->insert(1,*audicao);

//    Historico *historicoSamuel = new Historico();
//    NovoExameObserver obs(historicoSamuel);
//    historicoSamuel->setList(list);

//    consulta->getPaciente()->setHistorico(historicoSamuel);

//    // Adicionar novo exame
//    ExameFacade exm;
//    exm.proximaEtapa();
//    while (!exm.verificarEstado());
//    cout << "Exame aprovado depois de " << exm.numeroAtividades() << " atividades" << endl;
//    cout << endl;
//    consulta->getPaciente()->getHistorico()->adicionarExame(visao);

//    cout << "Paciente: " << consulta->getPaciente()->getNome() << endl;
//    cout << "Médico: " << consulta->getMedico()->getNome() << endl;

//    consulta->getPaciente()->getHistorico()->display();

//    // Criando um alerta
//    Alerta * alerta1 = new Alerta(
//                consulta->getPaciente()->getNome(),
//                consulta->getMedico()->getNome(),
//                "04/04/2018",
//                "Nova Consulta",
//                "armbrust.samuel@gmail.com");

//    // Criar observer

//    // Criar UI

//    // Criar Facade e lista de dados -> acesso a dados passando pelo facade

//    alerta1->display();

//    return 0;
}
