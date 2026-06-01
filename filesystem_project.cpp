#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

// ------------------- BASE CLASS ----------------

class FileSystemItem {
	protected:
		std::string path;
	
	public:
		
		FileSystemItem (std::string p) {
			path = p;
		}
		
		virtual void showInfo() = 0;
};

// ---------------- FILE CLASS --------------------

class FileItem : public FileSystemItem {
	public:
		
		
		FileItem (std::string p) : FileSystemItem(p) {};  // Constructor
		
		void showInfo() override {   // Virtual Function
			
			std::cout << "\n----- File Info -----\n";
			
			std::cout   << "Path: "
						<< path
						<< std::endl;
						
			if (fs::exists(path)) {
				
				std::cout << "File Exists\n";
				
				std::cout << "Size: " 
						  << fs::file_size(path)
						  << " bytes\n";
			}
			else {
				std::cout << "File does not exists\n";
			}
		}
		
		void createFile() {           // To create File. 
			std::ofstream file(path);
			
			file.close();
			
			std::cout << "File created successfully.\n";
		}
		
		void renameFile (std::string newName) {    // To rename the file. 
		
			if (!fs::exists(path)) {       // to check the existence of file. 
				
				std::cout << "File does not exists.\n";
				
				return;
			}
				
			fs::rename( path, newName);
			
			std::cout << "File renamed successfully.\n";
			
			path = newName;
			
		}
		
		void copyFile (std::string newName) {       // To copy the file into another file.
			
			if (!fs::exists(path)) {             // To check existence of file
				
				std::cout << "File does not exists.\n";
				
				return;
			}
			
			
			fs::copy(path, newName); // This filesystem command copies an existing file into a new file
			
			std::cout << "File copied successfully.\n";
	
		}

		void readFile() {
			
			if (!fs::exists(path)) {
				
				std::cout << "File does not exists.\n";
				
				return;
			}
			
			
			
			std::fstream file(path);                // Opens the file whose name is store in the path variable
			std::string line;                       // Variable to store the read data of the file 
			
			std::cout << "\n----- FILE CONTENT -----\n";
			
			while (getline(file, line)) {
				
				std::cout 
				<< line 
				<< std::endl;
				
			}
			
			file.close();
			
		}

		void writeFile() {                       // Writes to file after checking file opening and than writing what the user has given the input
			
			std::ofstream file(path, std::ios::app);
			if (!file.open()) {                  // File opening verification
				
				std::cout << "Could not open file.\n";  
				return;
			}
			
			std::string text;
			std::cin.ignore();
			std::cout << "Enter text: ";
			std::getline(cin, text);
			
			file << text << std::endl;
			file.close();
			std::cout << "Text written successfully.\n";
			
		}
		
		void deleteFile() {                       // Deletes the file or in other words, the path entered.
			
			if (!fs::exists(path)) {
				
				std::cout << "File does not exist.\n";
				return;
			}
			
			fs::remove(path);
			std::cout << "File deleted.\n";
		}

		void showExtension() {                    // Shows the file's extension
			
			std::cout 
			<< "Extension:  " << fs::path(path).extension() << std::endl;
		}

		void countFiles() {                       // Beaviour to count fils.
			
			int count = 0;
			
			for (const auto& item : fs::directory_iterator(path)) {  // loop for counting
				
				if (fs::is_regular_file(item)) {                     // if-condition to count files only
					
					count++;
				}
			}
			
			std::cout 
			<<  "Total files: " << count << std::endl;
		}

};

// --------------------- DIRECTORY CLASS ---------------------

class DirectoryItem : public FileSystemItem {
	
	public:
		
		DirectoryItem(std::string p) : FileSystemItem(p) {}  // Constructor
		
		
		void showInfo() override {
			
			std::cout << "\n---- DIRECTORY INFO -----\n";
			
			std::cout << "Path: "
					  << path
					  << std::endl;
					  
			if (fs::exists(path)) {
				
				std::cout << "Directory Exists\n";
			}
			else {
				std::cout << "Directory does not exists";			
			}
		}
		
		
		void createDirectory() {              // Function to create directory
			
			if (fs::create_directory(path)) {
				
				std::cout << "Directory created successfully.\n";
			}
			else {
				std::cout 
				<< "Directory alrady exists.\n";
			}
		}
		
		void showContents() {   // To show the contents inside the directory
			
			std::cout 
			<< "\n----- DIRECTORY CONTENTS -----\n";
			
			if (!fs::exists(path)) {
				std::cout 
				<< "Directory does not exists.\n";
				
				return ;
			}
			
			for (const auto& item : fs::directory_iterator(path)) {
				std::cout 
				<< item.path().filename()
				<< std::endl;
			}
		}
		
