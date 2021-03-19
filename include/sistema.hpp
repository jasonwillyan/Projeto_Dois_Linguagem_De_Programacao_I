#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "usuario.hpp"
#include "servidor.hpp"

using namespace std;

// Sistema deve concentrar todas as operações do Concordo
class Sistema {
  private:
    vector <Servidor> colecao_servidores; //precisa guardar uma coleção de servidores;
    vector <Usuario> colecao_usuarios;//precisa guardar uma coleção de usuários;
    int usuarioLogadoId = 0; // se 0: não logado, caso contrário guarda o id do usuário logado
    string nomeServidorConectado;
    string nomeCanalConectado;
    int usuarios_cadastrados = 0;
  public:

  string quit(); //OK
  string create_user (const string email, const string senha, const string nome);//OK
  string login(const string email, const string senha);//OK
  string disconnect(); //OK
  string create_server(const string nome); //OK
  string set_server_desc(const string nome, const string descricao); //OK
  string set_server_invite_code(const string nome, const string codigo); //OK
  string list_servers(); //OK
  string remove_server(const string nome); //OK
  string enter_server(const string nome, const string codigo); //OK
  string leave_server(); //OK
  string list_participants(); //OK
  string list_channels();
  string create_channel(const string nome, const string tipo);
  string enter_channel(const string nome);
  string leave_channel();
  string send_message(const string mensagem);
  string list_messages();
};

#endif