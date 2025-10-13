import platform
import os

def system_info():
    print("📊 System Information:")
    print(f"OS Name: {os.name}")
    print(f"System: {platform.system()}")
    print(f"Release: {platform.release()}")
    print(f"Version: {platform.version()}")
    print(f"Machine: {platform.machine()}")
    print(f"Processor: {platform.processor()}")

if __name__ == "__main__":
    system_info()
