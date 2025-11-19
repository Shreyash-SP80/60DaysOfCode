import os
import subprocess
import sys

def compile_and_run(filename):
    if not filename.endswith(".cpp"):
        print("Error: Please provide a .cpp file")
        return
    
    # Output executable name
    output = "program.exe" if os.name == "nt" else "program.out"

    print(f"Compiling {filename} ...")

    # Compile using g++
    compile_cmd = ["g++", filename, "-o", output]
    compile_process = subprocess.run(compile_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # If any compilation errors
    if compile_process.returncode != 0:
        print("❌ Compilation Failed:")
        print(compile_process.stderr)
        return

    print("✅ Compilation Successful!")
    print("Running program...\n")

    # Running
    run_cmd = [f"./{output}"] if os.name != "nt" else [output]
    run_process = subprocess.run(run_cmd, text=True)

def main():
    if len(sys.argv) < 2:
        print("Usage: python run_cpp.py filename.cpp")
        return
    compile_and_run(sys.argv[1])

if __name__ == "__main__":
    main()
