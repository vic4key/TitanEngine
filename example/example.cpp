#include <iostream>
using namespace std;

#include <TitanEngine_CPP>
using namespace TE;

class Dbg : public Debugger
{
public:
  Dbg() : Debugger() {}
  virtual ~Dbg() {}

  static void TITCALL fncb_entry()
  {
    auto pi = GetProcessInformation();
    cout << "PID => " << pi->dwProcessId << endl;
    cout << "TID => " << pi->dwThreadId << endl;

    auto oep = GetContextData(UE_CIP);
    cout << "OEP => " << hex << oep << endl;

    StopDebug();
  }
};

int main(int argc, char* argv[])
{
  Dbg dbg;
  dbg.InitDebugEx("example.exe", nullptr, nullptr, Dbg::fncb_entry);
  dbg.DebugLoop();

  return 0;
}