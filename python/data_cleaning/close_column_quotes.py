# This script checks each column of a tsv, and if there is only one quote (") add another to the end of the column

import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

with open(input_file, "r", newline='', encoding='utf-8') as infile, open(output_file, "w", newline='', encoding='utf-8') as outfile:
    for line in infile:
        row = line.rstrip().split('\t')
        corrected_row = []
        for column in row:
            if column.count('"') == 1 and column[-1] != '"':
                column += '"'
            corrected_row.append(column)
        outfile.write('\t'.join(corrected_row) + '\n')

