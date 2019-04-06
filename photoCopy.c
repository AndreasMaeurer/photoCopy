/***********************************************************************   
 * 
 * @Author
                     _                      __  __                                
     /\             | |                    |  \/  |                               
    /  \   _ __   __| |_ __ ___  __ _ ___  | \  / | __ _  ___ _   _ _ __ ___ _ __ 
   / /\ \ | '_ \ / _` | '__/ _ \/ _` / __| | |\/| |/ _` |/ _ \ | | | '__/ _ \ '__|
  / ____ \| | | | (_| | | |  __/ (_| \__ \ | |  | | (_| |  __/ |_| | | |  __/ |   
 /_/    \_\_| |_|\__,_|_|  \___|\__,_|___/ |_|  |_|\__,_|\___|\__,_|_|  \___|_| 
     

Scope: Make a photocopy in one click on my Ubuntu Installation with my Canon Scanner and my HP Printer

PseudoCode:
	* Start
		* This program uses my Scanner (my specific Cannon) to scan whatever is on the glass.
		* It then saves this file in a temporary directory (In my case: ) called raw.tiff
		* It then creates a cropped file called output.tiff
		* It then takes that file and prints it "as is" to my HP printer	
		* It then deletes the raw.tiff file and the output.tiff file
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
Tested On:
	Ubuntu 18.04.2 LTS
	Ubuntu...
	
Future:
	* Make a python script?
	* shell script?
	* find a nicer icon / find a way to compile with a custom icon 	
	* write code to measure how long it took to Scan the Document.   (Maybe measure how long it takes to print??)
	* add a debug mode to the code?  (boolean named debug... If TRUE then all the debug statements are executed.  Else not...
	* how can you get the info from here: http://localhost:631/printers/   Through the Command Line?
	* Write a man page for this?
	* 
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

char currentVersion[100] = "photoCopy Version: 0.01beta";				//Adjust the version String here and only here.

int version() {
	printf("%s \n",currentVersion );  // for debugging
}

int help() {
	version();
	system("cat /home/ernesto/from/Andreas/photoCopy/photoCopy.help");
}

int showPrinters() {
	system("lpstat -p");
}

int showScanners() {
	// Note that this really only works when the scanner is turned ON.
	// If you run this and the scanner is off, the output is messy
	// Is there a way to handle this better?
	system("echo Looking for Scanners Please stand by.  This may take a while.");
	system("echo Please make sure your Scanner is turned on!");
	system("scanimage -L");
}

int show() {
	printf("Printers: \n");
	showPrinters();
	printf("Scanners: \n");
	showScanners();
}

int normalExecution() {
	// The Scanner should be a variable...
	// The Printer should be a variable...
	// Maybe DPI should be a variable ?
	// Perhaps all of these should be global variables...?
	// Need to figure out what the best DPI to use is...  600 could be considered too slow.  But it's Resolution is nice.
	
	system("scanimage -d 'pixma:04A9176D_0F27CE' --resolution 600dpi --format tiff > /tmp/raw.tiff"); //Scans 5104 X 7016  Needs to be cropped to: 5104 X 6575
	system("convert /tmp/raw.tiff -crop 5104x6575+0+0 /tmp/output.tiff");	//(widthxheight+left+top / wxh+l+t format)  //638x820
	system("lp -o page-bottom=N -o page-left=N -o page-right=N -o page-top=N -d HP_LaserJet_P1505 /tmp/output.tiff");
	system("rm /tmp/raw.tiff");
	system("rm /tmp/output.tiff");
}

// Taking argument as command line 
int main(int argc, char *argv[]) {

	//This whole next section, that handles the Arguments, seems a bit clumsy...
	
	//List the strings that we are going to compare later:
	char s00[100] = "-v";
	char s01[100] = "-V";
	char s02[100] = "--version";
	char s03[100] = "-s";
	char s04[100] = "--show";
	char s05[100] = "-sp";
	char s06[100] = "--show-printers";
	char s07[100] = "-ss";
	char s08[100] = "--show-scanners";	
	
	// IF the Argument Vector is 1 THEN just execute the normalExecution ... of the code...
	if (argc == 1) {
		normalExecution();
		//printf("The normal Execution of the code has been reached.\n");  // for debugging
		return 0; 
	}	
	// IF the argument is -v or -V or --version THEN print the Version to the command prompt.
	if ( (strcmp(argv[1],s00) == 0) || (strcmp(argv[1],s01) == 0) || (strcmp(argv[1],s02) == 0) ) {	//-v -V --version		
		printf("\n");  // One blank line.  Makes the output look nicer.
		version();
		return 0;
	}	
	//show
	if ( (strcmp(argv[1],s03) == 0) || (strcmp(argv[1],s04) == 0) ) {	//-s --show
		//printf("show has been reached.\n");  // for debugging
		show();
		return 0;
	}	
	//show Printer
	if ( (strcmp(argv[1],s05) == 0) || (strcmp(argv[1],s06) == 0) ) {	//-sp --show-printers
		showPrinters();
		return 0;
	}	
	//show Scanner
	if ( (strcmp(argv[1],s07) == 0) || (strcmp(argv[1],s08) == 0) ) {	//-ss --show-scanners
		showScanners();
		return 0;
	}
	else {
		printf("\n");  // One blank line.  Makes the output look nicer.
		help();
		return 0;
	}
}

//When I grow up I hope to be the kind of person who expects too much from sunsets
