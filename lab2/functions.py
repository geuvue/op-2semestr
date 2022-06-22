import sys
import datetime
import time


def read_todays_date():
    date = input("Enter today's date (in format dd.mm.yy): ")

    return date


def capture_text():
    print('Enter your text\nPress Enter to go to the next line\nPress Ctrl + D - to end writing')

    text = sys.stdin.read()

    text = text[:len(text) - 1]

    print(f"Whole text:\n{text}\n")

    return text


def read_file(file_name: str):
    read_input_file = open(file_name, 'rt')
    text = read_input_file.read()
    read_input_file.close()

    return text


def split_lines(text: str):
    lines = text.split('\n')

    for i in range(len(lines)):
        if lines[i] == '':
            lines.pop(i)

    return lines


def split_information(lines: list[str]):
    general_information = []

    for i in range(len(lines)):
        information_array = lines[i].split(',')
        general_information.append(information_array)

    return general_information


def write_to_file(file_name: str, string_to_write: str):
    write_file = open(file_name, 'at')
    write_file.write(string_to_write)
    write_file.close()


def check_warranty(information: list[list[str]], todays_date: str):
    for i in range(len(information)):
        buy_date = information[i][1]
        buy_date_datetime = datetime.datetime.strptime(buy_date, '%d.%m.%y')
        buy_date_unix = time.mktime(buy_date_datetime.timetuple())
        warranty_term = int(information[i][2])
        warranty_expire_date = buy_date_unix + warranty_term * 86400
        todays_datetime = datetime.datetime.strptime(todays_date, '%d.%m.%y')
        todays_date_unix = time.mktime(todays_datetime.timetuple())
        if todays_date_unix > warranty_expire_date:
            print(f"Warranty have been expired for product {information[i][0]}")

            string_to_write = f"Warranty have been expired for product: {information[i][0]},{information[i][1]},{information[i][2]}\n"
            write_to_file("output.txt", string_to_write)


def write_empty_file(file_name: str, text: str):
    write_file = open(file_name, 'wt')
    write_file.write(text)
    write_file.close()