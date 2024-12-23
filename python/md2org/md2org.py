#!/usr/bin/env python3

import os
import sys
import pypandoc

def convert_md_to_org(root_dir, output_dir="output"):
    """
    Recursively convert all .md files in `root_dir` to .org in `output_dir`,
    preserving subdirectory structure.
    """
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for filename in filenames:
            # Only process Markdown files
            if filename.lower().endswith(".md"):
                # Full path of the .md file
                md_path = os.path.join(dirpath, filename)

                # Determine the relative path (subdirectories) from the root_dir
                rel_path = os.path.relpath(md_path, root_dir)

                # Replace .md with .org
                org_filename = os.path.splitext(rel_path)[0] + ".org"

                # Build the full output path
                org_path = os.path.join(output_dir, org_filename)

                # Ensure the output subdirectory exists
                os.makedirs(os.path.dirname(org_path), exist_ok=True)

                # Convert the .md file to Org format
                org_content = pypandoc.convert_file(md_path, to="org")

                # Write the converted content to the new .org file
                with open(org_path, "w", encoding="utf-8") as f:
                    f.write(org_content)

                print(f"Converted: {md_path} -> {org_path}")

def main():
    """
    Main entry point for the script.
    """
    # Parse command-line arguments
    if len(sys.argv) < 2:
        print("Usage: python convert_md_to_org.py <root_dir> [output_dir]")
        sys.exit(1)

    root_dir = sys.argv[1]
    output_dir = sys.argv[2] if len(sys.argv) > 2 else "output"

    # Run the conversion
    convert_md_to_org(root_dir, output_dir)

if __name__ == "__main__":
    main()
