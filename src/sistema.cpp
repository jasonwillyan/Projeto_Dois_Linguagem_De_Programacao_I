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

string Sistema::set_server_invite_code(const string nome, const string codigo)
{
	for(auto& servidor : colecao_servidores)
	{
		if(servidor.getNome() == nome)
		{
			if(usuarioLogadoId == servidor.getDono())
			{
				if(codigo == "")
				{
					servidor.setConvite(codigo);
					return "Codigo de convite do servidor "+servidor.getNome()+" removido!";
				}
				else
				{
					servidor.setConvite(codigo);
					return "Código de convite do servidor "+servidor.getNome()+" modificado!";
				}
			}
			for(auto& participantesIds : servidor.getParticipantes())
			{
				if(participantesIds == usuarioLogadoId)
				{
					return "Voce nao pode criar o codigo de um servidor que nao e seu";
				}
			}
		}
	}
	return "voce nao tem um servidor";
}

string Sistema::list_servers()
{	
	cout << "LISTA DE SERVIDORES" << endl;
	for(auto& servidor : colecao_servidores)
	{
		cout << "NOME: " << servidor.getNome() << endl;
		if(servidor.getDescricao() != "")
		{
			cout << "DESCRICAO: " << servidor.getDescricao() << endl;
		}
		if(servidor.getConvite() != "")
		{
			cout << "SERVIDOR FECHADO" << endl;
		}else
		{
			cout << "SERVIDOR ABERTO" << endl;
		}
		cout << endl;
	}
	return "************************";
}

string Sistema::remove_server(const string nome)
{
	for(auto servidor = colecao_servidores.begin(); servidor != colecao_servidores.end(); ++servidor)
	{
		if(servidor->getNome() == nome)
		{
			if(usuarioLogadoId == servidor->getDono())
			{
				colecao_servidores.erase(servidor);
				return "Servidor "+nome+" removido";
			}
			for(auto& participantesIds : servidor->getParticipantes())
			{
				if(participantesIds == usuarioLogadoId)
				{
					return "Voce nao e o dono do servidor "+nome;
				}
			}
		}
	}
	return "Servidor "+nome+"nao encontrado";
}

string Sistema::enter_server(const string nome, const string codigo)
{
	for(auto& servidor : colecao_servidores)
	{
		if(servidor.getNome() == nome)
		{
			if(usuarioLogadoId == servidor.getDono())
			{
				servidor.addParticipante(usuarioLogadoId);
				colecao_usuarios[usuarioLogadoId-1].addServer(&servidor);
				return "Entrou no servidor com sucesso";
			}
			else
			{
				for(auto& participantesIds : servidor.getParticipantes())
				{
					if(participantesIds == usuarioLogadoId)
					{
						return "Voce ja esta neste servidor";
					}
				}
				if(servidor.getConvite() == "" || servidor.getConvite() == codigo)
				{
					servidor.addParticipante(usuarioLogadoId);
					colecao_usuarios[usuarioLogadoId-1].addServer(&servidor);
					return "Entrou no servidor com sucesso";
				}
				else if(servidor.getConvite() != "" && codigo == "")
				{
					return "Servidor requer código de convite";
				}	
			}
		}
	}
	return "Servidor nao encontrado";
}

string Sistema::leave_server()
{
	colecao_usuarios[usuarioLogadoId-1].addServer(nullptr);
	for(auto& servidor : colecao_servidores)
	{
		for(auto usuario = servidor.getParticipantes().begin(); usuario != servidor.getParticipantes().end(); ++usuario)
		{
			if(colecao_usuarios[(*usuario)-1].getId() == usuarioLogadoId)
			{
				servidor.getParticipantes().erase(usuario);
				return "Saindo do servidor "+servidor.getNome();
			}
		}
	}
	return "voce nao esta conectado em nenhum servidor";
}

string Sistema::list_participants()
{
	if(colecao_usuarios[usuarioLogadoId-1].getServer() == nullptr)
	{
		return "Voce nao esta conectado a nenhum servidor";
	}
	cout << "LISTA DE PARTICIPANTES" << endl;
	for(auto& participante : colecao_usuarios[usuarioLogadoId-1].getServer()->getParticipantes())
	{
		cout << colecao_usuarios[participante-1].getNome() << endl;
	}
	return "************************";
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