from functions import *

#отримуємо від користувача сьогоднішню дату (у форматі dd.mm.yy)
todays_date = read_todays_date()

# читаємо текст з консолі, поки не буде натиснуто клавішу Ctrl + D
text_to_write = capture_text()
# записуємо цей текст у файл input.txt
write_empty_file("input.txt", text_to_write)

# читаємо текст з файлу input.txt у змінну text
text = read_file("input.txt")
print(f"Text on input:\n{text}\n")

lines = split_lines(text)
print("Lines list:")
print(*lines, sep='\n')

information = split_information(lines)
print("\nInformation list:")
print(*lines, sep='\n')

check_warranty(information, todays_date)

output_text = read_file("output.txt")
print("\n")
print(output_text)