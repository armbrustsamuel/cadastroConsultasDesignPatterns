#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    factory = new Factory();

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listarExameBtn_pressed()
{
    // read file and add exams
}

void MainWindow::on_criarExameBtn_pressed()
{
    // read file add new exam to the file
    Exame * exame = new Exame();
    exame->setData(this->ui->dataTxt->text().toStdString());
    exame->setEndereco(this->ui->enderecoTxt->text().toStdString());
    exame->setEspecialidade(this->ui->especialidadeTxt->text().toStdString());
    exame->setMedico(this->ui->medicoExameCbox->itemText(this->ui->medicoExameCbox->currentIndex()).toStdString());

    displayExame(exame);
}

void MainWindow::on_criarPessoaBtn_pressed()
{
    Pessoa * pessoa;

    if (this->ui->tipoCbox->currentText() == "Paciente" ) {
        pessoa = factory->createPessoa(tipoPessoa::paciente);
        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        pacienteList->insert(pessoaIndex, pessoa);

        this->ui->pacienteExameCbox->addItem(QString::fromStdString(pessoa->getNome()));

        pessoa->mockHistory();
    }

    else if (this->ui->tipoCbox->currentText() == "Médico" ) {
        pessoa = factory->createPessoa(tipoPessoa::medico);
        pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

        medicoList->insert(pessoaIndex, pessoa);

        this->ui->medicoExameCbox->addItem(QString::fromStdString(pessoa->getNome()));
    }

    pessoa->setNome(this->ui->nomePessoaTxt->text().toStdString());

    if(this->ui->generoCbox->currentIndex() == 0){
        pessoa->setGenero(Genero::masculino);
    } else if (this->ui->generoCbox->currentIndex() == 1) {
        pessoa->setGenero(Genero::feminino);
    }

    pessoa->setIdade(this->ui->idadeTxt->text().toInt());
    pessoa->setEndereco(this->ui->enderecoExameTxt->text().toStdString());
    pessoa->setTelefone(this->ui->telefoneTxt->text().toStdString());
    pessoa->setEmail(this->ui->emailTxt->text().toStdString());

    // Create Paciente
//    Paciente * paciente = new Paciente(pessoa);
//    paciente->setHistorico(pessoa->mockHistory());

    // Instead of write in cmd, display in the textEdit
//    paciente->getHistorico()->display();
//    this->ui->historicoTxt->append();

    pessoaIndex+=1;
}

void MainWindow::on_historicoBtn_pressed()
{
    // Loop at the pacienteList
    // get paciente and generate historico
    displayHistorico();
}

void MainWindow::displayMedico()
{
    // loop into the medicoList and display each one
}

void MainWindow::displayHistorico()
{
    // logic to loop into the historicoList
    // display each one inside the textEdit
    // this->ui->historicoTxt->append();
}

void MainWindow::displayExame(Exame * exame)
{
    this->ui->examesTxt->append("");
    this->ui->examesTxt->append("Exame de "+QString::fromStdString(exame->getEspecialidade()));
    this->ui->examesTxt->append("Médico: "+QString::fromStdString(exame->getMedico()));
    this->ui->examesTxt->append("Data: "+QString::fromStdString(exame->getData()));
    this->ui->examesTxt->append("Endereço: "+QString::fromStdString(exame->getEndereco()));
    // logic to loop into the historicoList
    // display each one inside the textEdit
    // this->ui->examesTxt->append();
}
