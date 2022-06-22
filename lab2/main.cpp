#include "functions.h"

int main() {
    string todays_date = read_today_date();
    string text_to_write = capture_text();
    write_empty_file("input.txt", text_to_write);
    string text = read_input_file("input.txt");
    printf("\nText on input:\n%s\n\n", text.c_str());
    vector<string> lines = split_lines(text);
    print_vector(lines);

    vector<vector<string>> information = split_information(lines);

    check_warranty(information, todays_date);
    read_output_file("output.txt");
}