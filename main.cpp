#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include <time.h>

using namespace std;

string current_directory = ".";

void display_files()
{
    DIR* directory;
    directory = opendir(current_directory.c_str());

    if (directory == NULL) {
        cout << "ERROR: Could not open directory!" << endl;
        return;
    }

    cout << "\n--- Files in " << current_directory << " ---\n";
    cout << "Name\t\t\tType\t\tSize\n";
    cout << "------------------------------------------------\n";

    struct dirent* file_entry;
    file_entry = readdir(directory);

    while (file_entry != NULL) {
        string file_name = file_entry->d_name;

        if (file_name[0] != '.') {
            string complete_path = current_directory + "/" + file_name;
            struct stat file_info;
            stat(complete_path.c_str(), &file_info);

            cout << file_name << "\t\t";

            if (file_entry->d_type == DT_DIR) {
                cout << "[FOLDER]\t";
            } else {
                cout << "[FILE]\t\t";
            }

            cout << file_info.st_size << " bytes\n";
        }

        file_entry = readdir(directory);
    }

    closedir(directory);
    cout << "\n";
}

void open_folder()
{
    string folder_name;
    cout << "Enter folder name: ";
    getline(cin, folder_name);

    string new_path = current_directory + "/" + folder_name;

    DIR* test_dir;
    test_dir = opendir(new_path.c_str());

    if (test_dir == NULL) {
        cout << "ERROR: Folder does not exist!\n";
        return;
    }

    closedir(test_dir);
    current_directory = new_path;
    cout << "Moved to: " << current_directory << "\n";
}

void go_back_folder()
{
    int last_slash = -1;
    for (int i = 0; i < current_directory.length(); i++) {
        if (current_directory[i] == '/') {
            last_slash = i;
        }
    }

    if (last_slash > 0) {
        current_directory = current_directory.substr(0, last_slash);
    } else {
        current_directory = ".";
    }

    cout << "Moved back to: " << current_directory << "\n";
}

void make_new_file()
{
    string file_name;
    cout << "Enter new file name: ";
    getline(cin, file_name);

    string full_path = current_directory + "/" + file_name;

    ofstream new_file;
    new_file.open(full_path.c_str());

    if (!new_file.is_open()) {
        cout << "ERROR: Cannot create file!\n";
        return;
    }

    cout << "File created successfully!\n";
    cout << "Enter file content (type 'END' on a new line to finish):\n";

    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        new_file << line << "\n";
    }

    new_file.close();
    cout << "File saved successfully!\n";
}

void remove_file()
{
    string file_name;
    cout << "Enter file name to delete: ";
    getline(cin, file_name);

    string full_path = current_directory + "/" + file_name;

    int result = remove(full_path.c_str());

    if (result == 0) {
        cout << "File deleted successfully!\n";
    } else {
        cout << "ERROR: Could not delete file!\n";
    }
}

void copy_a_file()
{
    string source_name, destination_name;

    cout << "Enter source file name: ";
    getline(cin, source_name);

    cout << "Enter destination file name: ";
    getline(cin, destination_name);

    string source_path = current_directory + "/" + source_name;
    string dest_path = current_directory + "/" + destination_name;

    ifstream source_file;
    source_file.open(source_path.c_str(), ios::binary);

    if (!source_file.is_open()) {
        cout << "ERROR: Source file not found!\n";
        return;
    }

    ofstream dest_file;
    dest_file.open(dest_path.c_str(), ios::binary);

    if (!dest_file.is_open()) {
        cout << "ERROR: Cannot create destination file!\n";
        source_file.close();
        return;
    }

    char ch;
    while (source_file.get(ch)) {
        dest_file.put(ch);
    }

    source_file.close();
    dest_file.close();

    cout << "File copied successfully!\n";
}

void search_file()
{
    string search_word;
    cout << "Enter search term: ";
    getline(cin, search_word);

    cout << "\nSearching for files containing: " << search_word << "\n";
    cout << "--------------------------------------\n";

    DIR* dir = opendir(current_directory.c_str());
    if (dir == NULL) {
        cout << "ERROR: Cannot search!\n";
        return;
    }

    struct dirent* entry;
    int found_count = 0;

    entry = readdir(dir);
    while (entry != NULL) {
        string name = entry->d_name;

        if (name[0] != '.') {
            if (name.find(search_word) != string::npos) {
                cout << "Found: " << name;
                if (entry->d_type == DT_DIR) {
                    cout << " [FOLDER]";
                }
                cout << "\n";
                found_count++;
            }
        }

        entry = readdir(dir);
    }

    closedir(dir);

    if (found_count == 0) {
        cout << "No files found!\n";
    } else {
        cout << "\nTotal found: " << found_count << " file(s)\n";
    }
}

void show_file_details()
{
    string file_name;
    cout << "Enter file name: ";
    getline(cin, file_name);

    string full_path = current_directory + "/" + file_name;

    struct stat file_stats;
    int result = stat(full_path.c_str(), &file_stats);

    if (result != 0) {
        cout << "ERROR: File not found!\n";
        return;
    }

    cout << "\n--- File Information ---\n";
    cout << "File Name: " << file_name << "\n";
    cout << "File Size: " << file_stats.st_size << " bytes\n";

    cout << "Permissions: ";
    if (file_stats.st_mode & S_IRUSR) cout << "r"; else cout << "-";
    if (file_stats.st_mode & S_IWUSR) cout << "w"; else cout << "-";
    if (file_stats.st_mode & S_IXUSR) cout << "x"; else cout << "-";
    cout << "\n";

    cout << "Last Modified: " << ctime(&file_stats.st_mtime);
    cout << "\n";
}

void show_main_menu()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "       FILE EXPLORER PROGRAM\n";
    cout << "========================================\n";
    cout << "Current Location: " << current_directory << "\n";
    cout << "========================================\n";
    cout << "1. Show all files\n";
    cout << "2. Open a folder\n";
    cout << "3. Go back to previous folder\n";
    cout << "4. Create new file\n";
    cout << "5. Delete a file\n";
    cout << "6. Copy a file\n";
    cout << "7. Search for files\n";
    cout << "8. Show file details\n";
    cout << "9. Exit program\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}
int main()
{
    cout << "\n*** Welcome to File Explorer! ***\n";
    cout << "This program helps you manage files on your computer.\n";

    int user_choice;

    while (true) {
        show_main_menu();
        cin >> user_choice;
        
        if (cin.fail()) {
            cin.clear();                
            cin.ignore(10000, '\n');   
            cout << "ERROR: Please enter a valid number (1-9)!\n";
            continue;                  
        }
        
        cin.ignore(); 
        if (user_choice == 1) {
            display_files();
        }
        else if (user_choice == 2) {
            open_folder();
        }
        else if (user_choice == 3) {
            go_back_folder();
        }
        else if (user_choice == 4) {
            make_new_file();
        }
        else if (user_choice == 5) {
            remove_file();
        }
        else if (user_choice == 6) {
            copy_a_file();
        }
        else if (user_choice == 7) {
            search_file();
        }
        else if (user_choice == 8) {
            show_file_details();
        }
        else if (user_choice == 9) {
            cout << "\nThank you for using File Explorer!\n";
            cout << "Goodbye!\n\n";
            break;
        }
        else {
            cout << "ERROR: Invalid choice! Please enter 1-9.\n";
        }
    }

    return 0;
}