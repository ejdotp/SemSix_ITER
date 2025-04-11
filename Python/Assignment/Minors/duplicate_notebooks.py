import json
import copy
import os

def add_print_statement(notebook_path, output_path):
    # Read the original notebook
    with open(notebook_path, 'r', encoding='utf-8') as f:
        nb = json.load(f)
    
    # Create a deep copy
    new_nb = copy.deepcopy(nb)
    
    # Modify each code cell
    for cell in new_nb['cells']:
        if cell['cell_type'] == 'code':
            # Add print statement at the end of the cell's source
            if isinstance(cell['source'], list):
                cell['source'].append('\nprint("Arman Das Pattanaik")\n')
            else:
                cell['source'] = cell['source'] + '\nprint("Arman Das Pattanaik")\n'
    
    # Write the modified notebook
    with open(output_path, 'w', encoding='utf-8') as f:
        json.dump(new_nb, f, indent=1)

# Get the directory of the current script
current_dir = os.path.dirname(os.path.abspath(__file__))

# Create duplicates with modifications
notebooks = [
    ('Minor_Ass_1.ipynb', 'Minor_Ass_1_Arman.ipynb'),
    ('Minor_Ass_2.ipynb', 'Minor_Ass_2_Arman.ipynb'),
    ('Minor_Ass_3.ipynb', 'Minor_Ass_3_Arman.ipynb')
]

for original, duplicate in notebooks:
    try:
        original_path = os.path.join(current_dir, original)
        duplicate_path = os.path.join(current_dir, duplicate)
        add_print_statement(original_path, duplicate_path)
        print(f"Successfully created {duplicate}")
    except Exception as e:
        print(f"Error processing {original}: {str(e)}") 