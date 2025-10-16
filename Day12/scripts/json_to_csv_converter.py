import json
import csv

def json_to_csv(json_file, csv_file):
    with open(json_file, 'r') as jf:
        data = json.load(jf)

    with open(csv_file, 'w', newline='') as cf:
        writer = csv.DictWriter(cf, fieldnames=data[0].keys())
        writer.writeheader()
        writer.writerows(data)

    print(f"✅ Successfully converted {json_file} to {csv_file}")

if __name__ == "__main__":
    json_path = input("Enter JSON file path: ")
    csv_path = input("Enter output CSV file path: ")
    json_to_csv(json_path, csv_path)

# Output =>
# Enter JSON file path: data.json
# Enter output CSV file path: data.csv
# ✅ Successfully converted data.json to data.csv
