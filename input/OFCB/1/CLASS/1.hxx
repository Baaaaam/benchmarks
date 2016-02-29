/*
Scenario parc français : 

- Inclut l'historique des réacteurs et des changement de gestion fuel

- Date de démarrage = PRIS "First Grid Connection"
	-> The date, when the plant is first connected to the electrical grid for the supply of power. After this date, the plant is considered in operation.   

- Gestion des MOX
	-> 1 réacteur full MOx M/3 et P/3
	-> 1 réacteur full UOx 2M/3 et 2P/3
	-> Ils ont des BU différents donc des temps de cycle différents

#############################
########## GESTION ##########
#############################

// REP 900 MWe
------------------------------------
STD900 :
	- Uranium @ 3.25%
	- Gestion 1/3
	- <BU>	= 37 GWj/t		(Rapport Sénat)
			= 33 GWj/t		(expl. Coeur REP)
	- BUmax	= 42 GWj/t		(Rapport Sénat)

GARANCE :
	- Uranium UNE @ 3.7%
	- Gestion 1/4
	- <BU>	= 42 GWj/t 		(expl. Coeur REP)
			= 46 GWj/t 		(Rapport Sénat)
			= 45.7 GWj/t	(Rapport IRSN)
	- BUmax	= 52 GWj/t		(Rapport sénat)

	- Uranium URE @ 4.1%
	- Gestion 1/4
	- <BU>	= 42 GWj/t 		(expl. Coeur REP)
			= 46 GWj/t 		(Rapport Sénat)
			= 45.7 GWj/t	(Rapport IRSN)
	- BUmax	= 52 GWj/t		(Rapport sénat)

CYCLADES CP0 (2000)
	- Uranium @ 4.2% + 52 Gadolinium
	- Gestion 1/3
	- <BU>	= 48 GWj/t		(Rapport Sénat)
			= 50 GWj/t		(expl. Coeur REP)
			= 47.2 GWj/t	(Rapport IRSN)
	- BUmax	= 51 GWj/t		(Rapport Sénat)

GALICE (2010)
	- Uranium @ 4.5% + ? Gadolinium
	- Gestion 1/3?
	- <BU>	= 55 GWj/t		(Rapport IRSN)
	- BUmax	= 62 GWj/t		(Rapport IRSN)

MOX
	- 1/3 MOx
	- Gestion 1/3
	- <BU>	= 39.5 GWj/t	(Rapport Sénat)
			= 32 GWj/t		(expl. Coeur REP) -> (ou 36 pour equ. UO2 3.25%) 
	- BUmax	= 41 GWj/t		(Rapport Sénat)

	- 1/4 MOx
	- Gestion 1/4
	- <BU>	= 45.8 GWj/t	(Rapport Sénat)
			= pas d'info
	- BUmax	= 51.8 GWj/t	(Rapport Sénat)

PARITE MOX
	- UNE : Gestion 1/4 (24 Ass) + 1/3 (4 ass)
	- <BU>	= 45.6 GWj/t	(Rapport IRSN)
	- BUmax	= 51.7 GWj/t	(Rapport Sénat)

	- MOx : 1/4 
	- <BU>	= 45.4 GWj/t	(Rapport IRSN)
	- BUmax	= 47.9 GWj/t	(Rapport Sénat)

HYBRIDE MOx:

------------------------------------

// REP 1300 MWe
------------------------------------
STD1300 :
	- Uranium @ 3.10%
	- Gestion 1/3
	- <BU>	= 36 GWj/t		(Rapport Sénat)
			= 33 GWj/t		(expl. Coeur REP)
	- BUmax	= 39 GWj/t		(Rapport Sénat)
et
	- Uranium @ 3.60%
	- Gestion 1/4
	- <BU>	= Pas d'info
			= 42 GWj/t		(expl. Coeur REP)
	- BUmax	= Pas d'info

GEMMES : 
	- Uranium @ 4% + 64 gadolinium
	- Gestion 1/3	
	- <BU>	= 48 GWj/t		(Rapport Sénat)
			= 43 GWj/t		(expl. Coeur REP)
	- BUmax	= 51 GWj/t		(Rapport Sénat)
------------------------------------

// REP 1450 MWe
------------------------------------
STD1450 :
	- Uranium @ 3.40%
	- Gestion 1/4
	- <BU>	= pas d'info
			= 43 GWj/t		(expl. Coeur REP)
	- BUmax	= pas d'info

ALCADE : (2008)
	- Uranium @ 4%
	- Gestion 1/3	
	- <BU>	= 46 GWj/t		(Rapport IRSN)
	- BUmax	= 52 GWj/t		(Rapport IRSN)
*/





