import os
import psutil
import shutil
import tempfile
import time
import platform

def clear_temp_files():
    print("🧹 Clearing temporary files...")
    temp_dir = tempfile.gettempdir()
    try:
        for file in os.listdir(temp_dir):
            file_path = os.path.join(temp_dir, file)
            try:
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    os.unlink(file_path)
                elif os.path.isdir(file_path):
                    shutil.rmtree(file_path)
            except Exception as e:
                pass
        print("✅ Temporary files cleared.")
    except Exception as e:
        print("⚠️ Error clearing temp files:", e)

def clear_prefetch():
    prefetch_path = r"C:\Windows\Prefetch"
    print("🧹 Clearing prefetch files...")
    if os.path.exists(prefetch_path):
        try:
            for file in os.listdir(prefetch_path):
                file_path = os.path.join(prefetch_path, file)
                os.remove(file_path)
            print("✅ Prefetch files cleared.")
        except Exception as e:
            print("⚠️ Unable to clear some files (Admin rights may be required).")
    else:
        print("⚠️ Prefetch directory not found.")

# def clear_prefetch():
#     prefetch_path = r"C:\Windows\Prefetch"
#     print("🧹 Clearing prefetch files...")
#     if os.path.exists(prefetch_path):
#         try:
#             for file in os.listdir(prefetch_path):
#                 file_path = os.path.join(prefetch_path, file)
#                 os.remove(file_path)
#             print("✅ Prefetch files cleared.")
#         except Exception as e:
#             print("⚠️ Unable to clear some files (Admin rights may be required).")
#     else:
#         print("⚠️ Prefetch directory not found.")

def clear_recycle_bin():
    print("🗑️ Emptying Recycle Bin...")
    try:
        os.system("PowerShell.exe Clear-RecycleBin -Force -ErrorAction SilentlyContinue")
        print("✅ Recycle Bin emptied.")
    except Exception as e:
        print("⚠️ Failed to empty Recycle Bin:", e)

def system_status():
    print("\n📊 Checking system performance...\n")
    cpu_usage = psutil.cpu_percent(interval=2)
    ram = psutil.virtual_memory()
    print(f"CPU Usage: {cpu_usage}%")
    print(f"RAM Usage: {ram.percent}% ({round(ram.used / (1024**3), 2)} GB used out of {round(ram.total / (1024**3), 2)} GB)")

    if cpu_usage > 80:
        print("⚠️ High CPU usage detected! Try closing unused background apps.")
    if ram.percent > 80:
        print("⚠️ High RAM usage detected! Consider restarting your system or adding more memory.")

def disk_cleanup():
    print("\n🧾 Performing disk cleanup suggestions...")
    partitions = psutil.disk_partitions()
    for partition in partitions:
        try:
            usage = psutil.disk_usage(partition.mountpoint)
            print(f"Drive {partition.device}: {usage.percent}% used")
            if usage.percent > 85:
                print(f"⚠️ Drive {partition.device} is nearly full. Consider freeing space.")
        except PermissionError:
            continue

def optimize_system():
    print("🚀 Starting system optimization...\n")
    clear_temp_files()
    clear_prefetch()
    clear_recycle_bin()
    system_status()
    disk_cleanup()
    print("\n✅ Optimization process completed successfully!")

if __name__ == "__main__":
    if platform.system() != "Windows":
        print("⚠️ This script is designed for Windows only.")
    else:
        start = time.time()
        optimize_system()
        print(f"\n⏱️ Total time taken: {round(time.time() - start, 2)} seconds")

