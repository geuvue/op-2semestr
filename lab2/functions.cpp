#include "functions.h"

string read_today_date(){
    string todays_date;
    cout << "Enter today's date (in format dd.mm.yy): ";
    getline(cin, todays_date);

    return todays_date;
}

string capture_text(){
    cout << "Enter your product info by the following format: Name,DD.MM.YY,Days\nPress Enter to go to the next line\nPress '<' - to end writing\n";

    string text;
    string line = "";
    while(line != "<"){
        getline(cin, line);
        text += line + '\n';
    }
    text = text.substr(0, text.size()-2);

    return text;
}

void write_empty_file(const string& file_name, const string& text){
    ofstream write_file(file_name, ios::binary);
    write_file << text;
    write_file.close();
}

string read_input_file(const string& file_name){
    ifstream read_file(file_name, ios::binary);
    string text;

    while (!read_file.eof()){
        text += read_file.get();
    }
    read_file.close();

    text = text.substr(0, text.size()-1);

    return text;
}

void print_vector(const vector<string>& vec){
    cout << "Lines vector:\n";

    for(auto & i : vec){
        cout << i << "\n";
    }
    cout << "\n";
}

vector<string> split_lines(const string& text){
    vector<string> lines;
    int previous_position = 0;
    int counter = 0;

    while(counter <= text.size()){
        if(text[counter] == '\n' || counter == text.size()){
            string line = text.substr(previous_position, counter-previous_position);
            lines.push_back(line);
            previous_position = counter+1;
        }
        counter++;
    }

    return lines;
}

vector<vector<string>> split_information(const vector<string>& lines){
    vector<vector<string>> general_information;

    for(int i=0;i<lines.size();i++){
        int previous_position = 0;
        int counter = 0;
        vector<string> information_vector;

        while(counter <= lines[i].size()){
            if(lines[i][counter] == ',' || counter == lines[i].size()){
                string info = lines[i].substr(previous_position, counter-previous_position);
                information_vector.push_back(info);
                previous_position = counter+1;
            }
            counter++;
        }

        general_information.push_back(information_vector);
    }

    return general_information;
}

void write_file(const string& file_name, const string& string_to_write){
    ofstream write_file(file_name, ios::app | ios::binary);
    write_file << string_to_write;

    write_file.close();
}

int get_unix_timestamp(const string& day,const string& month,const string& year){
    tm time{};

    stringstream ss("20" + year + "-" + month + "-" + day + "T00:00:00.000Z");

    ss >> get_time(&time, "%Y-%m-%dT%H:%M:%S");
    time_t time_stamp = mktime(&time);

    return static_cast<int>(time_stamp);
}

void check_warranty(vector<vector<string>> information, const string& todays_date){
    for(int i=0; i < information.size(); i++){
        string buy_date = information[i][1];
        string buy_date_day = buy_date.substr(0, 2);
        string buy_date_month = buy_date.substr(3, 2);
        string buy_date_year = buy_date.substr(6, 2);
        int buy_date_unix = get_unix_timestamp(buy_date_day, buy_date_month, buy_date_year);

        int warranty_term = stoi(information[i][2]);
        int warranty_expire_date = buy_date_unix + warranty_term * 86400;

        string todays_date_day = todays_date.substr(0, 2);
        string todays_date_month = todays_date.substr(3, 2);
        string todays_date_year = todays_date.substr(6, 2);
        int todays_date_unix = get_unix_timestamp(todays_date_day, todays_date_month, todays_date_year);

        if(todays_date_unix > warranty_expire_date){
            printf("Warranty have been expired for product: %s\n", information[i][0].c_str());
            string string_to_write = "Warranty have been expired for product: " + information[i][0] + "," + information[i][1] + "," + information[i][2] + "\n";

            write_file("output.txt", string_to_write);
        }

    }
}

void read_output_file(const string& file_name){
    ifstream read_output_file(file_name, ios::binary);
    cout << "\nOutput file:\n" << read_output_file.rdbuf() << "\n";
    read_output_file.close();
}
