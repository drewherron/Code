import csv
import sys

# This is to make sure that our file has the correct number of columns
# I.e., we're not missing a tab somewhere

if len(sys.argv) != 3:
    print("Usage: python verify_column_count.py input_file expected_columns")
    sys.exit(1)

input_file = sys.argv[1]
expected_columns = int(sys.argv[2])

with open(input_file, 'r') as f:
    reader = csv.reader(f, delimiter='\t')
    for i, row in enumerate(reader, start=1):
        if len(row) != expected_columns:
            print(f'Line {i}: {row}')

