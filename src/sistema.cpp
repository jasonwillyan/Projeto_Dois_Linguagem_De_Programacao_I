#include "sistema.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit()
{
  return "Saindo do Concordo";
}

string Sistema::create_user (const string email, const string senha, const string nome)
{
	if(usuarioLogadoId != 0)
	{
		return "Nao pode criar usuario logado";
	}
	for(auto& usuario : colecao_usuarios)
	{
		if(usuario.getEmail() == email)
		{
			return "Usuario ja existe!";
		}
	}
	usuarios_cadastrados++;
	Usuario user(usuarios_cadastrados, nome, email, senha);

	colecao_usuarios.emplace_back(user);
	return "Usuario criado";
}

string Sistema::login(const string email, const string senha)
{
	if(usuarioLogadoId != 0)
	{
		return "Disconnect para poder fazer o login";
	}
	for(auto& usuario : colecao_usuarios)
	{
		if(usuario.getEmail() == email)
		{
			if(usuario.getSenha() == senha)
			{
				usuarioLogadoId = usuario.getId();
				return "Usuario logado como "+email;
			}
			else
			{
				return "Senha ou usuario invalidos!";
			}
		}
	}
	return "Usuario nao existe";
}

string Sistema::disconnect()
{
	int aux = usuarioLogadoId;
	if(usuarioLogadoId == 0)
	{
		return "Nao esta conectado";
	}
	else
	{
		usuarioLogadoId = 0;
		return "Desconectando usuario "+colecao_usuarios[aux-1].getEmail();
	}
}

string Sistema::create_server(const string nome)
{
	if(usuarioLogadoId == 0)
	{
		return "Usuario nao conectado";
	}
	for(auto& servidor : colecao_servidores)
	{
		if(usuarioLogadoId == servidor.getDono() && servidor.getNome() == nome)
		{
			return "Servidor com esse nome ja existe";
		}
	}
	Servidor server(usuarioLogadoId, nome);
	colecao_servidores.emplace_back(server);
	return "Servidor criado";
}

string Sistema::set_server_desc(const string nome, const string descricao)
{
	for(auto& servidor : colecao_servidores)
	{
		if(servidor.getNome() == nome)
		{
			if(usuarioLogadoId == servidor.getDono())
			{
				servidor.setDescricao(descricao);
				return "Descricao do servidor "+servidor.getNome()+" modificada!";
			}
			for(auto& participantesIds : servidor.getParticipantes())
			{
				if(participantesIds == usuarioLogadoId)
				{
					return "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce";
				}
			}
		}
	}
  	return "Servidor "+nome+" não existe";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers() {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants() {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */