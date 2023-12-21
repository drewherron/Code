#This works
with open('title.basics.tsv', 'r') as infile, open('title.basics.out.tsv', 'w') as outfile:
    for line in infile:
        parts = line.split('\t')  # assuming tab-separated values
        if parts[-1].strip() != "\\N":
            genres = parts[-1].strip().split(',')
            parts[-1] = '{' + ','.join(genres) + '}\n'
        else:
            parts[-1] = '{NULL}\n'  # or just '{}' based on your requirements
        outfile.write('\t'.join(parts))

