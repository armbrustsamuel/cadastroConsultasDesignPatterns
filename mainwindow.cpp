#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    factory = new Factory();

    // Consulta instance;
    consulta = Consulta::getInstance();

    obs = new NovoExameObserver(consulta);

    // Medico/Paciente combobox
    this->ui->tipoCbox->addItem("Médico");
    this->ui->tipoCbox->addItem("Paciente");

    // Gênero dafault values
    // change to programatically approach
    // https://stackoverflow.com/questions/16955918/qt-using-enums-with-qcombobox
    this->ui->generoCbox->addItem(QString::fromStdString("masculino"));
    this->ui->generoCbox->addItem(QString::fromStdString("feminino"));

    // Then, initialize the program with the value from files
    // Pacientes, Médicos ...

    // Inserting dummy pessoa
    pacienteList->insert(0,new Paciente());
    medicoList->insert(0,new Medico());

    // Especialidade
    this->ui->especialidadeCbox->addItem("Cardiologia");
    this->ui->especialidadeCbox->addItem("Otorrino");
    this->ui->especialidadeCbox->addItem("Ortopedia");

    // Consultórios
    this->ui->consultorioCbox->addItem("Unimed");
    this->ui->consultorioCbox->addItem("EcoCentro");
    this->ui->consultorioCbox->addItem("Dynamic");

    // Resultado
    this->ui->resultadoCbox->addItem("Pendente");
    this->ui->resultadoCbox->addItem("Pronto");

    carregarPessoas();
    carregarMedicos();
//    carregarConsultas();
}

MainWindow::~MainWindow()
{
    // savePacientes();
    // saveMedicos();
    delete ui;
}

void MainWindow::on_criarExameBtn_pressed()
{
    // read file add new exam to the file
    Exame * exame = new Exame();
    exame->setId(exameId);
    exame->setData(this->ui->dataTxt->text().toStdString());
    exame->setEndereco(this->ui->enderecoExameTxt->text().toStdString());
    exame->setEspecialidade(this->ui->especialidadeCbox->itemText(this->ui->especialidadeCbox->currentIndex()).toStdString());
    exame->setMedico(this->ui->medicoExameCbox->itemText(this->ui->medicoExameCbox->currentIndex()).toStdString());
    exame->setPaciente(this->ui->pacienteExameCbox->itemText(this->ui->pacienteExameCbox->currentIndex()).toStdString());
    exame->setResultado(this->ui->resultadoCbox->itemText(this->ui->resultadoCbox->currentIndex()).toStdString());

    this->ui->exameConsultaCbox->addItem(QString::number(exameId));
    this->ui->exameConsultaCbox_2->addItem(QString::number(exameId));
    exameList->insert(exameId, *exame);
    displayExame(exame);
    exameId++;

    QList<Exame> * exameList = new QList<Exame>();

    // carregar consulta do arquivo
    if(consultaList->size() > 1){
        for(int i = 1; i<consultaList->size(); i++){
            Consulta * cons = new Consulta(consultaList->at(i));
            if(cons->getPaciente()->getNome() == this->ui->pacienteExameCbox->itemText(this->ui->pacienteExameCbox->currentIndex()).toStdString()) {
                exameList = cons->getList();
                if(exameList->size() > 1){
                    for(int i = 0; i<exameList->size(); i++){
                        Exame *aux = new Exame(exameList->at(i));
                        this->ui->resumoConsultaTxt->append("");
                        this->ui->resumoConsultaTxt->append("Exame: "+ QString::number(aux->getId()));
                        this->ui->resumoConsultaTxt->append("Médico: " + QString::fromStdString(aux->getMedico()));
                        this->ui->resumoConsultaTxt->append("Endereço: " + QString::fromStdString(aux->getEndereco()));
                        this->ui->resumoConsultaTxt->append("Data: " + QString::fromStdString(aux->getData()));
                        this->ui->resumoConsultaTxt->append("Resultado: " + QString::fromStdString(aux->getResultado()));
                        this->ui->resumoConsultaTxt->append("Consultório: " + QString::fromStdString(consulta->getConsultorio()));
                    }
                }
            }
        }
    }

    if(consultaList->isEmpty()){
        consultaList->insert(0, *consulta);
    }

}

