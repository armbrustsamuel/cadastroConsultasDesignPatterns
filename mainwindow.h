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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int pessoaIndex=0;
    explicit MainWindow(QWidget *parent = 0);
    pessoaFactory * factory;
    QList<Medico> *medicoList = new QList<Medico>();
    QList<Paciente> *pacienteList = new QList<Paciente>();

    ~MainWindow();

private slots:


    void on_listarExameBtn_pressed();

    void on_criarExameBtn_pressed();

    void on_criarPessoaBtn_pressed();

    void on_historicoBtn_pressed();

private:
    Ui::MainWindow *ui;

    void displayMedico();
    void displayHistorico();
    void displayExame(Exame *exame);
};

#endif // MAINWINDOW_H
