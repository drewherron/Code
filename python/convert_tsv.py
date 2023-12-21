import csv
import sys

#Converts column given as arguments to a Postgres-array-compatible format
def convert_to_pg_array(column_value):
    elements = column_value.split(',')
    pg_array = "{" + ','.join(f'{x}' for x in elements) + "}"
    return pg_array

def convert_tsv_to_pg_array_format(input_file, output_file, num_columns, array_column_indices):
    with open(input_file, 'r', newline='') as infile, open(output_file, 'w', newline='') as outfile:
        tsv_reader = csv.reader(infile, delimiter='\t')
        tsv_writer = csv.writer(outfile, delimiter='\t', quoting=csv.QUOTE_MINIMAL, escapechar='\\')

        # Write the header (unchanged)
        header = next(tsv_reader)
        tsv_writer.writerow(header)

        for row in tsv_reader:
            converted_row = []
            for i in range(num_columns):
                if i in array_column_indices:
                    converted_row.append(convert_to_pg_array(row[i]))
                else:
                    converted_row.append(row[i])

            # Write the converted row to the output file
            tsv_writer.writerow(converted_row)

if __name__ == '__main__':
    if len(sys.argv) != 5:
        print("Usage: python convert_tsv.py input_file output_file num_columns array_column_indices")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    num_columns = int(sys.argv[3])
    array_column_indices = [int(x) for x in sys.argv[4].split(',')]

    convert_tsv_to_pg_array_format(input_file, output_file, num_columns, array_column_indices)