void MainWindow::on_criarPessoaBtn_pressed()
{
    Pessoa * pessoa;

    if (this->ui->tipoCbox->currentText() == "Paciente" ) {
        pessoa = factory->createPessoa(tipoPessoa::paciente);
        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        if(this->ui->generoCbox->currentIndex() == 0){
            pessoa->setGenero(Genero::masculino);
        } else if (this->ui->generoCbox->currentIndex() == 1) {
            pessoa->setGenero(Genero::feminino);
        }

        pessoa->setIdade(this->ui->idadeTxt->text().toInt());
        pessoa->setEndereco(this->ui->enderecoTxt->text().toStdString());
        pessoa->setTelefone(this->ui->telefoneTxt->text().toStdString());
        pessoa->setEmail(this->ui->emailTxt->text().toStdString());

        pacienteList->insert(pessoaIndex, pessoa);

        this->ui->pacienteExameCbox->addItem(QString::fromStdString(pessoa->getNome()));
        this->ui->pacienteConsultaCbox->addItem(QString::fromStdString(pessoa->getNome()));

//        pessoa->mockHistory();
    }

    else if (this->ui->tipoCbox->currentText() == "Médico" ) {
        pessoa = factory->createPessoa(tipoPessoa::medico);
        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        if(this->ui->generoCbox->currentIndex() == 0){
            pessoa->setGenero(Genero::masculino);
        } else if (this->ui->generoCbox->currentIndex() == 1) {
            pessoa->setGenero(Genero::feminino);
        }

        pessoa->setIdade(this->ui->idadeTxt->text().toInt());
        pessoa->setEndereco(this->ui->enderecoTxt->text().toStdString());
        pessoa->setTelefone(this->ui->telefoneTxt->text().toStdString());
        pessoa->setEmail(this->ui->emailTxt->text().toStdString());

        medicoList->insert(pessoaIndex, pessoa);

        this->ui->medicoExameCbox->addItem(QString::fromStdString(pessoa->getNome()));
        this->ui->medicoConsultaCbox->addItem(QString::fromStdString(pessoa->getNome()));
    }

    // Create Paciente
//    Paciente * paciente = new Paciente(pessoa);
//    paciente->setHistorico(pessoa->mockHistory());

    pessoaIndex+=1;
}

void MainWindow::on_historicoBtn_pressed()
{
    this->ui->pacientesTxt->clear();
    this->ui->medicosTxt->clear();
//    displayHistorico();
    displayMedico();
    displayPacientes();
}

void MainWindow::displayMedico()
{
    // loop into the medicoList and display each one
    if(medicoList->size() > 1){
        for(int i = 1; i<medicoList->size(); i++){
            Medico medico = new Medico(medicoList->at(i));
            medico.setEspecialidade("Cardiologia");
            this->ui->medicosTxt->append("");
            this->ui->medicosTxt->append("Nome: " + QString::fromStdString(medico.getNome()));
            this->ui->medicosTxt->append("Especialidade: " + QString::fromStdString(medico.getEspecialidade()));
            if(medico.getGenero() == Genero::masculino){
                this->ui->medicosTxt->append("Gênero: Masculino");
            } else if (medico.getGenero() == Genero::feminino){
                this->ui->medicosTxt->append("Gênero: Feminino");
            }
            this->ui->medicosTxt->append("Idade: " + medico.getIdade());
            this->ui->medicosTxt->append("Telefone: " + QString::fromStdString(medico.getTelefone()));
            this->ui->medicosTxt->append("Endereço: " + QString::fromStdString(medico.getEndereco()));
        }
    }
}

void MainWindow::displayPacientes()
{
    // loop into the medicoList and display each one
    if(pacienteList->size() > 1){
        for(int i = 1; i<pacienteList->size(); i++){
            Paciente paciente = new Paciente(pacienteList->at(i));
            this->ui->pacientesTxt->append("");
            this->ui->pacientesTxt->append("Nome: " + QString::fromStdString(paciente.getNome()));
            if(paciente.getGenero() == Genero::masculino){
                this->ui->pacientesTxt->append("Gênero: Masculino");
            } else if (paciente.getGenero() == Genero::feminino){
                this->ui->pacientesTxt->append("Gênero: Feminino");
            }
            this->ui->pacientesTxt->append("Idade: " + paciente.getIdade());
            this->ui->pacientesTxt->append("Telefone: " + QString::fromStdString(paciente.getTelefone()));
            this->ui->pacientesTxt->append("Endereço: " + QString::fromStdString(paciente.getEndereco()));
        }
    }
}

