#include "pessoa.h"

Pessoa::Pessoa(string name, int age, Genero gender,
               string address, string phone, string mail){
    setId(index);
    setNome(name);
    setEndereco(address);
    setGenero(gender);
    setIdade(age);
    setTelefone(phone);
    setEmail(mail);
    index+=1;
}

//Historico *Pessoa::getHistorico() const
//{
//    return historico;
//}

//void Pessoa::setHistorico(Historico *value)
//{
//    historico = value;
//}

Pessoa::Pessoa(Pessoa *pessoa){
    setId(index);
    setNome(pessoa->getNome());
    setEndereco(pessoa->getEndereco());
    setGenero(pessoa->getGenero());
    setIdade(pessoa->getIdade());
    setTelefone(pessoa->getTelefone());
    setEmail(pessoa->getEmail());
    index+=1;
}

// get
double Pessoa::getId() const
{
    return id;
}
string Pessoa::getNome(){
    return nome;
}
int Pessoa::getIdade(){
    return idade;
}
Genero Pessoa::getGenero(){
    return genero;
}
string Pessoa::getEndereco(){
    return endereco;
}
string Pessoa::getTelefone(){
    return telefone;
}
string Pessoa::getEmail(){
    return email;
}

// set
void Pessoa::setNome(string name){
    nome = name;
}
void Pessoa::setIdade(int age){
    idade = age;
}
void Pessoa::setGenero(Genero gender){
    genero = gender;
}
void Pessoa::setEndereco(string address){
    endereco = address;
}
void Pessoa::setTelefone(string phone){
    telefone = phone;
}
void Pessoa::setEmail(string mail){
    email = mail;
}

Historico *Pessoa::mockHistory()
{
    // Criar exame
    Exame * visao = new Exame("04/04/2018", "oftalmologia", "Hospital Central", "Samuel");
    Exame * audicao = new Exame("01/04/2018", "otorrinolaringologia", "Consultorio Albernaz", "Pedro Henrique");

    // Criar histórico
    QList<Exame> *list = new QList<Exame>();
    list->insert(1,*audicao);
    list->insert(2,*visao);

    Historico *historicoMock = new Historico();
    historicoMock->setList(list);

    return historicoMock;

//    sethistoricoSamuel;
    // MUDAR HISTORICO PARA PESSOA -> REMOVER DE PACIENTE
}

void Pessoa::setId(double value)
{
    id = value;
}