//#######################################################################################################
//########################### Reactor Parameters ########################################################
//#######################################################################################################
#include "CLASSHeaders.hxx"

double 	M_A_CPX		= 0.4617;	//Assembly HM Mass
double 	M_A_P_N		= 0.5385;	//Assembly HM Mass
double 	M_A_EPR		= 0.5385;	//Assembly HM Mass
int 	N_A_CPX	= 157;
int 	N_A_P  	= 193;
int 	N_A_N  	= 205;
int 	N_A_EPR	= 205;

double M_CPX = M_A_CPX*N_A_CPX;
double M_P_P = M_A_P_N*N_A_P;
double M_P_N = M_A_P_N*N_A_N;


double P_CP0	= 2785e6;
double P_CPY	= 2785e6;
double P_P	= 3817e6;
double P_N	= 4270e6;


double BU_STD900	= 35;
double BU_STD900_min	= 33;
double BU_STD900_max	= 42;
double BU_STD900_mean	= (BU_STD900_max + BU_STD900_min)/2.;
double BU_STD900_STD	= (BU_STD900_max - BU_STD900_min)/2.;


double BU_GARANCE	= 44;
double BU_GARANCE_min	= 42;
double BU_GARANCE_max	= 46;
double BU_GARANCE_mean	= (BU_GARANCE_max + BU_GARANCE_min)/2.;
double BU_GARANCE_STD	= (BU_GARANCE_max - BU_GARANCE_min)/2.;

double BU_CYCLADE	= 49;
double BU_CYCLADE_min	= 47;
double BU_CYCLADE_max	= 50;
double BU_CYCLADE_mean	= (BU_CYCLADE_max + BU_CYCLADE_min)/2.;
double BU_CYCLADE_STD	= (BU_CYCLADE_max - BU_CYCLADE_min)/2.;


double BU_STD1300	= 34.5;
double BU_STD1300_min	= 33;
double BU_STD1300_max	= 39;
double BU_STD1300_mean	= (BU_STD1300_max + BU_STD1300_min)/2.;
double BU_STD1300_STD	= (BU_STD1300_max - BU_STD1300_min)/2.;

double BU_GEMMES	= 45;
double BU_GEMMES_min	= 43;
double BU_GEMMES_max	= 51;
double BU_GEMMES_mean	= (BU_GEMMES_max + BU_GEMMES_min)/2.;
double BU_GEMMES_STD	= (BU_GEMMES_max - BU_GEMMES_min)/2.;


double BU_STD1450	= 45;
double BU_STD1450_min	= 45;
double BU_STD1450_max	= 45;
double BU_STD1450_mean	= (BU_STD1450_max + BU_STD1450_min)/2.;
double BU_STD1450_STD	= (BU_STD1450_max - BU_STD1450_min)/2.;

double BU_ALCADE	= 46;
double BU_ALCADE_min	= 46;
double BU_ALCADE_max	= 53;
double BU_ALCADE_mean	= (BU_ALCADE_max + BU_ALCADE_min)/2.;
double BU_ALCADE_STD	= (BU_ALCADE_max - BU_ALCADE_min)/2.;

