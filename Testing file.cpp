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
		
		void createFile() {
			std::ofstream file(path);
			
			file.close();
			
			std::cout << "File created successfully.\n";
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
		
		void showContents() {
			
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
		<< "6. Show History\n"
		<< "7. Exit\n"
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
				manager.showHistory();
				
				break;
			}
			
			case 7: {
				std::cout << "Program Closed.\n";
				
				break;
			}
			
			default: 
			
				std::cout << "Invalid Choice.\n";
		}
	} while (choice != 7);
	
	return 0;
}