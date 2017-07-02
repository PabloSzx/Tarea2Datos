using namespace std;

#ifndef FILE_H
#define FILE_H

void file_open(const char* file);
void file_close();
void file_clear(const char* file);
void file_write_breakline();
void file_write_breakline(const char* str);
void file_write_breakline(double n);
void file_write_breakline(int n);
void file_write_single(const char* str);
void file_write_single(double n);
void file_write_single(int n);
void file_write_space();
void file_write_space(const char* str);
void file_write_space(double n);
void file_write_space(int n);

ofstream myfile;

void file_open(const char* file) {
  myfile.open((string("./info/") + string(file) + string(".txt")).c_str(), ofstream::app);
}

void file_close() {
  myfile.close();
}

void file_clear(const char* file) {
  myfile.open((string("./info/") + string(file) + string(".txt")).c_str());
  myfile.close();
}

void file_write_breakline() {
  myfile << "\n";
}

void file_write_breakline(const char* str) {
  myfile << str << "\n";
}

void file_write_breakline(double n) {
  myfile << n << "\n";
}

void file_write_breakline(int n) {
  myfile << n << "\n";
}

void file_write_single(const char* str) {
  myfile << str;
}

void file_write_single(double n) {
  myfile << n;
}

void file_write_single(int n) {
  myfile << n;
}

void file_write_space() {
  myfile << " ";
}

void file_write_space(const char* str) {
  myfile << str << " ";
}

void file_write_space(double n) {
  myfile << n << " ";
}

void file_write_space(int n) {
  myfile << n << " ";
}



#endif
