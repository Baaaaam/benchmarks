Test 1 : Single reactor over 120 years
=============================================

120 year simulation, single reactor, fixed fuel recipe, 120 years operation to be defined: reactor power, fuel burnup and associated recipes, (re)fueling strategy

Definition
----------------
120 year simulation, single reactor, fixed fuel recipe, 120 years operation

Reactor : 
* Type: LWR, 
* **Fuel**: UOX 3.25%w enriched uranium, 
* **Mass**: 82 tons (Oxyde Metal),
* **Thermal Power**: 2875e6 W -- **Efficiency**: 34%,  
* **Discharge burn-up** : 43.03 GWd/t -- Full Cycle length 3y, 
* **Capacity factor**: 1, 
* **Recipe sed**: REP900.dat from CLASS, fuelrecipe\STD900.dat
* **Suggested recipe**:
* Fresh UOX :
  * <sub>235</sub>U   :    3.25%w
  * <sub>238</sub>U   :   96.75%w
  * <sub>16</sub>O    :   TDB
* Used UOX @43.03 GWd/t (atomic):
  * <sub>234</sub>U   :   0.00026%
  * <sub>235</sub>U   :   0.52485%
  * <sub>236</sub>U   :   0.41405%
  * <sub>238</sub>U   :  89.33000%
  * <sub>238</sub>Pu  :   0.02294%
  * <sub>239</sub>Pu  :   0.54288%
  * <sub>240</sub>Pu  :   0.24718%
  * <sub>241</sub>Pu  :   0.15922%
  * <sub>242</sub>Pu  :   0.08248%
  * <sub>241</sub>Am  :   0.00399%
  * <sub>242</sub>Am* :   0.00008%
  * <sub>243</sub>Am  :   0.01890%
  * <sub>242</sub>Cm  :   0.00208%
  * <sub>243</sub>Cm  :   0.00005%
  * <sub>244</sub>Cm  :   0.00771%
  * <sub>245</sub>Cm  :   0.00049%
  * <sub>237</sub>Np  :   0.05255%
  * <sub>16</sub>O    : 191.34628%

Output
----------
TBD
