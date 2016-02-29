#include "CLASSHeaders.hxx"
#include <sstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <string>

using namespace std;


int main(int argc, char** argv)
{

//#######################################################################################################
//########################### DATA ######################################################################
//#######################################################################################################



	CLASSLogger* Logger	= new CLASSLogger("CLASS_OUTPUT.log",1,2);
	Scenario* gCLASS	= new Scenario(Logger);
	gCLASS->SetStockManagement(true);
	gCLASS->SetTimeStep(cYear/12.);
	gCLASS->SetZAIThreshold(90);
  gCLASS->SetSoberTerminalOutput();

//#######################################################################################################
//########################### BASES #####################################################################
//#######################################################################################################

	string s_BASE_PATH 	= "/Users/mouginot/work/App/CLASS/Database/";

	string s_DECAY_BASE	= s_BASE_PATH + "DECAY/ALL/Decay.idx";

	string s_STD900		= s_BASE_PATH + "PWR/UOX/FixedFuel/STD900.dat";

	DecayDataBank* DecayDB = new DecayDataBank(Logger, s_DECAY_BASE);
	gCLASS->SetDecayDataBase(DecayDB);

	EvolutionData* STD900 	= new EvolutionData(Logger, s_STD900 );

//#######################################################################################################
//########################### Stock #####################################################################
//#######################################################################################################

	/*Storage* Stock = new Storage(gCLASS->GetLog());
	Stock->SetName("Stock_UOX");
	Stock->AddToStock(ZAI(92,238,0)*  10);
	gCLASS->AddStorage(Stock);*/

	Storage* StockSPENTUOX = new Storage(Logger);
	StockSPENTUOX->SetName("Stock_UOX");
	gCLASS->AddStorage(StockSPENTUOX);

//#######################################################################################################
//########################### Pool ######################################################################
//#######################################################################################################

	Pool* C_UOX = new Pool(Logger,StockSPENTUOX, 5*cYear);
	C_UOX->SetName("Pool_UOX");
	gCLASS->AddPool(C_UOX);

//#######################################################################################################
//########################### FLEET #####################################################################
//#######################################################################################################



	Reactor* PWRUOX	 = new Reactor(gCLASS->GetLog(), STD900, StockSPENTUOX, 0, 120*cYear, 2838.7e6, 82, 43.03, 1);
	gCLASS->Add(PWRUOX);

	gCLASS->Evolution(cYear*120);

	delete gCLASS;
}
//==========================================================================================
// Compilation
//==========================================================================================
/*
 \rm CLASS* ; g++ -o CLASS_exec 1.cxx -I $CLASS_include -L $CLASS_lib -lCLASSpkg `root-config --cflags` `root-config --libs` -fopenmp -lgomp -Wunused-result
*/