void MainWindow::displayExame(Exame * exame)
{
    this->ui->examesTxt->append("");
    this->ui->examesTxt->append("Id: "+QString::number(exame->getId()));
    this->ui->examesTxt->append("Exame de "+QString::fromStdString(exame->getEspecialidade()));
    this->ui->examesTxt->append("Médico: "+QString::fromStdString(exame->getMedico()));
    this->ui->examesTxt->append("Data: "+QString::fromStdString(exame->getData()));
    this->ui->examesTxt->append("Endereço: "+QString::fromStdString(exame->getEndereco()));
    this->ui->examesTxt->append("Resultado: "+QString::fromStdString(exame->getResultado()));
}

void MainWindow::on_adicionarExameBtn_pressed()
{
    if(exameList->size() > 1){
        for(int i = 0; i<exameList->size(); i++){
            Exame *exame = new Exame(exameList->at(i));
            if(exame->getId() == this->ui->exameConsultaCbox->itemText(this->ui->exameConsultaCbox->currentIndex()).toInt()){

                this->ui->resumoConsultaTxt->append("Exame: "+QString::number(exame->getId()));

                consulta->addExame(exame);

                this->ui->alteracoesConsultaTxt->clear();
                for(int i=0; i<consulta->getLog()->size(); i++){
                    string log = consulta->log->at(i);
                    this->ui->alteracoesConsultaTxt->append(QString::fromStdString(log));
                }
            }
        }
    }
}

void MainWindow::carregarPessoas()
{
    QFile g("/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGB/CadastroConsultas/pacienteList.bin");
    char BufferBytes[sizeof(Paciente)];
    Paciente * paciente = new Paciente();
    int test=0;

    if(g.open(QIODevice::ReadWrite)){
        while(!g.atEnd()){
            g.seek(test*(sizeof(Paciente)));
            g.read(BufferBytes, sizeof(Paciente));
            memcpy(paciente, BufferBytes, sizeof(Paciente));
            this->ui->pacientesTxt->append("");
            this->ui->pacientesTxt->append("Paciente:");
            this->ui->pacientesTxt->append(QString::fromStdString(paciente->getNome()));
            this->ui->pacientesTxt->append("Telefone: "+QString::fromStdString(paciente->getTelefone()));
            this->ui->pacientesTxt->append("Idade: "+QString::number(paciente->getIdade()));
            pacienteList->insert(pessoaIndex, paciente);
            this->ui->pacienteExameCbox->addItem(QString::fromStdString(paciente->getNome()));
            this->ui->pacienteConsultaCbox->addItem(QString::fromStdString(paciente->getNome()));
            pessoaIndex+=1;
            test++;
        }
        g.flush();
        g.close();
    }
    test = 0;
}

void MainWindow::carregarMedicos()
{
    QFile g("/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGB/CadastroConsultas/medicoList.bin");
    char BufferBytes[sizeof(Medico)];
    Medico * medico = new Medico();
    int test=0;

    if(g.open(QIODevice::ReadWrite)){
        while(!g.atEnd()){
            g.seek(test*(sizeof(Medico)));
            g.read(BufferBytes, sizeof(Medico));
            memcpy(medico, BufferBytes, sizeof(Medico));
            this->ui->medicosTxt->append("");
            this->ui->medicosTxt->append("Medico:");
            this->ui->medicosTxt->append(QString::fromStdString(medico->getNome()));
            this->ui->medicosTxt->append("Telefone: "+QString::fromStdString(medico->getTelefone()));
            this->ui->medicosTxt->append("Idade: "+QString::number(medico->getIdade()));
            medicoList->insert(pessoaIndex, medico);
            this->ui->medicoExameCbox->addItem(QString::fromStdString(medico->getNome()));
            this->ui->medicoConsultaCbox->addItem(QString::fromStdString(medico->getNome()));
            pessoaIndex+=1;
            test++;
        }
        g.flush();
        g.close();
    }
    test = 0;
}