double BU_MOX		= 36; // Grosse incertitude
double BU_MOX_min	= 45; // Grosse incertitude
double BU_MOX_max	= 52; // Grosse incertitude
double BU_MOX_mean	= (BU_MOX_max + BU_MOX_min)/2.;
double BU_MOX_STD	= (BU_MOX_max - BU_MOX_min)/2.;

double FactorMOX	= 7.7272e-01; // Factor to get 4000 Assemblies MOX @ 2014


bool CP0	= true;
bool Fessenheim	= true;
bool Bugey	= true;


// CP0 //
// Fessenheim
// FS1
cSecond FS1_Start = 1977.3*cYear;
cSecond FS1_GAR_Start = 1995*cYear;
cSecond FS1_CYC_Start = 2001*cYear;
double FS1_CF = 0.678;

// FS2
cSecond FS2_Start = 1977.3*cYear;
cSecond FS2_GAR_Start = 1994.*cYear;
cSecond FS2_CYC_Start = 2001*cYear;
double FS2_CF = 0.684;


// BUGEY
// BG2
cSecond BG2_Start = 1978.4*cYear;
cSecond BG2_GAR_Start = 1994.*cYear;
cSecond BG2_CYC_Start = 2001*cYear;
double	BG2_CF = 0.678;

// BG3
cSecond BG3_Start = 1978.7*cYear;
cSecond BG3_GAR_Start = 1994.*cYear;
cSecond	BG3_CYC_Start = 2001*cYear;
double  BG3_CF = 0.648;

// BG4
cSecond BG4_Start = 1979.2*cYear;
cSecond BG4_GAR_Start = 1994.*cYear;
cSecond	BG4_CYC_Start = 2001*cYear;
double  BG4_CF = 0.691;

// BG5
cSecond BG5_Start = 1979.6*cYear;
cSecond BG5_GAR_Start = 1994.*cYear;
cSecond	BG5_CYC_Start = 1997*cYear;
double  BG5_CF = 0.702;


bool CPY	= true;
bool Graveline	= true;
bool Tricastin	= true;
bool Dampierre	= true;
bool Blayais	= true;
bool StLaurent	= true;
bool Cruas	= true;
bool Chinon	= true;

// CPY //

// Gravelines
//GR1
double  GR1_CF = 0.699;

cSecond GR1_Start = 1980.3*cYear;
cSecond GR1_GAR_Start = 1989.*cYear;
cSecond	GR1_MOX_Start = 2001*cYear;
cSecond GR1_T_MOX = 0;
double	GR1_FracMOX = 0.3*FactorMOX;

//GR2
double  GR2_CF = 0.732;

cSecond GR2_Start = 1980.7*cYear;
cSecond GR2_GAR_Start = 1995.*cYear;
cSecond	GR2_MOX_Start = 1998*cYear;
cSecond GR2_T_MOX = 0;
double	GR2_FracMOX = 0.3*FactorMOX;

//GR3
double  GR3_CF = 0.734;

cSecond GR3_Start = 1980.9*cYear;
cSecond GR3_MOX_Start = 1990.*cYear;
cSecond	GR3_MOX2_Start = 1993.*cYear;
cSecond GR3_T_MOX = 0;
double	GR3_FracMOX = 0.3*FactorMOX;

//GR4
double  GR4_CF = 0.756;

cSecond GR4_Start = 1981.5*cYear;
cSecond GR4_MOX_Start = 1990*cYear;
cSecond	GR4_MOX2_Start = 1993*cYear;
cSecond GR4_T_MOX = 0;
double	GR4_FracMOX = 0.3*FactorMOX;

//GR5
double  GR5_CF = 0.757;

cSecond GR5_Start = 1984.7*cYear;
cSecond GR5_GAR_Start = 1991*cYear;
cSecond	GR5_MOX_Start = 1999*cYear;
cSecond GR5_T_MOX = 0;
double	GR5_FracMOX = 0.3*FactorMOX;

