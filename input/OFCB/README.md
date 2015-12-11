Open Fuel Cycle Benchmark (OFCB)
====================

This is a repository for the specification of the different test of the open fuel cycle benchmark.
It contains the specification file in different formats for the different test.


Background
----------------

In support of a community of scholars who are developing software to simulate the nuclear fuel cycle, this set of problems is a community generated list of scenarios that is intended to progress from simple problems to verify fundamental behavior through more complex problems to be used to validate overall system evolution.

Generic test definition
-----------------

Problems based on a once-through cycle:

1. **120 year simulation, single reactor, fixed fuel recipe, 120 years operation** 
			to be defined: reactor power, fuel burnup and associated recipes, (re)fueling strategy
2. **120 year simulation, two reactors, fixed fuel recipe, 120 years operation**
3. **120 year simulation, ten reactors, fixed fuel recipe, 120 years operation**
4. **120 year simulation, two reactors, fixed fuel recipe, first reactor operates for 120 years, second reactor starts at midpoint**
5. **120 year simulation, ten reactors, fixed fuel recipe, a new reactor starts every 10 years and continues throughout simulation**
6. **120 year simulation, single reactor, fixed fuel recipe, 60 years operation replaced by another reactor**
7. **120 year simulation, two reactors, fixed fuel recipe, each has 60 years operation replaced by another reactor**
8. **120 year simulation, ten reactors, fixed fuel recipe, each has 60 years operation replaced by another reactor**
9. **120 year simulation, two reactors, fixed fuel recipe, reactor A: operates 20 years, replaced by 60 year reactor and another 60 year reactor, reactor B: operates 40 years, replaced by 60 year reactor and another 60 year reactor**
10. **120 year simulation, ten reactors, fixed fuel recipe, reactor lifetimes are staggered, with a new reactor shutting down/replaced each 10 years**


A more detailled test definition and output definition can be found in [here](http://docs.google.com/document/d/1kUfD3rwFf4xceZvqXzywrcH2GuWm8BWvUDSw0A1buKI).

Contains
--------------------

Each test folder contain the specific input for the corresponding test.

In each folder you will find:
The input file for the CYCLUS simulation tool, as wel as the corresponding results.
Up to now to result have been generated using the [CYCLUS2CVS tools](https://github.com/Baaaaam/CYCLUS2FCO/tree/CYCLUStoCVS).

note: a json file is suppose to be a ccanonical description of the fuel cycle, allowing each user to build a script wich convert a json file in a input file of their own fuel cycle simulator. An exemple of a python script converting json file in xml CYCLUS input file can be found at the root of the repository (the src/tests/xml2json folders)



