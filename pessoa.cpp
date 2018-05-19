#include "pessoa.h"

Pessoa::Pessoa(string name, int age, Genero gender,
               string address, string phone, string mail){
    setNome(name);
    setEndereco(address);
    setGenero(gender);
    setIdade(age);
    setTelefone(phone);
    setEmail(mail);
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
void Pessoa::setId(double value)
{
    id = value;
}
