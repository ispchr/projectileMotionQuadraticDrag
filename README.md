# projectileMotionQuadraticDrag

## Brief Introduction & Theory
Defines a projectile solver (well-known problem in Newtonian physics) that includes quadratic drag in C++. The 2nd order differential equations (ODEs) defined through the free body diagram are solved using the RK4 (Runge-Kutta 4th Order) numerical scheme. Step sizes are kept constant (no adaptive step-size routine). Simulation parameters together with global contants are defined in the constants.h header file. Please refer to that header file if you want to increase your number of steps or run the simulation in another medium (water for example)

## Assumptions in Physics
It is assumed that the drag acting on the body is fully defined through the quadratic drag formula. It is also assumed that the drag coefficient equals with 0.5. Projectile motions are limited in the XY plane, with +y being orthogonal to the ground and aiming away from it. The only 2 forces considered on the body are its weight and the drag. Any other forces (magneric, etc.) are ingored in the ODEs definition.
## How to Run

The source code can be compiled using Microsoft's Visual Studio application. As far as complementary libraries go, the program uses the cmath, string, iostream, fstream and oimanip libraries. The upcoming release will have a compiled binary with all required DLLs for the user to run straigh away from their Windows machine. Please note that this is a command-line appplication, it does not have any user interface at this point.

## Output Results
The results from the simulation run are printed out on the command prompt, but are also saved in a file called projectileCoordinates.txt that can be found in the same folder as the executable. In this output file, the first column is time, the second column is x-coordinates and the third column is y-coordinates. All units are SI (or metric). These data can be used to plot the object's trajectory in either LibreOffice Calc, Python or any other scripting language or spreadsheet program. A trajectory graph is included below from a sample run. The graph was created in LibreOffice Calc.

![sampleTrajectoryGraph](https://user-images.githubusercontent.com/55588269/211155080-2f77a9e7-afc6-4370-907e-330de65328d9.png)
> Figure 1: Trajectory Graph of a Sample Run using the Solver

## Closing Remarks
This is the first version of this projectile solver with drag, in the coming weeks I will publish a release with pre-compiled binaries that anyone can run with a Windows machine. A user interface will be included in following releases, as this will make it easier for STEM students to run this simple solver and compare analytical solutions of projectile motions with the numerical equivalent that includes realistic drag. This solver is mostly meant for STEM students that are interested to observe the effects of realistic drag in projectile motions!
