#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

string capture_text();
void write_empty_file(const string& file_name, const string& text);
string read_input_file(const string& file_name);
void print_vector(const vector<string>& vec);
vector<string> split_lines(const string& text);
vector<vector<string>> split_information(const vector<string>& lines);
void write_file(const string& file_name, const string& string_to_write);
int get_unix_timestamp(const string& day,const string& month,const string& year);
void check_warranty(vector<vector<string>> information, const string& todays_date);
void read_output_file(const string& file_name);
string read_today_date();