//GR6
double  GR6_CF = 0.776;

cSecond GR6_Start = 1985.6*cYear;
cSecond GR6_GAR_Start = 1989*cYear;
cSecond	GR6_MOX_Start = 2007*cYear;
cSecond GR6_T_MOX = 0;
double	GR6_FracMOX = 0.3*FactorMOX;

// Tricastin
//TR1
double  TR1_CF = 0.729;

cSecond TR1_Start = 1980.4*cYear;
cSecond TR1_GAR_Start = 1989.*cYear;
cSecond	TR1_MOX_Start = 1997*cYear;
cSecond TR1_T_MOX = 0;
double	TR1_FracMOX = 0.3*FactorMOX;

//TR2
double  TR2_CF = 0.723;

cSecond TR2_Start = 1980.6*cYear;
cSecond TR2_GAR_Start = 1989*cYear;
cSecond	TR2_MOX_Start = 1997*cYear;
cSecond TR2_T_MOX = 0;
double	TR2_FracMOX = 0.3*FactorMOX;

//TR3
double  TR3_CF = 0.753;

cSecond TR3_Start = 1981.1*cYear;
cSecond TR3_GAR_Start = 1990*cYear;
cSecond	TR3_MOX_Start = 1998*cYear;
cSecond TR3_T_MOX = 0;
double	TR3_FracMOX = 0.3*FactorMOX;

//TR4
double  TR4_CF = 0.746;

cSecond TR4_Start = 1981.5*cYear;
cSecond TR4_GAR_Start = 1990*cYear;
cSecond	TR4_MOX_Start = 1998*cYear;
cSecond TR4_T_MOX = 0;
double	TR4_FracMOX = 0.3*FactorMOX;

// Dampierre
//DP1
double  DP1_CF = 0.716;

cSecond DP1_Start = 1980.2*cYear;
cSecond	DP1_MOX_Start = 1992*cYear;
cSecond DP1_T_MOX = 0;
double	DP1_FracMOX = 0.3*FactorMOX;

//DP2
double  DP2_CF = 0.704;

cSecond DP2_Start = 1980.9*cYear;
cSecond DP2_GAR_Start = 1990*cYear;
cSecond	DP2_MOX_Start = 1994*cYear;
cSecond DP2_T_MOX = 0;
double	DP2_FracMOX = 0.3*FactorMOX;

//DP3
double  DP3_CF = 0.732;

cSecond DP3_Start = 1981.1*cYear;
cSecond DP3_GAR_Start = 1990*cYear;
cSecond	DP3_MOX_Start = 1998*cYear;
cSecond DP3_T_MOX = 0;
double	DP3_FracMOX = 0.3*FactorMOX;

//DP4
double  DP4_CF = 0.732;

cSecond DP4_Start = 1981.6*cYear;
cSecond DP4_GAR_Start = 1990*cYear;
cSecond	DP4_MOX_Start = 1998*cYear;
cSecond DP4_T_MOX = 0;
double	DP4_FracMOX = 0.3*FactorMOX;

// Blayais
//BL1
double  BL1_CF = 0.723;

cSecond BL1_Start = 1981.5*cYear;
cSecond BL1_GAR_Start = 1990*cYear;
cSecond	BL1_MOX_Start = 1998*cYear;
cSecond BL1_T_MOX = 0;
double	BL1_FracMOX = 0.3*FactorMOX;

//BL2
double  BL2_CF = 0.763;

cSecond BL2_Start = 1982.5*cYear;
cSecond BL2_GAR_Start = 1992*cYear;
cSecond	BL2_MOX_Start = 1996*cYear;
cSecond BL2_T_MOX = 0;
double	BL2_FracMOX = 0.3*FactorMOX;

//BL3
double  BL3_CF = 0.772;

cSecond BL3_Start = 1983.7*cYear;
cSecond BL3_GAR_Start = 1992*cYear;
cSecond	BL3_MOX_Start = 2012*cYear;
cSecond BL3_T_MOX = 0;
double	BL3_FracMOX = 0.3*FactorMOX;

