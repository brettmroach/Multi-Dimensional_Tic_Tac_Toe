//write_term.cpp

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "  Usage: " << argv[0] << " <path> <width>\n";
        exit(1);
    }
    string dir = argv[1], width = argv[2];
    ofstream outfile;
    outfile.open("Terminal_Execution/TTT.terminal");
    outfile << "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n\
<plist version=\"1.0\">\n\
<dict>\n\
	<key>BackgroundColor</key>\n\
	<data>\n\
	YnBsaXN0MDDUAQIDBAUGBwpYJHZlcnNpb25ZJGFyY2hpdmVyVCR0b3BYJG9iamVjdHMS\n\
	AAGGoF8QD05TS2V5ZWRBcmNoaXZlctEICVRyb290gAGmCwwXHR4lVSRudWxs1Q0ODxAR\n\
	EhMUFRZcTlNDb21wb25lbnRzVU5TUkdCXE5TQ29sb3JTcGFjZV8QEk5TQ3VzdG9tQ29s\n\
	b3JTcGFjZVYkY2xhc3NPECkwLjIwMjU4NTg1NzQgMC4wNzUzNDgzNjg2MiAwLjI3MjEy\n\
	ODAxNzUgMU8QKDAuMTY1MDQ3OTQzNiAwLjAzNzczNTk3MjU1IDAuMjE4NTkyNTg0MQAQ\n\
	AYACgAXTGBEZGhscVU5TSUNDWU5TU3BhY2VJRIADgAQQDE8RAiQAAAIkYXBwbAQAAABt\n\
	bnRyUkdCIFhZWiAH4QAHAAcADQAWACBhY3NwQVBQTAAAAABBUFBMAAAAAAAAAAAAAAAA\n\
	AAAAAAAA9tYAAQAAAADTLWFwcGzKGpWCJX8QTTiZE9XR6hWCAAAAAAAAAAAAAAAAAAAA\n\
	AAAAAAAAAAAAAAAAAAAAAApkZXNjAAAA/AAAAGVjcHJ0AAABZAAAACN3dHB0AAABiAAA\n\
	ABRyWFlaAAABnAAAABRnWFlaAAABsAAAABRiWFlaAAABxAAAABRyVFJDAAAB2AAAACBj\n\
	aGFkAAAB+AAAACxiVFJDAAAB2AAAACBnVFJDAAAB2AAAACBkZXNjAAAAAAAAAAtEaXNw\n\
	bGF5IFAzAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\
	AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHRleHQAAAAAQ29weXJp\n\
	Z2h0IEFwcGxlIEluYy4sIDIwMTcAAFhZWiAAAAAAAADzUQABAAAAARbMWFlaIAAAAAAA\n\
	AIPfAAA9v////7tYWVogAAAAAAAASr8AALE3AAAKuVhZWiAAAAAAAAAoOAAAEQsAAMi5\n\
	cGFyYQAAAAAAAwAAAAJmZgAA8qcAAA1ZAAAT0AAACltzZjMyAAAAAAABDEIAAAXe///z\n\
	JgAAB5MAAP2Q///7ov///aMAAAPcAADAbtIfICEiWiRjbGFzc25hbWVYJGNsYXNzZXNc\n\
	TlNDb2xvclNwYWNloiMkXE5TQ29sb3JTcGFjZVhOU09iamVjdNIfICYnV05TQ29sb3Ki\n\
	JiQACAARABoAJAApADIANwBJAEwAUQBTAFoAYABrAHgAfgCLAKAApwDTAP4BAAECAQQB\n\
	CwERARsBHQEfASEDSQNOA1kDYgNvA3IDfwOIA40DlQAAAAAAAAIBAAAAAAAAACgAAAAA\n\
	AAAAAAAAAAAAAAOY\n\
	</data>\n\
	<key>CommandString</key>\n\
	<string>cd " << dir << " ; ./Terminal_Execution/PlayGAME ; exit;</string>\n\
	<key>CursorColor</key>\n\
	<data>\n\
	YnBsaXN0MDDUAQIDBAUGBwpYJHZlcnNpb25ZJGFyY2hpdmVyVCR0b3BYJG9iamVjdHMS\n\
	AAGGoF8QD05TS2V5ZWRBcmNoaXZlctEICVRyb290gAGjCwwTVSRudWxs0w0ODxARElVO\n\
	U1JHQlxOU0NvbG9yU3BhY2VWJGNsYXNzTxAnMC41Nzc4MzQ1MzgzIDAuNzQ1ODM0Mjk0\n\
	OCAwLjc0NTkzMzg0MDMAEAGAAtIUFRYXWiRjbGFzc25hbWVYJGNsYXNzZXNXTlNDb2xv\n\
	cqIWGFhOU09iamVjdAgRGiQpMjdJTFFTV11kand+qKqssbzFzdAAAAAAAAABAQAAAAAA\n\
	AAAZAAAAAAAAAAAAAAAAAAAA2Q==\n\
	</data>\n\
	<key>CursorType</key>\n\
	<integer>2</integer>\n\
	<key>Font</key>\n\
	<data>\n\
	YnBsaXN0MDDUAQIDBAUGBwpYJHZlcnNpb25ZJGFyY2hpdmVyVCR0b3BYJG9iamVjdHMS\n\
	AAGGoF8QD05TS2V5ZWRBcmNoaXZlctEICVRyb290gAGkCwwVFlUkbnVsbNQNDg8QERIT\n\
	FFZOU1NpemVYTlNmRmxhZ3NWTlNOYW1lViRjbGFzcyNALAAAAAAAABAQgAKAA15TRk1v\n\
	bm8tUmVndWxhctIXGBkaWiRjbGFzc25hbWVYJGNsYXNzZXNWTlNGb250ohkbWE5TT2Jq\n\
	ZWN0CBEaJCkyN0lMUVNYXmdud36FjpCSlKOos7zDxgAAAAAAAAEBAAAAAAAAABwAAAAA\n\
	AAAAAAAAAAAAAADP\n\
	</data>\n\
	<key>ProfileCurrentVersion</key>\n\
	<real>2.0699999999999998</real>\n\
	<key>RunCommandAsShell</key>\n\
	<false/>\n\
	<key>ShowRepresentedURLPathInTitle</key>\n\
	<false/>\n\
	<key>TextBoldColor</key>\n\
	<data>\n\
	YnBsaXN0MDDUAQIDBAUGBwpYJHZlcnNpb25ZJGFyY2hpdmVyVCR0b3BYJG9iamVjdHMS\n\
	AAGGoF8QD05TS2V5ZWRBcmNoaXZlctEICVRyb290gAGjCwwTVSRudWxs0w0ODxARElVO\n\
	U1JHQlxOU0NvbG9yU3BhY2VWJGNsYXNzTxAeMC41IDAuOTE2MjA0NTAwMSAwLjk1Mjkz\n\
	NTY2MTkAEAGAAtIUFRYXWiRjbGFzc25hbWVYJGNsYXNzZXNXTlNDb2xvcqIWGFhOU09i\n\
	amVjdAgRGiQpMjdJTFFTV11kand+n6GjqLO8xMcAAAAAAAABAQAAAAAAAAAZAAAAAAAA\n\
	AAAAAAAAAAAA0A==\n\
	</data>\n\
	<key>TextColor</key>\n\
	<data>\n\
	YnBsaXN0MDDUAQIDBAUGBwpYJHZlcnNpb25ZJGFyY2hpdmVyVCR0b3BYJG9iamVjdHMS\n\
	AAGGoF8QD05TS2V5ZWRBcmNoaXZlctEICVRyb290gAGjCwwTVSRudWxs0w0ODxARElVO\n\
	U1JHQlxOU0NvbG9yU3BhY2VWJGNsYXNzTxAeMC41IDAuOTE5MTIwMzAzNSAwLjk1MzUz\n\
	MTQzMDYAEAGAAtIUFRYXWiRjbGFzc25hbWVYJGNsYXNzZXNXTlNDb2xvcqIWGFhOU09i\n\
	amVjdAgRGiQpMjdJTFFTV11kand+n6GjqLO8xMcAAAAAAAABAQAAAAAAAAAZAAAAAAAA\n\
	AAAAAAAAAAAA0A==\n\
	</data>\n\
	<key>columnCount</key>\n\
	<integer>" << width << "</integer>\n\
	<key>name</key>\n\
	<string>Tic Tac Toe</string>\n\
	<key>rowCount</key>\n\
	<integer>36</integer>\n\
	<key>shellExitAction</key>\n\
	<integer>1</integer>\n\
	<key>type</key>\n\
	<string>Window Settings</string>\n\
</dict>\n\
</plist>\n\
";
    outfile.close();
    return 0;
}