import csv
from collections import defaultdict

# Prints each column header with the top 5 values in that column by length
def max_column_lengths(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file, delimiter='\t')
        headers = next(reader)

        column_lengths = defaultdict(list)

        for row in reader:
            for i, value in enumerate(row):
                column_lengths[i].append(len(value))

        for i, header in enumerate(headers):
            top_5_lengths = sorted(column_lengths[i], reverse=True)[:5]
            top_5_lengths_str = ', '.join(str(x) for x in top_5_lengths)
            print(f"{header}: {top_5_lengths_str}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python top_5_column_lengths.py input_file")
        sys.exit(1)
    input_file = sys.argv[1]
    max_column_lengths(input_file)