		void renameDirectory(std::string newName) {     // Renames the Directory. 
			
			fs::rename(path, newName);
			
			std::cout << "Directory renamed successfully.\n";
			
			path = newName; 
		}
		
};


// -------------------- FILE MANAGER -----------------------

class FileManager {
	private:
		
		std::vector <std::string> history;
		
	public:
		
		void addHistory (std::string action) {   // To push back action variable in the history vector.
			
			history.push_back(action);
		
		}
		
		void showHistory() {
			
			std::cout 
			<< "\n----- ACTION HISTORY -----\n";
			
			for (const std::string& action : history) {
				std::cout 
				<< action
				<< std::endl;
			}
		}
		
		
		
};

// ----------------------- MAIN ----------------------------

int main() {
	
	FileManager manager;
	
	int choice;
	
	do {
		std::cout 
		<< "\n---------- FILE SYSTEM APP ----------\n"
		<< "1. Create File\n"
		<< "2. Create Directory\n"
		<< "3. Show File Info\n"
		<< "4. Show Directory Info\n"
		<< "5. Show Directory Contents\n"
		<< "6. Rename File\n"
		<< "7. Rename Directory\n"
		<< "8. Copy File\n"
		<< "9. Read File\n"
		<< "10. Show History\n"
		<< "11. Exit\n"
		<< "\nEnter Choice: ";
		
		
		std::cin >> choice;
		
		
		switch (choice) {
			
			case 1: {
				std::string filename;
				std::cout << "Enter File Name: ";
				std::cin >> filename;
				
				FileItem file(filename);
				file.createFile();
				
				manager.addHistory( "Created file: " + filename);
				
				break;
			}
			
			case 2: {
				std::string folder;
				std::cout << "Enter directory name: ";
				std::cin >> folder;
				
				DirectoryItem dir(folder);
				
				dir.createDirectory();
				
				manager.addHistory( "Created directory: " + folder);
				
				break;
			}
			
			case 3: {
				std::string filename;
				std::cout << "Enter file name: ";
				std::cin >> filename;
				
				FileItem file(filename);
				
				file.showInfo();
				
				break;
			}
			
			case 4: {
				std::string folder;
				
				std::cout << "Enter directory name: ";
				
				std::cin >> folder;
				
				DirectoryItem dir(folder);
				
				dir.showInfo();
				
				
				break;
			}
			
			case 5: {
				std::string folder;
				
				std::cout << "Enter directory name: ";
				
				std::cin >> folder;
				
				DirectoryItem dir(folder);
				
				dir.showContents();
				
				
				break;
			}
			
			case 6: {
				
				std::string oldFile;
				std::string newFile;
				
				std::cout << "Enter current file name: ";
				std::cin >> oldFile;
				
				std::cout << "Enter new file name: ";
				std::cin >> newFile;
				
				FileItem file (oldFile);
				
				file.renameFile(newFile);
			
				manager.addHistory(
					"Renamed File: " + oldFile + " to " + newFile
				);
				
				
				break;
			}
			
			case 7: {
				
				std::string oldFolder;
				std::string newFolder;
				
				std::cout << "Enter current directory name: ";
				std::cin >> oldFolder;
				
				std::cout << "Enter new directory name: ";
				std::cin >> newFolder;
				
				DirectoryItem dir(oldFolder);
				dir.renameDirectory(newFolder);
				
				manager.addHistory(
				"Renamed directory: " + oldFolder + " to " + newFolder
				);
				
				
				break;
			}
			
			case 8: {
				
				std::string sourceFile;
				std::string destinationFile;
				
				std::cout << "Enter source file name: ";
				std::cin >> sourceFile;
				
				std::cout << "Enter desination file name: ";
				std::cin >> destinationFile;
				
				FileItem file(sourceFile);          // Creates the file to be replaced
				file.copyFile(destinationFile);     // Replaces the file 
				
				
				manager.addHistory(                 // Ads the record in the vector
					"Copied File: " + sourceFile + " to " + destinationFile
				);
				
				
				
				break;
			}
			
			case 9: {
				
				  // To read file name from user.
				std::string filename;          
				std::cout << "Enter file name: ";
				std::cin >> filename; 
				
				
				
				 // Creates an object & reades it. 
				FileItem file(filename);
				file.readFile();
				
				
				
				//  Adds record in the vector
				manager.addHistory(
					"Read file: " + filename
				);
				
				break;
			}
			
			case 10: {
				manager.showHistory();
				
				break;
			}
			
			case 11: {
				std::cout << "Program Closed.\n";
				
				break;
			}
			
			default: 
			
				std::cout << "Invalid Choice.\n";
		}
	} while (choice != 11);
	
	return 0;
}