**Simcity Project Group 4 - Caleb Smay, Zachary Jones, and Daniel Kaderli**

This project simulates the growth of a city over a period of timesteps set by the user.

__Instructions__

Compile all .cpp files with a compiler of your choice. the program will call for the input of a config file. That file will contain the following:

On the first line, the config file should read "Region Layout:(InputFile.csv)" where the csv file that meets the requirements for an input file.

This csv file should have the following characters in a grid separated by commas.

'R' represents a residential zone

'I' represents an industrial zone

'C' represents a commercial zone

'-' represents a road

'T' represents a powerline

'#' represents a powerline over a road

'P' represents a power plant

Line 2 should include "Time Limit:(time steps)" where timesteps is how many times you want the program to iterate over.

Finally, line 3 should include "Refresh Rate:(rate)" which determines how many times it will refresh per time step.

Reading from the input file, the program will construct a 2d grid to view the city in the terminal. The zip file will include a sample input file for testing purposes.

Following the simulation, the user will be given a selection of choices to analyse the resultant region or subregions with tools to view population and pollution of cells.

