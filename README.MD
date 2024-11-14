# generic-ide
<img src="https://github.com/StarbotArc/generic-ide/blob/development/resource/icon-hq.png?raw=true"/>

The generic-ide project is a project meant to reinvent the modern IDE to a more customizable, stable, and efficient form.

## Building  

Building generic-ide from source has a few things to note:  
* There are variables that you have to adjust that may possibly come with unstability (such as what renderer is used.)  
* Some variables may change how functionality works in generic-ide (with, again changing renderers.)
* Finally, generally it's not recommended for the sake of stability.

It is recommended that you should first make a binary directory, as to keep out the compiled binary and CMake info out of the main directory you will be using.

Next, set what variables (GIDE_RENDERER) to what you want, you may find information either in the CMakeLists or in the documentation.

Finally run `cmake -DGIDE_RENDERER="lgl" ...` <- That part is required, and CMake will not be setup unless you have a specified renderer. `... .. && cmake --build .`

You should have a binary built now, and now from there you can run generic-ide.