//BL4
double  BL4_CF = 0.772;

cSecond BL4_Start = 1983.5*cYear;
cSecond BL4_GAR_Start = 1992*cYear;
cSecond	BL4_MOX_Start = 2012*cYear;
cSecond BL4_T_MOX = 0;
double	BL4_FracMOX = 0.3*FactorMOX;

// SaintLaurent
//SL1
double  SL1_CF = 0.732;

cSecond SL1_Start = 1981.0*cYear;
cSecond SL1_MOX_Start = 1989*cYear;
cSecond	SL1_MOX2_Start = 1992*cYear;
cSecond SL1_T_MOX = 0;
double	SL1_FracMOX = 0.3*FactorMOX;

//SL2
double  SL2_CF = 0.707;

cSecond SL2_Start = 1981.5*cYear;
cSecond SL2_MOX_Start = 1989*cYear;
cSecond	SL2_MOX2_Start = 1992*cYear;
cSecond SL2_T_MOX = 0;
double	SL2_FracMOX = 0.3*FactorMOX;

// Cruas
//CR1
double  CR1_CF = 0.719;

cSecond CR1_Start = 1983.5*cYear;
cSecond	CR1_GAR_Start = 1990*cYear;

//CR2
double  CR2_CF = 0.719;

cSecond CR2_Start = 1984.7*cYear;
cSecond	CR2_GAR_Start = 1990*cYear;

//CR3
double  CR3_CF = 0.727;

cSecond CR3_Start = 1984.5*cYear;
cSecond	CR3_GAR_Start = 1990*cYear;

//CR4
double  CR4_CF = 0.716;

cSecond CR4_Start = 1984.8*cYear;
cSecond	CR4_GAR_Start = 1990*cYear;


// Chinnon
//CH1
double  CH1_CF = 0.728;

cSecond CH1_Start = 1982.9*cYear;
cSecond CH1_GAR_Start = 1990*cYear;
cSecond	CH1_MOX_Start = 1998*cYear;
cSecond CH1_T_MOX = 0;
double	CH1_FracMOX = 0.3*FactorMOX;

//CH2
double  CH2_CF = 0.728;

cSecond CH2_Start = 1983.9*cYear;
cSecond CH2_GAR_Start = 1990*cYear;
cSecond	CH2_MOX_Start = 1998*cYear;
cSecond CH2_T_MOX = 0;
double	CH2_FracMOX = 0.3*FactorMOX;

//CH3
double  CH3_CF = 0.738;

cSecond CH3_Start = 1986.8*cYear;
cSecond CH3_GAR_Start = 1990*cYear;
cSecond	CH3_MOX_Start = 1998*cYear;
cSecond CH3_T_MOX = 0;
double	CH3_FracMOX = 0.3*FactorMOX;

//CH4
double  CH4_CF = 0.746;

cSecond CH4_Start = 1987.8*cYear;
cSecond CH4_GAR_Start = 1991*cYear;
cSecond	CH4_MOX_Start = 1999*cYear;
cSecond CH4_T_MOX = 0;
double	CH4_FracMOX = 0.3*FactorMOX;


bool P4		= true;
bool Paluel	= true;
bool Flamanville= true;
bool SaintAlban	= true;
bool Cattenom	= true;
bool Belleville	= true;
bool Nogent	= true;
bool Penly	= true;
bool Golfech	= true;

// Paluel
//PL1
double  PL1_CF = 0.711;

cSecond PL1_Start = 1984.5*cYear;
cSecond	PL1_GEM_Start = 2000*cYear;

//PL2
double  PL2_CF = 0.701;

cSecond PL2_Start = 1984.7*cYear;
cSecond	PL2_GEM_Start = 2000*cYear;

//PL3
double  PL3_CF = 0.679;

