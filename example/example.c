#include <iostream>
using namespace std;

#include <TitanEngine>

static void TITCALL fncb_entry()
{
  auto pi = TitanGetProcessInformation();
  cout << "PID => " << pi->dwProcessId << endl;
  cout << "TID => " << pi->dwThreadId << endl;

  auto oep = GetContextData(UE_CIP);
  cout << "OEP => " << hex << oep << endl;

  StopDebug();
}

int main(int argc, char* argv[])
{
  InitDebugEx(LPSTR("example.exe"), nullptr, nullptr, fncb_entry);
  DebugLoop();

  return 0;
}