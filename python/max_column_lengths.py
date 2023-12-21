import csv

#Prints each column name with the length of its last value
def max_column_lengths(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file, delimiter='\t')
        headers = next(reader)
        max_lengths = [0] * len(headers)

        for row in reader:
            for i, value in enumerate(row):
                max_lengths[i] = max(max_lengths[i], len(value))

        for header, max_length in zip(headers, max_lengths):
            print(f"{header}: {max_length}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python max_column_lengths.py input_file")
        sys.exit(1)
    input_file = sys.argv[1]
    max_column_lengths(input_file)

