#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "exame.h"
#include "pessoa.h"
#include "consultorio.h"
#include "pessoafactory.h"
#include "pessoafactory.cpp"
#include "novoexameobserver.h"
#include "examefacade.h"
#include "alerta.h"

#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int pessoaIndex=1;
    int exameId=0;
    explicit MainWindow(QWidget *parent = 0);
    pessoaFactory * factory;
    Consulta * consulta;
    QList<Medico> *medicoList = new QList<Medico>();
    QList<Paciente> *pacienteList = new QList<Paciente>();
    QList<Exame> *exameList = new QList<Exame>();

    NovoExameObserver *obs;

    ~MainWindow();

    void carregarPessoas();
    void carregarMedicos();

    void savePacientes();
    void saveMedicos();

private slots:

    void on_criarExameBtn_pressed();

    void on_criarPessoaBtn_pressed();

    void on_historicoBtn_pressed();

    void on_adicionarExameBtn_pressed();

    void on_processarExame_pressed();

    void on_marcarConsultaBtn_pressed();

    void on_letExamesBtn_pressed();

    void on_testeBtn_pressed();

private:
    Ui::MainWindow *ui;

    void displayMedico();
    void displayHistorico();
    void displayExame(Exame *exame);
};

#endif // MAINWINDOW_H