void MainWindow::savePacientes()
{
    QFile *f;
    f = new QFile("/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGB/CadastroConsultas/pacienteList.bin");

    f->remove();

    if(pacienteList->size() > 1){
        for(int i = 1; i<pacienteList->size(); i++){
            Paciente *aux = new Paciente(this->pacienteList->at(i));
            if(f->open(QIODevice::WriteOnly | QIODevice::Append)){
                QDataStream ds (f);
                char BufferBytes[sizeof(Paciente)];
                std::memcpy(BufferBytes, aux, sizeof(Paciente));
                f->write(BufferBytes, sizeof(Paciente));
                f->flush();
                f->close();
            }
        }
    }
}

void MainWindow::saveMedicos()
{
    QFile *f;
    f = new QFile("/Users/samuel/Documents/Unisinos/Programacao_Orientada_Objeto_II/TGB/CadastroConsultas/medicoList.bin");

    f->remove();

    if(medicoList->size() > 1){
        for(int i = 1; i<medicoList->size(); i++){
            Medico *aux = new Medico(this->medicoList->at(i));
            if(f->open(QIODevice::WriteOnly | QIODevice::Append)){
                QDataStream ds (f);
                char BufferBytes[sizeof(Medico)];
                std::memcpy(BufferBytes, aux, sizeof(Medico));
                f->write(BufferBytes, sizeof(Medico));
                f->flush();
                f->close();
            }
        }
    }
}

void MainWindow::on_processarExame_pressed()
{
    if(consulta->getList()->size() > 1){
        for(int i = 0; i<consulta->getList()->size(); i++){
            Exame *exame = new Exame(exameList->at(i));
            if(exame->getId() == this->ui->exameConsultaCbox_2->itemText(this->ui->exameConsultaCbox_2->currentIndex()).toInt()){
                ExameFacade exm;
                exm.proximaEtapa();
                while (!exm.verificarEstado());
                exame->setResultado("Pronto");
                consulta->getList()->replace(i, *exame);
            }
        }
    }
}

void MainWindow::on_marcarConsultaBtn_pressed()
{
    this->ui->resumoConsultaTxt->clear();
    this->ui->resumoConsultaTxt->append("Consulta marcada para "+ this->ui->pacienteConsultaCbox->itemText(this->ui->pacienteConsultaCbox->currentIndex()));
    this->ui->resumoConsultaTxt->append(this->ui->medicoConsultaCbox->itemText(this->ui->medicoConsultaCbox->currentIndex())
                                            + " está atendendo em " +
                                        this->ui->consultorioCbox->itemText(this->ui->consultorioCbox->currentIndex()));
    consulta->setConsultorio(this->ui->consultorioCbox->itemText(this->ui->consultorioCbox->currentIndex()).toStdString());

    // salvar consulta em arquivo
//    saveConsultas();
}

void MainWindow::on_letExamesBtn_pressed()
{
    this->ui->resumoConsultaTxt->clear();
    QList<Exame> *exame = consulta->getList();

    if(exame->size() > 1){
        for(int i = 0; i<exame->size(); i++){
            Exame *aux = new Exame(exame->at(i));
            this->ui->resumoConsultaTxt->append("");
            this->ui->resumoConsultaTxt->append("Exame: "+ QString::number(aux->getId()));
            this->ui->resumoConsultaTxt->append("Médico: " + QString::fromStdString(aux->getMedico()));
            this->ui->resumoConsultaTxt->append("Endereço: " + QString::fromStdString(aux->getEndereco()));
            this->ui->resumoConsultaTxt->append("Data: " + QString::fromStdString(aux->getData()));
            this->ui->resumoConsultaTxt->append("Resultado: " + QString::fromStdString(aux->getResultado()));
            this->ui->resumoConsultaTxt->append("Consultório: " + QString::fromStdString(consulta->getConsultorio()));
        }
    }
}

void MainWindow::on_testeBtn_pressed()
{
    savePacientes();
    saveMedicos();
}
