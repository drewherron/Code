import csv
import sys

def replace_inner_quotes(row):
    for i, col in enumerate(row):
        if col.count('"') > 2:
            col_parts = col.split('"')
            new_col = col_parts[0] + '"' + col_parts[1].replace('"', "'") + '"' + col_parts[2]
            row[i] = new_col
    return row

def process_file(input_file, output_file):
    with open(input_file, 'r', newline='', encoding='utf-8') as infile, \
         open(output_file, 'w', newline='', encoding='utf-8') as outfile:
        reader = csv.reader(infile, delimiter='\t', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        writer = csv.writer(outfile, delimiter='\t', quotechar='"', quoting=csv.QUOTE_MINIMAL)

        for row in reader:
            new_row = replace_inner_quotes(row)
            writer.writerow(new_row)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python replace_nested_quotes.py input_file output_file")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    process_file(input_file, output_file)

