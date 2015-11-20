Open Fuel Cycle Benchmark (OFCB)
====================

This is a repository for the specification of the different test of the open fuel cycle benchmark.
It contains the specification file in different formats for the different test.

<h2 id="background">Background</h2>

In support of a community of scholars who are developing software to simulate the nuclear fuel cycle, this set of problems is a community generated list of scenarios that is intended to progress from simple problems to verify fundamental behavior through more complex problems to be used to validate overall system evolution.


<h2 id="repo">Repository layout and use:</h2>

* [the main repository](https://github.com/cyclus/benchmarks) will hold only canonical problem definitions [\[1\]](#r) and supporting information in an OFCB directory,
* each participating fuel cycle tool project should:
  - fork this repository,
  - create a directory for their code,
  - place all code-specific input in that directory in a layout that aligns with the OFCB layout,
  - include a tool to convert json format file to their own tool input format, abd vice-versa.




<h2 id="link">Important Link</h2>
* [Github Repository](https://github.com/cyclus/benchmarks).
* [Google Group](https://groups.google.com/forum/#!forum/nfcs-dev).
* [Benchmark specification](http://docs.google.com/document/d/1kUfD3rwFf4xceZvqXzywrcH2GuWm8BWvUDSw0A1buKI).
* [Hangout event](https://plus.google.com/events/ckk141kjtk8fsf09vm0dbrepu0k).
* [Meeting minutes](https://docs.google.com/document/d/1_h3vw2HVZ2v_PW24BQ-CdsMQ_MeBO_HA3CKZ6P3On3A/edit?usp=sharing).



<h2 id="r">References</h2>

[1] the JSON format specification can be found in the [JSON\_format_specification.rst](JSON_format_specification.rst) file