cSecond PL3_Start = 1985.7*cYear;
cSecond	PL3_GEM_Start = 2001*cYear;

//PL4
double  PL4_CF = 0.711;

cSecond PL4_Start = 1986.5*cYear;
cSecond	PL4_GEM_Start = 2001*cYear;


// Flammanville
//FV1
double  FV1_CF = 0.696;

cSecond FV1_Start = 1985.9*cYear;
cSecond	FV1_GEM_Start = 1998*cYear;

//FV2
double  FV2_CF = 0.708;

cSecond FV2_Start = 1986.6*cYear;
cSecond	FV2_GEM_Start = 1999*cYear;


// Saint-Alban
//SA1
double  SA1_CF = 0.671;

cSecond SA1_Start = 1985.6*cYear;
cSecond	SA1_GEM_Start = 2001*cYear;

//SA2
double  SA2_CF = 0.672;

cSecond SA2_Start = 1986.5*cYear;
cSecond	SA2_GEM_Start = 1999*cYear;


// Cattenom
//CT1
double  CT1_CF = 0.694;

cSecond CT1_Start = 1986.9*cYear;
cSecond	CT1_GEM_Start = 1999*cYear;

//CT2
double  CT2_CF = 0.729;

cSecond CT2_Start = 1987.7*cYear;
cSecond	CT2_GEM_Start = 1997*cYear;

//CT3
double  CT3_CF = 0.737;

cSecond CT3_Start = 1990.5*cYear;
cSecond	CT3_GEM_Start = 1997*cYear;

//CT4
double  CT4_CF = 0.768;

cSecond CT4_Start = 1991.4*cYear;
cSecond	CT4_GEM_Start = 1998*cYear;


// Belleville
//BV1
double  BV1_CF = 0.706;

cSecond BV1_Start = 1987.8*cYear;
cSecond	BV1_GEM_Start = 1999*cYear;

//BV2
double  BV2_CF = 0.720;

cSecond BV2_Start = 1988.5*cYear;
cSecond	BV2_GEM_Start = 1997*cYear;


// Nogent
//NG1
double  NG1_CF = 0.717;

cSecond NG1_Start = 1987.8*cYear;
cSecond	NG1_GEM_Start = 1997*cYear;

//NG2
double  NG2_CF = 0.747;

cSecond NG2_Start = 1989.0*cYear;
cSecond	NG2_GEM_Start = 1998*cYear;


// Penly
//PN1
double  PN1_CF = 0.757;

cSecond PN1_Start = 1990.4*cYear;
cSecond	PN1_GEM_Start = 1999*cYear;

//PN2
double  PN2_CF = 0.772;

cSecond PN2_Start = 1992.2*cYear;
cSecond	PN2_GEM_Start = 1998*cYear;

// Golfech
//GO1
double  GO1_CF = 0.762;

cSecond GO1_Start = 1990.5*cYear;
cSecond	GO1_GEM_Start = 1997*cYear;

//GO2
double  GO2_CF = 0.762;

cSecond GO2_Start = 1990.5*cYear;
cSecond	GO2_GEM_Start = 1997*cYear;



bool N4		= true;
bool Choozb	= true;
bool Civaux	= true;

// Choozb
//CO1
double  CO1_CF = 0.776;

cSecond CO1_Start = 1996.7*cYear;
cSecond	CO1_ALC_Start = 2009*cYear;

//CO2
double  CO2_CF = 0.760;

cSecond CO2_Start = 1997.4*cYear;
cSecond	CO2_ALC_Start = 2009*cYear;


// Civaux
//CI1
double  CI1_CF = 0.748;

cSecond CI1_Start = 1998*cYear;
cSecond	CI1_ALC_Start = 2011*cYear;

//CI2
double  CI2_CF = 0.760;

cSecond CI2_Start = 2000*cYear;
cSecond	CI2_ALC_Start = 2011*cYear;


cSecond R_LT = 40. * cYear;;







