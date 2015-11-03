CLASS Fuel recipe file ".dat" and ".info" file.
===============================================

the fuel recipe in CLASS comes with 2 files :
* the .dat file with contain the evolution of the main characteristics of the fuel,
* the .info file which contains the information used to build the evolution (mass, power, fuel type...)

".dat" file format description
----------------------------

the ".dat" file is formated in line : each line contain the evolution of a parameter at each timestep. A keyword is placed in the begining of each line to be able to identify the parameter described.

List of keyword used :

 * **time**: time in s of each step
 * **keff**: neutron multiplication factor 
 * **flux**: neutron flux in neutron/(second.cm2)
 * **inv**: followed by Z A I, evolution of the quantity of the nucleus Z A I in atoms
 * **XSFis**: followed by Z A I, evolution of the macroscopic fission cross section of the nucleus Z A I in barns
 * **XSCap**: followed by Z A I, evolution of the macroscopic capture cross section of the nucleus Z A I in barns 
 * **XSn2n**: followed by Z A I, evolution of the macroscopic (n,2n) cross section of the nucleus Z A I in barns
