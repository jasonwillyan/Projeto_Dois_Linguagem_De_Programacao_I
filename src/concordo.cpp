#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "sistema.hpp"
#include "executor.hpp"

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  cout << sistema.create_user("jasonwillyan@hotmail.com", "123", "jason willyan") << endl;
  cout << sistema.login("jasonwillyan@hotmail.com", "123") << endl;
  cout << sistema.create_channel("canal-do-jason", "texto") << endl;
  cout << sistema.create_server("servidor-do-jason") << endl;
  cout << sistema.list_servers() << endl;
  cout << sistema.enter_server("servidor-do-jason", "") << endl;
  cout << sistema.create_channel("canal-do-jason", "texto") << endl;
  cout << sistema.create_channel("canal-da-gritaria", "voz") << endl;
  cout << sistema.list_channels() << endl;
  cout << sistema.enter_channel("canal-do-jason") << endl;
  cout << sistema.list_messages() << endl;
  cout << sistema.send_message("A LUA ME TRAIU") << endl;
  cout << sistema.send_message("ACREDITEI NAQUELA ILUSÃO") << endl;
  cout << sistema.send_message("A LUA ME TRAIU") << endl;
  cout << sistema.send_message("FIQUEI SOZINHA E LOUCA POR VOCE") << endl;
  cout << sistema.list_messages() << endl;
  cout << sistema.enter_channel("canal-da-gritaria") << endl;
  cout << sistema.send_message("CAVALO MANCO") << endl;
  cout << sistema.send_message("CAVALO CADEIRANTE") << endl;
  cout << sistema.list_messages() << endl;
  cout << sistema.leave_channel() << endl;
  cout << sistema.send_message("pa pa pa") << endl;
  cout << sistema.leave_server() << endl;
  cout << sistema.send_message("po po po") << endl;

  executor.iniciar(cin, cout);



  return 0;
}