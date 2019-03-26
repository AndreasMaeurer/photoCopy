"""
************************************************************************  
 * @Author
                     _                      __  __                                
     /\             | |                    |  \/  |                               
    /  \   _ __   __| |_ __ ___  __ _ ___  | \  / | __ _  ___ _   _ _ __ ___ _ __ 
   / /\ \ | '_ \ / _` | '__/ _ \/ _` / __| | |\/| |/ _` |/ _ \ | | | '__/ _ \ '__|
  / ____ \| | | | (_| | | |  __/ (_| \__ \ | |  | | (_| |  __/ |_| | | |  __/ |   
 /_/    \_\_| |_|\__,_|_|  \___|\__,_|___/ |_|  |_|\__,_|\___|\__,_|_|  \___|_| 
     

Scope: Make a photocopy in one click on my Ubuntu Laptop with my Canon Scanner and my HP Printer

* Start
	* This program uses my Scanner (my specific Cannon) to scan whatever is on the glass.
	* It then saves this file in a temporary directory (In my case: ) called raw.tiff
	* It then takes that file and prints it "as is" to my HP printer
	* It then deletes the raw.tiff file
* End 
* 

Notes:  
* On how to scan and print from the command line (to emulate a Photocopier with one click)

	References:
	https://makandracards.com/makandra/24202-linux-how-to-print-pdf-files-from-the-command-line

	First to find out what Scanner you are using go:	
	scanimage -L

		Then this works:
		scanimage -d "pixma:04A9176D_2F2912" --format tiff > raw.tiff
		
	Second to find out what Printer you are using go to:
	http://localhost:631/printers
	
		works:
		lp -d HP-LaserJet-1020 raw.tiff

Future:
* Make a C program?
* shell script?
* find a nice icon?
* 
************************************************************************
"""

Todo: actually finish this if want

import subprocess
subprocess.run([
""
""

"ls", "-l"])


https://stackoverflow.com/questions/89228/calling-an-external-command-in-python

these are the command line commands:
	
	'scanimage -d "pixma:04A9176D_2F2912" --format tiff > /tmp/raw.tiff'
	'lp -d HP-LaserJet-1020 /tmp/raw.tiff'
	'rm /tmp/raw.tiff'


# When I grow up I hope to be the kind of person who expects too much from sunsets
